(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: Types.md,v $
 *	
 *	purpose:	distinguish terminals and nonterminals
 *
 *	$Author: grosch $
 *	$Date: 1991/02/06 16:16:45 $
 *)

DEFINITION MODULE Types;

FROM Idents	IMPORT	tIdent;
FROM Sets	IMPORT	tSet;

PROCEDURE BeginTypes	;

PROCEDURE MakeTerm	(id: tIdent);
PROCEDURE MakeNonterm	(id: tIdent);

PROCEDURE IsDeclared	(id: tIdent): BOOLEAN;
PROCEDURE IsTerm	(id: tIdent): BOOLEAN;
PROCEDURE IsNonterm	(id: tIdent): BOOLEAN;

PROCEDURE Terminals	(VAR set: tSet);
PROCEDURE Nonterminals	(VAR set: tSet);

END Types.
