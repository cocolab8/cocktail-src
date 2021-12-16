/* $Id: Estral.rex,v 2.4 2021/10/28 09:11:39 grosch Exp $ */

EXPORT
{
FROM	Idents		IMPORT	tIdent;
FROM	StringM		IMPORT	tStringRef;
FROM	Position	IMPORT	tPosition;

CONST
  SymLParent		=  1	;
  SymRParent		=  2	;
  SymComma		=  3	;
  SymDot		=  4	;
  SymSlash		=  5	;
  SymColon		=  6	;
  SymSemiColon		=  7	;
  SymEqual		=  8	;
  SymBar		= 11	;
  SymLBrace		= 12	;
  SymRBrace		= 13	;

  SymRArrow		= 15	;

  SymBEGIN		= 21	;
  SymCLOSE		= 22	;
  SymCONDITION		= 23	;
  SymCOSTS		= 24	;
  SymDECLARE		= 25	;
  SymEXPORT		= 26	;
  SymGLOBAL		= 27	;
  SymGRAMMAR		= 28	;
  SymLOCAL		= 29	;
  SymFUNCTION		= 30	;
  SymTRANSFORMATION	= 31	;

  SymIdent		= 41	;
  SymNumber		= 42	;
  SymString		= 43	;

  SymCodeLBrace		= 51	;
  SymCodeRBrace		= 52	;
  SymCodeDot		= 53	;
  SymCodeLParent	= 54	;
  SymCodeRParent	= 55	;
  SymCodeIdent		= 56	;
  SymCodeString		= 57	;
  SymCodeSpace		= 58	;
  SymCodeComment	= 59	;
  SymCodeRest		= 60	;
  SymCodeComma		= 61	;
  
TYPE
  tScanAttribute	= RECORD
			    Position: tPosition;
			    CASE :INTEGER OF
			    | SymIdent, SymString, SymCodeIdent, SymCodeString:
				ident: tIdent;
			    | SymCodeSpace .. SymCodeRest, SymCodeComma:
				ref: tStringRef;
			    | SymNumber:
				val: INTEGER;
			    END;
			  END;

CONST
  NoValue	= -1;

VAR
  NoIdent	: tIdent;
  MaxIdent	: tIdent;
  NoStringRef	: tStringRef;
  MaxValue	: INTEGER;


PROCEDURE ErrorAttribute (Symbol: INTEGER; VAR Attribute: tScanAttribute);

}

GLOBAL
{
FROM	Errors		IMPORT	eError, eWarning, eCharacter, ErrorMessage, ErrorMessageI;
FROM	Position	IMPORT	tPosition;
FROM	Idents		IMPORT	MakeIdent;
FROM	Strings		IMPORT	tString, AssignEmpty, Append, Concatenate,
				StringToInt, ArrayToString, Char;
FROM	StringM		IMPORT	tStringRef, PutString;
FROM	SYSTEM		IMPORT	ADR;

IMPORT	Idents;

CONST
  eEolString		= 21	;	(* string exceeds line *)
  eEofCode		= 22	;	(* code exceeds file *)
  eEofString		= 23	;	(* string exceeds file *)
  eEofComment		= 24	;	(* comment exceeds file *)
  eIllegalChar		= 25	;	(* illegal character *)
  eDoNotUseYY		= 26	;	(* prefix yy is reserved *)

VAR
  word, string	: tString;
  char		: CHAR;
  level, clevel	: INTEGER;
  CodePos, CommentPos	: tPosition;



PROCEDURE ErrorAttribute (Symbol: INTEGER; VAR Attribute: tScanAttribute);
  BEGIN
    CASE Symbol OF
    | SymIdent, SymString, SymCodeIdent, SymCodeString:
	Attribute.ident := NoIdent;
    | SymCodeSpace .. SymCodeRest:
	Attribute.ref := NoStringRef;
    | SymNumber:
	Attribute.val := NoValue;
    ELSE
    END;
  END ErrorAttribute;
}

BEGIN {
ArrayToString ('_no_string_ref_', word);
NoStringRef := PutString (word);
ArrayToString ('_no_identifier_', word);
NoIdent := MakeIdent (word);
MaxValue := 0;
}

CLOSE { MaxIdent := Idents.MaxIdent (); }

EOF	{
CASE yyStartState OF
| STD: ;
| code: ErrorMessage (eEofCode, eError, CodePos);
| str1, str2, codestr1, codestr2: ErrorMessage (eEofString, eError, Attribute.Position);
| codecom1, codecom2: ErrorMessage (eEofComment, eError, CommentPos);
| comment1, comment2: ErrorMessage (eEofComment, eError, Attribute.Position);
END;
}

DEFINE
  letter	= {A-Za-z} .
  digit		= {0-9} .

START	code, str1, str2, comment1, comment2,
	codestr1, codestr2, codecom1, codecom2

RULES
	/*	--------	STD	--------	*/

#STD#	"/*"		: { yyStart (comment1);			}
#STD#	"(*"		: { level := 1; yyStart (comment2);	}

#STD#	"("		: { RETURN SymLParent;		}
#STD#	")"		: { RETURN SymRParent;		}
#STD#	","		: { RETURN SymComma;		}
#STD#	"."		: { RETURN SymDot;		}
#STD#	"/"		: { RETURN SymSlash;		}
#STD#	":"		: { RETURN SymColon;		}
#STD#	";"		: { RETURN SymSemiColon;	}
#STD#	"="		: { RETURN SymEqual;		}
#STD#	"|"		: { RETURN SymBar;		}

#STD#	"->"		: { RETURN SymRArrow;		}

#STD#	\BEGIN		: { RETURN SymBEGIN;		}
#STD#	\CLOSE		: { RETURN SymCLOSE;		}
#STD#	CONDITION	: { RETURN SymCONDITION;	}
#STD#	COSTS		: { RETURN SymCOSTS;		}
#STD#	DECLARE		: { RETURN SymDECLARE;		}
#STD#	\EXPORT		: { RETURN SymEXPORT;		}
#STD#	\GLOBAL		: { RETURN SymGLOBAL;		}
#STD#	GRAMMAR		: { RETURN SymGRAMMAR;		}
#STD#	\LOCAL		: { RETURN SymLOCAL;		}
#STD#	FUNCTION	: { RETURN SymFUNCTION;		}
#STD#	TRANSFORMATION	: { RETURN SymTRANSFORMATION;	}

#STD#	yy (letter | digit | "_") +
			: {
			ErrorMessage (eDoNotUseYY, eWarning, Attribute.Position);
			GetWord (word);
			Attribute.ident := MakeIdent (word);
			RETURN SymIdent;
			}

#STD#	letter (letter | digit | "_") *
			: {
			GetWord (word);
			Attribute.ident := MakeIdent (word);
			RETURN SymIdent;
			}

#STD#	digit +		: {
			GetWord (word);
			Attribute.val := StringToInt (word);
			IF Attribute.val > MaxValue THEN
			  MaxValue := Attribute.val
			END;
			RETURN SymNumber;
			}

#STD#	\'		: { GetWord (string); yyStart (str1); }

#STD#	\"		: { GetWord (string); yyStart (str2); }

#STD#	"{"		: {
			CodePos := Attribute.Position;
			yyStart (code);
			clevel := 1;
			RETURN SymLBrace;
			}

#STD#	\r		: {}

#STD#	- {\r\n\t\ }	: {
			GetWord (word);
			char := Char (word, 1);
			ErrorMessageI (eIllegalChar, eError, Attribute.Position,
				       eCharacter, ADR (char));
			}

	/*	--------	str1, str2	--------	*/

#str1#	- {\r\n\t'} +	:- {
			GetWord (word);
			Concatenate (string, word);
			}

#str1#	\t		:- {
			GetWord (word);
			yyTab;
			Concatenate (string, word);
			}

#str1#	\r ? \n		:- {
			Append (string, "'"); yyEol (0);
			ErrorMessage (eEolString, eError, Attribute.Position);
			Attribute.ident := MakeIdent (string);
			yyStart (STD);
			RETURN SymString;
			}

#str1#	\'		:- {
			GetWord (word);
			Concatenate (string, word);
			Attribute.ident := MakeIdent (string);
			yyStart (STD);
			RETURN SymString;
			}


#str2#	- {\r\n\t"} +	:- {
			GetWord (word);
			Concatenate (string, word);
			}

#str2#	\t		:-
			{
			GetWord (word);
			yyTab;
			Concatenate (string, word);
			}

#str2#	\r ? \n		:- {
			Append (string, '"'); yyEol (0);
			ErrorMessage (eEolString, eError, Attribute.Position);
			Attribute.ident := MakeIdent (string);
			yyStart (STD);
			RETURN SymString;
			}

#str2#	\"		:- {
			GetWord (word);
			Concatenate (string, word);
			Attribute.ident := MakeIdent (string);
			yyStart (STD);
			RETURN SymString;
			}


	/*	--------	comment1, comment2	--------	*/

#comment1#	"*/"	:- { yyStart (STD); }
#comment1#	- {\n\t*} + :- {}
#comment1#	"*"	:- {}
		
#comment2#	"(*"	:- { INC (level); }
#comment2#	"*)"	:- {
			DEC (level);
			IF level = 0 THEN
			  yyStart (STD);
			END;
			}
#comment2#	- {\n\t*(} + :- {}
#comment2#	"*"	:- {}
#comment2#	"("	:- {}



	/*	--------	code	--------	*/

#code#	"/*"		: {
			CommentPos := Attribute.Position;
			GetWord (string);
			yyStart (codecom1);
			}

#code#	"(*"		: {
			CommentPos := Attribute.Position;
			GetWord (string);
			level := 1;
			yyStart (codecom2);
			}

#code#	"."		: { RETURN SymCodeDot; }
#code#	","		: { RETURN SymCodeComma; }
#code#	"("		: { RETURN SymCodeLParent; }
#code#	")"		: { RETURN SymCodeRParent; }

#code#	"{"		: {
			INC (clevel);
			RETURN SymCodeLBrace;
			}

#code#	"}"		: {
			DEC (clevel);
			IF clevel = 0 THEN
			  yyStart (STD);
			  RETURN SymRBrace;
			ELSE
			  RETURN SymCodeRBrace;
			END;
			}

#code#	yy (letter | digit | "_") *
			: {
			ErrorMessage (eDoNotUseYY, eWarning, Attribute.Position);
			GetWord (word);
			Attribute.ident := MakeIdent (word);
			RETURN SymCodeIdent;
			}

#code#	letter (letter | digit | "_") *
			: {
			GetWord (word);
			Attribute.ident := MakeIdent (word);
			RETURN SymCodeIdent;
			}

#code#	\'		: { GetWord (string); yyStart (codestr1); }
#code#	\' - {\r\n\t'} * \' : { 
			GetWord (word);
			Attribute.ident := MakeIdent (word);
			RETURN SymCodeString;
			}

#code#	\"		: { GetWord (string); yyStart (codestr2); }

#code#	" " +		: {
			GetWord (string);
			Attribute.ref := PutString (string);
			RETURN SymCodeSpace;
			}

#code#	\t		: {
			GetWord (string);
			Attribute.ref := PutString (string);
			yyTab;
			RETURN SymCodeSpace;
			}

#code#	\r ? \n		: {
			GetWord (string);
			Attribute.ref := PutString (string);
			yyEol (0);
			RETURN SymCodeSpace;
			}

#code#	- {'"A-Za-z0-9./\{\}()\r\t\n\ } +
	| - {\r\n\t}	: {
			GetWord (string);
			Attribute.ref := PutString (string);
			RETURN SymCodeRest;
			}


	/*	--------	codestr1, codestr2	--------	*/

#codestr1# - {\r\n\t'} + :- {
			GetWord (word);
			Concatenate (string, word);
			}

#codestr1#	\t	:- {
			GetWord (word);
			yyTab;
			Concatenate (string, word);
			}

#codestr1#	\r ? \n	:- {
			Append (string, "'"); yyEol (0);
			ErrorMessage (eEolString, eError, Attribute.Position);
			Attribute.ident := MakeIdent (string);
			yyStart (code);
			RETURN SymCodeString;
			}

#codestr1#	\'	:- {
			GetWord (word);
			Concatenate (string, word);
			Attribute.ident := MakeIdent (string);
			yyStart (code);
			RETURN SymCodeString;
			}


#codestr2# - {\r\n\t"} + :- {
			GetWord (word);
			Concatenate (string, word);
			}

#codestr2#	\t	:-
			{
			GetWord (word);
			yyTab;
			Concatenate (string, word);
			}

#codestr2#	\r ? \n	:- {
			Append (string, '"'); yyEol (0);
			ErrorMessage (eEolString, eError, Attribute.Position);
			Attribute.ident := MakeIdent (string);
			yyStart (code);
			RETURN SymCodeString;
			}

#codestr2#	\"	:- {
			GetWord (word);
			Concatenate (string, word);
			Attribute.ident := MakeIdent (string);
			yyStart (code);
			RETURN SymCodeString;
			}

	  /*	--------	codecom1, codecom2	--------	*/

#codecom1#	"*/"	:- {
			GetWord (word);
			Concatenate (string, word);
			Attribute.ref := PutString (string);
			yyStart (code);
			RETURN SymCodeComment;
			}

#codecom1#	- {\r\n\t*} + :- {
			GetWord (word);
			Concatenate (string, word);
			}

#codecom1#	\t	:- {
			GetWord (word);
			Concatenate (string, word);
			yyTab;
			}

#codecom1#	\r ? \n	:- {
			GetWord (word);
			Concatenate (string, word);
			Attribute.ref := PutString (string);
			AssignEmpty (string);
			yyEol (0);
			RETURN SymCodeRest;
			}

#codecom1#	"*"	:- {
			GetWord (word);
			Concatenate (string, word);
			}
		
#codecom2#	"(*"	:- {
			GetWord (word);
			Concatenate (string, word);
			INC (level);
			}

#codecom2#	"*)"	:- {
			GetWord (word);
			Concatenate (string, word);
			DEC (level);
			IF level = 0 THEN
			  yyStart (code);
			  Attribute.ref := PutString (string);
			  RETURN SymCodeComment;
			END;
			}

#codecom2#	- {\r\n\t*(} + :- {
			GetWord (word);
			Concatenate (string, word);
			}

#codecom2#	\t	:- {
			GetWord (word);
			Concatenate (string, word);
			yyTab;
			}

#codecom2#	\r ? \n	:- {
			GetWord (word);
			Concatenate (string, word);
			Attribute.ref := PutString (string);
			AssignEmpty (string);
			yyEol (0);
			RETURN SymCodeRest;
			}

#codecom2#	"*" | "(" :- {
			GetWord (word);
			Concatenate (string, word);
			}
		
