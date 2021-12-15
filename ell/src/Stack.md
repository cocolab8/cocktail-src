(* $Id: Stack.md,v 5.0 2008/09/03 09:09:10 grosch rel $ *)

(*
 * $Log: Stack.md,v $
 * Revision 5.0  2008/09/03 09:09:10  grosch
 * moved from ../../common/src
 *
 * Revision 1.3  1997/05/27 14:58:14  grosch
 * cosmetic changes
 *
 * Revision 1.2  1990/06/12 18:33:46  grosch
 * layout improvements
 *
 * Revision 1.1  89/01/31	16:00:24  vielsack
 * Initial revision
 *
 *)

DEFINITION MODULE Stack;

FROM Idents	IMPORT tIdent;

CONST
  NoBound = 65535;

TYPE
  tElmt	 = tIdent;

  tStack = RECORD
    StackPtr	: LONGINT;
    StackSize	: LONGINT;
    Array	: POINTER TO ARRAY [0..NoBound] OF tElmt;
  END;

PROCEDURE MakeStack	(VAR s: tStack);
PROCEDURE ReleaseStack	(VAR s: tStack);
PROCEDURE ClearStack	(VAR s: tStack);
PROCEDURE IsEmptyStack	(s: tStack): BOOLEAN;
PROCEDURE Push		(VAR s: tStack; e: tElmt);
PROCEDURE Pop		(VAR s: tStack): tElmt;
PROCEDURE Top		(VAR s: tStack): tElmt;
PROCEDURE Depth		(s: tStack): INTEGER;
PROCEDURE Assign	(VAR s1: tStack; s2: tStack);

END Stack.
