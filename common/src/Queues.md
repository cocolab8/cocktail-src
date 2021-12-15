(* adt queue	*)

(* $Id: Queues.md,v 1.2 1997/05/27 14:58:14 grosch rel $ *)

(*
 * $Log: Queues.md,v $
 * Revision 1.2  1997/05/27 14:58:14  grosch
 * cosmetic changes
 *
 * Revision 1.1  1989/01/31 15:59:16  vielsack
 * Initial revision
 *
 *)

DEFINITION MODULE Queues;

FROM	SYSTEM		IMPORT	ADDRESS;

TYPE

  UnBounded	= [0..10000];
  tElmt		= ADDRESS;
  tArrayPtr	= POINTER TO ARRAY UnBounded OF tElmt;
  
  tIndex	= INTEGER;
  tQueue	= RECORD
		    Size,
		    First,
		    Last : INTEGER;
		    Array : tArrayPtr;
		  END;
  

PROCEDURE MakeQueue	(VAR Queue: tQueue);
PROCEDURE ReleaseQueue	(VAR Queue: tQueue);
PROCEDURE AssignEmpty	(VAR Queue: tQueue);
PROCEDURE Append	(VAR Queue: tQueue; Elmt: tElmt);
PROCEDURE Head		(    Queue: tQueue): tElmt;
PROCEDURE Last		(    Queue: tQueue): tElmt;
PROCEDURE ClearHead	(VAR Queue: tQueue);
PROCEDURE ClearLast	(VAR Queue: tQueue);
PROCEDURE Tail		(VAR Queue: tQueue);	(* synonym for ClearHead *)
PROCEDURE Insert	(VAR Queue: tQueue; Elmt: tElmt);
PROCEDURE IsEmpty	(    Queue: tQueue): BOOLEAN;
PROCEDURE Length	(    Queue: tQueue): tIndex;
PROCEDURE GetElement	(    Queue: tQueue; Pos: tIndex): tElmt;
PROCEDURE Assign	(VAR Queue1: tQueue; Queue2: tQueue);
PROCEDURE TakeHead	(VAR Queue: tQueue): tElmt;
PROCEDURE TakeLast	(VAR Queue: tQueue): tElmt;

END Queues.
