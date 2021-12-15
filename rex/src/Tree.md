(* $Id: Tree.md,v 3.6 2001/08/08 14:57:56 grosch rel $ *)

(*
 * $Log: Tree.md,v $
 * Revision 3.6  2001/08/08 14:57:56  grosch
 * added and revised support for #line directives
 *
 * Revision 3.5  2000/09/12 17:39:40  grosch
 * added support for Unicode
 *
 * Revision 3.4  1998/04/21 10:32:57  grosch
 * cosmetic changes
 * truncation of file and module names to 8.3 format
 *
 * Revision 3.3  1994/04/05 09:11:01  grosch
 * added handling of CHARACTER_SET
 *
 * Revision 3.2  1992/08/07  15:10:26  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 3.1  1991/11/21  14:41:19  grosch
 * fixed bug: interference of right context between constant and non-constant RE
 * new version of RCS on SPARC
 *
 * Revision 3.0  91/04/04  18:08:03  grosch
 * introduced partitioning of character set
 *
 * Revision 2.0  91/03/08  18:18:07  grosch
 * turned tables into initialized arrays (in C)
 * reduced case size
 * changed interface for source position
 *
 * Revision 1.2  89/02/23  15:56:01  grosch
 * added completeness check for the automaton
 *
 * Revision 1.1  89/01/17  15:01:41  grosch
 * correction and redesign of source position handling
 *
 * Revision 1.0  88/10/04  11:59:54  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1987 *)

DEFINITION MODULE Tree;

FROM Sets	IMPORT tSet;
FROM Texts	IMPORT tText;
FROM WStrings	IMPORT WCHAR;
FROM StringM	IMPORT tWStringRef;
FROM Position	IMPORT tPosition;
FROM Idents	IMPORT tIdent;

CONST
   NoTree	= NIL;

   nList	= 1;
   nRule	= 2;
   nPattern	= 3;
   nAlternative	= 4;
   nSequence	= 5;
   nRepetition	= 6;
   nOption	= 7;
   nChar	= 8;
   nSet		= 9;
   nString	= 10;

TYPE
   tTree	= POINTER TO Node;

   Node0	= RECORD
		     Rule	: SHORTCARD	;
		  END;

   Node1	= RECORD
		     Rule	: SHORTCARD	;
		     Son1	: tTree		;
		  END;

   Node2	= RECORD
		     Rule	: SHORTCARD	;
		     Son1	: tTree		;
		     Son2	: tTree		;
		  END;

   NodeCh	= RECORD
		     Rule	: SHORTCARD	;
		     Ch		: WCHAR		;
		  END;

   NodeSet	= RECORD
		     Rule	: SHORTCARD	;
		     Set	: tSet		;
		  END;

   NodeString	= RECORD
		     Rule	: SHORTCARD	;
		     String	: tWStringRef	;
		  END;

   NodeRule	= RECORD
		     Rule	: SHORTCARD	;
		     Patterns	: tTree		;
		     TargetCode	: tText		;
		     File	: tIdent	;
		     Line	: CARDINAL	;
		     CodeMode	: SHORTCARD	;
		     RuleNr	: SHORTCARD	;
		  END;

   NodePattern	= RECORD
		     Rule	: SHORTCARD	;
		     StartStates: tSet		;
		     RegExpr	: tTree		;
		     RightContext: tTree	;
		     IsConstantRE: BOOLEAN	;
		     PatternNr	: SHORTCARD	;
		     Position	: tPosition	;
		  END;

   Node		= RECORD
		     CASE : CARDINAL OF
		     |  0: vNode0	: Node0		;
		     |  1: vNode1	: Node1		;
		     |  2: vNode2	: Node2		;
		     |  3: vNodeCh	: NodeCh	;
		     |  4: vNodeSet	: NodeSet	;
		     |  5: vNodeString	: NodeString	;
		     |  6: vNodeRule	: NodeRule	;
		     |  7: vNodePattern	: NodePattern	;
		     END;
		  END;

PROCEDURE MakeTree1	(pRule: SHORTCARD; pSon1: tTree): tTree;
PROCEDURE MakeTree2	(pRule: SHORTCARD; pSon1, pSon2: tTree): tTree;
PROCEDURE MakeTreeCh	(pRule: SHORTCARD; pCh: WCHAR): tTree;
PROCEDURE MakeTreeSet	(pRule: SHORTCARD; pSet: tSet): tTree;
PROCEDURE MakeTreeString(pRule: SHORTCARD; pString: tWStringRef): tTree;
PROCEDURE MakeTreeRule	(pRule: SHORTCARD; pPatterns: tTree; pTargetCode: tText;
			 pFile: tIdent; pLine: CARDINAL;
			 pCodeMode, pRuleNr: SHORTCARD): tTree;
PROCEDURE MakeTreePattern(pRule: SHORTCARD; pStartStates: tSet; pRegExpr,
			pRightContext: tTree; pIsConstantRE: BOOLEAN;
			pPatternNr: SHORTCARD; pPosition: tPosition): tTree;
PROCEDURE WriteTree	(t: tTree);

VAR CharCode	: ARRAY CHAR OF CHAR;

END Tree.
