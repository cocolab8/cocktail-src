(*
 *	M T C  -  Modula-2 to C Translator
 *      ----------------------------------
 *
 *	Purpose: associate identifiers with objects of arbitrary types
 *
 *	$Author: grosch $
 *	$Date: 1998/05/29 10:46:12 $
 *	$Revision: 1.0 $
 *
 ***)

DEFINITION MODULE AssocTab;

FROM SYSTEM	IMPORT ADDRESS;
FROM Idents	IMPORT tIdent;

PROCEDURE BeginAssocTab;
			(* initialize the association table		*)

PROCEDURE PutAssoc	(Ident: tIdent; Object: ADDRESS);
			(* associate object 'Object' with identifier	*)
			(* 'Ident'.					*)

PROCEDURE GetAssoc	(Ident: tIdent; VAR Object: ADDRESS);
			(* return in 'Object' the object currently	*)
			(* associated with identfier 'Ident'		*)

PROCEDURE CloseAssocTab;
			(* finalize the association table		*)

END AssocTab.
