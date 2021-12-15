/*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: ell.rex,v $
 *
 *	purpose:	scanner specification
 *
 *	$Author: grosch $
 *	$Date: 2008/09/25 14:47:35 $
 */

EXPORT {
FROM Idents	IMPORT tIdent;
FROM StringM	IMPORT tStringRef;
FROM Position	IMPORT tPosition;

TYPE tScanAttribute = RECORD
		     Position : tPosition;
		     CASE :INTEGER OF
		     | 0 : value : INTEGER;
		     | 1 : ident : tIdent;
		     | 2 : ref   : tStringRef;
		     END;
		   END;

CONST NoValue = -1;

VAR
  Epsilon	: tIdent;
  EndOfToken	: tIdent;
  NoIdent	: tIdent;
  NoString	: tStringRef;

PROCEDURE ErrorAttribute (Token : INTEGER; VAR Attribute : tScanAttribute);
}

GLOBAL {
FROM Position	IMPORT tPosition;
FROM Strings	IMPORT tString, Concatenate, AssignEmpty, ArrayToString,
		       StringToInt, IntToString, SubString, Append, Length,
		       Char;
FROM Idents	IMPORT tIdent, MakeIdent, GetString;
FROM StringM	IMPORT PutString;
FROM Errors	IMPORT Message, MessageI, Error, Character;
FROM ArgCheck	IMPORT tLanguage, LANGUAGE, LINE;
FROM SYSTEM	IMPORT ADR;

CONST
  SymEqual	= 1;
  SymColon	= 2;
  SymPoint	= 3;
  SymOr		= 4;
  SymStar	= 5;
  SymPlus	= 6;
  SymList	= 7;
  SymLBrace	= 8;
  SymRBrace	= 9;
  SymLBracket	= 10;
  SymRBracket	= 11;
  SymEXPORT	= 12;
  SymGLOBAL	= 13;
  SymLOCAL	= 14;
  SymBEGIN	= 15;
  SymCLOSE	= 16;
  SymTOKEN	= 17;
  SymOPER	= 18;
  SymNONE	= 19;
  SymLEFT	= 20;
  SymRIGHT	= 21;
  SymRULE	= 22;
  SymPREC	= 23;
  SymNumber	= 24;
  SymAction	= 25;
  SymActionEnd	= 26;
  SymIdent	= 27;
  SymString	= 28;
  SymSCANNER	= 29;
  SymPARSER	= 30;
  SymComma	= 31;

VAR
  Level		: INTEGER;
  TargetCode, s	: tString;
  StartPosition	: tPosition;

PROCEDURE ErrorAttribute (Token : INTEGER; VAR pAttribute : tScanAttribute);
  BEGIN
    pAttribute.Position := Attribute.Position;
    CASE Token OF
    | SymNumber : pAttribute.value := NoValue;
    | SymAction, SymActionEnd : pAttribute.ref := NoString;
    | SymIdent, SymString : pAttribute.ident := NoIdent;
    ELSE
    END;
  END ErrorAttribute;

PROCEDURE MakeDirective (VAR Result: tString; Line: CARDINAL; File: tIdent);
    VAR s: tString;

  PROCEDURE AppendS (VAR Result: tString; VAR In: ARRAY OF CHAR);
    BEGIN
      ArrayToString (In, s); Concatenate (Result, s);
    END AppendS;

  PROCEDURE AppendI (VAR Result: tString; In: INTEGER);
    BEGIN
      IntToString (In, s); Concatenate (Result, s);
    END AppendI;

  PROCEDURE AppendIdent (VAR Result: tString; In: tIdent);
    BEGIN
      GetString (In, s); Concatenate (Result, s);
    END AppendIdent;

  PROCEDURE AppendIdentEscaped (VAR Result: tString; Ident: tIdent);
    VAR
      i	: CARDINAL;
      ch: CHAR;
    BEGIN
      GetString (Ident, s);
      FOR i := 1 TO Length (s) DO
	ch := Char (s, i);
	IF ch = '\' THEN Append (Result, ch); END;
	Append (Result, ch);
      END;
    END AppendIdentEscaped;

  BEGIN
    Strings.AssignEmpty (Result);
    IF LANGUAGE = C THEN
      IF LINE THEN
	AppendS (Result, "# line ");
	AppendI (Result, Line);
	AppendS (Result, ' "');
	AppendIdentEscaped (Result, File);
	Strings.Append (Result, '"');
      ELSE
	AppendS (Result, "/* line ");
	AppendI (Result, Line);
	AppendS (Result, ' "');
	AppendIdent (Result, File);
	AppendS (Result, '" */');
      END;
    ELSE
      AppendS (Result, "(* line ");
      AppendI (Result, Line);
      AppendS (Result, ' "');
      AppendIdent (Result, File);
      AppendS (Result, '" *)');
    END;
  END MakeDirective;
}

LOCAL { VAR String, Word: tString; ch: CHAR; LineNo: LONGCARD; }

BEGIN {
  ArrayToString ('_Epsilon'	, s); Epsilon	:= MakeIdent (s);
  ArrayToString ('_EOF_'	, s); EndOfToken:= MakeIdent (s);
  ArrayToString ('_ErrorId'	, s); NoIdent	:= MakeIdent (s);
  ArrayToString ('_ErrorStr'	, s); NoString	:= PutString (s);
}

EOF {
  CASE yyStartState OF
  | CStr1, CStr2, Str1, Str2 :
      Message ("unterminated string", Error, Attribute.Position);
  | Comment1, Comment2 :
      Message ("unterminated comment", Error, StartPosition);
  | Action :
      Message ("unterminated action", Error, StartPosition);
  ELSE
  END;
}

DEFINE
  letter	= {A-Z a-z _}	.
  digit		= {0-9}		.
  StrCh1	= - {'\t\n\r}	.
  StrCh2	= - {"\t\n\r}	.
  CStrCh1	= - {'\t\n\r\\}	.
  CStrCh2	= - {"\t\n\r\\}	.

START Action, Str1, Str2, CStr1, CStr2, Comment1, Comment2, PPline

RULES

#STD# "="	: { RETURN SymEqual	; }
#STD# ":"	: { RETURN SymColon	; }
#STD# "."	: { RETURN SymPoint	; }
#STD# ","	: { RETURN SymComma	; }
#STD# "|"	: { RETURN SymOr	; }
#STD# "*"	: { RETURN SymStar	; }
#STD# "+"	: { RETURN SymPlus	; }
#STD# "||"	: { RETURN SymList	; }
#STD# "("	: { RETURN SymLBrace	; }
#STD# ")"	: { RETURN SymRBrace	; }
#STD# "["	: { RETURN SymLBracket	; }
#STD# "]"	: { RETURN SymRBracket	; }
#STD# "BEGIN"	: { RETURN SymBEGIN	; }
#STD# "CLOSE"	: { RETURN SymCLOSE	; }
#STD# "EXPORT"	: { RETURN SymEXPORT	; }
#STD# "GLOBAL"	: { RETURN SymGLOBAL	; }
#STD# "LEFT"	: { RETURN SymLEFT	; }
#STD# "LOCAL"	: { RETURN SymLOCAL	; }
#STD# "NONE"	: { RETURN SymNONE	; }
#STD# "OPER"	: { RETURN SymOPER	; }
#STD# "PARSER"	: { RETURN SymPARSER	; }
#STD# "PREC"	: { RETURN SymPREC	; }
#STD# "RIGHT"	: { RETURN SymRIGHT	; }
#STD# "RULE"	: { RETURN SymRULE	; }
#STD# "SCANNER"	: { RETURN SymSCANNER	; }
#STD# "TOKEN"	: { RETURN SymTOKEN	; }

#STD# digit + :	{
		GetWord (Word);
		Attribute.value := StringToInt (Word);
		RETURN SymNumber;
		}

#STD# \\ letter (letter | digit) * : {
		GetWord (Word);
		SubString (Word, 2, Length (Word), String);
		Attribute.ident := MakeIdent (String);
		RETURN SymIdent;
		}

#STD# letter (letter | digit) * : {
		GetWord (Word);
		Attribute.ident := MakeIdent (Word);
		RETURN SymIdent;
		}

#STD# \f | \r | \26 :- {}

#STD# "{"	: { Level := 0; yyStart (Action); AssignEmpty (TargetCode);
		    StartPosition := Attribute.Position; }

#STD# "(*"	: { Level := 0; yyStart (Comment1);
		    StartPosition := Attribute.Position; }

#Comment1# - {\n\t\(\*} + :- {}
#Comment1# "("		:- {}
#Comment1# "*"		:- {}
#Comment1# "(*"		:- { INC (Level); }
#Comment1# "*)"		:- { IF Level = 0 THEN yyStart (STD);
					  ELSE DEC (Level); END; }

#STD# "/*"		:  { yyStart (Comment2);
			     StartPosition := Attribute.Position; }

#Comment2# - {\n\t\*} +	:- {}
#Comment2# "*"		:- {}
#Comment2# "*/"		:- { yyStart (STD); }

#STD# "//" ANY *	:- {}

#STD# - {\t\n\f\r\ '"}							// vi "
		: { GetWord (Word);
		    ch := Char (Word, 1);
		    IF ch <= ' ' THEN
		      Message ("illegal character", Error, Attribute.Position);
		    ELSE
		      MessageI ("illegal character", Error, Attribute.Position,
			Character, ADR (ch));
		    END; }

#STD, Action# ' : { GetWord (String);
		    IF LANGUAGE = C
		    THEN yyStart (CStr1);
		    ELSE yyStart (Str1);
		    END; }

#STD, Action# \":							// vi "
		  { GetWord (String);
		    IF LANGUAGE = C
		    THEN yyStart (CStr2);
		    ELSE yyStart (Str2);
		    END; }

#Str1#	StrCh1  + | "''" +	,
#Str2#	StrCh2  + | \"\" +	,					// vi "
#CStr1#	CStrCh1 + | \\ ANY ?	,
#CStr2#	CStrCh2 + | \\ ANY ? :- { GetWord (Word); Concatenate (String, Word); }

#CStr1, CStr2# \\ \r ? \n:-{ Strings.Append (String, '\');
			    Strings.Append (String, 12C); yyEol (0); }

#Str1, CStr1# '		,
#Str2, CStr2# \"	:-						// vi "
			   { Append (String, Char (String, 1));
			    yyPrevious;
			    IF yyStartState = Action THEN
			       Concatenate (TargetCode, String);
			    ELSE
			       Attribute.ident := MakeIdent (String);
			       RETURN SymString;
			    END; }

#Str1, Str2, CStr1, CStr2# \t :- { Append (String, 11C); yyTab; }

#Str1, Str2, CStr1, CStr2# \r ? \n :- {
			    Message ("string exceeds line", Error, Attribute.Position);
			    Append (String, 12C);
			    yyEol (0); yyPrevious;
			    IF yyStartState = Action THEN
			       Concatenate (TargetCode, String);
			    ELSE
			       Attribute.ident := MakeIdent (String);
			       RETURN SymString;
			    END; }

#Str1, Str2, CStr1, CStr2# \r :- { Strings.Append (String, 15C); }

#Action# - {\t\n\r\\\{\}'"#} + | \r | \#				// vi "
		:- { GetWord (Word); Concatenate (TargetCode, Word); }

#Action# \r ? \n:- {
		     Append (TargetCode, 12C);
		     Attribute.ref := PutString (TargetCode);
		     AssignEmpty (TargetCode);
		     yyEol (0);
		     RETURN SymAction;
		   }

#Action# \t	:- { yyTab; GetWord (Word); Concatenate (TargetCode, Word); }

#Action# \\ ANY :- { GetWord (Word); Append (TargetCode, Char (Word, 2)); }

#Action# \\	:- { GetWord (Word); Concatenate (TargetCode, Word); }

#Action# \{	:- { INC (Level); GetWord (Word); Concatenate (TargetCode, Word); }

#Action# \}	:- {
		     IF Level = 0 THEN
			Attribute.ref := PutString (TargetCode);
			yyStart (STD);
			RETURN SymActionEnd;
		     ELSE
			DEC (Level);
			GetWord (Word);
			Concatenate (TargetCode, Word);
		     END;
		   }

// interpret #@ line directives

< "#@" " " * "line"	:-{ yyPush (PPline); }

#PPline# {0-9} +	:-{
			   GetWord (Word);
			   LineNo := StringToInt (Word);
			}

#PPline# \" -{\n"} + \"	:-{					(* vi " *)
			   GetWord (Word);
			   SubString (Word, 2, Length (Word) - 1, Word);
			   yyLineCount := LineNo - 1;
			   (* change line # only if there is a file name *)
			   (* -1 compensates for the following yyEol () *)
			   Attribute.Position.File := MakeIdent (Word);
			}

#PPline# \r ? \n	:-{
			   yyPop ();
			   yyEol (0);
			   CASE yyStartState OF
			   | Action:
			     MakeDirective (TargetCode, yyLineCount,
			       Attribute.Position.File);
			     Append (TargetCode, 12C);
			     Attribute.ref := PutString (TargetCode);
			     AssignEmpty (TargetCode);
			     RETURN SymAction;
			   ELSE
			   END;
			}
