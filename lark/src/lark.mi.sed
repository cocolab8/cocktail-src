(* $Id: lark.sed,v 1.26 2011/07/06 09:22:42 grosch Exp $ *)

(*
 * $Log: lark.sed,v $
 * Revision 1.26  2011/07/06 09:22:42  grosch
 * improved handling of options
 *
 * Revision 1.25  2010/07/07 09:53:55  grosch
 * added support for building of concrete syntax trees
 *
 * Revision 1.24  2005/05/23 13:05:44  grosch
 * improved handling of options for conflict explanation
 *
 * Revision 1.23  2003/04/25 08:45:08  grosch
 * added license control based on WIBU-KEY
 *
 * Revision 1.22  2002/10/02 16:25:08  grosch
 * added initialization of Attribute.Position
 *
 * Revision 1.21  2002/09/25 16:01:12  grosch
 * improved usage information
 *
 * Revision 1.20  2002/08/07 12:38:32  grosch
 * added generation of named constants for all tokens (option -f)
 *
 * Revision 1.19  2001/08/28 20:53:36  grosch
 * added option and call for DrawTree
 *
 * Revision 1.18  2001/02/10 16:41:46  grosch
 * always treat path separatos / and \, not just DirectorySeparator ()
 *
 * Revision 1.17  2001/01/24 09:16:41  grosch
 * added access to environment variable CT_DIR
 *
 * Revision 1.16  2000/09/12 17:50:52  grosch
 * checked in update for generation of Java from Trevor Nash
 *
 * Revision 1.15  2000/04/10 14:18:27  grosch
 * improved license checking
 *
 * Revision 1.14  2000/01/31 11:48:29  grosch
 * extract basename from input path for derivation of output filenames
 *
 * Revision 1.13  1999/12/01 11:27:17  grosch
 * added generation of Java
 *
 * Revision 1.12  1999/11/09 19:57:11  grosch
 * improved and purified license checking
 *
 * Revision 1.11  1999/07/12 15:07:15  grosch
 * added filename to error messages
 *
 * Revision 1.10  1998/04/21 13:06:14  grosch
 * truncation of file and module names to 8.3 format
 * added handling of license file
 * improved error messages in case of missing files
 *
 * Revision 1.9  1995/11/07  09:25:52  grosch
 * removed read reduce reduce conflicts
 * added conflict manager (delta)
 * added handling of LALR(2) grammars
 *
 * Revision 1.8  1994/12/09  14:15:42  grosch
 * added alternate algorithm for table compression
 *
 * Revision 1.7  1994/11/13  12:48:01  grosch
 * added option 4: decrement by table or by inline code
 * added option W: explain implicitly repaired conflicts only
 *
 * Revision 1.6  1994/09/13  12:52:19  grosch
 * added generation of Ada code
 *
 * Revision 1.5  1994/08/30  12:11:48  grosch
 * added option for choice of whether warning or error
 *
 * Revision 1.4  1994/07/14  12:24:56  grosch
 * redesign of table generation
 * added support for graphic visualization
 * restrict names of output files to one dot
 *
 * Revision 1.3  1994/04/13  10:01:34  grosch
 * added missing initializations of Properties
 *
 * Revision 1.2  1994/03/23  15:09:56  grosch
 * allow several start symbols
 * accept Yacc input as well as Lark input
 *
 * Revision 1.1  1994/03/17  22:24:11  grosch
 * added generation of C++
 * added environment variable LARK
 *
 * Revision 1.0  1994/02/01  14:05:54  grosch
 * Initial revision
 *
 *)

(* Ich, Doktor Josef Grosch, Informatiker, Jan. 1993 *)

MODULE lark;

FROM SYSTEM	IMPORT ADR;
FROM rSystem	IMPORT GetArgCount, GetArgument, GetEnvVar, tArrayChar, rSystem,
			rExit, DirectorySeparator, rtpqx, rtpqy;
FROM rMemory	IMPORT MemoryUsed;
FROM General	IMPORT Min;
FROM IO		IMPORT StdOutput, StdError, WriteOpen, WriteClose, CloseIO,
			WriteI, WriteS, WriteNl, WriteFlush,
			tFile, ReadOpen, ReadClose, EndOfFile, ReadNl, ReadC;
FROM Strings	IMPORT tString, AssignEmpty, Assign, Append, Concatenate,
			ReadL, WriteL, ArrayToString, StringToArray, IsInOrder,
			Length;
FROM Idents	IMPORT NoIdent, MakeIdent, GetString;
FROM Sets	IMPORT tSet, MakeSet, ReleaseSet, Include, Exclude, IsEmpty,
			Extract, Union, IsElement;
FROM Position	IMPORT NoPosition;
FROM Errors	IMPORT StoreMessages, WriteMessages, MessageI, Short, Long,
			Information, Restriction, Fatal, Message, Array;
FROM Scanner	IMPORT BeginFile, Attribute;
FROM Parser	IMPORT Parser;
FROM Tree	IMPORT NoTree, tTree, TreeRoot, HeapUsed, SourceFile,
			SourceFile2, Options, ErrorCount, QueryTree, ParserName,
			LarkLib, Prefix, Language, tLanguage, DrawTree;
FROM Semantic	IMPORT Semantics, Semantics2, TermCount, NontermCount, RuleCount;
FROM LR1	IMPORT InitialStates, CompLR0, CompPred, ReduceReduce, CompLR1,
			CompReachable1, OptimizeLR0, CompReachable2, CompGrammarClass,
			ReadReduceConflict, ReduceReduceConflict, PrintStates,
			PrintStatistics, StateCount, PrintRepairCount,
			LastLR0State, LastLR1State, ResetPred, ResetLookahead;
FROM LRk	IMPORT LimitK, CloseLRk;
FROM Conflict	IMPORT CheckConflicts1, CheckConflicts2;
FROM Explain	IMPORT ExplainFile;
FROM Compress	IMPORT RenumberStates, RenumberRules, CompContinuation,
			CompressNTable, CompressTTable, CompTDefaults, CompTDefaults2,
			CompNDefaults;
FROM Generate	IMPORT GenInterface, GenParser, GenDriver, GenEiffelSupport,
			CaseLabels, GenCSTreeFiles, parser_name, parser_no;
FROM LarkTime	IMPORT WriteStepTime;
FROM Delta	IMPORT ReadDelta, WriteDelta, ConflictFile, DeltaFile, MissingConflicts;

CONST
   DbgExt	= ".dbg";
   ConflictExt	= ".cft";
   DeltaExt	= ".dlt";

VAR
   String	,
   PathS	,
   PathT	: tString;
   Argument	,
   PathA	: ARRAY [0..255] OF CHAR;
   LastDot	,
   BaseNameIndex,
   i		: CARDINAL;
   f		: tFile;
   HasArgs	: BOOLEAN;
   EnvVarPtr	: tArrayChar;

PROCEDURE ScanArg (VAR Argument: ARRAY OF CHAR);
   VAR
      ch	: CHAR;
      i, i2, j	: CARDINAL;
   BEGIN
      j := 1;
      ch := Argument [0];
      REPEAT
	 IF ch = '-' THEN
	    ch := Argument [j]; INC (j);
	    IF ch = 'l' THEN
	       AssignEmpty (LarkLib);
	       LOOP
		  ch := Argument [j]; INC (j);
		  IF ORD (ch) <= ORD (' ') THEN EXIT; END;
		  Append (LarkLib, ch);
	       END;
	       Append (LarkLib, DirectorySeparator ());
	    ELSIF ch = 'f' THEN
	       Include (Options, ORD ('f'));
	       IF ORD (Argument [j]) > ORD ('A') THEN
		  AssignEmpty (Prefix);
		  LOOP
		     ch := Argument [j]; INC (j);
		     IF ORD (ch) <= ORD (' ') THEN EXIT; END;
		     Append (Prefix, ch);
		  END;
	       END;
	    ELSIF ch = 'k' THEN
	       IF ORD (Argument [j]) > ORD (' ') THEN
		  LimitK := 0;
		  LOOP
		     ch := Argument [j]; INC (j);
		     IF (ORD (ch) < ORD ('0')) OR (ORD ('9') < ORD (ch)) THEN EXIT; END;
		     LimitK := 10 * LimitK + ORD (ch) - ORD ('0');
		  END;
	       END;
	    ELSIF ch = 'n' THEN
	       Include (Options, ORD ('n'));
	       IF ORD (Argument [j]) > ORD (' ') THEN
		  CaseLabels := 0;
		  LOOP
		     ch := Argument [j]; INC (j);
		     IF (ORD (ch) < ORD ('0')) OR (ORD ('9') < ORD (ch)) THEN EXIT; END;
		     CaseLabels := 10 * CaseLabels + ORD (ch) - ORD ('0');
		  END;
	       END;
	    ELSIF ch = 'N' THEN
	       Include (Options, ORD ('N'));
	       ch := Argument [j]; INC (j);
	       i := 0;
	       WHILE ORD (ch) > ORD (' ') DO
		  parser_name [i] := ch; INC (i);
		  ch := Argument [j]; INC (j);
	       END;
	       parser_name [i] := 0C;
	    ELSIF ch = 'O' THEN
	       Include (Options, ORD ('O'));
	       IF ORD (Argument [j]) > ORD (' ') THEN
		  parser_no := 0;
		  LOOP
		     ch := Argument [j]; INC (j);
		     IF (ORD (ch) < ORD ('0')) OR (ORD ('9') < ORD (ch)) THEN EXIT; END;
		     parser_no := 10 * parser_no + ORD (ch) - ORD ('0');
		  END;
	       END;
	    ELSE
	       WHILE ORD (ch) > ORD (' ') DO
		  IF ch = '?' THEN
		     Include (Options, ORD ('h'));
		  ELSE
		     Include (Options, ORD (ch));
		     HasArgs := TRUE;
		  END;
		  ch := Argument [j]; INC (j);
	       END;
	    END;
	 ELSIF ch = '?' THEN
	    Include (Options, ORD ('h'));
	 ELSIF ORD (ch) > ORD (' ') THEN
	    i := 0; i2 := 0;
	    REPEAT
	       SourceFile [i] := ch; INC (i);
	       SourceFile2 [i2] := ch; INC (i2);
	       IF ch = '\' THEN SourceFile2 [i2] := '\'; INC (i2); END;
	       ch := Argument [j]; INC (j);
	    UNTIL ORD (ch) <= ORD (' ');
	    SourceFile [i] := 0C;
	    SourceFile2 [i2] := 0C;
	 ELSIF ch # 0C THEN
	    ch := Argument [j]; INC (j);
	 END;
      UNTIL ch = 0C;
   END ScanArg;

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
      Assign		(PathS, LarkLib);
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
   HasArgs := FALSE;
   AssignEmpty (LarkLib);
   ArrayToString ("t_", Prefix);
   SourceFile [0] := 0C;
   SourceFile2 [0] := 0C;

   EnvVarPtr := GetEnvVar ("LARK");
   IF EnvVarPtr # NIL THEN
      i := 0;
      LOOP
	 Argument [i] := EnvVarPtr^ [i];
	 IF (Argument [i] = 0C) OR (i = 255) THEN EXIT; END;
	 INC (i);
      END;
      ScanArg (Argument);
   END;

   FOR i := 1 TO GetArgCount () - 1 DO
      GetArgument (i, Argument); ScanArg (Argument);
   END;

   IF NOT HasArgs THEN				(* {} -> a		*)
      Include (Options, ORD ('a'));
   END;

   IF IsElement (ORD ('a'), Options) THEN	(* a -> {d, i, p}	*)
      Include (Options, ORD ('d'));
      Include (Options, ORD ('i'));
      Include (Options, ORD ('p'));
   END;

   IF IsElement (ORD ('e'), Options) THEN	(* e -> o		*)
      Include (Options, ORD ('o'));
      Exclude (Options, ORD ('6'));
   END;

   IF IsElement (ORD ('v'), Options) THEN	(* v -> {w, U} *)
      Include (Options, ORD ('w'));
      Include (Options, ORD ('U'));
   END;

   IF IsElement (ORD ('w'), Options) THEN	(* w -> {V, W, X} *)
      Include (Options, ORD ('V'));
      Include (Options, ORD ('W'));
      Include (Options, ORD ('X'));
   END;

   IF IsElement (ORD ('U'), Options) OR		(* {U, V, W, X} -> | *)
      IsElement (ORD ('V'), Options) OR
      IsElement (ORD ('W'), Options) OR
      IsElement (ORD ('X'), Options) THEN
      Include (Options, ORD ('|'));
   END;

   IF IsElement (ORD ('A'), Options) THEN	(* A -> y		*)
      Include (Options, ORD ('y'));
   END;

   IF IsElement (ORD ('P'), Options) THEN	(* P -> {x, z}		*)
      Include (Options, ORD ('x'));
      Include (Options, ORD ('z'));
   END;

   IF IsElement (ORD ('T'), Options) THEN	(* T -> t		*)
      Include (Options, ORD ('t'));
   END;

   IF IsElement (ORD ('5'), Options) THEN	(* 5 -> - C		*)
      Exclude (Options, ORD ('C'));
   END;

   IF IsElement (ORD ('N'), Options) THEN	(* N -> O		*)
      Include (Options, ORD ('O'));
   END;

   IF IsElement (ORD ('O'), Options) THEN	(* O -> 4		*)
      Include (Options, ORD ('4'));
   END;

   IF IsElement (ORD ('4'), Options) THEN	(* 4 -> n		*)
      Include (Options, ORD ('n'));
   END;

   IF IsElement (ORD ('h'), Options) THEN
      Exclude (Options, ORD ('h'));
      f := StdOutput;
      !!
      !usage: lark [-options] [-l<directory>] [<file>]!
      !!
      ! c generate C         source code!
      ! + generate C++       source code!
      ! j generate Java      source code!
      ! m generate Modula-2  source code (default)!
      ! 3 generate Ada       source code!
      ! e generate Eiffel 3  source code!
   (* ! f generate support classes for Eiffel! *)
      !!
      ! a generate all = -dip (default)!
      ! d generate header file or definition module!
      ! i generate implementation part or module!
      ! p generate main program to be used as test driver!
      ! 5 generate parser with graphical visualization!
      ! -f[<prefix>] generate constant declarations for tokens in header file!
      !   using prefix (default: t_)!
      ! g generate # line directives!
      ! : generate lines not longer than 80 characters!
      ! J report undefined tokens and multiply defined nonterminals as error (default: warning)!
      ! 2 suppress reporting of multiply defined nonterminals!
      ! s suppress informations and warnings!
      ! r suppress elimination of LR(0) reductions!
      ! u use fast and large    terminal tables  (default: slow and small)!
      ! o use fast and large nonterminal tables  (default: slow and small)!
      ! 4 use tables to decrement stack pointers (default: inline code)!
      ! 6 use alternate algorithm for table compression!
      ! b memorize previous trial parses and avoid repetition of same trial parses!
      ! v explain all LR conflicts in file with suffix .dbg!
      ! w explain implicitly and dynamically repaired conflicts, only!
      ! D explain new conflicts, only - old conflicts are read from file with suffix .cft!
      !   current set of conflicts is written to new version of this file!
      !   differences between previous and current runs are written to file with suffix .dlt!
      ! h print help information!
      !!
      ! n reduce the number of case labels in switch, case, or inspect statements!
      !   by mapping so-called shift-reduce states to reduce states!
      !   (increases run time a little bit but decreases code size,!
      !   might be necessary due to compiler restrictions)!
      !!
      ! -n<mmm> generate switch or case statements with at most mmm case labels!
      !       (might be necessary due to compiler restrictions)!
      !!
      ! t print statistics about the generated parser!
      ! x print a list of terminals and their encoding!
      ! y print a readable version of the generated automaton (states and items)!
      ! z print a list of nonterminals and rules!
      ! 0 construct an LALR(1) parser (based on an LR(0) automaton) (default)!
      ! 1 construct an   LR(1) parser (based on an LR(1) automaton)!
      !01 construct an LALR(1) parser and extend it locally to LR(1) where necessary!
   (* ! -k<n> specify maximal value of k for LR(k) analysis (default: 1)! *)
      ! -k2 construct an LALR(2) parser (which uses 2 tokens lookahead) (default: 1)!
      ! 7 touch output files only if necessary!
      ! 8 report storage consumption!
      ! -l<dir> specify the directory dir where lark finds its data files!
   (* ! , used for TrialParse! *)
   (* ! ; used for ReParse! *)
   (* ! & used for GetLookahead! *)
   (* ! . used for yacc! *)
   (* ! % used for evaluation version! *)
   (* ! | used for explain! *)
      WriteFlush (StdOutput);
   END;

   IF IsElement (ORD ('H'), Options) THEN
      Exclude (Options, ORD ('H'));
      f := StdOutput;
      !!
      ! A print full automaton (invalid states, PRED, defaults, etc.)!
      ! B print full automaton before CheckConflicts1!
      ! P print full symbol info (PATH, LS, etc.)!
      ! L print info about lane trace algorithm!
      ! Q or q browse internal data structure with text browser!
      ! G browse internal data structure with graphical browser!
      ! R print step-time!
      ! S print messages (do not store)!
      ! T print full statistics!
      ! U explain explicitly  repaired conflicts!
      ! V explain implicitly  repaired conflicts!
      ! W explain LALR(2)     repaired conflicts!
      ! X explain dynamically repaired conflicts!
      ! Y print a list of terminals and their encoding!
      ! Z print a list of nonterminals and rules!
      ! E disable LR1(k) analysis!
      ! F disable LR(k)  analysis!
      ! C disable generation of comments and rules!
      ! N<name> specify parser name   for concrete syntax tree!
      ! O<nnn>  specify parser number for concrete syntax tree (default: 1)!
      WriteFlush (StdOutput);
   END;

   IF IsEmpty (Options) THEN CloseIO; rExit (0); END;

      IF Length (LarkLib) = 0 THEN
	 EnvVarPtr := GetEnvVar ("CT_DIR");
	 IF EnvVarPtr # NIL THEN
	    i := 0;
	    LOOP
	       Argument [i] := EnvVarPtr^ [i];
	       IF (Argument [i] = 0C) OR (i = 255) THEN EXIT; END;
	       INC (i);
	    END;
	    ArrayToString (Argument, LarkLib);
	    Append (LarkLib, DirectorySeparator ());
	    ArrayToString ("lib", String);
	    Concatenate	(LarkLib, String);
	    Append (LarkLib, DirectorySeparator ());
	    ArrayToString ("lark", String);
	    Concatenate	(LarkLib, String);
	    Append (LarkLib, DirectorySeparator ());
	 END;
      END;

      (* Include (Options, ORD ('%')); *)
	 IF IsElement (ORD ('+'), Options) THEN Language := Cpp;
      ELSIF IsElement (ORD ('c'), Options) THEN Language := C;
      ELSIF IsElement (ORD ('e'), Options) THEN Language := Eiffel;
      ELSIF IsElement (ORD ('3'), Options) THEN Language := Ada;
      ELSIF IsElement (ORD ('j'), Options) THEN Language := Java;
      ELSE Exclude (Options, ORD ('6'));	Language := Modula2;
      END;

      StoreMessages (NOT IsElement (ORD ('S'), Options));
      Attribute.Position := NoPosition;
      IF SourceFile [0] # 0C THEN
	 BeginFile (SourceFile);
	 ArrayToString (SourceFile, String);
      ELSE
	 ArrayToString ("-", String);
      END;
      Attribute.Position.File := MakeIdent (String);
      INC (ErrorCount, Parser ()); WriteStepTime ("CompParser	");
      Semantics	(TreeRoot); WriteStepTime ("CompSemantics	");
      WriteMessages (StdError);

      IF ErrorCount > 0 THEN CloseIO; rExit (1); END;
      StoreMessages (FALSE);
      IF NOT CheckLicense ("lark", TermCount + NontermCount + RuleCount) THEN
	 CloseIO; rExit (1); END;
      StoreMessages (NOT IsElement (ORD ('S'), Options));
      InitialStates;

   IF IsElement (ORD ('0'), Options) AND IsElement (ORD ('1'), Options) THEN
      Exclude (Options, ORD ('0'));
      Exclude (Options, ORD ('1'));
   ELSIF NOT IsElement (ORD ('0'), Options) AND NOT IsElement (ORD ('1'), Options) THEN
      Include (Options, ORD ('0'));
   END;

   IF IsElement (ORD ('1'), Options) THEN
      CompLR1;		WriteStepTime ("CompLR1		");
      IF IsElement (ORD ('|'), Options) THEN
	 CompPred;	WriteStepTime ("CompPred	");
      END;
   ELSIF IsElement (ORD ('0'), Options) THEN
      CompLR0;		WriteStepTime ("CompLR0		");
      CompPred;		WriteStepTime ("CompPred	");
   ELSE
      CompLR0;		WriteStepTime ("CompLR0		");
      CompPred;		WriteStepTime ("CompPred	");
      ReduceReduce;	WriteStepTime ("CompReduce	");
      CompLR1;		WriteStepTime ("CompLR1		");
      CompReachable1;	WriteStepTime ("CompReachable1	");
      IF LastLR0State < LastLR1State THEN
	 ResetLookahead;
	 ResetPred;
	 CompPred;	WriteStepTime ("CompPred	");
      END;
   END;

   IF IsElement (ORD ('B'), Options) THEN PrintStates; END;
      CheckConflicts1;	WriteStepTime ("CompConflicts1	");
      OptimizeLR0;	WriteStepTime ("CompOptimizeLR0	");
      CompReachable2;	WriteStepTime ("CompReachable2	");
      Semantics2 (TreeRoot);
      RenumberStates;
      RenumberRules;
      CompContinuation;

   IF IsElement (ORD ('q'), Options) OR IsElement (ORD ('Q'), Options) THEN
      QueryTree		(TreeRoot);
   END;

   IF IsElement (ORD ('G'), Options) THEN
      DrawTree		(TreeRoot);
   END;

   IF IsElement (ORD ('|'), Options) THEN
      IF SourceFile [0] # 0C THEN
	 BaseNameIndex := 0;		(* skip dirname, look for basename *)
	 i := 0;
	 WHILE SourceFile [i] # 0C DO
	    IF (SourceFile [i] = '/') OR (SourceFile [i] = '\') THEN
	       BaseNameIndex := i + 1;
	    END;
	    INC (i);
	 END;
	 LastDot := 9999;
	 i := 0;
	 LOOP
	    PathA [i] := SourceFile [BaseNameIndex];
	    IF PathA [i] = 0C THEN EXIT; END;
	    IF PathA [i] = '.' THEN LastDot := i; END;
	    INC (i);
	    INC (BaseNameIndex);
	 END;
	 IF LastDot # 9999 THEN i := LastDot; END;
	 PathA [i] := 0C;
	 ArrayToString	(PathA, PathS);
      ELSIF ParserName = NoIdent THEN
	 ArrayToString	("Parser", PathS);
      ELSE
	 GetString	(ParserName, PathS);
      END;
      Assign		(PathT, PathS);

      ArrayToString	(DbgExt, String);
      Concatenate	(PathS, String);
      StringToArray	(PathS, PathA);
      ExplainFile := WriteOpen (PathA);
      IF ExplainFile < 0 THEN
	 MessageI ("can not open file", Fatal, NoPosition, Array, ADR (PathA));
      END;

   IF IsElement (ORD ('D'), Options) THEN
      Assign		(PathS, PathT);
      ArrayToString	(DeltaExt, String);
      Concatenate	(PathS, String);
      StringToArray	(PathS, PathA);
      DeltaFile := WriteOpen (PathA);
      IF DeltaFile < 0 THEN
	 MessageI ("can not open file", Fatal, NoPosition, Array, ADR (PathA));
      END;

      Assign		(PathS, PathT);
      ArrayToString	(ConflictExt, String);
      Concatenate	(PathS, String);
      StringToArray	(PathS, PathA);
      ConflictFile := ReadOpen (PathA);
      IF ConflictFile >= 0 THEN
	 ReadDelta	;
	 ReadClose	(ConflictFile);
      END;

      ConflictFile := WriteOpen (PathA);
      IF ConflictFile < 0 THEN
	 MessageI ("can not open file", Fatal, NoPosition, Array, ADR (PathA));
      END;
      WriteDelta	(TreeRoot); WriteStepTime ("CompDelta	");
   END;
      CheckConflicts2	; WriteStepTime ("CompConflicts2	");
      CloseLRk		;
      WriteClose	(ExplainFile);
   IF IsElement (ORD ('D'), Options) THEN
      MissingConflicts	;
      WriteClose	(DeltaFile);
      WriteClose	(ConflictFile);
   END;
   ELSE
      CloseLRk		;
   END;
   IF IsElement (ORD ('i'), Options) THEN
   IF IsElement (ORD ('6'), Options) THEN
      CompTDefaults2;	WriteStepTime ("CompTDefaults	");
   ELSE
      CompTDefaults;	WriteStepTime ("CompTDefaults	");
   END;
      CompressTTable;	WriteStepTime ("CompressTTable	");
      CompNDefaults;	WriteStepTime ("CompNDefaults	");
      CompressNTable;	WriteStepTime ("CompressNTable	");
   END;
   IF IsElement (ORD ('y'), Options) THEN
      PrintStates;
   END;
(*
   IF NOT IsElement (ORD ('s'), Options) THEN
      IF ReadReduceConflict	> 0 THEN
	 MessageI ("shift  reduce conflicts", Information, NoPosition, Short, ADR (ReadReduceConflict));
      END;
      IF ReduceReduceConflict	> 0 THEN
	 MessageI ("reduce reduce conflicts", Information, NoPosition, Short, ADR (ReduceReduceConflict));
      END;
   END;
*)
      CompGrammarClass;
   IF IsElement (ORD ('d'), Options) AND (Language # Java) THEN
      GenInterface;
   END;
   IF IsElement (ORD ('i'), Options) THEN
      GenParser;	WriteStepTime ("CompGenParser	");
   END;
   IF IsElement (ORD ('p'), Options) THEN
      GenDriver;
   END;
(*
   IF IsElement (ORD ('f'), Options) THEN
      GenEiffelSupport;
   END;
*)
   IF IsElement (ORD ('O'), Options) THEN
      GenCSTreeFiles;
   END;

   WriteMessages (StdError);
   PrintRepairCount;
   IF IsElement (ORD ('t'), Options) THEN
      PrintStatistics;
   END;
   IF IsElement (ORD ('8'), Options) AND NOT IsElement (ORD ('s'), Options) THEN
      MessageI ("memory used", Information, NoPosition, Long, ADR (MemoryUsed));
      MessageI ("heap   used", Information, NoPosition, Long, ADR (HeapUsed));
   END;
   CloseIO;
   IF ErrorCount > 0 THEN rExit (1); ELSE rExit (0); END;
END lark.
