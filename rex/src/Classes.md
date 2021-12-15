(* $Id: Classes.md,v 3.5 2000/09/12 17:39:40 grosch rel $ *)

(*
 * $Log: Classes.md,v $
 * Revision 3.5  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 3.4  1998/04/21 10:26:07  grosch
 * cosmetic changes
 *
 * Revision 3.3  1993/08/18 15:10:38  grosch
 * rename System and Memory to rSystem and rMemory
 *
 * Revision 3.2  1991/11/21  14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.1  91/04/08  15:50:11  grosch
 * release memory after use in Classes and Tree0
 *
 * Revision 3.0  91/04/04  18:26:37  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, March 1991/August 2000 *)

DEFINITION MODULE Classes;

FROM HugeSets	IMPORT tSet;
FROM UniCode	IMPORT UCHAR;

IMPORT Sets;

CONST
   MaxClass	= MAX (SHORTCARD);

TYPE
   tCharClass	= [0 .. MaxClass];
			(* 0 .. ClassCount	    : for chars from sets    *)
			(* ClassCount+1 .. LastClass: for chars from CharSet *)

   tClassInfo	= RECORD Set: tSet; Classes: Sets.tSet; END;
   tClassRange	= RECORD Upb: UCHAR; Class: tCharClass; END;

VAR
   LastClass	: tCharClass;
   CharSet	: tSet;		(* set of characters appearing in REs as
				   single characters or in strings *)
   Unused	: tSet;		(* set of unused characters *)

   ToCharArray	: ARRAY tCharClass OF UCHAR; (* optimize storage 0 .. LastClass ??? *)
	     (* maps class to Unicode character, for chars from CharSet, only *)

   ToClassArrayPtr: POINTER TO ARRAY [0 .. 100000] OF tCharClass;
				(* maps chars < ToClassArraySize to class *)
   ToClassArraySize: LONGINT;

   ToClassRange	: POINTER TO ARRAY [0 .. 100000] OF tClassRange;
   ToClassSize	: LONGINT;	(* maps chars >= ToClassArraySize to class *)
   ToClassCount	: INTEGER;

   SetMemPtr	: POINTER TO ARRAY tCharClass OF tClassInfo;
   SetMemSize	: LONGINT;	(* set of all sets appearing in REs *)
   SetCount	: INTEGER;

   ClassMemPtr	: POINTER TO ARRAY tCharClass OF tSet;
   ClassMemSize	: LONGINT;	(* classification of all characters *)
   ClassCount	: INTEGER;

   b		: BOOLEAN;

PROCEDURE IsInSetMem (Set: tSet): INTEGER;
PROCEDURE ComputeClasses;
PROCEDURE WriteClasses;
PROCEDURE ToClass (Ch: UCHAR): tCharClass; (* maps Unicode character to class *)
PROCEDURE ToChar (Class: tCharClass): UCHAR; (* maps class to Unicode character,
					        for chars from CharSet, only *)
PROCEDURE ReleaseSetMem;

END Classes.
