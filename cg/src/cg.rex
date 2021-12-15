/* Ich, Doktor Josef Grosch, Informatiker, 20.3.1989 */

EXPORT  {

FROM StringM	IMPORT tStringRef;
FROM Idents	IMPORT tIdent	;
FROM Texts	IMPORT tText	;
FROM Position	IMPORT tPosition;

TYPE
   tScanAttribute = RECORD
	   Position	: tPosition	;
      CASE : INTEGER OF
      | 1: StringRef	: tStringRef	;
      | 2: Ident	: tIdent	;
      | 3: Integer	: INTEGER	;
      | 4: Text		: tText		;
	   FileName	: tIdent	;
      END;
   END;

VAR CurArg, ArgCount	: INTEGER;
    InRules		: BOOLEAN;

PROCEDURE ErrorAttribute (Token: CARDINAL; VAR Attribute: tScanAttribute);
PROCEDURE StartExpr2	 ();
}

GLOBAL  {

FROM SYSTEM	IMPORT ADR;
FROM rSystem	IMPORT GetArgument;
FROM StringM	IMPORT PutString;
FROM Strings	IMPORT tString, Concatenate, Char, SubString, ArrayToString,
			StringToInt, AssignEmpty, Length, IntToString;
FROM Idents	IMPORT tIdent, MakeIdent, NoIdent, GetStringRef;
FROM Texts	IMPORT MakeText, Append;
FROM Tree	IMPORT Options, ErrorCount, SourceFile;
FROM Sets	IMPORT IsElement;
FROM Position	IMPORT tPosition;

IMPORT Errors, Idents;

CONST
   TokIdentifier	= 1;
   TokInteger		= 2;
   TokString		= 3;
   TokTargetCode	= 4;
   TokCode		= 5;
   TokWhiteSpace	= 6;

   TokLParent		= 10;	(* '('			*)
   TokRParent		= 11;	(* ')'			*)
   TokLBracket		= 12;	(* '['			*)
   TokRBracket		= 13;	(* ']'			*)
   TokLBrace		= 14;	(* '{'			*)
   TokRBrace		= 15;	(* '}'			*)
   TokComma		= 16;	(* ','			*)
   TokSemiColon		= 17;	(* ';'			*)
   TokDot		= 18;	(* '.'			*)
   TokColon		= 19;	(* ':'			*)
   TokEqual		= 20;	(* '='			*)
   TokAssign		= 21;	(* ':='			*)
   TokLAngle		= 22;	(* '<'			*)
   TokRAngle		= 23;	(* '>'			*)
   TokRArrow		= 24;	(* '->'			*)
   TokCopy		= 25;	(* ':-'			*)
   TokArrow		= 26;	(* '=>'			*)
   TokLArrow		= 27;	(* '<-'			*)
   TokQuestion		= 28;	(* '?'			*)
   TokDollar		= 29;	(* '$'			*)
   TokLUCBrace		= 30;	(* '{['			*)
   TokRUCBrace		= 31;	(* ']}'			*)
   TokMinus		= 32;	(* '-'			*)

   TokAfter		= 40;
   TokAndThen		= 41;
   TokBefore		= 42;
   TokBegin		= 43;
   TokCheck		= 44;
   TokClose		= 45;
   TokDeclare		= 46;
   TokEnd		= 47;
   TokEval		= 48;
   TokExport		= 49;
   TokFor		= 50;
   TokGlobal		= 51;
   TokIgnore		= 52;
   TokImport		= 53;
   TokIn		= 54;
   TokInh		= 55;
   TokInherited		= 56;
   TokInput		= 57;
   TokLeft		= 58;
   TokLocal		= 59;
   TokModule		= 60;
   TokNone		= 61;
   TokOut		= 62;
   TokOutput		= 63;
   TokParser		= 64;
   TokPrec		= 65;
   TokProperty		= 66;
   TokRemote		= 67;
   TokRev		= 68;
   TokReverse		= 69;
   TokRight		= 70;
   TokRule		= 71;
   TokScanner		= 72;
   TokSelect		= 73;
   TokStart		= 74;
   TokSubunit		= 75;
   TokSyn		= 76;
   TokSynthesized	= 77;
   TokThread		= 78;
   TokTree		= 79;
   TokView		= 80;
   TokVirtual		= 81;
   TokVoid		= 82;
(* TokDemand		= 28;
   TokFunction		= 6;
   TokStack		= 20; *)

PROCEDURE ErrorAttribute (Token: CARDINAL; VAR pAttribute: tScanAttribute);
   BEGIN
      WITH pAttribute DO
	 Position := Attribute.Position;
	 CASE Token OF
	 | TokIdentifier: Ident		:= NoIdent;
	 | TokInteger	: Integer	:= 0;
	 | TokTargetCode: MakeText (Text);
	 | TokString
	 , TokCode
	 , TokWhiteSpace: StringRef	:= GetStringRef (NoIdent);
	 ELSE
	 END;
      END;
   END ErrorAttribute;

PROCEDURE StartExpr2	 ();
   BEGIN
      yyStart (expr2);
      AssignEmpty (TargetCode);
   END StartExpr2;

PROCEDURE MakeDirective (VAR Result: tString; Line: CARDINAL; File: tIdent);
   VAR s: tString;

   PROCEDURE AppendS (VAR Result: tString; VAR In: ARRAY OF CHAR);
     BEGIN
       ArrayToString (In, s); Concatenate (Result, s);
     END AppendS;

   PROCEDURE AppendI (VAR Result: tString; In: INTEGER);
     BEGIN
       IntToString (In, s); Concatenate (Result, s);
     END AppendI;

   PROCEDURE AppendIdent (VAR Result: tString; In: tIdent);
     BEGIN
       Idents.GetString (In, s); Concatenate (Result, s);
     END AppendIdent;

   PROCEDURE AppendIdentEscaped (VAR Result: tString; Ident: tIdent);
      VAR
         i	: CARDINAL;
         ch	: CHAR;
      BEGIN
         Idents.GetString (Ident, s);
         FOR i := 1 TO Length (s) DO
	    ch := Char (s, i);
	    IF ch = '\' THEN Strings.Append (Result, ch); END;
	    Strings.Append (Result, ch);
         END;
      END AppendIdentEscaped;

   BEGIN
      IF IsElement (ORD ('z'), Options) THEN
	ArrayToString ("#@ line ", Result);
	IntToString (Line, s); Concatenate (Result, s);
	Strings.Append (Result, ' ');
	Strings.Append (Result, '"');
	Idents.GetString (File, s); Concatenate (Result, s);
	Strings.Append (Result, '"');
      ELSE
	Strings.AssignEmpty (Result);
	IF IsElement (ORD ('*'), Options) OR
	  IsElement (ORD ('+'), Options) OR
	  IsElement (ORD ('c'), Options) THEN
	  IF IsElement (ORD ('6'), Options) THEN
	    AppendS (Result, "# line ");
	    AppendI (Result, Line);
	    AppendS (Result, ' "');
	    AppendIdentEscaped (Result, File);
	    Strings.Append (Result, '"');
	  ELSE
	    AppendS (Result, "/* line ");
	    AppendI (Result, Line);
	    AppendS (Result, ' "');
	    AppendIdent (Result, File);
	    AppendS (Result, '" */');
	  END;
	ELSIF IsElement (ORD ('J'), Options) THEN
	  AppendS (Result, "/* line ");
	  AppendI (Result, Line);
	  AppendS (Result, ' "');
	  AppendIdent (Result, File);
	  AppendS (Result, '" */');
	ELSE
	  AppendS (Result, "(* line ");
	  AppendI (Result, Line);
	  AppendS (Result, ' "');
	  AppendIdent (Result, File);
	  AppendS (Result, '" *)');
	END;
      END;
   END MakeDirective;

VAR
   NestingLevel	: INTEGER; ActPos, CmtPos, StrPos: tPosition;
   TargetCode	: tString;
}

LOCAL	{
VAR
   String, Word	: tString;
   Argument	: ARRAY [0..255] OF CHAR;
   j		: SHORTCARD;
   ch		: CHAR;
   LineNo	: LONGCARD;
}

BEGIN	{
   NestingLevel	:= 0;
   InRules	:= FALSE;
}

DEFAULT	{
   GetWord (Word);
   ch := Char (Word, 1);
   IF (' ' < ch) AND (ch <= '~') THEN
      Errors.MessageI ("illegal character", Errors.Error, Attribute.Position,
         Errors.String, ADR (Word));
   ELSE
      ArrayToString ("\", String);				(* vi " *)
      IntToString (ORD (ch), Word);
      Concatenate (String, Word);
      Errors.MessageI ("illegal character", Errors.Error, Attribute.Position,
         Errors.String, ADR (String));
   END;
   INC (ErrorCount);
}

EOF     {
   CASE yyStartState OF
   | targetcode	,
     expr	: Errors.Message ("unterminated target code", Errors.Error, ActPos);
		  INC (ErrorCount);

   | comment	: Errors.Message ("unterminated comment", Errors.Error, CmtPos);
		  INC (ErrorCount);

   | CStr1, CStr2,
     AStr1, AStr2,
     Str1, Str2	: Errors.Message ("unterminated string", Errors.Error, StrPos);
		  INC (ErrorCount);
   ELSE
   END;
   yyStart (STD);
   INC (CurArg);
   IF CurArg <= ArgCount THEN
      GetArgument (CurArg, Argument);
      j := 0;
      REPEAT
	 ch := Argument [j];
	 SourceFile [j] := ch;
	 INC (j);
      UNTIL ch = 0C;
      BeginFile (SourceFile);
      ArrayToString (SourceFile, String);
      Attribute.Position.File := MakeIdent (String);
   END;
}

DEFINE  letter  = {A-Z a-z _}	.
        digit   = {0-9}		.
	CmtCh   = - {*\t\n}	.
	StrCh1	= - {'\t\n\r}	.
	StrCh2	= - {"\t\n\r}	.
	CStrCh1	= - {'\t\n\r\\}	.
	CStrCh2	= - {"\t\n\r\\}	.
	AStrCh1	= {\ -&(-~}	.
	AStrCh2	= {\ !#-~}	.
	code	= - {{\}\t\n\r\\'"#} .
	anyExpr	= - {\ \\\t\n\r/'":;={\}a-zA-Z_} .

START	comment, Str1, Str2, CStr1, CStr2, AStr1, AStr2, targetcode, expr, expr2
	PPline

RULES

#targetcode#	"{"	: {
			   IF NestingLevel = 0 THEN
			      MakeText (Attribute.Text);
			      AssignEmpty (TargetCode);
			      ActPos := Attribute.Position;
			   ELSE
			      GetWord (Word);
			      Concatenate (TargetCode, Word);
			   END;
			   INC (NestingLevel);
			}

#targetcode#	"}"	:- {
			   DEC (NestingLevel);
			   IF NestingLevel = 0 THEN
			      yyStart (STD);
			      Append (Attribute.Text, TargetCode);
			      Attribute.Position.Line	:= ActPos.Line;
			      Attribute.Position.Column	:= ActPos.Column;
			      Attribute.FileName	:= ActPos.File;
			      IF TokenLength = 1 THEN
				 RETURN TokTargetCode;
			      ELSE
				 RETURN TokTargetCode;
			      END;
			   ELSE
			      GetWord (Word);
			      Concatenate (TargetCode, Word);
			   END;
			}

#targetcode#	code + | \# | \r :- {
			   IF NestingLevel > 0 THEN
			      GetWord (Word);
			      Concatenate (TargetCode, Word);
			   END;
			}

#targetcode#	\t	:- {
			   IF NestingLevel > 0 THEN
			      Strings.Append (TargetCode, 11C);
			   END;
			   yyTab;
			}

#targetcode#	\r ? \n	:- {
			   IF NestingLevel > 0 THEN
			      Append (Attribute.Text, TargetCode);
			      AssignEmpty (TargetCode);
			   END;
			   yyEol (0);
			}

#targetcode#	\\ / \r ? \n :- {
			   IF NestingLevel > 0 THEN
			      Strings.Append (TargetCode, '\');
			   END;
			}
#targetcode#	\\ ANY	:- {
			   IF NestingLevel > 0 THEN
			      GetWord (Word);
			      Strings.Append (TargetCode, Char (Word, 2));
			   END;
			}

#targetcode#	\\	:- {
			   IF NestingLevel > 0 THEN
			      Strings.Append (TargetCode, '\');
			   END;
			}

#STD, expr# "/*"	:  {yyStart (comment); CmtPos := Attribute.Position;}
#comment# "*/"		:- {yyPrevious;}
#comment# "*" | CmtCh +	:- {}

#STD, expr# "//" ANY *	:- {}

#STD# \f | \r | \26	:- {}

#STD# digit +		:  {GetWord (Word);
			   Attribute.Integer := StringToInt (Word);
			   RETURN TokInteger;}

#STD, expr, targetcode# ' :{GetWord (String);
			    StrPos := Attribute.Position;
			    IF IsElement (ORD ('c'), Options) THEN yyStart (CStr1);
			    ELSIF IsElement (ORD ('-'), Options) THEN yyStart (AStr1);
			    ELSE yyStart (Str1);
			    END;}

#STD, expr, targetcode# \":						// vi "
			   {GetWord (String);
			    StrPos := Attribute.Position;
			    IF IsElement (ORD ('c'), Options) THEN yyStart (CStr2);
			    ELSIF IsElement (ORD ('-'), Options) THEN yyStart (AStr2);
			    ELSE yyStart (Str2);
			    END;}

#Str1#	StrCh1 +	,
#Str2#	StrCh2 +	,
#CStr1#	CStrCh1 + | \\ ANY ? ,
#CStr2#	CStrCh2 + | \\ ANY ? ,
#AStr1# AStrCh1 +	,
#AStr2# AStrCh2 +	:- {GetWord (Word); Concatenate (String, Word);}

#CStr1, CStr2# \\ \r ? \n:-{Strings.Append (String, '\');
			    Strings.Append (String, 12C); yyEol (0);}

#Str1, CStr1, AStr1# '	,
#Str2, CStr2, AStr2# \"	:-						// vi "
			   {GetWord (Word); Concatenate (String, Word);
			    yyPrevious;
			    IF yyStartState = targetcode THEN
			       Concatenate (TargetCode, String);
			    ELSE
			       Attribute.StringRef := PutString (String);
			       RETURN TokString;
			    END;}

#Str1, Str2, CStr1, CStr2# \t :- {Strings.Append (String, 11C); yyTab;}

#Str1, Str2, CStr1, CStr2, AStr1, AStr2# \r ? \n :- {
			    Strings.Append (String, 12C);
			    yyEol (0); yyPrevious;
			    IF yyStartState = STD THEN
			       Errors.Message ("unterminated string", Errors.Error, Attribute.Position);
			       INC (ErrorCount);
			    END;
			    IF yyStartState = targetcode THEN
			       Concatenate (TargetCode, String);
			    ELSE
			       Attribute.StringRef := PutString (String);
			       RETURN TokString;
			    END;}

#Str1, Str2, CStr1, CStr2# \r :- {Strings.Append (String, 15C);}

#STD# "("		: {RETURN TokLParent		;}
#STD# ")"		: {RETURN TokRParent		;}
#STD# ","		: {RETURN TokComma		;}
#STD# "->"		: {RETURN TokRArrow		;}
#STD# "."		: {RETURN TokDot		;}
#STD# ":"		: {RETURN TokColon		;}
#STD# "<"		: {RETURN TokLAngle		;}
#STD# "<-"		: {RETURN TokLArrow		;}
#STD# "="		: {RETURN TokEqual		;}
#STD# ">"		: {RETURN TokRAngle		;}
#STD# "["		: {RETURN TokLBracket		;}
#STD# "]"		: {RETURN TokRBracket		;}
#STD# "?"		: {RETURN TokQuestion		;}
#STD# "-"		: {RETURN TokMinus		;}
#STD# "$"		: {RETURN TokDollar		;}
#STD# "{"		: {IF InRules THEN
			      yyStart (expr); INC (NestingLevel);
			      ActPos := Attribute.Position; RETURN TokLBrace;
			   END;
			   yyLess (0); yyStart (targetcode); }
#STD# "{["		: {yyStart (expr); INC (NestingLevel);
			   ActPos := Attribute.Position; RETURN TokLUCBrace;}

#expr# AFTER		: {RETURN TokAfter		;}
#expr# AND_THEN		: {RETURN TokAndThen		;}
#expr# BEFORE		: {RETURN TokBefore		;}
#expr# CHECK		: {RETURN TokCheck		;}
#expr# REMOTE		: {RETURN TokRemote		;}

#expr# AFTER	/ ":"	,
#expr# AND_THEN	/ ":"	,
#expr# BEFORE	/ ":"	,
#expr# CHECK	/ ":"	,
#expr# REMOTE	/ ":"	: {GetWord (Word);
	                   Attribute.Ident := MakeIdent (Word);
			   RETURN TokIdentifier;}

#expr# anyExpr * | \r	: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   RETURN TokCode;}

#STD, expr# ":="	: {IF NestingLevel <= 1 THEN
			      RETURN TokAssign;
			   ELSE
			      GetWord (Word);
			      Attribute.StringRef := PutString (Word);
			      RETURN TokCode;
			   END;}

#expr# ":-"		: {IF NestingLevel <= 1 THEN
			      RETURN TokCopy;
			   ELSE
			      GetWord (Word);
			      Attribute.StringRef := PutString (Word);
			      RETURN TokCode;
			   END;}

#expr# ";"		: {IF NestingLevel <= 1 THEN
			      RETURN TokSemiColon;
			   ELSE
			      GetWord (Word);
			      Attribute.StringRef := PutString (Word);
			      RETURN TokCode;
			   END;}

#expr# ":"		: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   RETURN TokColon;}

#expr# "=" ? "=>"	: {RETURN TokArrow;}

#expr# "{"		: {INC (NestingLevel);
			   IF NestingLevel <= 2 THEN
			      RETURN TokLBrace;
			   ELSE
			      GetWord (Word);
			      Attribute.StringRef := PutString (Word);
			      RETURN TokCode;
			   END;}

#expr# "}"		: {DEC (NestingLevel);
			   IF NestingLevel = 0 THEN yyStart (STD); END;
			   IF NestingLevel <= 1 THEN
			      RETURN TokRBrace;
			   ELSE
			      GetWord (Word);
			      Attribute.StringRef := PutString (Word);
			      RETURN TokCode;
			   END;}

#expr# "]}"		: {DEC (NestingLevel);
			   yyStart (STD);
			   RETURN TokRUCBrace		;}

#expr# "/"		: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   RETURN TokCode		;}

#expr# "="		: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   RETURN TokCode		;}

#expr# " " +		: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   RETURN TokWhiteSpace		;}

#expr# \n		: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   yyEol (0);
			   RETURN TokWhiteSpace		;}

#expr# \r \n		: {GetWord (Word);
			   SubString (Word, 2, 2, String);
			   Attribute.StringRef := PutString (String);
			   yyEol (0);
			   RETURN TokWhiteSpace		;}

#expr# \t		: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   yyTab;
			   RETURN TokWhiteSpace		;}

#expr# \\ ANY		: {GetWord (Word);
			   SubString (Word, 2, 2, String);
			   Attribute.StringRef := PutString (String);
			   RETURN TokCode		;}

#expr# \\ letter (letter | digit) *: {GetWord (Word);
			   SubString (Word, 2, Length (Word), String);
			   Attribute.StringRef := PutString (String);
			   RETURN TokCode		;}

#expr# \\ / \r \n	,
#expr# \\		: {GetWord (Word);
			   Attribute.StringRef := PutString (Word);
			   RETURN TokCode		;}

#expr2#	- {\t\n]}	: {GetWord (Word);
			   Concatenate (TargetCode, Word);}

#expr2#	\]		: {yyLess (0); yyStart (STD);
			   Attribute.StringRef := PutString (TargetCode);
			   RETURN TokCode		;}

#expr2#	\t		: {GetWord (Word);
			   Concatenate (TargetCode, Word);
			   yyTab;}

#expr2#	\r ? \n		: {GetWord (Word);
			   Concatenate (TargetCode, Word);
			   yyEol (0);}

#STD# BEGIN		: {RETURN TokBegin	;}
#STD# CLOSE		: {RETURN TokClose	;}
#STD# DECLARE		: {RETURN TokDeclare	;}
// #STD# DEMAND		: {RETURN TokDemand	;}
#STD# END		: {RETURN TokEnd	;}
#STD# EVAL		: {RETURN TokEval	;}
#STD# EXPORT		: {RETURN TokExport	;}
#STD# FOR		: {RETURN TokFor	;}
// #STD# FUNCTION	: {RETURN TokFunction	;}
#STD# GLOBAL		: {RETURN TokGlobal	;}
#STD# IGNORE		: {RETURN TokIgnore	;}
#STD# IMPORT		: {RETURN TokImport	;}
#STD# IN		: {RETURN TokIn		;}
#STD# INPUT		: {RETURN TokInput	;}
#STD# INH		: {RETURN TokInh	;}
#STD# INHERITED		: {RETURN TokInherited	;}
#STD# LEFT		: {RETURN TokLeft	;}
#STD# LOCAL		: {RETURN TokLocal	;}
#STD# MODULE		: {RETURN TokModule	;}
#STD# NONE		: {RETURN TokNone	;}
#STD# OUT		: {RETURN TokOut	;}
#STD# OUTPUT		: {RETURN TokOutput	;}
#STD# PARSER		: {RETURN TokParser	;}
#STD# PREC		: {RETURN TokPrec	;}
#STD# PROPERTY		: {RETURN TokProperty	;}
#STD# REV		: {RETURN TokRev	;}
#STD# REVERSE		: {RETURN TokReverse	;}
#STD# RIGHT		: {RETURN TokRight	;}
#STD# RULE		: {RETURN TokRule	;}
#STD# SCANNER		: {RETURN TokScanner	;}
#STD# SELECT		: {RETURN TokSelect	;}
// #STD# STACK		: {RETURN TokStack	;}
#STD# START		: {RETURN TokStart	;}
#STD# SUBUNIT		: {RETURN TokSubunit	;}
#STD# SYN		: {RETURN TokSyn	;}
#STD# SYNTHESIZED	: {RETURN TokSynthesized;}
#STD# THREAD		: {RETURN TokThread	;}
#STD# TREE		: {RETURN TokTree	;}
#STD# VIEW		: {RETURN TokView	;}
#STD# VOID		: {RETURN TokVoid	;}
#STD# VIRTUAL		: {RETURN TokVirtual	;}

#STD, expr# letter (letter | digit) *	: {GetWord (Word);
	                   Attribute.Ident := MakeIdent (Word);
			   RETURN TokIdentifier;}

#STD# \\ letter (letter | digit) *	: {GetWord (Word);
			   SubString (Word, 2, Length (Word), String);
	                   Attribute.Ident := MakeIdent (String);
			   RETURN TokIdentifier;}

// interpret #@ line directives

< "#@" " " * "line"	:-{ yyPush (PPline); }

#PPline# {0-9} +	:-{
			   GetWord (Word);
			   LineNo := StringToInt (Word);
			}

#PPline# \" -{\n"} + \"	:-{					(* vi " *)
			   GetWord (Word);
			   SubString (Word, 2, Length (Word) - 1, Word);
			   yyLineCount := LineNo - 1;
			   (* change line # only if there is a file name *)
			   (* -1 compensates for the following yyEol () *)
			   Attribute.Position.File := MakeIdent (Word);
			}

#PPline# \r ? \n	:-{
			   yyPop ();
			   yyEol (0);
			   CASE yyStartState OF
			   | targetcode:
			     MakeDirective (String, yyLineCount,
			       Attribute.Position.File);
			     Append (Attribute.Text, String);
			   ELSE
			   END;
			}
