(* $Id: Dfa.md,v 3.4 2007/03/27 09:49:25 grosch rel $ *)

(*
 * $Log: Dfa.md,v $
 * Revision 3.4  2007/03/27 09:49:25  grosch
 * fixed overflow of variable NodeCount
 * changed some INT types to CARD
 *
 * Revision 3.3  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 3.2  1998/04/21 10:26:07  grosch
 * cosmetic changes
 *
 * Revision 3.1  1991/11/21 14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.0  91/04/04  18:06:47  grosch
 * introduced partitioning of character set
 * 
 * Revision 1.2  90/06/11  11:27:23  grosch
 * extended character range to 8 bits, ChRange -> CHAR
 * 
 * Revision 1.1  90/05/17  11:21:33  grosch
 * extend character range to 8 bits
 * 
 * Revision 1.0  88/10/04  11:59:31  grosch
 * Initial revision
 * 
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE Dfa;

FROM Sets	IMPORT tSet	;
FROM UniCode	IMPORT UCHAR	;
FROM Classes	IMPORT tCharClass;

CONST
   DNoState     	= 0	;
   FirstCh		= 0	;
   BlankCh		= 32	;
   TabCh		= 9	;
   EolCh		= 10	;
   EobCh		= 127	;

TYPE DStateRange	= SHORTCARD;

VAR
   LastCh		: UCHAR		;
   DStateCount		: DStateRange	;
   EobState		: DStateRange	;
   EobDefaultState	: DStateRange	;
   AmbiguousStates	: tSet		;
   CyclicStates		: tSet		;
   MaxAmbiguousState	: DStateRange	;
   MinimizeSavings	: INTEGER	;
   DefaultSavings	: INTEGER	;

PROCEDURE MakeDState	(): DStateRange;
PROCEDURE GetDefault	(State: DStateRange): DStateRange;
PROCEDURE PutDefault	(State, DefaultState: DStateRange);
PROCEDURE GetDSemantics	(State: DStateRange; VAR Semantics: tSet);
PROCEDURE PutDSemantics	(State: DStateRange;     Semantics: tSet);
PROCEDURE GetStartSet	(State: DStateRange; VAR StartSet: tSet);
PROCEDURE PutStartSet	(State: DStateRange;     StartSet: tSet);
PROCEDURE GetTable	(State: DStateRange; Ch: tCharClass): DStateRange;
PROCEDURE PutTable	(State: DStateRange; Ch: tCharClass; NextState: DStateRange);
PROCEDURE GetTableNoDef	(State: DStateRange; Ch: tCharClass): DStateRange;
PROCEDURE GetFirst	(State: DStateRange): tCharClass;
PROCEDURE GetLast	(State: DStateRange): tCharClass;
PROCEDURE GetEobTrans	(State: DStateRange): DStateRange;

PROCEDURE MinimizeDfa;
PROCEDURE ComputeSuccGraph;
PROCEDURE ComputeAmbiguousStates;
PROCEDURE ComputeCyclicStates;
PROCEDURE ComputeStartSets;
PROCEDURE SaveEobTransitions;
PROCEDURE ComputeDefaults (From, To: DStateRange);
PROCEDURE WriteDfa;

END Dfa.
