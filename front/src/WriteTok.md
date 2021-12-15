(* generate output procedure for tokens *)

(* $Id: WriteTok.md,v 1.5 1997/05/27 15:14:05 grosch rel $ *)

(*
 * $Log: WriteTok.md,v $
 * Revision 1.5  1997/05/27 15:14:05  grosch
 * cosmetic changes
 *
 * Revision 1.4  1993/05/28 14:13:21  grosch
 * added target language Eiffel
 *
 * Revision 1.3  1991/11/21  14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.2  90/06/11  18:45:51  grosch
 * layout improvements
 * 
 * Revision 1.1	 89/01/12  17:45:26  vielsack
 * supply source file name
 * 
 * Revision 1.0	 88/10/04  14:27:28  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE WriteTok;

  FROM IO IMPORT tFile;

  TYPE tLanguage = (Modula2, C, Eiffel);
  
  VAR
    Language  : tLanguage;
    SourceFileName : ARRAY [0..255] OF CHAR;

  PROCEDURE GenWrTo (f : tFile);

END WriteTok.
