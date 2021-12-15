(* $Id: Queue.md,v 1.1 2008/09/13 15:41:00 grosch Exp $ *)

(*
 * $Log: Queue.md,v $
 * Revision 1.1  2008/09/13 15:41:00  grosch
 * fixed notation for comment leader
 *
 * Revision 1.0  1994/02/01 14:05:50  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, 11.8.1989 *)

DEFINITION MODULE Queue;

PROCEDURE MakeQueue	(Size: SHORTCARD);
PROCEDURE ReleaseQueue	;
PROCEDURE IsEmpty	(): BOOLEAN;
PROCEDURE Enqueue	(Elmt: SHORTCARD);
PROCEDURE Dequeue	(): SHORTCARD;
PROCEDURE IsElement	(Elmt: SHORTCARD): BOOLEAN;

END Queue.
