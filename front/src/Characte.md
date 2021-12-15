(* handle strings with open character arrays *)

(* $Id: Characte.md,v 1.4 1997/05/27 15:04:18 grosch rel $ *)

(*
 * $Log: Characte.md,v $
 * Revision 1.4  1997/05/27 15:04:18  grosch
 * truncated module names to 8 characters:
 * Characte, StringM, Position
 *
 * Revision 1.3  1991/11/21 14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.2  90/06/11  18:44:40  grosch
 * layout improvements
 * 
 * Revision 1.1	 89/01/12  18:05:05  vielsack
 * supply procedure Assign to assign a character string
 * 
 * Revision 1.0	 88/10/04  14:26:37  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE Characte;

PROCEDURE IsEqual	(c1, c2: ARRAY OF CHAR): BOOLEAN;
PROCEDURE Length	(c: ARRAY OF CHAR): CARDINAL;
PROCEDURE Assign	(VAR s1: ARRAY OF CHAR; s2: ARRAY OF CHAR);

END Characte.
