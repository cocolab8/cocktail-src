#include "SYSTEM_.h"

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Grammar
#include "Grammar.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_rMemory
#include "rMemory.h"
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

#ifndef DEFINITION_Lists
#include "Lists.h"
#endif

#ifndef DEFINITION_Stack
#include "Stack.h"
#endif

#ifndef DEFINITION_Reduced
#include "Reduced.h"
#endif

BOOLEAN Zol3CB23_0;
ZpmCQ_4 Zol3CB23_1;
ZpmCQ_4 Zol3CB23_2;

#define Z165	10000
static void Z171 ARGS ((ZpmCQ_4 Z167));
typedef struct S_1 {
BOOLEAN Y0;
Zp1Fy8_2 Y1;
} Z182;
typedef struct S_2 {
INTEGER Y0;
Zfb3DLQ_0 Y1;
Zfb3DLQ_0 Y2;
} Z185;
typedef Z182 *Z189;
typedef Z185 *Z190;
static struct S_3 {
Z189 A[Z165 + 1];
} *Z191;
static LONGINT Z192;
static Zp1Fy8_2 Z193;
static Zp1Fy8_2 Z194;
static void Z172 ARGS ((void));
static void Z197 ARGS ((void));
static void Z195 ARGS ((void));
static void Z200 ARGS ((void));
static void Z196 ARGS ((void));
static void Z198 ARGS ((void));
static void Z199 ARGS ((void));

void Zol3CB23_3
# ifdef HAVE_ARGS
(ZpmCQ_4 Z167)
# else
(Z167)
ZpmCQ_4 Z167;
# endif
{
Zol3CB23_0 = TRUE;
ZpmCQ_5(&Zol3CB23_1, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Zol3CB23_2, (LONGCARD)Zpky9FDA_40);
Z171(Z167);
Z172();
}

static void Z171
# ifdef HAVE_ARGS
(ZpmCQ_4 Z167)
# else
(Z167)
ZpmCQ_4 Z167;
# endif
{
ZpmCQ_4 Z173, Z174, Z175, Z176;
Zfb3DLQ_0 Z177, Z178, Z179;
ZdnD8D8D_0 Z180;
INTEGER Z181;

ZpmCQ_5(&Z173, (LONGCARD)Zpky9FDA_40);
Zq7SFB_11(&Z173);
ZpmCQ_5(&Z174, (LONGCARD)Zpky9FDA_40);
ZpmCQ_8(&Z174, Z167);
ZpmCQ_5(&Z175, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z176, (LONGCARD)Zpky9FDA_40);
ZpmCQ_9(&Z173, Z174);
while (!ZpmCQ_26(Z174)) {
Z178 = ZpmCQ_20(&Z174);
ZdnD8D8D_9(Z178, &Z176);
while (!ZpmCQ_26(Z176)) {
Z177 = ZpmCQ_20(&Z176);
if (ZdnD8D8D_22(Z177) != Zpky9FDA_38) {
Z180 = ZdnD8D8D_24(Z177, Z178);
{
LONGINT B_1 = 1, B_2 = ZdnD8D8D_22(Z177);

if (B_1 <= B_2)
for (Z181 = B_1;; Z181 += 1) {
Z179 = ZdnD8D8D_25(Z180, Z181);
if (ZpmCQ_25((LONGCARD)Z179, &Z173)) {
ZpmCQ_14(&Z173, (LONGCARD)Z179);
ZpmCQ_13(&Z174, (LONGCARD)Z179);
}
if (Z181 >= B_2) break;
}
}
}
}
ZdnD8D8D_14(Z178, &Z175);
ZpmCQ_10(&Z175, Z173);
ZpmCQ_9(&Z173, Z175);
ZpmCQ_8(&Z174, Z175);
}
if (!ZpmCQ_26(Z173)) {
Zol3CB23_0 = FALSE;
ZpmCQ_30(&Zol3CB23_1, Z173);
}
ZpmCQ_7(&Z175);
ZpmCQ_7(&Z176);
ZpmCQ_7(&Z173);
ZpmCQ_7(&Z174);
}

static void Z172
 ARGS ((void))
{
Zp1Fy8_3(&Z194);
Z195();
Z196();
Z197();
Z198();
Z199();
Z200();
Zp1Fy8_4(&Z194);
}

static void Z197
 ARGS ((void))
{
Z190 Z201;
Zfb3DLQ_0 Z178;
Zfb3DLQ_0 Z202;

while (!Zp1Fy8_6(Z194)) {
Z201 = (Z190)Zp1Fy8_8(&Z194);
Z178 = Z201->Y1;
Z202 = Z178;
for (;;) {
{
register Z182 *W_1 = Z191->A[Z178];

if (!W_1->Y0) {
while (!Zp1Fy8_6(W_1->Y1)) {
Z201 = (Z190)Zp1Fy8_8(&W_1->Y1);
{
register Z185 *W_2 = Z201;

DEC(W_2->Y0);
if (W_2->Y0 == 0) {
Zp1Fy8_7(&Z194, (ADDRESS)Z201);
}
}
}
W_1->Y0 = TRUE;
}
Z178 = ZdnD8D8D_11(Z178);
if (Z178 == Zpky9FDA_39 || Z178 == Z202) {
goto EXIT_1;
}
}
} EXIT_1:;
}
}

static void Z195
 ARGS ((void))
{
Zfb3DLQ_0 Z178;
ZpmCQ_4 Z175;

ZpmCQ_5(&Z175, (LONGCARD)Zpky9FDA_40);
Zq7SFB_11(&Z175);
Z192 = Zpky9FDA_40 + 1;
ZarQdhNDD_0((ADDRESS *)&Z191, &Z192, (LONGINT)sizeof (Z189));
while (!ZpmCQ_26(Z175)) {
Z178 = ZpmCQ_20(&Z175);
Z191->A[Z178] = (Z189)ZDtgCFKU_1((LONGINT)sizeof (Z182));
{
register Z182 *W_3 = Z191->A[Z178];

W_3->Y0 = FALSE;
Zp1Fy8_3(&W_3->Y1);
}
}
ZpmCQ_7(&Z175);
}

static void Z200
 ARGS ((void))
{
Zfb3DLQ_0 Z178;
ZpmCQ_4 Z175;

ZpmCQ_5(&Z175, (LONGCARD)Zpky9FDA_40);
Zq7SFB_11(&Z175);
while (!ZpmCQ_26(Z175)) {
Z178 = ZpmCQ_20(&Z175);
Zp1Fy8_4(&Z191->A[Z178]->Y1);
ZDtgCFKU_2((LONGINT)sizeof (Z182), (ADDRESS)Z191->A[Z178]);
}
ZarQdhNDD_3((ADDRESS *)&Z191, &Z192, (LONGINT)sizeof (Z189));
ZpmCQ_7(&Z175);
}

static void Z196
 ARGS ((void))
{
Z190 Z201;
ZpmCQ_4 Z176, Z175;
ZdnD8D8D_0 Z180;
Zfb3DLQ_0 Z179, Z178, Z177;
INTEGER Z181;

Zp1Fy8_3(&Z193);
ZpmCQ_5(&Z176, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z175, (LONGCARD)Zpky9FDA_40);
Zq7SFB_11(&Z175);
while (!ZpmCQ_26(Z175)) {
Z178 = ZpmCQ_20(&Z175);
ZdnD8D8D_9(Z178, &Z176);
while (!ZpmCQ_26(Z176)) {
Z177 = ZpmCQ_20(&Z176);
if (ZdnD8D8D_22(Z177) != Zpky9FDA_38) {
Z180 = ZdnD8D8D_24(Z177, Z178);
Z201 = (Z190)ZDtgCFKU_1((LONGINT)sizeof (Z185));
{
register Z185 *W_4 = Z201;

W_4->Y0 = ZdnD8D8D_22(Z177);
W_4->Y1 = Z178;
W_4->Y2 = Z177;
}
if (ZdnD8D8D_22(Z177) == 0) {
Zp1Fy8_7(&Z194, (ADDRESS)Z201);
}
{
LONGINT B_3 = 1, B_4 = ZdnD8D8D_22(Z177);

if (B_3 <= B_4)
for (Z181 = B_3;; Z181 += 1) {
Z179 = ZdnD8D8D_25(Z180, Z181);
if (Z179 != Zpky9FDA_39) {
Zp1Fy8_7(&Z191->A[Z179]->Y1, (ADDRESS)Z201);
}
if (Z181 >= B_4) break;
}
}
Zp1Fy8_7(&Z193, (ADDRESS)Z201);
}
}
}
ZpmCQ_7(&Z175);
ZpmCQ_7(&Z176);
}

static void Z198
 ARGS ((void))
{
Zfb3DLQ_0 Z178;
ZpmCQ_4 Z175;

ZpmCQ_5(&Z175, (LONGCARD)Zpky9FDA_40);
while (!ZpmCQ_26(Z175)) {
Z178 = ZpmCQ_20(&Z175);
{
register Z182 *W_5 = Z191->A[Z178];

if (!W_5->Y0) {
ZpmCQ_13(&Zol3CB23_2, (LONGCARD)Z178);
}
}
}
ZpmCQ_7(&Z175);
}

static void Z199
 ARGS ((void))
{
Zp1Fy8_2 Z176;
Z190 Z201;

Zp1Fy8_3(&Z176);
Zp1Fy8_11(&Z176, Z193);
while (!Zp1Fy8_6(Z176)) {
Z201 = (Z190)Zp1Fy8_8(&Z176);
{
register Z185 *W_6 = Z201;

if (W_6->Y0 > 0) {
}
}
}
Zp1Fy8_4(&Z176);
}

void BEGIN_Reduced ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Sets ();
BEGIN_DynArray ();
BEGIN_Grammar ();
BEGIN_Errors ();
BEGIN_Idents ();
BEGIN_rMemory ();
BEGIN_Scanner ();
BEGIN_Sets ();
BEGIN_Stack ();
BEGIN_Types ();
BEGIN_Lists ();
BEGIN_Stack ();

Zol3CB23_0 = FALSE;
}
