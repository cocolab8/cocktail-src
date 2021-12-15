/* $Id:$ */

/*
 * $Log:$
 *
 */

SCANNER Writer

EXPORT {
FROM	Position	IMPORT	tPosition, WritePosition;
FROM	Texts		IMPORT	tText;
FROM	Idents		IMPORT	tIdent;

TYPE tScanAttribute	= RECORD Position: tPosition; END;
}

GLOBAL {
FROM	Position	IMPORT	WritePosition;
FROM	Strings		IMPORT	tString;
FROM	Idents		IMPORT	tIdent,		NoIdent,	MakeIdent,
				WriteIdent;
FROM	Texts		IMPORT	tText,		WriteText;
FROM	Reader		IMPORT	TextList, MaxTextId;

VAR	Word		: tString;
	TextId		: tIdent;

PROCEDURE ErrorMsg (msg: ARRAY OF CHAR);
BEGIN
   WritePosition (IO.StdError, Attribute.Position);
   IO.WriteS (IO.StdError, ": ");
   IO.WriteS (IO.StdError, msg);
   IO.WriteNl (IO.StdError);
END ErrorMsg;
}

START	GetId, CheckId, Skipping

DEFINE TEXT = - { \n \r } * .

RULE

#STD#		< \+ " "*	:- {
					yyStart (Skipping);
				}

#STD#		< \? " "*	:- {
					yyStart (GetId);
				}

#GetId#		{a-z A-Z 0-9 . _}+	: {
					yyStart (STD);
					GetWord (Word);
					TextId := MakeIdent (Word);
					(* we could have ?name without any +name *)
					IF TextId <= MaxTextId THEN
					   WriteText (IO.StdOutput, TextList^ [TextId]);
					END;
				}

/* This gets rid of the white space introduced by cpp
   when a macro expands to nothing */
#STD#		" "+ \n		:- { yyEol (0); }

#STD#		- { ?+ \n \r} TEXT
				:- {
					yyEcho;
				}

/* This gets rid of the white space introduced by cpp */
#STD#		\n \r? / (\r? \n \r? \n)	:- { yyEol (0); }
#STD#		\n \r?				:- { yyEol (0); yyEcho; }

#Skipping#	< \= " "*	:- {
					yyStart (CheckId);
				}

#Skipping#	- { = \n \r } TEXT	:- {}


#CheckId#	{a-z A-Z 0-9 . _}+		:- {
				}

#CheckId#	ANY		:- {}

#CheckId#	\n		:- {
					yyEol (0);
					yyStart (STD);
				}

\r			: {}

