(* check arguments *)

(* $Id: ArgCheck.md,v 1.6 1997/05/27 15:18:37 grosch rel $ *)

(*
 * $Log: ArgCheck.md,v $
 * Revision 1.6  1997/05/27 15:18:37  grosch
 * cosmetic changes
 *
 * Revision 1.5  1997/04/17 14:34:13  grosch
 * added support for # line 'dir\file' under Windows
 *
 * Revision 1.4  1992/08/07  15:34:15  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 1.3  1991/11/21  14:50:01  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.2  90/06/12  15:51:27  grosch
 * renamed main program to bnf, layout improvements
 * 
 * Revision 1.1	 89/05/02  14:21:11  vielsack
 * new options: -c -m
 * make source file name available
 * 
 * Revision 1.0	 88/10/04  14:47:20  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE ArgCheck;

VAR
  Line		: BOOLEAN;
  Generate	: BOOLEAN;
  NoActionFlag	: BOOLEAN;
  SourceFileName,
  SourceFileName2: ARRAY [0..255] OF CHAR;

PROCEDURE ArgCheck;

END ArgCheck.
