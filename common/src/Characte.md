(* $Id: Characte.md,v 1.2 1997/05/27 14:57:52 grosch rel $ *)

(*
 * $Log: Characte.md,v $
 * Revision 1.2  1997/05/27 14:57:52  grosch
 * truncated module names to 8 characters: Characte
 *
 * Revision 1.1  1989/01/31 15:56:00  vielsack
 * Initial revision
 *
 *)

DEFINITION MODULE Characte;

PROCEDURE IsEqual (s1, s2: ARRAY OF CHAR): BOOLEAN;
PROCEDURE Length (s: ARRAY OF CHAR): INTEGER;
PROCEDURE Char	(s: ARRAY OF CHAR; i: INTEGER): CHAR;
PROCEDURE Append (s: ARRAY OF CHAR; c: CHAR);
PROCEDURE Concatenate (VAR s1: ARRAY OF CHAR; s2: ARRAY OF CHAR);
PROCEDURE SubString (s1: ARRAY OF CHAR; from,to: INTEGER; VAR s2:ARRAY OF CHAR);
PROCEDURE Assign (VAR s1: ARRAY OF CHAR; s2: ARRAY OF CHAR);
END Characte.
