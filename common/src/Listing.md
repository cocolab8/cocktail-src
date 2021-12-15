(* $Id: Listing.md,v 1.2 1997/05/27 14:58:14 grosch rel $ *)

(*
 * $Log: Listing.md,v $
 * Revision 1.2  1997/05/27 14:58:14  grosch
 * cosmetic changes
 *
 * Revision 1.1  1989/01/31 15:57:19  vielsack
 * Initial revision
 *
 *)

DEFINITION MODULE Listing;

FROM	IO		IMPORT	tFile;
FROM	SYSTEM		IMPORT	ADDRESS;

VAR

  SourceFile : tFile;
  ListFile   : tFile;
  LongListing: BOOLEAN;


PROCEDURE PutError (ErrorCode, ErrorClass: INTEGER;
		    Line, Column: INTEGER;
		    InfoClass: INTEGER; Info: ADDRESS);

PROCEDURE HasError (): BOOLEAN;

PROCEDURE GetError (VAR ErrorCode, ErrorClass: INTEGER;
		    VAR Line, Column: INTEGER;
		    VAR InfoClass: INTEGER; VAR Info: ADDRESS);

END Listing.
