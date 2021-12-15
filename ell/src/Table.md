(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: Table.md,v $
 *	
 *	purpose:	table to handle terminals and nonterminals environment
 *
 *	$Author: grosch $
 *	$Date: 2016/04/22 07:21:56 $
 *)

DEFINITION MODULE Table;

FROM Idents	IMPORT	tIdent;
FROM Sets	IMPORT	tSet;
FROM Tree	IMPORT	tTree;

(* TABLE_ )*
FROM IO		IMPORT	tFile;
*( _TABLE *)

VAR MaxId: tIdent;

PROCEDURE InitTable	;
PROCEDURE SetExpr	(nonterm: tIdent; expr: tTree);
PROCEDURE Expr		(nonterm: tIdent): tTree;
PROCEDURE SetLeaf	(nonterm: tIdent; leaf: tIdent);
PROCEDURE Leafs		(nonterm: tIdent; VAR leafs: tSet);
PROCEDURE SetFirst	(nonterm: tIdent; first: tSet);
PROCEDURE First		(nonterm: tIdent; VAR first: tSet);
PROCEDURE SetFollow	(nonterm: tIdent; follow: tSet);
PROCEDURE ExtendFollow	(nonterm: tIdent; follow: tSet);
PROCEDURE Follow	(nonterm: tIdent; VAR follow: tSet);
PROCEDURE SetLength	(id: tIdent; len: INTEGER);
PROCEDURE Length	(id: tIdent): INTEGER;

(* TABLE_ )*
PROCEDURE WriteTable	(f: tFile);
*( _TABLE *)

END Table.
