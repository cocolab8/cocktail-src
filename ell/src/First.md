(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: First.md,v $
 *	
 *	purpose:	compute first sets
 *
 *	$Author: grosch $
 *	$Date: 1991/02/06 16:15:47 $
 *)

DEFINITION MODULE First;

FROM Idents	IMPORT	tIdent;

PROCEDURE Firsts;
PROCEDURE IsLeftRec	(nonterm: tIdent): BOOLEAN;

END First.
