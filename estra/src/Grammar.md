(* $Id: Grammar.md,v 2.0 1989/06/22 13:09:52 vielsack rel $ *)

DEFINITION MODULE Grammar;

FROM	Idents		IMPORT	tIdent;
FROM	Sets		IMPORT	tSet;

(* GRAM_ *)
FROM	IO		IMPORT	tFile;
(* _GRAM *)

TYPE
  tLayout =
    POINTER TO tLayoutRec;

  tSon =
    tIdent;
  
  tSons =
    POINTER TO ARRAY [0..100] OF tSon;

  tLayoutRec =
    RECORD
      node: tIdent;
      class: tIdent;
      sons: tSons;
    END;

PROCEDURE BeginGrammar;

PROCEDURE SetSuperClass		(class, super: tIdent);
PROCEDURE Connect		(node, class: tIdent);

PROCEDURE CompleteSubclasses;
PROCEDURE FixMainClasses;

PROCEDURE NodesOfClass		(class: tIdent; VAR nodes: tSet);
PROCEDURE ClassesOfNode		(node: tIdent; VAR classes: tSet);
PROCEDURE SuperClass		(class: tIdent): tIdent;
PROCEDURE IsSubclass		(class, super: tIdent): BOOLEAN;
PROCEDURE DirectSubclasses	(class: tIdent; VAR sub: tSet);
PROCEDURE Subclasses		(class: tIdent; VAR sub: tSet);
PROCEDURE MainClass		(node: tIdent): tIdent;

PROCEDURE SetNodeIdent		(node, id: tIdent);
PROCEDURE SetArity		(node: tIdent; arity: INTEGER);
PROCEDURE SetSonName		(node: tIdent; pos: INTEGER; name: tIdent);
PROCEDURE CreateLayout		(node, class: tIdent): tLayout;
PROCEDURE SetSonClass		(layout: tLayout; pos: INTEGER; class: tIdent);

PROCEDURE NodeIdent		(node: tIdent): tIdent;
PROCEDURE Arity			(node: tIdent): INTEGER;
PROCEDURE SonName		(node: tIdent; pos: INTEGER): tIdent;
PROCEDURE Layout		(node, class: tIdent): tLayout;
PROCEDURE SonClass		(layout: tLayout; pos: INTEGER): tIdent;

PROCEDURE MakePatNumbers	(size: INTEGER);
PROCEDURE AddPatNumber		(node: tIdent; number: INTEGER);
PROCEDURE PatsOfNode		(node: tIdent; VAR numbers: tSet);
PROCEDURE MaxArity		(): INTEGER;

(* GRAM_ *)
PROCEDURE WriteGrammar		(f: tFile);
(* _GRAM *)
END Grammar.
