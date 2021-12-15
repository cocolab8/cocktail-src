(* $Id: Generate.md,v 1.7 2013/01/15 13:38:20 grosch Exp $ *)

(*
 * $Log: Generate.md,v $
 * Revision 1.7  2013/01/15 13:38:20  grosch
 * allow generation of large parsers in Java
 *
 * Revision 1.6  2010/07/07 09:53:55  grosch
 * added support for building of concrete syntax trees
 *
 * Revision 1.5  2008/09/25 14:50:35  grosch
 * revised handling of #@ line directives
 * renamed AppendLine -> MakeDirective, WriteLine -> WriteDirective
 *
 * Revision 1.4  2008/09/13 15:40:51  grosch
 * fixed notation for comment leader
 *
 * Revision 1.3  2001/08/08 15:01:15  grosch
 * added and revised support for #line directives
 *
 * Revision 1.2  1998/04/21 12:50:38  grosch
 * added external declaration for procedure WriteToken
 *
 * Revision 1.1  1995/11/07  09:18:00  grosch
 * export write procedures
 *
 * Revision 1.0  1994/02/01  14:05:45  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Jan. 1994 *)

DEFINITION MODULE Generate;

FROM IO		IMPORT tFile;
FROM Idents	IMPORT tIdent;
FROM Strings	IMPORT tString;
FROM Texts	IMPORT tText;

VAR CaseLabels	: CARDINAL;
  parser_name	: ARRAY [0..31] OF CHAR;
  parser_no	: CARDINAL;

PROCEDURE WriteC	(File: tFile; Ch: CHAR);
PROCEDURE WriteS	(File: tFile; Text: ARRAY OF CHAR);
PROCEDURE WriteI	(File: tFile; Value, Length: INTEGER);
PROCEDURE WriteN	(File: tFile; Value: LONGCARD; Length, Base: INTEGER);
PROCEDURE WriteNl	(File: tFile);
PROCEDURE WriteSpaces	(File: tFile; Count: INTEGER);
PROCEDURE WriteIdent	(File: tFile; Ident: tIdent);
PROCEDURE WriteL	(File: tFile; String: tString);
PROCEDURE WriteText	(File: tFile; Text: tText);
PROCEDURE Writeyy	(File: tFile; Ch: CHAR);
PROCEDURE WriteReduceCode (f: tFile; Rule: CARDINAL; dynamic: BOOLEAN);
PROCEDURE WriteToken	(f: tFile; t: CARDINAL);
PROCEDURE MakeDirective	(VAR Out: tString; Line: CARDINAL; File: tIdent);

PROCEDURE GenParser	;
PROCEDURE GenInterface	;
PROCEDURE GenDriver	;
PROCEDURE GenEiffelSupport;
PROCEDURE GenCSTreeFiles;

END Generate.
