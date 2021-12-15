(* handle global actions and comments *)

(* $Id: Actions.md,v 1.6 1997/05/27 15:04:18 grosch rel $ *)

(*
 * $Log: Actions.md,v $
 * Revision 1.6  1997/05/27 15:04:18  grosch
 * truncated module names to 8 characters:
 * Characte, StringM, Position
 *
 * Revision 1.5  1993/01/16 11:53:48  grosch
 * fixed bug in default GLOBAL section
 *
 * Revision 1.4  1992/08/07  15:13:51  grosch
 * allow several scanner and parsers; extend module Errors
 *
 * Revision 1.3  1991/12/04  16:21:41  grosch
 * unified escape conventions for all tools
 *
 * Revision 1.2  1991/11/21  14:47:50  grosch
 * new version of RCS on SPARC
 *
 * Revision 1.1  90/06/11  18:44:35  grosch
 * layout improvements
 * 
 * Revision 1.0	 88/10/04  14:26:32  vielsack
 * Initial revision
 * 
 *)

DEFINITION MODULE Actions;

FROM TokenTab	IMPORT PosType;
FROM StringM	IMPORT tStringRef;
FROM Strings	IMPORT tString;
FROM Idents	IMPORT tIdent;
FROM IO		IMPORT tFile;
FROM Lists	IMPORT tList;

TYPE tActionMode = (Export, Global, Local, Begin, Close);

VAR ScannerName	: tIdent;
VAR ParserName	: tIdent;

PROCEDURE PutComment (kind: tActionMode; kp: PosType; c: tList; cp: PosType);

(* Eintragen des zum Abschnitt DECL gehoerigen Kommentars *)

PROCEDURE GetComment (kind: tActionMode; VAR kp: PosType; VAR c: tList; VAR cp: PosType);

(* Lesen des zum Abschnitt DECL gehoerigen Kommentars *)

PROCEDURE PutAction (kind: tActionMode; a: tList; ap: PosType; c: tList; cp: PosType);

(* Eintragen einer Semantischen Aktion mit zugh. Kommentar *)

PROCEDURE GetAction (kind: tActionMode; VAR a: tList; VAR ap: PosType; VAR c: tList; VAR cp: PosType);

(* Lesen einer Semantischen Aktion mit zugh. Kommentar *)

PROCEDURE WriteActions (kind: tActionMode; f: tFile; Line: BOOLEAN);

(* Ausgabe der gesamten Deklaration des angegebenen Abschnitts auf eine Datei *)

PROCEDURE WriteSemanticAction (f: tFile; a: tList; t: CARDINAL);

(* Ausgabe der Semantischen Aktion 'a' auf Datei 'f' mit 2 * 't' *)
(* Leerzeichen am Zeilenanfang *)

PROCEDURE WriteStringList (file: tFile; slist: tList);

(* Ausgabe einer tList auf file *)

PROCEDURE InitDefaultActions;

END Actions.
