(*
 *	ell2 - a redesign of ell
 *
 *	$RCSfile: Codes.md,v $
 *	
 *	purpose:	handle the terminals codes
 *
 *	$Author: grosch $
 *	$Date: 2008/09/03 09:23:39 $
 *)

DEFINITION MODULE Codes;

FROM Idents	IMPORT	tIdent;
FROM Sets	IMPORT	tSet;
FROM IO		IMPORT	tFile;

CONST cNoIndex	= -1;

VAR vMaxRecSetIndex, vMaxSetIndex, EmptyRecSetIndex: INTEGER;

TYPE tCode	= INTEGER;

PROCEDURE SetCode	(term: tIdent; string: tIdent; code: tCode);
PROCEDURE Code		(term: tIdent): tCode;
PROCEDURE Term		(code: tCode): tIdent;
PROCEDURE String	(code: tCode): tIdent;
PROCEDURE IsCoded	(term: tIdent): BOOLEAN;
PROCEDURE IsCode	(code: tCode): BOOLEAN;
PROCEDURE SetDefCode	(term: tIdent; string: tIdent);
PROCEDURE MaxCode	(): tCode;

PROCEDURE RecSetIndex	(set: tSet): INTEGER;
PROCEDURE SetIndex	(set: tSet): INTEGER;
PROCEDURE GetRecSet	(index: INTEGER; VAR set: tSet);
PROCEDURE GetSet	(index: INTEGER; VAR set: tSet);

PROCEDURE WriteIndex	(f: tFile; index: INTEGER);
PROCEDURE WriteRecIndex (f: tFile; index: INTEGER);
PROCEDURE WriteTerminal	(f: tFile; ident: tIdent);

(* CODES_ )*
PROCEDURE WriteCodes	(f: tFile);
*( _CODES *)

END Codes.
