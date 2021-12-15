(* $Id: Patterns.md,v 2.0 1989/06/22 13:10:06 vielsack rel $ *)

DEFINITION MODULE Patterns;

FROM Idents	IMPORT	tIdent;
FROM IO		IMPORT	tFile;
FROM Queues	IMPORT	tQueue;
FROM Sets	IMPORT	tSet;
FROM Stack	IMPORT	tStack;

CONST
  infinite = 10000;
  ePattern = 13;	(* info class for pattern *)

TYPE

  tRelation = (		(* examples:		*)
    cIndependent,	(*	x    ~  y	*)
    cInconsistent,	(*	A () || B ()	*)
    cSubsumes,		(*	C () >  e	*)
    cSupersumes,	(*      e    <  C ()	*)
    cEqual		(*	x    =  x	*)
    );

  tPattern =
    POINTER TO tPatternR;

  tSons	=
    POINTER TO ARRAY [0..infinite] OF tPattern;

  tPatternR =
    RECORD
      Ident: tIdent;
      Classes: tSet;
      Sons:  tSons;
    END;

PROCEDURE MakePattern	(id: tIdent): tPattern;
PROCEDURE SetPatternSon	(pat: tPattern; pos: INTEGER; son: tPattern);

PROCEDURE ReleasePattern(VAR pat: tPattern);

PROCEDURE GetPatternSon	(pat: tPattern; pos: INTEGER): tPattern;
PROCEDURE GetPatternId	(pat: tPattern): tIdent;
PROCEDURE PatternClasses(pat: tPattern; VAR classes: tSet);

PROCEDURE NormPattern	(pat: tPattern): tPattern;
PROCEDURE Relation	(pat1, pat2: tPattern): tRelation;
PROCEDURE IsEqual	(pat1, pat2: tPattern): BOOLEAN;

PROCEDURE ResetExtendPos;
PROCEDURE ExtendPos	(): tPattern;
PROCEDURE Extend	(pat1, pos: tPattern; VAR pats: tQueue);

PROCEDURE SynthesizePatterns (class: tIdent; VAR pats: tStack);

PROCEDURE CopyPattern	(pat: tPattern): tPattern;

PROCEDURE WritePattern (f: tFile; p: tPattern);

(* PATT_   
PROCEDURE WriteRelation (pat1, pat2: tPattern);
   _PATT *)

END Patterns.
