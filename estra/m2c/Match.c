#include "SYSTEM_.h"

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

#ifndef DEFINITION_Automaton
#include "Automaton.h"
#endif

#ifndef DEFINITION_Characte
#include "Characte.h"
#endif

#ifndef DEFINITION_Convert
#include "Convert.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Environs
#include "Environs.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_General
#include "General.h"
#endif

#ifndef DEFINITION_Grammar
#include "Grammar.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

#ifndef DEFINITION_Patterns
#include "Patterns.h"
#endif

#ifndef DEFINITION_Queues
#include "Queues.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_Stack
#include "Stack.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_Types
#include "Types.h"
#endif

#ifndef DEFINITION_Pack
#include "Pack.h"
#endif

#ifndef DEFINITION_Patterns
#include "Patterns.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

#ifndef DEFINITION_Automaton
#include "Automaton.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Patterns
#include "Patterns.h"
#endif

#ifndef DEFINITION_Queues
#include "Queues.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_Match
#include "Match.h"
#endif

INTEGER ZjcFA5_0, ZjcFA5_1;

static CHAR Z226 [] = ".tab";
#define Z227	100
#define Z228	100
#define Z229	-1
#define Z230	32
typedef struct S_1 {
ZmfFRCAJK_3 Y0;
ZpmCQ_4 Y1;
struct S_7 {
INTEGER A[100 + 1];
} *Y2;
} Z231;
typedef struct S_2 {
ZpmCQ_4 Y0;
} Z235;
static struct S_3 {
Z231 A[1000 + 1];
} *Z237;
static LONGINT Z238, Z239;
static struct S_4 {
Z235 A[1000 + 1];
} *Z240;
static LONGINT Z241, Z242;
static struct S_5 {
ZpmCQ_4 A[100 + 1];
} *Z243;
static struct S_6 {
INTEGER A[1000 + 1];
} *Z244;
static LONGINT Z245;
static INTEGER Z246 ARGS ((ZmfFRCAJK_3 Z247, INTEGER Z248));
static BOOLEAN Z253 ARGS ((ZmfFRCAJK_3 Z247));
static void Z254 ARGS ((void));
static void Z255 ARGS ((void));
static void Z261 ARGS ((ZpmCQ_4 Z262));
static INTEGER Z263 ARGS ((ZpmCQ_4 Z262));
static BOOLEAN Z264 ARGS ((INTEGER Z265, INTEGER Z262));
static void Z266 ARGS ((void));
static void Z267 ARGS ((LONGINT Z268, ZpmCQ_4 *Z262));
static void Z277 ARGS ((ZDz6VQCC_4 Z278));
static void Z286 ARGS ((void));
static void Z289 ARGS ((Zfb3DLQ_0 Z288));
static void Z293 ARGS ((INTEGER Z258, INTEGER Z290, ZdnD8D8D_0 Z292));
static void Z294 ARGS ((Zfb3DLQ_0 Z288, ZpmCQ_4 Z262, INTEGER Z258, INTEGER Z290, Zn0DDDB_4 *Z291, ZdnD8D8D_0 Z292));
static void Z302 ARGS ((Zfb3DLQ_0 Z288, Zn0DDDB_4 *Z291, ZpmCQ_4 Z262));
static BOOLEAN Z301 ARGS ((Zfb3DLQ_0 Z288, ZdnD8D8D_0 Z292, Zn0DDDB_4 Z291, Zfb3DLQ_0 Z295));
static void Z310 ARGS ((void));
static void Z311 ARGS ((void));
static void Z317 ARGS ((Zfb3DLQ_0 Z288, Zn0DDDB_4 Z291, ZpmCQ_4 Z262));

static INTEGER Z246
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z247, INTEGER Z248)
# else
(Z247, Z248)
ZmfFRCAJK_3 Z247;
INTEGER Z248;
# endif
{
LONGINT Z249;
LONGINT Z250;
Zfb3DLQ_0 Z251;

{
LONGINT B_1 = 0, B_2 = Z239;

if (B_1 <= B_2)
for (Z249 = B_1;; Z249 += 1) {
if (ZmfFRCAJK_14(Z247, Z237->A[Z249].Y0)) {
if (Z248 != Z229) {
ZpmCQ_13(&Z237->A[Z249].Y1, (LONGCARD)Z248);
}
return Z249;
}
if (Z249 >= B_2) break;
}
}
INC(Z239);
if (Z238 == 0) {
Z238 = Z227;
ZarQdhNDD_0((ADDRESS *)&Z237, &Z238, (LONGINT)sizeof (Z231));
} else if (Z239 == Z238) {
ZarQdhNDD_2((ADDRESS *)&Z237, &Z238, (LONGINT)sizeof (Z231));
}
{
register Z231 *W_1 = &Z237->A[Z239];

W_1->Y0 = Z247;
ZpmCQ_5(&W_1->Y1, (LONGCARD)ZbhNIEKGK_8());
if (Z248 != Z229) {
ZpmCQ_13(&W_1->Y1, (LONGCARD)Z248);
}
if (Z247 == NIL) {
W_1->Y2 = NIL;
} else {
Z251 = ZmfFRCAJK_10(Z247);
if (Zq7SFB_2(Z251) == Zq7SFB_19) {
Z250 = ZdnD8D8D_22(Z251) + 1;
ZarQdhNDD_0((ADDRESS *)&W_1->Y2, &Z250, (LONGINT)sizeof (INTEGER));
} else {
W_1->Y2 = NIL;
Z244->A[Z251] = Z239;
}
}
}
return Z239;
}

static BOOLEAN Z253
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z247)
# else
(Z247)
ZmfFRCAJK_3 Z247;
# endif
{
LONGINT Z249;

{
LONGINT B_3 = 0, B_4 = Z239;

if (B_3 <= B_4)
for (Z249 = B_3;; Z249 += 1) {
if (ZmfFRCAJK_14(Z247, Z237->A[Z249].Y0)) {
return TRUE;
}
if (Z249 >= B_4) break;
}
}
return FALSE;
}

static void Z254
 ARGS ((void))
{
INTEGER Z248;
INTEGER Z249;

if (ZbhNIEKGK_8() == 0) {
Z249 = Z246((ZmfFRCAJK_3)NIL, (LONGINT)Z229);
} else {
{
LONGINT B_5 = 1, B_6 = ZbhNIEKGK_8();

if (B_5 <= B_6)
for (Z248 = B_5;; Z248 += 1) {
Z249 = Z246(ZbhNIEKGK_11(Z248), Z248);
if (Z248 >= B_6) break;
}
}
}
}

static void Z255
 ARGS ((void))
{
LONGINT Z249, Z256;
Zfb3DLQ_0 Z257;
INTEGER Z258;
ZmfFRCAJK_3 Z247, Z259;
Zp1Fy8_2 Z260;

Z249 = -1;
Zp1Fy8_3(&Z260);
while (Z249 < Z239) {
INC(Z249);
Z247 = Z237->A[Z249].Y0;
if (Z247 != NIL) {
Z257 = ZmfFRCAJK_10(Z247);
if (Zq7SFB_2(Z257) == Zq7SFB_19) {
{
LONGINT B_7 = 1, B_8 = ZdnD8D8D_22(Z257);

if (B_7 <= B_8)
for (Z258 = B_7;; Z258 += 1) {
Z259 = ZmfFRCAJK_9(Z247, Z258);
Z237->A[Z249].Y2->A[Z258] = Z246(Z259, (LONGINT)Z229);
if (Z258 >= B_8) break;
}
}
} else {
ZmfFRCAJK_18(Z257, &Z260);
while (!Zp1Fy8_6(Z260)) {
Z256 = Z246(ZmfFRCAJK_12((ZmfFRCAJK_3)Zp1Fy8_8(&Z260)), (LONGINT)Z229);
}
}
}
}
Zp1Fy8_4(&Z260);
}

static void Z261
# ifdef HAVE_ARGS
(ZpmCQ_4 Z262)
# else
(Z262)
ZpmCQ_4 Z262;
# endif
{
INC(Z242);
if (Z241 == 0) {
Z241 = Z228;
ZarQdhNDD_0((ADDRESS *)&Z240, &Z241, (LONGINT)sizeof (Z235));
} else if (Z242 == Z241) {
ZarQdhNDD_2((ADDRESS *)&Z240, &Z241, (LONGINT)sizeof (Z235));
}
{
register Z235 *W_2 = &Z240->A[Z242];

ZpmCQ_5(&W_2->Y0, (LONGCARD)Z239);
ZpmCQ_30(&W_2->Y0, Z262);
}
}

static INTEGER Z263
# ifdef HAVE_ARGS
(ZpmCQ_4 Z262)
# else
(Z262)
ZpmCQ_4 Z262;
# endif
{
if (ZpmCQ_23(&Z262, &Z240->A[Z245].Y0)) {
return Z245;
}
Z245 = 0;
for (;;) {
if (Z245 > Z242) {
goto EXIT_1;
}
if (ZpmCQ_23(&Z262, &Z240->A[Z245].Y0)) {
return Z245;
}
INC(Z245);
} EXIT_1:;
return Z229;
}

static BOOLEAN Z264
# ifdef HAVE_ARGS
(INTEGER Z265, INTEGER Z262)
# else
(Z265, Z262)
INTEGER Z265;
INTEGER Z262;
# endif
{
return ZpmCQ_25((LONGCARD)Z265, &Z240->A[Z262].Y0);
}

static void Z266
 ARGS ((void))
{
ZpmCQ_4 Z262;

ZpmCQ_5(&Z262, (LONGCARD)Z239);
Z267(-1L, &Z262);
ZpmCQ_7(&Z262);
}

static void Z267
# ifdef HAVE_ARGS
(LONGINT Z268, ZpmCQ_4 *Z262)
# else
(Z268, Z262)
LONGINT Z268;
ZpmCQ_4 *Z262;
# endif
{
LONGINT Z256, Z249;
ZmfFRCAJK_3 Z247, Z269;
BOOLEAN Z270, Z271;

if (Z268 == Z239) {
Z261(*Z262);
} else {
Z249 = Z268 + 1;
Z247 = Z237->A[Z249].Y0;
if (Z247 == NIL) {
Z270 = TRUE;
Z271 = FALSE;
} else {
Z270 = TRUE;
Z271 = TRUE;
{
LONGINT B_9 = 0, B_10 = Z268;

if (B_9 <= B_10)
for (Z256 = B_9;; Z256 += 1) {
Z269 = Z237->A[Z256].Y0;
if (ZpmCQ_25((LONGCARD)Z256, Z262)) {
switch (ZmfFRCAJK_13(Z269, Z247)) {
case ZmfFRCAJK_21:;
break;
case ZmfFRCAJK_22:;
Z270 = FALSE;
break;
case ZmfFRCAJK_23:;
Z271 = FALSE;
break;
case ZmfFRCAJK_24:;
break;
case ZmfFRCAJK_25:;
ZblNKKO_82((STRING)"SynthesizeMatchSets", 19L);
break;
}
} else {
switch (ZmfFRCAJK_13(Z269, Z247)) {
case ZmfFRCAJK_21:;
break;
case ZmfFRCAJK_22:;
break;
case ZmfFRCAJK_23:;
break;
case ZmfFRCAJK_24:;
Z270 = FALSE;
break;
case ZmfFRCAJK_25:;
ZblNKKO_82((STRING)"SynthesizeMatchSets", 19L);
break;
}
}
if (Z256 >= B_10) break;
}
}
}
if (Z270) {
ZpmCQ_13(Z262, (LONGCARD)Z249);
Z267(Z249, Z262);
ZpmCQ_14(Z262, (LONGCARD)Z249);
}
if (Z271) {
Z267(Z249, Z262);
}
}
}

static void Z277
# ifdef HAVE_ARGS
(ZDz6VQCC_4 Z278)
# else
(Z278)
ZDz6VQCC_4 Z278;
# endif
{
LONGINT Z279, Z249;
BITSET Z280;
INTEGER Z281, Z282, Z283;
INTEGER Z256, Z284;
ZpmCQ_4 Z285;

Z284 = ZbhNIEKGK_8();
ZpmCQ_5(&Z285, (LONGCARD)Z284);
{
LONGINT B_11 = 0, B_12 = Z242;

if (B_11 <= B_12)
for (Z249 = B_11;; Z249 += 1) {
ZpmCQ_32(&Z285);
{
LONGINT B_13 = 0, B_14 = Z239;

if (B_13 <= B_14)
for (Z279 = B_13;; Z279 += 1) {
if (ZpmCQ_25((LONGCARD)Z279, &Z240->A[Z249].Y0)) {
ZpmCQ_8(&Z285, Z237->A[Z279].Y1);
}
if (Z279 >= B_14) break;
}
}
{
LONGINT B_15 = 0, B_16 = ZbhNIEKGK_8() / Z230;

if (B_15 <= B_16)
for (Z283 = B_15;; Z283 += 1) {
Z280 = 0X0L;
for (Z282 = 0; Z282 <= Z230 - 1; Z282 += 1) {
Z281 = Z283 * Z230 + Z282;
if (Z281 <= Z284 && ZpmCQ_25((LONGCARD)Z281, &Z285)) {
INCL(Z280, Z282);
}
}
Z256 = rWrite(Z278, ADR (Z280), (LONGINT)sizeof (BITSET));
if (Z283 >= B_16) break;
}
}
if (Z249 >= B_12) break;
}
}
ZpmCQ_7(&Z285);
}

static void Z286
 ARGS ((void))
{
ZpmCQ_4 Z287;
Zfb3DLQ_0 Z288;
LONGINT Z250;
INTEGER Z258;

Z250 = ZdnD8D8D_29() + 1;
ZarQdhNDD_0((ADDRESS *)&Z243, &Z250, (LONGINT)sizeof (ZpmCQ_4));
{
LONGINT B_17 = 1, B_18 = ZdnD8D8D_29();

if (B_17 <= B_18)
for (Z258 = B_17;; Z258 += 1) {
ZpmCQ_5(&Z243->A[Z258], (LONGCARD)Z242);
if (Z258 >= B_18) break;
}
}
ZpmCQ_5(&Z287, (LONGCARD)Zpky9FDA_40);
Zq7SFB_10(&Z287);
while (!ZpmCQ_26(Z287)) {
Z288 = ZpmCQ_20(&Z287);
Z289(Z288);
}
ZpmCQ_7(&Z287);
ZarQdhNDD_3((ADDRESS *)&Z243, &Z250, (LONGINT)sizeof (ZpmCQ_4));
}

static void Z289
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z288)
# else
(Z288)
Zfb3DLQ_0 Z288;
# endif
{
INTEGER Z258;
ZpmCQ_4 Z262;
INTEGER Z290, Z249;
Zn0DDDB_4 Z291;
ZmfFRCAJK_3 Z247;
ZdnD8D8D_0 Z292;

ZpmCQ_5(&Z262, (LONGCARD)Z239);
{
LONGINT B_19 = 0, B_20 = Z239;

if (B_19 <= B_20)
for (Z249 = B_19;; Z249 += 1) {
Z247 = Z237->A[Z249].Y0;
if (Z247 != NIL && ZmfFRCAJK_10(Z247) == Z288) {
ZpmCQ_13(&Z262, (LONGCARD)Z249);
}
if (Z249 >= B_20) break;
}
}
if (ZdnD8D8D_15(Z288) != Zpky9FDA_39) {
Z290 = ZdnD8D8D_22(Z288);
Z292 = ZdnD8D8D_24(Z288, ZdnD8D8D_15(Z288));
Zn0DDDB_5(&Z291);
Z293(0L, Z290, Z292);
Z294(Z288, Z262, 0L, Z290, &Z291, Z292);
Zn0DDDB_6(&Z291);
}
ZpmCQ_7(&Z262);
}

static void Z293
# ifdef HAVE_ARGS
(INTEGER Z258, INTEGER Z290, ZdnD8D8D_0 Z292)
# else
(Z258, Z290, Z292)
INTEGER Z258;
INTEGER Z290;
ZdnD8D8D_0 Z292;
# endif
{
Zfb3DLQ_0 Z295;
ZmfFRCAJK_3 Z296, Z247;
ZpmCQ_4 Z297;
LONGINT Z279;

if (Z258 == Z290) {
return;
}
INC(Z258);
ZpmCQ_5(&Z297, (LONGCARD)Z239);
Z295 = ZdnD8D8D_25(Z292, Z258);
Z296 = ZmfFRCAJK_12(ZmfFRCAJK_6(Z295));
{
LONGINT B_21 = 0, B_22 = Z239;

if (B_21 <= B_22)
for (Z279 = B_21;; Z279 += 1) {
Z247 = Z237->A[Z279].Y0;
if (ZmfFRCAJK_13(Z296, Z247) != ZmfFRCAJK_22) {
ZpmCQ_13(&Z297, (LONGCARD)Z279);
}
if (Z279 >= B_22) break;
}
}
ZmfFRCAJK_8(&Z296);
ZpmCQ_32(&Z243->A[Z258]);
{
LONGINT B_23 = 0, B_24 = Z242;

if (B_23 <= B_24)
for (Z279 = B_23;; Z279 += 1) {
if (ZpmCQ_21(Z240->A[Z279].Y0, Z297)) {
ZpmCQ_13(&Z243->A[Z258], (LONGCARD)Z279);
}
if (Z279 >= B_24) break;
}
}
ZpmCQ_7(&Z297);
Z293(Z258, Z290, Z292);
}

static void Z294
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z288, ZpmCQ_4 Z262, INTEGER Z258, INTEGER Z290, Zn0DDDB_4 *Z291, ZdnD8D8D_0 Z292)
# else
(Z288, Z262, Z258, Z290, Z291, Z292)
Zfb3DLQ_0 Z288;
ZpmCQ_4 Z262;
INTEGER Z258;
INTEGER Z290;
Zn0DDDB_4 *Z291;
ZdnD8D8D_0 Z292;
# endif
{
LONGINT Z279;
INTEGER Z249;
ZpmCQ_4 Z298, Z299;
ZmfFRCAJK_3 Z247;

if (Z258 == Z290) {
{
LONGINT B_25 = 0, B_26 = Z239;

if (B_25 <= B_26)
for (Z279 = B_25;; Z279 += 1) {
Z247 = Z237->A[Z279].Y0;
if (Z247 == NIL) {
ZpmCQ_13(&Z262, (LONGCARD)Z279);
} else if (Zq7SFB_2(ZmfFRCAJK_10(Z247)) == Zq7SFB_18) {
if (Z301(Z288, Z292, *Z291, ZmfFRCAJK_10(Z247))) {
ZpmCQ_13(&Z262, (LONGCARD)Z279);
}
}
if (Z279 >= B_26) break;
}
}
Z302(Z288, Z291, Z262);
} else {
INC(Z258);
ZpmCQ_5(&Z298, (LONGCARD)Z242);
ZpmCQ_30(&Z298, Z243->A[Z258]);
ZpmCQ_5(&Z299, (LONGCARD)Z239);
while (!ZpmCQ_26(Z298)) {
Z249 = ZpmCQ_20(&Z298);
ZpmCQ_30(&Z299, Z262);
Z279 = -1;
for (;;) {
if (Z279 == Z239) {
goto EXIT_2;
}
INC(Z279);
if (ZpmCQ_25((LONGCARD)Z279, &Z299)) {
if (!ZpmCQ_25((LONGCARD)Z237->A[Z279].Y2->A[Z258], &Z240->A[Z249].Y0)) {
ZpmCQ_14(&Z299, (LONGCARD)Z279);
}
}
} EXIT_2:;
Zn0DDDB_8(Z291, (ADDRESS)Z249);
Z294(Z288, Z299, Z258, Z290, Z291, Z292);
Zn0DDDB_12(Z291);
}
ZpmCQ_7(&Z299);
ZpmCQ_7(&Z298);
}
}

static void Z302
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z288, Zn0DDDB_4 *Z291, ZpmCQ_4 Z262)
# else
(Z288, Z291, Z262)
Zfb3DLQ_0 Z288;
Zn0DDDB_4 *Z291;
ZpmCQ_4 Z262;
# endif
{
INTEGER Z303;

Z303 = Z263(Z262);
Zn0DDDB_14(Z291, ZggGNEAP_0(Z288));
ZekSMF8FMG_1(*Z291, Z303);
Zn0DDDB_11(Z291);
}

static BOOLEAN Z301
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z288, ZdnD8D8D_0 Z292, Zn0DDDB_4 Z291, Zfb3DLQ_0 Z295)
# else
(Z288, Z292, Z291, Z295)
Zfb3DLQ_0 Z288;
ZdnD8D8D_0 Z292;
Zn0DDDB_4 Z291;
Zfb3DLQ_0 Z295;
# endif
{
Zfb3DLQ_0 Z304;
ZpmCQ_4 Z305, Z287;
ZdnD8D8D_0 Z306;
Zfb3DLQ_0 Z307;
BOOLEAN Z308;
INTEGER Z262, Z249, Z258;

Z304 = ZdnD8D8D_15(Z288);
if (Z295 == Z304) {
return TRUE;
}
ZpmCQ_5(&Z305, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z287, (LONGCARD)Zpky9FDA_40);
ZdnD8D8D_14(Z295, &Z305);
Z308 = FALSE;
for (;;) {
ZdnD8D8D_9(Z295, &Z287);
if (ZpmCQ_25((LONGCARD)Z288, &Z287)) {
Z308 = TRUE;
Z306 = ZdnD8D8D_24(Z288, Z295);
{
LONGINT B_27 = 1, B_28 = ZdnD8D8D_22(Z288);

if (B_27 <= B_28)
for (Z258 = B_27;; Z258 += 1) {
if (Z308) {
Z307 = ZdnD8D8D_25(Z306, Z258);
if (Z307 != ZdnD8D8D_25(Z292, Z258)) {
Z262 = (INTEGER)Zn0DDDB_17(Z291, Z258);
Z249 = Z244->A[Z307];
if (Z249 == Z229) {
Zp1BbM_23((STRING)"MatchClass: ", 12L);
Zfb3DLQ_7((ZDz6VQCC_4)ZfM_1, Z307);
Zp1BbM_23((STRING)" is not defined", 15L);
Zp1BbM_27();
ZblNKKO_82((STRING)"MatchClass", 10L);
}
Z308 = ZpmCQ_25((LONGCARD)Z249, &Z240->A[Z262].Y0);
}
}
if (Z258 >= B_28) break;
}
}
if (Z308) {
goto EXIT_3;
}
}
if (ZpmCQ_26(Z305)) {
goto EXIT_3;
}
Z295 = ZpmCQ_20(&Z305);
} EXIT_3:;
ZpmCQ_7(&Z287);
ZpmCQ_7(&Z305);
return Z308;
}

void ZjcFA5_2
 ARGS ((void))
{
LONGINT Z250;
Zfb3DLQ_0 Z257;

if (ZehCfg728_4) {
Z250 = Zpky9FDA_40 + 1;
ZarQdhNDD_0((ADDRESS *)&Z244, &Z250, (LONGINT)sizeof (INTEGER));
{
SHORTCARD B_29 = 0, B_30 = Zpky9FDA_40;

if (B_29 <= B_30)
for (Z257 = B_29;; Z257 += 1) {
Z244->A[Z257] = Z229;
if (Z257 >= B_30) break;
}
}
Z254();
Z255();
Z266();
if (ZehCfg728_8) {
Z310();
Z311();
}
ZekSMF8FMG_0(Z242, ZdaDDAD7_4(Z242, (LONGINT)Zpky9FDA_40));
Z286();
if (ZehCfg728_9) {
ZekSMF8FMG_5();
}
ZekSMF8FMG_2(&ZjcFA5_1);
ZjcFA5_0 = Z242;
if (ZehCfg728_9) {
ZekSMF8FMG_5();
}
if (ZehCfg728_8) {
ZekSMF8FMG_6();
ZekSMF8FMG_7();
}
}
}

void ZjcFA5_3
# ifdef HAVE_ARGS
(ZDz6VQCC_4 Z278)
# else
(Z278)
ZDz6VQCC_4 Z278;
# endif
{
INTEGER Z284, Z249, Z279, Z256, Z315;
ZpmCQ_4 Z285;
Zmfy8_0 Z316;

Z284 = ZbhNIEKGK_8();
Zmfy8_4(&Z316, Z278);
ZpmCQ_5(&Z285, (LONGCARD)Z284);
{
LONGINT B_31 = 0, B_32 = Z242;

if (B_31 <= B_32)
for (Z249 = B_31;; Z249 += 1) {
ZpmCQ_32(&Z285);
{
LONGINT B_33 = 0, B_34 = Z239;

if (B_33 <= B_34)
for (Z279 = B_33;; Z279 += 1) {
if (ZpmCQ_25((LONGCARD)Z279, &Z240->A[Z249].Y0)) {
ZpmCQ_8(&Z285, Z237->A[Z279].Y1);
}
if (Z279 >= B_34) break;
}
}
Z315 = 0;
{
LONGINT B_35 = 0, B_36 = Z284;

if (B_35 <= B_36)
for (Z256 = B_35;; Z256 += 1) {
if (ZpmCQ_25((LONGCARD)Z256, &Z285)) {
INC(Z315);
}
if (Z256 >= B_36) break;
}
}
Zmfy8_6(Z316, (LONGCARD)Z315);
{
LONGINT B_37 = 0, B_38 = Z284;

if (B_37 <= B_38)
for (Z256 = B_37;; Z256 += 1) {
if (ZpmCQ_25((LONGCARD)Z256, &Z285)) {
Zmfy8_6(Z316, (LONGCARD)Z256);
}
if (Z256 >= B_38) break;
}
}
if (Z249 >= B_32) break;
}
}
ZpmCQ_7(&Z285);
Zmfy8_8(&Z316);
}

static void Z310
 ARGS ((void))
{
LONGINT Z249;
INTEGER Z258;

Zp1BbM_23((STRING)" Pattern Table ", 15L);
Zp1BbM_27();
{
LONGINT B_39 = 0, B_40 = Z239;

if (B_39 <= B_40)
for (Z249 = B_39;; Z249 += 1) {
{
register Z231 *W_3 = &Z237->A[Z249];

Zp1BbM_19(Z249, 3L);
Zp1BbM_23((STRING)"  ", 2L);
ZmfFRCAJK_20((ZDz6VQCC_4)ZfM_1, W_3->Y0);
Zp1BbM_27();
Zp1BbM_23((STRING)"     ", 5L);
ZpmCQ_35((ZDz6VQCC_4)ZfM_1, W_3->Y1);
Zp1BbM_23((STRING)" - ", 3L);
if (W_3->Y0 != NIL && Zq7SFB_2(ZmfFRCAJK_10(W_3->Y0)) == Zq7SFB_19) {
{
LONGINT B_41 = 1, B_42 = ZdnD8D8D_22(ZmfFRCAJK_10(W_3->Y0));

if (B_41 <= B_42)
for (Z258 = B_41;; Z258 += 1) {
Zp1BbM_23((STRING)" ", 1L);
Zp1BbM_19(W_3->Y2->A[Z258], 1L);
if (Z258 >= B_42) break;
}
}
}
Zp1BbM_27();
}
if (Z249 >= B_40) break;
}
}
Zp1BbM_27();
}

static void Z311
 ARGS ((void))
{
LONGINT Z279, Z249;
ZpmCQ_4 Z285;

Zp1BbM_23((STRING)" Match-Set Table ", 17L);
Zp1BbM_27();
ZpmCQ_5(&Z285, (LONGCARD)ZbhNIEKGK_8());
{
LONGINT B_43 = 0, B_44 = Z242;

if (B_43 <= B_44)
for (Z249 = B_43;; Z249 += 1) {
Zp1BbM_19(Z249, 3L);
{
register Z235 *W_4 = &Z240->A[Z249];

Zp1BbM_23((STRING)" ", 1L);
ZpmCQ_35((ZDz6VQCC_4)ZfM_1, W_4->Y0);
}
Zp1BbM_23((STRING)"    ", 4L);
ZpmCQ_32(&Z285);
{
LONGINT B_45 = 0, B_46 = Z239;

if (B_45 <= B_46)
for (Z279 = B_45;; Z279 += 1) {
if (ZpmCQ_25((LONGCARD)Z279, &Z240->A[Z249].Y0)) {
ZpmCQ_8(&Z285, Z237->A[Z279].Y1);
}
if (Z279 >= B_46) break;
}
}
ZpmCQ_35((ZDz6VQCC_4)ZfM_1, Z285);
Zp1BbM_27();
if (Z249 >= B_44) break;
}
}
ZpmCQ_7(&Z285);
Zp1BbM_27();
}

static void Z317
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z288, Zn0DDDB_4 Z291, ZpmCQ_4 Z262)
# else
(Z288, Z291, Z262)
Zfb3DLQ_0 Z288;
Zn0DDDB_4 Z291;
ZpmCQ_4 Z262;
# endif
{
INTEGER Z258;
INTEGER Z249;

Z249 = Z263(Z262);
Zfb3DLQ_7((ZDz6VQCC_4)ZfM_1, Z288);
Zp1BbM_23((STRING)"( ", 2L);
{
LONGINT B_47 = 1, B_48 = Zn0DDDB_16(Z291);

if (B_47 <= B_48)
for (Z258 = B_47;; Z258 += 1) {
Zp1BbM_19((INTEGER)Zn0DDDB_17(Z291, Z258), 1L);
Zp1BbM_23((STRING)" ", 1L);
if (Z258 >= B_48) break;
}
}
Zp1BbM_23((STRING)")  = ", 5L);
Zp1BbM_19(Z249, 1L);
Zp1BbM_27();
}

void BEGIN_Match ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_ArgCheck ();
BEGIN_Automaton ();
BEGIN_Characte ();
BEGIN_Convert ();
BEGIN_DynArray ();
BEGIN_Environs ();
BEGIN_Errors ();
BEGIN_General ();
BEGIN_Grammar ();
BEGIN_Idents ();
BEGIN_Parser ();
BEGIN_Patterns ();
BEGIN_Queues ();
BEGIN_Scanner ();
BEGIN_Sets ();
BEGIN_Stack ();
BEGIN_Strings ();
BEGIN_rSystem ();
BEGIN_Types ();
BEGIN_Pack ();
BEGIN_Patterns ();
BEGIN_Strings ();
BEGIN_ArgCheck ();
BEGIN_Automaton ();
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Patterns ();
BEGIN_Queues ();
BEGIN_Sets ();
BEGIN_StdIO ();

Z238 = 0;
Z239 = -1;
Z241 = 0;
Z242 = -1;
Z245 = 0;
}
