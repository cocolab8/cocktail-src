(* Ich, Doktor Josef Grosch, Informatiker, 8.1.1988 *)

MODULE cg;

FROM SYSTEM	IMPORT ADR;
FROM rSystem	IMPORT GetArgCount, GetArgument, GetEnvVar, rSystem, rExit,
			DirectorySeparator, rtpqx, rtpqy, tArrayChar;
FROM rMemory	IMPORT MemoryUsed;
FROM Position	IMPORT NoPosition;
FROM IO		IMPORT StdOutput, StdError, WriteOpen, WriteClose, CloseIO,
			WriteI, WriteS, WriteNl, WriteC, ReadC,
			tFile, ReadOpen, ReadClose, EndOfFile, ReadNl;
FROM Strings	IMPORT tString, AssignEmpty, Assign, Append, Concatenate,
			ReadL, WriteL, ArrayToString, StringToArray, IsInOrder,
			Length;
FROM Idents	IMPORT tIdent, NoIdent, MakeIdent, GetString, WriteIdent;
FROM Sets	IMPORT tSet, MakeSet, ReleaseSet, Include, Exclude, IsEmpty,
			Extract, Complement, Union, IsElement, Size;
FROM Errors	IMPORT StoreMessages, WriteMessages, Message, MessageI, Fatal,
			Error, Restriction, Array;
FROM Scanner	IMPORT BeginFile, Attribute, CurArg, ArgCount;
FROM Parser	IMPORT Parser;
FROM Tree	IMPORT NoTree, tTree, Trace, Options, TreeRoot, QueryTree,
			ErrorCount, HeapUsed, ModuleName, f, ForallClasses,
			SourceFile, WI, TypeNames, CppTypeNames, TreeTypeNames,
			itTree, iNoTree, iMain, iModule, iPackage, SubUnit,
			iInteger, IdentifyClass, CgLib, ViewName, ClassCount,
			GetFileName, fPosition, CurrentPos, (* DrawTree, *) Prefix,
			EmptyBodies;
FROM Tree2	IMPORT PutTree;
FROM Semantic	IMPORT Semantics, TypeCount;
FROM Order	IMPORT Order;
FROM Dialog	IMPORT Dialog;
(*
FROM tsl	IMPORT tsl;
*)

IMPORT Sets;
IMPORT GramMod, TreeMod1, EvalMod, EvalMod2, EvalMod3, EvalMod4;
IMPORT GramC, GramYacc, TreeC1, TreeC2, EvalC, EvalC2, EvalC3, EvalC4;
IMPORT GramAda (* , TreeAda1, EvalAda, EvalAda2, EvalAda3, EvalAda4 *) ;
IMPORT GramJava, TreeJav1, TreeJav2, EvalJava, EvalJav2, EvalJav3, EvalJav4;
IMPORT TreeCxx1, TreeCxx2, EvalCxx, EvalCxx2, EvalCxx3, EvalCxx4;

CONST
   Version	= 0208	;

   DefExtMc	= ".md"	;	(* file extensions for Modula (mc)	*)
   ImpExtMc	= ".mi"	;
   LisExtMc	= ".imp";

   DefExtC	= ".h"	;	(* file extensions for C		*)
   ImpExtC	= ".c"	;
   ImpExtCpp	= ".cxx";	(* file extension  for C++		*)

   ImpExtJava	= ".java";	(* file extension  for Java		*)

VAR
   DefFile	,
   TreeFile	,
   EvalFile	,
   String	,
   PathS	: tString;
   Argument	,
   PathA	: ARRAY [0..255] OF CHAR;
   Buffer	: ARRAY [0..1023] OF CHAR;
   i, j		: SHORTCARD;
   ch		: CHAR;
   AllOptions	: tSet;
   HasArgs	: BOOLEAN;
   EnvVarPtr	: tArrayChar;

PROCEDURE GenerateMacros;
   VAR TypeTabFile	: tFile;
   VAR s		: tString;
   VAR i		: tIdent;
   VAR j		: INTEGER;
   VAR lTypeNames	: tSet;
   BEGIN
      MakeSet (lTypeNames, Size (CppTypeNames));
      Sets.Assign (lTypeNames, CppTypeNames);
   IF IsElement (ORD ('*'), Options) THEN
      ArrayToString	("TypeTab.cxx", String);(* name of type table for C++ *)
   ELSIF IsElement (ORD ('+'), Options) THEN
      ArrayToString	("TypeTab.cx", String);	(* name of type table for C+ *)
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	("TypeTab.c", String);	(* name of type table for C *)
   ELSIF IsElement (ORD ('J'), Options) THEN
      ArrayToString	("TypeTab.j", String);	(* name of type table for Java *)
   ELSE
      ArrayToString	("TypeTab.m", String);	(* name of type table for Modula *)
   END;
      Assign		(PathS, CgLib);
      Concatenate	(PathS, String);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      TypeTabFile := ReadOpen (PathA);
      IF TypeTabFile < 0 THEN
	 MessageI ("can not access file", Error, NoPosition, Array, ADR (PathA));
	 INC (ErrorCount);
         RETURN;
      END;

      ArrayToString	("yy", PathS);		(* name of macro file *)
      GetString		(iModule, ModuleName);
      Concatenate	(PathS, ModuleName);
      ArrayToString	(".h", String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);

      (* copy macros from file TypeTab.xxx *)

      WHILE NOT EndOfFile (TypeTabFile) DO
	 ReadL (TypeTabFile, s);
	 i := MakeIdent (s);
	 IF (i <= TypeCount) AND IsElement (i, lTypeNames) THEN
	    Exclude (lTypeNames, i);
	    !# ifndef begin! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef close! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef read! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef write! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef get! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef put! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef copy! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef equal! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	    !# ifndef writeXML! WI (i); !!
	    ReadL (TypeTabFile, s);
	    WriteL (f, s);
	    !# endif!
	 ELSE
	    FOR j := 1 TO 9 DO
	       ReadNl (TypeTabFile);
	    END;
	 END;
      END;
      ReadClose (TypeTabFile);

      (* generate default macros for unknown types *)

      IF itTree <= TypeCount THEN Exclude (lTypeNames, itTree); END;
      WHILE NOT IsEmpty (lTypeNames) DO
	 i := Extract (lTypeNames);
   IF IsElement (ORD ('c'), Options) THEN
	 !# ifndef begin! WI (i); !!
	 !# define begin! WI (i); !(a)!
	 !# endif!
	 !# ifndef close! WI (i); !!
	 !# define close! WI (i); !(a)!
	 !# endif!
	 !# ifndef read! WI (i); !!
	 !# define read! WI (i); !(a)	\!
	 !  yyReadHex ((unsigned char *) & a, sizeof (a));!
	 !# endif!
	 !# ifndef write! WI (i); !!
	 !# define write! WI (i); !(a)	\!
	 !  yyWriteHex ((unsigned char *) & a, sizeof (a));!
	 !# endif!
	 !# ifndef get! WI (i); !!
	 !# define get! WI (i); !(a)	yyGet ((char *) & a, sizeof (a));!
	 !# endif!
	 !# ifndef put! WI (i); !!
	 !# define put! WI (i); !(a)	yyPut ((char *) & a, sizeof (a));!
	 !# endif!
	 !# ifndef copy! WI (i); !!
	 !# define copy! WI (i); !(a, b)!
	 !# endif!
	 !# ifndef equal! WI (i); !!
	 !# define equal! WI (i); !(a, b)	\!
	 !  memcmp ((char *) & a, (char *) & b, sizeof (a)) == 0!
	 !# endif!
	 !# ifndef writeXML! WI (i); !!
	 !# define writeXML! WI (i); !(a)	\!
	 !  yyWriteHex ((unsigned char *) & a, sizeof (a));!
	 !# endif!
   ELSIF IsElement (ORD ('J'), Options) THEN
	 !# ifndef begin! WI (i); !!
	 !# define begin! WI (i); !(a)!
	 !# endif!
	 !# ifndef close! WI (i); !!
	 !# define close! WI (i); !(a)!
	 !# endif!
	 !# ifndef read! WI (i); !!
	 !# define read! WI (i); !(a)	a = new ! WI (i); ! (yyin.readL ().toString ());!
	 !# endif!
	 !# ifndef write! WI (i); !!
	 !# define write! WI (i); @(a)	yyout.write (a == null ? "null" : a.toString ());@
	 !# endif!
	 (* get and put are not used in Java, we use Serialization instead *)
	 !# ifndef get! WI (i); !!
	 !# define get! WI (i); !(a)	**not used**!
	 !# endif!
	 !# ifndef put! WI (i); !!
	 !# define put! WI (i); !(a)	**not used**!
	 !# endif!
	 !# ifndef copy! WI (i); !!
	 !# define copy! WI (i); !(a, b)	a = (b);!
	 !# endif!
	 !# ifndef equal! WI (i); !!
	 !# define equal! WI (i); !(a, b)	(a.equals (b))!
	 !# endif!
	 !# ifndef writeXML! WI (i); !!
	 !# define writeXML! WI (i); !(a)	**not used**!
	 !# endif!
   ELSE
	 !# ifndef begin! WI (i); !!
	 !# define begin! WI (i); !(a)!
	 !# endif!
	 !# ifndef close! WI (i); !!
	 !# define close! WI (i); !(a)!
	 !# endif!
	 !# ifndef read! WI (i); !!
	 !# define read! WI (i); !(a)	yyReadHex (a);!
	 !# endif!
	 !# ifndef write! WI (i); !!
	 !# define write! WI (i); !(a)	yyWriteHex (a);!
	 !# endif!
	 !# ifndef get! WI (i); !!
	 !# define get! WI (i); !(a)	yyGet (a);!
	 !# endif!
	 !# ifndef put! WI (i); !!
	 !# define put! WI (i); !(a)	yyPut (a);!
	 !# endif!
	 !# ifndef copy! WI (i); !!
	 !# define copy! WI (i); !(a, b)!
	 !# endif!
	 !# ifndef equal! WI (i); !!
	 !# define equal! WI (i); !(a, b)	yyIsEqual (a, b)!
	 !# endif!
	 !# ifndef writeXML! WI (i); !!
	 !# define writeXML! WI (i); !(a)	yyWriteHex (a);!
	 !# endif!
   END;
      END;

      (* generate macros for the type TREE *)

      MakeSet (lTypeNames, Size (TreeTypeNames));
      Sets.Assign (lTypeNames, TreeTypeNames);

      (* For languages except those that have strongly typed Tree types *)
      IF NOT IsElement (ORD ('J'), Options)
      (* AND NOT IsElement (ORD ('*'), Options) *) 
      THEN
         Include (lTypeNames, itTree);
      END;

      WHILE NOT IsEmpty (lTypeNames) DO
	 i := Extract (lTypeNames);
   IF IsElement (ORD ('c'), Options) THEN
      !# ifndef begin! WI (i); !!
      !# define begin! WI (i); !(a)	a = ! WI (iNoTree); !;!
      !# endif!
      !# ifndef close! WI (i); !!
      !# define close! WI (i); !(a)!
      !# endif!
      !# ifndef read! WI (i); !!
      !# define read! WI (i); @(a)	fscanf (yyf, "%p +", (void * *) & a);@
      !# endif!
      !# ifndef write! WI (i); !!
      !# define write! WI (i); @(a)	fprintf (yyf, "%p +", (void *) a);@
      !# endif!
      !# ifndef get! WI (i); !!
      !# define get! WI (i); !(a)	yyGet ((char *) & a, sizeof (a));!
      !# endif!
      !# ifndef put! WI (i); !!
      !# define put! WI (i); !(a)	yyPut ((char *) & a, sizeof (a));!
      !# endif!
      !# ifndef copy! WI (i); !!
      !# define copy! WI (i); !(a, b)	a = b;!
      !# endif!
      !# ifndef equal! WI (i); !!
      !# define equal! WI (i); !(a, b)	a == b!
      !# endif!
      !# ifndef writeXML! WI (i); !!
      !# define writeXML! WI (i); !(a)	yyWriteAddrXML ((void *) a);!
      !# endif!
   ELSIF IsElement (ORD ('J'), Options) THEN
      !# ifndef begin! WI (i); !!
      !# define begin! WI (i); !(a)	a = null;!
      !# endif!
      !# ifndef close! WI (i); !!
      !# define close! WI (i); !(a)	a = null;!
      !# endif!
      !# ifndef read! WI (i); !!
      !# define read! WI (i); !(a)	a = (! WI (i); !) this.read (yyin);!
      !# endif!
      !# ifndef write! WI (i); !!
      !# define write! WI (i); !(a)	! WI (iModule); !.write (yyout, a);!
      !# endif!
      !# ifndef get! WI (i); !!
      !# define get! WI (i); !(a)	**not used**!
      !# endif!
      !# ifndef put! WI (i); !!
      !# define put! WI (i); !(a)	**not used**!
      !# endif!
      !# ifndef copy! WI (i); !!
      !# define copy! WI (i); !(a, b)	a = b;!
      !# endif!
      !# ifndef equal! WI (i); !!
      !# define equal! WI (i); !(a, b)	a == b!
      !# endif!
      !# ifndef writeXML! WI (i); !!
      !# define writeXML! WI (i); !(a)	**not used**!
      !# endif!
   ELSE
      !# ifndef begin! WI (i); !!
      !# define begin! WI (i); !(a)	a := ! WI (iNoTree); !;!
      !# endif!
      !# ifndef close! WI (i); !!
      !# define close! WI (i); !(a)!
      !# endif!
      !# ifndef read! WI (i); !!
      !# define read! WI (i); !(a)	a := SYSTEM.ADDRESS (IO.ReadN (yyf, 16)); yyc := IO.ReadC (yyf); yyc := IO.ReadC (yyf);!
      !# endif!
      !# ifndef write! WI (i); !!
      !# define write! WI (i); @(a)	IO.WriteN (yyf, LONGCARD (a), 8, 16); IO.WriteS (yyf, " +");@
      !# endif!
      !# ifndef get! WI (i); !!
      !# define get! WI (i); !(a)	yyGet (a);!
      !# endif!
      !# ifndef put! WI (i); !!
      !# define put! WI (i); !(a)	yyPut (a);!
      !# endif!
      !# ifndef copy! WI (i); !!
      !# define copy! WI (i); !(a, b)	a := b;!
      !# endif!
      !# ifndef equal! WI (i); !!
      !# define equal! WI (i); !(a, b)	a = b!
      !# endif!
      !# ifndef writeXML! WI (i); !!
      !# define writeXML! WI (i); @(a)	IO.WriteN (yyf, LONGCARD (a), 8, 16);@
      !# endif!
   END;
      END;

   IF IsElement (ORD ('c'), Options) THEN
      !# ifndef readSELECTOR!
      !# define readSELECTOR()	yySkip ();!
      !# endif!
      !# ifndef writeSELECTOR!
      !# define writeSELECTOR(a)	yyIndentSelector (a);!
      !# endif!
   ELSIF IsElement (ORD ('J'), Options) THEN
      !# ifndef readSELECTOR!
      !# define readSELECTOR()          yyin.skipToChar ('='); yyin.read ();!
      !# endif!
      !# ifndef writeSELECTOR!
      !# define writeSELECTOR(a)	yyIndentSelector (a);!
      !# endif!
   ELSE
      !# ifndef readSELECTOR!
      !# define readSELECTOR()	yySkip;!
      !# endif!
      !# ifndef writeSELECTOR!
      !# define writeSELECTOR(a)	yyIndentSelector (a);!
      !# endif!
   END;

      SmartClose (PathS, f);
      ReleaseSet (lTypeNames);
   END GenerateMacros;

PROCEDURE ReadTraceTab;
   VAR TraceTabFile	: tFile;
   VAR s		: tString;
   VAR t		: tTree;
   BEGIN
      TraceTabFile := ReadOpen ("TraceTab");	(* name of trace table *)
      IF TraceTabFile >= 0 THEN
	 WHILE NOT EndOfFile (TraceTabFile) DO
	    ReadL (TraceTabFile, s);
	    t := IdentifyClass (TreeRoot^.Ag.Classes, MakeIdent (s));
	    IF t # NoTree THEN
	       SetTrace (t);
	       ForallClasses (t^.Class.Extensions, SetTrace);
	    END;
	 END;
	 ReadClose (TraceTabFile);
      END;
   END ReadTraceTab;

PROCEDURE SetTrace (t: tTree);
   BEGIN INCL (t^.Class.Properties, Trace); END SetTrace;

PROCEDURE SmartOpen (FileName: tString): tFile;
   VAR PathS: tString; n: INTEGER;
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
	 ArrayToString	(" xx", String);
	 Concatenate	(PathS, String);
	 Concatenate	(PathS, FileName);
	 Append		(PathS, 0C);
	 StringToArray	(PathS, PathA);
	 j := rSystem	(PathA);
      END;
   END SmartClose;

PROCEDURE ToBin (ch: CHAR): INTEGER;
   BEGIN
      CASE ch OF
      | '0' .. '9': RETURN ORD (ch) - ORD ('0');
      | 'A' .. 'F': RETURN ORD (ch) - ORD ('A') + 10;
      | 'a' .. 'f': RETURN ORD (ch) - ORD ('a') + 10;
      END;
      RETURN 0;
   END ToBin;

PROCEDURE WriteMessage (n: INTEGER);
   BEGIN
      INC (ErrorCount);
      CASE n OF
      | 1: Message ("cannot open license file: ctlicens.dat", Fatal,
			TreeRoot^.Ag.Classes^.Class.Pos);
      | 2: Message ("sorry, the license is expired", Fatal,
			TreeRoot^.Ag.Classes^.Class.Pos);
      | 3: Message ("sorry, the problem is too big for demo version", Restriction,
			TreeRoot^.Ag.Classes^.Class.Pos);
      | 4: Message ("license file ctlicens.dat seems corrupted", Fatal,
			TreeRoot^.Ag.Classes^.Class.Pos);
      END;
   END WriteMessage;

PROCEDURE CheckLicense (tool: ARRAY OF CHAR; Limit: CARDINAL): BOOLEAN;
   VAR
      PathS, String	: tString;
      PathA		: ARRAY [0..128] OF CHAR;
      In		: tFile;
      b			: ARRAY [0..10] OF CHAR;
      p			: tArrayChar;
      y			: ARRAY [0..32] OF BITSET;
      z			: ARRAY [0..32] OF CHAR;
      ch		: CHAR;
      i, k		: CARDINAL;
      s, t		: BITSET;
   BEGIN
      IF rtpqy () THEN RETURN TRUE; END;		(* check WIBU-KEY *)
      Assign		(PathS, CgLib);
      Append		(PathS, '.');
      Append		(PathS, '.');
      Append		(PathS, DirectorySeparator ());
      ArrayToString	("ctlicens.dat", String);
      Concatenate	(PathS, String);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      In := ReadOpen	(PathA);
      IF In < 0 THEN WriteMessage (1); RETURN FALSE; END;

      LOOP
	 IF EndOfFile (In) THEN WriteMessage (4); RETURN FALSE; END;
	 i := 0;
	 ch := ReadC (In);
	 WHILE (ch # 12C) AND (ch # 15C) DO
	    y [i] := BITSET (ToBin (ch) * 16 + ToBin (ReadC (In)));
	    INC (i); ch := ReadC (In);
	 END;
	 IF ch = 15C THEN ch := ReadC (In); END;
	 IF ch # 12C THEN WriteMessage (4); RETURN FALSE; END;
	 k := i - 1;

	 s := BITSET (ORD ('j'));
	 FOR i := 0 TO k DO
	    t := y [i] / s; s := s / t; z [i] := CHR (CARDINAL (t));
	 END;
	 IF (z [0] = tool [0]) AND (z [1] = tool [1]) AND (z [2] = tool [2]) THEN EXIT; END;
      END;
      ReadClose (In);

      AssignEmpty (String);
      FOR i := 5 TO 12 DO Append (String, z [i]); END;	(* get license date *)
      b := "%Y%m%d";
      p := rtpqx (b);					(* get current date *)
      i := 0;
      LOOP
	 b [i] := p^ [i];
	 IF (b [i] = 0C) OR (i = 10) THEN EXIT; END;
	 INC (i);
      END;
      ArrayToString (b, PathS);
      IF NOT IsInOrder (PathS, String) THEN WriteMessage (2); RETURN FALSE; END;

      k := 0;
      FOR i := 14 TO 19 DO				(* get license size *)
         IF z [i] # ' ' THEN k := k * 10 + ORD (z [i]) - ORD ('0'); END;
      END;
      IF Limit > k THEN WriteMessage (3); RETURN FALSE; END;
      RETURN TRUE;
   END CheckLicense;

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
		  Include (Options, ORD ('H'));
	       ELSE
		  IF (ch = '+') AND IsElement (ORD ('+'), Options) AND
		     IsElement (ORD ('c'), Options) THEN
		     Include (Options, ORD ('*'));
		     Exclude (Options, ORD ('+'));
		  ELSE
		     Include (Options, ORD (ch));
		  END;
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
	 Include (Options, ORD ('H'));
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

   IF NOT HasArgs THEN				(* {} -> {a, A}		*)
      Include (Options, ORD ('a'));
      Include (Options, ORD ('A'));
   END;

   IF IsElement (ORD ('a'), Options) THEN	(* a -> {a-z, F, R, =, _} - {c, e, h, u, x, z} *)
      MakeSet (AllOptions, 127);
      FOR ch := 'a' TO 'z' DO
	 Include (AllOptions, ORD (ch));
      END;
      Include (AllOptions, ORD ('F'));
      Include (AllOptions, ORD ('R'));
      Include (AllOptions, ORD ('='));
      Include (AllOptions, ORD ('_'));
      Exclude (AllOptions, ORD ('c'));
      Exclude (AllOptions, ORD ('e'));
      Exclude (AllOptions, ORD ('h'));
      Exclude (AllOptions, ORD ('u'));
      Exclude (AllOptions, ORD ('x'));
      Exclude (AllOptions, ORD ('z'));
      Union (Options, AllOptions);
      ReleaseSet (AllOptions);
   END;

   IF IsElement (ORD ('+'), Options) THEN	(* {+} -> {c, F}	*)
      Include (Options, ORD ('c'));
      Include (Options, ORD ('F'));
   END;

   IF IsElement (ORD ('J') - ORD ('A'), Options) THEN
						(* +J -> i		*)
      Include (Options, ORD ('i'));
   END;

   IF IsElement (ORD ('D') - ORD ('A'), Options) THEN
      Include (Options, ORD ('e'));		(* +D -> e		*)
   END;

   IF IsElement (ORD ('E') - ORD ('A'), Options) THEN
      Include (Options, ORD ('='));		(* +E -> =		*)
   END;

   IF IsElement (ORD ('I') - ORD ('A'), Options) THEN
      Include (Options, ORD ('v'));		(* +I -> v		*)
   END;

   IF IsElement (ORD ('A'), Options) THEN	(* A -> {D, I}		*)
      Include (Options, ORD ('D'));
      Include (Options, ORD ('I'));
   END;

   IF IsElement (ORD ('T'), Options) OR		(* {T, X, Y, Z} -> I	*)
      IsElement (ORD ('X'), Options) OR
      IsElement (ORD ('Y'), Options) OR
      IsElement (ORD ('Z'), Options) THEN
      Include (Options, ORD ('I'));
   END;

   IF IsElement (ORD ('J'), Options) THEN	(* J -> i<==>d, I<==>D *)
      IF IsElement (ORD ('i'), Options) THEN Include (Options, ORD ('d')); END;
      IF IsElement (ORD ('d'), Options) THEN Include (Options, ORD ('i')); END;
      IF IsElement (ORD ('I'), Options) THEN Include (Options, ORD ('D')); END;
      IF IsElement (ORD ('D'), Options) THEN Include (Options, ORD ('I')); END;
   END;

   IF IsElement (ORD ('I'), Options) OR		(* {I, V, M, P, S, N, O, G, E, C, J, x, z, u} -> . = Order *)
      IsElement (ORD ('V'), Options) OR
      IsElement (ORD ('M'), Options) OR
      IsElement (ORD ('P'), Options) OR
      IsElement (ORD ('S'), Options) OR
      IsElement (ORD ('N'), Options) OR
      IsElement (ORD ('O'), Options) OR
      IsElement (ORD ('G'), Options) OR
      IsElement (ORD ('E'), Options) OR
      IsElement (ORD ('C'), Options) OR
      IsElement (ORD ('J') - ORD ('A'), Options) OR
      IsElement (ORD ('0'), Options) OR
      IsElement (ORD ('x'), Options) OR
      IsElement (ORD ('z'), Options) OR
      IsElement (ORD ('u'), Options) THEN
      Include (Options, ORD ('.'));
   END;

   IF IsElement (ORD ('x'), Options) OR		(* {x, z, u} -> B	*)
      IsElement (ORD ('z'), Options) OR
      IsElement (ORD ('u'), Options) THEN
      Include (Options, ORD ('B'));
   END;

   IF IsElement (ORD ('T'), Options) THEN	(* T -> {X, Z}		*)
      Include (Options, ORD ('X'));
      Include (Options, ORD ('Z'));
   END;

   IF IsElement (ORD ('X'), Options) THEN	(* X -> Y		*)
      Include (Options, ORD ('Y'));
   END;

   IF IsElement (ORD ('L'), Options) THEN	(* L -> - {K, 0}	*)
      Exclude (Options, ORD ('K'));
      Exclude (Options, ORD ('0'));
   END;

   IF IsElement (ORD ('K'), Options) THEN	(* K -> - {0}		*)
      Exclude (Options, ORD ('0'));
      IF IsElement (ORD ('D'), Options) THEN	(* {K, D} -> I		*)
	 Include (Options, ORD ('I'));
      END;
   END;

   IF IsElement (ORD ('h'), Options) THEN
      Exclude (Options, ORD ('h'));
      f := StdOutput;
      !!
      !usage: cg [-options] [+options] [-l<directory>] [<files>]!
      !!
      !options for tree/graph module!
      !!
      ! a generate all except -ceh (default)!
      ! n generate node constructors    procedures n<node> (node)!
      ! m generate node constructors    procedures m<node> (make)!
      ! f generate node/graph destroyer procedure ReleaseTREE (free)!
      ! F generate general    destroyer procedure ReleaseTREEModule (FREE)!
      ! o generate text   node  writer  procedure WriteTREENode (output)!
      ! r generate text   graph reader  procedure ReadTREE!
      ! w generate text   graph writer  procedure WriteTREE!
      !+X generate XML    graph writer  procedure WriteTREEXML!
      ! g generate binary graph reader  procedure GetTREE!
      ! p generate binary graph writer  procedure PutTREE!
      ! t generate top down  traversal  procedure TraverseTREETD!
      ! b generate bottom up traversal  procedure TraverseTREEBU!
      ! R generate list reverser        procedure ReverseTREE!
      ! R generate list iterator        procedure ForallTREE!
      ! y generate graph copy           procedure CopyTREE!
      ! = generate tree equality test   procedure IsEqualTREE!
      ! k generate graph type checker   procedure CheckTREE!
      ! q generate text  graph browser  procedure QueryTREE!
      ! e generate graphic browser      procedure DrawTREE!
      ! _ generate array TREE_NodeName!
      ! d generate header file or definition module!
      ! i generate implementation part or module!
      ! s generate import statements!
      ! : generate lines not longer than 80 characters!
      ! 4 generate tree/graph description in file TREE.TS!
      ! 6 generate # line directives!
      ! 7 touch output files only if necessary!
      ! 8 report storage consumption!
      ! c   generate C    source code (default: Modula-2)!
      ! c+  generate C++  source code (using C   data structure: union)!
      ! c++ generate C++  source code (using C++ data structure: class)!
   (* ! -   generate Ada  source code! *)
      ! J   generate Java source code!
      ! h print help information for tree/graph module!
      ! H print help information for attribute evaluator module!
      !+H print advanced help!
      ! -l<dir> specify the directory dir where cg finds its tables!
      !!
      !options for scanner and parser interface!
      !!
      ! x generate scanner specification!
      ! z generate parser  specification for lark!
      ! u generate parser  specification for yacc!
      ! v omit actions in the generated parser specifications!
      ! j allow undefined node types; define implicitly as terminals!
      !+I allow incomplete attribute computation rules!
   END;

   IF IsElement (ORD ('H'), Options) THEN
      Exclude (Options, ORD ('H'));
      f := StdOutput;
      !!
      !usage: cg [-options] [+options] [-l<directory>] [<files>]!
      !!
      !options for evaluator module!
      !!
      ! A generate all, same as -DI (default)!
      ! D generate header file or definition module!
      ! I generate implementation part or module!
      ! K generate an evaluator based on a stack automaton (default: recursive procedures)!
      ! L generate a (lazy) evaluator for WAG (default: OAG)!
      ! W suppress warnings!
      ! B allow missing attribute computations in extended node types!
      ! V print visit sequences!
      ! M print summary of all node types (rules) from source!
      ! P print dependency relations DP!
      ! S print dependency relations SNC!
      ! N print dependency relations DNC!
      ! O print dependency relations OAG!
      ! G print attribute instances sorted by declaration order!
      ! E print attribute instances sorted by evaluation order!
      ! C print dependencies introduced for total order!
      ! T generate evaluator with trace output (all actions, T = XZ)!
      ! U trace only node types specified in file TraceTab!
      ! X trace attribute evaluation actions with    values!
      ! Y trace attribute evaluation actions without values!
      ! Z trace visit actions!
      ! Q browse internal data structure with text browser!
      ! 0 optimize attribute storage!
      ! 1 print inserted copy rules!
      ! 2 print inherited attribute computation rules!
      ! 3 print attribute storage assignment!
      ! 5 generate source code to check for cyclic dependencies!
      ! 6 generate # line directives!
      ! 7 touch output files only if necessary!
      ! 8 report storage consumption!
      ! 9 generate source code to measure stack size!
      ! c generate C    source code (default: Modula-2)!
      ! + generate C++  source code!
   (* ! - generate Ada  source code! *)
      ! J generate Java source code!
   (* ! . run order! *)
   (* ! , generate procedure yyMark! *)
   (* ! ; generate 'TreeStore'! *)
   (* ! / follow as early as possible strategy instead of as late as possible! *)
   (* ! @ print messages (do not store)! *)
   (* ! % used for evaluation version! *)
      ! h print help information for tree/graph module!
      ! H print help information for attribute evaluator module!
      !+H print advanced help!
      ! -l<dir> specify the directory dir where cg finds its tables!
   (*
      !!
      !implications!
      !!
      ! {}              -> {a, A}!
      ! a               -> {a-z, F, R} - {c, e, h, u, x, z}!
      ! A               -> {D, I}!
      ! {L, T, X, Y, Z} -> I!
      ! T               -> {X, Z}!
   *)
   END;

   IF IsElement (ORD ('H') - ORD ('A'), Options) THEN
      Exclude (Options, ORD ('H') - ORD ('A'));
      f := StdOutput;
      !!
      !usage: cg [-options] [+options] [-l<directory>] [<files>]!
      !!
      !advanced options!
      !!
      ! +H print advanced help!
      ! +D generate graphic browser procedure DrawTREE enclosed in #ifdef DRAWTREE!
      ! +G browse internal data structure with graphical browser!
      ! +E generate tree equality test procedure IsEqualTREE!
      ! +I suppress informations!
      ! +J start dialog system!
      ! +P generate empty bodies for procedures not selected!
      ! +X generate XML writer procedure WriteTREEXML!
   (* ! -- generate Ada source code! *)
      ! -. run order!
      ! -, generate procedure yyMark!
      ! -; generate 'TreeStore'!
      ! -/ follow as early as possible strategy instead of as late as possible!
      ! -@ print messages (do not store)!
   END;

   IF NOT IsEmpty (Options) THEN

      IF Length (CgLib) = 0 THEN
	 EnvVarPtr := GetEnvVar ("CT_DIR");
	 IF EnvVarPtr # NIL THEN
	    i := 0;
	    LOOP
	       Argument [i] := EnvVarPtr^ [i];
	       IF (Argument [i] = 0C) OR (i = 255) THEN EXIT; END;
	       INC (i);
	    END;
	    ArrayToString (Argument, CgLib);
	    Append (CgLib, DirectorySeparator ());
	    ArrayToString ("lib", String);
	    Concatenate	(CgLib, String);
	    Append (CgLib, DirectorySeparator ());
	    ArrayToString ("cg", String);
	    Concatenate	(CgLib, String);
	    Append (CgLib, DirectorySeparator ());
	 END;
      END;

   (* Include (Options, ORD ('%')); *)
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
      IF SubUnit # NoIdent THEN
	 Include (Options, ORD ('<'));
      END;

   IF IsElement (ORD ('q'), Options) OR		(* {q, e} -> {t, o, ^} = Search *)
      IsElement (ORD ('e'), Options) THEN
	 IF NOT IsElement (ORD ('<'), Options) THEN
      Include (Options, ORD ('o'));
      Include (Options, ORD ('t'));
	 END;
      Include (Options, ORD ('^'));
   END;

   IF IsElement (ORD ('w'), Options) OR		(* {w, p, f, k, t, b, y, e, +X} -> , = Mark *)
      IsElement (ORD ('p'), Options) OR
      IsElement (ORD ('f'), Options) OR
      IsElement (ORD ('k'), Options) OR
      IsElement (ORD ('t'), Options) OR
      IsElement (ORD ('b'), Options) OR
      IsElement (ORD ('y'), Options) OR
      IsElement (ORD ('e'), Options) OR
      IsElement (ORD ('X') - ORD ('A'), Options) THEN
      Include (Options, ORD (','));
   END;

IF NOT IsElement (ORD ('<'), Options) THEN
   IF IsElement (ORD ('k'), Options) THEN	(* {k} -> o		*)
      Include (Options, ORD ('o'));
   END;

   IF IsElement (ORD ('o'), Options) OR		(* {o, w, r, e, +X} -> _ = NodeName *)
      IsElement (ORD ('w'), Options) OR
      IsElement (ORD ('r'), Options) OR
      IsElement (ORD ('e'), Options) OR
      IsElement (ORD ('X') - ORD ('A'), Options) THEN
      Include (Options, ORD ('_'));
   END;
END;

IF NOT IsElement (ORD ('+'), Options) THEN
   IF IsElement (ORD ('w'), Options) OR		(* {w, r, p, g, +X} -> ; = TreeStore *)
      IsElement (ORD ('r'), Options) OR
      IsElement (ORD ('p'), Options) OR
      IsElement (ORD ('g'), Options) OR
      IsElement (ORD ('X') - ORD ('A'), Options) THEN
      Include (Options, ORD (';'));
   END;

   IF IsElement (ORD ('w'), Options) OR		(* {w, o, +X} -> $ = WriteHex, etc. *)
      IsElement (ORD ('o'), Options) OR
      IsElement (ORD ('X') - ORD ('A'), Options) THEN
      Include (Options, ORD ('$'));
   END;
END;

IF IsElement (ORD ('+'), Options) AND NOT IsElement (ORD ('<'), Options) THEN
      Include (Options, ORD (';'));		(* + -> {;, $} = Support *)
      Include (Options, ORD ('$'));
END;

      Semantics		(TreeRoot);
      IF IsElement (ORD ('i'), Options) AND NOT CheckLicense ("ast", ClassCount)
      THEN INC (ErrorCount); END;
      IF IsElement (ORD ('I'), Options) AND NOT CheckLicense ("ag ", ClassCount)
      THEN INC (ErrorCount); END;
      IF ErrorCount > 0 THEN WriteMessages (StdError); CloseIO; rExit (1); END;
   END;

   EmptyBodies := IsElement (ORD ('P') - ORD ('A'), Options);

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
   IF IsElement (ORD ('*'), Options) THEN
      GramC.ScanSpec	(TreeRoot);
   ELSIF IsElement (ORD ('c'), Options) THEN
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
   IF IsElement (ORD ('*'), Options) THEN
      GramC.ParsSpec	(TreeRoot);
   ELSIF IsElement (ORD ('c'), Options) THEN
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
      StoreMessages (NOT IsElement (ORD ('@'), Options));

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

      IF ErrorCount > 0 THEN CloseIO; rExit (1); END;

   IF IsElement (ORD ('i'), Options) OR
      IsElement (ORD ('X'), Options) THEN
      GenerateMacros;
   END;

IF NOT (IsElement (ORD ('+'), Options) AND IsElement (ORD ('<'), Options)) AND
   NOT IsElement (ORD ('J'), Options) THEN

   IF IsElement (ORD ('d'), Options) THEN
      GetFileName	(iModule, ModuleName);
      Assign		(PathS, ModuleName);
   IF IsElement (ORD ('*'), Options) THEN
      ArrayToString	(DefExtC, String);
   ELSIF IsElement (ORD ('+'), Options) THEN
      ArrayToString	(DefExtC, String);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	(DefExtC, String);
   ELSE
      ArrayToString	(DefExtMc, String);
   END;
      Concatenate	(PathS, String);
      Assign		(DefFile, PathS);
      f := SmartOpen	(PathS);
   IF IsElement (ORD ('*'), Options) THEN
      TreeCxx1.TreeDefCxx (TreeRoot);
   ELSIF IsElement (ORD ('c'), Options) THEN
      TreeC1.TreeDefC	(TreeRoot);
   ELSE
      TreeMod1.TreeDefMod (TreeRoot);
   END;
      SmartClose	(PathS, f);

   IF NOT IsElement (ORD ('c'), Options) THEN
      ArrayToString	("gcpp ", PathS);		(* call cpp *)
      Concatenate	(PathS, DefFile);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      j := rSystem	(PathA);
   END;
   END;
END;

   IF IsElement (ORD ('4'), Options) THEN
      GetString		(ViewName, PathS);
      ArrayToString	(".TS", String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);
      WriteI		(f, Version, 1); WriteNl (f);
      IF iPackage # NoIdent THEN
         WriteIdent	(f, iPackage);
         WriteC		(f, '.');
      END;
      WriteIdent	(f, iModule); WriteNl (f);
      WriteIdent	(f, Prefix); WriteNl (f);
   IF IsElement (ORD ('L'), Options) THEN
      WriteC		(f, 'L');
   ELSE
      WriteC		(f, ' ');
   END;
      WriteNl		(f);
      PutTree		(f, TreeRoot^.Ag.Classes);
      SmartClose	(PathS, f);
   END;

   IF IsElement (ORD ('i'), Options) THEN
      GetFileName	(iModule, ModuleName);
      Assign		(PathS, ModuleName);
   IF IsElement (ORD ('*'), Options) THEN
      ArrayToString	(ImpExtCpp, String);
   ELSIF IsElement (ORD ('+'), Options) THEN
      ArrayToString	(ImpExtCpp, String);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	(ImpExtC, String);
   ELSIF IsElement (ORD ('J'), Options) THEN
      ArrayToString	(ImpExtJava, String);
   ELSE
      ArrayToString	(ImpExtMc, String);
   END;
      Concatenate	(PathS, String);
      Assign		(TreeFile, PathS);
      f := SmartOpen	(PathS);
   IF IsElement (ORD ('*'), Options) THEN
      TreeCxx1.TreeImplCxx (TreeRoot);
   ELSIF IsElement (ORD ('c'), Options) THEN
      TreeC1.TreeImplC	(TreeRoot);
   ELSIF IsElement (ORD ('J'), Options) THEN
      TreeJav1.TreeImplJava (TreeRoot);
   ELSE
      TreeMod1.TreeImplMod (TreeRoot);
   END;
      SmartClose	(PathS, f);

   IF NOT IsElement (ORD ('c'), Options) THEN
      IF IsElement (ORD ('J'), Options) THEN
         ArrayToString	("gcppt ", PathS);		(* call cpp + tidy *)
      ELSE
         ArrayToString	("gcpp ", PathS);		(* call cpp *)
      END;
      Concatenate	(PathS, TreeFile);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      j := rSystem	(PathA);
   END;
   END;

   IF IsElement (ORD ('s'), Options) AND NOT IsElement (ORD ('c'), Options) AND
      NOT IsElement (ORD ('J'), Options) THEN
      GetString		(iModule, ModuleName);
      Assign		(PathS, ModuleName);
      ArrayToString	(LisExtMc, String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);
      TreeMod1.ImportList (TreeRoot);
      SmartClose	(PathS, f);
   END;

   IF IsElement (ORD ('U'), Options) THEN
      ReadTraceTab;
   ELSIF NOT IsEmpty (Options) THEN
      ForallClasses	(TreeRoot^.Ag.Classes, SetTrace);
   END;

   IF IsElement (ORD ('I'), Options) THEN
      GetFileName	(TreeRoot^.Ag.EvalName, ModuleName);
      Assign		(PathS, ModuleName);
   IF IsElement (ORD ('*'), Options) THEN
      ArrayToString	(ImpExtCpp, String);
   ELSIF IsElement (ORD ('+'), Options) THEN
      ArrayToString	(ImpExtCpp, String);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	(ImpExtC, String);
   ELSIF IsElement (ORD ('J'), Options) THEN
      ArrayToString	(ImpExtJava, String);
   ELSE
      ArrayToString	(ImpExtMc, String);
   END;
      Concatenate	(PathS, String);
      Assign		(EvalFile, PathS);
      f := SmartOpen	(PathS);
   IF IsElement (ORD ('*'), Options) THEN
      IF IsElement (ORD ('K'), Options) THEN
	 EvalCxx4.EvalImplCxx (TreeRoot);
      ELSIF IsElement (ORD ('L'), Options) THEN
	 EvalCxx3.EvalImplCxx (TreeRoot);
      ELSIF IsElement (ORD ('0'), Options) THEN
	 EvalCxx2.EvalImplCxx (TreeRoot);
      ELSE
	 EvalCxx.EvalImplCxx (TreeRoot);
      END;
   ELSIF IsElement (ORD ('c'), Options) THEN
      IF IsElement (ORD ('K'), Options) THEN
	 EvalC4.EvalImplC (TreeRoot);
      ELSIF IsElement (ORD ('L'), Options) THEN
	 EvalC3.EvalImplC (TreeRoot);
      ELSIF IsElement (ORD ('0'), Options) THEN
	 EvalC2.EvalImplC (TreeRoot);
      ELSE
	 EvalC.EvalImplC (TreeRoot);
      END;
   ELSIF IsElement (ORD ('J'), Options) THEN
      IF IsElement (ORD ('K'), Options) THEN
         Message ("option K not supported for Java", Error, NoPosition);
	 INC (ErrorCount);
	 (* EvalJav4.EvalImplJava (TreeRoot); *)
      ELSIF IsElement (ORD ('L'), Options) THEN
	 Message ("option L not supported for Java", Error, NoPosition);
	 INC (ErrorCount);
	 (* EvalJav3.EvalImplJava (TreeRoot); *)
      ELSIF IsElement (ORD ('0'), Options) THEN
	 Message ("option 0 not supported for Java", Error, NoPosition);
	 INC (ErrorCount);
	 (* EvalJav2.EvalImplJava (TreeRoot); *)
      ELSE
	 EvalJava.EvalImplJava (TreeRoot);
      END;
   ELSE
      IF IsElement (ORD ('K'), Options) THEN
	 EvalMod4.EvalImplMod (TreeRoot);
      ELSIF IsElement (ORD ('L'), Options) THEN
	 EvalMod3.EvalImplMod (TreeRoot);
      ELSIF IsElement (ORD ('0'), Options) THEN
	 EvalMod2.EvalImplMod (TreeRoot);
      ELSE
	 EvalMod.EvalImplMod (TreeRoot);
      END;
   END;
      SmartClose	(PathS, f);

   IF NOT IsElement (ORD ('c'), Options) THEN
      IF IsElement (ORD ('J'), Options) THEN
         ArrayToString	("gcppt ", PathS);		(* call cpp + tidy *)
      ELSE
         ArrayToString	("gcpp ", PathS);		(* call cpp *)
      END;
      Concatenate	(PathS, EvalFile);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      j := rSystem	(PathA);
   END;
   END;

   IF IsElement (ORD ('D'), Options) AND NOT IsElement (ORD ('J'), Options) THEN
      GetFileName	(TreeRoot^.Ag.EvalName, ModuleName);
      Assign		(PathS, ModuleName);
   IF IsElement (ORD ('*'), Options) THEN
      ArrayToString	(DefExtC, String);
   ELSIF IsElement (ORD ('+'), Options) THEN
      ArrayToString	(DefExtC, String);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	(DefExtC, String);
   ELSE
      ArrayToString	(DefExtMc, String);
   END;
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);
   IF IsElement (ORD ('*'), Options) THEN
      IF IsElement (ORD ('L'), Options) THEN
	 EvalCxx3.EvalDefCxx (TreeRoot);
      ELSE
	 EvalCxx.EvalDefCxx (TreeRoot);
      END;
   ELSIF IsElement (ORD ('c'), Options) THEN
      IF IsElement (ORD ('L'), Options) THEN
	 EvalC3.EvalDefC (TreeRoot);
      ELSE
	 EvalC.EvalDefC (TreeRoot);
      END;
   ELSE
      IF IsElement (ORD ('L'), Options) THEN
	 EvalMod3.EvalDefMod (TreeRoot);
      ELSE
	 EvalMod.EvalDefMod (TreeRoot);
      END;
   END;
      SmartClose	(PathS, f);
   END;

   IF NOT IsElement (ORD ('c'), Options) THEN
      IF IsElement (ORD ('i'), Options) OR
	 IsElement (ORD ('X'), Options) THEN
	 ArrayToString	("grm yy", PathS);		(* name of macro file *)
	 GetString	(iModule, ModuleName);
	 Concatenate	(PathS, ModuleName);
	 ArrayToString	(".h", String);
	 Concatenate	(PathS, String);
	 Append		(PathS, 0C);
	 StringToArray	(PathS, PathA);
	 j := rSystem	(PathA);
      END;
   END;

(*
   IF IsElement (ORD ('T') - ORD ('A'), Options) THEN
      tsl (TreeRoot);
   END;
*)

   IF IsElement (ORD ('8'), Options) THEN
      WriteNl (StdError);
      WriteS  (StdError, "Memory"); WriteI (StdError, MemoryUsed, 8);
      WriteS  (StdError, "  Heap"); WriteI (StdError, HeapUsed  , 8);
      WriteNl (StdError);
   END;
   WriteMessages (StdError);
   CloseIO;
   IF ErrorCount > 0 THEN rExit (1); END;
   rExit (0);
END cg.
