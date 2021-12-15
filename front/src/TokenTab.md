(* map tokens to internal representation *)

(* $Id: TokenTab.md,v 1.7 1997/05/27 15:04:18 grosch rel $ *)

(*
 * $Log: TokenTab.md,v $
 * Revision 1.7  1997/05/27 15:04:18  grosch
 * truncated module names to 8 characters:
 * Characte, StringM, Position
 *
 * Revision 1.6  1994/05/31 12:14:00  grosch
 * increase maximal number of nonterminals to 2000
 *
 * Revision 1.5  1992/08/07  15:13:51  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 1.4  1991/11/21  14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.3  91/10/11  16:30:47  grosch
 * increased cMAXNonTerm from 1023 to 2047
 * 
 * Revision 1.2  90/06/11  18:45:43  grosch
 * layout improvements
 * 
 * Revision 1.1	 89/01/26  19:03:21  vielsack
 * better position handling for nonterminals
 * 
 * Revision 1.0	 88/10/04  14:27:22  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE TokenTab;

FROM Strings	IMPORT tString;
FROM SYSTEM	IMPORT ADDRESS;
FROM Idents	IMPORT tIdent;
FROM Position	IMPORT tPosition;

  CONST
    MINTerm	= 0;
    cMAXTerm	= 1000;
    MINNonTerm	= cMAXTerm + 1;
    cMAXNonTerm = 3000;
    EndOfToken	= 0;

  VAR
    MAXTerm	: SHORTCARD;   (* tatsaechlich belegte Groesse *) (* read only *)
    MAXNonTerm	: SHORTCARD;

  TYPE
    PosType	= tPosition;
    TokenType	= (Term, NonTerm, None);
    NonTerminal = SHORTCARD [MINNonTerm..cMAXNonTerm];
    Vocabulary	= SHORTCARD [0..cMAXNonTerm+2];
    Terminal	= SHORTCARD [0..cMAXTerm];
    Prio	= SHORTCARD;
    TokenError	= (NoError, SymbolExists, CodeExists, OutOfRange, NotExists,NoIntCode,NotTerm);

PROCEDURE MakeTerm (sym: tIdent; VAR ter: Terminal; VAR Error: TokenError; pos: PosType);
  
  (* Fuege 'sym' als NEUES Terminal in TokenTab mit vorgegebener Codierung
     'ter' ein. Falls 'sym' bereits in der TokenTab steht, wird der alte Code
     zurueckgeliefert und Error auf StringExists gesetzt.
     Error = OutOfRange ,falls voc ausserhalb des fuer Terminals
     zulaessigen Bereichs ist
     Error = CodeExists, falls der angegebene Code bereits vergeben ist . *)
      
PROCEDURE MakeDefTerm (VAR sym: tIdent; VAR Error: TokenError; pos: PosType);

  (* Fuege s als NEUES Terminal in TokenTab ohne interne Codierung
     ein. Die Codierung muss nach Abschluss aller Eintraege in die
     TokenTab mit CompleteDefTerm nachgeholt werden. 
     Falls s bereits in der TokenTab steht, wird der alte Code zurueck-
     geliefert und Error auf StringExists gesetzt. *)

PROCEDURE CompleteDefTerm (sym: tIdent; VAR Error: TokenError);

  (* Traegt die interne Codierung fuer bereits mit MakeDefTerm eingetragene
     Terminale nach und liefert ihren Wert zurueck.Moegliche Fehler:
     Error = NotExists	   Noch gar nicht eingetragen
	     CodeExists	   Schon vollstaendig eingetragen
	     TokenOverflow Ueberlauf: zu viele Tokens;
	     NonTerm   sym ist Codierung fuer Nichtterminal; *)
  
PROCEDURE MakeVoc (sym: tIdent; symPos: PosType): Vocabulary;

  (* falls sym bereits vorhanden:
	die Codierung von sym wird zurueckgeliefert
     sonst:
	sym wird als NichtTerminal in die TokenTab eingetragen und die
	Codierung zurueckgeliefert. *)
 
PROCEDURE SetNontermPos (sym: tIdent; pos: PosType);

  (* setze Position eines Nichtterminals *)

PROCEDURE GetTokenType (voc: Vocabulary): TokenType;

  (* liefert den Typ des Tokens voc zurueck *)

PROCEDURE SymbolToToken (sym: tIdent; VAR Error: TokenError): Vocabulary;
  
  (* liefert die zum SymboltabellenEintrag sym gehoerige interne Darstellung*)
  (* Moegliche Fehler:
     Error = NotExists	  Es existiert ueberhaupt kein Eintrag
     Error = NoIntCode	  Code muss noch mit CompleteDefToken eingetragen
			  werden.
     Error = NoError	  Alles in Ordnung    *)

PROCEDURE TokenToSymbol (voc: Vocabulary; VAR Error: TokenError):tIdent;
  
  (* liefert die zum TokenTabeintrag voc gehoerige Darstellung
     in der Symboltabelle *)
  (* Moegliche Fehler:
     Error = NotExists	  Es existiert ueberhaupt kein Eintrag
			  werden.
     Error = NoError	  Alles in Ordnung    *)

PROCEDURE GetTokenPos (voc: Vocabulary; VAR pos: PosType);
  
  (* liefert die zu 'voc' gehoerige Position 'pos' zurueck *)
  
PROCEDURE PutPrio (voc: Vocabulary; p: Prio);

  (* Setzen der Prioritaet von voc auf p *)

PROCEDURE GetPrio (voc: Vocabulary):Prio;

  (* liefert die mit PutPriority eingetragene Prioritaet von voc.
     Ist nichts eingetragen, wird 0 zurueckgegeben. *)

PROCEDURE InitTokenTable;

  (* Initialisiere die TokenTab *)

END TokenTab.
