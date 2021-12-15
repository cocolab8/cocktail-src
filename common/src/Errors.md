(* Errors.md		*)

(* $Id: Errors.md,v 1.8 2002/09/26 07:26:43 grosch rel $ *)

(*
 * $Log: Errors.md,v $
 * Revision 1.8  2002/09/26 07:26:43  grosch
 * added error ConfigureUnknownParam
 *
 * Revision 1.7  1997/05/27 14:58:14  grosch
 * cosmetic changes
 *
 * Revision 1.6  1996/10/22 20:14:36  grosch
 * added CONST TokenFound etc.
 *
 * Revision 1.5  1992/08/07  15:06:04  grosch
 * adaption to the new interface of the module Errors
 * 
 * Revision 1.4  1991/03/08  18:45:34  grosch
 * changed interface of Errors
 * changed interface for source position
 * 
 * Revision 1.3  90/06/12  18:33:32  grosch
 * layout improvements
 * 
 * Revision 1.2  89/02/15	20:07:36  vielsack
 * InError and NoReport is exported now
 * 
 * Revision 1.1  89/01/31	15:57:04  vielsack
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
   ErrorReadingParsTab	= 5	;
   WrongParseTable	= 5	;
   OpenParseTable	= 6	;
   ReadParseTable	= 7	;
   TooManyErrors	= 8	;
   TokenFound		= 9	;
   FoundExpected	= 10	;
   ConfigureUnknownParam= 26	;

   NoClass		= 0	;
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
 
CONST	(* info classes *)
  eNone		=	0;	(* reserved for internal use	*)
  eInteger	=	1;	(* INTEGER		*)
  eShort	=	2;	(* SHORTCARD		*)
  eLong		=	3;	(* LONGINT		*)
  eReal		=	4;	(* REAL			*)
  eBoolean	=	5;	(* BOOLEAN		*)
  eCharacter	=	6;	(* CHAR			*)
  eString	=	7;	(* Strings.tString	*)
  eArray	=	8;	(* ARRAY OF CHAR	*)
  eSet		=	9;	(* Sets.tSet		*)
  eIdent	=	10;	(* Idents.tIdent	*)
  eIdentSet	=	11;	(* Sets.tSet		*)

CONST	(* error classes *)
  eFatal	=	1;	(* deadly		*)
  eRestriction	=	2;	(* deadly		*)
  eError	=	3;	(* error		*)
  eWarning	=	4;	(* may be a error	*)
  eRepair	=	5;	(* something was repaired*)
  eNote		=	6;	(* only a comment	*)
  eInformation	=	7;	(* only a comment	*)
  MaxErrorClass =	7;

CONST	(* some reserved error codes	*)
  eSyntaxError		= 1;
  eExpectedSymbols	= 2;
  eRestartPoint		= 3;
  eSymbolInserted	= 4;
  eParseStackOverflow	= 5;
  eWrongParseTable	= 6;
  eOpenParseTable	= 7;
  eReadParseTable	= 8;
  eInternal		= 11;
  eWrongClass		= 12;
  eWrongCode		= 13;
  eNoOption		= 14;
  eTooManyArgs		= 15;
				(* 16..99 free *)
CONST
  SysOffset	=	100;
  MaxCode	=	SysOffset + 60;

TYPE
  tReportMode	= (eDirectly, eShortListing, eLongListing);
  tSaveProc	= PROCEDURE (INTEGER, ADDRESS): ADDRESS;
  tWriteProc	= PROCEDURE (INTEGER, ADDRESS);

VAR
  NoReports	: BOOLEAN;
  InError	: BOOLEAN;
  SaveProc	: tSaveProc;
  WriteProc	: tWriteProc;
  ReportClass	: BITSET;
  ErrorTable	: ARRAY [0..255] OF CHAR;

PROCEDURE ErrorMessage	(ErrorCode, ErrorClass: CARDINAL; Position: tPosition);
PROCEDURE ErrorMessageI (ErrorCode, ErrorClass: CARDINAL; Position: tPosition;
			 InfoClass: CARDINAL; Info: ADDRESS);
PROCEDURE BeginErrors	();
PROCEDURE SetReportMode (mode: tReportMode);
PROCEDURE CloseErrors	();
PROCEDURE ERROR		(c: ARRAY OF CHAR);

END Errors.
