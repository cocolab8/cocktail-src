#include "SYSTEM_.h"

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
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

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_Pack
#include "Pack.h"
#endif

#ifndef DEFINITION_Info
#include "Info.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Queues
#include "Queues.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_Automaton
#include "Automaton.h"
#endif


#define Z156	-1
#define Z157	0
#define Z158	100
typedef INTEGER Z159;
typedef struct S_7 {
Z159 A[1000 + 1];
} *Z160;
typedef struct S_6 {
INTEGER A[1000 + 1];
} *Z161;
typedef struct S_1 *Z162;
typedef struct S_1 {
INTEGER Y0;
Z159 Y1;
Z162 Y2;
} Z163;
typedef struct S_2 {
Z162 Y0;
Z159 Y1;
} Z167;
typedef struct S_3 {
Z159 Y0;
Z159 Y1;
INTEGER Y2;
struct S_5 {
Z167 A[1000 + 1];
} *Y3;
INTEGER Y4;
LONGINT Y5;
struct S_4 {
INTEGER A[1000 + 1];
} *Y6;
LONGINT Y7;
} Z170;
static Z170 Z114;
static Z161 Z179;
static LONGINT Z180;
static INTEGER Z181;
static INTEGER Z182;
static Z159 Z195 ARGS ((void));
static Z159 Z193 ARGS ((Z159 Z186, INTEGER Z190));
static void Z194 ARGS ((Z159 Z186, INTEGER Z190, Z159 Z189));
static void Z198 ARGS ((void));
static void Z202 ARGS ((Z160 Z200, Z159 Z186));
static BOOLEAN Z203 ARGS ((Z160 Z200, Z159 Z186));
static void Z204 ARGS ((Z159 Z199, Z159 Z186, Z160 Z200));
static void Z206 ARGS ((void));
static BOOLEAN Z209 ARGS ((INTEGER Z208, Z159 Z186));
static void Z210 ARGS ((INTEGER Z208, Z159 Z186));
static void Z218 ARGS ((void));
static Z159 Z169 ARGS ((Z159 Z186));
static void Z223 ARGS ((Z159 Z186, Zn0DDDB_4 *Z222));
static void Z228 ARGS ((Z159 Z186));

void ZekSMF8FMG_0
# ifdef HAVE_ARGS
(INTEGER Z184, INTEGER Z185)
# else
(Z184, Z185)
INTEGER Z184;
INTEGER Z185;
# endif
{
Z159 Z186;

{
register Z170 *W_1 = &Z114;

W_1->Y0 = Z184;
W_1->Y1 = Z184;
W_1->Y2 = Z185;
W_1->Y5 = 4 * Z184 + 4;
ZarQdhNDD_0((ADDRESS *)&W_1->Y3, &W_1->Y5, (LONGINT)sizeof (Z167));
W_1->Y4 = W_1->Y5;
{
LONGINT B_1 = 0, B_2 = W_1->Y4 - 1;

if (B_1 <= B_2)
for (Z186 = B_1;; Z186 += 1) {
W_1->Y3->A[Z186].Y0 = NIL;
W_1->Y3->A[Z186].Y1 = Z156;
if (Z186 >= B_2) break;
}
}
}
}

void ZekSMF8FMG_1
# ifdef HAVE_ARGS
(Zn0DDDB_4 Z188, INTEGER Z189)
# else
(Z188, Z189)
Zn0DDDB_4 Z188;
INTEGER Z189;
# endif
{
Z159 Z186;
INTEGER Z190, Z191, Z192;

Z186 = Z157;
Z192 = 0;
Z191 = Zn0DDDB_16(Z188);
for (;;) {
INC(Z192);
Z190 = (INTEGER)Zn0DDDB_17(Z188, Z192);
if (Z192 == Z191) {
goto EXIT_1;
}
Z186 = Z193(Z186, Z190);
} EXIT_1:;
Z194(Z186, Z190, Z189);
}

static Z159 Z195
 ARGS ((void))
{
Z159 Z186, Z196;

{
register Z170 *W_2 = &Z114;

INC(W_2->Y1);
if (W_2->Y1 >= W_2->Y4) {
ZarQdhNDD_2((ADDRESS *)&W_2->Y3, &W_2->Y5, (LONGINT)sizeof (Z167));
}
Z196 = W_2->Y5;
{
LONGINT B_3 = W_2->Y4, B_4 = Z196 - 1;

if (B_3 <= B_4)
for (Z186 = B_3;; Z186 += 1) {
W_2->Y3->A[Z186].Y0 = NIL;
W_2->Y3->A[Z186].Y1 = Z156;
if (Z186 >= B_4) break;
}
}
W_2->Y4 = W_2->Y5;
return W_2->Y1;
}
}

static Z159 Z193
# ifdef HAVE_ARGS
(Z159 Z186, INTEGER Z190)
# else
(Z186, Z190)
Z159 Z186;
INTEGER Z190;
# endif
{
Z162 *Z197;

Z197 = (Z162 *)ADR (Z114.Y3->A[Z186].Y0);
for (;;) {
if (*Z197 == NIL) {
goto EXIT_2;
}
if ((*Z197)->Y0 == Z190) {
return (*Z197)->Y1;
}
Z197 = (Z162 *)ADR ((*Z197)->Y2);
} EXIT_2:;
*Z197 = (Z162)ZDtgCFKU_1((LONGINT)sizeof (Z163));
(*Z197)->Y0 = Z190;
(*Z197)->Y1 = Z195();
(*Z197)->Y2 = NIL;
return (*Z197)->Y1;
}

static void Z194
# ifdef HAVE_ARGS
(Z159 Z186, INTEGER Z190, Z159 Z189)
# else
(Z186, Z190, Z189)
Z159 Z186;
INTEGER Z190;
Z159 Z189;
# endif
{
Z162 *Z197;

Z197 = (Z162 *)ADR (Z114.Y3->A[Z186].Y0);
for (;;) {
if (*Z197 == NIL) {
goto EXIT_3;
}
if ((*Z197)->Y0 == Z190) {
ZblNKKO_82((STRING)"Automaton.SetTarget: already defined", 36L);
}
Z197 = (Z162 *)ADR ((*Z197)->Y2);
} EXIT_3:;
*Z197 = (Z162)ZDtgCFKU_1((LONGINT)sizeof (Z163));
(*Z197)->Y0 = Z190;
(*Z197)->Y1 = Z189;
(*Z197)->Y2 = NIL;
}

static void Z198
 ARGS ((void))
{
Z159 Z199, Z186;
INTEGER Z190;
Z160 Z200;
LONGINT Z201;

{
register Z170 *W_3 = &Z114;

Z201 = W_3->Y2 + 1;
ZarQdhNDD_0((ADDRESS *)&Z200, &Z201, (LONGINT)sizeof (Z159));
{
LONGINT B_5 = W_3->Y1 - 1, B_6 = W_3->Y0 + 1;

if (B_5 >= B_6)
for (Z199 = B_5;; Z199 += -1) {
Z202(Z200, Z199);
{
LONGINT B_7 = Z199 + 1, B_8 = W_3->Y1;

if (B_7 <= B_8)
for (Z186 = B_7;; Z186 += 1) {
if (Z203(Z200, Z186)) {
Z204(Z199, Z186, Z200);
}
if (Z186 >= B_8) break;
}
}
if (Z199 <= B_6) break;
}
}
ZarQdhNDD_3((ADDRESS *)&Z200, &Z201, (LONGINT)sizeof (Z159));
}
}

static void Z202
# ifdef HAVE_ARGS
(Z160 Z200, Z159 Z186)
# else
(Z200, Z186)
Z160 Z200;
Z159 Z186;
# endif
{
Z159 Z190;
Z162 Z197;

{
register Z170 *W_4 = &Z114;

{
LONGINT B_9 = 0, B_10 = W_4->Y2;

if (B_9 <= B_10)
for (Z190 = B_9;; Z190 += 1) {
Z200->A[Z190] = Z156;
if (Z190 >= B_10) break;
}
}
Z197 = W_4->Y3->A[Z186].Y0;
while (Z197 != NIL) {
Z200->A[Z197->Y0] = Z169(Z197->Y1);
Z197 = Z197->Y2;
}
}
}

static BOOLEAN Z203
# ifdef HAVE_ARGS
(Z160 Z200, Z159 Z186)
# else
(Z200, Z186)
Z160 Z200;
Z159 Z186;
# endif
{
Z162 Z197;

{
register Z170 *W_5 = &Z114;

if (W_5->Y3->A[Z186].Y1 != Z156) {
return FALSE;
}
Z197 = W_5->Y3->A[Z186].Y0;
while (Z197 != NIL) {
if (Z200->A[Z197->Y0] != Z156 && Z169(Z200->A[Z197->Y0]) != Z169(Z197->Y1)) {
return FALSE;
}
Z197 = Z197->Y2;
}
return TRUE;
}
}

static void Z204
# ifdef HAVE_ARGS
(Z159 Z199, Z159 Z186, Z160 Z200)
# else
(Z199, Z186, Z200)
Z159 Z199, Z186;
Z160 Z200;
# endif
{
Z162 Z197;
INTEGER Z190;
Z159 Z205;

{
register Z170 *W_6 = &Z114;

Z197 = W_6->Y3->A[Z186].Y0;
while (Z197 != NIL) {
Z190 = Z197->Y0;
if (Z200->A[Z190] == Z156) {
Z205 = Z169(Z197->Y1);
Z200->A[Z190] = Z205;
Z194(Z199, Z190, Z205);
}
Z197 = Z197->Y2;
}
W_6->Y3->A[Z186].Y1 = Z199;
}
}

static void Z206
 ARGS ((void))
{
Z159 Z186, Z207;
INTEGER Z208;

Z182 = -1;
Z181 = 0;
{
register Z170 *W_7 = &Z114;

{
LONGINT B_11 = Z157, B_12 = W_7->Y0;

if (B_11 <= B_12)
for (Z186 = B_11;; Z186 += 1) {
W_7->Y6->A[Z186] = Z186;
if (Z186 >= B_12) break;
}
}
{
LONGINT B_13 = W_7->Y0 + 1, B_14 = W_7->Y1;

if (B_13 <= B_14)
for (Z186 = B_13;; Z186 += 1) {
Z207 = W_7->Y3->A[Z186].Y1;
if (Z207 == Z156) {
Z208 = 0;
while (!Z209(Z208, Z186)) {
INC(Z208);
}
Z210(Z208, Z186);
} else {
Z208 = W_7->Y6->A[Z207];
}
W_7->Y6->A[Z186] = Z208;
if (Z186 >= B_14) break;
}
}
{
LONGINT B_15 = 0, B_16 = Z182;

if (B_15 <= B_16)
for (Z208 = B_15;; Z208 += 1) {
Z186 = Z179->A[Z208];
if (Z186 > W_7->Y0) {
Z179->A[Z208] = W_7->Y6->A[Z186];
}
if (Z208 >= B_16) break;
}
}
}
}

static BOOLEAN Z209
# ifdef HAVE_ARGS
(INTEGER Z208, Z159 Z186)
# else
(Z208, Z186)
INTEGER Z208;
Z159 Z186;
# endif
{
Z162 Z197;
INTEGER Z211;
INTEGER Z212, Z213;

Z197 = Z114.Y3->A[Z186].Y0;
while (Z197 != NIL) {
Z211 = Z208 + Z197->Y0;
if (Z211 > Z182) {
while (Z211 >= Z181) {
Z212 = Z181;
if (Z181 == 0) {
Z180 = Z158;
ZarQdhNDD_0((ADDRESS *)&Z179, &Z180, (LONGINT)sizeof (INTEGER));
} else {
ZarQdhNDD_2((ADDRESS *)&Z179, &Z180, (LONGINT)sizeof (INTEGER));
}
Z181 = Z180;
{
LONGINT B_17 = Z212, B_18 = Z181 - 1;

if (B_17 <= B_18)
for (Z213 = B_17;; Z213 += 1) {
Z179->A[Z213] = Z156;
if (Z213 >= B_18) break;
}
}
}
Z182 = Z211;
}
if (Z179->A[Z211] != Z156 && Z179->A[Z211] != Z197->Y1) {
return FALSE;
}
Z197 = Z197->Y2;
}
return TRUE;
}

static void Z210
# ifdef HAVE_ARGS
(INTEGER Z208, Z159 Z186)
# else
(Z208, Z186)
INTEGER Z208;
Z159 Z186;
# endif
{
Z162 Z197;

Z197 = Z114.Y3->A[Z186].Y0;
while (Z197 != NIL) {
Z179->A[Z208 + Z197->Y0] = Z197->Y1;
Z197 = Z197->Y2;
}
}

void ZekSMF8FMG_2
# ifdef HAVE_ARGS
(INTEGER *Z181)
# else
(Z181)
INTEGER *Z181;
# endif
{
Z198();
{
register Z170 *W_8 = &Z114;

W_8->Y7 = W_8->Y1 + 1;
ZarQdhNDD_0((ADDRESS *)&W_8->Y6, &W_8->Y7, (LONGINT)sizeof (INTEGER));
}
Z206();
*Z181 = Z182;
}

void ZekSMF8FMG_4
# ifdef HAVE_ARGS
(ZfM_3 Z216)
# else
(Z216)
ZfM_3 Z216;
# endif
{
INTEGER Z211;
Zmfy8_0 Z217;

Zmfy8_5(&Z217, Z216);
{
LONGINT B_19 = 0, B_20 = Z182;

if (B_19 <= B_20)
for (Z211 = B_19;; Z211 += 1) {
Zmfy8_7(Z217, Z179->A[Z211]);
if (Z211 >= B_20) break;
}
}
Zmfy8_8(&Z217);
}

static void Z218
 ARGS ((void))
{
{
register Z170 *W_9 = &Z114;

ZarQdhNDD_3((ADDRESS *)&W_9->Y6, &W_9->Y7, (LONGINT)sizeof (INTEGER));
}
}

INTEGER ZekSMF8FMG_3
# ifdef HAVE_ARGS
(INTEGER Z190)
# else
(Z190)
INTEGER Z190;
# endif
{
Z162 Z220;

{
register Z170 *W_10 = &Z114;

Z220 = W_10->Y3->A[Z157].Y0;
for (;;) {
if (Z220 == NIL) {
goto EXIT_4;
}
if (Z220->Y0 == Z190) {
return W_10->Y6->A[Z220->Y1];
}
Z220 = Z220->Y2;
} EXIT_4:;
ZblNKKO_82((STRING)"Automaton.StartIndex: not defined", 33L);
}
}

static Z159 Z169
# ifdef HAVE_ARGS
(Z159 Z186)
# else
(Z186)
Z159 Z186;
# endif
{
{
register Z170 *W_11 = &Z114;

while (Z186 > W_11->Y0 && W_11->Y3->A[Z186].Y1 != Z156) {
Z186 = W_11->Y3->A[Z186].Y1;
}
return Z186;
}
}

void ZekSMF8FMG_6
 ARGS ((void))
{
Zn0DDDB_4 Z222;

Zn0DDDB_5(&Z222);
Z223((LONGINT)Z157, &Z222);
Zn0DDDB_6(&Z222);
}

static void Z223
# ifdef HAVE_ARGS
(Z159 Z186, Zn0DDDB_4 *Z222)
# else
(Z186, Z222)
Z159 Z186;
Zn0DDDB_4 *Z222;
# endif
{
ZpmCQ_4 Z224;
Z162 Z220, Z197;
ZpmCQ_4 Z225;
ZpmCQ_4 *Z226;
INTEGER Z192;
Z159 Z205;

{
register Z170 *W_12 = &Z114;

ZpmCQ_5(&Z224, (LONGCARD)W_12->Y1);
ZpmCQ_5(&Z225, (LONGCARD)W_12->Y2);
Zn0DDDB_8(Z222, ADR (Z225));
Z220 = W_12->Y3->A[Z186].Y0;
for (;;) {
if (Z220 == NIL) {
goto EXIT_5;
}
Z205 = Z169(Z220->Y1);
if (!ZpmCQ_25((LONGCARD)Z205, &Z224)) {
ZpmCQ_32(&Z225);
ZpmCQ_13(&Z225, (LONGCARD)Z220->Y0);
Z197 = Z220->Y2;
while (Z197 != NIL) {
if (Z169(Z197->Y1) == Z205) {
ZpmCQ_13(&Z225, (LONGCARD)Z197->Y0);
}
Z197 = Z197->Y2;
}
if (Z205 > W_12->Y0) {
Z223(Z205, Z222);
} else {
Z226 = (ZpmCQ_4 *)Zn0DDDB_17(*Z222, 1L);
ZflEF_2((ZDz6VQCC_4)ZfM_1, *Z226);
Zp1BbM_23((STRING)" ", 1L);
{
LONGINT B_21 = 2, B_22 = Zn0DDDB_16(*Z222);

if (B_21 <= B_22)
for (Z192 = B_21;; Z192 += 1) {
Z226 = (ZpmCQ_4 *)Zn0DDDB_17(*Z222, Z192);
ZpmCQ_35((ZDz6VQCC_4)ZfM_1, *Z226);
Zp1BbM_23((STRING)" ", 1L);
if (Z192 >= B_22) break;
}
}
Zp1BbM_23((STRING)" = ", 3L);
Zp1BbM_19(Z205, 1L);
Zp1BbM_27();
}
ZpmCQ_13(&Z224, (LONGCARD)Z205);
}
Z220 = Z220->Y2;
} EXIT_5:;
Zn0DDDB_12(Z222);
ZpmCQ_7(&Z225);
ZpmCQ_7(&Z224);
}
}

void ZekSMF8FMG_5
 ARGS ((void))
{
Z159 Z186;

Zp1BbM_23((STRING)"Automaton", 9L);
Zp1BbM_27();
{
LONGINT B_23 = 0, B_24 = Z114.Y1;

if (B_23 <= B_24)
for (Z186 = B_23;; Z186 += 1) {
Z228(Z186);
if (Z186 >= B_24) break;
}
}
Zp1BbM_27();
}

static void Z228
# ifdef HAVE_ARGS
(Z159 Z186)
# else
(Z186)
Z159 Z186;
# endif
{
Z162 Z197;
Z159 Z229;

Z229 = Z114.Y3->A[Z186].Y1;
if (Z229 != Z156) {
Zp1BbM_19(Z186, 3L);
Zp1BbM_23((STRING)" -> ", 4L);
Zp1BbM_19(Z229, 3L);
Zp1BbM_27();
} else {
Z197 = Z114.Y3->A[Z186].Y0;
if (Z197 != NIL) {
Zp1BbM_19(Z186, 3L);
while (Z197 != NIL) {
Zp1BbM_23((STRING)"  (", 3L);
Zp1BbM_19(Z197->Y0, 1L);
Zp1BbM_23((STRING)", ", 2L);
Zp1BbM_19(Z197->Y1, 1L);
Zp1BbM_23((STRING)")", 1L);
Z197 = Z197->Y2;
}
Zp1BbM_27();
}
}
}

void ZekSMF8FMG_7
 ARGS ((void))
{
INTEGER Z208;

Zp1BbM_23((STRING)"Comb", 4L);
Zp1BbM_27();
Zp1BbM_23((STRING)"       ", 7L);
for (Z208 = 0; Z208 <= 9; Z208 += 1) {
Zp1BbM_19(Z208, 5L);
}
{
LONGINT B_25 = 0, B_26 = Z182;

if (B_25 <= B_26)
for (Z208 = B_25;; Z208 += 1) {
if (Z208 % 10 == 0) {
Zp1BbM_27();
Zp1BbM_19(Z208, 5L);
Zp1BbM_23((STRING)"  ", 2L);
}
Zp1BbM_19(Z179->A[Z208], 5L);
if (Z208 >= B_26) break;
}
}
Zp1BbM_27();
Zp1BbM_27();
}

void BEGIN_Automaton ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_Queues ();
BEGIN_DynArray ();
BEGIN_Errors ();
BEGIN_IO ();
BEGIN_rMemory ();
BEGIN_Queues ();
BEGIN_rSystem ();
BEGIN_Pack ();
BEGIN_Info ();
BEGIN_IO ();
BEGIN_Queues ();
BEGIN_StdIO ();
BEGIN_Sets ();

}
