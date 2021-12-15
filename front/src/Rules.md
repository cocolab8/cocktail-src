(* handle rule section *)

(* $Id: Rules.md,v 1.4 1997/05/27 15:14:05 grosch rel $ *)

(*
 * $Log: Rules.md,v $
 * Revision 1.4  1997/05/27 15:14:05  grosch
 * cosmetic changes
 *
 * Revision 1.3  1991/11/21 14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.2  90/06/11  18:45:23  grosch
 * layout improvements
 * 
 * Revision 1.1	 89/01/23  15:47:43  vielsack
 * by using AppendArtificialNode instead of MakeArtificialNode
 * the tree order is the same as that of the input,
 * this is necessary to handle LL(1) conflicts correctly
 * 
 * Revision 1.0	 88/10/04  14:27:07  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE Rules;

  FROM Lists	IMPORT tList;
  FROM TokenTab IMPORT Terminal, NonTerminal, Vocabulary,PosType;
  FROM SYSTEM	IMPORT ADDRESS;
  FROM Idents	IMPORT tIdent;

  TYPE
    Operation = (Plus, Star, Optional, Bracket, Sequence, Separator, Alternative,
       ArtAlternative, Action, TermLeaf, NonTermLeaf,NoOperation);

    UnaryOperation = [Plus..Star];
    BracketOperation = [Optional..Bracket];
    BinaryOperation = [Sequence..Alternative];
    ArtificialOperation = [ArtAlternative..ArtAlternative];
    LeafOperation = [TermLeaf..NonTermLeaf];
    Expression;		(* eine rechte Seite *)
    MRules;		(* Regeln *)

  VAR NoExpression : Expression;	(* NIL *)

  PROCEDURE MakeLeafNode
    (Sym: tIdent;
     Pos: PosType) : Expression;
 
  (* Lege neuen Blattknoten an und liefere den Zeiger auf ihn
     zurueck. *)


  PROCEDURE MakeActionNode
    (Act: tList;
     Pos: PosType) : Expression;
  
  (* Lege neuen Actionknoten an und liefere den Zeiger auf ihn
     zurueck *)

  
  PROCEDURE MakeUnaryNode
    (Art: UnaryOperation;
     Pos: PosType;
     Son: Expression) : Expression;

  (* Bilde neuen Knoten der angegebenen Art mit gegebenem Sohn,
     und liefere den Zeiger auf ihn zurueck *)
  

  PROCEDURE MakeBracketNode
    (Art: BracketOperation;
     Pos,
     SecPos : PosType;
     Son: Expression) : Expression;

  (* Bilde neuen Knoten der angegebenen Art mit gegebenem Sohn,
     und liefere den Zeiger auf ihn zurueck *)
  

  PROCEDURE MakeBinaryNode
    (Art : BinaryOperation;
     Pos : PosType;
     LSon,
     RSon: Expression) : Expression;

  (* Bilde neuen Knoten der angegebenen Art mit gegebenen Soehnen,
     und liefere den Zeiger auf ihn zurueck *)


  PROCEDURE MakePrioAlternativeNode
    (Pos	: PosType;
     LSon,
     RSon	: Expression;
     HasPrio	: BOOLEAN;
     PRIOPos	: PosType;
     PrioSym	: tIdent;
     PrioSymPos : PosType) : Expression;
  
  (* entspricht MakeBinaryNode (Alternative,...) jedoch wird zusaetzlich
     eine Prioritaet abgespeichert *)


  PROCEDURE AppendArtificialNode
    (Pos, SecPos : PosType;
     VAR Expr: Expression;
     New: Expression);

  PROCEDURE PutNodeSpecial
    (Exp:  Expression;
     Spec: ADDRESS);
  
  (* Trage Knotensonderinformation ein *)
     

  PROCEDURE MakeRule
    (Left	: tIdent;
     LeftPos	: PosType;
     ColonPos	: PosType;
     Right	: Expression;
     Comment	: tList;
     CommPos	: PosType;
     PointPos	: PosType;
     HasPrio	: BOOLEAN;
     PRIOPos	: PosType;
     PrioSym	: tIdent;
     PrioSymPos : PosType);

  (* Trage eine neue Regel in die Datenstruktur ein *)


  PROCEDURE MakeRulesHeader
    (RULESPos	: PosType;
     Comment	: tList;
     CommPos	: PosType);

  (* Speichere globale Information zum Abschnitt RULES ab *)


  PROCEDURE InitRulesReading(); 

  (* Setze Lesezeiger auf Anfang der Liste. Gibt nach Schreib-
     zugriff Lesen am Anfang der Liste wieder frei. *)
      

  PROCEDURE GetNodeOperation (Exp: Expression): Operation;

  (* Hole Typinformation ueber Expression. Bei leerer Liste wird
     NoOperation zurueckgeliefert *)


  PROCEDURE GetLeafNode
    (	 Exp: Expression;
     VAR Voc: Vocabulary;
     VAR Pos: PosType);
 
  (* Liefere Information aus Blattknoten. *)


  PROCEDURE GetActionNode
    (	 Expr:Expression;
     VAR Act: tList;
     VAR Pos: PosType);
  
  (* Liefere Information aus Actionknoten *)

  
  PROCEDURE GetUnaryNode
    (	 Expr:Expression;
     VAR Pos: PosType;
     VAR Son: Expression);

  (* Liefere Information aus unaerem Knoten *) 
  

  PROCEDURE GetBracketNode
    (	 Expr:Expression;
     VAR Pos,
	 SecPos : PosType;
     VAR Son: Expression);

  (* Liefere Information aus Klammer-Knoten *) 
  

  PROCEDURE GetBinaryNode
    (	 Expr: Expression;
     VAR Pos : PosType;
     VAR LSon,
     RSon: Expression);

  (* Liefere Information aus binaerem Knoten *)

  PROCEDURE GetPrioAlternativeNode
    (	 Expr	    : Expression;
     VAR Pos	    : PosType;
     VAR LSon	    : Expression;
     VAR RSon	    : Expression;
     VAR HasPrio    : BOOLEAN;
     VAR PRIOPos    : PosType;
     VAR PrioSym    : tIdent;
     VAR PrioSymPos : PosType);
  
  (* entspricht MakeBinaryNode (Alternative,...) jedoch wird zusaetzlich
     eine Prioritaet abgespeichert *)


  PROCEDURE GetArtificialNode
    (	 Expr: Expression;
     VAR Pos : PosType;
     VAR SecPos : PosType;
     VAR LSon,
     RSon: Expression);

  (* Liefere Information aus kuenstlichem Knoten *)


  PROCEDURE GetNodeSpecial
    (Exp:  Expression) : ADDRESS;
  
  (* Liefere Knotensonderinformation *)
     

  PROCEDURE GetRule
    (VAR Left	    : NonTerminal;
     VAR LeftPos    : PosType;
     VAR ColonPos   : PosType;
     VAR Right	    : Expression;
     VAR Comment    : tList;
     VAR CommPos    : PosType;
     VAR PointPos   : PosType;
     VAR HasPrio    : BOOLEAN;
     VAR PRIOPos    : PosType;
     VAR PrioSym    : Terminal;
     VAR PrioSymPos : PosType) : BOOLEAN;

  (* Liefere naechste Regel bzw. FALSE falls es keine naechste Regel
     mehr gibt. Die erste Regel kann nach Aufruf von InitRulesReading
     gelesen werden. Kann in Wechsel mit GetEsentialRule verwendet 
     werden. *)

  PROCEDURE GetEssentialRule
    (VAR Left	    : NonTerminal;
     VAR Right	    : Expression;
     VAR HasPrio    : BOOLEAN) : BOOLEAN;

  (* Liefere naechste Regel bzw. FALSE falls es keine naechste Regel
     mehr gibt. Die erste Regel kann nach Aufruf von InitRulesReading
     gelesen werden.Kann im Wechsel mit GetRule verwendet werden *)

  PROCEDURE GetRulesHeader
    (VAR RULESPos   : PosType;
     VAR Comment    : tList;
     VAR CommPos    : PosType);

  (* Liefere globale Information zum Abschnitt RULES und initialisiere
     fuer das Lesen mit GetRule *)
  

END Rules.
