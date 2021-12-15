(* $Id: Info.md,v 2.1 1992/08/07 15:47:31 grosch rel $ *)

DEFINITION MODULE Info;

FROM	IO		IMPORT	tFile;
FROM	Sets		IMPORT	tSet;
FROM	SYSTEM		IMPORT	ADDRESS;

PROCEDURE SaveInfo (InfoClass: INTEGER; Info: ADDRESS): ADDRESS;
PROCEDURE WriteInfo (InfoClass: INTEGER; Info: ADDRESS);

PROCEDURE WriteIdentSet (f: tFile; s: tSet);

END Info.
