(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: Reachabl.md,v $
 *	
 *	purpose:	check reachability of the nonterminals
 *
 *	$Author: grosch $
 *	$Date: 1997/05/27 15:24:34 $
 *)


DEFINITION MODULE Reachabl;

FROM Idents	IMPORT	tIdent;

PROCEDURE WindThrough (start: tIdent);
PROCEDURE IsReachable (nonterm: tIdent): BOOLEAN;

END Reachabl.
