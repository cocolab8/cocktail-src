(* $Id: SysError.md,v 1.2 1997/05/27 14:58:14 grosch rel $ *)

(*
 * $Log: SysError.md,v $
 * Revision 1.2  1997/05/27 14:58:14  grosch
 * cosmetic changes
 *
 * Revision 1.1  1989/01/31 16:00:32  vielsack
 * Initial revision
 *
 *)

DEFINITION MODULE SysError;

FROM	SYSTEM		IMPORT	ADDRESS;

PROCEDURE StatIsBad (N: INTEGER): BOOLEAN;
PROCEDURE SysErrorMessageI (N: INTEGER; ErrCl, InfCl: CARDINAL; Info: ADDRESS);
PROCEDURE SysErrorMessage (N: INTEGER; ErrCl: CARDINAL);

END SysError.

