(* $Id: Errors.md,v 1.2 1997/05/27 15:45:25 grosch rel $ *)

(*
 * $Log: Errors.md,v $
 * Revision 1.2  1997/05/27 15:45:25  grosch
 * truncated module names to 8 characters: StringM, Position
 *
 * Revision 1.1  1996/05/14 20:19:53  grosch
 * update to latest version of rex (new syntax)
 *
 * Revision 3.5  1995/04/15  17:21:40  grosch
 * added message 'because of pattern at position' to 'pattern does never match'
 *
 * Revision 3.4  1994/12/06  12:12:54  grosch
 * added TokenFound necessary for latest version of lark
 *
 * Revision 3.3  1992/09/29  19:02:45  grosch
 * abort execution upon errors during scanning
 *
 * Revision 3.2  1992/08/07  15:10:26  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 3.1  1991/11/21  14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.0  91/04/04  18:06:52  grosch
 * introduced partitioning of character set
 * 
 * Revision 2.0  91/03/08  18:17:42  grosch
 * turned tables into initialized arrays (in C)
 * reduced case size
 * changed interface for source position
 * 
 * Revision 1.1  91/02/13  11:34:30  grosch
 * moved tables from file to initialization in C; reduced case size
 * 
 * Revision 1.0  88/10/04  11:59:33  grosch
 * Initial revision
 * 
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE Errors;

FROM SYSTEM	IMPORT ADDRESS;
FROM Position	IMPORT tPosition;

CONST
   NoText		= 0	;
   SyntaxError		= 1	;	(* error codes		*)
   ExpectedTokens	= 2	;
   RestartPoint		= 3	;
   TokenInserted	= 4	;
   WrongParseTable	= 5	;
   OpenParseTable	= 6	;
   ReadParseTable	= 7	;
   TokenFound		= 8	;
   FoundExpected	= 9	;

   Fatal		= 1	;	(* error classes	*)
   Restriction		= 2	;
   Error		= 3	;
   Warning		= 4	;
   Repair		= 5	;
   Note			= 6	;
   Information		= 7	;

   None			= 0	;
   Integer		= 1	;	(* info classes		*)
   Short		= 2	;
   Long			= 3	;
   Real			= 4	;
   Boolean		= 5	;
   Character		= 6	;
   String		= 7	;
   Array		= 8	;
   Set			= 9	;
   Ident		= 10	;
   Position		= 11	;
 
VAR ErrorCount	: INTEGER;

PROCEDURE ErrorMessage	(ErrorCode, ErrorClass: CARDINAL; Position: tPosition);
PROCEDURE ErrorMessageI (ErrorCode, ErrorClass: CARDINAL; Position: tPosition;
			 InfoClass: CARDINAL; Info: ADDRESS);

END Errors.
