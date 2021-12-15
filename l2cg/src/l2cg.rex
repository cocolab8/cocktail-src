/* $Id: l2cg.rex,v 1.9 2013/01/15 13:33:23 grosch Exp $ */

/*
 * $Log: l2cg.rex,v $
 * Revision 1.9  2013/01/15 13:33:23  grosch
 * added comments for improved syntax highlighting
 *
 * Revision 1.8  2008/08/25 13:10:13  grosch
 * cared for pointer operations on 64 bit platforms: introduced module Pointers
 *
 * Revision 1.7  2005/05/23 13:29:09  grosch
 * added line comments: // ...
 *
 * Revision 1.6  2002/05/24 20:22:23  grosch
 * update to recent language extensions
 *
 * Revision 1.5  2000/04/03 10:30:44  grosch
 * added missing assignment of Attribute.Position
 *
 * Revision 1.4  1997/05/27 15:47:12  grosch
 * truncated module names to 8 characters: StringM, Position
 *
 * Revision 1.3  1996/07/04 09:09:02  grosch
 * added syntax for predicates
 *
 * Revision 1.2  1996/05/14  20:17:56  grosch
 * fixed bug for MS-DOS at \ \r \n
 * replaced lalr by lark and use Errors.[hc] from reuse
 *
 * Revision 1.1  1995/02/23  20:00:07  grosch
 * added tokens START and ','
 *
 * Revision 1.0  1993/08/17  16:27:45  grosch
 * Initial revision
 *
 * Revision 2.3  1992/08/07  15:15:11  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 2.2  1991/12/04  16:21:41  grosch
 * unified escape conventions for all tools
 *
 * Revision 2.1  1991/11/21  14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 2.0  91/03/08  18:26:49  grosch
 * turned tables into initialized arrays (in C)
 * moved mapping tokens -> strings from Errors to Parser
 * changed interface for source position
 * 
 * Revision 1.3  90/06/11  18:47:51  grosch
 * allow keywords as token names, layout improvements
 * 
 * Revision 1.2  88/12/16  15:03:42  vielsack
 * identifier may now start with backslash ('\') which isn't significant
 * this can be used to define identifiers which are keywords
 * 
 * Revision 1.1  88/10/20  08:51:24  vielsack
 * use tScanAttribute instead of tAttribute
 * 
 * Revision 1.0  88/10/04  14:27:33  vielsack
 * Initial revision
 * 
 */

EXPORT	{

FROM Position	IMPORT tPosition;
FROM Idents	IMPORT tIdent;
FROM Lists      IMPORT tList;

TYPE
   AttributeMode = (Keys, Comment, Number, Action, Symbol, Coding, PrioPart, RightSide, Empty);

   tScanAttribute=
      RECORD
	 Position: tPosition;
	 CASE Mode: AttributeMode OF
	 | Comment: Comm   : tList;
	 | Number: Value   : CARDINAL;
	 | Action: Act     : tList;
	 | Symbol: Ident   : tIdent;
	 END;
      END;

PROCEDURE ErrorAttribute (Token: INTEGER; VAR Attr: tScanAttribute);
}

GLOBAL	{

FROM SYSTEM	IMPORT ADR, ADDRESS;
FROM Pointers	IMPORT INTPTR;
FROM Errors	IMPORT Warning, Error, Character, String, Message, MessageI;
FROM Lists	IMPORT tList, Append, MakeList;
FROM Strings	IMPORT tString, ArrayToString, Concatenate, SubString, AssignEmpty, Assign, Char, Length;
FROM StringM	IMPORT tStringRef, PutString;
FROM Idents	IMPORT MakeIdent;

CONST
  SymEqual	=  1;
  SymColon	=  2;
  SymPoint	=  3;
  SymOr		=  4;
  SymStar	=  5;
  SymPlus	=  6;
  SymList	=  7;
  SymLBrace	=  8;
  SymRBrace	=  9;
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
  SymComment	= 24; (* Schreibweise wie in MODULA-2		*)
  SymNumber	= 25; (* vorzeichenlose ganze Zahl		*)
  SymAction	= 26; (* in '{' und '}' eingeschlossene Aktion	*)
  SymIdentifier	= 27; (* letter (digit | letter) *		*)
  SymString	= 28; (* durch "'" oder '"' begrenzte Zeichenkette *)
  SymSCANNER	= 29;
  SymPARSER	= 30;
  SymSTART	= 31;
  SymComma	= 32;
  SymQuestion	= 33;
  SymMinus	= 34;
  SymIMPORT	= 35;

VAR level: INTEGER;

PROCEDURE ErrorAttribute (Token: INTEGER; VAR Attr: tScanAttribute);
  VAR s : tString;
  BEGIN
    Attr.Position := Attribute.Position;
    ArrayToString ('-error-', s);
    CASE Token OF
      0: ;
    | 1..23:  Attr.Mode	:= Keys;
    | 	 24:  Attr.Mode	:= Comment;
	      MakeList (Attr.Comm);
    |    25:  Attr.Mode	:= Number;
	      Attr.Value:= 0;
    |    26:  Attr.Mode	:= Action;
	      MakeList (Attr.Act);
    | 27,28:  Attr.Mode	:= Symbol;
	      Attr.Ident:= MakeIdent (s);
    END;
  END ErrorAttribute;

PROCEDURE GetNumber (VAR Word: tString): CARDINAL;
  VAR i, n, d : CARDINAL;
   BEGIN
      i := 0;
      n := 0;
      WHILE i < Length (Word) DO
	i := i+1;
	d := (ORD(Char (Word, i))-ORD('0'));
	n := n*10 + d;
      END;
      RETURN n;
   END GetNumber;
}

LOCAL	{ VAR Word, String, LastWord: tString; c: CHAR; PrevState: SHORTCARD; }

EOF	{
CASE yyStartState OF
| code			: Message ("unclosed action" , Error, Attribute.Position);
| comment, comment2	: Message ("unclosed comment", Error, Attribute.Position);
| Str1, Str2, CStr1, CStr2:Message ("unclosed string", Error, Attribute.Position);
ELSE
END;
}

DEFINE
  digit		= {0-9}		.
  letter	= {a-z A-Z _}	.
  cmt		= - {*(\t\n}	.
  cmt2		= - {*\t\n}	.
  codechar	= - {\\{\}\t\n\r'"} .					// vi "
  StrCh1	= - {'\t\n\r}	.
  StrCh2	= - {"\t\n\r}	.					// vi "
  CStrCh1	= - {'\t\n\r\\}	.
  CStrCh2	= - {"\t\n\r\\}	.					// vi "

START token, rule, code, Str1, Str2, CStr1, CStr2, comment, comment2

RULES

#token#	"="	: { Attribute.Mode := Keys; RETURN SymEqual	; }
#rule#	":"	: { Attribute.Mode := Keys; RETURN SymColon	; }
#rule#	"."	: { Attribute.Mode := Keys; RETURN SymPoint	; }
#rule#	"|"	: { Attribute.Mode := Keys; RETURN SymOr	; }
#rule#	"*"	: { Attribute.Mode := Keys; RETURN SymStar	; }
#rule#	"+"	: { Attribute.Mode := Keys; RETURN SymPlus	; }
#rule#	"||"	: { Attribute.Mode := Keys; RETURN SymList	; }
#rule#	"("	: { Attribute.Mode := Keys; RETURN SymLBrace	; }
#rule#	")"	: { Attribute.Mode := Keys; RETURN SymRBrace	; }
#rule#	"["	: { Attribute.Mode := Keys; RETURN SymLBracket	; }
#rule#	"]"	: { Attribute.Mode := Keys; RETURN SymRBracket	; }
#rule#	"?"	: { Attribute.Mode := Keys; RETURN SymQuestion	; }
#rule#	"-"	: { Attribute.Mode := Keys; RETURN SymMinus	; }
#STD#	\SCANNER: { Attribute.Mode := Keys; RETURN SymSCANNER	; }
#STD#	\PARSER	: { Attribute.Mode := Keys; RETURN SymPARSER	; }
#STD#	\IMPORT	: { Attribute.Mode := Keys; RETURN SymIMPORT	; }
#STD#	\EXPORT	: { Attribute.Mode := Keys; RETURN SymEXPORT	; }
#STD#	\GLOBAL	: { Attribute.Mode := Keys; RETURN SymGLOBAL	; }
#STD#	\LOCAL	: { Attribute.Mode := Keys; RETURN SymLOCAL	; }
#STD#	\BEGIN	: { Attribute.Mode := Keys; RETURN SymBEGIN	; }
#STD#	\CLOSE	: { Attribute.Mode := Keys; RETURN SymCLOSE	; }
#STD#	TOKEN	: { Attribute.Mode := Keys; yyStart (token); RETURN SymTOKEN	; }

#token#	OPER	: { Attribute.Mode := Keys; RETURN SymOPER	; }
#token#	NONE	: { Attribute.Mode := Keys; RETURN SymNONE	; }
#token#	LEFT	: { Attribute.Mode := Keys; RETURN SymLEFT	; }
#token#	RIGHT	: { Attribute.Mode := Keys; RETURN SymRIGHT	; }
#token#	START	: { Attribute.Mode := Keys; RETURN SymSTART	; }
#token#	","	: { Attribute.Mode := Keys; RETURN SymComma	; }
#token#	RULE	: { Attribute.Mode := Keys; yyStart (rule); RETURN SymRULE	; }

#rule#	PREC	: { Attribute.Mode := Keys; RETURN SymPREC	; }

#token#	digit +	:
{
  Attribute.Mode := Number;
  GetWord (Word);
  Attribute.Ident := MakeIdent (Word);
  Attribute.Value := GetNumber (Word);
  RETURN SymNumber;
}

#STD, token, rule#	\\ letter (letter | digit) *	:
{
  Attribute.Mode := Keys;
  GetWord (Word);
  SubString (Word, 2, Length (Word), String);
  Attribute.Ident := MakeIdent (String);
  RETURN SymIdentifier;
}

#STD, token, rule#	letter (letter | digit) *	:
{
  Attribute.Mode := Keys;
  GetWord (Word);
  Attribute.Ident := MakeIdent (Word);
  RETURN SymIdentifier;
}

#STD, rule#	"{"	:
{
  PrevState := yyStartState;
  yyStart (code);
  GetWord (LastWord);
  Attribute.Mode := Action;
  MakeList (Attribute.Act);
  level := 1;
}

#STD, token, rule# \f | \r | \26 :- {}

#token, rule, code# '	: { GetWord (String); Attribute.Mode := Symbol; yyStart (CStr1); }

#token, rule, code# \"	:						// vi "
			  { GetWord (String); Attribute.Mode := Symbol; yyStart (CStr2); }

#Str1#	StrCh1  + | \'\'	,
#Str2#	StrCh2  + | \"\"	,					// vi "
#CStr1#	CStrCh1 + | \\ ANY ?	,
#CStr2#	CStrCh2 + | \\ ANY ? :- {GetWord (Word); Concatenate (String, Word);}

#CStr1, CStr2# \\ \r ? \n:-{Strings.Append (String, '\');
			    Strings.Append (String, 12C); yyEol (0);}

#Str1, CStr1# '		,
#Str2, CStr2# \"	:-						// vi "
			   {Strings.Append (String, Char (String, 1));
			    yyPrevious;
			    IF yyStartState = code THEN
			       Concatenate (LastWord, String);
			    ELSE
  			       Attribute.Ident := MakeIdent (String);
  			       RETURN SymString;
			    END;}

#Str1, Str2, CStr1, CStr2# \t :- {Strings.Append (String, 11C); yyTab;}

#Str1, Str2, CStr1, CStr2# \r ? \n : {Message ("string exceeds line", Error, Attribute.Position);
			    Strings.Append (String, 12C);
			    yyEol (0); yyPrevious;
			    IF yyStartState = code THEN
			       Concatenate (LastWord, String);
			    ELSE
  			       Attribute.Ident := MakeIdent (String);
			       RETURN SymString;
			    END;}

#Str1, Str2, CStr1, CStr2# \r :- {Strings.Append (String, 15C);}

#STD, token, rule#	"(*"	:
{
  yyStart (comment);
  GetWord (LastWord);
  Attribute.Mode := Comment;
  MakeList (Attribute.Comm);
  level := 1;
}

#STD, token, rule#	"/*"	:- { yyStart (comment2); }

#STD, token, rule#	"//" ANY *	:- {}

#STD, token, rule#	- {\t\n\f\r\ }	:
{
  GetWord (Word);
  c := Char (Word, 1);
  MessageI ("character ignored", Warning, Attribute.Position, Character, ADR (c));
}

#code#	\\ ANY | codechar + | \r :-
{
  GetWord (Word);
  Concatenate (LastWord, Word);
}

#code#	\\ / \r ? \n ,
#code#	\\	:
{
  c := '\';
  MessageI ("character ignored", Warning, Attribute.Position, Character, ADR (c));
}

#code#	\t	:-
{
  yyTab;
  GetWord (Word);
  Concatenate (LastWord, Word);
}

#code#	\r ? \n	:-
{
  Strings.Append (LastWord, 12C);
  Append (Attribute.Act, INTPTR (PutString (LastWord)));
  AssignEmpty (LastWord);
  yyEol (0);
}

#code#	"{"	:-
{
  GetWord (Word);
  Concatenate (LastWord, Word);
  INC (level);
}

#code#	"}"	:-
{
  DEC (level);
  GetWord (Word);
  Concatenate (LastWord, Word);
  IF level = 0 THEN
    yyStart (PrevState);
    Append (Attribute.Act, INTPTR (PutString (LastWord)));
    RETURN SymAction;
  END;
}

#comment#	"(*"	:-
{
  GetWord (Word);
  Concatenate (LastWord, Word);
  INC (level);
}

#comment#	"*)"	:-
{
  DEC (level);
  GetWord (Word);
  Concatenate (LastWord, Word);
  IF level = 0 THEN
    yyPrevious;
    Append (Attribute.Comm, INTPTR (PutString (LastWord)));
    RETURN SymComment;
  END;
}

#comment#	"(" | "*" | cmt +	:-
{
  GetWord (Word);
  Concatenate (LastWord, Word);
}

#comment#	\t	:-
{
  yyTab;
  GetWord (Word);
  Concatenate (LastWord, Word);
}

#comment#	\n	:-
{
  GetWord (Word);
  Concatenate (LastWord, Word);
  Append (Attribute.Comm, INTPTR (PutString (LastWord)));
  AssignEmpty (LastWord);
  yyEol (0);
}

#comment2#	"*" | cmt2 +	:- { }
#comment2#	"*/"		:- { yyPrevious; }

< "#@ line" ANY *		:- { }
