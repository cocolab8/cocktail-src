(* $Id: Position.md,v 1.0 1999/07/12 15:06:29 grosch rel $ *)

(*
 * $Log: Position.md,v $
 * Revision 1.0  1999/07/12 15:06:29  grosch
 * Initial revision
 *
 * Revision 1.0  1999/07/12 14:57:36  grosch
 * Initial revision
 *
 * Revision 1.1  1998/04/21 13:21:19  grosch
 * truncation of file and module names to 8.3 format
 *
 * Revision 1.0  1993/08/18  13:23:56  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Juli 1992 *)

DEFINITION MODULE Position;

FROM IO		IMPORT tFile;
FROM Idents	IMPORT tIdent;

TYPE	  tPosition	= RECORD File: tIdent; Line, Column: SHORTCARD; END;

VAR	  NoPosition	: tPosition;
			(* A default position (0, 0).			*)

PROCEDURE Compare	(Position1, Position2: tPosition): INTEGER;
			(* Returns -1 if Position1 < Position2.		*)
			(* Returns  0 if Position1 = Position2.		*)
			(* Returns  1 if Position1 > Position2.		*)

PROCEDURE WritePosition	(File: tFile; Position: tPosition);
			(* The 'Position' is printed on the 'File'.	*)

END Position.
