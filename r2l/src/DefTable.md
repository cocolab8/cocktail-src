(* $Id: DefTable.md,v 1.1 1997/05/27 15:44:37 grosch rel $ *)

(*
 * $Log: DefTable.md,v $
 * Revision 1.1  1997/05/27 15:44:37  grosch
 * cosmetic changes
 *
 * Revision 1.0  1993/08/17 16:20:20  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Dec. 1990 *)

DEFINITION MODULE DefTable;

FROM Idents	IMPORT tIdent	;

CONST
   NoDef	= 0	;

TYPE
   DefRange	= LONGINT;
   tKind	= (NoKind, Ident, Start);

VAR
   DefCount	: DefRange;

PROCEDURE MakeIdentDef	( pIdent	: tIdent	);
PROCEDURE MakeStartDef	( pIdent	: tIdent	);
PROCEDURE GetDef	( pIdent	: tIdent	): DefRange;
PROCEDURE GetKind	( pDef		: DefRange	): tKind;

END DefTable.
