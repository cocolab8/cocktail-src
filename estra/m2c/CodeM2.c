#include "SYSTEM_.h"

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

#ifndef DEFINITION_Automaton
#include "Automaton.h"
#endif

#ifndef DEFINITION_Checks
#include "Checks.h"
#endif

#ifndef DEFINITION_Characte
#include "Characte.h"
#endif

#ifndef DEFINITION_Environs
#include "Environs.h"
#endif

#ifndef DEFINITION_Grammar
#include "Grammar.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Match
#include "Match.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_StringM
#include "StringM.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Types
#include "Types.h"
#endif

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

#ifndef DEFINITION_CodeM2
#include "CodeM2.h"
#endif


static CHAR Z220 [] = "/dev/null";
static CHAR Z221 [] = ".md";
static CHAR Z222 [] = ".mi";
static CHAR Z223 [] = ".tab";
#define Z224	1
#define Z225	32
static ZfM_3 Z226;
static INTEGER Z227;
static Zfb3DLQ_0 Z228;
static void Z232 ARGS ((Zq0A4_58 Z234));
static void Z235 ARGS ((Zfb3DLQ_0 Z236));
struct S_2 {
CHAR A[128 + 1];
};
static void Z233 ARGS ((Zq0A4_58 Z234));
static void Z248 ARGS ((Zfb3DLQ_0 Z236));
struct S_1 {
CHAR A[128 + 1];
};
static void Z262 ARGS ((Zq0A4_58 Z234));
static void Z266 ARGS ((Zq0A4_58 Z234));
static BOOLEAN Z271 ARGS ((ZpmCQ_4 Z270, Zfb3DLQ_0 Z268));
static void Z272 ARGS ((Zfb3DLQ_0 Z268));
static void Z273 ARGS ((Zq0A4_58 Z234, Zfb3DLQ_0 Z268, ZpmCQ_4 Z270));
static void Z283 ARGS ((Zq0A4_58 Z285, Zfb3DLQ_0 Z268, INTEGER Z282, INTEGER Z286));
static void Z274 ARGS ((Zq0A4_58 Z234, Zfb3DLQ_0 Z268, ZpmCQ_4 Z290));
static void Z293 ARGS ((Zq0A4_58 Z234, Zfb3DLQ_0 Z236, BOOLEAN Z291, INTEGER Z282));
static void Z294 ARGS ((Zq0A4_58 Z234, Zfb3DLQ_0 Z236, BOOLEAN Z291));
static void Z260 ARGS ((Zq0A4_58 Z234));
static void Z297 ARGS ((Zq0A4_58 Z234, Zq0A4_58 Z245));
static void Z288 ARGS ((Zq0A4_58 Z234, INTEGER Z286));
static void Z301 ARGS ((Zq0A4_58 Z245, INTEGER Z308));
static void Z259 ARGS ((Zq0A4_58 Z234));
static void Z309 ARGS ((Zq0A4_58 Z245));
static void Z258 ARGS ((Zq0A4_58 Z234));
static void Z310 ARGS ((Zq0A4_58 Z245));
static void Z261 ARGS ((Zq0A4_58 Z234));
static void Z311 ARGS ((Zq0A4_58 Z245));
static void Z238 ARGS ((Zq0A4_58 Z234));
static void Z240 ARGS ((Zq0A4_58 Z234));
static void Z298 ARGS ((Zq0A4_58 Z245, INTEGER Z308));
static void Z237 ARGS ((void));

void ZggD3g4_0
 ARGS ((void))
{
Z228 = ZmfDOBA_0->U_1.V_4.Y3.Y3;
if (ZehCfg728_2) {
Z232(ZmfDOBA_0);
}
if (ZehCfg728_3) {
Z233(ZmfDOBA_0);
}
}

static void Z232
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
{
register Zq0A4_78 *W_1 = &Z234->U_1.V_4.Y3;

Z235(W_1->Y1);
Z237();
ZfM_29(Z226, (STRING)"(*", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	\"", 4L);
Zfb3DLQ_7(Z226, W_1->Y1);
ZfM_29(Z226, (STRING)".md\"", 4L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	generated with estra/", 24L);
ZfM_29(Z226, ZehCfg728_0, 4L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	from \"", 9L);
ZfM_29(Z226, ZehCfg728_5.A, 256L);
ZfM_29(Z226, (STRING)"\"", 1L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	estra ", 9L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	was written by Bertram Vielsack in june 1989", 47L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *)", 3L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"DEFINITION MODULE ", 18L);
Zfb3DLQ_7(Z226, W_1->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IMPORT ", 7L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z238(W_1->Y5);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE Begin", 15L);
Zfb3DLQ_7(Z226, W_1->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z240(ZmfDOBA_0);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE Close", 15L);
Zfb3DLQ_7(Z226, W_1->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END ", 4L);
Zfb3DLQ_7(Z226, W_1->Y1);
ZfM_29(Z226, (STRING)".", 1L);
ZfM_33(Z226);
ZfM_21(Z226);
}
}

static void Z235
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z236)
# else
(Z236)
Zfb3DLQ_0 Z236;
# endif
{
Zp1PEAFD_2 Z241;
struct S_2 Z242;

if (Z236 == Zpky9FDA_39) {
(void) strncpy ((char *)Z242.A, (char *)Z220, sizeof (Z242.A));
} else {
Zfb3DLQ_3(Z236, &Z241);
Zp1PEAFD_6(&Z241, '\0');
Zp1PEAFD_14(&Z241, Z242.A, 129L);
Zgg3DDyAC_4(Z242.A, 129L, Z221, 3L);
}
Z226 = ZfM_20(Z242.A, 129L);
Zgg728H_2(&Z226, Z242.A, 129L);
}

static void Z233
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
ZpmCQ_4 Z243;
Zfb3DLQ_0 Z244;
Zq0A4_58 Z245, Z246;
INTEGER Z247;

{
register Zq0A4_78 *W_2 = &Z234->U_1.V_4.Y3;

Z248(W_2->Y1);
Z237();
ZfM_29(Z226, (STRING)"(*", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	\"", 4L);
Zfb3DLQ_7(Z226, W_2->Y1);
ZfM_29(Z226, (STRING)".mi\"", 4L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	generated with estra/", 24L);
ZfM_29(Z226, ZehCfg728_0, 4L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	from \"", 9L);
ZfM_29(Z226, ZehCfg728_5.A, 256L);
ZfM_29(Z226, (STRING)"\"", 1L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	estra ", 9L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *	was written by Bertram Vielsack in june 1989", 47L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" *)", 3L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IMPLEMENTATION MODULE ", 22L);
Zfb3DLQ_7(Z226, W_2->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"IMPORT SYSTEM, IO, rMemory, Pack, ", 34L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
} else {
Z237();
ZfM_29(Z226, (STRING)"IMPORT SYSTEM, IO, rMemory, ", 28L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
}
Z237();
ZfM_33(Z226);
if (ZehCfg728_10) {
Z237();
ZfM_29(Z226, (STRING)"IMPORT Times;", 13L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}
Z238(W_2->Y6);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"CONST", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyInfinite = ", 15L);
ZfM_25(Z226, (MAX_LONGINT - Zpky9FDA_42) / ZbhNIEKGK_19(), 1L);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyBitsPerBitset = 32;", 23L);
ZfM_33(Z226);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"  yySetSize = ", 14L);
ZfM_25(Z226, ZbhNIEKGK_8(), 1L);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyMaxIndex = ", 15L);
ZfM_25(Z226, ZjcFA5_0, 1L);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyCombSize = ", 15L);
ZfM_25(Z226, ZjcFA5_1, 1L);
ZfM_29(Z226, (STRING)";      ", 7L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyStartState = 0;", 19L);
ZfM_33(Z226);
} else {
ZpmCQ_5(&Z243, (LONGCARD)Zpky9FDA_40);
Zq7SFB_11(&Z243);
while (!ZpmCQ_26(Z243)) {
Z244 = ZpmCQ_20(&Z243);
Z237();
ZfM_29(Z226, (STRING)"  yyC", 5L);
Zfb3DLQ_7(Z226, Z244);
ZfM_29(Z226, (STRING)" = ", 3L);
ZfM_25(Z226, Zq7SFB_8(Z244), 1L);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
}
ZpmCQ_7(&Z243);
Z237();
ZfM_29(Z226, (STRING)"  yyMaxClass = ", 15L);
ZfM_25(Z226, Zq7SFB_9(), 1L);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
}
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyPoolSize = 10240;", 21L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"TYPE", 4L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yytBlockPtr = POINTER TO yytBlock;", 36L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yytBlock =", 12L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  RECORD", 8L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    Successor: yytBlockPtr;", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    Block: ARRAY [1..yyPoolSize] OF CHAR;", 41L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END;", 6L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"  yyStateType = INTEGER;", 24L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yySetType = ARRAY [0..yySetSize DIV yyBitsPerBitset] OF BITSET;", 65L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yySetsType = ARRAY [0..yyMaxIndex] OF yySetType;", 50L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyCombType = ARRAY [0..yyCombSize] OF yyStateType;", 52L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}
Z245 = W_2->Y10;
INC(Z227);
while (Z245->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_3 = &Z245->U_1.V_19.Y18;

Z237();
ZfM_29(Z226, (STRING)"yyP", 3L);
Zfb3DLQ_7(Z226, W_3->Y1);
ZfM_29(Z226, (STRING)" = PROCEDURE (", 14L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".t", 2L);
Zfb3DLQ_7(Z226, Z228);
Z246 = W_3->Y3;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
{
register Zq0A4_90 *W_4 = &Z246->U_1.V_16.Y15;

ZfM_29(Z226, (STRING)", ", 2L);
if (W_4->Y3 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_4->Y3);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_4->Y5);
Z246 = W_4->Y7;
}
}
Z246 = W_3->Y4;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
{
register Zq0A4_90 *W_5 = &Z246->U_1.V_16.Y15;

ZfM_29(Z226, (STRING)", VAR ", 6L);
if (W_5->Y3 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_5->Y3);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_5->Y5);
ZfM_29(Z226, (STRING)" ", 1L);
Z246 = W_5->Y7;
}
}
Z246 = W_3->Y5;
if (Z246->U_1.V_1.Y0 == Zq0A4_24) {
{
register Zq0A4_96 *W_6 = &Z246->U_1.V_22.Y21;

ZfM_29(Z226, (STRING)"): ", 3L);
if (W_6->Y1 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_6->Y1);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_6->Y3);
ZfM_29(Z226, (STRING)";", 1L);
}
} else {
ZfM_29(Z226, (STRING)");", 2L);
}
ZfM_33(Z226);
Z245 = W_3->Y8;
}
}
Z237();
ZfM_33(Z226);
DEC(Z227);
Z245 = W_2->Y10;
Z237();
ZfM_29(Z226, (STRING)"  yyInfoPtr  = POINTER TO yyInfoType;", 37L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyInfoType =", 14L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    RECORD", 10L);
ZfM_33(Z226);
if (!ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"      yyClasses: ARRAY [0..yyMaxClass DIV yyBitsPerBitset] OF BITSET;", 69L);
ZfM_33(Z226);
}
while (Z245->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_7 = &Z245->U_1.V_19.Y18;

Z237();
ZfM_29(Z226, (STRING)"      ", 6L);
Zfb3DLQ_7(Z226, W_7->Y1);
ZfM_29(Z226, (STRING)": RECORD Cost: INTEGER; Proc: yyP", 33L);
Zfb3DLQ_7(Z226, W_7->Y1);
ZfM_29(Z226, (STRING)"; END;", 6L);
ZfM_33(Z226);
Z245 = W_7->Y8;
}
}
Z237();
ZfM_29(Z226, (STRING)"    END;", 8L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"VAR", 3L);
ZfM_33(Z226);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"  yySets: yySetsType;", 21L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyComb: yyCombType;", 21L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"  yyInfo: yyInfoType;", 21L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyMatch: ARRAY [0..", 21L);
ZfM_25(Z226, ZbhNIEKGK_8(), 1L);
ZfM_29(Z226, (STRING)"] OF BOOLEAN;", 13L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyBlockList: yytBlockPtr;", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyPoolFreePtr, yyPoolEndPtr: SYSTEM.ADDRESS;", 46L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
if (ZehCfg728_10) {
Z237();
ZfM_29(Z226, (STRING)"  yyTime, yyTime0, yyNodeCount: LONGINT;", 40L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}
if (!ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyClass (yyt: ", 24L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".t", 2L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_29(Z226, (STRING)"Bit, Set: INTEGER): BOOLEAN;", 28L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"VAR info: yyInfoPtr;", 20L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  info := yyt^.yyHead.yyEstraInfo;", 34L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  RETURN Bit IN info^.yyClasses [Set];", 38L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END yyClass;", 12L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyAlloc (): SYSTEM.ADDRESS;", 37L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"VAR BlockPtr: yytBlockPtr;", 26L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IF LONGINT (yyPoolEndPtr - yyPoolFreePtr) < SYSTEM.TSIZE (yyInfoType) THEN", 76L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    BlockPtr  := yyBlockList;", 29L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyBlockList  := rMemory.Alloc (SYSTEM.TSIZE (yytBlock));", 60L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyBlockList^.Successor := BlockPtr;", 39L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyPoolFreePtr := SYSTEM.ADR (yyBlockList^.Block);", 53L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyPoolEndPtr  := yyPoolFreePtr + yyPoolSize;", 48L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END;", 6L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  INC (yyPoolFreePtr, SYSTEM.ADDRESS (SYSTEM.TSIZE (yyInfoType)));", 66L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  RETURN yyPoolFreePtr - SYSTEM.ADDRESS (SYSTEM.TSIZE (yyInfoType));", 68L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END yyAlloc;", 12L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyReleaseHeap;", 24L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"VAR BlockPtr: yytBlockPtr;", 26L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  WHILE yyBlockList # NIL DO", 28L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    BlockPtr:= yyBlockList;", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyBlockList:= yyBlockList^.Successor;", 41L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    rMemory.Free (SYSTEM.TSIZE (yytBlock), BlockPtr);", 53L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END;", 6L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyPoolFreePtr:= NIL;", 22L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyPoolEndPtr:= NIL;", 21L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END yyReleaseHeap;", 18L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z258(W_2->Y10);
Z259(W_2->Y10);
Z260(W_2->Y10);
Z261(W_2->Y10);
Z262(W_2->Y10);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyErrorCheck (i: INTEGER; s1, s2: ARRAY OF CHAR);", 59L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IF i < 0 THEN", 15L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    IO.WriteS (IO.StdError, s1);", 32L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    IO.WriteS (IO.StdError, s2);", 32L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    IO.WriteNl (IO.StdError); IO.CloseIO; HALT;", 47L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END;", 6L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END yyErrorCheck;", 17L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"VAR yyunpackindex, yyunpackcount, yyunpackset: CARDINAL;", 56L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyIsElement (VAR Set: yySetType; Element: SHORTCARD): BOOLEAN;", 72L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  BEGIN", 7L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    RETURN Element MOD ", 23L);
ZfM_25(Z226, (LONGINT)Z225, 1L);
ZfM_29(Z226, (STRING)" IN Set [Element DIV ", 21L);
ZfM_25(Z226, (LONGINT)Z225, 1L);
ZfM_29(Z226, (STRING)"];", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END yyIsElement;", 18L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyInclElement (VAR Set: yySetType; Element: SHORTCARD);", 65L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  BEGIN", 7L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    INCL (Set [Element DIV ", 27L);
ZfM_25(Z226, (LONGINT)Z225, 1L);
ZfM_29(Z226, (STRING)"], Element MOD ", 15L);
ZfM_25(Z226, (LONGINT)Z225, 1L);
ZfM_29(Z226, (STRING)");", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END yyInclElement;", 20L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyExclElement (VAR Set: yySetType; Element: SHORTCARD);", 65L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  BEGIN", 7L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    EXCL (Set [Element DIV ", 27L);
ZfM_25(Z226, (LONGINT)Z225, 1L);
ZfM_29(Z226, (STRING)"], Element MOD ", 15L);
ZfM_25(Z226, (LONGINT)Z225, 1L);
ZfM_29(Z226, (STRING)");", 2L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END yyExclElement;", 20L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE UnpackSetsHandler (value: CARDINAL);", 46L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"VAR i	: CARDINAL;", 17L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IF yyunpackindex > yyunpackcount THEN", 39L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyunpackindex := 0;", 23L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    INC (yyunpackset);", 22L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END;", 6L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IF yyunpackindex = 0 THEN", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyunpackcount := value;", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    FOR i := 0 TO yySetSize DO", 30L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"      yyExclElement (yySets [yyunpackset], i);", 46L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    END;", 8L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  ELSE", 6L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"    yyInclElement (yySets [yyunpackset], value)", 47L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  END;", 6L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  INC (yyunpackindex);", 22L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END UnpackSetsHandler;      	", 29L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE UnpackCombHandler (value: INTEGER);", 45L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyComb [yyunpackindex] := value;", 34L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  INC (yyunpackindex);", 22L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END UnpackCombHandler;      	", 29L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE Begin", 15L);
Zfb3DLQ_7(Z226, W_2->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"VAR", 3L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  hc	: Pack.UnpackCardHandler;", 30L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  hi	: Pack.UnpackIntHandler;", 29L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
INC(Z227);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"yyunpackindex := 0; yyunpackcount := 0; yyunpackset := 0;", 57L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"hc := UnpackSetsHandler;", 24L);
ZfM_33(Z226);
ZjcFA5_3(Z226);
Z237();
ZfM_29(Z226, (STRING)"hi := UnpackCombHandler; yyunpackindex := 0;", 44L);
ZfM_33(Z226);
ZekSMF8FMG_4(Z226);
}
DEC(Z227);
Z238(W_2->Y7);
Z237();
ZfM_29(Z226, (STRING)"END Begin", 9L);
Zfb3DLQ_7(Z226, W_2->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z240(Z234);
{
register Zq0A4_93 *W_8 = &Z234->U_1.V_4.Y3.Y10->U_1.V_19.Y18;

if (W_8->Y5->U_1.V_1.Y0 == Zq0A4_24) {
{
register Zq0A4_96 *W_9 = &W_8->Y5->U_1.V_22.Y21;

Z237();
ZfM_29(Z226, (STRING)"VAR yyresult :", 14L);
if (W_9->Y1 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_9->Y1);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_9->Y3);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
}
}
}
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"VAR yystate: yyStateType;", 25L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
INC(Z227);
if (ZehCfg728_10) {
Z237();
ZfM_29(Z226, (STRING)"yyTime0 := Times.CpuTime ();", 28L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"yyNodeCount := 0;", 17L);
ZfM_33(Z226);
}
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"yystate := yyTraverse (yyt);", 28L);
ZfM_33(Z226);
} else {
Z237();
ZfM_29(Z226, (STRING)"yyTraverse (yyt);", 17L);
ZfM_33(Z226);
}
if (ZehCfg728_10) {
Z237();
ZfM_29(Z226, (STRING)"yyTime := Times.CpuTime ();", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"yyTime := yyTime - yyTime0;", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteI (IO.StdError, yyNodeCount, 1);", 40L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteS (IO.StdError, ' Nodes');", 34L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteNl (IO.StdError);", 25L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteI (IO.StdError, yyTime, 1);", 35L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteS (IO.StdError, ' msec to traverse');", 45L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteNl (IO.StdError);", 25L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IF yyTime > 0 THEN", 18L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IO.WriteI (IO.StdError, (yyNodeCount * 1000 + yyTime DIV 2) DIV yyTime, 1);", 77L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IO.WriteS (IO.StdError, ' Nodes per sec');", 44L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IO.WriteNl (IO.StdError);", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  IO.WriteNl (IO.StdError);", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END;", 4L);
ZfM_33(Z226);
}
if (Z234->U_1.V_4.Y3.Y10->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_10 = &Z234->U_1.V_4.Y3.Y10->U_1.V_19.Y18;

Z237();
if (W_10->Y5->U_1.V_1.Y0 == Zq0A4_24) {
ZfM_29(Z226, (STRING)"yyresult := ", 12L);
}
Zfb3DLQ_7(Z226, W_10->Y1);
ZfM_29(Z226, (STRING)" (yyt", 5L);
Z246 = W_10->Y3;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
ZfM_29(Z226, (STRING)", ", 2L);
Zfb3DLQ_7(Z226, Z246->U_1.V_16.Y15.Y1);
Z246 = Z246->U_1.V_16.Y15.Y7;
}
Z246 = W_10->Y4;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
ZfM_29(Z226, (STRING)", ", 2L);
Zfb3DLQ_7(Z226, Z246->U_1.V_16.Y15.Y1);
Z246 = Z246->U_1.V_16.Y15.Y7;
}
ZfM_29(Z226, (STRING)");", 2L);
ZfM_33(Z226);
}
}
if (ZehCfg728_10) {
Z237();
ZfM_29(Z226, (STRING)"yyTime0 := Times.CpuTime ();", 28L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"yyReleaseHeap;", 14L);
ZfM_33(Z226);
if (ZehCfg728_10) {
Z237();
ZfM_29(Z226, (STRING)"yyTime := Times.CpuTime ();", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"yyTime := yyTime - yyTime0;", 27L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteI (IO.StdError, yyTime, 1);", 35L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteS (IO.StdError, ' msec to release Heap');", 49L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteNl (IO.StdError);", 25L);
ZfM_33(Z226);
}
if (Z234->U_1.V_4.Y3.Y10->U_1.V_19.Y18.Y5->U_1.V_1.Y0 == Zq0A4_24) {
Z237();
ZfM_29(Z226, (STRING)"RETURN yyresult;", 16L);
ZfM_33(Z226);
}
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"END Do", 6L);
Zfb3DLQ_7(Z226, Z234->U_1.V_4.Y3.Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE Close", 15L);
Zfb3DLQ_7(Z226, W_2->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z238(W_2->Y8);
Z237();
ZfM_29(Z226, (STRING)"END Close", 9L);
Zfb3DLQ_7(Z226, W_2->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z245 = W_2->Y10;
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
INC(Z227);
Z237();
ZfM_29(Z226, (STRING)"WITH yyInfo DO", 14L);
ZfM_33(Z226);
INC(Z227);
if (!ZehCfg728_4) {
{
LONGINT B_1 = 0, B_2 = Zq7SFB_9() / Z225;

if (B_1 <= B_2)
for (Z247 = B_1;; Z247 += 1) {
Z237();
ZfM_29(Z226, (STRING)"yyClasses [", 11L);
ZfM_25(Z226, Z247, 1L);
ZfM_29(Z226, (STRING)"] := {};", 8L);
ZfM_33(Z226);
if (Z247 >= B_2) break;
}
}
}
while (Z245->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_11 = &Z245->U_1.V_19.Y18;

Z237();
Zfb3DLQ_7(Z226, W_11->Y1);
ZfM_29(Z226, (STRING)".Cost := yyInfinite;", 20L);
ZfM_33(Z226);
Z237();
Zfb3DLQ_7(Z226, W_11->Y1);
ZfM_29(Z226, (STRING)".Proc := yyE", 12L);
Zfb3DLQ_7(Z226, W_11->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z245 = W_11->Y8;
}
}
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"END;", 4L);
ZfM_33(Z226);
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"  yyBlockList:= NIL;", 20L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyPoolFreePtr:= NIL;", 22L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  yyPoolEndPtr:= NIL;", 21L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END ", 4L);
Zfb3DLQ_7(Z226, W_2->Y1);
ZfM_29(Z226, (STRING)".", 1L);
ZfM_33(Z226);
ZfM_21(Z226);
}
}

static void Z248
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z236)
# else
(Z236)
Zfb3DLQ_0 Z236;
# endif
{
Zp1PEAFD_2 Z241;
struct S_1 Z242;

if (Z236 == Zpky9FDA_39) {
(void) strncpy ((char *)Z242.A, (char *)Z220, sizeof (Z242.A));
} else {
Zfb3DLQ_3(Z236, &Z241);
Zp1PEAFD_6(&Z241, '\0');
Zp1PEAFD_14(&Z241, Z242.A, 129L);
Zgg3DDyAC_4(Z242.A, 129L, Z222, 3L);
}
Z226 = ZfM_20(Z242.A, 129L);
Zgg728H_2(&Z226, Z242.A, 129L);
}

static void Z262
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyTraverse (yyt: ", 27L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".t", 2L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)"): yyStateType;", 15L);
ZfM_33(Z226);
} else {
Z237();
ZfM_29(Z226, (STRING)"PROCEDURE yyTraverse (yyt: ", 27L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".t", 2L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)");", 2L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"VAR", 3L);
ZfM_33(Z226);
INC(Z227);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"state: yyStateType;", 19L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"match: POINTER TO yySetType;", 28L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"cost: INTEGER;", 14L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"info: yyInfoPtr;", 16L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"success: BOOLEAN;", 17L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
INC(Z227);
if (ZehCfg728_10) {
Z237();
ZfM_29(Z226, (STRING)"INC (yyNodeCount);", 18L);
ZfM_33(Z226);
}
Z237();
ZfM_29(Z226, (STRING)"info := yyAlloc ();", 19L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"info^ := yyInfo;", 16L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"yyt^.yyHead.yyEstraInfo := info;", 32L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"CASE yyt^.Kind OF", 17L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
Z266(Z234);
Z237();
ZfM_29(Z226, (STRING)"END;", 4L);
ZfM_33(Z226);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"RETURN state;", 13L);
ZfM_33(Z226);
}
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"END yyTraverse;", 15L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}

static void Z266
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
ZpmCQ_4 Z267;
Zfb3DLQ_0 Z268, Z264, Z244;
INTEGER Z269;
ZpmCQ_4 Z270;

ZpmCQ_5(&Z267, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z270, (LONGCARD)ZbhNIEKGK_8());
Zq7SFB_10(&Z267);
while (!ZpmCQ_26(Z267)) {
Z268 = ZpmCQ_20(&Z267);
Z244 = ZdnD8D8D_15(Z268);
if (Z244 != Zpky9FDA_39) {
Z264 = ZdnD8D8D_21(Z268);
Z237();
ZfM_29(Z226, (STRING)"| ", 2L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".", 1L);
Zfb3DLQ_7(Z226, Z264);
ZfM_29(Z226, (STRING)":", 1L);
ZfM_33(Z226);
INC1(Z227, 2);
if (ZehCfg728_4) {
Z237();
ZfM_29(Z226, (STRING)"state := ", 9L);
ZfM_25(Z226, ZekSMF8FMG_3((LONGINT)Z268), 1L);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
}
{
LONGINT B_3 = 1, B_4 = ZdnD8D8D_22(Z268);

if (B_3 <= B_4)
for (Z269 = B_3;; Z269 += 1) {
Z237();
if (ZehCfg728_4) {
ZfM_29(Z226, (STRING)"state := yyComb [state + ", 25L);
}
ZfM_29(Z226, (STRING)"yyTraverse (yyt^.", 17L);
Zfb3DLQ_7(Z226, Z264);
ZfM_29(Z226, (STRING)".", 1L);
Zfb3DLQ_7(Z226, ZdnD8D8D_23(Z268, Z269));
if (ZehCfg728_4) {
ZfM_29(Z226, (STRING)")];", 3L);
} else {
ZfM_29(Z226, (STRING)");", 2L);
}
ZfM_33(Z226);
if (Z269 >= B_4) break;
}
}
ZdnD8D8D_28(Z268, &Z270);
if (ZehCfg728_4) {
if (!Z271(Z270, Z268)) {
Z237();
ZfM_29(Z226, (STRING)"match := SYSTEM.ADR (yySets [state]);", 37L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}
} else {
Z272(Z268);
}
Z273(Z234, Z268, Z270);
Z274(Z234, Z268, Z270);
DEC1(Z227, 2);
}
}
ZpmCQ_7(&Z270);
ZpmCQ_7(&Z267);
}

static BOOLEAN Z271
# ifdef HAVE_ARGS
(ZpmCQ_4 Z270, Zfb3DLQ_0 Z268)
# else
(Z270, Z268)
ZpmCQ_4 Z270;
Zfb3DLQ_0 Z268;
# endif
{
Zfb3DLQ_0 Z247;

{
SHORTCARD B_5 = ZpmCQ_17(&Z270), B_6 = ZpmCQ_18(&Z270);

if (B_5 <= B_6)
for (Z247 = B_5;; Z247 += 1) {
if (ZpmCQ_25((LONGCARD)Z247, &Z270) && !ZbhNIEKGK_22((LONGINT)Z247, Z268)) {
return FALSE;
}
if (Z247 >= B_6) break;
}
}
return TRUE;
}

static void Z272
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z268)
# else
(Z268)
Zfb3DLQ_0 Z268;
# endif
{
ZpmCQ_4 Z275, Z267;
Zfb3DLQ_0 Z244;
INTEGER Z276, Z277;
ZdnD8D8D_0 Z278;

ZpmCQ_5(&Z275, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z267, (LONGCARD)Zpky9FDA_40);
ZdnD8D8D_10(Z268, &Z275);
while (!ZpmCQ_26(Z275)) {
Z244 = ZpmCQ_20(&Z275);
Z276 = ZdnD8D8D_22(Z268);
if (Z276 == 0 || Z244 == ZdnD8D8D_15(Z268)) {
for (;;) {
Z237();
ZfM_29(Z226, (STRING)"INCL (info^.yyClasses [yyC", 26L);
Zfb3DLQ_7(Z226, Z244);
ZfM_29(Z226, (STRING)" DIV yyBitsPerBitset], ", 23L);
ZfM_29(Z226, (STRING)"yyC", 3L);
Zfb3DLQ_7(Z226, Z244);
ZfM_29(Z226, (STRING)" MOD yyBitsPerBitset); ", 23L);
ZfM_33(Z226);
Z244 = ZdnD8D8D_11(Z244);
if (Z244 == Zpky9FDA_39) {
goto EXIT_1;
}
ZdnD8D8D_9(Z244, &Z267);
if (ZpmCQ_25((LONGCARD)Z268, &Z267)) {
goto EXIT_1;
}
} EXIT_1:;
} else {
Z278 = ZdnD8D8D_24(Z268, Z244);
if (Z278 != NIL) {
Z237();
ZfM_29(Z226, (STRING)"IF ", 3L);
{
LONGINT B_7 = 1, B_8 = Z276;

if (B_7 <= B_8)
for (Z277 = B_7;; Z277 += 1) {
if (Z277 != 1) {
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)" & ", 3L);
}
ZfM_29(Z226, (STRING)"yyClass (yyt^.", 14L);
Zfb3DLQ_7(Z226, ZdnD8D8D_21(Z268));
ZfM_29(Z226, (STRING)".", 1L);
Zfb3DLQ_7(Z226, ZdnD8D8D_23(Z268, Z277));
ZfM_29(Z226, (STRING)", ", 2L);
ZfM_29(Z226, (STRING)"yyC", 3L);
Zfb3DLQ_7(Z226, Z244);
ZfM_29(Z226, (STRING)" MOD yyBitsPerBitset, yyC", 25L);
Zfb3DLQ_7(Z226, Z244);
ZfM_29(Z226, (STRING)" DIV yyBitsPerBitset) ", 22L);
if (Z277 >= B_8) break;
}
}
ZfM_29(Z226, (STRING)"THEN", 4L);
ZfM_33(Z226);
INC(Z227);
for (;;) {
Z237();
ZfM_29(Z226, (STRING)"INCL (info^.yyClasses [yyC", 26L);
Zfb3DLQ_7(Z226, Z244);
ZfM_29(Z226, (STRING)" DIV yyBitsPerBitset], ", 23L);
ZfM_29(Z226, (STRING)"yyC", 3L);
Zfb3DLQ_7(Z226, Z244);
ZfM_29(Z226, (STRING)" MOD yyBitsPerBitset);", 22L);
ZfM_33(Z226);
Z244 = ZdnD8D8D_11(Z244);
if (Z244 == Zpky9FDA_39 || Z244 == ZdnD8D8D_15(Z268)) {
goto EXIT_2;
}
} EXIT_2:;
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"END;", 4L);
ZfM_33(Z226);
}
}
}
ZfM_33(Z226);
ZpmCQ_7(&Z267);
ZpmCQ_7(&Z275);
}

static void Z273
# ifdef HAVE_ARGS
(Zq0A4_58 Z234, Zfb3DLQ_0 Z268, ZpmCQ_4 Z270)
# else
(Z234, Z268, Z270)
Zq0A4_58 Z234;
Zfb3DLQ_0 Z268;
ZpmCQ_4 Z270;
# endif
{
Zq0A4_58 Z279;

while (Z234->U_1.V_1.Y0 == Zq0A4_21) {
Z279 = Z234->U_1.V_19.Y18.Y7;
while (Z279->U_1.V_1.Y0 == Zq0A4_30) {
{
register Zq0A4_102 *W_12 = &Z279->U_1.V_28.Y27;

if (W_12->Y7 && ZpmCQ_25((LONGCARD)W_12->Y8, &Z270)) {
if (ZbhNIEKGK_23(W_12->Y8) || !ZbhNIEKGK_22(W_12->Y8, Z268)) {
Z283(W_12->Y2, Z268, W_12->Y8, W_12->Y8);
}
}
Z279 = W_12->Y6;
}
}
Z234 = Z234->U_1.V_19.Y18.Y8;
}
ZfM_33(Z226);
}

static void Z283
# ifdef HAVE_ARGS
(Zq0A4_58 Z285, Zfb3DLQ_0 Z268, INTEGER Z282, INTEGER Z286)
# else
(Z285, Z268, Z282, Z286)
Zq0A4_58 Z285;
Zfb3DLQ_0 Z268;
INTEGER Z282;
INTEGER Z286;
# endif
{
BOOLEAN Z287;

Z237();
ZfM_29(Z226, (STRING)"yyMatch [", 9L);
ZfM_25(Z226, Z282, 1L);
ZfM_29(Z226, (STRING)"] := ", 5L);
if (ZbhNIEKGK_22(Z286, Z268)) {
ZfM_29(Z226, (STRING)"TRUE", 4L);
} else {
if (ZehCfg728_4) {
ZfM_29(Z226, (STRING)"(", 1L);
ZfM_25(Z226, Z282 % Z225, 1L);
ZfM_29(Z226, (STRING)" IN match^[", 11L);
ZfM_25(Z226, Z282 / Z225, 1L);
ZfM_29(Z226, (STRING)"])", 2L);
} else {
ZbhNIEKGK_24(Z226, Z286, Z227, Z228);
}
}
if (Z285->U_1.V_1.Y0 == Zq0A4_39) {
if (!ZehCfg728_4) {
ZfM_33(Z226);
Z237();
}
ZfM_29(Z226, (STRING)" & (", 4L);
Z288(Z285->U_1.V_37.Y36.Y1, Z286);
ZfM_29(Z226, (STRING)")", 1L);
}
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
}

static void Z274
# ifdef HAVE_ARGS
(Zq0A4_58 Z234, Zfb3DLQ_0 Z268, ZpmCQ_4 Z290)
# else
(Z234, Z268, Z290)
Zq0A4_58 Z234;
Zfb3DLQ_0 Z268;
ZpmCQ_4 Z290;
# endif
{
Zq0A4_58 Z246, Z279;
ZpmCQ_4 Z270;
BOOLEAN Z291;

Z291 = FALSE;
ZpmCQ_5(&Z270, (LONGCARD)ZbhNIEKGK_8());
ZpmCQ_30(&Z270, Z290);
Z246 = Z234;
while (Z246->U_1.V_1.Y0 == Zq0A4_21) {
Z279 = Z246->U_1.V_19.Y18.Y7;
while (Z279->U_1.V_1.Y0 == Zq0A4_30) {
{
register Zq0A4_102 *W_13 = &Z279->U_1.V_28.Y27;

if (W_13->Y7 && ZpmCQ_25((LONGCARD)W_13->Y8, &Z270) && !W_13->Y10) {
ZpmCQ_14(&Z270, (LONGCARD)W_13->Y8);
if (ZbhNIEKGK_23(W_13->Y8) || !ZbhNIEKGK_22(W_13->Y8, Z268)) {
Z293(Z279, Z246->U_1.V_19.Y18.Y1, Z291, W_13->Y8);
} else {
Z294(Z279, Z246->U_1.V_19.Y18.Y1, Z291);
}
Z237();
ZfM_33(Z226);
}
Z279 = W_13->Y6;
}
}
Z246 = Z246->U_1.V_19.Y18.Y8;
}
if (!ZpmCQ_26(Z270)) {
if (ZpmCQ_15(&Z270) > 1) {
Z237();
ZfM_29(Z226, (STRING)"REPEAT", 6L);
ZfM_33(Z226);
INC(Z227);
Z291 = TRUE;
Z237();
ZfM_29(Z226, (STRING)"success := FALSE;", 17L);
ZfM_33(Z226);
}
while (Z234->U_1.V_1.Y0 == Zq0A4_21) {
Z279 = Z234->U_1.V_19.Y18.Y7;
while (Z279->U_1.V_1.Y0 == Zq0A4_30) {
{
register Zq0A4_102 *W_14 = &Z279->U_1.V_28.Y27;

if (W_14->Y7 && ZpmCQ_25((LONGCARD)W_14->Y8, &Z270) && W_14->Y10) {
if (ZbhNIEKGK_23(W_14->Y8) || !ZbhNIEKGK_22(W_14->Y8, Z268)) {
Z293(Z279, Z234->U_1.V_19.Y18.Y1, Z291, W_14->Y8);
} else {
Z294(Z279, Z234->U_1.V_19.Y18.Y1, Z291);
}
Z237();
ZfM_33(Z226);
}
Z279 = W_14->Y6;
}
}
Z234 = Z234->U_1.V_19.Y18.Y8;
}
if (ZpmCQ_15(&Z270) > 1) {
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"UNTIL NOT success;", 18L);
ZfM_33(Z226);
}
}
ZpmCQ_7(&Z270);
}

static void Z293
# ifdef HAVE_ARGS
(Zq0A4_58 Z234, Zfb3DLQ_0 Z236, BOOLEAN Z291, INTEGER Z282)
# else
(Z234, Z236, Z291, Z282)
Zq0A4_58 Z234;
Zfb3DLQ_0 Z236;
BOOLEAN Z291;
INTEGER Z282;
# endif
{
Z237();
ZfM_29(Z226, (STRING)"IF yyMatch [", 12L);
ZfM_25(Z226, Z282, 1L);
ZfM_29(Z226, (STRING)"] THEN", 6L);
ZfM_33(Z226);
INC(Z227);
Z294(Z234, Z236, Z291);
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"END;", 4L);
ZfM_33(Z226);
}

static void Z294
# ifdef HAVE_ARGS
(Zq0A4_58 Z234, Zfb3DLQ_0 Z236, BOOLEAN Z291)
# else
(Z234, Z236, Z291)
Zq0A4_58 Z234;
Zfb3DLQ_0 Z236;
BOOLEAN Z291;
# endif
{
{
register Zq0A4_102 *W_15 = &Z234->U_1.V_28.Y27;

Z237();
ZfM_29(Z226, (STRING)"cost := ", 8L);
switch (W_15->Y3->U_1.V_1.Y0) {
case Zq0A4_41:;
ZfM_25(Z226, (LONGINT)Z224, 1L);
ZbhNIEKGK_25(Z226, W_15->Y8, Z227);
break;
case Zq0A4_42:;
ZfM_25(Z226, W_15->Y3->U_1.V_40.Y39.Y1, 1L);
ZbhNIEKGK_25(Z226, W_15->Y8, Z227);
break;
case Zq0A4_43:;
Z288(W_15->Y3->U_1.V_41.Y40.Y1, W_15->Y8);
break;
}
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IF cost < info^.", 16L);
Zfb3DLQ_7(Z226, Z236);
ZfM_29(Z226, (STRING)".Cost THEN", 10L);
ZfM_33(Z226);
INC(Z227);
Z237();
ZfM_29(Z226, (STRING)"info^.", 6L);
Zfb3DLQ_7(Z226, Z236);
ZfM_29(Z226, (STRING)".Cost := cost;", 14L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"info^.", 6L);
Zfb3DLQ_7(Z226, Z236);
ZfM_29(Z226, (STRING)".Proc := yyF", 12L);
ZfM_25(Z226, W_15->Y8, 1L);
Zfb3DLQ_7(Z226, Z236);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
if (Z291) {
Z237();
ZfM_29(Z226, (STRING)"success := TRUE;", 16L);
ZfM_33(Z226);
}
DEC(Z227);
Z237();
ZfM_29(Z226, (STRING)"END;", 4L);
ZfM_33(Z226);
}
}

static void Z260
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
while (Z234->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_16 = &Z234->U_1.V_19.Y18;

Z297(W_16->Y7, Z234);
Z234 = W_16->Y8;
}
}
}

static void Z297
# ifdef HAVE_ARGS
(Zq0A4_58 Z234, Zq0A4_58 Z245)
# else
(Z234, Z245)
Zq0A4_58 Z234;
Zq0A4_58 Z245;
# endif
{
while (Z234->U_1.V_1.Y0 == Zq0A4_30) {
{
register Zq0A4_102 *W_17 = &Z234->U_1.V_28.Y27;

if (W_17->Y7) {
Z298(Z245, W_17->Y8);
Z238(W_17->Y4);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
Z288(W_17->Y5, W_17->Y8);
ZfM_33(Z226);
Z301(Z245, W_17->Y8);
}
Z234 = W_17->Y6;
}
}
}

static void Z288
# ifdef HAVE_ARGS
(Zq0A4_58 Z234, INTEGER Z286)
# else
(Z234, Z286)
Zq0A4_58 Z234;
INTEGER Z286;
# endif
{
if (Z234->U_1.V_1.Y0 != Zq0A4_56) {
Z237();
ZfM_29(Z226, (STRING)"    (* line ", 12L);
ZfM_25(Z226, (LONGINT)Z234->U_1.V_42.Y41.Y1.Y0, 1L);
ZfM_29(Z226, (STRING)" ", 1L);
ZfM_29(Z226, ZehCfg728_5.A, 256L);
ZfM_29(Z226, (STRING)" *)", 3L);
ZfM_33(Z226);
}
for (;;) {
switch (Z234->U_1.V_1.Y0) {
case Zq0A4_45:;
switch (Z234->U_1.V_43.Y42.Y4) {
case Zq0A4_207:;
Zfb3DLQ_7(Z226, Z234->U_1.V_43.Y42.Y2);
break;
case Zq0A4_208:;
ZbhNIEKGK_21(Z226, Z286, Z234->U_1.V_43.Y42.Y2);
break;
case Zq0A4_209:;
ZbhNIEKGK_20(Z226, Z286, Z234->U_1.V_43.Y42.Y2);
break;
}
Z234 = Z234->U_1.V_43.Y42.Y3;
break;
case Zq0A4_46:;
switch (Z234->U_1.V_44.Y43.Y4) {
case Zq0A4_207:;
Zfb3DLQ_7(Z226, Z234->U_1.V_44.Y43.Y2);
break;
case Zq0A4_208:;
ZbhNIEKGK_21(Z226, Z286, Z234->U_1.V_44.Y43.Y2);
break;
case Zq0A4_209:;
ZbhNIEKGK_20(Z226, Z286, Z234->U_1.V_44.Y43.Y2);
break;
}
Z234 = Z234->U_1.V_44.Y43.Y3;
break;
case Zq0A4_47:;
ZfM_29(Z226, (STRING)".", 1L);
Z234 = Z234->U_1.V_45.Y44.Y2;
break;
case Zq0A4_48:;
ZfM_29(Z226, (STRING)",", 1L);
Z234 = Z234->U_1.V_45.Y44.Y2;
break;
case Zq0A4_49:;
ZfM_29(Z226, (STRING)"(", 1L);
Z234 = Z234->U_1.V_47.Y46.Y2;
break;
case Zq0A4_50:;
ZfM_29(Z226, (STRING)")", 1L);
Z234 = Z234->U_1.V_48.Y47.Y2;
break;
case Zq0A4_51:;
ZfM_29(Z226, (STRING)"{", 1L);
Z234 = Z234->U_1.V_49.Y48.Y2;
break;
case Zq0A4_52:;
ZfM_29(Z226, (STRING)"}", 1L);
Z234 = Z234->U_1.V_50.Y49.Y2;
break;
case Zq0A4_53:;
Zp1PEAFi_6(Z226, Z234->U_1.V_51.Y50.Y2);
Z234 = Z234->U_1.V_51.Y50.Y3;
break;
case Zq0A4_54:;
Zp1PEAFi_6(Z226, Z234->U_1.V_52.Y51.Y2);
Z234 = Z234->U_1.V_52.Y51.Y3;
break;
case Zq0A4_55:;
Zp1PEAFi_6(Z226, Z234->U_1.V_53.Y52.Y2);
Z234 = Z234->U_1.V_53.Y52.Y3;
break;
case Zq0A4_56:;
goto EXIT_3;
break;
}
} EXIT_3:;
}

static void Z301
# ifdef HAVE_ARGS
(Zq0A4_58 Z245, INTEGER Z308)
# else
(Z245, Z308)
Zq0A4_58 Z245;
INTEGER Z308;
# endif
{
{
register Zq0A4_93 *W_18 = &Z245->U_1.V_19.Y18;

if (Z308 > 0) {
Z237();
ZfM_29(Z226, (STRING)"END yyF", 7L);
ZfM_25(Z226, Z308, 1L);
Zfb3DLQ_7(Z226, W_18->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
} else if (Z308 == -1) {
Z237();
ZfM_29(Z226, (STRING)"END yyE", 7L);
Zfb3DLQ_7(Z226, W_18->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
} else {
Z237();
ZfM_29(Z226, (STRING)"END ", 4L);
Zfb3DLQ_7(Z226, W_18->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
}
Z237();
ZfM_33(Z226);
}
}

static void Z259
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
while (Z234->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_19 = &Z234->U_1.V_19.Y18;

Z309(Z234);
Z234 = W_19->Y8;
}
}
}

static void Z309
# ifdef HAVE_ARGS
(Zq0A4_58 Z245)
# else
(Z245)
Zq0A4_58 Z245;
# endif
{
{
register Zq0A4_93 *W_20 = &Z245->U_1.V_19.Y18;

Z298(Z245, -1L);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
INC(Z227);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteS (IO.StdError, 'Function ", 34L);
Zfb3DLQ_7(Z226, W_20->Y1);
ZfM_29(Z226, (STRING)" is not defined for this tree');", 32L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"IO.WriteNl (IO.StdError); IO.CloseIO; HALT;", 43L);
ZfM_33(Z226);
DEC(Z227);
Z301(Z245, -1L);
}
}

static void Z258
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
while (Z234->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_21 = &Z234->U_1.V_19.Y18;

Z310(Z234);
Z234 = W_21->Y8;
}
}
}

static void Z310
# ifdef HAVE_ARGS
(Zq0A4_58 Z245)
# else
(Z245)
Zq0A4_58 Z245;
# endif
{
Zq0A4_58 Z246;

{
register Zq0A4_93 *W_22 = &Z245->U_1.V_19.Y18;

Z298(Z245, 0L);
Z237();
ZfM_29(Z226, (STRING)"VAR InfoPtr: yyInfoPtr;", 23L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
INC(Z227);
Z237();
ZfM_29(Z226, (STRING)"InfoPtr := yyInfoPtr (yyt^.yyHead.yyEstraInfo);", 47L);
ZfM_33(Z226);
Z237();
if (W_22->Y5->U_1.V_1.Y0 == Zq0A4_24) {
ZfM_29(Z226, (STRING)"RETURN ", 7L);
}
ZfM_29(Z226, (STRING)"InfoPtr^.", 9L);
Zfb3DLQ_7(Z226, W_22->Y1);
ZfM_29(Z226, (STRING)".Proc (yyt", 10L);
Z246 = W_22->Y3;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
ZfM_29(Z226, (STRING)", ", 2L);
Zfb3DLQ_7(Z226, Z246->U_1.V_16.Y15.Y1);
Z246 = Z246->U_1.V_16.Y15.Y7;
}
Z246 = W_22->Y4;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
ZfM_29(Z226, (STRING)", ", 2L);
Zfb3DLQ_7(Z226, Z246->U_1.V_16.Y15.Y1);
Z246 = Z246->U_1.V_16.Y15.Y7;
}
ZfM_29(Z226, (STRING)");", 2L);
ZfM_33(Z226);
DEC(Z227);
Z301(Z245, 0L);
}
}

static void Z261
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
while (Z234->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_23 = &Z234->U_1.V_19.Y18;

Z311(Z234);
Z234 = W_23->Y8;
}
}
}

static void Z311
# ifdef HAVE_ARGS
(Zq0A4_58 Z245)
# else
(Z245)
Zq0A4_58 Z245;
# endif
{
{
register Zq0A4_93 *W_24 = &Z245->U_1.V_19.Y18;

Z237();
ZfM_29(Z226, (STRING)"PROCEDURE Cost", 14L);
Zfb3DLQ_7(Z226, W_24->Y1);
ZfM_29(Z226, (STRING)" (yyt: ", 7L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".t", 2L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)"): INTEGER;", 11L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"VAR", 3L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  InfoPtr: yyInfoPtr;", 21L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"BEGIN", 5L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  InfoPtr := yyt^.yyHead.yyEstraInfo;", 37L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"  RETURN InfoPtr^.", 18L);
Zfb3DLQ_7(Z226, W_24->Y1);
ZfM_29(Z226, (STRING)".Cost;", 6L);
ZfM_33(Z226);
Z237();
ZfM_29(Z226, (STRING)"END Cost", 8L);
Zfb3DLQ_7(Z226, W_24->Y1);
ZfM_29(Z226, (STRING)";", 1L);
ZfM_33(Z226);
Z237();
ZfM_33(Z226);
}
}

static void Z238
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
if (Z234->U_1.V_1.Y0 != Zq0A4_56) {
Z237();
ZfM_29(Z226, (STRING)"    (* line ", 12L);
ZfM_25(Z226, (LONGINT)Z234->U_1.V_42.Y41.Y1.Y0, 1L);
ZfM_29(Z226, (STRING)" ", 1L);
ZfM_29(Z226, ZehCfg728_5.A, 256L);
ZfM_29(Z226, (STRING)" *)", 3L);
ZfM_33(Z226);
}
for (;;) {
switch (Z234->U_1.V_1.Y0) {
case Zq0A4_45:;
Zfb3DLQ_7(Z226, Z234->U_1.V_43.Y42.Y2);
Z234 = Z234->U_1.V_43.Y42.Y3;
break;
case Zq0A4_46:;
Zfb3DLQ_7(Z226, Z234->U_1.V_44.Y43.Y2);
Z234 = Z234->U_1.V_44.Y43.Y3;
break;
case Zq0A4_47:;
ZfM_29(Z226, (STRING)".", 1L);
Z234 = Z234->U_1.V_45.Y44.Y2;
break;
case Zq0A4_48:;
ZfM_29(Z226, (STRING)",", 1L);
Z234 = Z234->U_1.V_46.Y45.Y2;
break;
case Zq0A4_49:;
ZfM_29(Z226, (STRING)"(", 1L);
Z234 = Z234->U_1.V_47.Y46.Y2;
break;
case Zq0A4_50:;
ZfM_29(Z226, (STRING)")", 1L);
Z234 = Z234->U_1.V_48.Y47.Y2;
break;
case Zq0A4_51:;
ZfM_29(Z226, (STRING)"{", 1L);
Z234 = Z234->U_1.V_49.Y48.Y2;
break;
case Zq0A4_52:;
ZfM_29(Z226, (STRING)"}", 1L);
Z234 = Z234->U_1.V_50.Y49.Y2;
break;
case Zq0A4_53:;
Zp1PEAFi_6(Z226, Z234->U_1.V_51.Y50.Y2);
Z234 = Z234->U_1.V_51.Y50.Y3;
break;
case Zq0A4_54:;
Zp1PEAFi_6(Z226, Z234->U_1.V_52.Y51.Y2);
Z234 = Z234->U_1.V_52.Y51.Y3;
break;
case Zq0A4_55:;
Zp1PEAFi_6(Z226, Z234->U_1.V_53.Y52.Y2);
Z234 = Z234->U_1.V_53.Y52.Y3;
break;
case Zq0A4_56:;
ZfM_33(Z226);
goto EXIT_4;
break;
}
} EXIT_4:;
}

static void Z240
# ifdef HAVE_ARGS
(Zq0A4_58 Z234)
# else
(Z234)
Zq0A4_58 Z234;
# endif
{
Zq0A4_58 Z246;

Z237();
ZfM_29(Z226, (STRING)"PROCEDURE Do", 12L);
Zfb3DLQ_7(Z226, Z234->U_1.V_4.Y3.Y1);
ZfM_29(Z226, (STRING)" (yyt: ", 7L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".t", 2L);
Zfb3DLQ_7(Z226, Z228);
if (Z234->U_1.V_4.Y3.Y10->U_1.V_1.Y0 == Zq0A4_21) {
{
register Zq0A4_93 *W_25 = &Z234->U_1.V_4.Y3.Y10->U_1.V_19.Y18;

Z246 = W_25->Y3;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
{
register Zq0A4_90 *W_26 = &Z246->U_1.V_16.Y15;

ZfM_29(Z226, (STRING)";", 1L);
Zfb3DLQ_7(Z226, W_26->Y1);
ZfM_29(Z226, (STRING)":", 1L);
if (W_26->Y3 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_26->Y3);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_26->Y5);
Z246 = W_26->Y7;
}
}
Z246 = W_25->Y4;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
{
register Zq0A4_90 *W_27 = &Z246->U_1.V_16.Y15;

ZfM_29(Z226, (STRING)"; VAR ", 6L);
Zfb3DLQ_7(Z226, W_27->Y1);
ZfM_29(Z226, (STRING)":", 1L);
ZfM_33(Z226);
if (W_27->Y3 != Zpky9FDA_39) {
Z237();
Zfb3DLQ_7(Z226, W_27->Y3);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_27->Y5);
Z246 = W_27->Y7;
}
}
Z246 = W_25->Y5;
if (Z246->U_1.V_1.Y0 == Zq0A4_24) {
{
register Zq0A4_96 *W_28 = &Z246->U_1.V_22.Y21;

ZfM_29(Z226, (STRING)"): ", 3L);
if (W_28->Y1 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_28->Y1);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_28->Y3);
ZfM_29(Z226, (STRING)";", 1L);
}
} else {
ZfM_29(Z226, (STRING)");", 2L);
}
ZfM_33(Z226);
}
}
}

static void Z298
# ifdef HAVE_ARGS
(Zq0A4_58 Z245, INTEGER Z308)
# else
(Z245, Z308)
Zq0A4_58 Z245;
INTEGER Z308;
# endif
{
Zq0A4_58 Z246;

{
register Zq0A4_93 *W_29 = &Z245->U_1.V_19.Y18;

ZfM_29(Z226, (STRING)"PROCEDURE ", 10L);
if (Z308 > 0) {
ZfM_29(Z226, (STRING)"yyF", 3L);
ZfM_25(Z226, Z308, 1L);
} else if (Z308 == -1) {
ZfM_29(Z226, (STRING)"yyE", 3L);
}
Zfb3DLQ_7(Z226, W_29->Y1);
Z237();
ZfM_29(Z226, (STRING)" (yyt: ", 7L);
Zfb3DLQ_7(Z226, Z228);
ZfM_29(Z226, (STRING)".t", 2L);
Zfb3DLQ_7(Z226, Z228);
Z246 = W_29->Y3;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
{
register Zq0A4_90 *W_30 = &Z246->U_1.V_16.Y15;

ZfM_29(Z226, (STRING)";", 1L);
Zfb3DLQ_7(Z226, W_30->Y1);
ZfM_29(Z226, (STRING)":", 1L);
if (W_30->Y3 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_30->Y3);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_30->Y5);
Z246 = W_30->Y7;
}
}
Z246 = W_29->Y4;
while (Z246->U_1.V_1.Y0 == Zq0A4_18) {
{
register Zq0A4_90 *W_31 = &Z246->U_1.V_16.Y15;

ZfM_29(Z226, (STRING)"; VAR ", 6L);
Zfb3DLQ_7(Z226, W_31->Y1);
ZfM_29(Z226, (STRING)":", 1L);
ZfM_33(Z226);
if (W_31->Y3 != Zpky9FDA_39) {
Z237();
Zfb3DLQ_7(Z226, W_31->Y3);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_31->Y5);
Z246 = W_31->Y7;
}
}
Z246 = W_29->Y5;
if (Z246->U_1.V_1.Y0 == Zq0A4_24) {
{
register Zq0A4_96 *W_32 = &Z246->U_1.V_22.Y21;

ZfM_29(Z226, (STRING)"): ", 3L);
if (W_32->Y1 != Zpky9FDA_39) {
Zfb3DLQ_7(Z226, W_32->Y1);
ZfM_29(Z226, (STRING)".", 1L);
}
Zfb3DLQ_7(Z226, W_32->Y3);
ZfM_29(Z226, (STRING)";", 1L);
}
} else {
ZfM_29(Z226, (STRING)");", 2L);
}
ZfM_33(Z226);
}
}

static void Z237
 ARGS ((void))
{
INTEGER Z247;

{
LONGINT B_9 = 1, B_10 = Z227;

if (B_9 <= B_10)
for (Z247 = B_9;; Z247 += 1) {
ZfM_29(Z226, (STRING)"  ", 2L);
if (Z247 >= B_10) break;
}
}
}

void BEGIN_CodeM2 ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_ArgCheck ();
BEGIN_Automaton ();
BEGIN_Checks ();
BEGIN_Characte ();
BEGIN_Environs ();
BEGIN_Grammar ();
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Match ();
BEGIN_Parser ();
BEGIN_Scanner ();
BEGIN_Sets ();
BEGIN_StringM ();
BEGIN_Strings ();
BEGIN_Tree ();
BEGIN_Types ();
BEGIN_ArgCheck ();

Z227 = 0;
}
