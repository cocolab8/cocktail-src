#include "SYSTEM_.h"

#ifndef DEFINITION_Convert
#include "Convert.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
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

#ifndef DEFINITION_Layout
#include "Layout.h"
#endif

#ifndef DEFINITION_rMemory
#include "rMemory.h"
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

#ifndef DEFINITION_Types
#include "Types.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Environs
#include "Environs.h"
#endif


static CHAR Z167 [] = "yyt";
static CHAR Z168 [] = "Kind";
static CHAR Z169 [] = "yyClass";
static CHAR Z170 [] = "Cost";
#define Z171	32
#define Z172	100
typedef struct S_1 *Z173;
typedef struct S_1 {
Zn0DDDB_4 Y0;
Zfb3DLQ_0 Y1;
Zfb3DLQ_0 Y2;
BOOLEAN Y3;
Zn0DDDB_4 Y4;
Z173 Y5;
INTEGER Y6;
ZmfFRCAJK_3 Y7;
} Z174;
typedef struct S_2 {
ZmfFRCAJK_3 Y0;
BOOLEAN Y1;
ZpmCQ_4 Y2;
Z173 Y3;
Z173 Y4;
} Z183;
typedef struct S_3 *Z188;
typedef struct S_3 {
ZbhNIEKGK_1 Y0;
Z188 Y1;
} Z189;
static struct S_4 {
Z183 A[1000 + 1];
} *Z192;
static LONGINT Z193, Z194;
static INTEGER Z195;
static Z188 Z179;
static ZbhNIEKGK_1 Z209 ARGS ((Zfb3DLQ_0 Z197));
static Z173 Z231 ARGS ((ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224));
static void Z237 ARGS ((ZfM_3 Z199, Zn0DDDB_4 Z175));

ZbhNIEKGK_1 ZbhNIEKGK_3
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z197, ZpmCQ_4 Z198)
# else
(Z197, Z198)
Zfb3DLQ_0 Z197;
ZpmCQ_4 Z198;
# endif
{
ZbhNIEKGK_1 Z199;
Z188 Z200;

Z199 = (ZbhNIEKGK_1)ZDtgCFKU_1((LONGINT)sizeof (ZbhNIEKGK_2));
Z200 = (Z188)ZDtgCFKU_1((LONGINT)sizeof (Z189));
Z200->Y0 = Z199;
Z200->Y1 = Z179;
Z179 = Z200;
Z199->Y0 = Z197;
Zn0DDDB_5(&Z199->Y1);
ZpmCQ_5(&Z199->Y2, (LONGCARD)Zpky9FDA_40);
ZpmCQ_30(&Z199->Y2, Z198);
return Z199;
}

BOOLEAN ZbhNIEKGK_4
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z197, ZmfFRCAJK_3 Z206)
# else
(Z197, Z206)
Zfb3DLQ_0 Z197;
ZmfFRCAJK_3 Z206;
# endif
{
ZbhNIEKGK_1 Z199;
BOOLEAN Z207;
ZpmCQ_4 Z208;

Z199 = Z209(Z197);
ZpmCQ_5(&Z208, (LONGCARD)Zpky9FDA_40);
ZmfFRCAJK_11(Z206, &Z208);
ZpmCQ_10(&Z208, Z199->Y2);
Z207 = !ZpmCQ_26(Z208);
ZpmCQ_7(&Z208);
return Z207;
}

static ZbhNIEKGK_1 Z209
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z197)
# else
(Z197)
Zfb3DLQ_0 Z197;
# endif
{
Z188 Z200;

Z200 = Z179;
for (;;) {
if (Z200 == NIL) {
ZblNKKO_82((STRING)"Environs.Function: not found", 28L);
}
if (Z200->Y0->Y0 == Z197) {
return Z200->Y0;
}
Z200 = Z200->Y1;
} EXIT_1:;
}

ZbhNIEKGK_0 ZbhNIEKGK_5
# ifdef HAVE_ARGS
(ZbhNIEKGK_1 Z211)
# else
(Z211)
ZbhNIEKGK_1 Z211;
# endif
{
INTEGER Z213;

INC(Z194);
if (Z194 >= Z193) {
if (Z193 == 0) {
Z193 = Z172;
ZarQdhNDD_0((ADDRESS *)&Z192, &Z193, (LONGINT)sizeof (Z183));
} else {
ZarQdhNDD_2((ADDRESS *)&Z192, &Z193, (LONGINT)sizeof (Z183));
}
}
Z213 = Z194;
Zn0DDDB_8(&Z211->Y1, (ADDRESS)Z213);
{
register Z183 *W_1 = &Z192->A[Z213];

W_1->Y0 = NIL;
ZpmCQ_5(&W_1->Y2, (LONGCARD)Zpky9FDA_40);
W_1->Y3 = NIL;
W_1->Y4 = NIL;
}
return Z194;
}

void ZbhNIEKGK_6
# ifdef HAVE_ARGS
(ZbhNIEKGK_1 Z211, Zn0DDDB_4 *Z215)
# else
(Z211, Z215)
ZbhNIEKGK_1 Z211;
Zn0DDDB_4 *Z215;
# endif
{
INTEGER Z213, Z216;

Zn0DDDB_7(Z215);
{
LONGINT B_1 = 1, B_2 = Zn0DDDB_16(Z211->Y1);

if (B_1 <= B_2)
for (Z216 = B_1;; Z216 += 1) {
Z213 = (INTEGER)Zn0DDDB_17(Z211->Y1, Z216);
if (!Z192->A[Z213].Y1) {
Zn0DDDB_8(Z215, (ADDRESS)Z192->A[Z213].Y0);
}
if (Z216 >= B_2) break;
}
}
}

void ZbhNIEKGK_7
# ifdef HAVE_ARGS
(ZbhNIEKGK_1 Z211, Zn0DDDB_4 *Z215)
# else
(Z211, Z215)
ZbhNIEKGK_1 Z211;
Zn0DDDB_4 *Z215;
# endif
{
INTEGER Z213, Z216;

Zn0DDDB_7(Z215);
{
LONGINT B_3 = 1, B_4 = Zn0DDDB_16(Z211->Y1);

if (B_3 <= B_4)
for (Z216 = B_3;; Z216 += 1) {
Z213 = (INTEGER)Zn0DDDB_17(Z211->Y1, Z216);
if (Z192->A[Z213].Y1) {
Zn0DDDB_8(Z215, (ADDRESS)Z192->A[Z213].Y0);
}
if (Z216 >= B_4) break;
}
}
}

ZbhNIEKGK_0 ZbhNIEKGK_8
 ARGS ((void))
{
return Z194;
}

void ZbhNIEKGK_9
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, ZmfFRCAJK_3 Z206)
# else
(Z213, Z206)
ZbhNIEKGK_0 Z213;
ZmfFRCAJK_3 Z206;
# endif
{
{
register Z183 *W_2 = &Z192->A[Z213];

W_2->Y0 = Z206;
W_2->Y1 = FALSE;
}
}

void ZbhNIEKGK_10
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, ZmfFRCAJK_3 Z206)
# else
(Z213, Z206)
ZbhNIEKGK_0 Z213;
ZmfFRCAJK_3 Z206;
# endif
{
{
register Z183 *W_3 = &Z192->A[Z213];

W_3->Y0 = Z206;
W_3->Y1 = TRUE;
}
}

ZmfFRCAJK_3 ZbhNIEKGK_11
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213)
# else
(Z213)
ZbhNIEKGK_0 Z213;
# endif
{
return Z192->A[Z213].Y0;
}

void ZbhNIEKGK_12
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zn0DDDB_4 Z223, Zfb3DLQ_0 Z224, Zfb3DLQ_0 Z225, BOOLEAN Z226)
# else
(Z213, Z223, Z224, Z225, Z226)
ZbhNIEKGK_0 Z213;
Zn0DDDB_4 Z223;
Zfb3DLQ_0 Z224, Z225;
BOOLEAN Z226;
# endif
{
Z173 Z227;

if (Z224 != Zpky9FDA_39) {
ZpmCQ_13(&Z192->A[Z213].Y2, (LONGCARD)Z224);
}
Z227 = (Z173)ZDtgCFKU_1((LONGINT)sizeof (Z174));
{
register Z174 *W_4 = Z227;

Zn0DDDB_5(&W_4->Y0);
Zn0DDDB_18(&W_4->Y0, Z223);
Zn0DDDB_5(&W_4->Y4);
W_4->Y1 = Z224;
W_4->Y2 = Z225;
W_4->Y3 = Z226 || Z225 == Zpky9FDA_39;
W_4->Y5 = NIL;
W_4->Y6 = 0;
}
if (Z192->A[Z213].Y4 == NIL) {
if (Zq7SFB_2(Z225) == Zq7SFB_19) {
Z227->Y3 = TRUE;
}
Z192->A[Z213].Y3 = Z227;
} else {
Z192->A[Z213].Y4->Y5 = Z227;
}
Z192->A[Z213].Y4 = Z227;
}

BOOLEAN ZbhNIEKGK_14
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224)
# else
(Z213, Z224)
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224;
# endif
{
return ZpmCQ_25((LONGCARD)Z224, &Z192->A[Z213].Y2);
}

void ZbhNIEKGK_13
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224, ZmfFRCAJK_3 Z206)
# else
(Z213, Z224, Z206)
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224;
ZmfFRCAJK_3 Z206;
# endif
{
Z173 Z227;

Z227 = Z231(Z213, Z224);
Z227->Y7 = Z206;
}

ZmfFRCAJK_3 ZbhNIEKGK_15
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224)
# else
(Z213, Z224)
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224;
# endif
{
Z173 Z227;

Z227 = Z231(Z213, Z224);
return Z227->Y7;
}

static Z173 Z231
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224)
# else
(Z213, Z224)
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224;
# endif
{
Z173 Z227;

Z227 = Z192->A[Z213].Y3;
for (;;) {
if (Z227->Y1 == Z224) {
return Z227;
}
Z227 = Z227->Y5;
} EXIT_2:;
}

void ZbhNIEKGK_16
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224, Zfb3DLQ_0 Z197)
# else
(Z213, Z224, Z197)
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224, Z197;
# endif
{
Z173 Z227;

Z227 = Z231(Z213, Z224);
INC(Z227->Y6);
if (Z227->Y6 > Z195) {
Z195 = Z227->Y6;
}
Zn0DDDB_8(&Z227->Y4, ZggGNEAP_0(Z197));
}

BOOLEAN ZbhNIEKGK_17
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213)
# else
(Z213)
ZbhNIEKGK_0 Z213;
# endif
{
return !Zn0DDDB_15(Z192->A[Z213].Y3->Y4);
}

BOOLEAN ZbhNIEKGK_18
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224)
# else
(Z213, Z224)
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224;
# endif
{
return Z192->A[Z213].Y3->Y1 == Z224;
}

INTEGER ZbhNIEKGK_19
 ARGS ((void))
{
return Z195;
}

static void Z237
# ifdef HAVE_ARGS
(ZfM_3 Z199, Zn0DDDB_4 Z175)
# else
(Z199, Z175)
ZfM_3 Z199;
Zn0DDDB_4 Z175;
# endif
{
INTEGER Z216;

ZfM_29(Z199, Z167, 3L);
{
LONGINT B_5 = 1, B_6 = Zn0DDDB_16(Z175) - 1;

if (B_5 <= B_6)
for (Z216 = B_5;; Z216 += 1) {
if (ODD(Z216)) {
ZfM_29(Z199, (STRING)"^.", 2L);
} else {
ZfM_29(Z199, (STRING)".", 1L);
}
Zfb3DLQ_7(Z199, ZggGNEAP_1(Zn0DDDB_17(Z175, Z216)));
if (Z216 >= B_6) break;
}
}
}

void ZbhNIEKGK_20
# ifdef HAVE_ARGS
(ZfM_3 Z199, ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224)
# else
(Z199, Z213, Z224)
ZfM_3 Z199;
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224;
# endif
{
Z173 Z227;

Z227 = Z231(Z213, Z224);
Z237(Z199, Z227->Y0);
}

void ZbhNIEKGK_21
# ifdef HAVE_ARGS
(ZfM_3 Z199, ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z224)
# else
(Z199, Z213, Z224)
ZfM_3 Z199;
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z224;
# endif
{
Z173 Z227;

Z227 = Z231(Z213, Z224);
Z237(Z199, Z227->Y0);
ZfM_29(Z199, (STRING)"^.", 2L);
Zfb3DLQ_7(Z199, Z227->Y2);
}

BOOLEAN ZbhNIEKGK_22
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213, Zfb3DLQ_0 Z241)
# else
(Z213, Z241)
ZbhNIEKGK_0 Z213;
Zfb3DLQ_0 Z241;
# endif
{
ZmfFRCAJK_3 Z206;
ZmfFRCAJK_2 Z242;

Z206 = ZmfFRCAJK_12(ZmfFRCAJK_6(Z241));
Z242 = ZmfFRCAJK_13(Z192->A[Z213].Y0, Z206);
ZmfFRCAJK_8(&Z206);
return Z242 == ZmfFRCAJK_25 || Z242 == ZmfFRCAJK_24;
}

BOOLEAN ZbhNIEKGK_23
# ifdef HAVE_ARGS
(ZbhNIEKGK_0 Z213)
# else
(Z213)
ZbhNIEKGK_0 Z213;
# endif
{
return Z192->A[Z213].Y1;
}

void ZbhNIEKGK_24
# ifdef HAVE_ARGS
(ZfM_3 Z199, ZbhNIEKGK_0 Z213, INTEGER Z247, Zfb3DLQ_0 Z248)
# else
(Z199, Z213, Z247, Z248)
ZfM_3 Z199;
ZbhNIEKGK_0 Z213;
INTEGER Z247;
Zfb3DLQ_0 Z248;
# endif
{
Z173 Z227;
BOOLEAN Z249;

Z249 = FALSE;
Z227 = Z192->A[Z213].Y3;
while (Z227 != NIL) {
if (!Z227->Y3) {
if (Z249) {
ZfM_33(Z199);
ZibDRNS_2(Z199, 2 * Z247);
ZfM_29(Z199, (STRING)" & ", 3L);
}
Z249 = TRUE;
if (Zq7SFB_2(Z227->Y2) == Zq7SFB_19) {
ZfM_29(Z199, (STRING)"(", 1L);
Z237(Z199, Z227->Y0);
ZfM_29(Z199, (STRING)"^.", 2L);
ZfM_29(Z199, Z168, 4L);
ZfM_29(Z199, (STRING)" = ", 3L);
Zfb3DLQ_7(Z199, Z248);
ZfM_29(Z199, (STRING)".", 1L);
Zfb3DLQ_7(Z199, ZdnD8D8D_21(Z227->Y2));
ZfM_29(Z199, (STRING)")", 1L);
} else {
ZfM_29(Z199, Z169, 7L);
ZfM_29(Z199, (STRING)" (", 2L);
Z237(Z199, Z227->Y0);
ZfM_29(Z199, (STRING)", yyC", 5L);
Zfb3DLQ_7(Z199, Z227->Y2);
ZfM_29(Z199, (STRING)" MOD yyBitsPerBitset", 20L);
ZfM_29(Z199, (STRING)", yyC", 5L);
Zfb3DLQ_7(Z199, Z227->Y2);
ZfM_29(Z199, (STRING)" DIV yyBitsPerBitset", 20L);
ZfM_29(Z199, (STRING)")", 1L);
}
}
Z227 = Z227->Y5;
}
if (!Z249) {
ZfM_29(Z199, (STRING)"TRUE", 4L);
}
}

void ZbhNIEKGK_25
# ifdef HAVE_ARGS
(ZfM_3 Z199, ZbhNIEKGK_0 Z213, INTEGER Z247)
# else
(Z199, Z213, Z247)
ZfM_3 Z199;
ZbhNIEKGK_0 Z213;
INTEGER Z247;
# endif
{
Z173 Z227;
INTEGER Z216;

Z227 = Z192->A[Z213].Y3;
while (Z227 != NIL) {
{
LONGINT B_7 = 1, B_8 = Zn0DDDB_16(Z227->Y4);

if (B_7 <= B_8)
for (Z216 = B_7;; Z216 += 1) {
ZfM_33(Z199);
ZibDRNS_2(Z199, 2 * Z247);
ZfM_29(Z199, (STRING)"+ ", 2L);
ZfM_29(Z199, Z170, 4L);
Zfb3DLQ_7(Z199, ZggGNEAP_1(Zn0DDDB_17(Z227->Y4, Z216)));
ZfM_29(Z199, (STRING)" (", 2L);
Z237(Z199, Z227->Y0);
ZfM_29(Z199, (STRING)")", 1L);
if (Z216 >= B_8) break;
}
}
Z227 = Z227->Y5;
}
}

void BEGIN_Environs ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Patterns ();
BEGIN_Queues ();
BEGIN_Sets ();
BEGIN_Convert ();
BEGIN_DynArray ();
BEGIN_Grammar ();
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Layout ();
BEGIN_rMemory ();
BEGIN_Patterns ();
BEGIN_Queues ();
BEGIN_Scanner ();
BEGIN_Sets ();
BEGIN_Types ();
BEGIN_Sets ();
BEGIN_Errors ();

Z194 = 0;
Z193 = 0;
Z195 = 1;
Z179 = NIL;
}
