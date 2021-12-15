(* $Id: Position.md,v 1.1 2008/09/13 15:36:01 grosch Exp $ *)

(*
 * $Log: Position.md,v $
 * Revision 1.1  2008/09/13 15:36:01  grosch
 * fixed notation for comment leader
 *
 * Revision 1.0  1998/05/29 10:46:12  grosch
 * Initial revision
 *
 * Revision 1.0  1998/05/29 10:44:39  grosch
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

PROCEDURE ReadPosition	(File: tFile; VAR Position: tPosition);
			(* The 'Position' is read from the 'File'.	*)

END Position.
