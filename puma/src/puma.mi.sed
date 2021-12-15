(* $Id: puma.sed,v 4.30 2013/01/15 13:38:48 grosch Exp $ *)

(*
 * $Log: puma.sed,v $
 * Revision 4.30  2013/01/15 13:38:48  grosch
 * added option -T: specify directories to be searched for .TS files
 *
 * Revision 4.29  2008/09/25 14:54:16  grosch
 * removed variable SourceFile2
 *
 * Revision 4.28  2008/09/16 19:39:00  grosch
 * made it work if installed in a directory with blanks in its name
 *
 * Revision 4.27  2008/09/16 08:13:57  grosch
 * added type specific operation writeXML<type>
 *
 * Revision 4.26  2005/10/12 21:12:52  grosch
 * quit after errors in semantic analysis
 *
 * Revision 4.25  2005/05/23 13:26:57  grosch
 * added option -I <dir>:
 * add dir to the list of directories to be searched for IMPORT files!
 *
 * Revision 4.24  2004/01/05 16:40:33  grosch
 * allow statements after RETURN statement
 * added new statement for IMPORT of external routine declarations
 * allow pattern matching in IF statements
 * a FOR loop can declare its loop variable
 * added new scopes and changed scoping rules:
 *    THEN and ELSE parts of the IF statement and the FOR and WHILE loops
 *
 * Revision 4.23  2003/04/25 08:46:31  grosch
 * added license control based on WIBU-KEY
 *
 * Revision 4.22  2002/10/02 16:22:25  grosch
 * added initialization of Attribute.Position
 *
 * Revision 4.21  2002/09/25 15:27:33  grosch
 * added generation of proper C++ source code
 *
 * Revision 4.20  2002/07/30 09:52:32  grosch
 * added support for automatic prefixing of node types for C and C++
 *
 * Revision 4.19  2001/12/17 12:07:44  grosch
 * quit processing after errors in reading of the view files
 *
 * Revision 4.18  2001/09/20 14:30:45  grosch
 * added option @ for suppressing a call of function StoreMessages
 *
 * Revision 4.17  2001/08/28 21:03:41  grosch
 * added option and call for DrawTree
 * made output of option -t more pretty
 *
 * Revision 4.16  2001/08/01 14:43:52  grosch
 * delivery of Trevor Nash for generation of Java
 *
 * Revision 4.15  2001/01/24 11:22:46  grosch
 * updated version number
 *
 * Revision 4.14  2001/01/24 09:15:52  grosch
 * added access to environment variable CT_DIR
 *
 * Revision 4.13  2000/04/10 14:30:47  grosch
 * improved license checking
 *
 * Revision 4.12  2000/04/10 14:29:43  grosch
 * added version number to .TS file
 * corrected printing of abstract node types
 * omit printing of virtual attributes
 * improved handling of options
 *
 * Revision 4.11  1999/11/09 19:54:44  grosch
 * improved and purified license checking
 *
 * Revision 4.10  1999/07/12 14:01:09  grosch
 * added filename to error messages
 *
 * Revision 4.9  1999/06/03 08:27:00  grosch
 * bug fix: printing types of tree-valued attributes
 *
 * Revision 4.8  1998/04/21 10:12:19  grosch
 * truncation of file and module names to 8.3 format
 * added Information messages and option -u
 * added options -x, -y, -z
 * added handling of license file
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

(* Ich, Doktor Josef Grosch, Informatiker, April 1991/Okt. 1996 *)

MODULE puma;

FROM SYSTEM	IMPORT ADR;
FROM rSystem	IMPORT GetArgCount, GetArgument, GetEnvVar, rSystem, rExit,
			tArrayChar, rtpqx, rtpqy, DirectorySeparator;
FROM rMemory	IMPORT MemoryUsed;
FROM IO		IMPORT StdOutput, StdError, WriteOpen, WriteClose, CloseIO,
			WriteI, WriteS, WriteNl, ReadC, ReadI,
			tFile, ReadOpen, ReadClose, EndOfFile, ReadNl;
FROM Strings	IMPORT tString, AssignEmpty, Assign, Append, Concatenate,
			ReadL, WriteL, ArrayToString, StringToArray, IsInOrder,
			Length;
FROM Idents	IMPORT tIdent, NoIdent, MakeIdent, GetString, WriteIdent,
			GetLength;
FROM Sets	IMPORT tSet, MakeSet, ReleaseSet, Include, Exclude, IsEmpty,
			Extract, Complement, Union, IsElement, WriteSet, Select;
FROM Relation	IMPORT tRelation, MakeRelation, ReleaseRelation, Closure,
			IsRelated, WriteRelation;
FROM Position	IMPORT NoPosition;
FROM Errors	IMPORT StoreMessages, WriteMessages, Message, MessageI, Fatal,
			Error, Array, Restriction;
FROM Scanner	IMPORT BeginFile, ErrorI;
FROM Parser	IMPORT Parser;
FROM Tree	IMPORT NoTree, tTree, TreeRoot, HeapUsed, Options, SourceFile,
			f, WI, mNoClass, TreeName, ErrorCount, Class, Child,
			Attribute, ActionPart, NoClass, Test, Dummy, Abstract,
			ForallClasses, ForallAttributes, QueryTree, DrawTree,
			Reverse, Virtual, GetFileName, GetPackage, Spec, Import;
FROM Semantic	IMPORT Semantics, TypeCount, TypeNames, UserTypes,
			RemoveTreeTypes, AddStructuredTypes, IdentifyClass,
			IdentifyClass2, LookupClass;
FROM Optimize	IMPORT Optimize, RuleProperties;
FROM Mod	IMPORT DefMod, ImplMod, MacroMod;
FROM C		IMPORT DefC, ImplC, MacroC, MacroCpp;
FROM Cxx	IMPORT DefCxx, ImplCxx, MacroCxx;
FROM Java	IMPORT ImplJava, MacroJava;

IMPORT Tree2, Relation, Scanner;

CONST
   Version	= 0208	;

   DefExtMc	= ".md"	;	(* file extensions for Modula (mc)	*)
   ImpExtMc	= ".mi"	;
   DefExtC	= ".h"	;	(* file extensions for C		*)
   ImpExtC	= ".c"	;
   ImpExtCpp	= ".cxx";	(* file extension  for C++		*)
   ImpExtJava	= ".java";	(* file extension  for Java		*)

VAR
   PumaLib	,
   TrafoFile	,
   String	,
   String2	,
   PathS	: tString;
   Argument	,
   PathA	: ARRAY [0..255] OF CHAR;
   NoOption	,
   TheIndex	,
   StopIndex	,
   i, j, j2, n	: SHORTCARD;
   ch		: CHAR;
   Iterator	,
   StartClass	,
   StopClass	,
   TheClass	,
   TheTree	: tTree;
   StartId	,
   StopId	: tIdent;
   WorkingSet	,
   Done		: tSet;
   Reachable	: tRelation;
   NeedsTraversal: BOOLEAN;
   EnvVarPtr	: tArrayChar;
   ImportPath	: ARRAY [0..16] OF tString;
   PathCount	: SHORTCARD;
   TSPath	: ARRAY [0..16] OF tString;
   TSPathCount	: SHORTCARD;

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
	 MessageI ("can not access file", Fatal, NoPosition, Array, ADR (PathA));
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
	 n := rSystem	(PathA);
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
      CASE n OF
      | 1: Message ("cannot open license file: ctlicens.dat", Fatal, NoPosition);
      | 2: Message ("sorry, the license is expired", Fatal, NoPosition);
      | 3: Message ("sorry, the problem is too big for demo version", Restriction, NoPosition);
      | 4: Message ("license file ctlicens.dat seems corrupted", Fatal, NoPosition);
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
      Assign		(PathS, PumaLib);
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

PROCEDURE GenerateMacros;
   VAR TypeTabFile	: tFile;
   VAR s		: tString;
   VAR i		: tIdent;
   VAR j		: INTEGER;
   BEGIN
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
      Assign		(PathS, PumaLib);
      Concatenate	(PathS, String);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      TypeTabFile := ReadOpen (PathA);
      IF TypeTabFile < 0 THEN
	 MessageI ("can not access file", Error, NoPosition, Array, ADR (PathA));
	 INC (ErrorCount);
         RETURN;
      END;

      ArrayToString	("yy" , PathS);		(* name of macro file *)
      GetFileName	(TreeRoot^.Spec.TrafoName, String);
      Concatenate	(PathS, String);
      ArrayToString	(".h", String);
      Concatenate	(PathS, String);
      f := SmartOpen	(PathS);

(* !//Built in types!~ *)
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
	    ReadNl (TypeTabFile);
	 ELSE
	    FOR j := 1 TO 9 DO ReadNl (TypeTabFile); END;
	 END;
      END;
      ReadClose (TypeTabFile);
      RemoveTreeTypes (TreeRoot);

(* !//Typenames!~ *)
      WHILE NOT IsEmpty (TypeNames) DO
	 i := Extract (TypeNames);
	 Include (UserTypes, i);
   IF IsElement (ORD ('c'), Options) THEN
	 !# ifndef begin! WI (i); !!
	 !# define begin! WI (i); !(a)!
	 !# endif!
	 !# ifndef equal! WI (i); !!
	 !# define equal! WI (i); !(a, b)	\!
	 !  memcmp ((char *) & a, (char *) & b, sizeof (a)) == 0!
	 !# endif!
   ELSIF IsElement (ORD ('J'), Options) THEN
	 !# ifndef begin! WI (i); !!
	 !# define begin! WI (i); !(a)!
	 !# endif!
	 !# ifndef equal! WI (i); !!
	 !# define equal! WI (i); !(a, b)	(a.equals (b))!
	 !# endif!
   ELSE
	 !# ifndef begin! WI (i); !!
	 !# define begin! WI (i); !(a)!
	 !# endif!
	 !# ifndef equal! WI (i); !!
	 !# define equal! WI (i); !(a, b)	yyIsEqual (a, b)!
	 !# endif!
   END;
      END;
(* !//Structured Types!~ *)
      AddStructuredTypes;

(* !//Macros!~ *)
   IF IsElement (ORD ('*'), Options) THEN
      MacroCxx (TreeRoot);
   ELSIF IsElement (ORD ('+'), Options) THEN
      MacroCpp (TreeRoot);
   ELSIF IsElement (ORD ('c'), Options) THEN
      MacroC (TreeRoot);
   ELSIF IsElement (ORD ('J'), Options) THEN
      MacroJava (TreeRoot);
   ELSE
      MacroMod (TreeRoot);
   END;

      SmartClose (PathS, f);
   END GenerateMacros;

VAR IndentLevel: INTEGER;

PROCEDURE WriteClass (t: tTree);
   VAR i, column: INTEGER;
   BEGIN
      CASE t^.Kind OF
      | Class	: WITH t^.Class DO
	    FOR i := 1 TO IndentLevel DO
	       WriteS	(StdOutput, "  ");
	    END;
	    WriteIdent	(StdOutput, Name);
	    column := IndentLevel * 2 + GetLength (Name);
	    FOR i := column + 1 TO 32 DO
	       WriteS	(StdOutput, " ");
	    END;
	    IF Abstract IN Properties THEN
	       WriteS	(StdOutput, ":=");
	    ELSE
	       WriteS	(StdOutput, "=");
	    END;
	    WriteClass	(Attributes);
	    IF Extensions^.Kind # NoClass THEN
	       WriteS	(StdOutput, " <");
	       WriteNl	(StdOutput);
	       INC (IndentLevel);
	       WriteClass (Extensions);
	       DEC (IndentLevel);
	       FOR i := 1 TO IndentLevel DO
		  WriteS (StdOutput, "  ");
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
	    IF (NodeType # NoTree) AND (NodeType^.Kind = Class) THEN
	       WriteIdent (StdOutput, NodeType^.Class.Name);
	    ELSE
	       WriteIdent (StdOutput, Type);
	    END;
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
	 IF NOT (Virtual IN Properties) THEN
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
	 END;
      | Attribute	: WITH t^.Attribute DO
	 IF ({Test, Dummy, Virtual} * Properties) = {} THEN
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
	    ELSIF NOT (Virtual IN Properties) THEN
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
	    ELSIF NOT (Virtual IN Properties) THEN
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
	       ELSIF NOT (Virtual IN Properties) THEN
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

PROCEDURE GetTSFile (Name: tIdent): tFile;
  VAR i		: SHORTCARD;
  VAR File	: tFile;
  BEGIN
    i := 0;
    LOOP
      Assign		(PathS, TSPath [i]);
      GetFileName	(Name, String);
      Concatenate	(PathS, String);
      ArrayToString	(".TS", String);
      Concatenate	(PathS, String);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      File := ReadOpen	(PathA);
      IF File >= 0 THEN RETURN File; END;
      INC (i);
      IF i > PathCount THEN RETURN -1; END;
    END;
  END GetTSFile;

PROCEDURE GetTrees (Node: tTree);
   BEGIN
      WHILE Node^.Kind = TreeName DO
	 WITH Node^.TreeName DO
	    f := GetTSFile (Name);
	    IF f >= 0 THEN
	       IF ReadI (f) # Version THEN
		  INC (ErrorCount);
		  MessageI ("file produced by wrong version of ast", Fatal, NoPosition, Array, ADR (PathA));
	       END;
	       ReadNl (f);
	       ReadL (f, String);
	       Name := MakeIdent (String);
	       GetPackage (Name, Package, Name);
	       GetString (Name, String);
	       ArrayToString ("t", String2);
	       Concatenate (String2, String);
	       tName := MakeIdent (String2);
	       ReadL (f, String);
	       Prefix := MakeIdent (String);
	       Include (Options, ORD (ReadC (f))); ReadNl (f);
	       Classes := Tree2.GetTree (f);
	       ReadClose (f);
      IF IsElement (ORD ('t'), Options) THEN
	       WriteS (StdOutput, "Tree Definition: "); WriteIdent (StdOutput, Name);
	       WriteNl (StdOutput);
	       WriteS (StdOutput, "----------------"); WriteNl (StdOutput);
	       WriteNl (StdOutput);
	       WriteClass (Classes);
	       WriteNl (StdOutput);
      END;
      IF IsElement (ORD ('r'), Options) THEN
	       WriteS (StdOutput, "Patterns: "); WriteIdent (StdOutput, Name);
	       WriteNl (StdOutput);
	       WriteS (StdOutput, "---------"); WriteNl (StdOutput);
	       WriteNl (StdOutput);
	       ForallClasses (Classes, WritePattern);
	       WriteNl (StdOutput);
      END;
      IF IsElement (ORD ('x'), Options) THEN
	       WriteS (StdOutput, "PROCEDURE Traverse (");
	       WriteIdent (StdOutput, Name);
	       WriteS (StdOutput, ")");
	       WriteNl (StdOutput);
	       WriteNl (StdOutput);
	       WriteTraverse (Classes);
	       WriteNl (StdOutput);
      END;
	    ELSE
	       Classes := mNoClass ();
	       ErrorI ("cannot read view file", Pos, Name);
	    END;
	    Node := Next;
	 END;
      END;
   END GetTrees;

PROCEDURE GetImports (t: tTree);
   VAR i	: SHORTCARD;
   VAR File	: tFile;
   BEGIN
      CASE t^.Kind OF
      | Spec	:
            GetImports (t^.Spec.Imports);
	    TreeRoot := t;
      | Import	: WITH t^.Import DO
	    i := 0;
	    LOOP
	       Assign (String, ImportPath [i]);
	       GetString (Name, String2);
	       Concatenate (String, String2);
	       StringToArray (String, PathA);
	       File := ReadOpen (PathA);
	       IF File >= 0 THEN
		  ReadClose (File);
		  Scanner.Attribute.Position := NoPosition;
		  Scanner.Attribute.Position.File := MakeIdent (String);
		  BeginFile (PathA);
		  INC (ErrorCount, Parser ());
		  Spec := TreeRoot;
		  EXIT;
	       END;
	       INC (i);
	       IF i > PathCount THEN
		  ErrorI ("cannot read IMPORT file", Pos, Name);
		  EXIT;
	       END;
	    END;
            GetImports (Next);
	 END;
      ELSE
      END;
   END GetImports;

BEGIN
   NoOption := 0;
   IndentLevel := 0;
   AssignEmpty (PumaLib);
   PathCount := 0;
   AssignEmpty (ImportPath [0]);
   Append (ImportPath [0], '.');
   Append (ImportPath [0], DirectorySeparator ());
   TSPathCount := 0;
   AssignEmpty (TSPath [0]);
   Append (TSPath [0], '.');
   Append (TSPath [0], DirectorySeparator ());
   SourceFile [0] := 0C;
   n := GetArgCount () - 1;

   i := 1;
   WHILE i <= n DO
      GetArgument (i, Argument);
      IF Argument [0] = '-' THEN
	 IF Argument [1] = 'l' THEN
	    IF (Argument [2] = 0C) AND (i < n) THEN
	       INC (i);
	       GetArgument (i, Argument);
	       j := 0;
	    ELSE
	       j := 2;
	    END;
	    AssignEmpty (PumaLib);
	    LOOP
	       ch := Argument [j];
	       IF ch = 0C THEN EXIT; END;
	       Append (PumaLib, ch);
	       INC (j);
	    END;
	    Append (PumaLib, DirectorySeparator ());
	    INC (NoOption);
	 ELSIF Argument [1] = 'I' THEN
	    IF (Argument [2] = 0C) AND (i < n) THEN
	       INC (i);
	       GetArgument (i, Argument);
	       j := 0;
	    ELSE
	       j := 2;
	    END;
	    INC (PathCount);
	    AssignEmpty (ImportPath [PathCount]);
	    LOOP
	       ch := Argument [j];
	       IF ch = 0C THEN EXIT; END;
	       Append (ImportPath [PathCount], ch);
	       INC (j);
	    END;
	    Append (ImportPath [PathCount], DirectorySeparator ());
	    INC (NoOption);
	 ELSIF Argument [1] = 'T' THEN
	    IF (Argument [2] = 0C) AND (i < n) THEN
	       INC (i);
	       GetArgument (i, Argument);
	       j := 0;
	    ELSE
	       j := 2;
	    END;
	    INC (TSPathCount);
	    AssignEmpty (TSPath [TSPathCount]);
	    LOOP
	       ch := Argument [j];
	       IF ch = 0C THEN EXIT; END;
	       Append (TSPath [TSPathCount], ch);
	       INC (j);
	    END;
	    Append (TSPath [TSPathCount], DirectorySeparator ());
	    INC (NoOption);
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
		  IF (ch = '+') AND IsElement (ORD ('+'), Options) AND
		     IsElement (ORD ('c'), Options) THEN
		     Include (Options, ORD ('*'));
		     Exclude (Options, ORD ('+'));
		  ELSE
		     Include (Options, ORD (ch));
		  END;
	       END;
	    END;
	 END;
      ELSIF Argument [0] = '?' THEN
	 Include (Options, ORD ('h'));
      ELSE
	 j := 0; j2 := 0;
	 REPEAT
            ch := Argument [j];
	    SourceFile [j] := ch; INC (j);
	 UNTIL ch = 0C;
	 INC (NoOption);
      END;
      INC (i);
   END;

   IF n <= NoOption THEN			(* {} -> a		*)
      Include (Options, ORD ('a'));
   END;

   IF IsElement (ORD ('a'), Options) THEN	(* a -> {d, i}		*)
      Include (Options, ORD ('d'));
      Include (Options, ORD ('i'));
   END;

   IF IsElement (ORD ('+'), Options) THEN	(* + -> c		*)
      Include (Options, ORD ('c'));
   END;

   IF IsElement (ORD ('s'), Options) THEN	(* s -> u		*)
      Include (Options, ORD ('u'));
   END;

   IF IsElement (ORD ('h'), Options) THEN
      Exclude (Options, ORD ('h'));
      f := StdOutput;
      !!
      !usage: puma [-options] [-y <type>] [-z <type>] [-I <directory>] [-T <directory>]!
      !            [-l <directory>] [<file>]!
      !!
      ! a generate all, same as -di (default)!
      ! d generate header file or definition module!
      ! i generate implementation part or module!
      ! s suppress information and warning messages!
      ! u suppress information messages!
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
      ! q browse internal data structure with text browser!
      ! g browse internal data structure with graphical browser!
      ! : generate lines not longer than 80 characters!
      ! 6 generate # line directives!
      ! 7 touch output files only if necessary!
      ! 8 report storage consumption!
      ! c generate C source code (default: Modula-2)!
      ! c+ generate simple C++ source code!
      ! c++ generate proper C++ source code!
      ! J generate Java source code!
      ! h print help information!
      ! l <dir> specify the directory dir where puma finds its data files!
      ! I <dir> add dir to the list of directories to be searched for IMPORT files!
      ! T <dir> add dir to the list of directories to be searched for .TS files!
   (* ! b do not optimize generated source code! *)
   (* ! @ do not store and sort messages! *)
      !!
   END;

   IF IsEmpty (Options) THEN CloseIO; HALT; END;

      IF Length (PumaLib) = 0 THEN
	 EnvVarPtr := GetEnvVar ("CT_DIR");
	 IF EnvVarPtr # NIL THEN
	    i := 0;
	    LOOP
	       Argument [i] := EnvVarPtr^ [i];
	       IF (Argument [i] = 0C) OR (i = 255) THEN EXIT; END;
	       INC (i);
	    END;
	    ArrayToString (Argument, PumaLib);
	    Append (PumaLib, DirectorySeparator ());
	    ArrayToString ("lib", String);
	    Concatenate	(PumaLib, String);
	    Append (PumaLib, DirectorySeparator ());
	    ArrayToString ("puma", String);
	    Concatenate	(PumaLib, String);
	    Append (PumaLib, DirectorySeparator ());
	 END;
      END;

   IF NOT IsElement (ORD ('@'), Options) THEN
      StoreMessages (TRUE);
   END;
      IF SourceFile [0] # 0C THEN
	 ArrayToString (SourceFile, String);
      ELSE
	 ArrayToString ("-", String);
      END;
      Scanner.Attribute.Position := NoPosition;
      Scanner.Attribute.Position.File := MakeIdent (String);
      IF SourceFile [0] # 0C THEN
	 BeginFile (SourceFile);
      END;
      INC (ErrorCount, Parser ());
      GetTrees		(TreeRoot^.Spec.TreeNames);
      GetImports	(TreeRoot);
      IF ErrorCount > 0 THEN WriteMessages (StdError); CloseIO; rExit (1); END;
      Semantics		(TreeRoot);
      IF ErrorCount > 0 THEN WriteMessages (StdError); CloseIO; rExit (1); END;
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
      StoreMessages (FALSE);
      IF NOT CheckLicense ("pum", TypeCount) THEN CloseIO; rExit (1); END;

   IF IsElement (ORD ('q'), Options) THEN
      QueryTree		(TreeRoot);
   END;
   IF IsElement (ORD ('g'), Options) THEN
      DrawTree		(TreeRoot);
   END;

      IF ErrorCount > 0 THEN CloseIO; rExit (1); END;

   IF IsElement (ORD ('d'), Options) THEN
      IF IsElement (ORD ('J'), Options) THEN
         (* No definition module in Java: assume an implementation is wanted. *)
         Include (Options, ORD ('i'));
      ELSE
         GetFileName		(TreeRoot^.Spec.TrafoName, PathS);
	 IF IsElement (ORD ('*'), Options) THEN
	    ArrayToString	(DefExtC, String);
	 ELSIF IsElement (ORD ('+'), Options) THEN
	    ArrayToString	(DefExtC, String);
	 ELSIF IsElement (ORD ('c'), Options) THEN
	    ArrayToString	(DefExtC, String);
	 ELSE
	    ArrayToString	(DefExtMc, String);
	 END;
	 Concatenate		(PathS, String);
	 f := SmartOpen		(PathS);
	 IF IsElement (ORD ('*'), Options) THEN
	    DefCxx		(TreeRoot);
	 ELSIF IsElement (ORD ('c'), Options) THEN
	    DefC		(TreeRoot);
	 ELSE
	    DefMod		(TreeRoot);
	 END;
	 SmartClose	(PathS, f);
      END;
   END;

   IF IsElement (ORD ('i'), Options) THEN
      GenerateMacros;

      GetFileName	(TreeRoot^.Spec.TrafoName, PathS);
   IF IsElement (ORD ('*'), Options) THEN
      ArrayToString	(ImpExtCpp, String);
   ELSIF IsElement (ORD ('+'), Options) THEN
      ArrayToString	(ImpExtCpp, String);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ArrayToString	(ImpExtC , String);
   ELSIF IsElement (ORD ('J'), Options) THEN
      ArrayToString	(ImpExtJava , String);
   ELSE
      ArrayToString	(ImpExtMc, String);
   END;
      Concatenate	(PathS, String);
      Assign		(TrafoFile, PathS);
      f := SmartOpen	(PathS);
   IF IsElement (ORD ('*'), Options) THEN
      ImplCxx		(TreeRoot);
   ELSIF IsElement (ORD ('c'), Options) THEN
      ImplC		(TreeRoot);
   ELSIF IsElement (ORD ('J'), Options) THEN
      ImplJava		(TreeRoot);
   ELSE
      ImplMod		(TreeRoot);
   END;
      SmartClose	(PathS, f);

   IF NOT IsElement (ORD ('c'), Options) THEN
      ArrayToString	("gcpp ", PathS);		(* call cpp *)
      Concatenate	(PathS, TrafoFile);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      n := rSystem	(PathA);

      ArrayToString	("grm yy", PathS);		(* name of macro file *)
      GetFileName	(TreeRoot^.Spec.TrafoName, String);
      Concatenate	(PathS, String);
      ArrayToString	(".h", String);
      Concatenate	(PathS, String);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      n := rSystem	(PathA);
   END;

   (* Java code generation may signal further errors in implementation file *)
   IF ErrorCount > 0 THEN
      ArrayToString	("grm ", PathS);	(* remove generated file *)
      Concatenate	(PathS, TrafoFile);
      Append		(PathS, 0C);
      StringToArray	(PathS, PathA);
      n := rSystem	(PathA);
      CloseIO; rExit (1);
   END;
   END;

   IF IsElement (ORD ('8'), Options) THEN
      WriteNl (StdError);
      WriteS  (StdError, "Memory"); WriteI (StdError, MemoryUsed, 8);
      WriteS  (StdError, "  Heap"); WriteI (StdError, HeapUsed  , 8);
      WriteNl (StdError);
   END;
   CloseIO; rExit (0);
END puma.
