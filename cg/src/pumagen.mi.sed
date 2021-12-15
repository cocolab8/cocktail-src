(* Ich, Doktor Josef Grosch, Informatiker, Nov. 1996 *)

MODULE pumagen;

FROM SYSTEM	IMPORT ADR;
FROM rSystem	IMPORT GetArgCount, GetArgument, rSystem, rExit,
			OpenInput, OpenOutput, rRead, rWrite, rClose;
FROM rMemory	IMPORT MemoryUsed;
FROM IO		IMPORT StdOutput, StdError, WriteOpen, WriteClose, CloseIO,
			WriteI, WriteS, WriteNl, WriteC,
			tFile, ReadOpen, ReadClose, EndOfFile, ReadNl;
FROM Strings	IMPORT tString, AssignEmpty, Assign, Append, Concatenate,
			ReadL, WriteL, ArrayToString, StringToArray;
FROM Idents	IMPORT tIdent, NoIdent, MakeIdent, GetString, WriteIdent;
FROM Sets	IMPORT tSet, MakeSet, ReleaseSet, Include, Exclude, IsEmpty,
			Extract, Complement, Union, IsElement, Size;
FROM Errors	IMPORT StoreMessages, WriteMessages;
FROM Scanner	IMPORT BeginFile, Attribute, CurArg, ArgCount;
FROM Parser	IMPORT Parser;
FROM Tree	IMPORT NoTree, tTree, Trace, Options, TreeRoot, QueryTree, ErrorCount,
			HeapUsed, ModuleName, f, ForallClasses, SourceFile,
			WI, TypeNames, itTree, iNoTree, iMain, iModule,
			iInteger, IdentifyClass, ViewName;
FROM Semantic	IMPORT Semantics, TypeCount;
FROM Order	IMPORT Order;
FROM Dialog	IMPORT Dialog;
FROM Puma0	IMPORT PumaLite, PumaLiteDef;

VAR
   String	: tString;
   Argument	: ARRAY [0..255] OF CHAR;
   j		: SHORTCARD;
   ch		: CHAR;

BEGIN
   SourceFile [0] := 0C;
   ArgCount := GetArgCount () - 1;

   CurArg := 0;
   LOOP
      INC (CurArg);
      IF CurArg > ArgCount THEN EXIT; END;
      GetArgument (CurArg, Argument);
      IF Argument [0] = '-' THEN
	 j := 0;
	 LOOP
	    INC (j);
	    ch := Argument [j];
	    IF ch = 0C THEN
	       EXIT;
	    ELSIF ch = '?' THEN
	       Include (Options, ORD ('h'));
	       Include (Options, ORD ('H'));
	    ELSE
	       Include (Options, ORD (ch));
	    END;
	 END;
      ELSIF Argument [0] = '?' THEN
	 Include (Options, ORD ('h'));
	 Include (Options, ORD ('H'));
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

   IF IsElement (ORD ('h'), Options) THEN
      Exclude (Options, ORD ('h'));
      f := StdOutput;
      !!
      !usage: pumagen [-options] [<files>]!
      !!
      ! Q browse internal data structure!
      ! J start dialog system!
      ! 8 report storage consumption!
      ! h print help information!
   ELSE

   (* Include (Options, ORD ('%')); *)
      ArrayToString	("int", String);
      iInteger := MakeIdent (String);
      IF SourceFile [0] # 0C THEN
	 BeginFile (SourceFile);
	 ArrayToString (SourceFile, String);
	 Attribute.Position.File := MakeIdent (String);
      ELSE
	 Attribute.Position.File := NoIdent;
      END;
      StoreMessages (NOT IsElement (ORD ('@'), Options));
      ErrorCount := Parser ();
      Semantics		(TreeRoot);
      IF ErrorCount > 0 THEN WriteMessages (StdError); CloseIO; rExit (1); END;
   END;

   IF IsElement (ORD ('.'), Options) THEN
      Order		(TreeRoot);
   END;

      WriteMessages	(StdError);
      StoreMessages (NOT IsElement (ORD ('@'), Options));

   IF IsElement (ORD ('Q'), Options) THEN
      QueryTree		(TreeRoot);
   END;

   IF IsElement (ORD ('J') - ORD ('A'), Options) THEN
      Dialog		(TreeRoot);
   END;

      IF ErrorCount > 0 THEN CloseIO; rExit (1); END;

      f := WriteOpen	("Tree3.h");
      PumaLiteDef	(TreeRoot);
      WriteClose	(f);

      f := WriteOpen	("Tree3.c");
      PumaLite		(TreeRoot);
      WriteClose	(f);

   IF IsElement (ORD ('8'), Options) THEN
      WriteNl (StdError);
      WriteS  (StdError, "Memory"); WriteI (StdError, MemoryUsed, 8);
      WriteS  (StdError, "  Heap"); WriteI (StdError, HeapUsed  , 8);
      WriteNl (StdError);
   END;
   WriteMessages (StdError);
   CloseIO; rExit (0);
END pumagen.
