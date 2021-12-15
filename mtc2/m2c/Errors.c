#include "SYSTEM_.h"

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_rMemory
#include "rMemory.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_General
#include "General.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif


#define Z140	64
#define Z141	TRUE
typedef struct S_1 {
CHAR A[255 + 1];
} Z142;
typedef struct S_2 {
union {
struct {
char dummy;
} V_1;
struct {
Zp1PEAFD_2 *Y0;
} V_2;
struct {
Z142 *Y1;
} V_3;
struct {
Zfb3DLQ_0 Y2;
} V_4;
} U_1;
SHORTCARD Y3;
SHORTCARD Y4;
SHORTCARD Y5;
SHORTCARD Y6;
Zfb3DLQ_0 Y7;
SHORTCARD Y8;
SHORTCARD Y9;
} Z143;
static struct S_3 {
Z143 A[Z140 - 1 + 1];
} Z158;
static CARDINAL Z159;
static struct S_4 {
CARDINAL A[ZblNKKO_33 - ZblNKKO_27 + 1];
} Z160;
static CARDINAL Z154;
static ZfM_3 Z163;
static void Z168 ARGS ((CARDINAL Z188, CARDINAL Z189, Zfb3DLQ_0 Z190, CARDINAL Z191, CARDINAL Z192, CARDINAL Z193, ADDRESS Z194));
static void Z183 ARGS ((INTEGER Z199, INTEGER Z200));
static BOOLEAN Z203 ARGS ((INTEGER Z201, INTEGER Z202));
static void Z204 ARGS ((INTEGER Z201, INTEGER Z202));
static void Z184 ARGS ((ZfM_3 Z206, CARDINAL Z153, CARDINAL Z154, CARDINAL Z156, CARDINAL Z157));
static void Z185 ARGS ((ZfM_3 Z206, CARDINAL Z151, ADDRESS Z167));

void ZblNKKO_39
# ifdef HAVE_ARGS
(CARDINAL Z153, CARDINAL Z154, ZmtLFGGBG_0 Z165)
# else
(Z153, Z154, Z165)
CARDINAL Z153, Z154;
ZmtLFGGBG_0 Z165;
# endif
{
ZblNKKO_40(Z153, Z154, Z165, (LONGCARD)ZblNKKO_34, (ADDRESS)NIL);
}

void ZblNKKO_40
# ifdef HAVE_ARGS
(CARDINAL Z153, CARDINAL Z154, ZmtLFGGBG_0 Z165, CARDINAL Z151, ADDRESS Z167)
# else
(Z153, Z154, Z165, Z151, Z167)
CARDINAL Z153, Z154;
ZmtLFGGBG_0 Z165;
CARDINAL Z151;
ADDRESS Z167;
# endif
{
Z168(Z153, Z154, Z165.Y0, (LONGCARD)Z165.Y1, (LONGCARD)Z165.Y2, Z151, Z167);
if (Z154 == ZblNKKO_27) {
ZblNKKO_45(Z141);
ZfM_34();
rExit(1L);
}
}

void ZblNKKO_41
# ifdef HAVE_ARGS
(CARDINAL Z153, CARDINAL Z154, ZmtLFGGBG_0 Z165)
# else
(Z153, Z154, Z165)
CARDINAL Z153, Z154;
ZmtLFGGBG_0 Z165;
# endif
{
ZblNKKO_42(Z153, Z154, Z165, (LONGCARD)ZblNKKO_34, (ADDRESS)NIL);
}

void ZblNKKO_42
# ifdef HAVE_ARGS
(CARDINAL Z153, CARDINAL Z154, ZmtLFGGBG_0 Z165, CARDINAL Z151, ADDRESS Z167)
# else
(Z153, Z154, Z165, Z151, Z167)
CARDINAL Z153, Z154;
ZmtLFGGBG_0 Z165;
CARDINAL Z151;
ADDRESS Z167;
# endif
{
Z168(Z153, Z154, Z165.Y0, (LONGCARD)Z165.Y1, (LONGCARD)Z165.Y2, Z151, Z167);
if (Z154 == ZblNKKO_27) {
ZblNKKO_45(Z141);
ZfM_34();
rExit(1L);
}
}

void ZblNKKO_43
# ifdef HAVE_ARGS
(CHAR Z173[], LONGCARD O_1)
# else
(Z173, O_1)
CHAR Z173[];
LONGCARD O_1;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z173, O_1, CHAR)
ZfM_29(Z163, Z173, O_1);
ZfM_29(Z163, (STRING)": assertion violation", 21L);
ZfM_33(Z163);
ZfM_34();
rExit(1L);
FREE_OPEN_ARRAYS
}

CARDINAL ZblNKKO_44
 ARGS ((void))
{
return Z160.A[ZblNKKO_27 - 1] + Z160.A[ZblNKKO_28 - 1] + Z160.A[ZblNKKO_29 - 1];
}

void ZblNKKO_45
# ifdef HAVE_ARGS
(BOOLEAN Z177)
# else
(Z177)
BOOLEAN Z177;
# endif
{
CARDINAL Z178, Z179, Z180;
Zfb3DLQ_0 Z181;

if (Z159 == 0) {
return;
}
if (Z177 && Z159 == Z160.A[ZblNKKO_30 - 1]) {
return;
}
Z178 = ZdaDDAD7_3((LONGINT)Z140, (LONGINT)Z159);
Z183(1L, (LONGINT)Z178);
Z181 = Zfb3DLQ_1;
{
LONGCARD B_1 = 1, B_2 = Z178;

if (B_1 <= B_2)
for (Z179 = B_1;; Z179 += 1) {
{
register Z143 *W_1 = &Z158.A[Z179 - 1];

if (Z177 && W_1->Y6 == ZblNKKO_30) {
} else {
if (W_1->Y7 != Z181) {
Zfb3DLQ_7(Z163, W_1->Y7);
ZfM_24(Z163, ':');
ZfM_33(Z163);
Z181 = W_1->Y7;
}
Z184(Z163, (LONGCARD)W_1->Y5, (LONGCARD)W_1->Y6, (LONGCARD)W_1->Y8, (LONGCARD)W_1->Y9);
Z185(Z163, (LONGCARD)W_1->Y3, (ADDRESS)W_1->U_1.V_2.Y0);
ZfM_33(Z163);
}
}
if (Z179 >= B_2) break;
}
}
for (Z180 = ZblNKKO_27; Z180 <= ZblNKKO_33; Z180 += 1) {
if (Z177 && Z180 == ZblNKKO_30) {
} else {
if (Z160.A[Z180 - 1] > 0) {
ZfM_29(Z163, (STRING)"  ", 2L);
ZfM_25(Z163, (LONGINT)Z160.A[Z180 - 1], 1L);
ZfM_24(Z163, ' ');
switch (Z180) {
case ZblNKKO_27:;
ZfM_29(Z163, (STRING)"fatal error(s)", 14L);
break;
case ZblNKKO_28:;
ZfM_29(Z163, (STRING)"restriction(s)", 14L);
break;
case ZblNKKO_29:;
ZfM_29(Z163, (STRING)"error(s)", 8L);
break;
case ZblNKKO_30:;
ZfM_29(Z163, (STRING)"warning(s)", 10L);
break;
case ZblNKKO_31:;
ZfM_29(Z163, (STRING)"repair(s)", 9L);
break;
case ZblNKKO_32:;
ZfM_29(Z163, (STRING)"note(s)", 7L);
break;
case ZblNKKO_33:;
ZfM_29(Z163, (STRING)"information(s)", 14L);
break;
}
}
}
}
ZfM_33(Z163);
}

static void Z168
# ifdef HAVE_ARGS
(CARDINAL Z188, CARDINAL Z189, Zfb3DLQ_0 Z190, CARDINAL Z191, CARDINAL Z192, CARDINAL Z193, ADDRESS Z194)
# else
(Z188, Z189, Z190, Z191, Z192, Z193, Z194)
CARDINAL Z188, Z189;
Zfb3DLQ_0 Z190;
CARDINAL Z191, Z192;
CARDINAL Z193;
ADDRESS Z194;
# endif
{
Zp1PEAFD_2 *Z195;
Z142 *Z196;
Zfb3DLQ_0 *Z197;

INC(Z160.A[Z189 - 1]);
if (Z159 < Z140) {
INC(Z159);
{
register Z143 *W_2 = &Z158.A[Z159 - 1];

W_2->Y4 = Z159;
W_2->Y5 = Z188;
W_2->Y6 = Z189;
W_2->Y7 = Z190;
W_2->Y8 = Z191;
W_2->Y9 = Z192;
W_2->Y3 = Z193;
switch (W_2->Y3) {
case ZblNKKO_36:;
Z195 = (Zp1PEAFD_2 *)Z194;
W_2->U_1.V_2.Y0 = (Zp1PEAFD_2 *)ZDtgCFKU_1((LONGINT)sizeof (Zp1PEAFD_2));
*W_2->U_1.V_2.Y0 = *Z195;
break;
case ZblNKKO_37:;
Z196 = (Z142 *)Z194;
W_2->U_1.V_3.Y1 = (Z142 *)ZDtgCFKU_1((LONGINT)sizeof (Z142));
*W_2->U_1.V_3.Y1 = *Z196;
break;
case ZblNKKO_38:;
Z197 = (SHORTCARD *)Z194;
W_2->U_1.V_4.Y2 = *Z197;
break;
default:
break;
}
if (Z159 == Z140) {
W_2->Y5 = ZblNKKO_5;
W_2->Y6 = ZblNKKO_28;
W_2->Y3 = ZblNKKO_34;
}
}
} else {
INC(Z159);
}
}

static void Z183
# ifdef HAVE_ARGS
(INTEGER Z199, INTEGER Z200)
# else
(Z199, Z200)
INTEGER Z199, Z200;
# endif
{
INTEGER Z201, Z202;

if (Z199 < Z200) {
Z201 = Z199 + 1;
Z202 = Z200;
do {
while (Z201 < Z200 && Z203(Z201, Z199)) {
INC(Z201);
}
while (Z199 < Z202 && Z203(Z199, Z202)) {
DEC(Z202);
}
if (Z201 < Z202) {
Z204(Z201, Z202);
}
} while (!(Z201 >= Z202));
Z204(Z199, Z202);
Z183(Z199, Z202 - 1);
Z183(Z202 + 1, Z200);
}
}

static BOOLEAN Z203
# ifdef HAVE_ARGS
(INTEGER Z201, INTEGER Z202)
# else
(Z201, Z202)
INTEGER Z201, Z202;
# endif
{
{
register Z143 *W_3 = &Z158.A[Z201 - 1];

if (W_3->Y7 < Z158.A[Z202 - 1].Y7) {
return TRUE;
}
if (W_3->Y7 > Z158.A[Z202 - 1].Y7) {
return FALSE;
}
if (W_3->Y8 < Z158.A[Z202 - 1].Y8) {
return TRUE;
}
if (W_3->Y8 > Z158.A[Z202 - 1].Y8) {
return FALSE;
}
if (W_3->Y9 < Z158.A[Z202 - 1].Y9) {
return TRUE;
}
if (W_3->Y9 > Z158.A[Z202 - 1].Y9) {
return FALSE;
}
return W_3->Y4 < Z158.A[Z202 - 1].Y4;
}
}

static void Z204
# ifdef HAVE_ARGS
(INTEGER Z201, INTEGER Z202)
# else
(Z201, Z202)
INTEGER Z201, Z202;
# endif
{
Z143 Z205;

Z205 = Z158.A[Z201 - 1];
Z158.A[Z201 - 1] = Z158.A[Z202 - 1];
Z158.A[Z202 - 1] = Z205;
}

static void Z184
# ifdef HAVE_ARGS
(ZfM_3 Z206, CARDINAL Z153, CARDINAL Z154, CARDINAL Z156, CARDINAL Z157)
# else
(Z206, Z153, Z154, Z156, Z157)
ZfM_3 Z206;
CARDINAL Z153, Z154;
CARDINAL Z156, Z157;
# endif
{
ZfM_25(Z206, (LONGINT)Z156, 3L);
ZfM_29(Z206, (STRING)", ", 2L);
ZfM_25(Z206, (LONGINT)Z157, 2L);
ZfM_29(Z206, (STRING)": ", 2L);
switch (Z154) {
case ZblNKKO_27:;
ZfM_29(Z206, (STRING)"Fatal        ", 13L);
break;
case ZblNKKO_28:;
ZfM_29(Z206, (STRING)"Restriction  ", 13L);
break;
case ZblNKKO_29:;
ZfM_29(Z206, (STRING)"Error        ", 13L);
break;
case ZblNKKO_30:;
ZfM_29(Z206, (STRING)"Warning      ", 13L);
break;
case ZblNKKO_31:;
ZfM_29(Z206, (STRING)"Repair       ", 13L);
break;
case ZblNKKO_32:;
ZfM_29(Z206, (STRING)"Note         ", 13L);
break;
case ZblNKKO_33:;
ZfM_29(Z206, (STRING)"Information  ", 13L);
break;
}
switch (Z153) {
case ZblNKKO_1:;
ZfM_29(Z206, (STRING)"syntax error", 12L);
break;
case ZblNKKO_2:;
ZfM_29(Z206, (STRING)"expected tokens:", 16L);
break;
case ZblNKKO_3:;
ZfM_29(Z206, (STRING)"restart point", 13L);
break;
case ZblNKKO_4:;
ZfM_29(Z206, (STRING)"token inserted :", 16L);
break;
case ZblNKKO_5:;
ZfM_29(Z206, (STRING)"too many errors", 15L);
break;
case ZblNKKO_6:;
ZfM_29(Z206, (STRING)"token found    :", 16L);
break;
case ZblNKKO_7:;
ZfM_29(Z206, (STRING)"found/expected :", 16L);
break;
case ZblNKKO_8:;
ZfM_29(Z206, (STRING)"illegal character", 17L);
break;
case ZblNKKO_9:;
ZfM_29(Z206, (STRING)"unclosed comment", 16L);
break;
case ZblNKKO_10:;
ZfM_29(Z206, (STRING)"unclosed string", 15L);
break;
case ZblNKKO_11:;
ZfM_29(Z206, (STRING)"cyclic module dependency", 24L);
break;
case ZblNKKO_12:;
ZfM_29(Z206, (STRING)"cannot find definition module", 29L);
break;
case ZblNKKO_13:;
ZfM_29(Z206, (STRING)"cannot translate standard procedure NEWPROCESS", 46L);
break;
case ZblNKKO_14:;
ZfM_29(Z206, (STRING)"cannot translate standard procedure TRANSFER", 44L);
break;
case ZblNKKO_15:;
ZfM_29(Z206, (STRING)"cannot translate standard procedure IOTRANSFER", 46L);
break;
case ZblNKKO_16:;
ZfM_29(Z206, (STRING)"cannot translate forward reference to non structured type", 57L);
break;
case ZblNKKO_17:;
ZfM_29(Z206, (STRING)"cannot resolve name conflict with opaque type", 45L);
break;
case ZblNKKO_18:;
ZfM_29(Z206, (STRING)"name conflict with FOREIGN procedure", 36L);
break;
case ZblNKKO_19:;
ZfM_29(Z206, (STRING)"use of '_' in identifiers may lead to name conflicts", 52L);
break;
case ZblNKKO_20:;
ZfM_29(Z206, (STRING)"constant out of long range", 26L);
break;
case ZblNKKO_21:;
ZfM_29(Z206, (STRING)"cannot take the address of a call", 33L);
break;
case ZblNKKO_22:;
ZfM_29(Z206, (STRING)"undeclared identifier", 21L);
break;
case ZblNKKO_23:;
ZfM_29(Z206, (STRING)"illegal assignment", 18L);
break;
case ZblNKKO_24:;
ZfM_29(Z206, (STRING)"Tcl/Tk ", 7L);
break;
case ZblNKKO_25:;
ZfM_29(Z206, (STRING)"ConfigureTree: unknown parameter", 32L);
break;
default:
ZfM_25(Z206, (LONGINT)Z153, 1L);
break;
}
}

static void Z185
# ifdef HAVE_ARGS
(ZfM_3 Z206, CARDINAL Z151, ADDRESS Z167)
# else
(Z206, Z151, Z167)
ZfM_3 Z206;
CARDINAL Z151;
ADDRESS Z167;
# endif
{
Zp1PEAFD_2 *Z195;
Z142 *Z196;
Zfb3DLQ_0 *Z197;

if (Z151 == ZblNKKO_34) {
return;
}
ZfM_24(Z206, ' ');
switch (Z151) {
case ZblNKKO_36:;
Z195 = (Zp1PEAFD_2 *)Z167;
Zp1PEAFD_21(Z206, Z195);
break;
case ZblNKKO_37:;
Z196 = (Z142 *)Z167;
ZfM_29(Z206, (*Z196).A, 256L);
break;
case ZblNKKO_38:;
Z197 = (SHORTCARD *)ADR (Z167);
Zfb3DLQ_7(Z206, *Z197);
break;
default:
break;
}
}

void BEGIN_Errors ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Position ();
BEGIN_rSystem ();
BEGIN_rMemory ();
BEGIN_IO ();
BEGIN_General ();
BEGIN_Strings ();
BEGIN_Scanner ();
BEGIN_Idents ();
BEGIN_Position ();
BEGIN_Strings ();

Z159 = 0;
Z163 = ZfM_1;
for (Z154 = ZblNKKO_27; Z154 <= ZblNKKO_33; Z154 += 1) {
Z160.A[Z154 - 1] = 0;
}
}
