(* $Id: LR1.md,v 1.8 2005/05/23 13:06:51 grosch rel $ *)

(*
 * $Log: LR1.md,v $
 * Revision 1.8  2005/05/23 13:06:51  grosch
 * increased limitation of number of items from 1000000 to 10000000
 *
 * Revision 1.7  1999/10/01 14:56:19  grosch
 * fixed bug in CompContinuation
 *
 * Revision 1.6  1999/06/03 07:56:44  grosch
 * bug fix: in ANSI C++ contants need a type
 *
 * Revision 1.5  1995/11/07 09:21:20  grosch
 * removed read reduce reduce conflicts
 * added export of procedure AllocLookahead
 *
 * Revision 1.4  1994/11/13  12:42:26  grosch
 * fixed bug in lookahead computation by introducing digraph algorithm
 *
 * Revision 1.3  1994/10/31  23:12:23  grosch
 * report detailed counts of conflict repairs
 *
 * Revision 1.2  1994/07/14  12:23:16  grosch
 * redesign of table generation
 *
 * Revision 1.1  1994/03/17  22:16:28  grosch
 * removed unused objects
 *
 * Revision 1.0  1994/02/01  14:05:46  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Jan. 1994 *)

DEFINITION MODULE LR1;

FROM SYSTEM	IMPORT ADDRESS;
FROM IO		IMPORT tFile;
FROM Strings	IMPORT tString;
FROM Sets	IMPORT tSet;
FROM Tree	IMPORT tTree, tpSet;

CONST
   Invalid	= 0;
   Reduce	= 1;
   Read		= 2;
   ReadReduce	= 3;

   ExplicitRepair	= 1;

TYPE
   tStateRange	= SHORTCARD;

   tTablePtr	= POINTER TO ARRAY [0..1000000] OF tStateRange;

   tState	= RECORD
		     Kernel	,
		     KernelInfo	: CARDINAL;
		     KernelSize	,
		     ClosureSize,
		     Class	,
		     ReadIndex	,
		     Continuation,
		     MinSym	,
		     MaxSym	: SHORTCARD;
		     Next	: tStateRange;
		     TablePtr	: tTablePtr;
		  END;

   tItem	= RECORD
		     Rule, Dot	: SHORTCARD;
		     Order	: SHORTCARD;
		  END;

   tKernelItem	= RECORD
		     Lookahead	: tpSet;
		     PredPtr	: POINTER TO ARRAY [1..1000000] OF tStateRange;
		     PredSize	,
		     PredCount	: tStateRange;
		     N		: SHORTCARD;
		  END;

   tToItemList	= RECORD First, Last: SHORTINT; LastOrder: SHORTCARD; END;

   tItemList	= RECORD lItem: CARDINAL; Next: SHORTINT; END;

VAR
   StateCount		: LONGINT;
   StateSize		: LONGINT;
   StatePtr		: POINTER TO ARRAY [0..100000] OF tState;

   ItemCount		: LONGINT;
   ItemSize		: LONGINT;
   ItemPtr		: POINTER TO ARRAY [0..10000000] OF tItem;

   KernelItemCount	: LONGINT;
   KernelItemSize	: LONGINT;
   KernelItemPtr	: POINTER TO ARRAY [0..1000000] OF tKernelItem;

   HashSize		: LONGINT;
   HashPtr		: POINTER TO ARRAY [0..1000000] OF tStateRange;

   ToItemListSize	: LONGINT;
   ToItemListPtr	: POINTER TO ARRAY [0..1000000] OF tToItemList;

   ItemListCount	: LONGINT;
   ItemListSize		: LONGINT;
   ItemListPtr		: POINTER TO ARRAY [0..1000000] OF tItemList;

   RuleBase		,
   LastLR0State		,
   LastLR1State		: CARDINAL;
   TableCount		,
   gTableSize		: LONGINT;
   HasConflict		: BOOLEAN;
   StopList		: tTree;

   Repair		,
   ReduceCount		,
   ReadCount		,
   ReadReduceCount	,
   InvalidCount		,
   ReadReduceConflict	,
   ReduceReduceConflict	: SHORTCARD;

   ReadReduceSet	,
   WorkingSet		: tSet;

PROCEDURE InitialStates	;
PROCEDURE CompLR0	;
PROCEDURE CompPred	;
PROCEDURE ResetPred	;
PROCEDURE AllocLookahead (): ADDRESS;
PROCEDURE GetLookahead	(State: tStateRange; Item: CARDINAL; VAR LASet: tSet);
PROCEDURE ResetLookahead;
PROCEDURE ReduceReduce	;
PROCEDURE CompLR1	;
PROCEDURE CompReachable1;
PROCEDURE OptimizeLR0	;
PROCEDURE CompReachable2;
PROCEDURE CompGrammarClass;
PROCEDURE SeqFirst	(Rule, Dot: SHORTCARD; VAR Set: tSet);
PROCEDURE PrintStates	;
PROCEDURE PrintState	(File: tFile; State: tStateRange);
PROCEDURE PrintItem	(File: tFile; Item, Info: CARDINAL);
PROCEDURE PrintRepairCount;
PROCEDURE PrintStatistics;

END LR1.
