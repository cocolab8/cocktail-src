(* $Id: Nfa.md,v 3.4 2007/03/27 09:49:25 grosch rel $ *)

(*
 * $Log: Nfa.md,v $
 * Revision 3.4  2007/03/27 09:49:25  grosch
 * fixed overflow of variable NodeCount
 * changed some INT types to CARD
 *
 * Revision 3.3  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 3.2  1998/04/21 10:29:21  grosch
 * cosmetic changes
 *
 * Revision 3.1  1991/11/21 14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.0  91/04/04  18:07:08  grosch
 * introduced partitioning of character set
 * 
 * Revision 1.1  91/03/26  18:26:51  grosch
 * improved generation time
 * introduced options n and o to control table size and generation time
 * increased limitation for table size from 64K to 256K
 * 
 * Revision 1.0  88/10/04  11:59:35  grosch
 * Initial revision
 * 
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE Nfa;

FROM ScanTabs	IMPORT	RuleType;
FROM Classes	IMPORT	tCharClass;

CONST
   NoTransition		= 0;

TYPE
   NStateRange		= LONGCARD;
   TransitionRange	= LONGCARD;

VAR
   NStateCount		: NStateRange;
   TransitionCount	: TransitionRange;

PROCEDURE BeginNfa;
PROCEDURE MakeNState	(pTransitions: TransitionRange): NStateRange;
PROCEDURE PutNSemantics	(State: NStateRange; pSemantics: RuleType);
PROCEDURE GetNSemantics	(State: NStateRange): RuleType;
PROCEDURE PutTransitions(State: NStateRange; pTransition: TransitionRange);
PROCEDURE GetTransitions(State: NStateRange): TransitionRange;
PROCEDURE IsLastTransition
			(Transition: TransitionRange): BOOLEAN;
PROCEDURE NextTransition(Transition: TransitionRange): TransitionRange;

PROCEDURE MakeTransition(pCh: tCharClass; State: NStateRange): TransitionRange;
PROCEDURE AddTransition	(Transition, Transitions: TransitionRange): TransitionRange;
PROCEDURE GetCh		(Transition: TransitionRange): tCharClass;
PROCEDURE GetNextState	(Transition: TransitionRange): NStateRange;
PROCEDURE UniteTransitions
			(t1, t2: TransitionRange): TransitionRange;
PROCEDURE CopyTransitions
			(t1: TransitionRange): TransitionRange;
PROCEDURE WriteNfa;
PROCEDURE FinalizeNfa;

END Nfa.
