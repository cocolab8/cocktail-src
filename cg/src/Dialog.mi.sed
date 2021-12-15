(* Ich, Doktor Josef Grosch, Informatiker, 23.5.1989 *)

IMPLEMENTATION MODULE Dialog;

FROM SYSTEM	IMPORT TSIZE;
FROM DynArray	IMPORT MakeArray, ExtendArray, ReleaseArray;
FROM IO		IMPORT StdInput, ReadC, StdOutput, WriteI, WriteS, WriteNl;
FROM Strings	IMPORT tString, ArrayToString, WriteL;
FROM Idents	IMPORT tIdent, MakeIdent, WriteIdent;

FROM Sets	IMPORT
   tSet		, MakeSet	, ReleaseSet	, IsElement	;

FROM Relation	IMPORT
   tRelation	, MakeRelation	, ReleaseRelation, Closure	,
   IsRelated	, Assign	, Difference	, GetCyclics	;

FROM Tree	IMPORT
   NoTree	, tTree		, tInstance	,
   Computed	, Reverse	, Write		, Read		,
   Inherited	, Synthesized	, Input		, Output	,
   Stack	, Parameter	, Variable	,
   CopyDef	, CopyUse	, Thread	, Test		,
   Left		, Right		, Def		, Use		,
   ChildUse	, ParentUse	, NonBaseComp	, First		,
   Dummy	, Virtual	, Demand	, f		,
   WriteName	, WriteDependencies, WriteClass	, MaxSet	,
   GrammarClass	, cLNC	, cDNC	, cLAG	, cOAG	, cSAG	, cSNC	,
   QueryTree	, IdentifyClass	, IdentifyAttribute;

FROM Order	IMPORT WriteOrderDecl, WriteOrderEval, WriteVisitSequence, IndexToClass;

IMPORT Tree;

TYPE tDepend	= RECORD A, B: SHORTCARD; Rule: tTree; END;

VAR
   Cyclics	: tSet;
   ClassCount	: SHORTCARD;
   String	: tString;

   MarkSize	: LONGINT;
   MarkPtr	: POINTER TO ARRAY [0 .. 10000] OF tDepend;
   MarkCount	: INTEGER;

   TraceSize	: LONGINT;
   TracePtr	: POINTER TO ARRAY [0 .. 10000] OF tDepend;
   TraceCount	: INTEGER;

PROCEDURE Find (a, b: SHORTCARD; rule: tTree): BOOLEAN;
   VAR
      c, UserIndex		: SHORTCARD;
      i, markCount, traceCount	: INTEGER;
      DPClosure			: tRelation;
      UserClass			: tTree;

   PROCEDURE ForallClasses (t: tTree): BOOLEAN;
      BEGIN
	 IF t^.Kind = Tree.Class THEN
	    WITH rule^.Class DO
	       WITH Instance^[a].Selector^.Child DO
		  IF Find (SHORTCARD (a - AttrCount - InstOffset),
			   SHORTCARD (b - AttrCount - InstOffset), t) THEN
		     RETURN TRUE;
		  END;
	       END;
	    END;
	    IF ForallClasses (t^.Class.Extensions) THEN RETURN TRUE; END;
	    RETURN ForallClasses (t^.Class.Next);
	 ELSE
	    RETURN FALSE;
	 END;
      END ForallClasses;

   PROCEDURE ForallAttributes (t: tTree): BOOLEAN;
      BEGIN
	 CASE t^.Kind OF
	 | Tree.Class:
	       IF ForallAttributes (t^.Class.BaseClass) THEN
		  RETURN TRUE;
	       ELSE
		  RETURN ForallAttributes (t^.Class.Attributes);
	       END;
	 | Tree.Child:
	       WITH UserClass^.Class DO WITH t^.Child DO
		  IF (Class = rule) AND
		     Find (SHORTCARD (AttrCount + InstOffset + a),
			   SHORTCARD (AttrCount + InstOffset + b), UserClass) THEN
		     RETURN TRUE;
		  END;
	       END; END;
	       RETURN ForallAttributes (t^.Child.Next);
	 | Tree.Attribute:
	       RETURN ForallAttributes (t^.Attribute.Next);
	 | Tree.ActionPart:
	       RETURN ForallAttributes (t^.ActionPart.Next);
	 ELSE
	       RETURN FALSE;
	 END;
      END ForallAttributes;

   BEGIN
      WITH rule^.Class DO
	 IF NOT (((cSNC IN GrammarClass) AND IsRelated (a, b, DNC)) OR
		 ((cLNC IN GrammarClass) AND IsRelated (a, b, SNC))) THEN RETURN FALSE; END;

	 FOR i := 1 TO MarkCount DO	(* IF (a, b, rule) IN Mark THEN RETURN FALSE *)
	    WITH MarkPtr^ [i] DO
	       IF (a = A) AND (b = B) AND (rule = Rule) THEN RETURN FALSE; END;
	    END;
	 END;

	 INC (MarkCount);		(* Mark := Mark UNION (a, b, rule)	*)
	 IF MarkCount = MarkSize THEN
	    ExtendArray (MarkPtr, MarkSize, TSIZE (tDepend));
	 END;
	 WITH MarkPtr^ [MarkCount] DO
	    A := a; B := b; Rule := rule;
	 END;

	 markCount	:= MarkCount;	(* Mark = set checkpoint		*)
	 traceCount	:= TraceCount;

	 MakeRelation (DPClosure, InstCount, InstCount);
	 Assign (DPClosure, DP);
	 Closure (DPClosure);
	 IF IsRelated (a, b, DPClosure) THEN
	    FOR c := 1 TO InstCount DO
	       IF IsRelated (a, c, DP) AND (IsRelated (c, b, DPClosure) OR (c = b)) THEN
		  INC (TraceCount);
		  IF TraceCount = TraceSize THEN
		     ExtendArray (TracePtr, TraceSize, TSIZE (tDepend));
		  END;
		  WITH TracePtr^ [TraceCount] DO
		     A := a; B := c; Rule := rule;
		  END;
		  ReleaseRelation (DPClosure);
		  RETURN (c = b) OR Find (c, b, rule);
	       END;
	    END;
	 END;
	 ReleaseRelation (DPClosure);

	 IF (Right IN Instance^[a].Properties) AND (Right IN Instance^[b].Properties) AND
	    (Instance^[a].Selector = Instance^[b].Selector) AND (Instance^[a].Selector # NoTree) THEN
	    WITH Instance^[a].Selector^.Child DO
	       IF Find (SHORTCARD (a - AttrCount - InstOffset),
			SHORTCARD (b - AttrCount - InstOffset), Class) THEN
		  RETURN TRUE;
	       END;
	       IF ForallClasses (Class^.Class.Extensions) THEN RETURN TRUE; END;
	    END;
	 END;

	 IF (Left IN Instance^[a].Properties) AND (Left IN Instance^[b].Properties) THEN
	    FOR UserIndex := 1 TO ClassCount DO
	       IF IsElement (UserIndex, Users) THEN
		  UserClass := IndexToClass^[UserIndex];
		  IF ForallAttributes (UserClass) THEN RETURN TRUE; END;
	       END;
	    END;
	 END;

	 IF cLNC IN GrammarClass THEN
	    FOR c := 1 TO InstCount DO
	       IF IsRelated (a, c, SNC) AND IsRelated (c, b, SNC) AND
		  Find (a, c, rule) AND Find (c, b, rule) THEN RETURN TRUE; END;
	    END;
	 END;

	 IF cSNC IN GrammarClass THEN
	    FOR c := 1 TO InstCount DO
	       IF IsRelated (a, c, DNC) AND IsRelated (c, b, DNC) AND
		  Find (a, c, rule) AND Find (c, b, rule) THEN RETURN TRUE; END;
	    END;
	 END;

	 MarkCount	:= markCount;	(* Release = return to last checkpoint	*)
	 TraceCount	:= traceCount;
	 RETURN FALSE;
      END;
   END Find;

PROCEDURE FindPath (a, b: SHORTCARD; rule: tTree);
   VAR i	: INTEGER;
   BEGIN
      WITH rule^.Class DO
	 WriteIdent	(StdOutput, Name);
	 WriteS		(StdOutput, "	");
	 WriteName	(Instance^ [a]);
	 WriteS		(StdOutput, "	");
	 WriteName	(Instance^ [b]);
	 WriteNl	(StdOutput);
	 WriteNl	(StdOutput);
      END;
      MarkSize := 32;
      MakeArray (MarkPtr, MarkSize, TSIZE (tDepend));
      MarkCount := 0;
      TraceSize := 32;
      MakeArray (TracePtr, TraceSize, TSIZE (tDepend));
      TraceCount := 0;
      IF Find (a, b, rule) THEN
	 FOR i := 1 TO TraceCount DO
	    WITH TracePtr^ [i] DO
	       WriteIdent	(StdOutput, Rule^.Class.Name);
	       WriteS		(StdOutput, "	");
	       WriteName	(Rule^.Class.Instance^ [A]);
	       WriteS		(StdOutput, "	");
	       WriteName	(Rule^.Class.Instance^ [B]);
	       WriteNl		(StdOutput);
	    END;
	 END;
      END;
      ReleaseArray (MarkPtr, MarkSize, TSIZE (tDepend));
      ReleaseArray (TracePtr, TraceSize, TSIZE (tDepend));
   END FindPath;

PROCEDURE Menue;
   BEGIN
      f := StdOutput;
      !!
      ! Dialog System!
      !!
      !   <name>          select current node type (rule)!
      ! t <name>          select current node type (rule)!
      ! a <name>[:<name>] select current attribute instance a!
      ! b <name>[:<name>] select current attribute instance b!
      !!
      ! P print dependency relation DP  for complete node type!
      ! p print dependency relation DP  for current attribute instance!
      ! S print dependency relation SNC for complete node type!
      ! s print dependency relation SNC for current attribute instance!
      ! N print dependency relation DNC for complete node type!
      ! n print dependency relation DNC for current attribute instance!
      ! O print dependency relation OAG for complete node type!
      ! o print dependency relation OAG for current attribute instance!
      ! C print dependencies introduced for total order for complete node type!
      ! c print dependencies introduced for total order for cyclic attributes!
      ! G print attribute instances sorted by declaration order!
      ! E print attribute instances sorted by evaluation order!
      ! V print visit sequence!
      ! F search for and print dependency path between attributes a and b!
      ! M print summary of node type (rule) from source!
      ! Q browse internal data structure of complete attribute grammar!
      ! q browse internal data structure of current node type!
      ! h print menue for dialog system!
      ! ? print current state!
      ! x exit dialog system!
      !!
   END Menue;

PROCEDURE Dialog (t: tTree);
   VAR
      Com, Ch		: CHAR;
      Class, ChildsClass: tTree;
      Attribute		: tTree;
      Name0, Name1, Name2	: ARRAY [0..64] OF CHAR;
      Length0, Length1, Length2	: INTEGER;
      Ident		: tIdent;
      a, b, Offset	: SHORTCARD;
   BEGIN
      Menue;
      Class := NoTree;
      a := 0;
      b := 0;

      LOOP
	 WriteS (StdOutput, "? ");
	 Ch := ReadC (StdInput); IF Ch = 0C THEN EXIT; END;

	 Length0 := -1;
	 WHILE (Ch > ' ') AND (Ch # ':') DO
	    INC (Length0); Name0 [Length0] := Ch;
	    Ch := ReadC (StdInput); IF Ch = 0C THEN EXIT; END;
	 END;
	 Name0 [Length0 + 1] := 0C;

	 WHILE (Ch <= ' ') AND (Ch # 12C) OR (Ch = ':') DO
	    Ch := ReadC (StdInput); IF Ch = 0C THEN EXIT; END;
	 END;

	 Length1 := -1;
	 WHILE (Ch > ' ') AND (Ch # ':') DO
	    INC (Length1); Name1 [Length1] := Ch;
	    Ch := ReadC (StdInput); IF Ch = 0C THEN EXIT; END;
	 END;
	 Name1 [Length1 + 1] := 0C;

	 WHILE (Ch <= ' ') AND (Ch # 12C) OR (Ch = ':') DO
	    Ch := ReadC (StdInput); IF Ch = 0C THEN EXIT; END;
	 END;

	 Length2 := -1;
	 WHILE (Ch > ' ') AND (Ch # ':') DO
	    INC (Length2); Name2 [Length2] := Ch;
	    Ch := ReadC (StdInput); IF Ch = 0C THEN EXIT; END;
	 END;
	 Name2 [Length2 + 1] := 0C;

	 WHILE Ch # 12C DO
	    Ch := ReadC (StdInput); IF Ch = 0C THEN EXIT; END;
	 END;

	 IF Length0 = 0 THEN
	    Com := Name0 [0];
	    CASE Com OF
	    | 't',
	      'T': (* <name>          select current node type (rule)	*)
		     ArrayToString (Name1, String);
		     Ident := MakeIdent (String);
		     Class := IdentifyClass (t^.Ag.Classes, Ident);
		     IF Class = NoTree THEN
			WriteS (StdOutput, "unknown node type: ");
			WriteL (StdOutput, String);
		     END;
	    | 'a',
	      'A', (* <name>[:<name>] select current attribute instance a	*)
	      'b',
	      'B': (* <name>[:<name>] select current attribute instance b	*)
		     ArrayToString (Name1, String);
		     Ident := MakeIdent (String);
		     Attribute := IdentifyAttribute (Class, Ident);
		     IF Attribute = NoTree THEN
			WriteS (StdOutput, "unknown attribute: ");
			WriteL (StdOutput, String);
		     ELSE
			IF (Com = 'a') OR (Com = 'A') THEN
			   a := Attribute^.Child.AttrIndex;
			ELSE
			   b := Attribute^.Child.AttrIndex;
			END;
			IF Length2 >= 0 THEN
			   ChildsClass := Attribute^.Child.Class;
			   IF ChildsClass # NoTree THEN
			      ArrayToString (Name2, String);
			      Ident := MakeIdent (String);
			      Offset := Class^.Class.AttrCount + Attribute^.Child.InstOffset;
			      Attribute := IdentifyAttribute (ChildsClass, Ident);
			      IF Attribute = NoTree THEN
				 WriteS (StdOutput, "unknown attribute: ");
				 WriteL (StdOutput, String);
			      ELSE
				 IF (Com = 'a') OR (Com = 'A') THEN
				    a := Offset + Attribute^.Child.AttrIndex;
				 ELSE
				    b := Offset + Attribute^.Child.AttrIndex;
				 END;
			      END;
			   END;
			END;
		     END;
	    | 'P': (* print dependency relation DP  for complete node type (rule)	*)
		     WriteDependencies (Class, Class^.Class. DP, MaxSet);
	    | 'p': (* print dependency relation DP  for current attribute instance	*)
		     WriteDependencies (Class, Class^.Class. DP, MaxSet);
	    | 'S': (* print dependency relation SNC for complete node type (rule)	*)
		     WriteDependencies (Class, Class^.Class. SNC, MaxSet);
	    | 's': (* print dependency relation SNC for current attribute instance	*)
		     WriteDependencies (Class, Class^.Class. SNC, MaxSet);
	    | 'N': (* print dependency relation DNC for complete node type (rule)	*)
		     WriteDependencies (Class, Class^.Class. DNC, MaxSet);
	    | 'n': (* print dependency relation DNC for current attribute instance	*)
		     WriteDependencies (Class, Class^.Class. DNC, MaxSet);
	    | 'O': (* print dependency relation OAG for complete node type (rule)	*)
		     WriteDependencies (Class, Class^.Class. OAG, MaxSet);
	    | 'o': (* print dependency relation OAG for current attribute instance	*)
		     WriteDependencies (Class, Class^.Class. OAG, MaxSet);
	    | 'C': (* print dependencies introduced for total order for complete node type *)
		     IF (Class # NoTree) AND (cDNC IN GrammarClass) THEN
			WITH Class^.Class DO
			   MakeRelation (Part, InstCount, InstCount);
			   Assign (Part, OAG);
			   Difference (Part, DNC);
			   WriteDependencies (Class, Part, MaxSet); WriteNl (StdOutput);
			   ReleaseRelation (Part);
			END;
		     END;
	    | 'c': (* print dependencies introduced for total order for cyclic attributes *)
		     IF (Class # NoTree) AND (cDNC IN GrammarClass) THEN
			WITH Class^.Class DO
			   MakeRelation (Part, InstCount, InstCount);
			   MakeSet (Cyclics, InstCount);
			   GetCyclics (OAG, Cyclics);
			   Assign (Part, OAG);
			   Difference (Part, DNC);
			   WriteDependencies (Class, Part, Cyclics);
			   ReleaseRelation (Part);
			   ReleaseSet (Cyclics);
			END;
		     END;
	    | 'D',
	      'd',
	      'G',
	      'g': (* print attribute instances sorted by declaration	*)
		     WriteOrderDecl (Class);
	    | 'E',
	      'e': (* print attribute instances sorted by evaluation order	*)
		     IF cOAG IN GrammarClass THEN WriteOrderEval (Class); END;
	    | 'V',
	      'v': (* print visit sequence	*)
		     IF cOAG IN GrammarClass THEN WriteVisitSequence (Class); END;
	    | 'F',
	      'f': (* find and print dependency path between attributes a and b	*)
		     IF (Class # NoTree) AND
			(1 <= a) AND (a <= Class^.Class.InstCount) AND
			(1 <= b) AND (b <= Class^.Class.InstCount) THEN
			FindPath (a, b, Class);
		     END;
	    | 'M',
	      'm': (* print summary of current node type (rule)	*)
		     WriteClass (Class);
	    | 'Q': (* browse internal data structure of complete attribute grammar	*)
		     QueryTree (t);
	    | 'q': (* browse internal data structure of current node type (rule)	*)
		     QueryTree (Class);
	    | 'h',
	      'H': (* print menue for dialog system	*)
		     Menue;
	    | 'x',
	      'X': (* exit dialog system	*)
		     EXIT;
	    | '?': (* print current state	*)
		     WriteS (StdOutput, "node type: ");
		     IF Class # NoTree THEN
			WITH Class^.Class DO
			   WriteIdent	(StdOutput, Name);
			   WriteS	(StdOutput, ", a: ");
			   IF (1 <= a) AND (a <= Class^.Class.InstCount) THEN
			      WriteName	(Instance^ [a]);
			      WriteS	(StdOutput, " = ");
			      WriteI	(StdOutput, a, 0);
			   ELSE
			      WriteS	(StdOutput, "?");
			   END;
			   WriteS	(StdOutput, ", b: ");
			   IF (1 <= b) AND (b <= Class^.Class.InstCount) THEN
			      WriteName	(Instance^ [b]);
			      WriteS	(StdOutput, " = ");
			      WriteI	(StdOutput, b, 0);
			   ELSE
			      WriteS	(StdOutput, "?");
			   END;
			END;
		     ELSE
			WriteS	(StdOutput, "?, a: ?, b: ?");
		     END;
		     WriteNl (StdOutput);
	    ELSE
		     (* <name>          select current node type (rule)	*)
		     ArrayToString (Name0, String);
		     Ident := MakeIdent (String);
		     Class := IdentifyClass (t^.Ag.Classes, Ident);
		     IF Class = NoTree THEN
			WriteS (StdOutput, "unknown node type: ");
			WriteL (StdOutput, String);
		     END;
	    END;
	 ELSE
	    ArrayToString (Name0, String);
	    Ident := MakeIdent (String);
	    Class := IdentifyClass (t^.Ag.Classes, Ident);
	    IF Class = NoTree THEN
	       WriteS (StdOutput, "unknown node type: ");
	       WriteL (StdOutput, String);
	    END;
	 END;
      END;
   END Dialog;

END Dialog.
