(* handle oper section *)

(* $Id: Oper.md,v 1.3 1997/05/27 15:14:05 grosch rel $ *)

(*
 * $Log: Oper.md,v $
 * Revision 1.3  1997/05/27 15:14:05  grosch
 * cosmetic changes
 *
 * Revision 1.2  1991/11/21 14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.1  90/06/11  18:45:04  grosch
 * layout improvements
 * 
 * Revision 1.0	 88/10/04  14:26:53  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE Oper;

FROM Lists	IMPORT tList;
FROM TokenTab	IMPORT Vocabulary,PosType;
FROM Idents	IMPORT tIdent;

TYPE OperKind = (Left, Right, None);

  PROCEDURE MakePriority
    (Art : OperKind;
     Pos : PosType); 
  
  (* Festlegen einer neuen Assoziativitaet (LEFT/RIGHT) und damit einer
     neuen, d.h. um eins erhoehten Prioritaet *)


  PROCEDURE CompletePriority
    (Comment : tList;
     CommPos  : PosType);
      
  (* Eintragen des zu einer Prioritaet gehoerigen Kommentars,  
     gleichzeitig Abschluss dieser Prioritaet. Optional nach
     MakePriority bzw nach MakeOperator. *)


  PROCEDURE MakeOperator
    (Token    : tIdent;
     TokenPos : PosType);

  (* Eintragen des naechsten Operators mit der aktuellen Prioritaet.
     Nur zulaessig nach MakePriority . *)


  PROCEDURE MakeOperHeader
    (OPERPos   : PosType;
     Comment   : tList;
     CommPos	: PosType);

  (* Eintragen des Anfangskommentars des Abschnitts OPER sowie der
     Position des Schluesselwortes OPER. *)


  PROCEDURE InitPrioReading;

  (* Initialisiert des Lesen mit GetPriority. Nach dem ersten Aufruf ist 
     kein Schreiben innerhalb von Oper mehr moeglich. Wiederholter Aufruf
     setzt Lesezeiger an den Anfang zurueck. *)

  
  PROCEDURE GetOperHeader
    (VAR OPERPos  : PosType;
     VAR Comment  : tList;
     VAR CommPos   : PosType):BOOLEAN;
      
  (* Lesen der mit MakeOperHeader abgelegten Information *) 


  PROCEDURE GetPriority
    (VAR Art	 : OperKind;
     VAR Pos	 : PosType;
     VAR Comment : tList;
     VAR CommPos  : PosType): BOOLEAN;
      
  (* Lesen der mit MakePriority und CompletePriority abgelegten
     Information. (FIFO). Ist das Lesen erfolgreich, wird TRUE
     zurueckgeliefert, sonst (Listenende erreicht) FALSE. *)


  PROCEDURE GetOperator
    (VAR Token	  : Vocabulary;
     VAR TokenPos : PosType): BOOLEAN;

  (* Lesen der naechsten mit MakeOperator unter der aktuellen 
     Prioritaet abgelegten Information. Ist das Lesen erfolgreich, 
     wird TRUE zurueckgeliefert, sonst (Listenende erreicht) FALSE *)

END Oper.
