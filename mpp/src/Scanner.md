(* $Id: Scanner.md,v 1.4 1998/05/27 15:21:15 grosch rel $ *)

DEFINITION MODULE Scanner;

FROM Position	IMPORT tPosition;

TYPE tScanAttribute	= RECORD Position: tPosition; Ch: CHAR; END;

VAR Attribute	: tScanAttribute;

PROCEDURE BeginScanner;
PROCEDURE CloseScanner;
PROCEDURE GetToken (): CARDINAL;
PROCEDURE ErrorAttribute (Symbol: CARDINAL; VAR Attribute: tScanAttribute);

END Scanner.
