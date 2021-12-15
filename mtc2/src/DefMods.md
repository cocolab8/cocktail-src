(*
 *	M T C  -  Modula-2 to C Translator
 *      ----------------------------------
 *
 *	Purpose: get all definition modules on which the current compilation
 *		 unit depends and construct an abstract tree for them
 *
 *	$Author: grosch $
 *	$Date: 1998/05/29 10:46:12 $
 *	$Revision: 1.0 $
 *
 ***)

DEFINITION MODULE DefMods;

FROM Tree	IMPORT tTree;

PROCEDURE GetDefinitionModules	(CompUnit: tTree; VAR Root: tTree);
(* IN:		The current compilation unit 'CompUnit'.		*)
(*		PRECONDITION: Tree^.Kind IN {DefMod, ProgMod}		*)
(* OUT:		'Root' is a tree (module list) that consists of the	*)
(*		current compilation unit 'CompUnit' and of all defini-	*)
(*		tion modules on which the current compilation unit	*)
(*		depends. The tree is ordered such that each module (	*)
(*		compilation unit) depends only on modules (compilation	*)
(*		units) preceding it in the module list. The current	*)
(*		compilation unit is always the last element on the list.*)
(*		POSTCONDITION: Tree^.Kind = ROOT			*)

END DefMods.
