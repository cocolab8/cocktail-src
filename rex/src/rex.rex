/* $Id: rex.rex,v 3.26 2008/09/25 15:01:34 grosch Exp $ */

/*
 * $Log: rex.rex,v $
 * Revision 3.26  2008/09/25 15:01:34  grosch
 * revised handling of # line directives
 * renamed WriteLine -> WriteDirective, AppendLine -> MakeDirective
 *
 * Revision 3.25  2008/09/17 18:42:13  grosch
 * fixed handling of line comments/directives
 *
 * Revision 3.24  2006/11/14 10:31:20  grosch
 * added recognition of \a
 *
 * Revision 3.23  2006/11/09 15:07:07  grosch
 * removed 2 grammar conflicts
 * keywords are not reserved identifiers anymore
 *
 * Revision 3.22  2006/08/01 14:15:17  grosch
 * allow comments in CHARACTER_SET definition
 * NOT is not a reserved keyword anymore
 *
 * Revision 3.21  2005/05/23 12:57:03  grosch
 * added recognition of \a
 *
 * Revision 3.20  2001/08/08 14:57:56  grosch
 * added and revised support for #line directives
 *
 * Revision 3.19  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 3.18  2000/04/03 10:15:55  grosch
 * added missing assignment of Attribute.Position
 * added C++ comments
 * improved messages for unclosed constructs
 * allow comments after : and :-
 *
 * Revision 3.17  1999/06/02 15:44:32  grosch
 * added check for: number out of range
 *
 * Revision 3.16  1998/04/21 10:35:24  grosch
 * truncation of file and module names to 8.3 format
 * cosmetic changes
 *
 * Revision 3.15  1997/01/17 21:29:43  grosch
 * removed Errors module, use the one from reuse
 *
 * Revision 3.14  1996/05/14  19:47:40  grosch
 * fixed bug for MS-DOS at \ \r \n
 *
 * Revision 3.13  1995/07/24  16:38:15  grosch
 * detect and handle null strings
 *
 * Revision 3.12  1995/06/26  13:06:04  grosch
 * omit unused objects
 * suppress warnings (gcc -Wall)
 *
 * Revision 3.11  1994/09/29  11:10:01  grosch
 * improved error detection for target code sections
 *
 * Revision 3.10  1994/09/13  12:44:12  grosch
 * added generation of Ada code
 *
 * Revision 3.9  1994/04/05  09:11:01  grosch
 * added handling of CHARACTER_SET
 *
 * Revision 3.8  1994/03/23  14:49:17  grosch
 * added generation of C++
 * read options from environment variable REX
 * added touching of output files only if necessary
 *
 * Revision 3.7  1992/09/29  19:02:45  grosch
 * abort execution upon errors during scanning
 *
 * Revision 3.6  1992/09/29  14:38:55  grosch
 * abort execution upon errors during scanning
 *
 * Revision 3.5  1992/08/11  11:51:51  grosch
 * moved PrevState from LOCAL to GLOBAL
 *
 * Revision 3.4  1992/08/07  15:11:08  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 3.3  1991/12/04  16:16:58  grosch
 * unified escape conventions for all tools
 *
 * Revision 3.2  1991/11/21  14:42:27  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.1  91/06/06  15:29:42  grosch
 * fixed bug in EOF secton: yyStart (STD);
 *
 * Revision 3.0  91/04/04  18:08:10  grosch
 * introduced partitioning of character set
 *
 * Revision 2.0  91/03/08  18:18:14  grosch
 * turned tables into initialized arrays (in C)
 * reduced case size
 * changed interface for source position
 *
 * Revision 1.4  90/08/22  17:33:38  grosch
 * fixed bug with backslash in comments
 *
 * Revision 1.3  90/05/17  11:17:47  grosch
 * allow RULE or RULES
 *
 * Revision 1.2  89/02/23  15:56:12  grosch
 * added DEFAULT section
 *
 * Revision 1.1  89/01/17  15:01:58  grosch
 * correction and redesign of source position handling
 *
 * Revision 1.0  88/10/04  11:59:58  grosch
 * Initial revision
 *
 */

/* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 */

EXPORT	{

FROM Idents	IMPORT tIdent	;
FROM StringM	IMPORT tStringRef;
FROM Texts	IMPORT tText	;
FROM Position	IMPORT tPosition;
FROM UniCode	IMPORT UCHAR	;

TYPE
   tScanAttribute	= RECORD
	      Position	: tPosition	;
	 CASE : INTEGER OF
	 | 1: Ident	: tIdent	;
	 | 2: Number	: LONGCARD	;
	 | 3: String	: tStringRef	;
	 | 4: Ch	: UCHAR		;
	 | 5: Text	: tText		;
	 END;
      END;

VAR ErrorCount	: CARDINAL;

PROCEDURE ErrorAttribute (Token: CARDINAL; VAR Attribute: tScanAttribute);
PROCEDURE startCode	;
PROCEDURE startCharset	;
PROCEDURE startSet	;
PROCEDURE startRules	;
}

GLOBAL	{

FROM Strings	IMPORT tString, Concatenate, Char, SubString, cMaxStrLength,
			StringToInt, StringToNumber, AssignEmpty, Length,
			ArrayToString, IntToString;
FROM Texts	IMPORT MakeText, Append;
FROM StringM	IMPORT tStringRef, PutString;
FROM Idents	IMPORT tIdent, MakeIdent, NoIdent, GetString;
FROM Errors	IMPORT Message, Error, Restriction;
FROM ScanGen	IMPORT Language, tLanguage, Procedures, MakeDirective,
			pGetWord, pGetLower, pGetUpper, pinput, pyyPush, pyyPop;
FROM Position	IMPORT tPosition;
FROM UniCode	IMPORT MaxUCHAR;

CONST
   SymIdent		= 1	;
   SymNumber		= 2	;
   SymString		= 3	;
   SymChar		= 4	;
   SymTargetcode	= 5	;
   SymScanner		= 37	;
   SymImport		= 39	;
   SymExport		= 32	;
   SymGlobal		= 6	;
   SymLocal		= 31	;
   SymBegin		= 7	;
   SymClose		= 8	;
   SymEof		= 34	;
   SymDefault		= 36	;
   SymCharSet		= 38	;
   SymDefine		= 9	;
   SymStart		= 10	;
   SymRules		= 11	;
   SymDot		= 12	;
   SymComma		= 13	;
   SymEqual		= 14	;
   SymColon		= 15	;
   SymColonMinus	= 35	;
   SymNrSign		= 33	;
   SymSlash		= 16	;
   SymBar		= 17	;
   SymPlus		= 18	;
   SymMinus		= 19	;
   SymAsterisk		= 20	;
   SymQuestion		= 21	;
   SymLParen		= 22	;
   SymRParen		= 23	;
   SymLBracket		= 24	;
   SymRBracket		= 25	;
   SymLBrace		= 26	;
   SymRBrace		= 27	;
   SymLess		= 28	;
   SymGreater		= 29	;
   SymRule		= 30	;

VAR
   level	: INTEGER	;
   string, TargetCode	: tString	;
   NoString	: tStringRef	;
   StartPosition, StringPosition: tPosition	;
   PrevState	: SHORTCARD	;
   IsChar	: BOOLEAN	;

PROCEDURE ErrorAttribute (Token: CARDINAL; VAR pAttribute: tScanAttribute);
   BEGIN
      pAttribute.Position := Attribute.Position;
      CASE Token OF
      |  SymIdent	: pAttribute.Ident  := NoIdent;
      |  SymNumber	: pAttribute.Number := 0;
      |  SymString	: pAttribute.String := NoString;
      |  SymChar	: pAttribute.Ch	    := ORD ('?');
      |  SymTargetcode	: MakeText (pAttribute.Text);
      ELSE
      END;
   END ErrorAttribute;

PROCEDURE startCode;
  BEGIN
    yyStart (targetcode);
    MakeText (Attribute.Text);
    AssignEmpty (TargetCode);
    level := 1;
  END startCode;

PROCEDURE startCharset;
  BEGIN
    yyStart (charset);
    IsChar := TRUE;
  END startCharset;

PROCEDURE startSet;
  BEGIN
    yyStart (set);
  END startSet;

PROCEDURE startRules;
  BEGIN
    yyStart (rules);
  END startRules;
}

LOCAL	{
VAR
   String, Word	: tString;
   n, LineNo	: LONGCARD;

PROCEDURE AppendCode;
   BEGIN
      GetWord (Word);
      Concatenate (TargetCode, Word);
   END AppendCode;
}

BEGIN	{
   level := 0;
   AssignEmpty (string);
   NoString := PutString (string);
   ErrorCount := 0;
}

DEFAULT	{
   Message ("illegal character", Error, Attribute.Position);
   INC (ErrorCount);
}

EOF	{
   CASE yyStartState OF
   | targetcode	,
     set	: Message ("terminating '}' missing", Error, StartPosition);
		  INC (ErrorCount);
   | comment	: Message ("unterminated comment", Error, StartPosition);
		  INC (ErrorCount);
   | CStr1, CStr2,
     AStr1, AStr2,
     Str1, Str2	: Message ("unterminated string", Error, StringPosition);
		  INC (ErrorCount);
   ELSE
   END;
   yyStart (STD);
}

DEFINE
   letter	= {A-Z a-z}	.
   digit	= {0-9}		.
   octdigit	= {0-7}		.
   hexdigit	= {0-9 A-F a-f}	.
   string	= - {"\n}	.
   cmtch	= - {*\t\n}	.
   code		= - {{\}\t\n\r\\'"gGiy#} .
   StrCh1	= - {'\t\n\r}	.
   StrCh2	= - {"\t\n\r}	.
   CStrCh1	= - {'\t\n\r\\}	.
   CStrCh2	= - {"\t\n\r\\}	.
   AStrCh	= {\ !#-~}	.

START targetcode, set, rules, comment,
      Str1, Str2, CStr1, CStr2, AStr1, AStr2, charset, PPline

RULES

#targetcode#	"{"	:- {
			   AppendCode;
			   INC (level);
			}

#targetcode#	"}"	:- {
			   DEC (level);
			   IF level = 0 THEN
			      yyStart (PrevState);
			      Append (Attribute.Text, TargetCode);
			      Attribute.Position := StartPosition;
			      RETURN SymTargetcode;
			   ELSE
			      AppendCode;
			   END;
			}

#targetcode#	code + | {gGiy\r#} :- { AppendCode; }

#targetcode#	GetWord	:- {IF Language # Java THEN
			      INCL (Procedures, pGetWord);
			    END; AppendCode; }
#targetcode#	getWord	:- {IF Language = Java THEN
			      INCL (Procedures, pGetWord);
			    END; AppendCode; }
#targetcode#	GetLower:- {IF Language # Java THEN
			      INCL (Procedures, pGetLower);
			    END;  AppendCode; }
#targetcode#	getLower:- {IF Language = Java THEN
			      INCL (Procedures, pGetLower);
			    END;  AppendCode; }
#targetcode#	GetUpper:- {IF Language # Java THEN
			      INCL (Procedures, pGetUpper);
			    END;  AppendCode; }
#targetcode#	getUpper:- {IF Language = Java THEN
			      INCL (Procedures, pGetUpper);
			    END;  AppendCode; }

#targetcode#	input	:- { INCL (Procedures, pinput	); AppendCode; }
#targetcode#	yyPush	:- { INCL (Procedures, pyyPush	); AppendCode; }
#targetcode#	yyPop	:- { INCL (Procedures, pyyPop	); AppendCode; }

#targetcode#	\t	:- {
			   Strings.Append (TargetCode, 11C);
			   yyTab;
			}

#targetcode#	\r ? \n	:- {
			   Append (Attribute.Text, TargetCode);
			   AssignEmpty (TargetCode);
			   yyEol (0);
			}

#targetcode#	\\ ANY	: {
			   GetWord (Word);
			   Strings.Append (TargetCode, Char (Word, 2));
			}

#targetcode#	\\ / \r ? \n,
#targetcode#	\\	: { Strings.Append (TargetCode, '\'); }

#targetcode#	'	: {
			   GetWord (String);
			   IF (Language = C) OR (Language = Cpp) THEN yyStart (CStr1);
			   ELSIF Language = Ada THEN yyStart (AStr1);
			   ELSE yyStart (Str1);
			   END;
			   StringPosition := Attribute.Position;
			}

#targetcode#	\"	: {
			   GetWord (String);
			   IF (Language = C) OR (Language = Cpp) THEN yyStart (CStr2);
			   ELSIF Language = Ada THEN yyStart (AStr2);
			   ELSE yyStart (Str2);
			   END;
			   StringPosition := Attribute.Position;
			}

#Str1#	StrCh1 +	,
#Str2#	StrCh2 +	,
#CStr1#	CStrCh1 + | \\ ANY ?	,
#CStr2#	CStrCh2 + | \\ ANY ?	,
#AStr2# AStrCh +	:- {GetWord (Word); Concatenate (String, Word);}

#CStr1, CStr2# \\ \r ? \n:-{Strings.Append (String, '\');
			    Strings.Append (String, 12C); yyEol (0);}

#Str1, CStr1# '		,
#Str2, CStr2, AStr2# \"	,						// vi "
#AStr1# ANY ' ?		:- {GetWord (Word); Concatenate (String, Word);
			    yyPrevious; Concatenate (TargetCode, String);}

#Str1, Str2, CStr1, CStr2# \t :- {Strings.Append (String, 11C); yyTab;}

#Str1, Str2, CStr1, CStr2, AStr2# \r ? \n
			:- { (* Message ("unterminated string", Error, Attribute.Position);
			    INC (ErrorCount); *)
			    Strings.Append (String, 12C);
			    yyEol (0); yyPrevious; Concatenate (TargetCode, String);
			}

#Str1, Str2, CStr1, CStr2# \r :- {Strings.Append (String, 15C);}

#STD, rules, charset#
	  "/*"		:  {yyStart (comment); StartPosition := Attribute.Position; }
#comment# "*" | cmtch +	:- {}
#comment# "*/"		:- {yyPrevious;}

#STD, rules, charset# "//" ANY * :- {}

#STD# IMPORT		: {PrevState := STD; RETURN SymImport	;}
#STD# EXPORT		: {PrevState := STD; RETURN SymExport	;}
#STD# GLOBAL		: {PrevState := STD; RETURN SymGlobal	;}
#STD# LOCAL		: {PrevState := STD; RETURN SymLocal	;}
#STD# BEGIN		: {PrevState := STD; RETURN SymBegin	;}
#STD# CLOSE		: {PrevState := STD; RETURN SymClose	;}
#STD# DEFAULT		: {PrevState := STD; RETURN SymDefault	;}
#STD# EOF		: {PrevState := STD; RETURN SymEof	;}
#STD# SCANNER		: {RETURN SymScanner	;}
#STD# CHARACTER_SET	: {RETURN SymCharSet	;}
#STD# DEFINE		: {RETURN SymDefine	;}
#STD# START		: {RETURN SymStart	;}
#STD# RULE		: {RETURN SymRule	;}
#STD# RULES		: {RETURN SymRules	;}

#STD, rules#	letter (letter | digit | _) * : {
			   GetWord (Word);
			   Attribute.Ident  := MakeIdent (Word);
			   RETURN SymIdent;
			}

#STD, rules#	digit +	: {
			   GetWord (Word);
			   Attribute.Number := StringToInt (Word);
			   RETURN SymNumber;
			}

#STD, rules#	\" string * \" : {				(* vi " *)
			   IF TokenLength > cMaxStrLength THEN
			      Message ("string too long (max. 255)", Restriction, Attribute.Position);
			      INC (ErrorCount);
			      ArrayToString (" ", TargetCode);
			   ELSIF TokenLength = 2 THEN
			      Message ("string length > 0 required", Error, Attribute.Position);
			      INC (ErrorCount);
			      ArrayToString (" ", TargetCode);
			   ELSE
			      GetWord (Word);
			      SubString (Word, 2, Length (Word) - 1, TargetCode);
			   END;
			   Attribute.String := PutString (TargetCode);
			   RETURN SymString;
			}

#STD#		"."	: {RETURN SymDot	;}
#STD#		"="	: {RETURN SymEqual	;}
#STD, set#	"}"	: {yyPrevious;		RETURN SymRBrace	;}
#STD, set, rules# "-"	: {RETURN SymMinus	;}
#STD, rules#	","	: {RETURN SymComma	;}
#STD, rules#	"|"	: {RETURN SymBar	;}
#STD, rules#	"+"	: {RETURN SymPlus	;}
#STD, rules#	"*"	: {RETURN SymAsterisk	;}
#STD, rules#	"?"	: {RETURN SymQuestion	;}
#STD, rules#	"("	: {RETURN SymLParen	;}
#STD, rules#	")"	: {RETURN SymRParen	;}
#STD, rules#	"["	: {RETURN SymLBracket	;}
#STD, rules#	"]"	: {RETURN SymRBracket	;}
#STD, rules#	"{"	: {StartPosition := Attribute.Position;
			   RETURN SymLBrace	;}
#rules#		"#"	: {RETURN SymNrSign	;}
#rules#		"/"	: {RETURN SymSlash	;}
#rules#		"<"	: {RETURN SymLess	;}
#rules#		">"	: {RETURN SymGreater	;}
#rules#		":"	: {PrevState := rules; RETURN SymColon	;}
#rules#		":-"	: {PrevState := rules; RETURN SymColonMinus	;}

#STD, set, rules# \\ a	: {Attribute.Ch := ORD (007C); RETURN SymChar;}
#STD, set, rules# \\ b	: {Attribute.Ch := ORD (010C); RETURN SymChar;}
#STD, set, rules# \\ t	: {Attribute.Ch := ORD (011C); RETURN SymChar;}
#STD, set, rules# \\ n	: {Attribute.Ch := ORD (012C); RETURN SymChar;}
#STD, set, rules# \\ v	: {Attribute.Ch := ORD (013C); RETURN SymChar;}
#STD, set, rules# \\ f	: {Attribute.Ch := ORD (014C); RETURN SymChar;}
#STD, set, rules# \\ r	: {Attribute.Ch := ORD (015C); RETURN SymChar;}

#STD, set, rules# \\ digit + : {
			   GetWord (Word);
			   SubString (Word, 2, Length (Word), TargetCode);
			   n := LONGCARD (StringToInt (TargetCode));
			   IF n <= MaxUCHAR THEN
			      Attribute.Ch := n;
			   ELSE
			      Message ("number out of range", Error, Attribute.Position);
			      INC (ErrorCount);
			      Attribute.Ch := 0;
			   END;
			   RETURN SymChar;
			}

#STD, set, rules# \\ "0" {xX} hexdigit + : {
			   GetWord (Word);
			   SubString (Word, 4, Length (Word), TargetCode);
			   n := StringToNumber (TargetCode, 16);
			   IF n <= MaxUCHAR THEN
			      Attribute.Ch := n;
			   ELSE
			      Message ("number out of range", Error, Attribute.Position);
			      INC (ErrorCount);
			      Attribute.Ch := 0;
			   END;
			   RETURN SymChar;
			}

#STD, set, rules# \\ {xXuU} hexdigit + : {
			   GetWord (Word);
			   SubString (Word, 3, Length (Word), TargetCode);
			   n := StringToNumber (TargetCode, 16);
			   IF n <= MaxUCHAR THEN
			      Attribute.Ch := n;
			   ELSE
			      Message ("number out of range", Error, Attribute.Position);
			      INC (ErrorCount);
			      Attribute.Ch := 0;
			   END;
			   RETURN SymChar;
			}

#STD, set, rules# \\ ANY : {
			   GetWord (Word);
			   Attribute.Ch := ORD (Char (Word, 2));
			   RETURN SymChar;
			}

#STD, set, rules# \\ / \r \n : {
			   Attribute.Ch := ORD ('\');
			   RETURN SymChar;
			}

#STD, set, rules# - {\ \t\n\f\r\26} : {
			   GetWord (Word);
			   Attribute.Ch := ORD (Char (Word, 1));
			   RETURN SymChar;
			}

\f , \r , \26		:- {}

#charset# digit		: {
			   IsChar := NOT IsChar;
			   GetWord (Word);
			   IF NOT IsChar THEN
			      Attribute.Ch := ORD (Char (Word, 1));
			      RETURN SymChar;
			   ELSE
			      Attribute.Number := StringToInt (Word);
			      RETURN SymNumber;
			   END;
			}

#charset# "0" octdigit *: {
			   IsChar := NOT IsChar;
			   GetWord (Word);
			   Attribute.Number := StringToNumber (Word, 8);
			   RETURN SymNumber;
			}

#charset# digit +	: {
			   IsChar := NOT IsChar;
			   GetWord (Word);
			   Attribute.Number := StringToInt (Word);
			   RETURN SymNumber;
			}

#charset# "0" {xX} hexdigit +	: {
			   IsChar := NOT IsChar;
			   GetWord (Word);
			   SubString (Word, 3, Length (Word), TargetCode);
			   Attribute.Number := StringToNumber (TargetCode, 16);
			   RETURN SymNumber;
			}

#charset# \\ a		: {Attribute.Ch := ORD (007C); IsChar := FALSE; RETURN SymChar;}
#charset# \\ b		: {Attribute.Ch := ORD (010C); IsChar := FALSE; RETURN SymChar;}
#charset# \\ t		: {Attribute.Ch := ORD (011C); IsChar := FALSE; RETURN SymChar;}
#charset# \\ n		: {Attribute.Ch := ORD (012C); IsChar := FALSE; RETURN SymChar;}
#charset# \\ v		: {Attribute.Ch := ORD (013C); IsChar := FALSE; RETURN SymChar;}
#charset# \\ f		: {Attribute.Ch := ORD (014C); IsChar := FALSE; RETURN SymChar;}
#charset# \\ r		: {Attribute.Ch := ORD (015C); IsChar := FALSE; RETURN SymChar;}

#charset# \\ ANY	: {
			   IsChar := FALSE;
			   GetWord (Word);
			   Attribute.Ch := ORD (Char (Word, 2));
			   RETURN SymChar;
			}

#charset# - {\ \t\n\f\r\26\}} : {
			   IsChar := FALSE;
			   GetWord (Word);
			   Attribute.Ch := ORD (Char (Word, 1));
			   RETURN SymChar;
			}

#charset# "}" / {\ \t\n} * digit : {
			   IsChar := FALSE;
			   Attribute.Ch := ORD ('}');
			   RETURN SymChar;
			}

#charset# "}"		: {yyStart (STD); RETURN SymRBrace;}

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
			   | targetcode:
			     MakeDirective (String, yyLineCount,
			       Attribute.Position.File);
			     Append (Attribute.Text, String);
			   ELSE
			   END;
			}
