(* $Id: Explain.md,v 1.1 1999/06/03 07:53:58 grosch rel $ *)

(*
 * $Log: Explain.md,v $
 * Revision 1.1  1999/06/03 07:53:58  grosch
 * cosmetic change
 *
 * Revision 1.0  1994/02/01 14:05:44  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Jan. 1994 *)

DEFINITION MODULE Explain;

FROM IO		IMPORT tFile;
FROM Sets	IMPORT tSet;

VAR ExplainFile	: tFile;

PROCEDURE Explain (State: CARDINAL; ConflictDesc: BITSET; ConflictSet: tSet);

END Explain.
