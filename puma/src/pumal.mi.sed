(* $Id: pumal.sed,v 1.1 1999/06/03 08:23:36 grosch rel $ *)

(*
 * $Log: pumal.sed,v $
 * Revision 1.1  1999/06/03 08:23:36  grosch
 * add source window
 *
 * Revision 1.0  1998/05/28 16:32:44  grosch
 * Initial revision
 *
 * Revision 4.7  1996/05/08  15:36:12  grosch
 * introduced option -: for breaking long lines
 *
 * Revision 4.6  1996/05/06  17:52:08  grosch
 * adaption to new style of SUBUNITS in ast
 *
 * Revision 4.5  1996/05/06  17:34:50  grosch
 * added generation of C++
 *
 * Revision 4.4  1995/08/22  08:09:11  grosch
 * added missing initialization of yyHead.yyParent (purify)
 *
 * Revision 4.3  1995/06/12  22:19:29  grosch
 * make option -r generate patterns in named style
 *
 * Revision 4.2  1995/04/23  20:51:43  grosch
 * changed suffix of yyTree.w to .h
 *
 * Revision 4.1  1994/01/30  00:42:15  grosch
 * changed prefix gmd to g
 *
 * Revision 4.0  1993/08/26  16:07:58  grosch
 * replaced table files (Scanner.Tab, Parser.Tab, ...) by initialization code
 *
 * Revision 1.0  1993/08/17  15:48:18  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1996 *)

MODULE pumal;

FROM rSystem	IMPORT GetArgCount, GetArgument, rSystem, rExit;
FROM rMemory	IMPORT MemoryUsed;
FROM IO		IMPORT StdOutput, StdError, WriteOpen, WriteClose, CloseIO,
			WriteI, WriteS, WriteNl, ReadC,
			tFile, ReadOpen, ReadClose, EndOfFile, ReadNl;
FROM Strings	IMPORT tString, AssignEmpty, Assign, Append, Concatenate,
			ReadL, WriteL, ArrayToString, StringToArray;
FROM Idents	IMPORT tIdent, NoIdent, MakeIdent, GetString, WriteIdent;
FROM Sets	IMPORT tSet, MakeSet, ReleaseSet, Include, Exclude, IsEmpty,
			Extract, Complement, Union, IsElement, WriteSet, Select;
FROM Relation	IMPORT tRelation, MakeRelation, ReleaseRelation, Closure,
			IsRelated, WriteRelation;
FROM Position	IMPORT NoPosition;
FROM Errors	IMPORT StoreMessages, WriteMessages;
FROM Scanner	IMPORT BeginFile, ErrorI;
FROM Parser	IMPORT Parser;
FROM Tree	IMPORT NoTree, tTree, TreeRoot, HeapUsed, Options, SourceFile,
			f, WI, mNoClass, TreeName, ErrorCount, Class, Child,
			Attribute, ActionPart, NoClass, Test, Dummy,
			ForallClasses, ForallAttributes, QueryTree, Reverse,
			mNoTreeName;
FROM Semantic	IMPORT Semantics, TypeCount, TypeNames, UserTypes,
			RemoveTreeTypes, AddStructuredTypes, IdentifyClass,
			IdentifyClass2, LookupClass;
FROM Optimize	IMPORT Optimize, RuleProperties;
FROM C		IMPORT DefC, ImplC, MacroC, MacroCpp;
FROM Tree3	IMPORT GetTree;

IMPORT Relation;

CONST
   DefExtC	= ".h"	;	(* file extensions for C		*)
   ImpExtC	= ".c"	;
   DefExtCpp	= ".h"	;	(* file extensions for C++		*)
   ImpExtCpp	= ".cxx";

VAR
   PumaLib	,
   TrafoFile	,
   String	,
   PathS	: tString;
   Argument	,
   PathA	: ARRAY [0..255] OF CHAR;
   TheIndex	,
   StopIndex	,
   i, j, n	: SHORTCARD;
   ch		: CHAR;
   Iterator	,
   StartClass	,
   StopClass	,
   TheClass	,
   TheTree	,
   Node		: tTree;
   StartId	,
   StopId	: tIdent;
   WorkingSet	,
   Done		: tSet;
   Reachable	: tRelation;
   NeedsTraversal: BOOLEAN;

PROCEDURE SmartOpen (FileName: tString): tFile;
   VAR PathS: tString;
   BEGIN
      IF IsElement (ORD ('7'), Options) THEN
	 ArrayToString	("xx", PathS);
	 Concatenate	(PathS, FileName);
	 Append		(PathS, 0C);
	 StringToArray	(PathS, PathA);
      ELSE
	 Append		(FileName, 0C);
	 StringToArray	(FileName, PathA);
      END;
      RETURN WriteOpen	(PathA);
   END SmartOpen;

PROCEDURE SmartClose (FileName: tString; f: tFile);
   VAR PathS: tString;
   BEGIN
      WriteClose	(f);
      IF IsElement (ORD ('7'), Options) THEN
	 Assign		(PathS, PumaLib);
	 ArrayToString	("gupd ", String);
	 Concatenate	(PathS, String);
	 Concatenate	(PathS, FileName);
	 ArrayToString	(" xx", String);
	 Concatenate	(PathS, String);
	 Concatenate	(PathS, FileName);
	 Append		(PathS, 0C);
	 StringToArray	(PathS, PathA);
	 n := rSystem	(PathA);
      END;
   END SmartClose;

PROCEDURE GenerateMacros;
   VAR TypeTabFile	: tFile;
   VAR s		: tString;
   VAR i		: tIdent;
   VAR j		: INTEGER;
   BEGIN
   IF IsElement (ORD ('+'), Options) THEN
      ArrayToString	("TypeTab.cxx", String);(* name of type table for C++ *)
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	("TypeTab.c", String);	(* name of type table for C *)
   END;
      Assign		(PathS, PumaLib);
      Concatenate	(PathS, String);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      TypeTabFile := ReadOpen (PathA);

      ArrayToString	("yy" , PathS);		(* name of macro file *)
      GetString		(TreeRoot^.Spec.TrafoName, String);
      Concatenate	(PathS, String);
      ArrayToString	(".h", String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);

      WHILE NOT EndOfFile (TypeTabFile) DO
	 ReadL (TypeTabFile, s);
	 i := MakeIdent (s);
	 IF (i <= TypeCount) AND IsElement (i, TypeNames) THEN
	    Exclude (TypeNames, i);
	    !# ifndef begin! WI (i); !!
	    ReadL (TypeTabFile, s); WriteL (f, s);
	    !# endif!
	    FOR j := 2 TO 7 DO ReadNl (TypeTabFile); END;
	    !# ifndef equal! WI (i); !!
	    ReadL (TypeTabFile, s); WriteL (f, s);
	    !# endif!
	 ELSE
	    FOR j := 1 TO 8 DO ReadNl (TypeTabFile); END;
	 END;
      END;
      ReadClose (TypeTabFile);
      RemoveTreeTypes (TreeRoot);

      WHILE NOT IsEmpty (TypeNames) DO
	 i := Extract (TypeNames);
	 Include (UserTypes, i);
	 !# ifndef begin! WI (i); !!
	 !# define begin! WI (i); !(a)!
	 !# endif!
	 !# ifndef equal! WI (i); !!
	 !# define equal! WI (i); !(a, b)	\!
	 !  memcmp ((char *) & a, (char *) & b, sizeof (a)) == 0!
	 !# endif!
      END;
      AddStructuredTypes;

   IF IsElement (ORD ('+'), Options) THEN
      MacroCpp (TreeRoot);
   ELSIF IsElement (ORD ('c'), Options) THEN
      MacroC (TreeRoot);
   END;

      SmartClose (PathS, f);
   END GenerateMacros;

VAR IndentLevel: INTEGER;

PROCEDURE WriteClass (t: tTree);
   VAR i: INTEGER;
   BEGIN
      CASE t^.Kind OF
      | Class	: WITH t^.Class DO
	    FOR i := 1 TO IndentLevel DO
	       WriteS	(StdOutput, "   ");
	    END;
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, "	=");
	    WriteClass	(Attributes);
	    IF Extensions^.Kind # NoClass THEN
	       WriteS	(StdOutput, " <");
	       WriteNl	(StdOutput);
	       INC (IndentLevel);
	       WriteClass (Extensions);
	       DEC (IndentLevel);
	       FOR i := 1 TO IndentLevel DO
		  WriteS (StdOutput, "   ");
	       END;
	       WriteS	(StdOutput, ">");
	    END;
	    WriteS	(StdOutput, " .");
	    WriteNl	(StdOutput);
	    WriteClass	(Next);
	 END;
      | Child	: WITH t^.Child DO
	    WriteS	(StdOutput, " ");
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, ": ");
	    WriteIdent	(StdOutput, Type);
	    WriteClass	(Next);
	 END;
      | Attribute	: WITH t^.Attribute DO
	 IF ({Test, Dummy} * Properties) = {} THEN
	    WriteS	(StdOutput, " [");
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, ": ");
	    WriteIdent	(StdOutput, Type);
	    WriteS	(StdOutput, "]");
	 END;
	    WriteClass	(Next);
	 END;
      | ActionPart	: WITH t^.ActionPart DO
	    WriteClass	(Next);
	 END;
      ELSE
      END;
   END WriteClass;

VAR IsFirst: BOOLEAN;

PROCEDURE WritePattern (t: tTree);
   BEGIN
      CASE t^.Kind OF
      | Class	: WITH t^.Class DO
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, " (");
	    IsFirst := TRUE;
	    ForallAttributes (t, WritePattern);
	    WriteS	(StdOutput, ")");
	    WriteNl	(StdOutput);
	 END;
      | Child	: WITH t^.Child DO
	    IF IsFirst THEN
	       IsFirst := FALSE;
	    ELSE
	       WriteS	(StdOutput, ", ");
	    END;
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, " := ");
	    IF Name # Type THEN
	       WriteIdent (StdOutput, Name);
	       WriteS	(StdOutput, ": ");
	    END;
	    WriteIdent	(StdOutput, Type);
	 END;
      | Attribute	: WITH t^.Attribute DO
	 IF ({Test, Dummy} * Properties) = {} THEN
	    IF IsFirst THEN
	       IsFirst := FALSE;
	    ELSE
	       WriteS	(StdOutput, ", ");
	    END;
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, " := ");
	    WriteIdent	(StdOutput, Name);
	 END;
	 END;
      ELSE
      END;
   END WritePattern;

PROCEDURE WriteTraverse (t: tTree);
   BEGIN
      CASE t^.Kind OF
      | Class	: WITH t^.Class DO
	    WriteTraverse (Extensions);
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, " (");
	    IsFirst := TRUE;
	    ForallAttributes (t, WritePattern);
	    WriteS	(StdOutput, ") :-");
	    WriteNl	(StdOutput);
	    Iterator := NoTree;
	    ForallAttributes (t, WriteTraverse);
	    IF Iterator # NoTree THEN
	       WriteS	(StdOutput, "   Traverse (");
	       WriteIdent (StdOutput, Iterator^.Child.Name);
	       WriteS	(StdOutput, ");");
	       WriteNl	(StdOutput);
	    END;
	    WriteS	(StdOutput, "   .");
	    WriteNl	(StdOutput);
	    WriteTraverse (Next);
	 END;
      | Child	: WITH t^.Child DO
	    IF Reverse IN Properties THEN
	       Iterator := t;
	    ELSE
	       WriteS	(StdOutput, "   Traverse (");
	       WriteIdent (StdOutput, Name);
	       WriteS	(StdOutput, ");");
	       WriteNl	(StdOutput);
	    END;
	 END;
      ELSE
      END;
   END WriteTraverse;

PROCEDURE WriteTraverse2 (t: tTree);
   VAR TheClass, Dummy: tTree;
   BEGIN
      CASE t^.Kind OF
      | Class	: WITH t^.Class DO
	    IF IsElement (Index, Done) THEN RETURN; END;
	    Include (Done, Index);
	    WriteTraverse3 (Extensions);
	    WriteIdent	(StdOutput, Name);
	    WriteS	(StdOutput, " (");
	    IsFirst := TRUE;
	    ForallAttributes (t, WritePattern);
	    WriteS	(StdOutput, ") :-");
	    WriteNl	(StdOutput);
	    Iterator := NoTree;
	    ForallAttributes (t, WriteTraverse2);
	    IF Iterator # NoTree THEN
	       WriteS	(StdOutput, "   Traverse (");
	       WriteIdent (StdOutput, Iterator^.Child.Name);
	       WriteS	(StdOutput, ");");
	       WriteNl	(StdOutput);
	    END;
	    WriteS	(StdOutput, "   .");
	    WriteNl	(StdOutput);
	 END;
      | Child	: WITH t^.Child DO
	    IF Reverse IN Properties THEN
	       Iterator := t;
	    ELSE
	       WriteS	(StdOutput, "   Traverse (");
	       WriteIdent (StdOutput, Name);
	       WriteS	(StdOutput, ");");
	       WriteNl	(StdOutput);
	    END;
	    TheClass := IdentifyClass2 (Type, Dummy);
	    IF NOT IsElement (TheClass^.Class.Index, Done) THEN
	       Include (WorkingSet, TheClass^.Class.Index);
	    END;
	 END;
      ELSE
      END;
   END WriteTraverse2;

PROCEDURE WriteTraverse3 (t: tTree);
   BEGIN
      WHILE t^.Kind = Class DO
	 WriteTraverse2 (t);
	 t := t^.Class.Next;
      END;
   END WriteTraverse3;

PROCEDURE WriteTraverse4 (t: tTree);
   VAR TheClass, Dummy: tTree;
   BEGIN
      CASE t^.Kind OF
      | Class	: WITH t^.Class DO
	    IF IsElement (Index, Done) THEN RETURN; END;
	    Include (Done, Index);
	    WriteTraverse5 (Extensions);
	    IF Index = StopIndex THEN
	       NeedsTraversal := TRUE;
	    ELSE
	       NeedsTraversal := FALSE;
	       ForallAttributes (Attributes, CheckTraversal);
	    END;
	    IF NeedsTraversal THEN
	       WriteIdent	(StdOutput, Name);
	       WriteS		(StdOutput, " (");
	       IsFirst := TRUE;
	       ForallAttributes (t, WritePattern);
	       WriteS		(StdOutput, ") :-");
	       WriteNl		(StdOutput);
	       Iterator := NoTree;
	       ForallAttributes (t, WriteTraverse4);
	       IF Iterator # NoTree THEN
		  TheClass := IdentifyClass2 (Iterator^.Child.Type, Dummy);
		  IF IsRelated (TheClass^.Class.Index, StopIndex, Reachable) THEN
		     WriteS	(StdOutput, "   Traverse (");
		     WriteIdent	(StdOutput, Iterator^.Child.Name);
		     WriteS	(StdOutput, ");");
		     WriteNl	(StdOutput);
		  END;
	       END;
	       WriteS		(StdOutput, "   .");
	       WriteNl		(StdOutput);
	    END;
	 END;
      | Child	: WITH t^.Child DO
	    TheClass := IdentifyClass2 (Type, Dummy);
	    IF IsRelated (TheClass^.Class.Index, StopIndex, Reachable) THEN
	       IF Reverse IN Properties THEN
		  Iterator := t;
	       ELSE
		  WriteS	(StdOutput, "   Traverse (");
		  WriteIdent	(StdOutput, Name);
		  WriteS	(StdOutput, ");");
		  WriteNl	(StdOutput);
	       END;
	       IF NOT IsElement (TheClass^.Class.Index, Done) THEN
		  Include (WorkingSet, TheClass^.Class.Index);
	       END;
	    END;
	 END;
      ELSE
      END;
   END WriteTraverse4;

PROCEDURE WriteTraverse5 (t: tTree);
   BEGIN
      WHILE t^.Kind = Class DO
	 WriteTraverse4 (t);
	 t := t^.Class.Next;
      END;
   END WriteTraverse5;

PROCEDURE CheckTraversal (t: tTree);
   VAR TheClass, Dummy: tTree;
   BEGIN
      IF t^.Kind = Child THEN
	 TheClass := IdentifyClass2 (t^.Child.Type, Dummy);
	 IF IsRelated (TheClass^.Class.Index, StopIndex, Reachable) THEN
	    NeedsTraversal := TRUE;
	 END;
      END;
   END CheckTraversal;

PROCEDURE CompReachable (t: tTree);
   VAR TheClass, Dummy: tTree;
   BEGIN
      CASE t^.Kind OF
      | Class	: WITH t^.Class DO
	    TheIndex := Index;
	    Relation.Include (Reachable, TheIndex, Index);
	    ForallClasses (Extensions, CompReachable2);
	    ForallAttributes (t, CompReachable);
	 END;
      | Child	: WITH t^.Child DO
	    TheClass := IdentifyClass2 (Type, Dummy);
	    Relation.Include (Reachable, TheIndex, TheClass^.Class.Index);
	 END;
      ELSE
      END;
   END CompReachable;

PROCEDURE CompReachable2 (t: tTree);
   BEGIN
      Relation.Include (Reachable, TheIndex, t^.Class.Index);
   END CompReachable2;

BEGIN
   IndentLevel := 0;
   AssignEmpty (PumaLib);
   SourceFile [0] := 0C;
   n := GetArgCount () - 1;

   FOR i := 1 TO n DO
      GetArgument (i, Argument);
      IF Argument [0] = '-' THEN
	 IF Argument [1] = 'l' THEN
	    AssignEmpty (PumaLib);
	    j := 2;
	    LOOP
	       ch := Argument [j];
	       IF ch = 0C THEN EXIT; END;
	       Append (PumaLib, ch);
	       INC (j);
	    END;
	    Append (PumaLib, '/');
	    DEC (n);
	 ELSIF (Argument [1] = 'y') AND (i < n) THEN
	    Include (Options, ORD ('y'));
	    INC (i);
	    GetArgument (i, Argument);
	    ArrayToString (Argument, PathS);
	    StartId := MakeIdent (PathS);
	 ELSIF (Argument [1] = 'z') AND (i < n) THEN
	    Include (Options, ORD ('z'));
	    INC (i);
	    GetArgument (i, Argument);
	    ArrayToString (Argument, PathS);
	    StopId := MakeIdent (PathS);
	 ELSE
	    j := 0;
	    LOOP
	       INC (j);
	       ch := Argument [j];
	       IF ch = 0C THEN
		  EXIT;
	       ELSIF ch = '?' THEN
		  Include (Options, ORD ('h'));
	       ELSE
		  Include (Options, ORD (ch));
	       END;
	    END;
	 END;
      ELSIF Argument [0] = '?' THEN
	 Include (Options, ORD ('h'));
      ELSE
	 j := 0;
	 REPEAT
            ch := Argument [j];
	    SourceFile [j] := ch;
	    INC (j);
	 UNTIL ch = 0C;
	 DEC (n);
      END;
   END;

   IF n < 1 THEN				(* {} -> a		*)
      Include (Options, ORD ('a'));
   END;

   IF IsElement (ORD ('a'), Options) THEN	(* a -> {d, i}		*)
      Include (Options, ORD ('d'));
      Include (Options, ORD ('i'));
   END;

      Include (Options, ORD ('c'));

   IF IsElement (ORD ('h'), Options) THEN
      Exclude (Options, ORD ('h'));
      f := StdOutput;
      !!
      !usage: puma-light [-options] [-y <type>] [-z <type>] [-l<directory>] [<file>]!
      !!
      ! a generate all, same as -di (default)!
      ! d generate header file!
      ! i generate implementation part!
      ! s suppress warnings!
      ! m use procedure MakeTREE to construct nodes (default: inline code)!
      ! p allow node constructors without parentheses!
      ! f signal a runtime error if none of the rules of a procedure matches!
      ! k allow non-linear patterns!
      ! n check parameters for NoTREE (NULL, NIL) and treat as failure!
      ! w surround actions by WITH statements!
      ! e treat undefined names as error!
      ! v treat undefined names as warning!
      ! o list undefined names on standard output!
      ! t print tree definitions!
      ! r print patterns!
      ! x generate and print a traversal procedure for all node types (Traverse)!
      ! y <type> generate and print a traversal procedure for all node types!
      !      that are reachable from the node type <type>!
      ! z <type> restrict traversal procedure to reach node types of class <type>, only!
      ! q browse internal data structure!
      ! : generate lines not longer than 80 characters!
      ! 6 generate # line directives!
      ! 7 touch output files only if necessary!
      ! 8 report storage consumption!
      ! c generate C   code (default)!
      ! + generate C++ code!
      ! h print help information!
      ! -l<dir> specify the directory dir where puma finds its tables!
      !!
   END;

   IF IsEmpty (Options) THEN CloseIO; HALT; END;

      StoreMessages (TRUE);
      IF SourceFile [0] # 0C THEN BeginFile (SourceFile); END;
      INC (ErrorCount, Parser ());

      Node := TreeRoot^.Spec.TreeNames;
      IF Node^.Kind = TreeName THEN
	    Node^.TreeName.Next := mNoTreeName ();
	    Node^.TreeName.Classes := GetTree ();
   IF IsElement (ORD ('t'), Options) THEN
	    WriteS (StdOutput, "Tree Definition: "); WriteIdent (StdOutput, Node^.TreeName.Name);
	    WriteNl (StdOutput);
	    WriteS (StdOutput, "----------------"); WriteNl (StdOutput);
	    WriteNl (StdOutput);
	    WriteClass (Node^.TreeName.Classes);
	    WriteNl (StdOutput);
   END;
   IF IsElement (ORD ('r'), Options) THEN
	    WriteS (StdOutput, "Patterns: "); WriteIdent (StdOutput, Node^.TreeName.Name);
	    WriteNl (StdOutput);
	    WriteS (StdOutput, "---------"); WriteNl (StdOutput);
	    WriteNl (StdOutput);
	    ForallClasses (Node^.TreeName.Classes, WritePattern);
	    WriteNl (StdOutput);
   END;
   IF IsElement (ORD ('x'), Options) THEN
	    WriteS (StdOutput, "PROCEDURE Traverse (");
	    WriteIdent (StdOutput, Node^.TreeName.Name);
	    WriteS (StdOutput, ")");
	    WriteNl (StdOutput);
	    WriteNl (StdOutput);
	    WriteTraverse (Node^.TreeName.Classes);
	    WriteNl (StdOutput);
   END;
      END;

      Semantics	(TreeRoot);
   IF IsElement (ORD ('b'), Options) THEN
      RuleProperties	(TreeRoot);
   ELSE
      Optimize		(TreeRoot);
   END;

   IF IsElement (ORD ('y'), Options) THEN
      StartClass := IdentifyClass2 (StartId, TheTree);
      IF StartClass = NoTree THEN
	 ErrorI ("node type not declared", NoPosition, StartId);
      ELSIF NOT IsElement (ORD ('z'), Options) THEN
	 MakeSet (WorkingSet, TheTree^.TreeName.ClassCount);
	 MakeSet (Done, TheTree^.TreeName.ClassCount);
	 WriteS (StdOutput, "PROCEDURE Traverse (");
	 WriteIdent (StdOutput, TheTree^.TreeName.Name);
	 WriteS (StdOutput, ")");
	 WriteNl (StdOutput);
	 WriteNl (StdOutput);
	 Include (WorkingSet, StartClass^.Class.Index);
	 WHILE NOT IsEmpty (WorkingSet) DO
	    TheIndex := Extract (WorkingSet);
	    TheClass := LookupClass (TheTree^.TreeName.Classes, TheIndex);
	    WriteTraverse2 (TheClass);
	 END;
	 WriteNl (StdOutput);
	 ReleaseSet (WorkingSet);
	 ReleaseSet (Done);
      ELSE
	 StopClass := IdentifyClass (TheTree^.TreeName.Classes, StopId);
	 IF StopClass = NoTree THEN
	    ErrorI ("node type not declared", NoPosition, StopId);
	 ELSE
	    StopIndex := StopClass^.Class.Index;
	    MakeRelation (Reachable, TheTree^.TreeName.ClassCount, TheTree^.TreeName.ClassCount);
	    ForallClasses (TheTree^.TreeName.Classes, CompReachable);
	    Closure (Reachable);
	    MakeSet (WorkingSet, TheTree^.TreeName.ClassCount);
	    MakeSet (Done, TheTree^.TreeName.ClassCount);
	    WriteS (StdOutput, "PROCEDURE Traverse (");
	    WriteIdent (StdOutput, TheTree^.TreeName.Name);
	    WriteS (StdOutput, ")");
	    WriteNl (StdOutput);
	    WriteNl (StdOutput);
	    Include (WorkingSet, StartClass^.Class.Index);
	    WHILE NOT IsEmpty (WorkingSet) DO
	       TheIndex := Extract (WorkingSet);
	       TheClass := LookupClass (TheTree^.TreeName.Classes, TheIndex);
	       WriteTraverse4 (TheClass);
	    END;
	    WriteNl (StdOutput);
	    ReleaseSet (WorkingSet);
	    ReleaseSet (Done);
	    ReleaseRelation (Reachable);
	 END;
      END;
   END;

      WriteMessages (StdError);

   IF IsElement (ORD ('q'), Options) THEN
      QueryTree		(TreeRoot);
   END;

      IF ErrorCount > 0 THEN CloseIO; rExit (1); END;
      GenerateMacros;

   IF IsElement (ORD ('d'), Options) THEN
      GetString		(TreeRoot^.Spec.TrafoName, PathS);
   IF IsElement (ORD ('+'), Options) THEN
      ArrayToString	(DefExtCpp, String);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	(DefExtC , String);
   END;
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);
      DefC		(TreeRoot);
      SmartClose	(PathS, f);
   END;

   IF IsElement (ORD ('i'), Options) THEN
      GetString		(TreeRoot^.Spec.TrafoName, PathS);
   IF IsElement (ORD ('+'), Options) THEN
      ArrayToString	(ImpExtCpp, String);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	(ImpExtC , String);
   END;
      Concatenate	(PathS, String);
      Assign		(TrafoFile, PathS);
      f := SmartOpen	(PathS);
      ImplC		(TreeRoot);
      SmartClose	(PathS, f);

   IF NOT IsElement (ORD ('c'), Options) THEN
      Assign		(PathS, PumaLib);
      ArrayToString	("gcpp ", String);		(* call cpp *)
      Concatenate	(PathS, String);
      Concatenate	(PathS, TrafoFile);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      n := rSystem	(PathA);

      Assign		(PathS, PumaLib);
      ArrayToString	("grm yy", String);		(* name of macro file *)
      Concatenate	(PathS, String);
      GetString		(TreeRoot^.Spec.TrafoName, String);
      Concatenate	(PathS, String);
      ArrayToString	(".h", String);
      Concatenate	(PathS, String);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      n := rSystem	(PathA);
   END;
   END;

   IF IsElement (ORD ('8'), Options) THEN
      WriteNl (StdError);
      WriteS  (StdError, "Memory"); WriteI (StdError, MemoryUsed, 8);
      WriteS  (StdError, "  Heap"); WriteI (StdError, HeapUsed  , 8);
      WriteNl (StdError);
   END;
   CloseIO; rExit (0);
END pumal.
