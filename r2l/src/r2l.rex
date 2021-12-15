/* $Id: r2l.rex,v 1.3 2000/04/03 10:24:22 grosch rel $ */

/*
 * $Log: r2l.rex,v $
 * Revision 1.3  2000/04/03 10:24:22  grosch
 * added missing assignment of Attribute.Position
 *
 * Revision 1.2  1997/05/27 15:45:25  grosch
 * truncated module names to 8 characters: StringM, Position
 *
 * Revision 1.1  1996/05/14 20:19:53  grosch
 * update to latest version of rex (new syntax)
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

TYPE
   tScanAttribute	= RECORD
	      Position	: tPosition	;
	 CASE : INTEGER OF
	 | 1: Ident	: tIdent	;
	 | 2: Number	: SHORTCARD	;
	 | 3: String	: tStringRef	;
	 | 4: Ch	: CHAR		;
	 | 5: Text	: tText		;
	 END;
      END;

PROCEDURE ErrorAttribute (Token: CARDINAL; VAR Attribute: tScanAttribute);
}

GLOBAL	{

FROM SYSTEM	IMPORT ADDRESS;
FROM Strings	IMPORT tString, Concatenate, Char, SubString, cMaxStrLength,
			StringToInt, StringToNumber, AssignEmpty, Length,
			ArrayToString;
FROM Texts	IMPORT MakeText, Append;
FROM StringM	IMPORT tStringRef, PutString;
FROM Idents	IMPORT tIdent, MakeIdent, NoIdent;
FROM Errors	IMPORT ErrorMessage, Error, Restriction;
FROM Position	IMPORT tPosition;

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
   SymNot		= 30	;
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

   BraceMissing		= 13	;
   UnclosedComment	= 14	;
   UnclosedString	= 16	;
   IllegalCharacter	= 17	;
   LeftCurlyExpected	= 21    ;
   StringTooLong	= 26	;
   StringTooShort	= 27	;

VAR
   level	: INTEGER	;
   string	: tString	;
   NoString	: tStringRef	;
   ThePosition	: tPosition	;
   PrevState	: SHORTCARD	;
   IsChar	: BOOLEAN	;

PROCEDURE ErrorAttribute (Token: CARDINAL; VAR pAttribute: tScanAttribute);
   BEGIN
      pAttribute.Position := Attribute.Position;
      CASE Token OF
      |  SymIdent	: pAttribute.Ident  := NoIdent;
      |  SymNumber	: pAttribute.Number := 0;
      |  SymString	: pAttribute.String := NoString;
      |  SymChar	: pAttribute.Ch	    := '?';
      |  SymTargetcode	: MakeText (pAttribute.Text);
      ELSE
      END;
   END ErrorAttribute;
}

LOCAL	{
VAR TargetCode, String, Word: tString;

PROCEDURE AppendCode;
   BEGIN
      IF level > 0 THEN
	 GetWord (Word);
	 Concatenate (TargetCode, Word);
      ELSE
	 ErrorMessage (LeftCurlyExpected, Error, Attribute.Position);
      END;
   END AppendCode;
}

BEGIN	{
   level := 0;
   AssignEmpty (string);
   NoString := PutString (string);
}

DEFAULT	{
   ErrorMessage (IllegalCharacter, Error, Attribute.Position);
}

EOF	{
   CASE yyStartState OF
   | targetcode	,
     set	: ErrorMessage (BraceMissing	, Error, Attribute.Position);
   | comment	: ErrorMessage (UnclosedComment	, Error, Attribute.Position);
   | CStr1, CStr2: ErrorMessage (UnclosedString	, Error, Attribute.Position);
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
   code		= - {{\}\t\n\r\\'"} .
   StrCh1	= - {'\t\n\r}	.
   StrCh2	= - {"\t\n\r}	.
   CStrCh1	= - {'\t\n\r\\}	.
   CStrCh2	= - {"\t\n\r\\}	.
   AStrCh	= {\ !#-~}	.

START targetcode, set, rules, comment, CStr1, CStr2, charset0, charset

RULES

#targetcode#	"{"	: {
			   IF level = 0 THEN
			      MakeText (Attribute.Text);
			      AssignEmpty (TargetCode);
			      ThePosition := Attribute.Position;
			   ELSE
			      GetWord (Word);
			      Concatenate (TargetCode, Word);
			   END;
			   INC (level);
			}

#targetcode#	"}"	:- {
			   DEC (level);
			   IF level = 0 THEN
			      yyStart (PrevState);
			      Append (Attribute.Text, TargetCode);
			      Attribute.Position := ThePosition;
			      RETURN SymTargetcode;
			   ELSE
			      GetWord (Word);
			      Concatenate (TargetCode, Word);
			   END;
			}

#targetcode#	" " +	:- {
			   IF level > 0 THEN
			      GetWord (Word);
			      Concatenate (TargetCode, Word);
			   END;
			}

#targetcode#	code + | \r : { AppendCode; }

#targetcode#	\t	:- {
			   IF level > 0 THEN
			      Strings.Append (TargetCode, 11C);
			   END;
			   yyTab;
			}

#targetcode#	\r ? \n	:- {
			   IF level > 0 THEN
			      Append (Attribute.Text, TargetCode);
			      AssignEmpty (TargetCode);
			   END;
			   yyEol (0);
			}

#targetcode#	\\ ANY	: {
			   IF level > 0 THEN
			      GetWord (Word);
			      Strings.Append (TargetCode, Char (Word, 2));
			   ELSE
			      ErrorMessage (LeftCurlyExpected, Error, Attribute.Position);
			   END;
			}

#targetcode#	\\ / \r ? \n,
#targetcode#	\\	: {
			   IF level > 0 THEN
			      Strings.Append (TargetCode, '\');
			   ELSE
			      ErrorMessage (LeftCurlyExpected, Error, Attribute.Position);
			   END;
			}

#targetcode#	'	: {
			   GetWord (String);
			   yyStart (CStr1);
			}

#targetcode#	\"	: {
			   GetWord (String);
			   yyStart (CStr2);
			}

#CStr1#	CStrCh1 + | \\ ANY ?	,
#CStr2#	CStrCh2 + | \\ ANY ?
			:- {GetWord (Word); Concatenate (String, Word);}

#CStr1, CStr2# \\ \r ? \n:-{Strings.Append (String, '\');
			    Strings.Append (String, 12C); yyEol (0);}

#CStr1#		'	,
#CStr2#		\"	:- {GetWord (Word); Concatenate (String, Word);
			    yyPrevious; Concatenate (TargetCode, String);}

#CStr1, CStr2# \t	:- {Strings.Append (String, 11C); yyTab;}

#CStr1, CStr2# \r ? \n	:- { (* ErrorMessage (UnclosedString, Error, Attribute.Position); *)
			    Strings.Append (String, 12C);
			    yyEol (0); yyPrevious; Concatenate (TargetCode, String);
			}

#CStr1, CStr2# \r	:- {Strings.Append (String, 15C);}

#STD, rules#	"/*"	:- {yyStart (comment)	;}
#comment#	"*" | cmtch +	:- {}
#comment#	"*/"	:- {yyPrevious		;}

#STD#		IMPORT	: {PrevState := STD; yyStart (targetcode); RETURN SymImport	;}
#STD#		EXPORT	: {PrevState := STD; yyStart (targetcode); RETURN SymExport	;}
#STD#		GLOBAL	: {PrevState := STD; yyStart (targetcode); RETURN SymGlobal	;}
#STD#		LOCAL	: {PrevState := STD; yyStart (targetcode); RETURN SymLocal	;}
#STD#		BEGIN	: {PrevState := STD; yyStart (targetcode); RETURN SymBegin	;}
#STD#		CLOSE	: {PrevState := STD; yyStart (targetcode); RETURN SymClose	;}
#STD#		DEFAULT	: {PrevState := STD; yyStart (targetcode); RETURN SymDefault	;}
#STD#		EOF	: {PrevState := STD; yyStart (targetcode); RETURN SymEof	;}
#STD#		SCANNER	: {RETURN SymScanner	;}
#STD#		CHARACTER_SET
			: {yyStart (charset0);	RETURN SymCharSet	;}
#STD#		DEFINE	: {RETURN SymDefine	;}
#STD#		START	: {RETURN SymStart	;}
#STD#		RULE S ?: {yyStart (rules);	RETURN SymRules		;}
#rules#		\NOT	: {RETURN SymNot	;}

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

#STD, rules#	\" string * \" : {
			   IF TokenLength > cMaxStrLength THEN
			      ErrorMessage (StringTooLong, Restriction, Attribute.Position);
			      ArrayToString (" ", TargetCode);
			   ELSIF TokenLength = 2 THEN
			      ErrorMessage (StringTooShort, Error, Attribute.Position);
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
#STD, rules#	"{"	: {yyStart (set);	RETURN SymLBrace	;}
#rules#		"#"	: {RETURN SymNrSign	;}
#rules#		"/"	: {RETURN SymSlash	;}
#rules#		"<"	: {RETURN SymLess	;}
#rules#		">"	: {RETURN SymGreater	;}
#rules#		":"	: {PrevState := rules; yyStart (targetcode); RETURN SymColon;}
#rules#		":-"	: {PrevState := rules; yyStart (targetcode); RETURN SymColonMinus;}

#STD, set, rules# \\ n	: {Attribute.Ch := 012C; RETURN SymChar;}
#STD, set, rules# \\ t	: {Attribute.Ch := 011C; RETURN SymChar;}
#STD, set, rules# \\ v	: {Attribute.Ch := 013C; RETURN SymChar;}
#STD, set, rules# \\ b	: {Attribute.Ch := 010C; RETURN SymChar;}
#STD, set, rules# \\ r	: {Attribute.Ch := 015C; RETURN SymChar;}
#STD, set, rules# \\ f	: {Attribute.Ch := 014C; RETURN SymChar;}

#STD, set, rules# \\ digit + : {
			   GetWord (Word);
			   SubString (Word, 2, Length (Word), TargetCode);
			   Attribute.Ch := CHR (CARDINAL (StringToInt (TargetCode)));
	  		   RETURN SymChar;
			}

#STD, set, rules# \\ ANY : {
			   GetWord (Word);
			   Attribute.Ch := Char (Word, 2);
	  		   RETURN SymChar;
			}

#STD, set, rules# \\ / \r \n : {
			   Attribute.Ch := '\';
	  		   RETURN SymChar;
			}

#STD, set, rules# - {\ \t\n\f\r\26} : {
			   GetWord (Word);
			   Attribute.Ch := Char (Word, 1);
	  		   RETURN SymChar;
			}

\f , \r , \26		:- {}

#charset0# "{"		: {yyStart (charset); IsChar := TRUE; RETURN SymLBrace;}

#charset# digit		: {
			   IsChar := NOT IsChar;
			   GetWord (Word);
			   IF NOT IsChar THEN
			      Attribute.Ch := Char (Word, 1);
			      RETURN SymChar;
			   ELSE
			      Attribute.Number := StringToInt (Word);
			      RETURN SymNumber;
			   END;
			}

#charset# "0" octdigit *	: {
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

#charset# \\ n		: {Attribute.Ch := 012C; IsChar := FALSE; RETURN SymChar;}
#charset# \\ t		: {Attribute.Ch := 011C; IsChar := FALSE; RETURN SymChar;}
#charset# \\ v		: {Attribute.Ch := 013C; IsChar := FALSE; RETURN SymChar;}
#charset# \\ b		: {Attribute.Ch := 010C; IsChar := FALSE; RETURN SymChar;}
#charset# \\ r		: {Attribute.Ch := 015C; IsChar := FALSE; RETURN SymChar;}
#charset# \\ f		: {Attribute.Ch := 014C; IsChar := FALSE; RETURN SymChar;}

#charset# \\ ANY	: {
			   IsChar := FALSE;
			   GetWord (Word);
			   Attribute.Ch := Char (Word, 2);
	  		   RETURN SymChar;
			}

#charset# - {\ \t\n\f\r\26\}} : {
			   IsChar := FALSE;
			   GetWord (Word);
			   Attribute.Ch := Char (Word, 1);
	  		   RETURN SymChar;
			}

#charset# "}" / {\ \t\n} * digit	: {
			   IsChar := FALSE;
			   Attribute.Ch := '}';
	  		   RETURN SymChar;
			}

#charset# "}"		: {yyStart (STD); RETURN SymRBrace;}
