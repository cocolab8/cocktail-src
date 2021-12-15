(* $Id: Compress.md,v 1.6 2008/09/13 15:40:41 grosch Exp $ *)

(*
 * $Log: Compress.md,v $
 * Revision 1.6  2008/09/13 15:40:41  grosch
 * fixed notation for comment leader
 *
 * Revision 1.5  1999/06/03 07:52:17  grosch
 * increased values of Infinite and Infinite2
 *
 * Revision 1.4  1994/12/09 14:15:42  grosch
 * added alternate algorithm for table compression
 *
 * Revision 1.3  1994/07/14  12:16:32  grosch
 * improved handling of nonterminal reduce actions
 *
 * Revision 1.2  1994/04/25  11:46:50  grosch
 * added graphic runtime debugger
 *
 * Revision 1.1  1994/03/17  22:20:23  grosch
 * changed element type of TBase and NBase arrays from tTableElmt to CARDINAL
 *
 * Revision 1.0  1994/02/01  14:05:42  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Jan. 1994 *)

DEFINITION MODULE Compress;

FROM Sets	IMPORT tSet;
FROM LR1	IMPORT tStateRange;

CONST Infinite	= 10000000;
CONST Infinite2	= 10000000;

TYPE
   tTableElmt	= SHORTCARD;
   tComb	= RECORD Check, Next: tTableElmt; END;
   tDefault	= POINTER TO ARRAY [0..Infinite] OF tTableElmt;
   tEntryPtr	= POINTER TO tEntry;
   tEntry	= RECORD Next: tEntryPtr; Symbol, Entry: SHORTCARD; END;

VAR
   TEntryCount		,
   NEntryCount		,
   TDefaultSavings	,
   NDefaultSavings	,
   LastReadState	,
   LastReadReduceState	: CARDINAL;

   TComb		: POINTER TO ARRAY [0..Infinite2] OF tComb;
   TBase		: POINTER TO ARRAY [0..Infinite] OF CARDINAL;
   TDefault		: tDefault;
   TCombSize		: LONGINT;
   TBaseSize		: LONGINT;
   TDefaultSize		: LONGINT;
   TTableMax		: CARDINAL;
   TTableSize		: CARDINAL;

   NComb		: POINTER TO ARRAY [0..Infinite] OF tComb;
   NBase		: POINTER TO ARRAY [0..Infinite] OF CARDINAL;
   NDefault		: tDefault;
   NCombSize		: LONGINT;
   NBaseSize		: LONGINT;
   NDefaultSize		: LONGINT;
   NTableMax		: CARDINAL;
   NTableSize		: CARDINAL;

   DefaultLookPtr	: POINTER TO ARRAY [0..Infinite] OF SHORTCARD;
   DefaultLookSize	: LONGINT;
   DefaultSetPtr	: POINTER TO ARRAY [0..Infinite] OF tSet;
   DefaultSetSize	: LONGINT;
   DefaultSetCount	: LONGINT;

   ElmtSize		: tTableElmt;

PROCEDURE RenumberStates	;
PROCEDURE RenumberRules		;
PROCEDURE RecodeSymbol		(Symbol: CARDINAL): CARDINAL;
PROCEDURE RecodeTableElmt	(TableElmt: LONGINT): tStateRange;
PROCEDURE RecodeDefault		(TableElmt: CARDINAL): CARDINAL;
PROCEDURE CompContinuation	;
PROCEDURE CompTDefaults		;
PROCEDURE CompTDefaults2	;
PROCEDURE CompNDefaults		;
PROCEDURE CompressTTable	;
PROCEDURE CompressNTable	;

END Compress.
