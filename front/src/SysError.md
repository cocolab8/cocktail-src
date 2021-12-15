(* handle system errors *)

(* $Id: SysError.md,v 1.3 1997/05/27 15:14:05 grosch rel $ *)

(*
 * $Log: SysError.md,v $
 * Revision 1.3  1997/05/27 15:14:05  grosch
 * cosmetic changes
 *
 * Revision 1.2  1991/11/21 14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.1  90/06/11  18:45:41  grosch
 * layout improvements
 * 
 * Revision 1.0	 88/10/04  14:27:19  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE SysError;

FROM SYSTEM	IMPORT ADDRESS;

PROCEDURE StatIsBad		(N: INTEGER): BOOLEAN;
PROCEDURE SysErrorMessageI	(N: INTEGER; ErrCl, InfCl: CARDINAL; Info: ADDRESS);
PROCEDURE SysErrorMessage	(N: INTEGER; ErrCl: CARDINAL);

END SysError.
