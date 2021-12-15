#include "SYSTEM_.h"

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_General
#include "General.h"
#endif

#ifndef DEFINITION_Pack
#include "Pack.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

Zq0A4_58 ZmfDOBA_0;
BOOLEAN ZmfDOBA_30;

typedef struct S_1 {
union {
struct {
Zpky9FDA_37 Y0;
} V_1;
struct {
Zq0A4_58 Y1;
} V_2;
struct {
struct S_25 {
Zq0A4_58 Y0, Y1;
} Y2;
} V_3;
struct {
struct S_24 {
Zq0A4_58 Y0;
Zpky9FDA_37 Y1;
} Y3;
} V_4;
} U_1;
} Z133;
static Zq0A4_58 Z139;
#define Z141	0
#define Z142	0
#define Z143	1
#define Z144	2
#define Z145	3
#define Z146	0
#define Z147	61
#define Z148	62
#define Z149	0
#define Z150	90
#define Z151	225
#define Z152	142
#define Z153	1
#define Z154	1
#define Z155	91
#define Z156	92
#define Z157	123
#define Z158	124
#define Z159	203
#define Z160	203
#define Z161	124
#define Z162	91
#define Z163	91
#define Z164	62
#define Z165	142
#define Z166	Z156
typedef SHORTCARD Z167;
typedef Z167 Z168;
typedef Z167 Z169;
typedef Z167 Z170;
typedef Z167 Z171;
typedef struct S_2 {
Z168 Y0, Y1;
} Z172;
typedef Z168 Z175;
typedef Z172 Z176;
typedef Z172 *Z177;
typedef Z175 *Z178;
typedef Z176 *Z179;
typedef struct S_23 {
Z168 A[1000000 + 1];
} *Z180;
typedef struct S_3 {
BITSET Y0;
BOOLEAN Y1, Y2;
} Z181;
static struct S_4 {
ADDRESS A[Z155 + 1];
} Z185;
static struct S_5 {
ADDRESS A[Z155 + 1];
} Z186;
static struct S_6 {
Z168 A[Z162 + 1];
} Z187;
static struct S_7 {
Z168 A[Z163 + 1];
} Z188;
static struct S_8 {
Z172 A[Z151 + 1];
} Z189;
static struct S_9 {
Z175 A[Z164 - (Z147 + 1) + 1];
} Z190;
static struct S_10 {
Z176 A[Z165 - (Z147 + 1) + 1];
} Z191;
static struct S_11 {
Z167 A[Z159 - Z158 + 1];
} Z192;
static struct S_12 {
Z171 A[Z159 - Z158 + 1];
} Z193;
static struct S_13 {
Z171 A[Z155 + 1];
} Z194;
static struct S_14 {
Z168 A[Z160 + 1 - (Z159 + 1) + 1];
} Z195;
static struct S_15 {
Z170 A[Z157 + 1 - Z156 + 1];
} Z196;
static struct S_16 {
SHORTCARD A[Z161 - Z157 - 1 + 1];
} Z197;
static Z181 Z198;
static void Z205 ARGS ((CHAR Z206[], LONGCARD O_3, CHAR Z207[], LONGCARD O_2));
static Z167 Z214;
static LONGINT Z215;
static LONGINT Z216;
static Z167 Z217;
static Z180 Z218;
static struct S_17 {
Z133 A[100000 + 1];
} *Z219;
struct S_1_yyParse;
static INTEGER Z225 ARGS ((Z168 Z221, Z171 Z228, CARDINAL Z229));
struct S_19 {
CHAR A[127 + 1];
};
static void Z241 ARGS ((struct S_1_yyParse *link));
static void Z243 ARGS ((void));
static void Z244 ARGS ((struct S_1_yyParse *link));
static void Z245 ARGS ((void));
struct S_1_yyParse {
Z168 *Z230;
Z171 *Z231;
BOOLEAN *Z239;
CARDINAL *Z222;
};
static Z171 Z247 ARGS ((Z171 Z335, LONGINT Z336, LONGINT Z337));
struct S_18 {
CHAR A[127 + 1];
};
static void Z353 ARGS ((LONGINT Z336, LONGINT Z337, ZpmCQ_4 *Z339));
static BOOLEAN Z367 ARGS ((Z171 Z335, LONGINT Z336, LONGINT Z337));
static void Z371 ARGS ((Z168 Z365, ZpmCQ_4 *Z339));
static void Z363 ARGS ((LONGINT Z336, LONGINT Z337, ZpmCQ_4 *Z341));
static Z168 Z174 ARGS ((Z168 Z365, Z171 Z373));
static CARDINAL Z377;
static void Z378 ARGS ((LONGCARD Z379));
static void Z380 ARGS ((LONGCARD Z379));
static void Z381 ARGS ((LONGCARD Z379));
static void Z382 ARGS ((LONGCARD Z379));
static void Z383 ARGS ((LONGCARD Z379));
static void Z384 ARGS ((LONGCARD Z379));
static void Z385 ARGS ((LONGCARD Z379));
static void Z386 ARGS ((LONGCARD Z379));
static void Z387 ARGS ((LONGCARD Z379));
static void Z388 ARGS ((LONGCARD Z379));
static void Z389 ARGS ((LONGCARD Z379));
static void Z390 ARGS ((LONGCARD Z379));
static void Z391 ARGS ((void));

static void Z205
# ifdef HAVE_ARGS
(CHAR Z206[], LONGCARD O_3, CHAR Z207[], LONGCARD O_2)
# else
(Z206, O_3, Z207, O_2)
CHAR Z206[];
LONGCARD O_3;
CHAR Z207[];
LONGCARD O_2;
# endif
{
CARDINAL Z208, Z209;
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_3 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z206, O_3, CHAR)
if ((O_3 - 1) < (O_2 - 1)) {
Z209 = (O_3 - 1);
} else {
Z209 = (O_2 - 1);
}
{
LONGCARD B_1 = 0, B_2 = Z209;

if (B_1 <= B_2)
for (Z208 = B_1;; Z208 += 1) {
Z207[Z208] = Z206[Z208];
if (Z208 >= B_2) break;
}
}
if ((O_2 - 1) > Z209) {
Z207[Z209 + 1] = CHR(0);
}
FREE_OPEN_ARRAYS
}

void ZmfDOBA_35
# ifdef HAVE_ARGS
(CARDINAL Z200, CHAR Z201[], LONGCARD O_1)
# else
(Z200, Z201, O_1)
CARDINAL Z200;
CHAR Z201[];
LONGCARD O_1;
# endif
{
Zp1PEAFD_2 Z202, Z203;

switch (Z200) {
case 0:;
Z205((STRING)"_EOF_", 5L, Z201, O_1);
break;
case 1:;
Z205((STRING)"(", 1L, Z201, O_1);
break;
case 2:;
Z205((STRING)")", 1L, Z201, O_1);
break;
case 3:;
Z205((STRING)",", 1L, Z201, O_1);
break;
case 4:;
Z205((STRING)".", 1L, Z201, O_1);
break;
case 5:;
Z205((STRING)"/", 1L, Z201, O_1);
break;
case 6:;
Z205((STRING)":", 1L, Z201, O_1);
break;
case 7:;
Z205((STRING)";", 1L, Z201, O_1);
break;
case 8:;
Z205((STRING)"=", 1L, Z201, O_1);
break;
case 11:;
Z205((STRING)"|", 1L, Z201, O_1);
break;
case 12:;
Z205((STRING)"{", 1L, Z201, O_1);
break;
case 13:;
Z205((STRING)"}", 1L, Z201, O_1);
break;
case 15:;
Z205((STRING)"->", 2L, Z201, O_1);
break;
case 21:;
Z205((STRING)"BEGIN", 5L, Z201, O_1);
break;
case 22:;
Z205((STRING)"CLOSE", 5L, Z201, O_1);
break;
case 23:;
Z205((STRING)"CONDITION", 9L, Z201, O_1);
break;
case 24:;
Z205((STRING)"COSTS", 5L, Z201, O_1);
break;
case 25:;
Z205((STRING)"DECLARE", 7L, Z201, O_1);
break;
case 26:;
Z205((STRING)"EXPORT", 6L, Z201, O_1);
break;
case 27:;
Z205((STRING)"GLOBAL", 6L, Z201, O_1);
break;
case 28:;
Z205((STRING)"GRAMMAR", 7L, Z201, O_1);
break;
case 30:;
Z205((STRING)"FUNCTION", 8L, Z201, O_1);
break;
case 31:;
Z205((STRING)"TRANSFORMATION", 14L, Z201, O_1);
break;
case 41:;
Z205((STRING)"Ident", 5L, Z201, O_1);
break;
case 42:;
Z205((STRING)"Number", 6L, Z201, O_1);
break;
case 43:;
Z205((STRING)"String", 6L, Z201, O_1);
break;
case 51:;
Z205((STRING)"{", 1L, Z201, O_1);
break;
case 52:;
Z205((STRING)"}", 1L, Z201, O_1);
break;
case 53:;
Z205((STRING)".", 1L, Z201, O_1);
break;
case 54:;
Z205((STRING)"(", 1L, Z201, O_1);
break;
case 55:;
Z205((STRING)")", 1L, Z201, O_1);
break;
case 56:;
Z205((STRING)"ident", 5L, Z201, O_1);
break;
case 57:;
Z205((STRING)"string", 6L, Z201, O_1);
break;
case 58:;
Z205((STRING)"space", 5L, Z201, O_1);
break;
case 59:;
Z205((STRING)"comment", 7L, Z201, O_1);
break;
case 60:;
Z205((STRING)"rest", 4L, Z201, O_1);
break;
case 61:;
Z205((STRING)",", 1L, Z201, O_1);
break;
default:
Zp1PEAFD_13((STRING)"unknown ", 8L, &Z202);
Zp1PEAFD_18((LONGINT)Z200, &Z203);
Zp1PEAFD_5(&Z202, &Z203);
Zp1PEAFD_14(&Z202, Z201, O_1);
break;
}
}

CARDINAL ZmfDOBA_32
 ARGS ((void))
{
return ZmfDOBA_33(Z153);
}

CARDINAL ZmfDOBA_33
# ifdef HAVE_ARGS
(SHORTCARD Z221)
# else
(Z221)
SHORTCARD Z221;
# endif
{
CARDINAL Z222;

ZmfDOBA_31();
Z215 = 100;
Z216 = 100;
ZarQdhNDD_0((ADDRESS *)&Z218, &Z215, (LONGINT)sizeof (Z168));
ZarQdhNDD_0((ADDRESS *)&Z219, &Z216, (LONGINT)sizeof (Z133));
Z217 = Z215 - 1;
Z214 = 0;
Z198.Y0 = SET_ELEM (Z142);
Z198.Y1 = TRUE;
Z198.Y2 = TRUE;
Z222 = Z225(Z221, (Z171)Zpky9FDA_51(), (LONGCARD)Z197.A[Z221 - 1]);
ZarQdhNDD_3((ADDRESS *)&Z218, &Z215, (LONGINT)sizeof (Z167));
ZarQdhNDD_3((ADDRESS *)&Z219, &Z216, (LONGINT)sizeof (Z133));
return Z222;
}

static void Z241
# ifdef HAVE_ARGS
(struct S_1_yyParse *link)
# else
(link)
struct S_1_yyParse *link;
# endif
{
*link->Z230 = Z195.A[(Z167)(*link->Z230) - 204];
INC(Z214);
Z219->A[Z214].U_1.V_1.Y0 = Zpky9FDA_47;
*link->Z231 = Zpky9FDA_51();
*link->Z239 = FALSE;
}

static void Z243
 ARGS ((void))
{
}

static void Z244
# ifdef HAVE_ARGS
(struct S_1_yyParse *link)
# else
(link)
struct S_1_yyParse *link;
# endif
{
INC(*link->Z222);
}

static void Z245
 ARGS ((void))
{
ZarQdhNDD_2((ADDRESS *)&Z218, &Z215, (LONGINT)sizeof (Z168));
ZarQdhNDD_2((ADDRESS *)&Z219, &Z216, (LONGINT)sizeof (Z133));
Z217 = Z215 - 1;
}

static INTEGER Z225
# ifdef HAVE_ARGS
(Z168 Z221, Z171 Z228, CARDINAL Z229)
# else
(Z221, Z228, Z229)
Z168 Z221;
Z171 Z228;
CARDINAL Z229;
# endif
{
Z168 Z230;
Z171 Z231;
Z171 Z232;
Z133 Z233;
Zpky9FDA_37 Z234;
Z171 Z235;
Z168 Z236;
Z177 Z237;
Z179 Z238;
BOOLEAN Z239;
CARDINAL Z222;
struct S_19 Z240;
struct S_1_yyParse frame;

frame.Z230 = &Z230;
frame.Z231 = &Z231;
frame.Z239 = &Z239;
frame.Z222 = &Z222;
Z230 = Z221;
Z231 = Z228;
Z222 = 0;
Z239 = FALSE;
for (;;) {
for (;;) {
if (Z214 >= Z217) {
Z245();
}
Z218->A[Z214] = Z230;
for (;;) {
Z237 = (Z177)(Z185.A[Z230] + Z231 * sizeof (Z172));
if (Z237->Y0 == Z230) {
Z230 = Z237->Y1;
goto EXIT_3;
}
Z230 = Z187.A[Z230];
if (Z230 == Z141) {
goto EXIT_3;
}
} EXIT_3:;
if (Z230 == Z141 || Z239 && Z230 >= Z158) {
if (Z230 == Z141 && !Z239) {
INC(Z222);
Z231 = Z247(Z231, Z215, (LONGINT)Z214);
Z239 = TRUE;
Z230 = Z218->A[Z214];
goto EXIT_2;
}
Z230 = Z218->A[Z214];
Z235 = Z194.A[Z230];
Z230 = Z174(Z230, Z235);
if (Z230 > Z159) {
Z230 = Z195.A[(Z167)Z230 - 204];
}
if (Z230 <= Z157) {
Zpky9FDA_43((LONGINT)Z235, &Z234);
if (Z198.Y2) {
ZmfDOBA_35((LONGCARD)Z235, Z240.A, 128L);
ZblNKKO_78((LONGCARD)ZblNKKO_4, (LONGCARD)ZblNKKO_18, Zpky9FDA_47.Y0, (LONGCARD)ZblNKKO_29, ADR (Z240));
}
if (Z214 >= Z217) {
Z245();
}
INC(Z214);
Z219->A[Z214].U_1.V_1.Y0 = Z234;
if (Z230 >= Z166) {
Z218->A[Z214] = Z218->A[Z214 - 1];
Z230 = Z196.A[Z230 - 92];
} else {
Z218->A[Z214] = Z230;
}
}
if (Z230 <= Z155) {
goto EXIT_2;
}
}
if (Z230 >= Z166) {
if (Z230 <= Z157) {
INC(Z214);
Z219->A[Z214].U_1.V_1.Y0 = Zpky9FDA_47;
Z231 = Zpky9FDA_51();
Z239 = FALSE;
}
for (;;) {
switch (Z230) {
case 124:;
Z243();
return Z222;
break;
case 125:;
DEC1(Z214, 8);
Z232 = ZmfDOBA_2;
ZmfDOBA_0 = Zq0A4_150(Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 8].U_1.V_4.Y3.Y1.U_1.V_1.Y1, Z219->A[Z214 + 8].U_1.V_4.Y3.Y1.Y0, Z219->A[Z214 + 3].U_1.V_2.Y1, Z219->A[Z214 + 4].U_1.V_2.Y1, Z219->A[Z214 + 5].U_1.V_2.Y1, Z219->A[Z214 + 6].U_1.V_2.Y1, Z219->A[Z214 + 7].U_1.V_2.Y1, Zq0A4_202(Z219->A[Z214 + 8].U_1.V_4.Y3.Y0));
break;
case 126:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_3;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 2].U_1.V_2.Y1;
break;
case 127:;
Z232 = ZmfDOBA_3;
Z233.U_1.V_2.Y1 = Zq0A4_200(ZmtLFGGBG_1);
break;
case 128:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_4;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 2].U_1.V_2.Y1;
break;
case 129:;
Z232 = ZmfDOBA_4;
Z233.U_1.V_2.Y1 = Zq0A4_200(ZmtLFGGBG_1);
break;
case 130:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_5;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 2].U_1.V_2.Y1;
break;
case 131:;
Z232 = ZmfDOBA_5;
Z233.U_1.V_2.Y1 = Zq0A4_200(ZmtLFGGBG_1);
break;
case 132:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_6;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 2].U_1.V_2.Y1;
break;
case 133:;
Z232 = ZmfDOBA_6;
Z233.U_1.V_2.Y1 = Zq0A4_200(ZmtLFGGBG_1);
break;
case 134:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_7;
Z233.U_1.V_4.Y3.Y1.U_1.V_1.Y1 = Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1;
Z233.U_1.V_4.Y3.Y1.Y0 = Z219->A[Z214 + 2].U_1.V_1.Y0.Y0;
Z233.U_1.V_4.Y3.Y0 = Zq0A4_202(Z219->A[Z214 + 3].U_1.V_2.Y1);
break;
case 135:;
Z232 = ZmfDOBA_8;
Z233.U_1.V_2.Y1 = Zq0A4_152();
break;
case 136:;
DEC1(Z214, 6);
Z232 = ZmfDOBA_8;
Z233.U_1.V_2.Y1 = Zq0A4_153(Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 4].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 4].U_1.V_1.Y0.Y0, Zq0A4_202(Z219->A[Z214 + 6].U_1.V_2.Y1), Z219->A[Z214 + 1].U_1.V_2.Y1, TRUE);
break;
case 137:;
DEC1(Z214, 4);
Z232 = ZmfDOBA_8;
Z233.U_1.V_2.Y1 = Zq0A4_153(Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Zq0A4_202(Z219->A[Z214 + 4].U_1.V_2.Y1), Z219->A[Z214 + 1].U_1.V_2.Y1, TRUE);
break;
case 138:;
Z232 = ZmfDOBA_9;
Z233.U_1.V_2.Y1 = Zq0A4_155();
break;
case 139:;
case 92:;
DEC1(Z214, 8);
Z232 = ZmfDOBA_9;
Z233.U_1.V_2.Y1 = Zq0A4_156(Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Z219->A[Z214 + 5].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 5].U_1.V_1.Y0.Y0, Z219->A[Z214 + 7].U_1.V_2.Y1, Z219->A[Z214 + 1].U_1.V_2.Y1, TRUE);
break;
case 140:;
case 93:;
DEC1(Z214, 6);
Z232 = ZmfDOBA_9;
Z233.U_1.V_2.Y1 = Zq0A4_156(Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 5].U_1.V_2.Y1, Z219->A[Z214 + 1].U_1.V_2.Y1, TRUE);
break;
case 141:;
Z232 = ZmfDOBA_10;
Z233.U_1.V_2.Y1 = Zq0A4_158();
break;
case 142:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_10;
Z233.U_1.V_2.Y1 = Zq0A4_202(Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 143:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_11;
Z233.U_1.V_2.Y1 = Zq0A4_159(Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Zq0A4_158(), TRUE);
break;
case 144:;
case 94:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_11;
Z233.U_1.V_2.Y1 = Zq0A4_159(Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Zq0A4_158(), TRUE);
break;
case 145:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_11;
Z233.U_1.V_2.Y1 = Zq0A4_159(Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1, TRUE);
break;
case 146:;
case 95:;
DEC1(Z214, 5);
Z232 = ZmfDOBA_11;
Z233.U_1.V_2.Y1 = Zq0A4_159(Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Z219->A[Z214 + 5].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 5].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1, TRUE);
break;
case 147:;
Z232 = ZmfDOBA_12;
Z233.U_1.V_2.Y1 = Zq0A4_161();
break;
case 148:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_12;
Z233.U_1.V_2.Y1 = Zq0A4_202(Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 149:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_13;
Z139 = Z219->A[Z214 + 1].U_1.V_3.Y2.Y0;
for (;;) {
Z139->U_1.V_16.Y15.Y5 = Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1;
Z139->U_1.V_16.Y15.Y6 = Z219->A[Z214 + 3].U_1.V_1.Y0.Y0;
if (Z139 == Z219->A[Z214 + 1].U_1.V_3.Y2.Y1) {
goto EXIT_5;
}
Z139 = Z139->U_1.V_16.Y15.Y7;
} EXIT_5:;
Z219->A[Z214 + 1].U_1.V_3.Y2.Y1->U_1.V_16.Y15.Y7 = Zq0A4_161();
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 1].U_1.V_3.Y2.Y0;
break;
case 150:;
case 96:;
DEC1(Z214, 5);
Z232 = ZmfDOBA_13;
Z139 = Z219->A[Z214 + 1].U_1.V_3.Y2.Y0;
for (;;) {
Z139->U_1.V_16.Y15.Y3 = Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1;
Z139->U_1.V_16.Y15.Y4 = Z219->A[Z214 + 3].U_1.V_1.Y0.Y0;
Z139->U_1.V_16.Y15.Y5 = Z219->A[Z214 + 5].U_1.V_1.Y0.U_1.V_1.Y1;
Z139->U_1.V_16.Y15.Y6 = Z219->A[Z214 + 5].U_1.V_1.Y0.Y0;
if (Z139 == Z219->A[Z214 + 1].U_1.V_3.Y2.Y1) {
goto EXIT_6;
}
Z139 = Z139->U_1.V_16.Y15.Y7;
} EXIT_6:;
Z219->A[Z214 + 1].U_1.V_3.Y2.Y1->U_1.V_16.Y15.Y7 = Zq0A4_161();
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 1].U_1.V_3.Y2.Y0;
break;
case 151:;
DEC1(Z214, 5);
Z232 = ZmfDOBA_13;
Z139 = Z219->A[Z214 + 3].U_1.V_3.Y2.Y0;
for (;;) {
Z139->U_1.V_16.Y15.Y5 = Z219->A[Z214 + 5].U_1.V_1.Y0.U_1.V_1.Y1;
Z139->U_1.V_16.Y15.Y6 = Z219->A[Z214 + 5].U_1.V_1.Y0.Y0;
if (Z139 == Z219->A[Z214 + 3].U_1.V_3.Y2.Y1) {
goto EXIT_7;
}
Z139 = Z139->U_1.V_16.Y15.Y7;
} EXIT_7:;
Z219->A[Z214 + 3].U_1.V_3.Y2.Y1->U_1.V_16.Y15.Y7 = Z219->A[Z214 + 1].U_1.V_2.Y1;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 3].U_1.V_3.Y2.Y0;
break;
case 152:;
case 97:;
DEC1(Z214, 7);
Z232 = ZmfDOBA_13;
Z139 = Z219->A[Z214 + 3].U_1.V_3.Y2.Y0;
for (;;) {
Z139->U_1.V_16.Y15.Y3 = Z219->A[Z214 + 5].U_1.V_1.Y0.U_1.V_1.Y1;
Z139->U_1.V_16.Y15.Y4 = Z219->A[Z214 + 5].U_1.V_1.Y0.Y0;
Z139->U_1.V_16.Y15.Y5 = Z219->A[Z214 + 7].U_1.V_1.Y0.U_1.V_1.Y1;
Z139->U_1.V_16.Y15.Y6 = Z219->A[Z214 + 7].U_1.V_1.Y0.Y0;
if (Z139 == Z219->A[Z214 + 3].U_1.V_3.Y2.Y1) {
goto EXIT_8;
}
Z139 = Z139->U_1.V_16.Y15.Y7;
} EXIT_8:;
Z219->A[Z214 + 3].U_1.V_3.Y2.Y1->U_1.V_16.Y15.Y7 = Z219->A[Z214 + 1].U_1.V_2.Y1;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 3].U_1.V_3.Y2.Y0;
break;
case 153:;
case 98:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_14;
Z139 = Zq0A4_162(Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Zpky9FDA_39, ZmtLFGGBG_1, Zpky9FDA_39, ZmtLFGGBG_1, (Zq0A4_58)Zq0A4_4);
Z233.U_1.V_3.Y2.Y0 = Z139;
Z233.U_1.V_3.Y2.Y1 = Z139;
break;
case 154:;
case 99:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_14;
Z233.U_1.V_3.Y2.Y0 = Zq0A4_162(Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Zpky9FDA_39, ZmtLFGGBG_1, Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 1].U_1.V_3.Y2.Y0);
Z233.U_1.V_3.Y2.Y1 = Z219->A[Z214 + 1].U_1.V_3.Y2.Y1;
break;
case 155:;
Z232 = ZmfDOBA_15;
Z233.U_1.V_2.Y1 = Zq0A4_164();
break;
case 156:;
DEC1(Z214, 6);
Z232 = ZmfDOBA_15;
Z219->A[Z214 + 4].U_1.V_2.Y1->U_1.V_19.Y18.Y1 = Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1;
Z219->A[Z214 + 4].U_1.V_2.Y1->U_1.V_19.Y18.Y2 = Z219->A[Z214 + 3].U_1.V_1.Y0.Y0;
Z219->A[Z214 + 4].U_1.V_2.Y1->U_1.V_19.Y18.Y6 = Z219->A[Z214 + 5].U_1.V_2.Y1;
Z219->A[Z214 + 4].U_1.V_2.Y1->U_1.V_19.Y18.Y7 = Zq0A4_202(Z219->A[Z214 + 6].U_1.V_2.Y1);
Z219->A[Z214 + 4].U_1.V_2.Y1->U_1.V_19.Y18.Y8 = Z219->A[Z214 + 1].U_1.V_2.Y1;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 4].U_1.V_2.Y1;
break;
case 157:;
case 100:;
DEC1(Z214, 7);
Z232 = ZmfDOBA_16;
Z233.U_1.V_2.Y1 = Zq0A4_165(Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 1].U_1.V_2.Y1, Z219->A[Z214 + 3].U_1.V_2.Y1, Zq0A4_168(Z219->A[Z214 + 5].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 5].U_1.V_1.Y0.Y0, Z219->A[Z214 + 7].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 7].U_1.V_1.Y0.Y0), (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4);
break;
case 158:;
DEC1(Z214, 5);
Z232 = ZmfDOBA_16;
Z233.U_1.V_2.Y1 = Zq0A4_165(Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 1].U_1.V_2.Y1, Z219->A[Z214 + 3].U_1.V_2.Y1, Zq0A4_168(Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 5].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 5].U_1.V_1.Y0.Y0), (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4);
break;
case 159:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_16;
Z233.U_1.V_2.Y1 = Zq0A4_165(Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 1].U_1.V_2.Y1, Z219->A[Z214 + 3].U_1.V_2.Y1, Zq0A4_167(), (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4);
break;
case 160:;
case 101:;
DEC1(Z214, 4);
Z232 = ZmfDOBA_16;
Z233.U_1.V_2.Y1 = Zq0A4_165(Zpky9FDA_39, ZmtLFGGBG_1, Zq0A4_161(), Zq0A4_161(), Zq0A4_168(Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 4].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 4].U_1.V_1.Y0.Y0), (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4);
break;
case 161:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_16;
Z233.U_1.V_2.Y1 = Zq0A4_165(Zpky9FDA_39, ZmtLFGGBG_1, Zq0A4_161(), Zq0A4_161(), Zq0A4_168(Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0), (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4);
break;
case 162:;
Z232 = ZmfDOBA_16;
Z233.U_1.V_2.Y1 = Zq0A4_165(Zpky9FDA_39, ZmtLFGGBG_1, Zq0A4_161(), Zq0A4_161(), Zq0A4_167(), (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4, (Zq0A4_58)Zq0A4_4);
break;
case 163:;
case 102:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_17;
Z233.U_1.V_2.Y1 = Zq0A4_170();
break;
case 164:;
case 103:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_17;
Z233.U_1.V_2.Y1 = Zq0A4_202(Z219->A[Z214 + 2].U_1.V_2.Y1);
break;
case 165:;
case 104:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_18;
Z233.U_1.V_2.Y1 = Zq0A4_171(Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Zq0A4_170());
break;
case 166:;
case 105:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_18;
Z233.U_1.V_2.Y1 = Zq0A4_171(Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 167:;
Z232 = ZmfDOBA_19;
Z233.U_1.V_2.Y1 = Zq0A4_173();
break;
case 168:;
DEC1(Z214, 6);
Z232 = ZmfDOBA_19;
Z233.U_1.V_2.Y1 = Zq0A4_174(Z219->A[Z214 + 2].U_1.V_2.Y1, Z219->A[Z214 + 3].U_1.V_2.Y1, Z219->A[Z214 + 4].U_1.V_2.Y1, Z219->A[Z214 + 5].U_1.V_2.Y1, Z219->A[Z214 + 6].U_1.V_2.Y1, Z219->A[Z214 + 1].U_1.V_2.Y1, TRUE);
break;
case 169:;
case 106:;
DEC1(Z214, 6);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_177(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, Z219->A[Z214 + 5].U_1.V_2.Y1, TRUE);
break;
case 170:;
case 107:;
DEC1(Z214, 4);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_177(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 3].U_1.V_2.Y1, TRUE);
break;
case 171:;
case 108:;
DEC1(Z214, 5);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_177(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 4].U_1.V_2.Y1, TRUE);
break;
case 172:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_176(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 3].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 3].U_1.V_1.Y0.Y0, TRUE);
break;
case 173:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_176(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, TRUE);
break;
case 174:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_176(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Zpky9FDA_39, ZmtLFGGBG_1, TRUE);
break;
case 175:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_176(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Zpky9FDA_39, ZmtLFGGBG_1, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, TRUE);
break;
case 176:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_20;
Z233.U_1.V_2.Y1 = Zq0A4_176(Z219->A[Z214 + 1].U_1.V_1.Y0.Y0, Zpky9FDA_39, ZmtLFGGBG_1, Zpky9FDA_39, ZmtLFGGBG_1, TRUE);
break;
case 177:;
Z232 = ZmfDOBA_21;
Z233.U_1.V_2.Y1 = Zq0A4_179();
break;
case 178:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_21;
Z233.U_1.V_2.Y1 = Zq0A4_202(Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 179:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_22;
Z233.U_1.V_2.Y1 = Zq0A4_180(Z219->A[Z214 + 1].U_1.V_2.Y1, Zq0A4_179());
break;
case 180:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_22;
Z233.U_1.V_2.Y1 = Zq0A4_180(Z219->A[Z214 + 3].U_1.V_2.Y1, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 181:;
case 109:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_23;
Z233.U_1.V_1.Y0 = Z219->A[Z214 + 1].U_1.V_1.Y0;
break;
case 182:;
case 110:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_23;
Z233.U_1.V_1.Y0 = Z219->A[Z214 + 1].U_1.V_1.Y0;
break;
case 183:;
Z232 = ZmfDOBA_24;
Z233.U_1.V_2.Y1 = Zq0A4_182();
break;
case 184:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_24;
Z233.U_1.V_2.Y1 = Zq0A4_183(Z219->A[Z214 + 2].U_1.V_2.Y1);
break;
case 185:;
Z232 = ZmfDOBA_25;
Z233.U_1.V_2.Y1 = Zq0A4_185();
break;
case 186:;
case 111:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_25;
Z233.U_1.V_2.Y1 = Zq0A4_186(Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_3.Y3, Z219->A[Z214 + 2].U_1.V_1.Y0.Y0);
break;
case 187:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_25;
Z233.U_1.V_2.Y1 = Zq0A4_187(Z219->A[Z214 + 2].U_1.V_2.Y1);
break;
case 188:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_26;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 2].U_1.V_2.Y1;
break;
case 189:;
Z232 = ZmfDOBA_26;
Z233.U_1.V_2.Y1 = Zq0A4_200(ZmtLFGGBG_1);
break;
case 190:;
DEC1(Z214, 1);
Z232 = ZmfDOBA_27;
Z233.U_1.V_2.Y1 = Z219->A[Z214 + 1].U_1.V_2.Y1;
break;
case 191:;
case 112:;
DEC1(Z214, 3);
Z232 = ZmfDOBA_28;
Z233.U_1.V_2.Y1 = Zq0A4_202(Z219->A[Z214 + 2].U_1.V_2.Y1);
break;
case 192:;
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_200(ZmtLFGGBG_1);
break;
case 193:;
case 113:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_189(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 194:;
case 114:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_190(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_1.Y1, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 195:;
case 115:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_191(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 196:;
case 116:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_193(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 197:;
case 117:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_194(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 198:;
case 118:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_195(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 199:;
case 119:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_196(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 200:;
case 120:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_197(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_2.Y2, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 201:;
case 121:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_198(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_2.Y2, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 202:;
case 122:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_199(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 2].U_1.V_1.Y0.U_1.V_2.Y2, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
case 203:;
case 123:;
DEC1(Z214, 2);
Z232 = ZmfDOBA_29;
Z233.U_1.V_2.Y1 = Zq0A4_192(Z219->A[Z214 + 2].U_1.V_1.Y0.Y0, Z219->A[Z214 + 1].U_1.V_2.Y1);
break;
}
Z230 = Z218->A[Z214];
for (;;) {
Z238 = (Z179)(Z186.A[Z230] + Z232 * sizeof (Z176));
if (Z238->Y0 == Z230) {
Z230 = Z238->Y1;
goto EXIT_9;
}
Z230 = Z188.A[Z230];
} EXIT_9:;
INC(Z214);
Z219->A[Z214] = Z233;
if (Z230 < Z166) {
goto EXIT_4;
}
} EXIT_4:;
} else {
INC(Z214);
Z219->A[Z214].U_1.V_1.Y0 = Zpky9FDA_47;
Z231 = Zpky9FDA_51();
Z239 = FALSE;
}
} EXIT_2:;
} EXIT_1:;
}

static Z171 Z247
# ifdef HAVE_ARGS
(Z171 Z335, LONGINT Z336, LONGINT Z337)
# else
(Z335, Z336, Z337)
Z171 Z335;
LONGINT Z336;
LONGINT Z337;
# endif
{
BOOLEAN Z338;
ZpmCQ_4 Z339;
ZpmCQ_4 Z341;
Z171 Z200;
struct S_18 Z342;
Zp1PEAFD_2 Z343;
Zp1PEAFD_2 Z344;
INTEGER Z345;

if (Z198.Y2) {
ZblNKKO_77((LONGCARD)ZblNKKO_1, (LONGCARD)ZblNKKO_16, Zpky9FDA_47.Y0);
ZmfDOBA_35((LONGCARD)Z335, Z342.A, 128L);
Zp1PEAFD_13(Z342.A, 128L, &Z343);
ZblNKKO_78((LONGCARD)ZblNKKO_10, (LONGCARD)ZblNKKO_20, Zpky9FDA_47.Y0, (LONGCARD)ZblNKKO_28, ADR (Z343));
ZpmCQ_5(&Z339, (LONGCARD)Z147);
Z353(Z336, Z337, &Z339);
Zp1PEAFD_4(&Z344);
{
Z171 B_3 = ZpmCQ_17(&Z339), B_4 = ZpmCQ_18(&Z339);

if (B_3 <= B_4)
for (Z200 = B_3;; Z200 += 1) {
if (ZpmCQ_25((LONGCARD)Z200, &Z339)) {
ZmfDOBA_35((LONGCARD)Z200, Z342.A, 128L);
Zp1PEAFD_13(Z342.A, 128L, &Z343);
if (Zp1PEAFD_7(&Z344) + Zp1PEAFD_7(&Z343) + 1 <= Zp1PEAFD_0) {
Zp1PEAFD_5(&Z344, &Z343);
Zp1PEAFD_6(&Z344, ' ');
}
}
if (Z200 >= B_4) break;
}
}
ZblNKKO_78((LONGCARD)ZblNKKO_2, (LONGCARD)ZblNKKO_20, Zpky9FDA_47.Y0, (LONGCARD)ZblNKKO_28, ADR (Z344));
ZpmCQ_7(&Z339);
}
ZpmCQ_5(&Z341, (LONGCARD)Z147);
Z363(Z336, Z337, &Z341);
Z338 = FALSE;
while (!ZpmCQ_25((LONGCARD)Z335, &Z341)) {
Z335 = Zpky9FDA_51();
Z338 = TRUE;
}
ZpmCQ_7(&Z341);
if (Z338 && Z198.Y2) {
ZblNKKO_77((LONGCARD)ZblNKKO_3, (LONGCARD)ZblNKKO_20, Zpky9FDA_47.Y0);
}
return Z335;
}

static void Z353
# ifdef HAVE_ARGS
(LONGINT Z336, LONGINT Z337, ZpmCQ_4 *Z339)
# else
(Z336, Z337, Z339)
LONGINT Z336;
LONGINT Z337;
ZpmCQ_4 *Z339;
# endif
{
Z171 Z335;
Z168 Z365;
Z168 Z366;

Z365 = Z218->A[Z337];
ZpmCQ_32(Z339);
for (Z335 = Z146; Z335 <= Z147; Z335 += 1) {
Z366 = Z174(Z365, Z335);
if (Z366 != Z141 && (Z366 <= Z161 || Z367(Z335, Z336, Z337))) {
ZpmCQ_13(Z339, (LONGCARD)Z335);
}
}
}

static BOOLEAN Z367
# ifdef HAVE_ARGS
(Z171 Z335, LONGINT Z336, LONGINT Z337)
# else
(Z335, Z336, Z337)
Z171 Z335;
LONGINT Z336;
LONGINT Z337;
# endif
{
LONGINT Z365;
Z171 Z369;
Z180 Z370;

ZarQdhNDD_0((ADDRESS *)&Z370, &Z336, (LONGINT)sizeof (Z168));
{
LONGINT B_5 = 0, B_6 = Z337;

if (B_5 <= B_6)
for (Z365 = B_5;; Z365 += 1) {
Z370->A[Z365] = Z218->A[Z365];
if (Z365 >= B_6) break;
}
}
Z365 = Z370->A[Z337];
for (;;) {
Z370->A[Z337] = Z365;
Z365 = Z174((Z168)Z365, Z335);
if (Z365 == Z141) {
ZarQdhNDD_3((ADDRESS *)&Z370, &Z336, (LONGINT)sizeof (Z168));
return FALSE;
}
do {
if (Z365 > Z159) {
Z365 = Z195.A[Z365 - 204];
}
if (Z365 <= Z161) {
ZarQdhNDD_3((ADDRESS *)&Z370, &Z336, (LONGINT)sizeof (Z168));
return TRUE;
} else {
DEC1(Z337, Z192.A[Z365 - 124]);
Z369 = Z193.A[Z365 - 124];
}
Z365 = Z174(Z370->A[Z337], Z369);
INC(Z337);
if (Z337 >= Z336) {
ZarQdhNDD_2((ADDRESS *)&Z370, &Z336, (LONGINT)sizeof (Z168));
}
} while (!(Z365 < Z166));
} EXIT_10:;
}

static void Z371
# ifdef HAVE_ARGS
(Z168 Z365, ZpmCQ_4 *Z339)
# else
(Z365, Z339)
Z168 Z365;
ZpmCQ_4 *Z339;
# endif
{
Z171 Z335;
Z168 Z366;

ZpmCQ_32(Z339);
for (Z335 = Z146; Z335 <= Z147; Z335 += 1) {
Z366 = Z174(Z365, Z335);
if (Z366 != Z141 && Z366 <= Z161) {
ZpmCQ_13(Z339, (LONGCARD)Z335);
}
}
}

static void Z363
# ifdef HAVE_ARGS
(LONGINT Z336, LONGINT Z337, ZpmCQ_4 *Z341)
# else
(Z336, Z337, Z341)
LONGINT Z336;
LONGINT Z337;
ZpmCQ_4 *Z341;
# endif
{
Z180 Z370;
LONGINT Z365;
Z171 Z369;
ZpmCQ_4 Z339;

ZarQdhNDD_0((ADDRESS *)&Z370, &Z336, (LONGINT)sizeof (Z168));
{
LONGINT B_7 = 0, B_8 = Z337;

if (B_7 <= B_8)
for (Z365 = B_7;; Z365 += 1) {
Z370->A[Z365] = Z218->A[Z365];
if (Z365 >= B_8) break;
}
}
ZpmCQ_5(&Z339, (LONGCARD)Z147);
ZpmCQ_32(Z341);
Z365 = Z370->A[Z337];
for (;;) {
if (Z337 >= Z336) {
ZarQdhNDD_2((ADDRESS *)&Z370, &Z336, (LONGINT)sizeof (Z168));
}
Z370->A[Z337] = Z365;
Z371((Z168)Z365, &Z339);
ZpmCQ_8(Z341, Z339);
Z365 = Z174((Z168)Z365, Z194.A[Z365]);
if (Z365 >= Z166) {
if (Z365 <= Z157) {
INC(Z337);
Z365 = Z196.A[Z365 - 92];
}
for (;;) {
if (Z365 > Z159) {
Z365 = Z195.A[Z365 - 204];
}
if (Z158 <= Z365 && Z365 <= Z161) {
ZarQdhNDD_3((ADDRESS *)&Z370, &Z336, (LONGINT)sizeof (Z168));
ZpmCQ_7(&Z339);
return;
} else if (Z365 < Z166) {
INC(Z337);
goto EXIT_12;
} else {
DEC1(Z337, Z192.A[Z365 - 124]);
Z369 = Z193.A[Z365 - 124];
}
Z365 = Z174(Z370->A[Z337], Z369);
INC(Z337);
if (Z365 < Z166) {
goto EXIT_12;
}
} EXIT_12:;
} else {
INC(Z337);
}
} EXIT_11:;
}

static Z168 Z174
# ifdef HAVE_ARGS
(Z168 Z365, Z171 Z373)
# else
(Z365, Z373)
Z168 Z365;
Z171 Z373;
# endif
{
Z177 Z374;
Z178 Z375;
Z179 Z376;

if (Z373 <= Z147) {
for (;;) {
Z374 = (Z177)(Z185.A[Z365] + Z373 * sizeof (Z172));
if (Z374->Y0 == Z365) {
return Z374->Y1;
}
Z365 = Z187.A[Z365];
if (Z365 == Z141) {
return Z141;
}
} EXIT_13:;
} else {
for (;;) {
Z376 = (Z179)(Z186.A[Z365] + Z373 * sizeof (Z176));
if (Z376->Y0 == Z365) {
return Z376->Y1;
}
Z365 = Z188.A[Z365];
} EXIT_14:;
}
}

static void Z378
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z185.A[Z377] = ADR (Z189.A[Z379]);
INC(Z377);
}

static void Z380
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z186.A[Z377] = ADR (Z191.A[Z379 + Z147 + 1 - 62]) - (Z147 + 1) * sizeof (Z176);
INC(Z377);
}

static void Z381
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z187.A[Z377] = Z379;
INC(Z377);
}

static void Z382
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z188.A[Z377] = Z379;
INC(Z377);
}

static void Z383
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
if (!ODD(Z377)) {
Z189.A[Z377 / 2].Y0 = Z379;
} else {
Z189.A[Z377 / 2].Y1 = Z379;
}
INC(Z377);
}

static void Z384
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z190.A[Z377 - 62] = Z379;
INC(Z377);
}

static void Z385
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
if (!ODD(Z377)) {
Z191.A[Z377 / 2 - 62].Y0 = Z379;
} else {
Z191.A[Z377 / 2 - 62].Y1 = Z379;
}
INC(Z377);
}

static void Z386
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z192.A[Z377 - 124] = Z379;
INC(Z377);
}

static void Z387
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z193.A[Z377 - 124] = Z379;
INC(Z377);
}

static void Z388
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z194.A[Z377] = Z379;
INC(Z377);
}

static void Z389
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z195.A[Z377 - 204] = Z379;
INC(Z377);
}

static void Z390
# ifdef HAVE_ARGS
(LONGCARD Z379)
# else
(Z379)
LONGCARD Z379;
# endif
{
Z196.A[Z377 - 92] = Z379;
INC(Z377);
}

static void Z391
 ARGS ((void))
{
Zmfy8_1 Z392;

Z392 = Z378;
Z377 = 1;
Zmfy8_9(Z392, (STRING)"XAX8+V@XMVP+XQW06XPW=XOXCX9X7W==WDX;X3WOW3XCXBXOVJX>XNWI", 56L, 30L);
Zmfy8_9(Z392, (STRING)"XNX5X@XGXFXAXDVLWM+XLX9XNMX+XG+W4X=X>X?X@VK0W7VR+XJX1I>", 55L, 31L);
Zmfy8_9(Z392, (STRING)"AVHXK3+V-XM2,XMXN+-6XNX4WFWTXKXIXHXNW,XLXNXE8XOXPX:", 51L, 30L);
Z392 = Z380;
Z377 = 1;
Zmfy8_9(Z392, (STRING)"V.++JCK6@Q+AV5BT+V.O++++.G+++++Q++++K++T9LK+++++.++++++", 55L, 52L);
Zmfy8_9(Z392, (STRING)":+6+>+++++;E<+++++++/++<J++++A+.D+6++++", 39L, 39L);
Z392 = Z381;
Z377 = 1;
Zmfy8_9(Z392, (STRING)"+++++++++++++++++++++L+++++++V1++M++++++B++G++W.++++++R", 55L, 53L);
Zmfy8_9(Z392, (STRING)"VK++VS+++VK+V6++W+++++++W+++8+++++++W.++R++++", 45L, 38L);
Z392 = Z382;
Z377 = 1;
Zmfy8_9(Z392, (STRING)"+++++++++++++++++++++L+++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z392, (STRING)"++++++++++V/++++++VC++++++++V:+VC++V/++++", 41L, 36L);
Z392 = Z383;
Z377 = 0;
Zmfy8_9(Z392, (STRING)".WSV0V:VGVSVKY8VKY/VKY/V0V;V7Y0V7Y0VFX;VFVRV7V@VLW+2YCVK", 56L, 29L);
Zmfy8_9(Z392, (STRING)"Y/W/X>W/X>V7Y0=WTW/W2VBY<V>Y2V>Y2V?VJ5WGVKY/VKY/VKY/V7Y0", 56L, 29L);
Zmfy8_9(Z392, (STRING)"V7Y0V7Y0V>Y2VBVMVBY<V=VIV=XDV=XDV=XDV-V4V-XBV-XBV-XBV>Y2", 56L, 28L);
Zmfy8_9(Z392, (STRING)"V>Y2V>Y2V=XDVDX<VDX<=?V-XBVDVQ2YC2YC2YC2YC2YC2YC2YC2YC2", 55L, 33L);
Zmfy8_9(Z392, (STRING)"YC2YC2YC5WM5WN5WJ5WK5WL5WI5WH5WO5WP5WQ5WRV@Y1V@Y1QXTV6Y3", 56L, 35L);
Zmfy8_9(Z392, (STRING)"V6Y3FXAFXAFMQXTV9VCV@Y1/X,/X,V6Y3W+Y4FXA/0/X,/X,BX7V1X5", 55L, 34L);
Zmfy8_9(Z392, (STRING)"V@Y1V@Y1V@Y1V6Y3V6Y3V6Y31X.1X.<X4BX7V1RQXT131X.V8Y:>X34", 55L, 33L);
Zmfy8_9(Z392, (STRING)"64X0V@VKVOWBIX6V6V>QXT4X0QXTV8VAV8Y:V8Y:BX7V1X578AXOADVP", 56L, 34L);
Zmfy8_9(Z392, (STRING)"Y5VPW.V.V57X2V.W><X4BX7V1X5AX@V<VHV<XK;XH>X3KTKXN@B<X4I", 55L, 34L);
Zmfy8_9(Z392, (STRING)"X6V+XLV+V2VNY@GN@C>@GOLX@LX@V/XIIX6PW=VSX:W.V6RWDVNW,RWE", 56L, 35L);
Zmfy8_9(Z392, (STRING)"VEW4VTWCW0W3W1WAHPV,V3;XHJSVA2W,202W-2826232EL9:,--/:<W2", 56L, 41L);
Zmfy8_9(Z392, (STRING)"W6?AV/XIV2V<V3V=V4W7V5W@OV-DKCJPW?W.V7NW:MW9VSVDVRW/V;VG", 56L, 33L);
Zmfy8_9(Z392, (STRING)"VQW5TW<VHW;VIW8VMWF++++++++++++++++++++++++++++++++++++", 55L, 46L);
Zmfy8_9(Z392, (STRING)"++++++++", 8L, 8L);
Z392 = Z384;
Z377 = Z147 + 1;
Z392 = Z385;
Z377 = (Z147 + 1) * 2;
Zmfy8_9(Z392, (STRING)"++++++++++++++++++++++LV+LFLGAE++++++AHVCY6VCVOVCVPV/V8", 55L, 46L);
Zmfy8_9(Z392, (STRING)"W+W1VJVTV/V9W-Y+W-YAV:VEV:VFW.Y7VSW0QV//1V8VB14BIV6V?V@", 55L, 31L);
Zmfy8_9(Z392, (STRING)"VL25SV1VBVN47<>VMY>MV,,.9;3X-6X/8X10X+W,Y?VAY;HQRV0VNW-", 55L, 37L);
Zmfy8_9(Z392, (STRING)"79PV.;=++++++++++++++++++++++++++++++++++++++++++", 49L, 48L);
Z392 = Z386;
Z377 = Z158;
Zmfy8_9(Z392, (STRING)"-3-+-+-+-+.+1/+31+,,..0+,.002,.+120./-+-.,.+11/0.,--,+,", 55L, 55L);
Zmfy8_9(Z392, (STRING)",.,,+-+---+,.+-----------", 25L, 25L);
Z392 = Z387;
Z377 = Z158;
Zmfy8_9(Z392, (STRING)"V?V@VAVAVBVBVCVCVDVDVEVFVFVFVGVGVGVHVHVIVIVIVIVJVJVKVKVK", 56L, 28L);
Zmfy8_9(Z392, (STRING)"VKVLVLVMVMVNVNVNVNVNVNVOVOVPVPVQVQVRVRVRVRVRVRVRVRVSVSVT", 56L, 28L);
Zmfy8_9(Z392, (STRING)"VTW+W+W,W,W-W-W-W.W.W/W0W1W1W1W1W1W1W1W1W1W1W1W1", 48L, 24L);
Z392 = Z388;
Z377 = 1;
Zmfy8_9(Z392, (STRING)"JT+@7@87A87G7GT++++T30+TT:010+300TTT0+V,+T0100+,+TTTT--", 55L, 54L);
Zmfy8_9(Z392, (STRING)"7,-T00-,-77----,TT--,V+7--TT---771---T", 38L, 37L);
Z392 = Z389;
Z377 = Z159 + 1;
Zmfy8_9(Z392, (STRING)"", 1L, 0L);
Z392 = Z390;
Z377 = Z156;
Zmfy8_9(Z392, (STRING)"X8X9X=X?XCXEXFXGXJXMXPXQXRXSY,Y-Y.Y8Y9Y=YBYDYEYFYGYHYIYJ", 56L, 28L);
Zmfy8_9(Z392, (STRING)"YKYLYMYN", 8L, 4L);
}

void ZmfDOBA_31
 ARGS ((void))
{
Zpky9FDA_49();
}

void ZmfDOBA_34
 ARGS ((void))
{
Zpky9FDA_56();
}

void BEGIN_Parser ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Tree ();
BEGIN_Scanner ();
BEGIN_General ();
BEGIN_Pack ();
BEGIN_Strings ();
BEGIN_DynArray ();
BEGIN_Sets ();
BEGIN_Errors ();
BEGIN_Position ();
BEGIN_IO ();
BEGIN_Scanner ();
BEGIN_Tree ();
BEGIN_Position ();
BEGIN_Tree ();

Z391();
ZmfDOBA_30 = FALSE;
Z197.A[1 - 1] = 75;
}
