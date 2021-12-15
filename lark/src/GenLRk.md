(* $Id: GenLRk.md,v 1.2 2008/09/13 15:40:41 grosch Exp $ *)

(*
 * $Log: GenLRk.md,v $
 * Revision 1.2  2008/09/13 15:40:41  grosch
 * fixed notation for comment leader
 *
 * Revision 1.1  1998/04/21 10:47:49  grosch
 * added procedure WriteLook
 *
 * Revision 1.0  1995/11/07  09:33:17  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Okt. 1994 *)

DEFINITION MODULE GenLRk;

FROM IO		IMPORT tFile;

PROCEDURE WriteCaseLRk	(f: tFile; Rule: CARDINAL);
PROCEDURE WriteRead	(f: tFile; Rule: CARDINAL);
PROCEDURE WriteReduce	(f: tFile; Rule: CARDINAL);
PROCEDURE WriteLook	(f: tFile; Rule, Item: CARDINAL);
  
END GenLRk.
