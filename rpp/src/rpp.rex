/* $Id: rpp.rex,v 4.20 2008/09/25 15:03:21 grosch Exp $ */

/*
 * $Log: rpp.rex,v $
 * Revision 4.20  2008/09/25 15:03:21  grosch
 * added handling of #@ line directives
 * revised code a bit
 *
 * Revision 4.19  2008/01/30 15:43:48  grosch
 * treat \a as escape sequence
 *
 * Revision 4.18  2007/08/29 10:47:27  grosch
 * fixed bug at 'case t_return: case'
 *
 * Revision 4.17  2004/11/26 10:12:11  grosch
 * increased limitation of number of terminal symbols from 1024 to 2048
 *
 * Revision 4.16  2004/05/03 13:06:43  grosch
 * fixed bug at "return;"
 *
 * Revision 4.15  2002/10/28 20:30:59  grosch
 * added // comments
 *
 * Revision 4.14  2002/10/02 16:43:18  grosch
 * added initialization of Attribute.Position
 *
 * Revision 4.13  2001/08/08 14:48:51  grosch
 * added and revised support for #line directives
 *
 * Revision 4.12  2001/01/11 17:21:05  grosch
 * fixed bug in procedure Echo (long comments)
 *
 * Revision 4.11  2001/01/11 11:02:17  grosch
 * added arguments for input and output as alternative for stdio
 *
 * Revision 4.10  2001/01/05 12:26:18  grosch
 * added generation of Java
 *
 * Revision 4.9  1999/01/12 17:20:27  grosch
 * made WriteId more stable
 *
 * Revision 4.8  1997/05/27 15:42:24  grosch
 * truncated module names to 8 characters: StringM, Position
 * bug fix: handling of tokens containing quotes and double quotes
 *
 * Revision 4.7  1996/05/14 19:49:00  grosch
 * fixed bug for MS-DOS at \ \r \n
 *
 * Revision 4.6  1996/04/28  20:04:46  grosch
 * renamed Positions to Position
 *
 * Revision 4.5  1995/04/23  21:04:37  grosch
 * added handling of comments after DEFINE and RULE
 *
 * Revision 4.4  1994/12/04  17:38:14  grosch
 * added handling of tokens with embedded blanks
 *
 * Revision 4.3  1994/09/13  12:50:10  grosch
 * added generation of Ada code
 *
 * Revision 4.2  1994/07/13  08:52:56  grosch
 * added keyword YYCODE
 *
 * Revision 4.1  1994/02/09  16:51:41  grosch
 * removed unused objects
 *
 * Revision 4.0  1993/08/26  16:07:08  grosch
 * replaced table files (Scanner.Tab, Parser.Tab, ...) by initialization code
 *
 * Revision 1.1  1993/08/18  17:39:01  grosch
 * fixed bug: now '1..n' translates to '1'\.\.'n' instead of \1\.\.'n'
 *
 * Revision 1.0  1993/08/17  15:54:46  grosch
 * Initial revision
 *
 */

EXPORT {
FROM	Position	IMPORT	tPosition;

TYPE tScanAttribute	= RECORD Position: tPosition; END;
}

GLOBAL {
FROM	rSystem		IMPORT	GetArgument,	GetArgCount;
FROM	Position	IMPORT	NoPosition;
FROM	Strings		IMPORT	tString,	AssignEmpty,	Append,
				Concatenate,	Length,		Char,
				IntToString,	StringToArray,	WriteS,
				ReadL,		WriteL,		IsEqual,
				ArrayToString,	StringToInt,	SubString;
FROM	StringM		IMPORT	tStringRef,	PutString,	GetString;
FROM	Idents		IMPORT	tIdent,		NoIdent,	MakeIdent,
				MaxIdent,	WriteIdent;
FROM	IO		IMPORT	StdInput,	StdOutput,	StdError,
				tFile,		ReadOpen,	ReadClose,
				ReadI,		ReadC,		WriteC,
				WriteOpen,	WriteI,		WriteNl,
				EndOfFile,	CloseIO;

CONST	MissingInfo	= "rpp: cannot access file <Scanner>.rpp";
	ArgumentNumber	= "rpp: wrong number of arguments";

VAR	Level, l	: CARDINAL;
	StartString	: tString;
	TheWord		: tString;
	IsCollecting	: BOOLEAN;
	BothFlag	: BOOLEAN;
	IsCode		: BOOLEAN;
	InsText		: tString;
	String		: tString;
	InfoFile	: tFile;
	OutFile		: tFile;
	LastIdent	: tIdent;
	TokenCode	: ARRAY [0..2047] OF SHORTCARD;
	TokenSelector	: ARRAY [0..2047] OF tStringRef;
	Not1		: tString;
	Any1		: tString;
	Language	: (Modula, C, Ada, Java);
	InFileName	,
	OutFileName	,
	InfoFileName	: ARRAY [0..511] OF CHAR;
	OutFileLineNo	: INTEGER;	(* current line number of .rex file *)

PROCEDURE Echo;
VAR i	: INTEGER;
BEGIN
  FOR i := yyChBufferIndex - TokenLength TO yyChBufferIndex - 1 DO
    IO.WriteC (OutFile, yyChBufferPtr^ [i]);
  END;
END Echo;

PROCEDURE ProcessEol;
VAR i: INTEGER;
BEGIN
  FOR i := yyChBufferIndex - TokenLength TO yyChBufferIndex - 1 DO
    IF yyChBufferPtr^ [i] = 12C THEN yyEol (0); END;
    (* we don''t need right column pos, so parameter for yyEol is 0 *)
  END;
END ProcessEol;

PROCEDURE Skip;
BEGIN
  REPEAT
    ReadL (InfoFile, TheWord);
    l := Length (TheWord);
  UNTIL ((l = 2) OR (l = 3)) AND (Char (TheWord, 1) = '%') AND (Char (TheWord, 2) = '%');
END Skip;

(* Write line directive specifying the input file (usually .scan).
   Called after INSERT directives.
   Note: The line number of the INSERT directive is used
   because code following a directive is placed after the inserted section.
   (e. g. "INSERT ErrorAttribute /* comment */")
   At the directive INSERT RULES the line number after the directive is used.
 *)

PROCEDURE WriteDirectiveInFile (Line: CARDINAL);
BEGIN
  IO.WriteS (OutFile,"#@ line ");
  IO.WriteI (OutFile, Line, 0);
  IF Attribute.Position.File # NoIdent THEN
    IO.WriteS (OutFile, ' "');
    WriteIdent (OutFile, Attribute.Position.File);
    IO.WriteS (OutFile, '"');
  END;
  IO.WriteNl (OutFile); INC (OutFileLineNo);
END WriteDirectiveInFile;

(* Write line directive specifying the output file (usually .rex).
   Called before INSERT directives.
 *)

PROCEDURE WriteDirectiveOutFile;
BEGIN
  IO.WriteNl (OutFile); INC (OutFileLineNo);
  IO.WriteS (OutFile,"#@ line ");
  IO.WriteI (OutFile, OutFileLineNo + 2, 0);
  IF OutFileName [0] # 0C THEN
    IO.WriteS (OutFile, ' "');
    IO.WriteS (OutFile, OutFileName);
    IO.WriteS (OutFile, '"');
  END;
  IO.WriteNl (OutFile); INC (OutFileLineNo);
END WriteDirectiveOutFile;

PROCEDURE DoText;
BEGIN
(*
GetWord (TheWord);
IO.WriteS (StdOutput, "DoText: ");
WriteS (StdOutput, TheWord);
IO.WriteNl (StdOutput);
*)
  IF NOT IsCollecting THEN Echo;
  ELSIF Level > 0 THEN GetWord (TheWord); Concatenate (InsText, TheWord);
  END;
END DoText;

PROCEDURE DoIdent;
VAR i: tIdent;
BEGIN
  GetWord (TheWord);
  i := MakeIdent (TheWord);
  IF i <= LastIdent THEN
    IF IsCode THEN
      IntToString (TokenCode [i], TheWord);
    ELSE
      GetString (TokenSelector [i], TheWord);
    END;
    IF IsCollecting THEN
      Concatenate (InsText, TheWord);
    ELSE
      WriteS (OutFile, TheWord);
    END;
  ELSE
    IF IsCollecting THEN
      Concatenate (InsText, TheWord);
    ELSE
      Echo;
    END;
  END;
END DoIdent;

PROCEDURE CopyText;
BEGIN
  LOOP
    ReadL (InfoFile, TheWord);
    l := Length (TheWord);
    IF ((l = 2) OR (l = 3)) AND (Char (TheWord, 1) = '%') AND (Char (TheWord, 2) = '%') THEN EXIT; END;
    WriteL (OutFile, TheWord); INC (OutFileLineNo);
  END;
END CopyText;

PROCEDURE GenPosition;
BEGIN
  CASE Language OF
  | Modula: IO.WriteS (OutFile, "FROM Positions IMPORT tPosition;");
  | C	  : IO.WriteS (OutFile, '# include "Position.h"');
  | Ada	  : IO.WriteS (OutFile, "with Position; use Position;");
  ELSE
  END;
  WriteNl (OutFile); INC (OutFileLineNo);
END GenPosition;

PROCEDURE GenScanAttr;
BEGIN
  InfoFile := ReadOpen (InfoFileName);
  ReadL (InfoFile, TheWord);
  CopyText;
  ReadClose (InfoFile);
END GenScanAttr;

PROCEDURE GenErrorAttr;
BEGIN
  InfoFile := ReadOpen (InfoFileName);
  Skip;
  CopyText;
  ReadClose (InfoFile);
END GenErrorAttr;

PROCEDURE ReadIdents;
VAR	t, i	: INTEGER;
	c, d	: CHAR;
	Ident	: tIdent;
	Selector: ARRAY [0..255] OF CHAR;
	String	: tString;
BEGIN
  InfoFile := ReadOpen (InfoFileName);
  IF InfoFile < 0 THEN
     IO.WriteS (StdError, MissingInfo); WriteNl (StdError); CloseIO; HALT;
  END;
  ReadL (InfoFile, TheWord);
  CASE Char (TheWord, 1) OF
  | 'm' : Language := Modula;
  | 'c' : Language := C;
  | 'a' : Language := Ada;
  | 'j' : Language := Java;
  ELSE
  END;
  Skip;
  Skip;
  WHILE NOT EndOfFile (InfoFile) DO
    t := ReadI (InfoFile);
    c := ReadC (InfoFile);
    c := ReadC (InfoFile);
    c := ReadC (InfoFile);
    d := ReadC (InfoFile);
    Selector [0] := d;
    i := 1;
    IF (d = "'") OR (d = '"') THEN
       REPEAT
	  c := ReadC (InfoFile); Selector [i] := c; INC (i);
       UNTIL c = d;
    END;
    REPEAT
       Selector [i] := ReadC (InfoFile); INC (i);
    UNTIL Selector [i-1] = ' ';
    Selector [i-1] := 0C;
    ArrayToString (Selector, String);
    ReadL (InfoFile, TheWord);
    Ident := MakeIdent (TheWord);
    TokenCode [Ident] := t;
    TokenSelector [Ident] := PutString (String);
  END;
  ReadClose (InfoFile);
  LastIdent := MaxIdent ();
END ReadIdents;

PROCEDURE InsertRules;
VAR	Code	: CARDINAL;
	c, d, Ch: CHAR;
	Selector: ARRAY [0..255] OF CHAR;
	i	: CARDINAL;

  PROCEDURE WriteId (VAR TheWord: tString);
  VAR	s	: ARRAY [0..255] OF CHAR;
	j, l	: CARDINAL;
	special	: BOOLEAN;
	delim	: CHAR;
  BEGIN
    StringToArray (TheWord, s);
    IF NOT BothFlag AND (IsEqual (TheWord, Not1) OR IsEqual (TheWord, Any1)) THEN
      WriteC (OutFile, "\");
    END;
    l := Length (TheWord);
    delim := s [0];
    special := (delim = "'") OR (delim = '"');
    IF special THEN j := 1; DEC (l); ELSE j := 0; END;
    REPEAT
      IF BothFlag THEN
	CASE s [j] OF
	  'a'..'z' :
	    WriteC (OutFile, "{");
	    WriteC (OutFile, s [j]);
	    WriteC (OutFile, CAP (s [j]));
	    WriteC (OutFile, "}");
	| 'A'..'Z' :
	    WriteC (OutFile, "{");
	    WriteC (OutFile, CHR (ORD (s [j]) - ORD ('A') + ORD ('a')));
	    WriteC (OutFile, s [j]);
	    WriteC (OutFile, "}");
	| '0'..'9', '_' :
	    WriteC (OutFile, s [j]);
	ELSE
	  WriteC (OutFile, "\");
	  WriteC (OutFile, s [j]);
	END;
      ELSE
	IF special THEN
	  CASE s [j] OF
	    '0' .. '9', 'n', 't', 'v', 'b', 'r', 'f', 'a':
	    WriteC (OutFile, '"');
	    WriteC (OutFile, s [j]);
	    WriteC (OutFile, '"');
	  ELSE
	    WriteC (OutFile, "\");
	    WriteC (OutFile, s [j]);
	  END;
	ELSE
	  CASE s [j] OF
	    '0'..'9', 'A'..'Z', 'a'..'z', '_' : WriteC (OutFile, s [j]);
	  ELSE
	    WriteC (OutFile, "\");
	    WriteC (OutFile, s [j]);
	  END;
	END;
      END;
      INC (j);
    UNTIL j >= l;
  END WriteId;

BEGIN
  InfoFile := ReadOpen (InfoFileName);
  Skip;
  Skip;
  WHILE NOT EndOfFile (InfoFile) DO
    Code := ReadI (InfoFile);
    c := ReadC (InfoFile);
    Ch := ReadC (InfoFile);
    c := ReadC (InfoFile);
    d := ReadC (InfoFile);
    Selector [0] := d;
    i := 1;
    IF (d = "'") OR (d = '"') THEN
       REPEAT
	  c := ReadC (InfoFile); Selector [i] := c; INC (i);
       UNTIL c = d;
    END;
    REPEAT
       Selector [i] := ReadC (InfoFile); INC (i);
    UNTIL Selector [i-1] = ' ';
    Selector [i-1] := 0C;
    ReadL (InfoFile, TheWord);
    IF Ch # 'S' THEN
       WriteS (OutFile, StartString);
       WriteId (TheWord);
       WriteC (OutFile, 11C);
       IO.WriteS (OutFile, ": { ");
       WriteS (OutFile, InsText);
       CASE Language OF
       | Modula	: IO.WriteS (OutFile, "RETURN ");
       | C, Ada, Java
		: IO.WriteS (OutFile, "return ");
       END;
       WriteI (OutFile, Code, 0);
       IO.WriteS (OutFile, "; }");
       WriteNl (OutFile); INC (OutFileLineNo);
     END;
  END;
  ReadClose (InfoFile);
END InsertRules;
}

LOCAL {
VAR
  Word, Directive: tString;
  LineNo	: LONGCARD;
}

BEGIN {
InfoFileName := "Scanner.rpp";
OutFile := StdOutput;
Language := Modula;
Attribute.Position := NoPosition;
CASE GetArgCount () - 1 OF
| 0: InFileName[0] := 0C;
     OutFileName[0] := 0C;

| 1: GetArgument (1, InfoFileName);
     InFileName[0] := 0C;
     OutFileName[0] := 0C;

| 2: GetArgument (1, InFileName);
     GetArgument (2, OutFileName);

| 3: GetArgument (1, InfoFileName);
     GetArgument (2, InFileName);
     GetArgument (3, OutFileName);
ELSE
  IO.WriteS (StdError, ArgumentNumber); WriteNl (StdError); CloseIO; HALT;
END;
IsCollecting := FALSE;
ReadIdents;
IF InFileName [0] # 0C THEN
  BeginFile (InFileName);
  ArrayToString (InFileName, String);
  Attribute.Position.File := MakeIdent (String);
  OutFile := WriteOpen (OutFileName);
END;
AssignEmpty (InsText);
AssignEmpty (StartString);
ArrayToString ("NOT", Not1);
ArrayToString ("ANY", Any1);
WriteDirectiveInFile (1);
}

DEFINE
  letter	= {A-Z a-z _} .
  digit		= {0-9} .
  StartCh	= - {#\n} .
  StrCh1	= - {'\n} .
  StrCh2	= - {"\n} .
  WS		= {\ \t} + .
  line_terminator = \r ? \n .
  comment	= "/*" - {*\n} * "*" + (- {*/\n} - {*\n} * "*" +) * "/" .
  long_comment	= "/*" - {*} * "*" + (- {*/} - {*} * "*" +) * "/" .
  line_comment	= "//" ANY * .
  identifier	= (letter | digit) + .

START	Return, Start, Action, Rules, Set, PPline

RULE

#STD#	 \{		:- { yyPush (Action); Echo; Level := 1; }
#STD#	 DEFINE | RULE	:- { yyStart (Rules); Echo; }

#Rules#	 \" StrCh2 + \"	:- { DoText; }					// vi "
#Rules#	 INSERT WS RULES:  { yyPush (Start); BothFlag := FALSE; }
#Rules#	 INSERT WS RULES WS CASE\-INSENSITIVE
			:  { yyPush (Start); BothFlag := TRUE; }
#Rules#	 \: | \:\-	:- { yyPush (Action); Echo; Level := 0; }
#Rules#	 \{		:- { yyStart (Set); Echo; }
#Rules#	 comment	:- { Echo; }
#Rules#	 long_comment	:- { ProcessEol; Echo; }
#Rules#	 line_comment	:- { Echo; }

#Set#	 \}		:- { yyPrevious; Echo; }

#Start#	 "NOT" ? WS ? \# StartCh + \#
			:- { GetWord (StartString); }

#Start#  \{		:- { yyPush (Action); Level := 1;
			     IsCollecting := TRUE; }

#Start#  WS		:- {}

#Start#  line_terminator:- { yyPop (); yyEol (0);
			     WriteDirectiveOutFile;
			     InsertRules;
			     WriteDirectiveInFile (Attribute.Position.Line + 1);
			     IsCollecting := FALSE; }

#Action# INSERT WS tPosition
			:- { GenPosition; }

#Action# INSERT WS tScanAttribute
			:  { WriteDirectiveOutFile;
			     GenScanAttr;
			     WriteDirectiveInFile (Attribute.Position.Line); }

#Action# INSERT WS ErrorAttribute
			:  { WriteDirectiveOutFile;
			     GenErrorAttr;
			     WriteDirectiveInFile (Attribute.Position.Line); }

#Action# \{		:- { DoText; INC (Level); }

#Action# \}		:- { DEC (Level); DoText;
			     IF Level = 0 THEN yyPop (); END;
			   }

#Action# identifier ? Attribute \.
			:- { DoText; yyPush (Return); IsCode := FALSE; }

#Action# RETURN		:- { DoText;
			     IF Language = Modula THEN
			       yyPush (Return); IsCode := TRUE;
			     END;
			   }

#Action# return		:- { DoText;
			     IF Language <> Modula THEN
			       yyPush (Return); IsCode := TRUE;
			     END;
			   }

#Action# YYCODE		:- { yyPush (Return); IsCode := TRUE; }

#Action# identifier	:- { DoText; }

#Return# identifier	,
#Return# \" StrCh2 + \"	,						// vi "
#Return# ' StrCh1 + '	:- { yyPop (); DoIdent; }

#Return# \;		:- { yyPop (); DoText; }

// interpret #@ line directives

< "#@" " " * "line"	:- { yyPush (PPline);
			     GetWord (Directive); }

#PPline# {0-9} +	:- {
			     GetWord (Word);
			     Concatenate (Directive, Word);
			     LineNo := StringToInt (Word);
			}

#PPline# \" -{\n"} + \"	:- {					(* vi " *)
			     GetWord (Word);
			     Concatenate (Directive, Word);
			     SubString (Word, 2, Length (Word) - 1, Word);
			     yyLineCount := LineNo - 1;
			     (* change line # only if there is a file name *)
			     (* -1 compensates for the following yyEol () *)
			     Attribute.Position.File := MakeIdent (Word);
			}

#PPline# line_terminator :- {
			     yyPop ();
			     yyEol (0); 
			     WriteL (OutFile, Directive); INC (OutFileLineNo);
			}

#PPline# WS		:- { Append (Directive, ' '); }
#PPline# ANY		:- {}


  \f , \r , \26		:- {}

  line_terminator	:- { yyEol (0); DoText; INC (OutFileLineNo); }

  ANY			,
  \\ - {\r\n}		,
  \\ / line_terminator	,
  WS			:- { DoText; }
