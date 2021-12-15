(* $Id: Reduced.md,v 2.0 1989/06/22 13:10:10 vielsack rel $ *)

DEFINITION MODULE Reduced;

FROM	Sets		IMPORT	tSet;

VAR
  IsReduced: BOOLEAN;
  UnReachable: tSet;	(* unreachable classes *)
  UnDerivable: tSet;	(* underivable classes *)

PROCEDURE TestReduced (StartClasses: tSet);

END Reduced.
