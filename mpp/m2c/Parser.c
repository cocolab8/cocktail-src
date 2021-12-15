#include "SYSTEM_.h"

#ifndef DEFINITION_Pack
#include "Pack.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Table
#include "Table.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

ZmfDOBA_0 ZmfDOBA_1;

#define Z133	'\t'
#define Z134	0
typedef struct S_1 *Z135;
typedef struct S_1 {
Z135 Y0;
SHORTCARD Y1;
} Z136;
typedef struct S_2 {
BITSET A[0 + 1];
} Z139;
static SHORTCARD Z140;
static INTEGER Z141;
static BOOLEAN Z142;
static BOOLEAN Z143;
static struct S_3 {
Z139 A[25 + 1];
} Z144;
static struct S_4 {
BITSET A[12 + 1];
} Z145;
static void Z149 ARGS ((CHAR Z150[], LONGCARD O_3, CHAR Z151[], LONGCARD O_2));
static BOOLEAN Z159 ARGS ((Z139 *Z160, SHORTCARD Z161));
static void Z162 ARGS ((Z139 *Z160, SHORTCARD Z161));
static void Z163 ARGS ((Z139 *Z160, SHORTCARD Z161));
static void Z164 ARGS ((void));
struct S_8 {
CHAR A[255 + 1];
};
static void Z178 ARGS ((SHORTCARD Z138, Z135 Z137));
static void Z180 ARGS ((SHORTCARD Z181, SHORTCARD Z138, Z135 Z137));
struct S_7 {
CHAR A[255 + 1];
};
static void Z158 ARGS ((SHORTCARD Z186, SHORTCARD Z138, Z135 Z137));
struct S_6 {
CHAR A[255 + 1];
};
static void Z190 ARGS ((SHORTCARD Z186, SHORTCARD Z138, Z135 Z137, Zpky9FDA_0 *Z191));
struct S_5 {
CHAR A[255 + 1];
};
static void Z179 ARGS ((SHORTCARD Z138, Z135 Z137));
static CARDINAL Z197, Z198, Z199;
static void Z200 ARGS ((CARDINAL Z201));
static void Z202 ARGS ((CARDINAL Z201));
static void Z154 ARGS ((void));
static void Z156 ARGS ((ZmfDOBA_0 *Z207, Z135 Z209));
static void Z212 ARGS ((ZmfDOBA_0 *Z213, Z135 Z209));
static void Z217 ARGS ((ZmfDOBA_0 *Z220, Z135 Z209));
static void Z218 ARGS ((ZmfDOBA_0 *Z229, Z135 Z209));
static void Z219 ARGS ((ZmfDOBA_0 *Z234, Z135 Z209));
static void Z226 ARGS ((ZmfDOBA_0 *Z237, Z135 Z209));
static void Z233 ARGS ((ZmfDOBA_0 *Z239, Z135 Z209));
static void Z228 ARGS ((ZmfDOBA_0 *Z240, Z135 Z209));
static void Z236 ARGS ((ZmfDOBA_0 *Z242, Z135 Z209));

static void Z149
# ifdef HAVE_ARGS
(CHAR Z150[], LONGCARD O_3, CHAR Z151[], LONGCARD O_2)
# else
(Z150, O_3, Z151, O_2)
CHAR Z150[];
LONGCARD O_3;
CHAR Z151[];
LONGCARD O_2;
# endif
{
CARDINAL Z152, Z153;
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_3 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z150, O_3, CHAR)
if ((O_3 - 1) < (O_2 - 1)) {
Z153 = (O_3 - 1);
} else {
Z153 = (O_2 - 1);
}
{
LONGCARD B_1 = 0, B_2 = Z153;

if (B_1 <= B_2)
for (Z152 = B_1;; Z152 += 1) {
Z151[Z152] = Z150[Z152];
if (Z152 >= B_2) break;
}
}
if ((O_2 - 1) > Z153) {
Z151[Z153 + 1] = CHR(0);
}
FREE_OPEN_ARRAYS
}

void ZmfDOBA_4
# ifdef HAVE_ARGS
(CARDINAL Z147, CHAR Z148[], LONGCARD O_1)
# else
(Z147, Z148, O_1)
CARDINAL Z147;
CHAR Z148[];
LONGCARD O_1;
# endif
{
switch (Z147) {
case 0:;
Z149((STRING)"_EOF_", 5L, Z148, O_1);
break;
case 1:;
Z149((STRING)" ", 1L, Z148, O_1);
break;
case 2:;
Z149((STRING)"^", 1L, Z148, O_1);
break;
case 3:;
Z149((STRING)"%", 1L, Z148, O_1);
break;
case 4:;
Z149((STRING)"$", 1L, Z148, O_1);
break;
case 5:;
Z149((STRING)".", 1L, Z148, O_1);
break;
case 6:;
Z149((STRING)"\\", 1L, Z148, O_1);
break;
case 7:;
Z149((STRING)"{", 1L, Z148, O_1);
break;
case 8:;
Z149((STRING)"}", 1L, Z148, O_1);
break;
case 9:;
Z149((STRING)"nl", 2L, Z148, O_1);
break;
case 10:;
Z149((STRING)"bnl", 3L, Z148, O_1);
break;
case 11:;
Z149((STRING)"char", 4L, Z148, O_1);
break;
case 12:;
Z149((STRING)"tab", 3L, Z148, O_1);
break;
}
}

INTEGER ZmfDOBA_2
 ARGS ((void))
{
Z141 = 0;
Z154();
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z156(&ZmfDOBA_1, (Z135)NIL);
if (Z140 != Z134) {
Z158(Z134, 0, (Z135)NIL);
}
return Z141;
}

static BOOLEAN Z159
# ifdef HAVE_ARGS
(Z139 *Z160, SHORTCARD Z161)
# else
(Z160, Z161)
Z139 *Z160;
SHORTCARD Z161;
# endif
{
return IN(Z161 % 32, Z160->A[Z161 / 32]);
}

static void Z162
# ifdef HAVE_ARGS
(Z139 *Z160, SHORTCARD Z161)
# else
(Z160, Z161)
Z139 *Z160;
SHORTCARD Z161;
# endif
{
INCL(Z160->A[Z161 / 32], Z161 % 32);
}

static void Z163
# ifdef HAVE_ARGS
(Z139 *Z160, SHORTCARD Z161)
# else
(Z160, Z161)
Z139 *Z160;
SHORTCARD Z161;
# endif
{
EXCL(Z160->A[Z161 / 32], Z161 % 32);
}

static void Z164
 ARGS ((void))
{
struct S_8 Z165;
Zp1PEAFD_2 Z166;
Zp1PEAFD_2 Z168;

INC(Z141);
ZblNKKO_77((LONGCARD)ZblNKKO_1, (LONGCARD)ZblNKKO_16, Zpky9FDA_1.Y0);
ZmfDOBA_4((LONGCARD)Z140, Z165.A, 256L);
Zp1PEAFD_13(Z165.A, 256L, &Z166);
ZblNKKO_78((LONGCARD)ZblNKKO_10, (LONGCARD)ZblNKKO_20, Zpky9FDA_1.Y0, (LONGCARD)ZblNKKO_28, ADR (Z166));
}

static void Z178
# ifdef HAVE_ARGS
(SHORTCARD Z138, Z135 Z137)
# else
(Z138, Z137)
SHORTCARD Z138;
Z135 Z137;
# endif
{
if (!Z143) {
Z164();
Z179(Z138, Z137);
}
}

static void Z180
# ifdef HAVE_ARGS
(SHORTCARD Z181, SHORTCARD Z138, Z135 Z137)
# else
(Z181, Z138, Z137)
SHORTCARD Z181;
SHORTCARD Z138;
Z135 Z137;
# endif
{
SHORTCARD Z147;
struct S_7 Z165;
Zp1PEAFD_2 Z166;
Zp1PEAFD_2 Z168;

if (!Z143) {
Z164();
Zp1PEAFD_4(&Z168);
for (Z147 = 0; Z147 <= 12; Z147 += 1) {
if (Z159(&Z144.A[Z181], Z147)) {
ZmfDOBA_4((LONGCARD)Z147, Z165.A, 256L);
Zp1PEAFD_13(Z165.A, 256L, &Z166);
if (Zp1PEAFD_7(&Z168) + Zp1PEAFD_7(&Z166) + 1 <= Zp1PEAFD_0) {
Zp1PEAFD_5(&Z168, &Z166);
Zp1PEAFD_6(&Z168, ' ');
}
}
}
ZblNKKO_78((LONGCARD)ZblNKKO_2, (LONGCARD)ZblNKKO_20, Zpky9FDA_1.Y0, (LONGCARD)ZblNKKO_28, ADR (Z168));
Z179(Z138, Z137);
}
}

static void Z158
# ifdef HAVE_ARGS
(SHORTCARD Z186, SHORTCARD Z138, Z135 Z137)
# else
(Z186, Z138, Z137)
SHORTCARD Z186;
SHORTCARD Z138;
Z135 Z137;
# endif
{
struct S_6 Z165;
Zp1PEAFD_2 Z166;

if (!Z143) {
Z164();
ZmfDOBA_4((LONGCARD)Z186, Z165.A, 256L);
Zp1PEAFD_13(Z165.A, 256L, &Z166);
ZblNKKO_78((LONGCARD)ZblNKKO_2, (LONGCARD)ZblNKKO_20, Zpky9FDA_1.Y0, (LONGCARD)ZblNKKO_28, ADR (Z166));
Z179(Z138, Z137);
}
if (Z140 != Z186) {
ZmfDOBA_4((LONGCARD)Z186, Z165.A, 256L);
ZblNKKO_78((LONGCARD)ZblNKKO_4, (LONGCARD)ZblNKKO_18, Zpky9FDA_1.Y0, (LONGCARD)ZblNKKO_29, ADR (Z165));
} else {
if (Z140 != Z134) {
Z140 = Zpky9FDA_4();
}
Z143 = FALSE;
}
}

static void Z190
# ifdef HAVE_ARGS
(SHORTCARD Z186, SHORTCARD Z138, Z135 Z137, Zpky9FDA_0 *Z191)
# else
(Z186, Z138, Z137, Z191)
SHORTCARD Z186;
SHORTCARD Z138;
Z135 Z137;
Zpky9FDA_0 *Z191;
# endif
{
struct S_5 Z165;
Zp1PEAFD_2 Z166;

if (!Z143) {
Z164();
ZmfDOBA_4((LONGCARD)Z186, Z165.A, 256L);
Zp1PEAFD_13(Z165.A, 256L, &Z166);
ZblNKKO_78((LONGCARD)ZblNKKO_2, (LONGCARD)ZblNKKO_20, Zpky9FDA_1.Y0, (LONGCARD)ZblNKKO_28, ADR (Z166));
Z179(Z138, Z137);
}
if (Z140 != Z186) {
ZmfDOBA_4((LONGCARD)Z186, Z165.A, 256L);
ZblNKKO_78((LONGCARD)ZblNKKO_4, (LONGCARD)ZblNKKO_18, Zpky9FDA_1.Y0, (LONGCARD)ZblNKKO_29, ADR (Z165));
Zpky9FDA_5((LONGCARD)Z186, Z191);
} else {
*Z191 = Zpky9FDA_1;
if (Z140 != Z134) {
Z140 = Zpky9FDA_4();
}
Z143 = FALSE;
}
}

static void Z179
# ifdef HAVE_ARGS
(SHORTCARD Z138, Z135 Z137)
# else
(Z138, Z137)
SHORTCARD Z138;
Z135 Z137;
# endif
{
Z139 Z194;
BOOLEAN Z195;

Z194 = Z144.A[Z138];
INCL(Z194.A[0], Z134);
while (Z137 != NIL) {
Z194.A[0] = Z194.A[0] | Z144.A[Z137->Y1].A[0];
Z137 = Z137->Y0;
}
Z195 = FALSE;
while (!Z159(&Z194, Z140)) {
Z140 = Zpky9FDA_4();
Z195 = TRUE;
}
if (Z195) {
ZblNKKO_77((LONGCARD)ZblNKKO_3, (LONGCARD)ZblNKKO_20, Zpky9FDA_1.Y0);
}
Z143 = TRUE;
}

static void Z200
# ifdef HAVE_ARGS
(CARDINAL Z201)
# else
(Z201)
CARDINAL Z201;
# endif
{
CARDINAL Z152;

if (Z197 > Z198) {
Z197 = 0;
INC(Z199);
}
if (Z197 == 0) {
Z198 = Z201;
for (Z152 = 0; Z152 <= 12; Z152 += 1) {
Z163(&Z144.A[Z199], (SHORTCARD)Z152);
}
} else {
Z162(&Z144.A[Z199], (SHORTCARD)Z201);
}
INC(Z197);
}

static void Z202
# ifdef HAVE_ARGS
(CARDINAL Z201)
# else
(Z201)
CARDINAL Z201;
# endif
{
if (Z197 > Z198) {
Z197 = 0;
INC(Z199);
}
if (Z197 == 0) {
Z198 = Z201;
Z145.A[Z199] = 0X0L;
} else {
INCL(Z145.A[Z199], Z201);
}
INC(Z197);
}

static void Z154
 ARGS ((void))
{
Zmfy8_1 Z203;

if (Z142) {
return;
}
Zpky9FDA_2();
Z199 = 0;
Z198 = 0;
Z197 = 0;
Z203 = Z200;
Zmfy8_9(Z203, (STRING)"+7,-./012345676,-./01234674,-./014675,-./0124675,-./013", 55L, 55L);
Zmfy8_9(Z203, (STRING)"467,46,-./0124567-45,5-,7,,,75,-./0123674,-./01367,34,-", 55L, 55L);
Zmfy8_9(Z203, (STRING)"./012673,-./0167,-,.,/,0,60,1237,1,2", 36L, 36L);
Z199 = 0;
Z198 = 0;
Z197 = 0;
Z203 = Z202;
Zmfy8_9(Z203, (STRING)"+0+,-/0/+,-//+,-//+,-//+,-//+,-/.+-/-+/-+.-+./+,-/0+,-/", 55L, 55L);
Zmfy8_9(Z203, (STRING)"0", 1L, 1L);
Z142 = TRUE;
}

void ZmfDOBA_3
 ARGS ((void))
{
Zpky9FDA_3();
}

static void Z156
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z207, Z135 Z209)
# else
(Z207, Z209)
ZmfDOBA_0 *Z207;
Z135 Z209;
# endif
{
ZmfDOBA_0 Z210;
Z136 Z211;

Z211.Y0 = Z209;
for (;;) {
if (IN(0, Z145.A[Z140])) {
Z211.Y1 = 0;
Z212(&Z210, (Z135)ADR (Z211));
} else if (Z140 == 0 || Z143) {
goto EXIT_1;
} else {
Z180(1, 1, Z209);
}
} EXIT_1:;
}

static void Z212
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z213, Z135 Z209)
# else
(Z213, Z209)
ZmfDOBA_0 *Z213;
Z135 Z209;
# endif
{
ZmfDOBA_0 Z214;
ZmfDOBA_0 Z215;
ZmfDOBA_0 Z216;
Z136 Z211;

Z211.Y0 = Z209;
for (;;) {
switch (Z140) {
case 5:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
for (;;) {
switch (Z140) {
case 5:;
Z211.Y1 = 0;
Z217(&Z214, (Z135)ADR (Z211));
goto EXIT_3;
break;
case 1:;
case 2:;
case 3:;
case 4:;
case 6:;
case 7:;
case 8:;
case 9:;
case 10:;
case 11:;
case 12:;
Z211.Y1 = 0;
Z218(&Z215, (Z135)ADR (Z211));
goto EXIT_3;
break;
default:
if (Z143) {
Z211.Y1 = 0;
Z218(&Z215, (Z135)ADR (Z211));
goto EXIT_3;
}
Z180(1, 1, Z209);
break;
}
} EXIT_3:;
goto EXIT_2;
break;
case 1:;
case 2:;
case 3:;
case 4:;
case 6:;
case 7:;
case 8:;
case 9:;
case 10:;
case 11:;
case 12:;
Z211.Y1 = 0;
Z219(&Z216, (Z135)ADR (Z211));
goto EXIT_2;
break;
default:
if (Z143) {
Z211.Y1 = 0;
Z219(&Z216, (Z135)ADR (Z211));
goto EXIT_2;
}
Z180(1, 1, Z209);
break;
}
} EXIT_2:;
}

static void Z217
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z220, Z135 Z209)
# else
(Z220, Z209)
ZmfDOBA_0 *Z220;
Z135 Z209;
# endif
{
Zpky9FDA_0 Z221;
Zpky9FDA_0 Z222;
ZmfDOBA_0 Z223, Z224;
ZmfDOBA_0 Z225;
Z136 Z211;

Z211.Y0 = Z209;
if (Z140 != 5) {
Z158(5, 2, Z209);
} else {
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Z211.Y1 = 2;
Z226(&Z223, (Z135)ADR (Z211));
for (;;) {
switch (Z140) {
case 11:;
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
goto EXIT_4;
break;
case 2:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '^';
goto EXIT_4;
break;
case 3:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '%';
goto EXIT_4;
break;
case 4:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '$';
goto EXIT_4;
break;
case 7:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '{';
goto EXIT_4;
break;
case 8:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '}';
goto EXIT_4;
break;
case 6:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '\\';
goto EXIT_4;
break;
default:
if (Z143) {
if (Z140 != 11) {
Z190(11, 3, Z209, &Z222);
} else {
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
goto EXIT_4;
}
Z180(2, 2, Z209);
break;
}
} EXIT_4:;
Z211.Y1 = 3;
Z226(&Z224, (Z135)ADR (Z211));
Zp1PEAFD_4(&Z225);
for (;;) {
if (IN(1, Z145.A[Z140])) {
Z211.Y1 = 6;
Z228(&Z225, (Z135)ADR (Z211));
goto EXIT_5;
} else if (Z140 == 9 || Z143) {
goto EXIT_5;
}
Z180(3, 3, Z209);
} EXIT_5:;
if (Z140 != 9) {
Z190(9, 6, Z209, &Z221);
} else {
Z221 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zqjx8B_0(Z222.Y1, &Z225);
Zqjx8B_5();
}

static void Z218
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z229, Z135 Z209)
# else
(Z229, Z209)
ZmfDOBA_0 *Z229;
Z135 Z209;
# endif
{
Zpky9FDA_0 Z221, Z230;
Zpky9FDA_0 Z231;
Zpky9FDA_0 Z222;
ZmfDOBA_0 Z223;
ZmfDOBA_0 Z225;
ZmfDOBA_0 Z232;
Z136 Z211;

Z211.Y0 = Z209;
for (;;) {
switch (Z140) {
case 2:;
case 3:;
case 4:;
case 7:;
case 8:;
case 11:;
Zp1PEAFD_4(&Z225);
for (;;) {
switch (Z140) {
case 11:;
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
goto EXIT_7;
break;
case 2:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '^';
goto EXIT_7;
break;
case 3:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '%';
goto EXIT_7;
break;
case 4:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '$';
goto EXIT_7;
break;
case 7:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '{';
goto EXIT_7;
break;
case 8:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '}';
goto EXIT_7;
break;
default:
if (Z143) {
if (Z140 != 11) {
Z190(11, 3, Z209, &Z222);
} else {
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
goto EXIT_7;
}
Z180(2, 2, Z209);
break;
}
} EXIT_7:;
for (;;) {
if (IN(1, Z145.A[Z140])) {
Z211.Y1 = 6;
Z228(&Z225, (Z135)ADR (Z211));
goto EXIT_8;
} else if (Z140 == 9 || Z143) {
goto EXIT_8;
}
Z180(3, 3, Z209);
} EXIT_8:;
if (Z140 != 9) {
Z190(9, 6, Z209, &Z221);
} else {
Z221 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zqjx8B_1(Z222.Y1, &Z225);
goto EXIT_6;
break;
case 1:;
case 5:;
case 6:;
case 9:;
case 10:;
case 12:;
Zqjx8B_2();
Z211.Y1 = 7;
Z226(&Z223, (Z135)ADR (Z211));
for (;;) {
if (IN(2, Z145.A[Z140])) {
Z211.Y1 = 8;
Z233(&Z232, (Z135)ADR (Z211));
} else if (IN(3, Z145.A[Z140]) || Z143) {
goto EXIT_9;
} else {
Z180(7, 7, Z209);
}
} EXIT_9:;
for (;;) {
switch (Z140) {
case 9:;
Z230 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zqjx8B_3();
goto EXIT_10;
break;
case 10:;
Z231 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
goto EXIT_10;
break;
default:
if (Z143) {
if (Z140 != 9) {
Z190(9, 6, Z209, &Z230);
} else {
Z230 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zqjx8B_3();
goto EXIT_10;
}
Z180(8, 8, Z209);
break;
}
} EXIT_10:;
goto EXIT_6;
break;
default:
if (Z143) {
Zqjx8B_2();
Z211.Y1 = 7;
Z226(&Z223, (Z135)ADR (Z211));
for (;;) {
if (IN(2, Z145.A[Z140])) {
Z211.Y1 = 8;
Z233(&Z232, (Z135)ADR (Z211));
} else if (IN(3, Z145.A[Z140]) || Z143) {
goto EXIT_11;
} else {
Z180(7, 7, Z209);
}
} EXIT_11:;
for (;;) {
switch (Z140) {
case 9:;
Z230 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zqjx8B_3();
goto EXIT_12;
break;
case 10:;
Z231 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
goto EXIT_12;
break;
default:
if (Z143) {
if (Z140 != 9) {
Z190(9, 6, Z209, &Z230);
} else {
Z230 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zqjx8B_3();
goto EXIT_12;
}
Z180(8, 8, Z209);
break;
}
} EXIT_12:;
goto EXIT_6;
}
Z180(1, 1, Z209);
break;
}
} EXIT_6:;
Zqjx8B_5();
}

static void Z219
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z234, Z135 Z209)
# else
(Z234, Z209)
ZmfDOBA_0 *Z234;
Z135 Z209;
# endif
{
Zpky9FDA_0 Z221;
Zpky9FDA_0 Z231;
ZmfDOBA_0 Z235;
Z136 Z211;

Z211.Y0 = Z209;
for (;;) {
if (IN(4, Z145.A[Z140])) {
Z211.Y1 = 8;
Z236(&Z235, (Z135)ADR (Z211));
Zqjx8B_4(&Z235);
goto EXIT_13;
} else if (IN(3, Z145.A[Z140]) || Z143) {
goto EXIT_13;
}
Z180(1, 1, Z209);
} EXIT_13:;
for (;;) {
switch (Z140) {
case 9:;
Z221 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
goto EXIT_14;
break;
case 10:;
Z231 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1BbM_18('\\');
goto EXIT_14;
break;
default:
if (Z143) {
if (Z140 != 9) {
Z190(9, 6, Z209, &Z221);
} else {
Z221 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
goto EXIT_14;
}
Z180(8, 8, Z209);
break;
}
} EXIT_14:;
Zqjx8B_5();
}

static void Z226
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z237, Z135 Z209)
# else
(Z237, Z209)
ZmfDOBA_0 *Z237;
Z135 Z209;
# endif
{
Zpky9FDA_0 Z238;

for (;;) {
if (IN(5, Z145.A[Z140])) {
if (Z140 == 1) {
Z140 = Zpky9FDA_4();
Z143 = FALSE;
} else {
Z238 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
} else if (IN(0, Z145.A[Z140]) || Z143) {
goto EXIT_15;
} else {
Z180(10, 10, Z209);
}
} EXIT_15:;
}

static void Z233
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z239, Z135 Z209)
# else
(Z239, Z209)
ZmfDOBA_0 *Z239;
Z135 Z209;
# endif
{
Zpky9FDA_0 Z222;
ZmfDOBA_0 Z223;
ZmfDOBA_0 Z225;
Z136 Z211;

Z211.Y0 = Z209;
for (;;) {
switch (Z140) {
case 7:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
for (;;) {
switch (Z140) {
case 11:;
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
goto EXIT_17;
break;
case 2:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '^';
goto EXIT_17;
break;
case 3:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '%';
goto EXIT_17;
break;
case 4:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '$';
goto EXIT_17;
break;
case 7:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '{';
goto EXIT_17;
break;
case 8:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '}';
goto EXIT_17;
break;
case 6:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Z222.Y1 = '\\';
goto EXIT_17;
break;
default:
if (Z143) {
if (Z140 != 11) {
Z190(11, 14, Z209, &Z222);
} else {
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
goto EXIT_17;
}
Z180(13, 13, Z209);
break;
}
} EXIT_17:;
Zp1PEAFD_4(&Z225);
Z211.Y1 = 14;
Z226(&Z223, (Z135)ADR (Z211));
for (;;) {
if (IN(1, Z145.A[Z140])) {
Z211.Y1 = 15;
Z228(&Z225, (Z135)ADR (Z211));
goto EXIT_18;
} else if (Z140 == 8 || Z143) {
goto EXIT_18;
}
Z180(14, 14, Z209);
} EXIT_18:;
if (Z140 != 8) {
Z158(8, 15, Z209);
} else {
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zqjx8B_1(Z222.Y1, &Z225);
goto EXIT_16;
break;
case 1:;
case 2:;
case 3:;
case 4:;
case 5:;
case 6:;
case 11:;
case 12:;
Z211.Y1 = 0;
Z228(&Z225, (Z135)ADR (Z211));
Zqjx8B_1('%', &Z225);
goto EXIT_16;
break;
default:
if (Z143) {
Z211.Y1 = 0;
Z228(&Z225, (Z135)ADR (Z211));
Zqjx8B_1('%', &Z225);
goto EXIT_16;
}
Z180(16, 16, Z209);
break;
}
} EXIT_16:;
}

static void Z228
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z240, Z135 Z209)
# else
(Z240, Z209)
ZmfDOBA_0 *Z240;
Z135 Z209;
# endif
{
Zpky9FDA_0 Z222;
Zpky9FDA_0 Z238, Z241;

Zp1PEAFD_4(Z240);
for (;;) {
for (;;) {
switch (Z140) {
case 1:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, ' ');
goto EXIT_20;
break;
case 2:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '^');
goto EXIT_20;
break;
case 3:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '%');
goto EXIT_20;
break;
case 4:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '$');
goto EXIT_20;
break;
case 5:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '.');
goto EXIT_20;
break;
case 11:;
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, Z222.Y1);
goto EXIT_20;
break;
case 12:;
Z238 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, Z133);
goto EXIT_20;
break;
case 6:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '\\');
for (;;) {
switch (Z140) {
case 6:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '\\');
goto EXIT_21;
break;
case 7:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '{');
goto EXIT_21;
break;
case 8:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, '}');
goto EXIT_21;
break;
case 1:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, ' ');
goto EXIT_21;
break;
case 12:;
Z241 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z240, Z133);
goto EXIT_21;
break;
default:
if (Z143) {
if (Z140 != 6) {
Z158(6, 24, Z209);
} else {
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zp1PEAFD_6(Z240, '\\');
goto EXIT_21;
}
Z180(23, 23, Z209);
break;
}
} EXIT_21:;
goto EXIT_20;
break;
default:
if (Z143) {
if (Z140 != 1) {
Z158(1, 11, Z209);
} else {
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zp1PEAFD_6(Z240, ' ');
goto EXIT_20;
}
Z180(17, 17, Z209);
break;
}
} EXIT_20:;
if (!IN(1, Z145.A[Z140])) {
if (IN(0, Z145.A[Z140])) {
goto EXIT_19;
}
Z180(17, 17, Z209);
if (!IN(1, Z145.A[Z140])) {
goto EXIT_19;
}
}
} EXIT_19:;
}

static void Z236
# ifdef HAVE_ARGS
(ZmfDOBA_0 *Z242, Z135 Z209)
# else
(Z242, Z209)
ZmfDOBA_0 *Z242;
Z135 Z209;
# endif
{
Zpky9FDA_0 Z222;
Zpky9FDA_0 Z238;

Zp1PEAFD_4(Z242);
for (;;) {
for (;;) {
switch (Z140) {
case 1:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, ' ');
goto EXIT_23;
break;
case 2:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, '^');
goto EXIT_23;
break;
case 3:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, '%');
goto EXIT_23;
break;
case 4:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, '$');
goto EXIT_23;
break;
case 5:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, '.');
goto EXIT_23;
break;
case 6:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, '\\');
goto EXIT_23;
break;
case 7:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, '{');
goto EXIT_23;
break;
case 8:;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, '}');
goto EXIT_23;
break;
case 11:;
Z222 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, Z222.Y1);
goto EXIT_23;
break;
case 12:;
Z238 = Zpky9FDA_1;
Z140 = Zpky9FDA_4();
Z143 = FALSE;
Zp1PEAFD_6(Z242, Z133);
goto EXIT_23;
break;
default:
if (Z143) {
if (Z140 != 1) {
Z158(1, 11, Z209);
} else {
Z140 = Zpky9FDA_4();
Z143 = FALSE;
}
Zp1PEAFD_6(Z242, ' ');
goto EXIT_23;
}
Z180(13, 13, Z209);
break;
}
} EXIT_23:;
if (!IN(4, Z145.A[Z140])) {
if (IN(3, Z145.A[Z140])) {
goto EXIT_22;
}
Z180(13, 13, Z209);
if (!IN(4, Z145.A[Z140])) {
goto EXIT_22;
}
}
} EXIT_22:;
}

void BEGIN_Parser ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Strings ();
BEGIN_Pack ();
BEGIN_Position ();
BEGIN_Errors ();
BEGIN_Scanner ();
BEGIN_Strings ();
BEGIN_StdIO ();
BEGIN_Scanner ();
BEGIN_Strings ();
BEGIN_Table ();

Z142 = FALSE;
}
