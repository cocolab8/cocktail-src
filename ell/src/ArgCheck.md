(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: ArgCheck.md,v $
 *	
 *	purpose:	check arguments
 *
 *	$Author: grosch $
 *	$Date: 2008/09/25 14:46:18 $
 *)

DEFINITION MODULE ArgCheck;

FROM Strings	IMPORT	tString;

TYPE tLanguage = (C, MODULA2);

VAR
  DEF, IMP, PAR, LINE, ImplicitDecl, TokenConstants: BOOLEAN;
  LANGUAGE	: tLanguage;
  SourceFileName: ARRAY [0..255] OF CHAR;
  TokenPrefix	: ARRAY [0..63] OF CHAR;
  EllLib	: tString;

  (* ARG_ )*
  TREE, TABLE, CODES, QUERY: BOOLEAN;
  *( _ARG *)

PROCEDURE CheckArgs;

END ArgCheck.
