(* $Id: Traces.md,v 3.2 1998/04/21 10:32:25 grosch rel $ *)

(*
 * $Log: Traces.md,v $
 * Revision 3.2  1998/04/21 10:32:25  grosch
 * cosmetic changes
 *
 * Revision 3.1  1991/11/21 14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.0  91/04/04  18:07:59  grosch
 * introduced partitioning of character set
 * 
 * Revision 1.0  88/10/04  11:59:52  grosch
 * Initial revision
 * 
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE Traces;

FROM Dfa	IMPORT DStateRange;

PROCEDURE InitTraces	;
PROCEDURE ResetTraces	(StringLength: INTEGER);
PROCEDURE RecordTrace	(Position: SHORTCARD; TraceState, NewState: DStateRange);
PROCEDURE RecordedTrace (Position: SHORTCARD; TraceState: DStateRange): DStateRange;
PROCEDURE FinalizeTraces;

END Traces.
