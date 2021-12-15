(* $Id: Convert.md,v 1.2 1997/05/27 14:58:14 grosch rel $ *)

DEFINITION MODULE Convert;

FROM Idents	IMPORT	tIdent;
FROM SYSTEM	IMPORT	ADDRESS;

(* procedures to convert tIdent to ADDRESS and vice versa *)

PROCEDURE IdToAdr (id: tIdent): ADDRESS;
PROCEDURE AdrToId (adr: ADDRESS): tIdent;

END Convert.
