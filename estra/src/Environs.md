(* $Id: Environs.md,v 2.0 1989/06/22 13:09:40 vielsack rel $ *)

DEFINITION MODULE Environs;

FROM Idents	IMPORT	tIdent;
FROM IO		IMPORT	tFile;
FROM Patterns	IMPORT	tPattern;
FROM Queues	IMPORT	tQueue;
FROM Sets	IMPORT	tSet;

TYPE
  tDirNo = INTEGER;
  tFunction = POINTER TO tFunctionR;
  tFunctionR =
    RECORD
      Name: tIdent;
      Pats: tQueue;
      Domain: tSet;
    END;


PROCEDURE MakeFunctEnv		(name: tIdent; doamin: tSet): tFunction;
PROCEDURE InDomain		(name: tIdent; pat: tPattern): BOOLEAN;

PROCEDURE MakeDirective		(funct: tFunction): tDirNo;
PROCEDURE GetPatterns		(funct: tFunction; VAR pats: tQueue);
PROCEDURE GetCondPatterns	(funct: tFunction; VAR pats: tQueue);
PROCEDURE MaxDirective		(): tDirNo;

PROCEDURE SetPattern		(no: tDirNo; pat: tPattern);
PROCEDURE SetCondPattern	(no: tDirNo; pat: tPattern);
PROCEDURE GetPattern		(no: tDirNo): tPattern;

PROCEDURE DefineAccess		(no: tDirNo; path: tQueue;
				 sel, ident: tIdent; sure: BOOLEAN);
PROCEDURE DefineSelPat		(no: tDirNo; sel: tIdent; pat: tPattern);
PROCEDURE Defined		(no: tDirNo; sel: tIdent): BOOLEAN;
PROCEDURE SelPattern		(no: tDirNo; sel: tIdent): tPattern;
PROCEDURE CallFunction		(no: tDirNo; sel, name: tIdent);
PROCEDURE HeadCalled		(no: tDirNo): BOOLEAN;
PROCEDURE IsHead		(no: tDirNo; sel: tIdent): BOOLEAN;
PROCEDURE MaxCalls		(): INTEGER;

PROCEDURE WritePath		(f: tFile; no: tDirNo; sel: tIdent);
PROCEDURE WriteAccess		(f: tFile; no: tDirNo; sel: tIdent);
PROCEDURE AlwaysMatch		(no: tDirNo; node: tIdent): BOOLEAN;
PROCEDURE HasCondition		(no: tDirNo): BOOLEAN;
PROCEDURE WriteMatch		(f: tFile; no: tDirNo; margin: INTEGER;
				 GrammarName: tIdent);
PROCEDURE WriteCost		(f: tFile; no: tDirNo; margin: INTEGER);

END Environs.
