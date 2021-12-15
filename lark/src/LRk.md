(* $Id: LRk.md,v 1.3 2008/09/13 15:40:51 grosch Exp $ *)

(*
 * $Log: LRk.md,v $
 * Revision 1.3  2008/09/13 15:40:51  grosch
 * fixed notation for comment leader
 *
 * Revision 1.2  1998/04/21 12:58:31  grosch
 * added constant MaxK
 * introduced procedure GetLATreeIndex
 *
 * Revision 1.1  1995/11/07  09:22:48  grosch
 * major redesign for handling of LALR(2) grammars
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Okt. 1995 *)

DEFINITION MODULE LRk;

FROM IO		IMPORT tFile;
FROM Sets	IMPORT tSet;
FROM Tree	IMPORT tpSet;

CONST MaxK	= 32;

TYPE
   tpNode	= POINTER TO tNode;

   tpArray	= POINTER TO ARRAY [0..100000] OF tpNode;

   tNode	= RECORD
		     Set	: tSet;
		     Array	: tpArray;
		     Token	: POINTER TO ARRAY [0..100000] OF SHORTCARD;
		     MinToken	: SHORTCARD;
		     MaxToken	: SHORTCARD;
		  END;

   tpLAK	= RECORD
		     LAK	: POINTER TO tLAK;
		  END;
   
   tLAK		= RECORD
		     N1		: POINTER TO ARRAY [2..MaxK] OF SHORTCARD;
		     Look1	: POINTER TO ARRAY [2..MaxK] OF tpSet;
		     N		: POINTER TO ARRAY [2..MaxK] OF SHORTCARD;
		     Look	: tpNode;
		  END;

   tLATree	= RECORD
		     Item	: CARDINAL;
		     Look1	: POINTER TO ARRAY [2..MaxK] OF tpSet;
		     Node	: tNode;
		  END;

VAR
   LimitK	: SHORTCARD;
   LAKPtr	: POINTER TO ARRAY [0..100000] OF tpLAK;
   LAKSize	: LONGINT;
   LATreePtr	: POINTER TO ARRAY [0..100000] OF tLATree;
   LATreeSize	: LONGINT;
   LATreeCount	: LONGINT;

PROCEDURE CheckLRk	(State, x: CARDINAL; ConflictSet1: tSet; VAR ElseItem: CARDINAL): INTEGER;
PROCEDURE GetLATreeIndex (Item: CARDINAL): CARDINAL;
PROCEDURE CloseLRk	;

END LRk.
