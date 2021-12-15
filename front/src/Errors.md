(* handle and log errors *)

(* $Id: Errors.md,v 2.3 1997/05/27 15:04:18 grosch rel $ *)

(*
 * $Log: Errors.md,v $
 * Revision 2.3  1997/05/27 15:04:18  grosch
 * truncated module names to 8 characters:
 * Characte, StringM, Position
 *
 * Revision 2.2  1992/08/07 15:13:51  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 2.1  1991/11/21  14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 2.0  91/03/08  18:26:15  grosch
 * turned tables into initialized arrays (in C)
 * moved mapping tokens -> strings from Errors to Parser
 * changed interface for source position
 * 
 * Revision 1.1  90/06/11  18:44:44  grosch
 * layout improvements
 * 
 * Revision 1.0	 88/10/04  14:26:43  vielsack
 * Initial revision
 * 
 *)

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
   TooManyErrors	= 8	;
   TokenFound		= 9	;
   FoundExpected	= 10	;

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
 
CONST	(* info classes *)
  eInteger	=	1;
  eShort	=	2;
  eLong		=	3;
  eReal		=	4;
  eBoolean	=	5;
  eCharacter	=	6;
  eString	=	7;
  eArray	=	8;
  eSet		=	9;
  eIdent	=	10;
  eTermSet	=	11;

CONST	(* error classes *)
  eFatal	=	1;
  eRestriction	=	2;
  eError	=	3;
  eWarning	=	4;
  eRepair	=	5;
  eNote		=	6;
  eInformation	=	7;

CONST
  SysOffset	=	100;
  eInternal	=	15;

TYPE tReportMode	= (eImmediate, eNoListing, eListing);

CONST MaxErrorClass	= 7;

VAR ErrorCount	: ARRAY [0..MaxErrorClass] OF SHORTCARD;

PROCEDURE ErrorMessage	(ErrorCode, ErrorClass: CARDINAL; Position: tPosition);
PROCEDURE ErrorMessageI (ErrorCode, ErrorClass: CARDINAL; Position: tPosition;
			 InfoClass: CARDINAL; Info: ADDRESS);
PROCEDURE BeginErrors	();
PROCEDURE SetReportMode (mode: tReportMode);
PROCEDURE CloseErrors	();

VAR
  ReportClass : BITSET;
  ErrorTable  : ARRAY [0..255] OF CHAR;

END Errors.
