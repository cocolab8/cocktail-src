#include "SYSTEM_.h"

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
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

#ifndef DEFINITION_rMemory
#include "rMemory.h"
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

#ifndef DEFINITION_Types
#include "Types.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Patterns
#include "Patterns.h"
#endif


static ZmfFRCAJK_3 Z173;
static ZmfFRCAJK_3 Z196 ARGS ((ZmfFRCAJK_3 Z179, BOOLEAN Z197));
static BOOLEAN Z205 ARGS ((Zfb3DLQ_0 Z199));
static void Z223 ARGS ((Zfb3DLQ_0 Z226, ZpmCQ_4 *Z227));
static void Z234 ARGS ((Zfb3DLQ_0 Z199, Zp1Fy8_2 *Z231, ZpmCQ_4 Z237));
static ZmfFRCAJK_3 Z235 ARGS ((ZmfFRCAJK_3 Z179, ZmfFRCAJK_3 Z180, ZmfFRCAJK_3 Z240));

ZmfFRCAJK_3 ZmfFRCAJK_6
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z176)
# else
(Z176)
Zfb3DLQ_0 Z176;
# endif
{
INTEGER Z177;
LONGINT Z178;
ZmfFRCAJK_3 Z179;
INTEGER Z180;

Z179 = (ZmfFRCAJK_3)ZDtgCFKU_1((LONGINT)sizeof (ZmfFRCAJK_5));
Z179->Y0 = Z176;
ZpmCQ_5(&Z179->Y1, (LONGCARD)Zpky9FDA_40);
if (Zq7SFB_2(Z176) == Zq7SFB_19) {
Z177 = ZdnD8D8D_22(Z176);
Z178 = Z177 + 1;
ZarQdhNDD_0((ADDRESS *)&Z179->Y2, &Z178, (LONGINT)sizeof (ZmfFRCAJK_3));
{
LONGINT B_1 = 1, B_2 = Z177;

if (B_1 <= B_2)
for (Z180 = B_1;; Z180 += 1) {
Z179->Y2->A[Z180] = NIL;
if (Z180 >= B_2) break;
}
}
} else {
Z179->Y2 = NIL;
}
return Z179;
}

void ZmfFRCAJK_11
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179, ZpmCQ_4 *Z187)
# else
(Z179, Z187)
ZmfFRCAJK_3 Z179;
ZpmCQ_4 *Z187;
# endif
{
ZpmCQ_30(Z187, Z179->Y1);
}

void ZmfFRCAJK_7
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179, INTEGER Z180, ZmfFRCAJK_3 Z189)
# else
(Z179, Z180, Z189)
ZmfFRCAJK_3 Z179;
INTEGER Z180;
ZmfFRCAJK_3 Z189;
# endif
{
Z179->Y2->A[Z180] = Z189;
}

ZmfFRCAJK_3 ZmfFRCAJK_9
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179, INTEGER Z180)
# else
(Z179, Z180)
ZmfFRCAJK_3 Z179;
INTEGER Z180;
# endif
{
return Z179->Y2->A[Z180];
}

Zfb3DLQ_0 ZmfFRCAJK_10
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179)
# else
(Z179)
ZmfFRCAJK_3 Z179;
# endif
{
return Z179->Y0;
}

void ZmfFRCAJK_8
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 *Z179)
# else
(Z179)
ZmfFRCAJK_3 *Z179;
# endif
{
LONGINT Z178;
INTEGER Z177, Z180;

if (*Z179 != NIL) {
ZpmCQ_7(&(*Z179)->Y1);
if (Zq7SFB_2((*Z179)->Y0) == Zq7SFB_19) {
Z177 = ZdnD8D8D_22((*Z179)->Y0);
{
LONGINT B_3 = 1, B_4 = Z177;

if (B_3 <= B_4)
for (Z180 = B_3;; Z180 += 1) {
ZmfFRCAJK_8(&(*Z179)->Y2->A[Z180]);
if (Z180 >= B_4) break;
}
}
Z178 = Z177 + 1;
ZarQdhNDD_3((ADDRESS *)&(*Z179)->Y2, &Z178, (LONGINT)sizeof (ZmfFRCAJK_3));
}
ZDtgCFKU_2((LONGINT)sizeof (ZmfFRCAJK_5), (ADDRESS)(*Z179));
*Z179 = NIL;
}
}

ZmfFRCAJK_3 ZmfFRCAJK_19
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179)
# else
(Z179)
ZmfFRCAJK_3 Z179;
# endif
{
INTEGER Z180;
ZmfFRCAJK_3 Z194;

if (Z179 == NIL) {
Z194 = NIL;
} else {
Z194 = ZmfFRCAJK_6(Z179->Y0);
ZpmCQ_30(&Z194->Y1, Z179->Y1);
if (Zq7SFB_2(Z179->Y0) == Zq7SFB_19) {
{
LONGINT B_5 = 1, B_6 = ZdnD8D8D_22(Z179->Y0);

if (B_5 <= B_6)
for (Z180 = B_5;; Z180 += 1) {
Z194->Y2->A[Z180] = ZmfFRCAJK_19(Z179->Y2->A[Z180]);
if (Z180 >= B_6) break;
}
}
}
}
return Z194;
}

ZmfFRCAJK_3 ZmfFRCAJK_12
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179)
# else
(Z179)
ZmfFRCAJK_3 Z179;
# endif
{
return Z196(Z179, TRUE);
}

static ZmfFRCAJK_3 Z196
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179, BOOLEAN Z197)
# else
(Z179, Z197)
ZmfFRCAJK_3 Z179;
BOOLEAN Z197;
# endif
{
Zfb3DLQ_0 Z198, Z199;
ZpmCQ_4 Z187;
ZdnD8D8D_0 Z200, Z201;
INTEGER Z177, Z180;
BOOLEAN Z202;
BOOLEAN Z203;
ZmfFRCAJK_3 Z204;

if (Z179 == NIL) {
} else {
ZpmCQ_5(&Z187, (LONGCARD)Zpky9FDA_40);
if (Zq7SFB_2(Z179->Y0) == Zq7SFB_19) {
Z177 = ZdnD8D8D_22(Z179->Y0);
Z198 = ZdnD8D8D_15(Z179->Y0);
Z200 = ZdnD8D8D_24(Z179->Y0, Z198);
Z203 = TRUE;
{
LONGINT B_7 = 1, B_8 = Z177;

if (B_7 <= B_8)
for (Z180 = B_7;; Z180 += 1) {
Z204 = Z196(Z179->Y2->A[Z180], Z197);
if (Z204 != NIL) {
if (Z204->Y0 == ZdnD8D8D_25(Z200, Z180)) {
if (Z197) {
ZmfFRCAJK_8(&Z204);
Z204 = NIL;
}
} else {
Z203 = FALSE;
}
}
Z179->Y2->A[Z180] = Z204;
if (Z180 >= B_8) break;
}
}
ZpmCQ_32(&Z179->Y1);
ZdnD8D8D_10(Z179->Y0, &Z187);
while (!ZpmCQ_26(Z187)) {
Z199 = ZpmCQ_20(&Z187);
Z201 = ZdnD8D8D_24(Z179->Y0, Z199);
Z202 = TRUE;
{
LONGINT B_9 = 1, B_10 = Z177;

if (B_9 <= B_10)
for (Z180 = B_9;; Z180 += 1) {
if (Z202) {
if (Z179->Y2->A[Z180] == NIL) {
Z202 = ZdnD8D8D_25(Z201, Z180) == ZdnD8D8D_25(Z200, Z180);
} else {
Z202 = ZpmCQ_25((LONGCARD)ZdnD8D8D_25(Z201, Z180), &Z179->Y2->A[Z180]->Y1);
}
}
if (Z180 >= B_10) break;
}
}
if (Z202) {
ZpmCQ_13(&Z179->Y1, (LONGCARD)Z199);
}
}
if (Z197 && Z203 && Z205(Z198)) {
ZmfFRCAJK_8(&Z179);
Z179 = ZmfFRCAJK_6(Z198);
}
}
if (Zq7SFB_2(Z179->Y0) == Zq7SFB_18) {
ZpmCQ_31(&Z179->Y1, (LONGCARD)Z179->Y0);
}
ZpmCQ_30(&Z187, Z179->Y1);
while (!ZpmCQ_26(Z187)) {
Z199 = ZdnD8D8D_11((SHORTCARD)ZpmCQ_20(&Z187));
while (Z199 != Zpky9FDA_39 && !ZpmCQ_25((LONGCARD)Z199, &Z179->Y1)) {
ZpmCQ_13(&Z179->Y1, (LONGCARD)Z199);
Z199 = ZdnD8D8D_11(Z199);
}
}
ZpmCQ_7(&Z187);
}
return Z179;
}

static BOOLEAN Z205
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z199)
# else
(Z199)
Zfb3DLQ_0 Z199;
# endif
{
ZpmCQ_4 Z187, Z207;
Zfb3DLQ_0 Z208;
INTEGER Z209;

ZpmCQ_5(&Z187, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z207, (LONGCARD)Zpky9FDA_40);
ZdnD8D8D_14(Z199, &Z187);
Z209 = 0;
for (;;) {
ZdnD8D8D_9(Z199, &Z207);
while (!ZpmCQ_26(Z207)) {
Z208 = ZpmCQ_20(&Z207);
INC(Z209);
if (Z209 > 1) {
goto EXIT_1;
}
}
if (ZpmCQ_26(Z187)) {
goto EXIT_1;
}
Z199 = ZpmCQ_20(&Z187);
} EXIT_1:;
ZpmCQ_7(&Z187);
ZpmCQ_7(&Z207);
return Z209 == 1;
}

ZmfFRCAJK_2 ZmfFRCAJK_13
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z211, ZmfFRCAJK_3 Z212)
# else
(Z211, Z212)
ZmfFRCAJK_3 Z211, Z212;
# endif
{
Zfb3DLQ_0 Z214, Z215;
Zq7SFB_0 Z216, Z217;
INTEGER Z180;
ZmfFRCAJK_2 Z218;
ZpmCQ_4 Z219, Z187, Z207;

if (Z211 == NIL && Z212 == NIL) {
return ZmfFRCAJK_25;
}
if (Z211 == NIL) {
return ZmfFRCAJK_24;
}
if (Z212 == NIL) {
return ZmfFRCAJK_23;
}
Z214 = Z211->Y0;
Z216 = Zq7SFB_2(Z214);
Z215 = Z212->Y0;
Z217 = Zq7SFB_2(Z215);
if (Z216 == Zq7SFB_18 && Z217 == Zq7SFB_18) {
if (Z214 == Z215) {
return ZmfFRCAJK_25;
} else if (ZpmCQ_25((LONGCARD)Z214, &Z212->Y1)) {
Z173 = Z211;
return ZmfFRCAJK_24;
} else if (ZpmCQ_25((LONGCARD)Z215, &Z211->Y1)) {
return ZmfFRCAJK_23;
} else {
ZpmCQ_5(&Z219, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z207, (LONGCARD)Zpky9FDA_40);
Z223(Z214, &Z219);
Z223(Z215, &Z207);
ZpmCQ_10(&Z219, Z207);
if (ZpmCQ_26(Z219)) {
Z218 = ZmfFRCAJK_22;
} else {
Z218 = ZmfFRCAJK_21;
}
ZpmCQ_7(&Z207);
ZpmCQ_7(&Z219);
return Z218;
}
} else if (Z216 == Zq7SFB_18) {
if (ZpmCQ_25((LONGCARD)Z214, &Z212->Y1)) {
Z173 = Z211;
return ZmfFRCAJK_24;
} else {
ZpmCQ_5(&Z219, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z187, (LONGCARD)Zpky9FDA_40);
ZdnD8D8D_14(Z214, &Z219);
ZdnD8D8D_10(Z215, &Z187);
ZpmCQ_13(&Z219, (LONGCARD)Z214);
ZpmCQ_10(&Z219, Z187);
if (ZpmCQ_26(Z219)) {
Z218 = ZmfFRCAJK_22;
} else {
Z173 = Z211;
Z218 = ZmfFRCAJK_21;
}
ZpmCQ_7(&Z187);
ZpmCQ_7(&Z219);
return Z218;
}
} else if (Z217 == Zq7SFB_18) {
if (ZpmCQ_25((LONGCARD)Z215, &Z211->Y1)) {
return ZmfFRCAJK_23;
} else {
ZpmCQ_5(&Z219, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z187, (LONGCARD)Zpky9FDA_40);
ZdnD8D8D_14(Z215, &Z219);
ZdnD8D8D_10(Z214, &Z187);
ZpmCQ_13(&Z219, (LONGCARD)Z215);
ZpmCQ_10(&Z219, Z187);
if (ZpmCQ_26(Z219)) {
Z218 = ZmfFRCAJK_22;
} else {
Z218 = ZmfFRCAJK_21;
}
ZpmCQ_7(&Z187);
ZpmCQ_7(&Z219);
return Z218;
}
} else {
if (Z214 == Z215) {
Z218 = ZmfFRCAJK_25;
{
LONGINT B_11 = 1, B_12 = ZdnD8D8D_22(Z214);

if (B_11 <= B_12)
for (Z180 = B_11;; Z180 += 1) {
switch (ZmfFRCAJK_13(Z211->Y2->A[Z180], Z212->Y2->A[Z180])) {
case ZmfFRCAJK_25:;
break;
case ZmfFRCAJK_21:;
if (Z218 != ZmfFRCAJK_22) {
Z218 = ZmfFRCAJK_21;
}
break;
case ZmfFRCAJK_22:;
return ZmfFRCAJK_22;
break;
case ZmfFRCAJK_23:;
if (Z218 == ZmfFRCAJK_25) {
Z218 = ZmfFRCAJK_23;
} else if (Z218 == ZmfFRCAJK_24) {
Z218 = ZmfFRCAJK_21;
}
break;
case ZmfFRCAJK_24:;
if (Z218 == ZmfFRCAJK_25) {
Z218 = ZmfFRCAJK_24;
} else if (Z218 == ZmfFRCAJK_23) {
Z218 = ZmfFRCAJK_21;
}
break;
}
if (Z180 >= B_12) break;
}
}
return Z218;
} else {
return ZmfFRCAJK_22;
}
}
}

static void Z223
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z226, ZpmCQ_4 *Z227)
# else
(Z226, Z227)
Zfb3DLQ_0 Z226;
ZpmCQ_4 *Z227;
# endif
{
ZpmCQ_4 Z187, Z207;

ZpmCQ_32(Z227);
ZpmCQ_5(&Z187, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z207, (LONGCARD)Zpky9FDA_40);
ZdnD8D8D_14(Z226, &Z187);
for (;;) {
ZdnD8D8D_9(Z226, &Z207);
ZpmCQ_8(Z227, Z207);
if (ZpmCQ_26(Z187)) {
goto EXIT_2;
}
Z226 = ZpmCQ_20(&Z187);
} EXIT_2:;
ZpmCQ_7(&Z187);
ZpmCQ_7(&Z207);
}

void ZmfFRCAJK_15
 ARGS ((void))
{
Z173 = NIL;
}

ZmfFRCAJK_3 ZmfFRCAJK_16
 ARGS ((void))
{
return Z173;
}

void ZmfFRCAJK_17
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179, ZmfFRCAJK_3 Z180, Zn0DDDB_4 *Z231)
# else
(Z179, Z180, Z231)
ZmfFRCAJK_3 Z179, Z180;
Zn0DDDB_4 *Z231;
# endif
{
Zp1Fy8_2 Z232;
ZpmCQ_4 Z233;

Zp1Fy8_3(&Z232);
ZpmCQ_5(&Z233, (LONGCARD)Zpky9FDA_40);
Z234(Z180->Y0, &Z232, Z233);
while (!Zp1Fy8_6(Z232)) {
Zn0DDDB_14(Z231, (ADDRESS)Z196(Z235(Z179, Z180, (ZmfFRCAJK_3)Zp1Fy8_8(&Z232)), FALSE));
}
ZpmCQ_7(&Z233);
Zp1Fy8_4(&Z232);
}

void ZmfFRCAJK_18
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z199, Zp1Fy8_2 *Z232)
# else
(Z199, Z232)
Zfb3DLQ_0 Z199;
Zp1Fy8_2 *Z232;
# endif
{
ZpmCQ_4 Z233;

ZpmCQ_5(&Z233, (LONGCARD)Zpky9FDA_40);
Zp1Fy8_5(Z232);
Z234(Z199, Z232, Z233);
ZpmCQ_7(&Z233);
}

static void Z234
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z199, Zp1Fy8_2 *Z231, ZpmCQ_4 Z237)
# else
(Z199, Z231, Z237)
Zfb3DLQ_0 Z199;
Zp1Fy8_2 *Z231;
ZpmCQ_4 Z237;
# endif
{
ZpmCQ_4 Z207, Z187;
ZpmCQ_4 Z238;
Zfb3DLQ_0 Z208;
ZdnD8D8D_0 Z201;
ZmfFRCAJK_3 Z179;
INTEGER Z239;
Zfb3DLQ_0 Z198;

if (Zq7SFB_2(Z199) != Zq7SFB_18) {
ZblNKKO_82((STRING)"Synthesize", 10L);
}
ZpmCQ_5(&Z207, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z187, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z238, (LONGCARD)Zpky9FDA_40);
ZpmCQ_30(&Z238, Z237);
ZdnD8D8D_9(Z199, &Z207);
ZpmCQ_9(&Z207, Z237);
while (!ZpmCQ_26(Z207)) {
Z208 = ZpmCQ_20(&Z207);
Z198 = ZdnD8D8D_15(Z208);
if (Z198 != Zpky9FDA_39) {
if (Z199 == Z198) {
ZpmCQ_13(&Z238, (LONGCARD)Z208);
}
Z201 = ZdnD8D8D_24(Z208, Z199);
Z179 = ZmfFRCAJK_6(Z208);
{
LONGINT B_13 = 1, B_14 = ZdnD8D8D_22(Z208);

if (B_13 <= B_14)
for (Z239 = B_13;; Z239 += 1) {
ZmfFRCAJK_7(Z179, Z239, ZmfFRCAJK_6(ZdnD8D8D_25(Z201, Z239)));
if (Z239 >= B_14) break;
}
}
Zp1Fy8_7(Z231, (ADDRESS)Z179);
}
}
ZdnD8D8D_13(Z199, &Z187);
while (!ZpmCQ_26(Z187)) {
Z199 = ZpmCQ_20(&Z187);
Z234(Z199, Z231, Z238);
}
ZpmCQ_7(&Z187);
ZpmCQ_7(&Z207);
ZpmCQ_7(&Z238);
}

static ZmfFRCAJK_3 Z235
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z179, ZmfFRCAJK_3 Z180, ZmfFRCAJK_3 Z240)
# else
(Z179, Z180, Z240)
ZmfFRCAJK_3 Z179, Z180, Z240;
# endif
{
INTEGER Z241;
ZmfFRCAJK_3 Z194;

if (Z179 == Z180) {
Z194 = Z240;
} else {
Z194 = ZmfFRCAJK_6(Z179->Y0);
ZpmCQ_30(&Z194->Y1, Z179->Y1);
if (Zq7SFB_2(Z179->Y0) == Zq7SFB_19) {
{
LONGINT B_15 = 1, B_16 = ZdnD8D8D_22(Z179->Y0);

if (B_15 <= B_16)
for (Z241 = B_15;; Z241 += 1) {
Z194->Y2->A[Z241] = Z235(Z179->Y2->A[Z241], Z180, Z240);
if (Z241 >= B_16) break;
}
}
}
}
return Z194;
}

BOOLEAN ZmfFRCAJK_14
# ifdef HAVE_ARGS
(ZmfFRCAJK_3 Z211, ZmfFRCAJK_3 Z212)
# else
(Z211, Z212)
ZmfFRCAJK_3 Z211, Z212;
# endif
{
return ZmfFRCAJK_13(Z211, Z212) == ZmfFRCAJK_25;
}

void ZmfFRCAJK_20
# ifdef HAVE_ARGS
(ZfM_3 Z244, ZmfFRCAJK_3 Z179)
# else
(Z244, Z179)
ZfM_3 Z244;
ZmfFRCAJK_3 Z179;
# endif
{
INTEGER Z177, Z180;

if (Z179 == NIL) {
ZfM_29(Z244, (STRING)":", 1L);
} else {
Zfb3DLQ_7(Z244, Z179->Y0);
if (Zq7SFB_2(Z179->Y0) == Zq7SFB_19) {
ZfM_29(Z244, (STRING)" (", 2L);
Z177 = ZdnD8D8D_22(Z179->Y0);
if (Z177 > 0) {
Z180 = 0;
for (;;) {
INC(Z180);
ZmfFRCAJK_20(Z244, Z179->Y2->A[Z180]);
if (Z180 == Z177) {
goto EXIT_3;
}
ZfM_29(Z244, (STRING)", ", 2L);
} EXIT_3:;
}
ZfM_29(Z244, (STRING)")", 1L);
}
}
}

void BEGIN_Patterns ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Queues ();
BEGIN_Sets ();
BEGIN_Stack ();
BEGIN_DynArray ();
BEGIN_Errors ();
BEGIN_Grammar ();
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_rMemory ();
BEGIN_Queues ();
BEGIN_Scanner ();
BEGIN_Sets ();
BEGIN_Stack ();
BEGIN_Types ();
BEGIN_Scanner ();

}
