
(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: Nullable.md,v $
 *	
 *	purpose:	check nullability of the nonterminals
 *
 *	$Author: grosch $
 *	$Date: 1992/10/15 18:26:55 $
 *)

DEFINITION MODULE Nullable;

FROM Idents	IMPORT	tIdent;

PROCEDURE TestNullable;
PROCEDURE IsNullable	(Nonterm: tIdent): BOOLEAN;

(* NULL_ )*
PROCEDURE WriteNullables;
*( _NULL *)

END Nullable.
