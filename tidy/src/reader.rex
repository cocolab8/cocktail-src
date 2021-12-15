/* $Id:$ */

/*
 * $Log:$
 *
 */

SCANNER Reader

EXPORT {
FROM	Position	IMPORT	tPosition, WritePosition;
FROM	Texts		IMPORT	tText;
FROM	Idents		IMPORT	tIdent;

TYPE tScanAttribute	= RECORD Position: tPosition; END;

VAR	TextList	: POINTER TO ARRAY [1 .. 1000000] OF tText;
	MaxTextId	: tIdent;
}

GLOBAL {
FROM	Position	IMPORT	WritePosition;
FROM	Strings		IMPORT	tString,	AssignEmpty;
FROM	Idents		IMPORT	tIdent,		NoIdent,	MakeIdent,
				WriteIdent,	InitIdents;
FROM	Texts		IMPORT	tText,		MakeText,	Append;

VAR	Word		: tString;
	TextId, EndId	: tIdent;
	TextListSize, I	: LONGINT;
	Text		: tText;

PROCEDURE ErrorMsg (msg: ARRAY OF CHAR);
BEGIN
   WritePosition (IO.StdError, Attribute.Position);
   IO.WriteS (IO.StdError, ": ");
   IO.WriteS (IO.StdError, msg);
   IO.WriteNl (IO.StdError);
END ErrorMsg;
}

BEGIN {
	InitIdents;
	TextListSize := 10;
	MaxTextId := 0;
	DynArray.MakeArray (TextList, TextListSize, SYSTEM.TSIZE (tText));
}

START	GetId, CheckId, Storing

DEFINE TEXT = - { \n \r } * .

RULE

#STD#		< \+ " "*	: {
					yyStart (GetId);
				}

#GetId#		{a-z A-Z 0-9 . _}+	: {
					yyStart (Storing);
					GetWord (Word);
					TextId := MakeIdent (Word);
					IF TextId > MaxTextId THEN
					   I := TextId; (* cast to longint *)
					   IF I >= TextListSize THEN
					      DynArray.ExtendArray (TextList,
					         TextListSize,
					         SYSTEM.TSIZE (tText));
					   END;
					   MakeText (Text);
					   MaxTextId := TextId;
					ELSE
					   Text := TextList^ [TextId];
					END;
					AssignEmpty (Word);
				}

#STD#		- {+\n\r} TEXT	: {}

#Storing#	< \= " "*	: {
					TextList^ [TextId] := Text;
					yyStart (CheckId);
				}

#Storing#	- { \= \n \r} TEXT
				: {
					GetWord (Word);
				}

#Storing#	" "+ \n \r?	: {	yyEol(0); }

#Storing#	\n \r?		: {
					yyEol(0);
					Append (Text, Word);
					AssignEmpty (Word);
				}

#CheckId#	{a-z A-Z 0-9 . _}+	: {
					GetWord (Word);
					EndId := MakeIdent (Word);
					IF EndId # TextId THEN
					   ErrorMsg ("ID mismatch");
					   IO.WriteS (IO.StdError, "           ");
					   WriteIdent (IO.StdError, TextId);
					   IO.WriteS (IO.StdError, " # ");
					   WriteIdent (IO.StdError, EndId);
					   IO.WriteNl (IO.StdError);
					END;
					yyStart (STD);
				}

\r	: {}

