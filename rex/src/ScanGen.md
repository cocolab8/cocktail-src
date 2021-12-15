(* $Id: ScanGen.md,v 3.16 2013/01/15 13:54:39 grosch Exp $ *)

(*
 * $Log: ScanGen.md,v $
 * Revision 3.16  2013/01/15 13:54:39  grosch
 * allow generation of large scanners in Java
 *
 * Revision 3.15  2008/09/25 15:01:34  grosch
 * revised handling of # line directives
 * renamed WriteLine -> WriteDirective, AppendLine -> MakeDirective
 *
 * Revision 3.14  2008/09/17 18:42:13  grosch
 * fixed handling of line comments/directives
 *
 * Revision 3.13  2001/08/08 14:57:56  grosch
 * added and revised support for #line directives
 *
 * Revision 3.12  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 3.11  1999/11/16 17:52:34  grosch
 * added generation of Java
 *
 * Revision 3.10  1998/04/21 10:29:39  grosch
 * cosmetic changes
 *
 * Revision 3.9  1997/04/17 09:09:20  grosch
 * added support for # line 'dir\file' under Windows
 *
 * Revision 3.8  1996/04/25  09:43:30  grosch
 * added option for specification of a file to be used as skeleton
 *
 * Revision 3.7  1995/06/26  13:06:04  grosch
 * omit unused objects
 * suppress warnings (gcc -Wall)
 *
 * Revision 3.6  1994/09/13  12:43:56  grosch
 * added generation of Ada code
 *
 * Revision 3.5  1994/03/23  14:49:28  grosch
 * added generation of C++
 * read options from environment variable REX
 * added touching of output files only if necessary
 *
 * Revision 3.4  1993/05/28  14:09:53  grosch
 * added target language Eiffel
 *
 * Revision 3.3  1992/08/07  15:10:26  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 3.2  1991/11/21  14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.1  91/09/18  15:05:27  grosch
 * added option to control generation of # line directives
 *
 * Revision 3.0  91/04/04  18:07:36  grosch
 * introduced partitioning of character set
 *
 * Revision 1.3  91/02/13  11:34:45  grosch
 * moved tables from file to initialization in C; reduced case size
 *
 * Revision 1.2  89/02/23  15:55:40  grosch
 * added DEFAULT section
 *
 * Revision 1.1  89/01/17  15:01:20  grosch
 * correction and redesign of source position handling
 *
 * Revision 1.0  88/10/04  11:59:42  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE ScanGen;

FROM IO		IMPORT tFile	;
FROM Texts	IMPORT tText	;
FROM Strings	IMPORT tString	;
FROM Idents	IMPORT tIdent	;

CONST
   HasPosition	= 0		;
   NoPosition	= 1		;

   pGetWord	= 0		;
   pGetLower	= 1		;
   pGetUpper	= 2		;
   pinput	= 3		;
   pyyPush	= 4		;
   pyyPop	= 5		;

TYPE
   tLanguage	= (Modula, C, Cpp, Eiffel, Ada, Java);

VAR
   Import	,
   Export	,
   Global	,
   Local	,
   Begin	,
   Close	,
   Default	,
   Eof		,
   BlankText	,
   TabText	,
   EolText	: tText		;
   ImportLine	,
   ExportLine	,
   GlobalLine	,
   LocalLine	,
   BeginLine	,
   CloseLine	,
   DefaultLine	,
   EofLine	: CARDINAL	;
   ImportFile	,
   ExportFile	,
   GlobalFile	,
   LocalFile	,
   BeginFile	,
   CloseFile	,
   DefaultFile	,
   EofFile	: tIdent	;
   PackageName,
   ScannerName	: tIdent	;
   Language	: tLanguage	;
   ScannerFrame	,
   RexLib	: tString	;
   k		: SHORTCARD	;
   g, t, y, z	: BOOLEAN	;
   Procedures	: BITSET	;
   SmallTables	: BOOLEAN	;
   prefix	: tIdent	;

PROCEDURE InitScanGen		;
PROCEDURE GenerateScanner	(ReduceCaseSize, Warnings: BOOLEAN);
PROCEDURE GenerateInterface	;
PROCEDURE GenerateSupport	;
PROCEDURE WriteNl		(File: tFile);
PROCEDURE MakeDirective		(VAR Out: tString; Line: CARDINAL; File: tIdent);

END ScanGen.
