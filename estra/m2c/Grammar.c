#include "SYSTEM_.h"

#ifndef DEFINITION_Convert
#include "Convert.h"
#endif

#ifndef DEFINITION_Heap
#include "Heap.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Lists
#include "Lists.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Stack
#include "Stack.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_Types
#include "Types.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Info
#include "Info.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Grammar
#include "Grammar.h"
#endif


#define Z177	-1
#define Z178	100000
typedef struct S_5 {
INTEGER A[1000 + 1];
} *Z179;
typedef struct S_1 {
Zfb3DLQ_0 Y0;
ZpmCQ_4 Y1;
ZpmCQ_4 Y2;
ZpmCQ_4 Y3;
ZijFQQ_3 Y4;
} Z180;
typedef struct S_2 {
Zfb3DLQ_0 Y0;
Zfb3DLQ_0 Y1;
INTEGER Y2;
ZdnD8D8D_2 Y3;
ZpmCQ_4 Y4;
ZijFQQ_3 Y5;
ZpmCQ_4 Y6;
} Z186;
typedef struct S_4 {
union {
struct {
Z180 Y0;
} V_1;
struct {
Z186 Y1;
} V_2;
} U_1;
} *Z194;
static struct S_3 {
Z194 A[1000 + 1];
} *Z199;
static INTEGER Z200;
static void Z210 ARGS ((void));
static void Z214 ARGS ((Zfb3DLQ_0 Z213, Z179 Z212, Zp1Fy8_2 *Z211));
static void Z220 ARGS ((Zfb3DLQ_0 Z208));

void ZdnD8D8D_4
 ARGS ((void))
{
LONGINT Z202;
Zfb3DLQ_0 Z203;

Z202 = Zpky9FDA_40 + 1;
ZarQdhNDD_0((ADDRESS *)&Z199, &Z202, (LONGINT)sizeof (Z194));
{
SHORTCARD B_1 = 0, B_2 = Zpky9FDA_40;

if (B_1 <= B_2)
for (Z203 = B_1;; Z203 += 1) {
switch (Zq7SFB_2(Z203)) {
case Zq7SFB_18:;
Z199->A[Z203] = (Z194)Zeb0B_1((LONGINT)sizeof (Z180));
{
register Z180 *W_1 = &Z199->A[Z203]->U_1.V_1.Y0;

W_1->Y0 = Zpky9FDA_39;
ZpmCQ_5(&W_1->Y1, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&W_1->Y2, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&W_1->Y3, (LONGCARD)Zpky9FDA_40);
ZijFQQ_5(&W_1->Y4);
}
break;
case Zq7SFB_19:;
Z199->A[Z203] = (Z194)Zeb0B_1((LONGINT)sizeof (Z186));
{
register Z186 *W_2 = &Z199->A[Z203]->U_1.V_2.Y1;

W_2->Y0 = Zpky9FDA_39;
W_2->Y1 = Z203;
W_2->Y2 = Z177;
W_2->Y3 = NIL;
ZpmCQ_5(&W_2->Y4, (LONGCARD)Zpky9FDA_40);
ZijFQQ_5(&W_2->Y5);
}
break;
default:
Z199->A[Z203] = NIL;
break;
}
if (Z203 >= B_2) break;
}
}
}

void ZdnD8D8D_5
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z205, Zfb3DLQ_0 Z206)
# else
(Z205, Z206)
Zfb3DLQ_0 Z205, Z206;
# endif
{
if (Zq7SFB_2(Z205) != Zq7SFB_18) {
ZblNKKO_82((STRING)"SetSuperClass: class is no class", 32L);
}
if (Zq7SFB_2(Z206) != Zq7SFB_18) {
ZblNKKO_82((STRING)"SetSuperClass: super is no class", 32L);
}
Z199->A[Z205]->U_1.V_1.Y0.Y0 = Z206;
ZpmCQ_13(&Z199->A[Z206]->U_1.V_1.Y0.Y2, (LONGCARD)Z205);
}

void ZdnD8D8D_6
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, Zfb3DLQ_0 Z205)
# else
(Z208, Z205)
Zfb3DLQ_0 Z208, Z205;
# endif
{
ZpmCQ_13(&Z199->A[Z205]->U_1.V_1.Y0.Y1, (LONGCARD)Z208);
ZpmCQ_13(&Z199->A[Z208]->U_1.V_2.Y1.Y4, (LONGCARD)Z205);
}

void ZdnD8D8D_7
 ARGS ((void))
{
Z210();
}

static void Z210
 ARGS ((void))
{
Zp1Fy8_2 Z211;
Z179 Z212;
Zfb3DLQ_0 Z213;
LONGINT Z202;

Zp1Fy8_3(&Z211);
Z202 = Zpky9FDA_40 + 1;
ZarQdhNDD_0((ADDRESS *)&Z212, &Z202, (LONGINT)sizeof (INTEGER));
{
SHORTCARD B_3 = 0, B_4 = Zpky9FDA_40;

if (B_3 <= B_4)
for (Z213 = B_3;; Z213 += 1) {
Z212->A[Z213] = 0;
if (Z213 >= B_4) break;
}
}
{
SHORTCARD B_5 = 0, B_6 = Zpky9FDA_40;

if (B_5 <= B_6)
for (Z213 = B_5;; Z213 += 1) {
if (Z212->A[Z213] == 0 && Zq7SFB_2(Z213) == Zq7SFB_18) {
Z214(Z213, Z212, &Z211);
}
if (Z213 >= B_6) break;
}
}
ZarQdhNDD_3((ADDRESS *)&Z212, &Z202, (LONGINT)sizeof (INTEGER));
Zp1Fy8_4(&Z211);
}

static void Z214
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z213, Z179 Z212, Zp1Fy8_2 *Z211)
# else
(Z213, Z212, Z211)
Zfb3DLQ_0 Z213;
Z179 Z212;
Zp1Fy8_2 *Z211;
# endif
{
INTEGER Z215;
ZpmCQ_4 Z216;
Zfb3DLQ_0 Z217;

ZpmCQ_5(&Z216, (LONGCARD)Zpky9FDA_40);
Zp1Fy8_7(Z211, ZggGNEAP_0(Z213));
Z215 = Zp1Fy8_10(*Z211);
Z212->A[Z213] = Z215;
ZpmCQ_30(&Z199->A[Z213]->U_1.V_1.Y0.Y3, Z199->A[Z213]->U_1.V_1.Y0.Y2);
ZdnD8D8D_13(Z213, &Z216);
while (!ZpmCQ_26(Z216)) {
Z217 = ZpmCQ_20(&Z216);
if (Z212->A[Z217] == 0) {
Z214(Z217, Z212, Z211);
}
if (Z212->A[Z213] > Z212->A[Z217]) {
Z212->A[Z213] = Z212->A[Z217];
}
ZpmCQ_8(&Z199->A[Z213]->U_1.V_1.Y0.Y3, Z199->A[Z217]->U_1.V_1.Y0.Y3);
}
if (Z212->A[Z213] == Z215) {
do {
Z217 = ZggGNEAP_1(Zp1Fy8_8(Z211));
Z212->A[Z217] = Z178;
if (Z213 != Z217) {
ZpmCQ_30(&Z199->A[Z217]->U_1.V_1.Y0.Y3, Z199->A[Z213]->U_1.V_1.Y0.Y3);
}
} while (!(Z217 == Z213));
}
ZpmCQ_7(&Z216);
}

void ZdnD8D8D_8
 ARGS ((void))
{
ZpmCQ_4 Z182;

ZpmCQ_5(&Z182, (LONGCARD)Zpky9FDA_40);
Zq7SFB_10(&Z182);
while (!ZpmCQ_26(Z182)) {
Z220((SHORTCARD)ZpmCQ_20(&Z182));
}
ZpmCQ_7(&Z182);
}

static void Z220
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208)
# else
(Z208)
Zfb3DLQ_0 Z208;
# endif
{
INTEGER Z221;
Zfb3DLQ_0 Z222;
ZpmCQ_4 Z223;

if (Zq7SFB_2(Z208) != Zq7SFB_19) {
ZblNKKO_82((STRING)"FixMainClass: no node", 21L);
}
{
register Z186 *W_3 = &Z199->A[Z208]->U_1.V_2.Y1;

Z221 = ZpmCQ_15(&W_3->Y4);
if (Z221 == 0) {
} else if (Z221 == 1) {
W_3->Y0 = ZpmCQ_17(&W_3->Y4);
} else {
ZpmCQ_5(&Z223, (LONGCARD)Zpky9FDA_40);
{
SHORTCARD B_7 = ZpmCQ_17(&W_3->Y4), B_8 = ZpmCQ_18(&W_3->Y4);

if (B_7 <= B_8)
for (Z222 = B_7;; Z222 += 1) {
if (ZpmCQ_25((LONGCARD)Z222, &W_3->Y4)) {
ZpmCQ_14(&W_3->Y4, (LONGCARD)Z222);
if (ZpmCQ_21(W_3->Y4, Z199->A[Z222]->U_1.V_1.Y0.Y3)) {
ZpmCQ_13(&Z223, (LONGCARD)Z222);
}
ZpmCQ_13(&W_3->Y4, (LONGCARD)Z222);
}
if (Z222 >= B_8) break;
}
}
if (ZpmCQ_15(&Z223) == 1) {
W_3->Y0 = ZpmCQ_17(&Z223);
}
ZpmCQ_7(&Z223);
}
}
}

void ZdnD8D8D_9
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z205, ZpmCQ_4 *Z182)
# else
(Z205, Z182)
Zfb3DLQ_0 Z205;
ZpmCQ_4 *Z182;
# endif
{
if (Zq7SFB_2(Z205) != Zq7SFB_18) {
ZblNKKO_82((STRING)"NodesOfClass: no class", 22L);
}
ZpmCQ_30(Z182, Z199->A[Z205]->U_1.V_1.Y0.Y1);
}

void ZdnD8D8D_10
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, ZpmCQ_4 *Z192)
# else
(Z208, Z192)
Zfb3DLQ_0 Z208;
ZpmCQ_4 *Z192;
# endif
{
if (Zq7SFB_2(Z208) != Zq7SFB_19) {
ZblNKKO_82((STRING)"ClassesOfNode: no node", 22L);
}
ZpmCQ_30(Z192, Z199->A[Z208]->U_1.V_2.Y1.Y4);
}

Zfb3DLQ_0 ZdnD8D8D_11
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z205)
# else
(Z205)
Zfb3DLQ_0 Z205;
# endif
{
if (Zq7SFB_2(Z205) != Zq7SFB_18) {
ZblNKKO_82((STRING)"SuperClass: no class", 20L);
}
return Z199->A[Z205]->U_1.V_1.Y0.Y0;
}

BOOLEAN ZdnD8D8D_12
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z205, Zfb3DLQ_0 Z206)
# else
(Z205, Z206)
Zfb3DLQ_0 Z205, Z206;
# endif
{
if (Zq7SFB_2(Z205) != Zq7SFB_18) {
ZblNKKO_82((STRING)"IsSubClass: class is no class", 29L);
}
if (Zq7SFB_2(Z206) != Zq7SFB_18) {
ZblNKKO_82((STRING)"IsSubClass: super is no class", 29L);
}
return ZpmCQ_25((LONGCARD)Z205, &Z199->A[Z206]->U_1.V_1.Y0.Y3);
}

void ZdnD8D8D_13
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z205, ZpmCQ_4 *Z228)
# else
(Z205, Z228)
Zfb3DLQ_0 Z205;
ZpmCQ_4 *Z228;
# endif
{
if (Zq7SFB_2(Z205) != Zq7SFB_18) {
ZblNKKO_82((STRING)"DirectSubClass: no class", 24L);
}
ZpmCQ_30(Z228, Z199->A[Z205]->U_1.V_1.Y0.Y2);
}

void ZdnD8D8D_14
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z205, ZpmCQ_4 *Z228)
# else
(Z205, Z228)
Zfb3DLQ_0 Z205;
ZpmCQ_4 *Z228;
# endif
{
if (Zq7SFB_2(Z205) != Zq7SFB_18) {
ZblNKKO_82((STRING)"DirectSubClass: no class", 24L);
}
ZpmCQ_30(Z228, Z199->A[Z205]->U_1.V_1.Y0.Y3);
}

Zfb3DLQ_0 ZdnD8D8D_15
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208)
# else
(Z208)
Zfb3DLQ_0 Z208;
# endif
{
return Z199->A[Z208]->U_1.V_2.Y1.Y0;
}

void ZdnD8D8D_16
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, Zfb3DLQ_0 Z203)
# else
(Z208, Z203)
Zfb3DLQ_0 Z208, Z203;
# endif
{
Z199->A[Z208]->U_1.V_2.Y1.Y1 = Z203;
}

void ZdnD8D8D_17
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, INTEGER Z233)
# else
(Z208, Z233)
Zfb3DLQ_0 Z208;
INTEGER Z233;
# endif
{
INTEGER Z234;
LONGINT Z202;

{
register Z186 *W_4 = &Z199->A[Z208]->U_1.V_2.Y1;

W_4->Y2 = Z233;
Z202 = Z233 + 1;
ZarQdhNDD_0((ADDRESS *)&W_4->Y3, &Z202, (LONGINT)sizeof (ZdnD8D8D_1));
{
LONGINT B_9 = 0, B_10 = W_4->Y2;

if (B_9 <= B_10)
for (Z234 = B_9;; Z234 += 1) {
W_4->Y3->A[Z234] = Zpky9FDA_39;
if (Z234 >= B_10) break;
}
}
}
if (Z233 > Z200) {
Z200 = Z233;
}
}

void ZdnD8D8D_18
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, INTEGER Z234, Zfb3DLQ_0 Z237)
# else
(Z208, Z234, Z237)
Zfb3DLQ_0 Z208;
INTEGER Z234;
Zfb3DLQ_0 Z237;
# endif
{
Z199->A[Z208]->U_1.V_2.Y1.Y3->A[Z234] = Z237;
}

ZdnD8D8D_0 ZdnD8D8D_19
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z239, Zfb3DLQ_0 Z222)
# else
(Z239, Z222)
Zfb3DLQ_0 Z239, Z222;
# endif
{
ZdnD8D8D_0 Z241;
LONGINT Z202;
INTEGER Z189, Z234;

if (Zq7SFB_2(Z239) != Zq7SFB_19) {
ZblNKKO_82((STRING)"CreateLayout: no node", 21L);
}
if (Zq7SFB_2(Z222) != Zq7SFB_18) {
ZblNKKO_82((STRING)"CreateLayout: no class", 22L);
}
Z189 = ZdnD8D8D_22(Z239);
Z241 = (ZdnD8D8D_0)Zeb0B_1((LONGINT)sizeof (ZdnD8D8D_3));
{
register ZdnD8D8D_3 *W_5 = Z241;

W_5->Y0 = Z239;
W_5->Y1 = Z222;
Z202 = Z189 + 1;
ZarQdhNDD_0((ADDRESS *)&W_5->Y2, &Z202, (LONGINT)sizeof (ZdnD8D8D_1));
{
LONGINT B_11 = 0, B_12 = Z189;

if (B_11 <= B_12)
for (Z234 = B_11;; Z234 += 1) {
W_5->Y2->A[Z234] = Zpky9FDA_39;
if (Z234 >= B_12) break;
}
}
}
ZijFQQ_7(&Z199->A[Z239]->U_1.V_2.Y1.Y5, (ADDRESS)Z241);
ZijFQQ_7(&Z199->A[Z222]->U_1.V_1.Y0.Y4, (ADDRESS)Z241);
return Z241;
}

void ZdnD8D8D_20
# ifdef HAVE_ARGS
(ZdnD8D8D_0 Z241, INTEGER Z234, Zfb3DLQ_0 Z205)
# else
(Z241, Z234, Z205)
ZdnD8D8D_0 Z241;
INTEGER Z234;
Zfb3DLQ_0 Z205;
# endif
{
Z241->Y2->A[Z234] = Z205;
}

Zfb3DLQ_0 ZdnD8D8D_21
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208)
# else
(Z208)
Zfb3DLQ_0 Z208;
# endif
{
return Z199->A[Z208]->U_1.V_2.Y1.Y1;
}

INTEGER ZdnD8D8D_22
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208)
# else
(Z208)
Zfb3DLQ_0 Z208;
# endif
{
return Z199->A[Z208]->U_1.V_2.Y1.Y2;
}

Zfb3DLQ_0 ZdnD8D8D_23
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, INTEGER Z234)
# else
(Z208, Z234)
Zfb3DLQ_0 Z208;
INTEGER Z234;
# endif
{
return Z199->A[Z208]->U_1.V_2.Y1.Y3->A[Z234];
}

ZdnD8D8D_0 ZdnD8D8D_24
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, Zfb3DLQ_0 Z205)
# else
(Z208, Z205)
Zfb3DLQ_0 Z208, Z205;
# endif
{
ZijFQQ_3 Z185;
ZdnD8D8D_0 Z241;

if (Zq7SFB_2(Z208) != Zq7SFB_19) {
ZblNKKO_82((STRING)"Layout: no node", 15L);
}
if (Zq7SFB_2(Z205) != Zq7SFB_18) {
ZblNKKO_82((STRING)"Layout: no class", 16L);
}
Z185 = Z199->A[Z208]->U_1.V_2.Y1.Y5;
for (;;) {
Z241 = (ZdnD8D8D_0)ZijFQQ_8(Z185);
if (Z241->Y1 == Z205) {
return Z241;
}
ZijFQQ_9(&Z185);
} EXIT_1:;
}

Zfb3DLQ_0 ZdnD8D8D_25
# ifdef HAVE_ARGS
(ZdnD8D8D_0 Z241, INTEGER Z234)
# else
(Z241, Z234)
ZdnD8D8D_0 Z241;
INTEGER Z234;
# endif
{
return Z241->Y2->A[Z234];
}

void ZdnD8D8D_26
# ifdef HAVE_ARGS
(INTEGER Z202)
# else
(Z202)
INTEGER Z202;
# endif
{
ZpmCQ_4 Z182;

ZpmCQ_5(&Z182, (LONGCARD)Zpky9FDA_40);
Zq7SFB_10(&Z182);
while (!ZpmCQ_26(Z182)) {
ZpmCQ_5(&Z199->A[ZpmCQ_20(&Z182)]->U_1.V_2.Y1.Y6, (LONGCARD)Z202);
}
ZpmCQ_7(&Z182);
}

void ZdnD8D8D_27
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, INTEGER Z252)
# else
(Z208, Z252)
Zfb3DLQ_0 Z208;
INTEGER Z252;
# endif
{
ZpmCQ_13(&Z199->A[Z208]->U_1.V_2.Y1.Y6, (LONGCARD)Z252);
}

void ZdnD8D8D_28
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z208, ZpmCQ_4 *Z193)
# else
(Z208, Z193)
Zfb3DLQ_0 Z208;
ZpmCQ_4 *Z193;
# endif
{
ZpmCQ_30(Z193, Z199->A[Z208]->U_1.V_2.Y1.Y6);
}

INTEGER ZdnD8D8D_29
 ARGS ((void))
{
return Z200;
}

void ZdnD8D8D_30
# ifdef HAVE_ARGS
(ZfM_3 Z256)
# else
(Z256)
ZfM_3 Z256;
# endif
{
Zfb3DLQ_0 Z203;

{
SHORTCARD B_13 = 1, B_14 = Zpky9FDA_40;

if (B_13 <= B_14)
for (Z203 = B_13;; Z203 += 1) {
switch (Zq7SFB_2(Z203)) {
case Zq7SFB_18:;
{
register Z180 *W_6 = &Z199->A[Z203]->U_1.V_1.Y0;

ZfM_29(Z256, (STRING)"class:                ", 22L);
Zfb3DLQ_7(Z256, Z203);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  super class:        ", 22L);
Zfb3DLQ_7(Z256, W_6->Y0);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  nodes:              ", 22L);
ZflEF_2(Z256, W_6->Y1);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  direct sub classes: ", 22L);
ZflEF_2(Z256, W_6->Y2);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  sub classes:        ", 22L);
ZflEF_2(Z256, W_6->Y3);
ZfM_33(Z256);
}
break;
case Zq7SFB_19:;
{
register Z186 *W_7 = &Z199->A[Z203]->U_1.V_2.Y1;

ZfM_29(Z256, (STRING)"node:                 ", 22L);
Zfb3DLQ_7(Z256, Z203);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  main class:         ", 22L);
Zfb3DLQ_7(Z256, W_7->Y0);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  node ident:         ", 22L);
Zfb3DLQ_7(Z256, W_7->Y1);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  arity:              ", 22L);
ZfM_25(Z256, W_7->Y2, 1L);
ZfM_33(Z256);
ZfM_29(Z256, (STRING)"  classes:            ", 22L);
ZflEF_2(Z256, W_7->Y4);
ZfM_33(Z256);
}
break;
default:
break;
}
if (Z203 >= B_14) break;
}
}
}

void BEGIN_Grammar ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_Sets ();
BEGIN_IO ();
BEGIN_Convert ();
BEGIN_Heap ();
BEGIN_DynArray ();
BEGIN_Idents ();
BEGIN_Lists ();
BEGIN_Scanner ();
BEGIN_Stack ();
BEGIN_Sets ();
BEGIN_Types ();
BEGIN_Errors ();
BEGIN_Info ();
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_StdIO ();
BEGIN_IO ();

Z200 = 0;
}
