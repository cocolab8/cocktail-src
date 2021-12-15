(* $Id: Table.md,v 1.1 1989/04/14 12:21:54 vielsack rel $ *)

DEFINITION MODULE Table;

FROM Strings	IMPORT	tString;

PROCEDURE Define	(letter: CHAR; VAR definition: tString);
PROCEDURE Translate	(letter: CHAR; VAR text: tString);
PROCEDURE BeginLine	;
PROCEDURE CloseLine	;
PROCEDURE WriteLine	(VAR text: tString);
PROCEDURE NewLine	;

END Table.
