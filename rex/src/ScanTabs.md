(* $Id: ScanTabs.md,v 4.5 2013/01/15 13:54:39 grosch Exp $ *)

(*
 * $Log: ScanTabs.md,v $
 * Revision 4.5  2013/01/15 13:54:39  grosch
 * allow generation of large scanners in Java
 *
 * Revision 4.4  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 4.3  1998/04/21 10:31:28  grosch
 * cosmetic changes
 *
 * Revision 4.2  1995/01/24 19:14:18  grosch
 * removed restriction for tables with more than 65535 elements
 *
 * Revision 4.1  1994/12/30  15:11:43  grosch
 * increased size of Control (avoid range overflow)
 *
 * Revision 4.0  1993/08/26  16:01:21  grosch
 * replaced table files (Scanner.Tab, Parser.Tab, ...) by initialization code
 *
 * Revision 3.2  1993/05/28  14:09:53  grosch
 * added target language Eiffel
 *
 * Revision 3.1  1991/11/21  14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.0  91/04/04  18:07:44  grosch
 * introduced partitioning of character set
 * 
 * Revision 1.3  91/03/26  18:27:13  grosch
 * improved generation time
 * introduced options n and o to control table size and generation time
 * increased limitation for table size from 64K to 256K
 * 
 * Revision 1.2  91/02/13  11:34:50  grosch
 * moved tables from file to initialization in C; reduced case size
 * 
 * Revision 1.1  90/06/11  11:27:59  grosch
 * extended character range to 8 bits, ChRange -> CHAR
 * 
 * Revision 1.0  88/10/04  11:59:46  grosch
 * Initial revision
 * 
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE ScanTabs;

FROM IO	IMPORT tFile;

CONST
   NoRule	= 0	;
   NoAction	= 0	;
   EofAction	= 1	;
   EolAction	= 2	;
   EobAction	= 3	;
   TabAction	= 4	;
   CopyAction	= 5	;
   BlankAction	= 6	;

TYPE
   TableElmt	= SHORTCARD	;
   StateRange	= TableElmt	;
   RuleRange	= TableElmt	;
   RuleType	= TableElmt	;
   TableRange	= CARDINAL	;
   ActionType	= TableElmt	;
   ControlType	= RECORD Check, Next: TableElmt; END;

TYPE
   RuleBase	= ARRAY [0 .. 100000]	OF RuleRange	;
   Rule		= ARRAY [0 .. 100000]	OF RuleType	;
   Base		= ARRAY [0 .. 100000]	OF TableRange	;
   Default	= ARRAY [0 .. 100000]	OF StateRange	;
   Control	= ARRAY [0 .. 1000000]	OF ControlType	;
   EobTrans	= ARRAY [0 .. 100000]	OF StateRange	;
   Context	= ARRAY [0 .. 100000]	OF StateRange	;
   Action	= ARRAY [0 .. 100000]	OF ActionType	;

VAR
   RuleBasePtr	: POINTER TO RuleBase	;
   RuleBaseSize	: LONGINT		;
   RulePtr	: POINTER TO Rule	;
   RuleSize	: LONGINT		;
   BasePtr	: POINTER TO Base	;
   BaseSize	: LONGINT		;
   DefaultPtr	: POINTER TO Default	;
   DefaultSize	: LONGINT		;
   ControlPtr	: POINTER TO Control	;
   ControlSize	: LONGINT		;
   EobTransPtr	: POINTER TO EobTrans	;
   EobTransSize	: LONGINT		;
   ContextPtr	: POINTER TO Context	;
   ContextSize	: LONGINT		;
   ActionPtr	: POINTER TO Action	;
   ActionSize	: LONGINT		;

   ActionNr	: ActionType	;
   TableSize	: TableRange	;
   TableEntries	: TableRange	;

PROCEDURE MakeTables		(ReduceCaseSize: BOOLEAN);
PROCEDURE CompressTables	(Optimize: SHORTINT);
PROCEDURE PutEiffelTables	(ReduceCaseSize: BOOLEAN);
PROCEDURE WriteTables		;
PROCEDURE QueryTables		;
PROCEDURE PutComb		(File: tFile);
PROCEDURE PutBase		(File: tFile);
PROCEDURE PutDefault		(File: tFile);
PROCEDURE PutEobTrans		(File: tFile);
PROCEDURE PutAction		(File: tFile);
PROCEDURE PutToClassUpb		(File: tFile);
PROCEDURE PutToClassClass	(File: tFile);
PROCEDURE PutToClassArray	(File: tFile);
PROCEDURE PutTableParts		(File: tFile; ReduceCaseSize: BOOLEAN);
PROCEDURE CopyTableParts	(File: tFile; ReduceCaseSize: BOOLEAN);

END ScanTabs.
