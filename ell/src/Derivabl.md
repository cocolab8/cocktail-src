(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: Derivabl.md,v $
 *	
 *	purpose:	check derivability of each nonterminal
 *
 *	$Author: grosch $
 *	$Date: 1997/05/27 15:24:34 $
 *)

DEFINITION MODULE Derivabl;

FROM Idents	IMPORT	tIdent;

PROCEDURE TestDerivable;
PROCEDURE IsDerivable	(Nonterm: tIdent): BOOLEAN;
PROCEDURE IsNullable	(Nonterm: tIdent): BOOLEAN;

END Derivabl.
