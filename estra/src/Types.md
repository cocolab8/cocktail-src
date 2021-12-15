(* $Id: Types.md,v 2.0 1989/06/22 13:10:34 vielsack rel $ *)

DEFINITION MODULE Types;

FROM	Idents	IMPORT	tIdent;
FROM	Sets	IMPORT	tSet;

TYPE
  tType	= (cNoType, cTransformation, cFunction, cClass, cNode, cNodeId);

PROCEDURE BeginTypes;
PROCEDURE Type (id: tIdent): tType;
PROCEDURE MakeTransformation (name: tIdent);
PROCEDURE MakeFunction (name: tIdent);
PROCEDURE MakeClass (name: tIdent);
PROCEDURE MakeNode (name: tIdent);
PROCEDURE MakeNodeId (ident: tIdent);

PROCEDURE ClassCode (class: tIdent): INTEGER;
PROCEDURE MaxClassCode (): INTEGER;

PROCEDURE AllNodes (VAR nodes: tSet);
PROCEDURE AllClasses (VAR classes: tSet);

PROCEDURE SetEssential (name: tIdent);
PROCEDURE UnionEssential (set: tSet);
PROCEDURE Essential (name: tIdent): BOOLEAN;

END Types.
