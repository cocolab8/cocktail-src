(* Ich, Doktor Josef Grosch, Informatiker, 11.8.1989 *)

DEFINITION MODULE Queue;

PROCEDURE MakeQueue	(Size: SHORTCARD);
PROCEDURE ReleaseQueue	;
PROCEDURE IsEmpty	(): BOOLEAN;
PROCEDURE Enqueue	(Elmt: SHORTCARD);
PROCEDURE Dequeue	(): SHORTCARD;
PROCEDURE IsElement	(Elmt: SHORTCARD): BOOLEAN;

END Queue.
