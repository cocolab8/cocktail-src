(* check i/o errors *)

(* $Id: Checks.md,v 1.3 1997/05/27 15:14:05 grosch rel $ *)

(*
 * $Log: Checks.md,v $
 * Revision 1.3  1997/05/27 15:14:05  grosch
 * cosmetic changes
 *
 * Revision 1.2  1991/11/21 14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.1  90/06/11  18:44:42  grosch
 * layout improvements
 * 
 * Revision 1.0	 88/10/04  14:26:39  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE Checks;

FROM	IO		IMPORT	tFile;

PROCEDURE ErrorCheck	 (s: ARRAY OF CHAR; n: INTEGER);
PROCEDURE CheckReadOpen	 (VAR f: tFile; s: ARRAY OF CHAR);
PROCEDURE CheckWriteOpen (VAR f: tFile; s: ARRAY OF CHAR);

END Checks.
