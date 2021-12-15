(* $Id: Conflict.md,v 1.4 2008/09/13 15:40:41 grosch Exp $ *)

(*
 * $Log: Conflict.md,v $
 * Revision 1.4  2008/09/13 15:40:41  grosch
 * fixed notation for comment leader
 *
 * Revision 1.3  1998/04/21 10:41:33  grosch
 * truncation of file and module names to 8.3 format
 *
 * Revision 1.2  1995/11/07  09:16:57  grosch
 * removed read reduce reduce conflicts
 * added handling of LALR(2) grammars
 *
 * Revision 1.1  1994/11/13  12:38:16  grosch
 * added detailed counts of conflict repairs
 *
 * Revision 1.0  1994/07/14  12:15:29  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, June 1994 *)

DEFINITION MODULE Conflict;

FROM Sets	IMPORT tSet;
FROM LR1	IMPORT tStateRange;

CONST
   cReadReduce			= 1;
   cReduceReduce		= 2;
   cExplRepReadReduce		= 3;
   cExplRepReduceReduce		= 4;
   cImplRepReadReduce		= 5;
   cImplRepReduceReduce		= 6;
   cDynaRepReadReduce		= 7;
   cDynaRepReduceReduce		= 8;
   cLRkRepReadReduce		= 9;
   cLRkRepReduceReduce		= 10;

TYPE
   tCondition	= RECORD
		     RuleSet	: tSet;
		     dState	: tStateRange;
		     Implicit	: SHORTCARD;
		     TableEntry	: SHORTCARD;
		     Repair	: SHORTCARD;
		     TheK	: SHORTINT;
		     TheX	: SHORTCARD;
		     dElseItem	: CARDINAL;
		  END;

VAR
   ConditionCount	: LONGINT;
   ConditionSize	: LONGINT;
   ConditionPtr		: POINTER TO ARRAY [0..100000] OF tCondition;

   DynRuleSet		: tSet;
   RepairCount		: ARRAY [cReadReduce..cLRkRepReduceReduce] OF SHORTCARD;

PROCEDURE CheckConflicts1;
PROCEDURE CheckConflicts2;

END Conflict.
