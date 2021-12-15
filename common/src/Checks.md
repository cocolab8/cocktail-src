(* check i/o errors *)

(* $Id: Checks.md,v 1.3 1997/05/27 14:58:14 grosch rel $ *)

(*
 * $Log: Checks.md,v $
 * Revision 1.3  1997/05/27 14:58:14  grosch
 * cosmetic changes
 *
 * Revision 1.2  1990/06/12 18:33:30  grosch
 * layout improvements
 *
 * Revision 1.1  89/01/31	15:56:41  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE Checks;

FROM	IO		IMPORT	tFile;

PROCEDURE ErrorCheck	 (s: ARRAY OF CHAR; n: INTEGER);
PROCEDURE CheckReadOpen	 (VAR f: tFile; s: ARRAY OF CHAR);
PROCEDURE CheckWriteOpen (VAR f: tFile; s: ARRAY OF CHAR);
PROCEDURE CheckOpenInput (VAR f: tFile; s: ARRAY OF CHAR);
PROCEDURE CheckOpenOutput (VAR f: tFile; s: ARRAY OF CHAR);

END Checks.
