(* $Id: DefTable.md,v 3.4 2006/08/01 14:12:37 grosch rel $ *)

(*
 * $Log: DefTable.md,v $
 * Revision 3.4  2006/08/01 14:12:37  grosch
 * introduced separate name spaces for start states and definitions
 *
 * Revision 3.3  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 3.2  1998/04/21 10:26:07  grosch
 * cosmetic changes
 *
 * Revision 3.1  1991/11/21 14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.0  91/04/04  18:06:40  grosch
 * introduced partitioning of character set
 *
 * Revision 1.0  88/10/04  11:59:29  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE DefTable;

FROM Idents	IMPORT tIdent	;
FROM Tree	IMPORT tTree	;

CONST
   NoDef	= 0	;

TYPE
   DefRange	= LONGINT;
   tKind	= (NoKind, Define, Start);

VAR
   DefCount	: DefRange;

PROCEDURE MakeDefineDef	(
          pIdent	: tIdent	;
          pTree		: tTree		);

PROCEDURE MakeStartDef	(
          pIdent	: tIdent	;
          pNumber	: LONGCARD	);

PROCEDURE GetDef	(
          pIdent	: tIdent	;
	  pKind		: tKind		): DefRange;

PROCEDURE GetKind	(
          pDef		: DefRange	): tKind;

PROCEDURE GetDefineDef	(
          pDef		: DefRange	;
      VAR pIdent	: tIdent	;
      VAR pTree		: tTree		);

PROCEDURE GetStartDef	(
          pDef		: DefRange	;
      VAR pIdent	: tIdent	;
      VAR pNumber	: LONGCARD	);

END DefTable.
