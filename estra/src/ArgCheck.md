(* $Id: ArgCheck.md,v 2.0 1989/06/22 13:09:15 vielsack rel $ *)

DEFINITION MODULE ArgCheck;

CONST
  cVersion = '8906';	(* year and month of actual version *)

VAR
  TEST: BOOLEAN;
  DEF: BOOLEAN;
  IMP: BOOLEAN;
  BU: BOOLEAN;		(* use bottom up pattern matching *)

  SourceFileName: ARRAY [0..255] OF CHAR;

(* ARGCHECK_ *)
  TREE: BOOLEAN;
  GRAM: BOOLEAN;
  MATCH: BOOLEAN;
  AUTO: BOOLEAN;
  DEBUG: BOOLEAN;
(* _ARGCHECK *)


PROCEDURE CheckArgs;

END ArgCheck.
