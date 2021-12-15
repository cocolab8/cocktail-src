(* $Id: Complete.md,v 2.3 1998/05/27 15:23:55 grosch rel $ *)

DEFINITION MODULE Complete;

FROM	Environs	IMPORT	tFunction;
FROM	Idents		IMPORT	tIdent;
FROM	Position	IMPORT	tPosition;

VAR IsComplete: BOOLEAN;

PROCEDURE FunctionComplete (function: tFunction; ident: tIdent; pos: tPosition);

END Complete.
