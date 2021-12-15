(* Ich, Doktor Josef Grosch, Informatiker, 28.10.1993 *)

MODULE lpp;

FROM SYSTEM	IMPORT ADR;
FROM rSystem	IMPORT GetArgCount, GetArgument, rSystem, rExit,
			DirectorySeparator;
FROM rMemory	IMPORT MemoryUsed;
FROM IO		IMPORT StdOutput, StdError, WriteOpen, WriteClose, CloseIO,
			WriteI, WriteS, WriteNl,
			tFile, ReadOpen, ReadClose, EndOfFile, ReadNl;
FROM Strings	IMPORT tString, AssignEmpty, Assign, Append, Concatenate,
			ReadL, WriteL, ArrayToString, StringToArray;
FROM Idents	IMPORT tIdent, NoIdent, MakeIdent, GetString, WriteIdent;
FROM Sets	IMPORT tSet, MakeSet, ReleaseSet, Include, Exclude, IsEmpty,
			Extract, Complement, Union, IsElement;
FROM Position	IMPORT NoPosition;
FROM Errors	IMPORT StoreMessages, WriteMessages, MessageI, Fatal, Array;
FROM Scanner	IMPORT BeginFile, Attribute, CurArg, ArgCount;
FROM Parser	IMPORT Parser;
FROM Tree	IMPORT NoTree, tTree, Trace, Options, TreeRoot, QueryTree, ErrorCount,
			HeapUsed, ModuleName, f, fPosition, ForallClasses, SourceFile,
			WI, TypeNames, itTree, iNoTree, iModule, iInteger, IdentifyClass,
			ViewName, GetFileName, CurrentPos (* , DrawTree *) ;
FROM Semantic	IMPORT Semantics, TypeCount;
FROM Order	IMPORT Order;
FROM Dialog	IMPORT Dialog;

IMPORT GramMod;
IMPORT GramC, GramYacc;
IMPORT GramAda;
IMPORT GramJava;

VAR
   CgLib	,
   String	,
   PathS	: tString;
   Argument	,
   PathA	: ARRAY [0..255] OF CHAR;
   j		: SHORTCARD;
   ch		: CHAR;
   HasArgs	: BOOLEAN;

PROCEDURE SmartOpen (FileName: tString): tFile;
   VAR PathS: tString; n: INTEGER;
   BEGIN
      IF IsElement (ORD ('7'), Options) THEN
	 ArrayToString	("yy", PathS);
	 Concatenate	(PathS, FileName);
	 Append		(PathS, 0C);
	 StringToArray	(PathS, PathA);
      ELSE
	 Append		(FileName, 0C);
	 StringToArray	(FileName, PathA);
      END;
      n := WriteOpen	(PathA);
      IF n < 0 THEN
	 INC (ErrorCount);
	 MessageI ("can not open file", Fatal, NoPosition, Array, ADR (PathA));
      END;
      RETURN n;
   END SmartOpen;

PROCEDURE SmartClose (FileName: tString; f: tFile);
   VAR PathS: tString;
   BEGIN
      WriteClose	(f);
      IF IsElement (ORD ('7'), Options) THEN
	 ArrayToString	("gupd ", PathS);
	 Concatenate	(PathS, FileName);
	 ArrayToString	(" yy", String);
	 Concatenate	(PathS, String);
	 Concatenate	(PathS, FileName);
	 Append		(PathS, 0C);
	 StringToArray	(PathS, PathA);
	 j := rSystem	(PathA);
      END;
   END SmartClose;

BEGIN
   AssignEmpty (CgLib);
   SourceFile [0] := 0C;
   ArgCount := GetArgCount () - 1;
   HasArgs := FALSE;

   CurArg := 0;
   LOOP
      INC (CurArg);
      IF CurArg > ArgCount THEN EXIT; END;
      GetArgument (CurArg, Argument);
      IF Argument [0] = '-' THEN 
	 IF Argument [1] = 'l' THEN 
	    AssignEmpty (CgLib);
	    j := 2;
	    LOOP
	       ch := Argument [j];
	       IF ch = 0C THEN EXIT; END;
	       Append (CgLib, ch);
	       INC (j);
	    END;
	    Append (CgLib, DirectorySeparator ());
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
	    HasArgs := TRUE;
	 END;
      ELSIF Argument [0] = '+' THEN
	 j := 0;
	 LOOP
	    INC (j);
	    ch := Argument [j];
	    IF ch = 0C THEN
	       EXIT;
	    ELSE
	       Include (Options, ORD (ch) - ORD ('A'));
	    END;
	 END;
	 HasArgs := TRUE;
      ELSIF Argument [0] = '?' THEN 
	 Include (Options, ORD ('h'));
	 HasArgs := TRUE;
      ELSE
	 j := 0;
	 REPEAT
            ch := Argument [j];
	    SourceFile [j] := ch;
	    INC (j);
	 UNTIL ch = 0C;
	 EXIT;
      END;
   END;

   IF NOT HasArgs THEN				(* {} -> {x, z}		*)
      Include (Options, ORD ('x'));
      Include (Options, ORD ('z'));
   END;

   IF IsElement (ORD ('+'), Options) THEN	(* {+} -> c		*)
      Include (Options, ORD ('c'));
   END;

   IF IsElement (ORD ('x'), Options) OR		(* {x, z, u} -> . = Order, B *)
      IsElement (ORD ('z'), Options) OR
      IsElement (ORD ('u'), Options) THEN
      Include (Options, ORD ('.'));
      Include (Options, ORD ('B'));
   END;

   IF IsElement (ORD ('I') - ORD ('A'), Options) THEN
      Include (Options, ORD ('v'));		(* +I -> v		*)
   END;

   IF IsElement (ORD ('h'), Options) THEN
      Exclude (Options, ORD ('h'));
      f := StdOutput;
      !!
      !usage: lpp [-options] [files]!
      !!
      ! x generate scanner specification!
      ! z generate parser  specification for lark!
      ! u generate parser  specification for yacc!
      ! v omit actions in the generated parser specifications!
      ! j allow undefined node types; define implicitly as terminals!
      ! c generate C   code (default: Modula-2)!
      ! + generate C++ code!
      ! - generate Ada code!
      ! h print help information!
      ! H print more options!
      ! W suppress warnings!
      ! B allow missing attribute computations in extended node types!
      ! 1 print inserted copy rules!
      ! 2 print inherited attribute computation rules!
   (* ! 6 generate # line directives! *)
      ! 7 touch output files only if necessary!
      ! 8 report storage consumption!
      ! +I allow incomplete attribute computation rules!
   (* ! @ print messages (do not store)! *)
   END;

   IF IsElement (ORD ('H'), Options) THEN
      Exclude (Options, ORD ('H'));
      f := StdOutput;
      !!
      !usage: lpp [-options] [-ldir] [files]!
      !!
      !options for evaluator module!
      !!
      ! V print visit sequences!
      ! M print summary of all node types (rules) from source!
      ! P print dependency relations DP!
      ! S print dependency relations SNC!
      ! N print dependency relations DNC!
      ! O print dependency relations OAG!
      ! G print attribute instances sorted by declaration order!
      ! E print attribute instances sorted by evaluation order!
      ! C print dependencies introduced for total order!
      ! J start dialog system!
      ! Q browse internal data structure with text browser!
      !+G browse internal data structure with graphical browser!
   END;

   IF NOT IsEmpty (Options) THEN

   IF IsElement (ORD ('c'), Options) OR IsElement (ORD ('J'), Options) THEN
      ArrayToString	("int", String);
   ELSE
      ArrayToString	("INTEGER", String);
   END;
      iInteger := MakeIdent (String);

      Attribute.Position := NoPosition;
      IF SourceFile [0] # 0C THEN
	 BeginFile (SourceFile);
	 ArrayToString (SourceFile, String);
      ELSE
	 ArrayToString ("-", String);
      END;
      Attribute.Position.File := MakeIdent (String);
      StoreMessages (NOT IsElement (ORD ('@'), Options));
      INC (ErrorCount, Parser ());
      Semantics		(TreeRoot);

      IF ErrorCount > 0 THEN
	 WriteMessages	(StdError);
(*
      IF IsElement (ORD ('G') - ORD ('A'), Options) THEN
	 DrawTree	(TreeRoot);
      END;
*)
	 CloseIO; rExit (1);
      END;
   END;

   IF IsElement (ORD ('x'), Options) THEN
      IF TreeRoot^.Ag.ScannerName = NoIdent THEN
	 ArrayToString	("Scanner", PathS);
      ELSE
	 GetFileName (TreeRoot^.Ag.ScannerName, PathS);
      END;
      ArrayToString	(".rpp", String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);
      fPosition.File := MakeIdent (PathS); 
      fPosition.Line := 1;
      CurrentPos := NoPosition;
   IF IsElement (ORD ('c'), Options) THEN
      GramC.ScanSpec	(TreeRoot);
   ELSIF IsElement (ORD ('-'), Options) THEN
      GramAda.ScanSpec	(TreeRoot);
   ELSIF IsElement (ORD ('J'), Options) THEN
      GramJava.ScanSpec	(TreeRoot);
   ELSE
      GramMod.ScanSpec	(TreeRoot);
   END;
      SmartClose	(PathS, f);
   END;

   IF IsElement (ORD ('z'), Options) THEN
      GetFileName	(TreeRoot^.Ag.ParserName, ModuleName);
      Assign		(PathS, ModuleName);
      ArrayToString	(".lrk", String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);
      fPosition.File := MakeIdent (PathS); 
      fPosition.Line := 1;
      CurrentPos := NoPosition;
   IF IsElement (ORD ('c'), Options) THEN
      GramC.ParsSpec	(TreeRoot);
   ELSIF IsElement (ORD ('-'), Options) THEN
      GramAda.ParsSpec	(TreeRoot);
   ELSIF IsElement (ORD ('J'), Options) THEN
      GramJava.ParsSpec	(TreeRoot);
   ELSE
      GramMod.ParsSpec	(TreeRoot);
   END;
      SmartClose	(PathS, f);
   ELSIF IsElement (ORD ('u'), Options) THEN
      GetFileName	(TreeRoot^.Ag.ParserName, ModuleName);
      Assign		(PathS, ModuleName);
      ArrayToString	(".y", String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);
      fPosition.File := MakeIdent (PathS); 
      fPosition.Line := 1;
      CurrentPos := NoPosition;
      GramYacc.ParsSpec	(TreeRoot);
      SmartClose	(PathS, f);
   END;

   IF IsElement (ORD ('.'), Options) THEN
      Order		(TreeRoot);
   END;

      WriteMessages	(StdError);

   IF IsElement (ORD ('Q'), Options) THEN
      QueryTree		(TreeRoot);
   END;

(*
   IF IsElement (ORD ('G') - ORD ('A'), Options) THEN
      DrawTree		(TreeRoot);
   END;
*)

   IF IsElement (ORD ('J') - ORD ('A'), Options) THEN
      Dialog		(TreeRoot);
   END;

   IF IsElement (ORD ('8'), Options) THEN
      WriteNl (StdError);
      WriteS  (StdError, "Memory"); WriteI (StdError, MemoryUsed, 8);
      WriteS  (StdError, "  Heap"); WriteI (StdError, HeapUsed  , 8);
      WriteNl (StdError);
   END;
   CloseIO; rExit (0);
END lpp.
