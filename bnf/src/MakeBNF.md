(* converte EBNF into BNF *)

(* $Id: MakeBNF.md,v 1.5 1997/05/27 15:18:37 grosch rel $ *)

(*
 * $Log: MakeBNF.md,v $
 * Revision 1.5  1997/05/27 15:18:37  grosch
 * cosmetic changes
 *
 * Revision 1.4  1991/12/04 16:24:36  grosch
 * unified escape conventions for all tools
 *
 * Revision 1.3  1991/11/21  14:50:01  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.2  90/06/12  15:51:28  grosch
 * renamed main program to bnf, layout improvements
 * 
 * Revision 1.1	 89/05/02  14:22:08  vielsack
 * line informations are written in the actions
 * the format depends on the target language (C or MODULA2)
 * 
 * Revision 1.0	 88/10/04  14:47:23  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE MakeBNF;

FROM IO IMPORT tFile;

PROCEDURE MakeBnf (out: tFile);

(* gibt die eingelesene Grammatik in BNF-Notation aus *)

END MakeBNF.
