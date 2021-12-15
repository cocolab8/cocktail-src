(* $Id: Match.md,v 4.0 1993/08/26 16:06:46 grosch rel $ *)

DEFINITION MODULE Match;

FROM IO IMPORT tFile;

VAR
  MaxMatchIndex,
  CombSize: INTEGER;

PROCEDURE MakeTables;
PROCEDURE PackMatchSets (f: tFile);

END Match.
