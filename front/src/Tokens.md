(* handle token section *)

(* $Id: Tokens.md,v 1.3 1997/05/27 15:14:05 grosch rel $ *)

(*
 * $Log: Tokens.md,v $
 * Revision 1.3  1997/05/27 15:14:05  grosch
 * cosmetic changes
 *
 * Revision 1.2  1991/11/21 14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.1  90/06/11  18:45:47  grosch
 * layout improvements
 * 
 * Revision 1.0	 88/10/04  14:27:25  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE Tokens;
 
FROM Lists	IMPORT tList;
FROM TokenTab	IMPORT Vocabulary,PosType,Terminal;
FROM Idents	IMPORT tIdent;

  PROCEDURE MakeGlobalHeader
    (GlobalComment : tList;
     GlobalCommPos : PosType);

  (* Speichert den globalen Kommentar *)

  PROCEDURE  MakeTokensHeader
    (TOKENPos	   : PosType;
     TOKENComment  : tList;
     TOKENCommPos  : PosType);
  
  (* Speichert globale Informationen ueber den zu TOKEN gehoerigen
     Abschnitt *)

  PROCEDURE MakeDeclaration
    (Token	: tIdent;
     TokenPos	: PosType; 
     HasCoding	: BOOLEAN;
     EQUALPos	: PosType;
     Number	: Terminal;
     NumberPos	: PosType;
     Comment	: tList;
     CommPos	: PosType);
  
  (* Fuege neue Deklaration ein. *)

  PROCEDURE  CompleteDeclarations;
   
  (* Vervollstaendigt die Eintraege in der Tokentable. Muss n a c h
     dem letzten MakeDeclaration und v o r dem ersten GetDeclaration
     aufgerufen werden. *)

  PROCEDURE  GetGlobalHeader
    (VAR GlobalComment : tList;
     VAR GlobalCommPos : PosType);

  (* liest die mit MakeGlobalHeader abgelegte Information *)

  PROCEDURE  GetTokensHeader
    (VAR TOKENPos      : PosType;
     VAR TOKENComment  : tList;
     VAR TOKENCommPos  : PosType);

  (* liest die mit MakeTokensHeader abgelegte Information *)

  PROCEDURE GetDeclaration
    (VAR Token	    : tIdent;
     VAR TokenPos   : PosType; 
     VAR HasCoding  : BOOLEAN;
     VAR EQUALPos   : PosType;
     VAR NumberPos  : PosType;
     VAR Comment    : tList;
     VAR CommPos    : PosType) : BOOLEAN;
  
  (* liefert die naechste Deklaration, falls vorhanden. Ansonsten wird
     FALSE zurueckgegeben. *)


END Tokens.
