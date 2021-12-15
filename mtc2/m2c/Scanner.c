#include "SYSTEM_.h"

#ifndef DEFINITION_Checks
#include "Checks.h"
#endif

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_General
#include "General.h"
#endif

#ifndef DEFINITION_Pack
#include "Pack.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Source
#include "Source.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_StringM
#include "StringM.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Tokens
#include "Tokens.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

INTEGER Zpky9FDA_3;
INTEGER Zpky9FDA_4;
Zpky9FDA_0 Zpky9FDA_5;
PROC Zpky9FDA_6;

static CARDINAL Z222;
static Zp1PEAFi_1 Z223, Z224;
static Zp1PEAFD_2 Z225;
static BOOLEAN Z226;
#define Z237	8
#define Z238	0
#define Z239	16
#define Z240	(1024 * 8 + 256)
#define Z241	'\0'
#define Z242	((CHAR)'\377')
#define Z243	'\n'
#define Z244	((CHAR)'\177')
#define Z245	251
#define Z246	1679
#define Z247	35
#define Z248	36
#define Z249	0
#define Z250	1
#define Z251	3
#define Z252	5
#define Z253	7
#define Z254	9
typedef SHORTCARD Z255;
typedef Z255 Z256;
typedef Z255 Z257;
typedef struct S_1 {
Z256 Y0, Y1;
} Z258;
typedef Z258 *Z261;
typedef struct S_12 {
CHAR A[1000000 + 1];
} *Z262;
typedef CHAR Z263;
static struct S_2 {
LONGCARD A[Z245 + 1];
} Z264;
static struct S_3 {
Z256 A[Z245 + 1];
} Z265;
static struct S_4 {
Z258 A[Z246 + 1];
} Z266;
static struct S_5 {
Z256 A[Z245 + 1];
} Z267;
static struct S_6 {
CHAR A[Z242 + 1];
} Z268, Z269;
static struct S_7 {
Z256 A[1000000 + 1];
} *Z270;
static LONGINT Z271;
static Z256 Z272;
static Z256 Z273;
static CHAR Z274;
static BOOLEAN Z275;
static ZDz6VQCC_4 Z276;
static BOOLEAN Z278;
static Z262 Z279;
static INTEGER Z280;
static LONGINT Z281;
static INTEGER Z282;
static INTEGER Z283;
static INTEGER Z284;
static CARDINAL Z285;
static INTEGER Z286;
static SHORTCARD Z287;
static struct S_8 {
struct S_9 {
ZDz6VQCC_4 Y0;
BOOLEAN Y1;
Z262 Y2;
INTEGER Y3;
LONGINT Y4;
INTEGER Y5;
INTEGER Y6;
INTEGER Y7;
CARDINAL Y8;
INTEGER Y9;
} A[Z239 - 1 + 1];
} Z288;
#define Z299	16
static LONGINT Z300;
static struct S_10 {
Z256 A[100000 + 1];
} *Z301;
static LONGINT Z302;
static void Z303 ARGS ((Z256 Z304));
static void Z307 ARGS ((void));
static void Z333 ARGS ((void));
static void Z306 ARGS ((Z256 Z345));
static void Z346 ARGS ((void));
static void Z348 ARGS ((void));
static void Z351 ARGS ((INTEGER Z352));
static void Z323 ARGS ((void));
static void Z353 ARGS ((INTEGER Z354));
static void Z355 ARGS ((INTEGER Z354, INTEGER Z356));
static void Z324 ARGS ((INTEGER Z321));
static void Z357 ARGS ((CHAR Z358));
static void Z359 ARGS ((CHAR Z358));
static CHAR Z360 ARGS ((void));
static CARDINAL Z363;
static void Z364 ARGS ((LONGCARD Z365));
static void Z366 ARGS ((LONGCARD Z365));
static void Z367 ARGS ((LONGCARD Z365));
static void Z368 ARGS ((LONGCARD Z365));
static void Z369 ARGS ((void));
static void Z308 ARGS ((SHORTCARD Z373));
static void Z379 ARGS ((void));

void Zpky9FDA_1
# ifdef HAVE_ARGS
(CARDINAL Z228, Zpky9FDA_0 *Z229)
# else
(Z228, Z229)
CARDINAL Z228;
Zpky9FDA_0 *Z229;
# endif
{
Z229->Y0 = Zpky9FDA_5.Y0;
switch (Z228) {
case ZqxDADK_2:;
Z229->U_1.V_1.Y1 = Zfb3DLQ_1;
break;
case ZqxDADK_3:;
case ZqxDADK_4:;
case ZqxDADK_5:;
Z229->U_1.V_2.Y2 = 1;
break;
case ZqxDADK_6:;
Z229->U_1.V_3.Y3 = CHR(0);
break;
case ZqxDADK_7:;
Z229->U_1.V_4.Y4 = Z224;
break;
case ZqxDADK_8:;
Z229->U_1.V_5.Y5 = Z223;
break;
default:
break;
}
}

static void Z303
# ifdef HAVE_ARGS
(Z256 Z304)
# else
(Z304)
Z256 Z304;
# endif
{
if (Z302 == Z300) {
ZarQdhNDD_2((ADDRESS *)&Z301, &Z300, (LONGINT)sizeof (Z256));
}
Z301->A[Z302] = Z272;
INC(Z302);
Z306(Z304);
}

static void Z307
 ARGS ((void))
{
Z273 = Z272;
if (Z302 > 0) {
DEC(Z302);
Z272 = Z301->A[Z302];
} else {
Z308(6);
}
}

INTEGER Zpky9FDA_9
 ARGS ((void))
{
Z256 Z304;
Z261 Z310;
BOOLEAN Z311;
INTEGER Z312, Z313, Z314, Z315;
Zp1PEAFD_2 Z225, Z316, Z317;

for (;;) {
Z304 = Z272;
Zpky9FDA_3 = 0;
Zpky9FDA_4 = Z282;
for (;;) {
for (;;) {
Z310 = (Z261)(Z264.A[Z304] + ORD(Z279->A[Z282]) * sizeof (Z258));
if (Z310->Y0 != Z304) {
Z304 = Z265.A[Z304];
if (Z304 == Z238) {
goto EXIT_3;
}
} else {
Z304 = Z310->Y1;
INC(Zpky9FDA_3);
Z270->A[Zpky9FDA_3] = Z304;
INC(Z282);
}
} EXIT_3:;
for (;;) {
switch (Z270->A[Zpky9FDA_3]) {
case 251:;
Z222 = 1;
Z306(Z251);
Z311 = FALSE;
goto EXIT_4;
break;
case 250:;
INC(Z222);
Z311 = FALSE;
goto EXIT_4;
break;
case 248:;
DEC(Z222);
if (Z222 == 0) {
Z306(Z250);
}
Z311 = FALSE;
goto EXIT_4;
break;
case 14:;
case 27:;
case 40:;
case 247:;
case 249:;
Z311 = FALSE;
goto EXIT_4;
break;
case 245:;
INC(Z222);
Z306(Z252);
Z311 = FALSE;
goto EXIT_4;
break;
case 244:;
DEC(Z222);
if (Z222 == 0) {
Z306(Z250);
}
Z311 = FALSE;
goto EXIT_4;
break;
case 13:;
case 26:;
case 41:;
case 243:;
case 246:;
Z311 = FALSE;
goto EXIT_4;
break;
case 17:;
Z311 = FALSE;
goto EXIT_4;
break;
case 15:;
case 28:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zpky9FDA_5.U_1.V_2.Y2 = Zp1PEAFD_16(&Z317, 10L);
return ZqxDADK_3;
Z311 = FALSE;
goto EXIT_4;
break;
case 25:;
DEC1(Z282, 2);
DEC1(Zpky9FDA_3, 2);
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zpky9FDA_5.U_1.V_2.Y2 = Zp1PEAFD_16(&Z317, 10L);
return ZqxDADK_3;
Z311 = FALSE;
goto EXIT_4;
break;
case 24:;
DEC1(Z282, 2);
DEC1(Zpky9FDA_3, 2);
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zpky9FDA_5.U_1.V_2.Y2 = Zp1PEAFD_16(&Z317, 10L);
return ZqxDADK_3;
Z311 = FALSE;
goto EXIT_4;
break;
case 21:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zp1PEAFD_11(&Z317, 1, (Zp1PEAFD_1)(Zp1PEAFD_7(&Z317) - 1), &Z225);
Zpky9FDA_5.U_1.V_2.Y2 = Zp1PEAFD_16(&Z225, 8L);
return ZqxDADK_4;
Z311 = FALSE;
goto EXIT_4;
break;
case 22:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zp1PEAFD_11(&Z317, 1, (Zp1PEAFD_1)(Zp1PEAFD_7(&Z317) - 1), &Z225);
Zpky9FDA_5.U_1.V_3.Y3 = CHR(Zp1PEAFD_16(&Z225, 8L));
return ZqxDADK_6;
Z311 = FALSE;
goto EXIT_4;
break;
case 23:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zp1PEAFD_11(&Z317, 1, (Zp1PEAFD_1)(Zp1PEAFD_7(&Z317) - 1), &Z225);
Zpky9FDA_5.U_1.V_2.Y2 = Zp1PEAFD_16(&Z225, 16L);
return ZqxDADK_5;
Z311 = FALSE;
goto EXIT_4;
break;
case 20:;
case 31:;
case 32:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zpky9FDA_5.U_1.V_4.Y4 = Zp1PEAFi_2(&Z317);
return ZqxDADK_7;
Z311 = FALSE;
goto EXIT_4;
break;
case 242:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zp1PEAFD_4(&Z225);
Z306(Z253);
Z311 = FALSE;
goto EXIT_4;
break;
case 12:;
case 42:;
Zpky9FDA_10(&Z316);
Zp1PEAFD_5(&Z225, &Z316);
Z311 = FALSE;
goto EXIT_4;
break;
case 241:;
Z306(Z250);
Zpky9FDA_5.U_1.V_5.Y5 = Zp1PEAFi_2(&Z225);
return ZqxDADK_8;
Z311 = FALSE;
goto EXIT_4;
break;
case 240:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zp1PEAFD_4(&Z225);
Z306(Z254);
Z311 = FALSE;
goto EXIT_4;
break;
case 11:;
case 43:;
Zpky9FDA_10(&Z316);
Zp1PEAFD_5(&Z225, &Z316);
Z311 = FALSE;
goto EXIT_4;
break;
case 239:;
Z306(Z250);
Zpky9FDA_5.U_1.V_5.Y5 = Zp1PEAFi_2(&Z225);
return ZqxDADK_8;
Z311 = FALSE;
goto EXIT_4;
break;
case 238:;
Zp1PEAFD_6(&Z225, '\t');
Z323();
Z311 = FALSE;
goto EXIT_4;
break;
case 237:;
Z324(0L);
Z306(Z250);
ZblNKKO_39((LONGCARD)ZblNKKO_10, (LONGCARD)ZblNKKO_29, Zpky9FDA_5.Y0);
Zpky9FDA_5.U_1.V_5.Y5 = Zp1PEAFi_2(&Z225);
return ZqxDADK_8;
Z311 = FALSE;
goto EXIT_4;
break;
case 236:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_9;
Z311 = FALSE;
goto EXIT_4;
break;
case 235:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_33;
Z311 = FALSE;
goto EXIT_4;
break;
case 234:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_10;
Z311 = FALSE;
goto EXIT_4;
break;
case 233:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_11;
Z311 = FALSE;
goto EXIT_4;
break;
case 232:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_12;
Z311 = FALSE;
goto EXIT_4;
break;
case 231:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_13;
Z311 = FALSE;
goto EXIT_4;
break;
case 230:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_14;
Z311 = FALSE;
goto EXIT_4;
break;
case 229:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_15;
Z311 = FALSE;
goto EXIT_4;
break;
case 227:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_16;
Z311 = FALSE;
goto EXIT_4;
break;
case 228:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_17;
Z311 = FALSE;
goto EXIT_4;
break;
case 226:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_18;
Z311 = FALSE;
goto EXIT_4;
break;
case 224:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_19;
Z311 = FALSE;
goto EXIT_4;
break;
case 225:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_20;
Z311 = FALSE;
goto EXIT_4;
break;
case 223:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_21;
Z311 = FALSE;
goto EXIT_4;
break;
case 220:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_22;
Z311 = FALSE;
goto EXIT_4;
break;
case 222:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_23;
Z311 = FALSE;
goto EXIT_4;
break;
case 221:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_9;
Z311 = FALSE;
goto EXIT_4;
break;
case 219:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_24;
Z311 = FALSE;
goto EXIT_4;
break;
case 217:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_25;
Z311 = FALSE;
goto EXIT_4;
break;
case 218:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_26;
Z311 = FALSE;
goto EXIT_4;
break;
case 216:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_27;
Z311 = FALSE;
goto EXIT_4;
break;
case 215:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_28;
Z311 = FALSE;
goto EXIT_4;
break;
case 214:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_29;
Z311 = FALSE;
goto EXIT_4;
break;
case 213:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_30;
Z311 = FALSE;
goto EXIT_4;
break;
case 212:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_31;
Z311 = FALSE;
goto EXIT_4;
break;
case 211:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_32;
Z311 = FALSE;
goto EXIT_4;
break;
case 210:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_56;
Z311 = FALSE;
goto EXIT_4;
break;
case 209:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_33;
Z311 = FALSE;
goto EXIT_4;
break;
case 207:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_34;
Z311 = FALSE;
goto EXIT_4;
break;
case 202:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_35;
Z311 = FALSE;
goto EXIT_4;
break;
case 198:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_36;
Z311 = FALSE;
goto EXIT_4;
break;
case 196:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_37;
Z311 = FALSE;
goto EXIT_4;
break;
case 193:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_38;
Z311 = FALSE;
goto EXIT_4;
break;
case 188:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_39;
Z311 = FALSE;
goto EXIT_4;
break;
case 179:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_40;
Z311 = FALSE;
goto EXIT_4;
break;
case 177:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_41;
Z311 = FALSE;
goto EXIT_4;
break;
case 175:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_42;
Z311 = FALSE;
goto EXIT_4;
break;
case 174:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_43;
Z311 = FALSE;
goto EXIT_4;
break;
case 170:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_44;
Z311 = FALSE;
goto EXIT_4;
break;
case 168:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_45;
Z311 = FALSE;
goto EXIT_4;
break;
case 166:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_46;
Z311 = FALSE;
goto EXIT_4;
break;
case 57:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_47;
Z311 = FALSE;
goto EXIT_4;
break;
case 162:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_48;
Z311 = FALSE;
goto EXIT_4;
break;
case 159:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_49;
Z311 = FALSE;
goto EXIT_4;
break;
case 158:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_50;
Z311 = FALSE;
goto EXIT_4;
break;
case 147:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_51;
Z311 = FALSE;
goto EXIT_4;
break;
case 142:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_52;
Z311 = FALSE;
goto EXIT_4;
break;
case 140:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_53;
Z311 = FALSE;
goto EXIT_4;
break;
case 133:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_54;
Z311 = FALSE;
goto EXIT_4;
break;
case 136:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_55;
Z311 = FALSE;
goto EXIT_4;
break;
case 130:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_56;
Z311 = FALSE;
goto EXIT_4;
break;
case 127:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_57;
Z311 = FALSE;
goto EXIT_4;
break;
case 126:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_58;
Z311 = FALSE;
goto EXIT_4;
break;
case 124:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_59;
Z311 = FALSE;
goto EXIT_4;
break;
case 118:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_60;
Z311 = FALSE;
goto EXIT_4;
break;
case 109:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_61;
Z311 = FALSE;
goto EXIT_4;
break;
case 100:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_62;
Z311 = FALSE;
goto EXIT_4;
break;
case 96:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_63;
Z311 = FALSE;
goto EXIT_4;
break;
case 92:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_64;
Z311 = FALSE;
goto EXIT_4;
break;
case 88:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_65;
Z311 = FALSE;
goto EXIT_4;
break;
case 85:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_66;
Z311 = FALSE;
goto EXIT_4;
break;
case 82:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_67;
Z311 = FALSE;
goto EXIT_4;
break;
case 81:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_68;
Z311 = FALSE;
goto EXIT_4;
break;
case 77:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_69;
Z311 = FALSE;
goto EXIT_4;
break;
case 72:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_70;
Z311 = FALSE;
goto EXIT_4;
break;
case 69:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_71;
Z311 = FALSE;
goto EXIT_4;
break;
case 65:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_72;
Z311 = FALSE;
goto EXIT_4;
break;
case 61:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_73;
Z311 = FALSE;
goto EXIT_4;
break;
case 54:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_74;
Z311 = FALSE;
goto EXIT_4;
break;
case 51:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
return ZqxDADK_75;
Z311 = FALSE;
goto EXIT_4;
break;
case 16:;
case 44:;
case 45:;
case 46:;
case 47:;
case 48:;
case 49:;
case 50:;
case 52:;
case 53:;
case 55:;
case 56:;
case 58:;
case 59:;
case 60:;
case 62:;
case 63:;
case 64:;
case 66:;
case 67:;
case 68:;
case 70:;
case 71:;
case 73:;
case 74:;
case 75:;
case 76:;
case 78:;
case 79:;
case 80:;
case 83:;
case 84:;
case 86:;
case 87:;
case 89:;
case 90:;
case 91:;
case 93:;
case 94:;
case 95:;
case 97:;
case 98:;
case 99:;
case 101:;
case 102:;
case 103:;
case 104:;
case 105:;
case 106:;
case 107:;
case 108:;
case 110:;
case 111:;
case 112:;
case 113:;
case 114:;
case 115:;
case 116:;
case 117:;
case 119:;
case 120:;
case 121:;
case 122:;
case 123:;
case 125:;
case 128:;
case 129:;
case 131:;
case 132:;
case 134:;
case 135:;
case 137:;
case 138:;
case 139:;
case 141:;
case 143:;
case 144:;
case 145:;
case 146:;
case 148:;
case 149:;
case 150:;
case 151:;
case 152:;
case 153:;
case 154:;
case 155:;
case 156:;
case 157:;
case 160:;
case 161:;
case 163:;
case 164:;
case 165:;
case 167:;
case 169:;
case 171:;
case 172:;
case 173:;
case 176:;
case 178:;
case 180:;
case 181:;
case 182:;
case 183:;
case 184:;
case 185:;
case 186:;
case 187:;
case 189:;
case 190:;
case 191:;
case 192:;
case 194:;
case 195:;
case 197:;
case 199:;
case 200:;
case 201:;
case 203:;
case 204:;
case 205:;
case 206:;
case 208:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_10(&Z317);
Zpky9FDA_5.U_1.V_1.Y1 = Zfb3DLQ_2(&Z317);
return ZqxDADK_2;
Z311 = FALSE;
goto EXIT_4;
break;
case 18:;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Z226 = TRUE;
Zpky9FDA_10(&Z317);
Zpky9FDA_5.U_1.V_1.Y1 = Zfb3DLQ_2(&Z317);
return ZqxDADK_2;
Z311 = FALSE;
goto EXIT_4;
break;
case 39:;
while (Z279->A[Z282] == ' ') {
INC(Z282);
}
Z311 = FALSE;
goto EXIT_4;
break;
case 38:;
Z323();
Z311 = FALSE;
goto EXIT_4;
break;
case 37:;
Z324(0L);
Z311 = FALSE;
goto EXIT_4;
break;
case 1:;
case 2:;
case 3:;
case 4:;
case 5:;
case 6:;
case 7:;
case 8:;
case 9:;
case 10:;
case 19:;
case 29:;
case 30:;
case 33:;
case 34:;
DEC(Z282);
DEC(Zpky9FDA_3);
break;
case 36:;
INC(Z282);
Zpky9FDA_3 = 1;
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
ZblNKKO_39((LONGCARD)ZblNKKO_8, (LONGCARD)ZblNKKO_29, Zpky9FDA_5.Y0);
Z311 = FALSE;
goto EXIT_4;
break;
case Z238:;
Z311 = FALSE;
goto EXIT_4;
break;
case 35:;
DEC(Z282);
DEC(Zpky9FDA_3);
if (Zpky9FDA_3 == 0) {
Z304 = Z272;
} else {
Z304 = Z270->A[Zpky9FDA_3];
}
if (Z282 != Z280 + Z283) {
Z304 = Z267.A[Z304];
if (Z304 != Z238) {
INC(Z282);
INC(Zpky9FDA_3);
Z270->A[Zpky9FDA_3] = Z304;
Z311 = TRUE;
goto EXIT_4;
}
} else {
if (!Z278) {
Z313 = Z282 - Zpky9FDA_3 - 1;
Z314 = ZdaDDAD7_1 - Zpky9FDA_3 % ZdaDDAD7_1 - 1;
if (Z313 > Z314) {
{
LONGINT B_1 = 0, B_2 = Zpky9FDA_3;

if (B_1 <= B_2)
for (Z312 = B_1;; Z312 += 1) {
Z279->A[Z314 + Z312] = Z279->A[Z313 + Z312];
if (Z312 >= B_2) break;
}
}
DEC1(Z286, Z313 - Z314);
DEC1(Zpky9FDA_4, Z313 - Z314);
Z280 = Z314 + Zpky9FDA_3 + 1;
} else {
Z280 = Z282;
}
Z315 = ZdaDDAD7_8(ZdaDDAD7_7((LONGCARD)(Z281 - 4 - ZdaDDAD7_1 - Zpky9FDA_3)));
if (Z315 < Z281 / 8) {
ZarQdhNDD_2((ADDRESS *)&Z279, &Z281, (LONGINT)sizeof (CHAR));
if (Z279 == NIL) {
Z308(1);
}
Z315 = ZdaDDAD7_8(ZdaDDAD7_7((LONGCARD)(Z281 - 4 - ZdaDDAD7_1 - Zpky9FDA_3)));
if (Z271 < Z281) {
ZarQdhNDD_2((ADDRESS *)&Z270, &Z271, (LONGINT)sizeof (Z256));
if (Z270 == NIL) {
Z308(1);
}
}
}
Z282 = Z280;
INC1(Z284, Z283);
Z283 = ZpwNQF2_1(Z276, ADR (Z279->A[Z282]), (LONGCARD)Z315);
if (Z283 <= 0) {
Z283 = 0;
Z278 = TRUE;
}
Z279->A[Z280 + Z283] = Z244;
Z279->A[Z280 + Z283 + 1] = '\0';
Z311 = TRUE;
goto EXIT_4;
}
if (Zpky9FDA_3 == 0) {
Zpky9FDA_5.Y0.Y1 = Z285;
Zpky9FDA_5.Y0.Y2 = Z282 - Z286 - Zpky9FDA_3;
Zpky9FDA_13();
if (Z287 == 0) {
if (Z272 == Z251) {
ZblNKKO_39((LONGCARD)ZblNKKO_9, (LONGCARD)ZblNKKO_29, Zpky9FDA_5.Y0);
Z222 = 0;
}
if (Z272 != Z250) {
Z306(Z250);
}
if (Z226) {
ZblNKKO_39((LONGCARD)ZblNKKO_19, (LONGCARD)ZblNKKO_30, Zpky9FDA_5.Y0);
Z226 = FALSE;
}
}
if (Z287 == 0) {
return Zpky9FDA_2;
}
Z311 = FALSE;
goto EXIT_4;
}
}
break;
default:
Z308(0);
break;
}
} EXIT_4:;
if (Z311) {
} else {
goto EXIT_2;
}
} EXIT_2:;
} EXIT_1:;
}

void Zpky9FDA_8
# ifdef HAVE_ARGS
(CHAR Z332[], LONGCARD O_1)
# else
(Z332, O_1)
CHAR Z332[];
LONGCARD O_1;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z332, O_1, CHAR)
if (Z275 && Z283 == 0) {
Z287 = 0;
Z275 = FALSE;
}
Z333();
if (ORD(Z332[0]) == 0) {
Z276 = ZDz6VQCC_1;
} else {
Z276 = ZpwNQF2_0(Z332, O_1);
}
if (Z276 < 0) {
Z308(5);
}
FREE_OPEN_ARRAYS
}

static void Z333
 ARGS ((void))
{
if (Z287 >= Z239) {
Z308(3);
}
INC(Z287);
{
register struct S_9 *W_1 = &Z288.A[Z287 - 1];

W_1->Y0 = Z276;
W_1->Y1 = Z278;
W_1->Y2 = Z279;
W_1->Y3 = Z280;
W_1->Y4 = Z281;
W_1->Y5 = Z282;
W_1->Y6 = Z283;
W_1->Y7 = Z284;
W_1->Y8 = Z285;
W_1->Y9 = Z286;
}
Z281 = Z240;
ZarQdhNDD_0((ADDRESS *)&Z279, &Z281, (LONGINT)sizeof (CHAR));
if (Z279 == NIL) {
Z308(1);
}
Z280 = ZdaDDAD7_1;
Z279->A[Z280 - 1] = Z243;
Z279->A[Z280] = Z244;
Z279->A[Z280 + 1] = '\0';
Z282 = Z280;
Z278 = FALSE;
Z283 = 0;
Z284 = 0;
Z285 = 1;
Z286 = Z280 - 1;
}

void Zpky9FDA_13
 ARGS ((void))
{
if (Z287 == 0) {
Z308(4);
}
ZpwNQF2_2(Z276);
ZarQdhNDD_3((ADDRESS *)&Z279, &Z281, (LONGINT)sizeof (CHAR));
{
register struct S_9 *W_2 = &Z288.A[Z287 - 1];

Z276 = W_2->Y0;
Z278 = W_2->Y1;
Z279 = W_2->Y2;
Z280 = W_2->Y3;
Z281 = W_2->Y4;
Z282 = W_2->Y5;
Z283 = W_2->Y6;
Z284 = W_2->Y7;
Z285 = W_2->Y8;
Z286 = W_2->Y9;
}
DEC(Z287);
Z275 = FALSE;
}

void Zpky9FDA_10
# ifdef HAVE_ARGS
(Zp1PEAFD_2 *Z317)
# else
(Z317)
Zp1PEAFD_2 *Z317;
# endif
{
CARDINAL Z338, Z339;

Z339 = Z282 - Zpky9FDA_3 - 1;
Z317->Y1 = ZdaDDAD7_3(Zpky9FDA_3, (LONGINT)Zp1PEAFD_0);
{
LONGCARD B_3 = 1, B_4 = Z317->Y1;

if (B_3 <= B_4)
for (Z338 = B_3;; Z338 += 1) {
Z317->Y0.A[Z338] = Z279->A[Z339 + Z338];
if (Z338 >= B_4) break;
}
}
}

void Zpky9FDA_11
# ifdef HAVE_ARGS
(Zp1PEAFD_2 *Z317)
# else
(Z317)
Zp1PEAFD_2 *Z317;
# endif
{
CARDINAL Z338, Z339;

Z339 = Z282 - Zpky9FDA_3 - 1;
Z317->Y1 = ZdaDDAD7_3(Zpky9FDA_3, (LONGINT)Zp1PEAFD_0);
{
LONGCARD B_5 = 1, B_6 = Z317->Y1;

if (B_5 <= B_6)
for (Z338 = B_5;; Z338 += 1) {
Z317->Y0.A[Z338] = Z268.A[Z279->A[Z339 + Z338]];
if (Z338 >= B_6) break;
}
}
}

void Zpky9FDA_12
# ifdef HAVE_ARGS
(Zp1PEAFD_2 *Z317)
# else
(Z317)
Zp1PEAFD_2 *Z317;
# endif
{
CARDINAL Z338, Z339;

Z339 = Z282 - Zpky9FDA_3 - 1;
Z317->Y1 = ZdaDDAD7_3(Zpky9FDA_3, (LONGINT)Zp1PEAFD_0);
{
LONGCARD B_7 = 1, B_8 = Z317->Y1;

if (B_7 <= B_8)
for (Z338 = B_7;; Z338 += 1) {
Z317->Y0.A[Z338] = Z269.A[Z279->A[Z339 + Z338]];
if (Z338 >= B_8) break;
}
}
}

static void Z306
# ifdef HAVE_ARGS
(Z256 Z345)
# else
(Z345)
Z256 Z345;
# endif
{
Z273 = Z272;
Z272 = Z345;
}

static void Z346
 ARGS ((void))
{
Z256 Z347;

Z347 = Z272;
Z272 = Z273;
Z273 = Z347;
}

static void Z348
 ARGS ((void))
{
INTEGER Z338;

{
LONGINT B_9 = Z282 - Zpky9FDA_3, B_10 = Z282 - 1;

if (B_9 <= B_10)
for (Z338 = B_9;; Z338 += 1) {
ZfM_24((ZDz6VQCC_4)ZfM_1, Z279->A[Z338]);
if (Z338 >= B_10) break;
}
}
}

static void Z351
# ifdef HAVE_ARGS
(INTEGER Z352)
# else
(Z352)
INTEGER Z352;
# endif
{
DEC1(Z282, Zpky9FDA_3 - Z352);
Zpky9FDA_3 = Z352;
}

static void Z323
 ARGS ((void))
{
DEC1(Z286, Z237 - 1 - (Z282 - Z286 - 2) % Z237);
}

static void Z353
# ifdef HAVE_ARGS
(INTEGER Z354)
# else
(Z354)
INTEGER Z354;
# endif
{
DEC1(Z286, Z237 - 1 - (Z282 - Z286 - Zpky9FDA_3 + Z354 - 1) % Z237);
}

static void Z355
# ifdef HAVE_ARGS
(INTEGER Z354, INTEGER Z356)
# else
(Z354, Z356)
INTEGER Z354, Z356;
# endif
{
DEC1(Z286, Z237 - 1 - (Z282 - Z286 - Zpky9FDA_3 + Z354 - 1) % Z237);
}

static void Z324
# ifdef HAVE_ARGS
(INTEGER Z321)
# else
(Z321)
INTEGER Z321;
# endif
{
INC(Z285);
Z286 = Z282 - 1 - Z321;
}

static void Z357
# ifdef HAVE_ARGS
(CHAR Z358)
# else
(Z358)
CHAR Z358;
# endif
{
ZfM_24((ZDz6VQCC_4)ZfM_1, Z358);
}

static void Z359
# ifdef HAVE_ARGS
(CHAR Z358)
# else
(Z358)
CHAR Z358;
# endif
{
DEC(Z282);
Z279->A[Z282] = Z358;
}

static CHAR Z360
 ARGS ((void))
{
if (Z282 == Z280 + Z283) {
if (!Z278) {
DEC1(Z286, Z283);
Z282 = 0;
Z280 = 0;
INC1(Z284, Z283);
Z283 = ZpwNQF2_1(Z276, (ADDRESS)Z279, ZdaDDAD7_8(ZdaDDAD7_7((LONGCARD)Z281)));
if (Z283 <= 0) {
Z283 = 0;
Z278 = TRUE;
}
Z279->A[Z283] = Z244;
Z279->A[Z283 + 1] = '\0';
}
}
if (Z282 == Z280 + Z283) {
return '\0';
} else {
INC(Z282);
return Z279->A[Z282 - 1];
}
}

void Zpky9FDA_7
 ARGS ((void))
{
Z226 = FALSE;
Z222 = 0;
Zp1PEAFD_4(&Z225);
Z223 = Zp1PEAFi_2(&Z225);
Zp1PEAFD_13((STRING)"1.0", 3L, &Z225);
Z224 = Zp1PEAFi_2(&Z225);
}

void Zpky9FDA_14
 ARGS ((void))
{
}

static void Z364
# ifdef HAVE_ARGS
(LONGCARD Z365)
# else
(Z365)
LONGCARD Z365;
# endif
{
Z264.A[Z363] = (LONGCARD)ADR (Z266.A[Z365]);
INC(Z363);
}

static void Z366
# ifdef HAVE_ARGS
(LONGCARD Z365)
# else
(Z365)
LONGCARD Z365;
# endif
{
Z265.A[Z363] = Z365;
INC(Z363);
}

static void Z367
# ifdef HAVE_ARGS
(LONGCARD Z365)
# else
(Z365)
LONGCARD Z365;
# endif
{
Z267.A[Z363] = Z365;
INC(Z363);
}

static void Z368
# ifdef HAVE_ARGS
(LONGCARD Z365)
# else
(Z365)
LONGCARD Z365;
# endif
{
if (!ODD(Z363)) {
Z266.A[Z363 / 2].Y0 = Z365;
} else {
Z266.A[Z363 / 2].Y1 = Z365;
}
INC(Z363);
}

static void Z369
 ARGS ((void))
{
Zmfy8_1 Z370;

Z370 = Z364;
Z363 = 1;
Zmfy8_9(Z370, (STRING)"++VB+VP+W1+W-+X/^3++c3cI+eLgCeA,++++j,p0h2V;+<h:+++++++", 55L, 39L);
Zmfy8_9(Z370, (STRING)"++++EL-5?2K+StE+LGV0V/V:V?+\\HVQY<+];_<bG+c-bG+bLbGbSbQ+", 55L, 38L);
Zmfy8_9(Z370, (STRING)"tAbNc2++c3c5+c?c1+c1c5c:+cDd9cQ+d-d+d;+dPeFe<e@eDeBeGf9", 55L, 31L);
Zmfy8_9(Z370, (STRING)"+f/f0f=f=g9fSg-g;+g8g4g/gEgN+tD++gRgN+gThEh5i4iM+k2n>n>", 55L, 31L);
Zmfy8_9(Z370, (STRING)"+tF+o2tBo2q1+tHtBtMtItDu0tHtTtOtQ++tQtT+tStQtP+tQ+u8+tT", 55L, 32L);
Zmfy8_9(Z370, (STRING)"u9u9++u;+u++u=u<u8u>u4u@u<u>+uLu@u<u<+u>uM+uN+uMuLuH+uJ", 55L, 32L);
Zmfy8_9(Z370, (STRING)"uEv.uA+v/++++++++.++vJ+++v8++vH++++++vM++++++++v:++vOvQ", 55L, 44L);
Zmfy8_9(Z370, (STRING)"+vQ++", 5L, 4L);
Z370 = Z366;
Z363 = 1;
Zmfy8_9(Z370, (STRING)";,F.E07264MMMM>M+;MM>>+++MM:K@?MK+++MM+FE76;;;;;;;;;;;;", 55L, 55L);
Zmfy8_9(Z370, (STRING)";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;", 55L, 55L);
Zmfy8_9(Z370, (STRING)";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;", 55L, 55L);
Zmfy8_9(Z370, (STRING)";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;+++++++M++M", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++M++M++++++M++PQ++++8++89+9++", 31L, 31L);
Z370 = Z367;
Z363 = 1;
Zmfy8_9(Z370, (STRING)"++FFEE776667+++++++++++++EF++++++++++++FE76++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++", 31L, 31L);
Z370 = Z368;
Z363 = 0;
Zmfy8_9(Z370, (STRING)"++++++++++++++++++,Q,P++,<,<++++++++++++++++++++++++,<+", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++,R++,ZI,ZE++++,ZD,ZK,ZC,ZB,ZA,Z@,Z?,Z>,Z<,Z;,:", 55L, 43L);
Zmfy8_9(Z370, (STRING)",:,:,:,:,:,:,:,G,G,Z9,Z8,Z5,Z4,Z2JDZ2Z3,YN,YH,Y@,Y3,V-,", 55L, 43L);
Zmfy8_9(Z370, (STRING)"V8V/V0V2V3,X:.Q.P,X6,X0,X-,WT,WE,W<,V5,W-,VO,VJ,VG,V?0Q", 55L, 37L);
Zmfy8_9(Z370, (STRING)"0P@C,Z1V0V1,Z0,Z/4ZG4ZF.SV1V22ZG2ZFHLV-Y.HLV-Y,.ZRV.XT.", 55L, 37L);
Zmfy8_9(Z370, (STRING)"ZPV3V4V5V6V9V:0TV8V9V.XPV-V.V8XMV:V;V.V/4V,V;V<4ZH0ZL2V+", 56L, 31L);
Zmfy8_9(Z370, (STRING)",Z.,Z-,Z,,Z+MNV<V=2ZJ6666666666666666660ZOV=V>666666666", 55L, 45L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666V@VA66666666666666", 55L, 53L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666666666666666666666", 55L, 55L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666666666666666666666", 55L, 55L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666666666666666666666", 55L, 55L);
Zmfy8_9(Z370, (STRING)"66666VAVB6666666666666666666666666666666666666666666666", 55L, 53L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666666666666666666666", 55L, 55L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666666666666666666666", 55L, 55L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666666666666666666666", 55L, 55L);
Zmfy8_9(Z370, (STRING)"6666666666666666666666666666666666666666666667777777777", 55L, 55L);
Zmfy8_9(Z370, (STRING)"77777777V?VCV?V@777777777777777777777777777777777777777", 55L, 51L);
Zmfy8_9(Z370, (STRING)"77777777777777777VCVD7777777777777777777777777777777777", 55L, 53L);
Zmfy8_9(Z370, (STRING)"7777777777777777777777777777777777777777777777777777777", 55L, 55L);
Zmfy8_9(Z370, (STRING)"7777777777777777777777777777777777777777777777777777777", 55L, 55L);
Zmfy8_9(Z370, (STRING)"777777777777777777777777777777VDVE777777777777777777777", 55L, 53L);
Zmfy8_9(Z370, (STRING)"7777777777777777777777777777777777777777777777777777777", 55L, 55L);
Zmfy8_9(Z370, (STRING)"7777777777777777777777777777777777777777777777777777777", 55L, 55L);
Zmfy8_9(Z370, (STRING)"7777777777777777777777777777777777777777777777777777777", 55L, 55L);
Zmfy8_9(Z370, (STRING)"7777777777777777777777777777777777777777777777777777777", 55L, 55L);
Zmfy8_9(Z370, (STRING)"777777777777777:JVEVF:::::::::::::::::G:G;;VGVHVHVIVJVK", 55L, 47L);
Zmfy8_9(Z370, (STRING)"VKVLVLVMVMVNVPVQ:@:AVQVRVTW+;;;;;;;;;;;;;;;;;;;;W+W,W-W.", 56L, 40L);
Zmfy8_9(Z370, (STRING)"W.W/W0W1W1W2W2W3W4W5;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;", 55L, 45L);
Zmfy8_9(Z370, (STRING)";;;;;;;;;;;;;;;;;W5W6W6W7W8W9W9W:;=W:W;;;;;;;;;;;;;;;;;", 55L, 45L);
Zmfy8_9(Z370, (STRING)";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;==?????????????????", 55L, 55L);
Zmfy8_9(Z370, (STRING)"???W<W=====================?HW=W>W>W?W?W@W@WAWAWBWBWC==", 55L, 41L);
Zmfy8_9(Z370, (STRING)"==================================================WCWDWE", 56L, 53L);
Zmfy8_9(Z370, (STRING)"WNWFWGWGWHWEWFWHWI=====================================", 55L, 46L);
Zmfy8_9(Z370, (STRING)"===============>>>>>>>>>>>>>>>>>>>>WIWJWJWKWKWLWLWMWNWO", 55L, 45L);
Zmfy8_9(Z370, (STRING)"WOWPWPWQ>>>>>>>>>>>>WQWR>BGGGGGGGGGGGGGGGGKKKKKKKKKKKKK", 55L, 49L);
Zmfy8_9(Z370, (STRING)"KKKKKKKGIG>WRWSX-X.X.X/X0X1>>>>>>>>>>>>EEEEEEEEEEEEEEEE", 55L, 47L);
Zmfy8_9(Z370, (STRING)"EEX1X2X2X3EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 51L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEEEEEEEX3X4EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 53L);
Zmfy8_9(Z370, (STRING)"X4X5EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 53L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 55L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEEEEEEEEEEEEEEEEX6X7EEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 53L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 55L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 55L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 55L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 55L, 55L);
Zmfy8_9(Z370, (STRING)"EEEEEEEEEEEFFFFFFFFFFFFFFFFFFX7X8X8X9FFFFFFFFFFFFFFFFFF", 55L, 51L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFX<X=FFX>X?FFFFF", 55L, 51L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 55L, 55L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 55L, 55L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFX?", 55L, 54L);
Zmfy8_9(Z370, (STRING)"X@FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 55L, 54L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 55L, 55L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 55L, 55L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 55L, 55L);
Zmfy8_9(Z370, (STRING)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFV6W8VOVTWTX,V6V7X:", 56L, 47L);
Zmfy8_9(Z370, (STRING)"XLXAXBX=XAXBXCVOVSX=X>XCXDX:X<X:X;V6W4WTX+XDXEXEXFV6W0VO", 56L, 28L);
Zmfy8_9(Z370, (STRING)"VPXFXGXGXHXHXIXIXJXJXKXMXNXNXOXPXQXQXRXRXSXTY+Y,Y-Y.Y/Y/", 56L, 28L);
Zmfy8_9(Z370, (STRING)"Y2Y0Y1Y3Y7Y5Y6Y/Y0Y7Y8Y3Y5Y8Y9Y9Y:Y:Y;Y;Y<Y<Y=Y3Y4Y=Y>Y>", 56L, 28L);
Zmfy8_9(Z370, (STRING)"Y?Y@YEYAYBYBYCYCYDYEYFYFYGYHYJYJYKYKYLYLYMYOYPYNYSYPYQYQ", 56L, 28L);
Zmfy8_9(Z370, (STRING)"YRY@YAYNYOYSYTZ5ZNZ9Z:Z<Z=ZCZTZLZMZOZNZPZQZRZS++YHYI+++", 55L, 30L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++Z5Z7Z5Z6++++++++++++++++++++++++++++++++", 55L, 51L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"+++++++++++++++++++++++++++++++++++++++++++++++++++++++", 55L, 55L);
Zmfy8_9(Z370, (STRING)"++++++++++++++++++++++++++++++++++++++", 38L, 38L);
}

static void Z308
# ifdef HAVE_ARGS
(SHORTCARD Z373)
# else
(Z373)
SHORTCARD Z373;
# endif
{
ZmtLFGGBG_3((ZDz6VQCC_4)ZfM_2, Zpky9FDA_5.Y0);
switch (Z373) {
case 0:;
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)": Scanner: internal error", 25L);
break;
case 1:;
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)": Scanner: out of memory", 24L);
break;
case 3:;
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)": Scanner: too many nested include files", 40L);
break;
case 4:;
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)": Scanner: file stack underflow (too many calls of CloseFile)", 61L);
break;
case 5:;
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)": Scanner: cannot open input file", 33L);
break;
case 6:;
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)": Scanner: start stack underflow (too many calls of yyPop)", 58L);
break;
}
ZfM_33((ZDz6VQCC_4)ZfM_2);
(*Zpky9FDA_6)();
}

static void Z379
 ARGS ((void))
{
ZfM_34();
rExit(1L);
}

void BEGIN_Scanner ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Strings ();
BEGIN_StringM ();
BEGIN_Idents ();
BEGIN_Tokens ();
BEGIN_Position ();
BEGIN_Checks ();
BEGIN_rSystem ();
BEGIN_General ();
BEGIN_Pack ();
BEGIN_Position ();
BEGIN_IO ();
BEGIN_DynArray ();
BEGIN_Strings ();
BEGIN_Source ();
BEGIN_Strings ();
BEGIN_StringM ();
BEGIN_Idents ();
BEGIN_Errors ();
BEGIN_Tokens ();

Zpky9FDA_6 = Z379;
Z275 = TRUE;
Z287 = 0;
Z333();
Z276 = ZDz6VQCC_1;
Z272 = Z250;
Z273 = Z250;
Z271 = Z240;
ZarQdhNDD_0((ADDRESS *)&Z270, &Z271, (LONGINT)sizeof (Z256));
Z270->A[0] = Z248;
Z300 = Z299;
ZarQdhNDD_0((ADDRESS *)&Z301, &Z300, (LONGINT)sizeof (Z256));
Z302 = 0;
Z369();
{
CHAR B_11 = Z241, B_12 = Z242;

if (B_11 <= B_12)
for (Z274 = B_11;; Z274 += 1) {
Z268.A[Z274] = Z274;
if (Z274 >= B_12) break;
}
}
Z269 = Z268;
for (Z274 = 'A'; Z274 <= 'Z'; Z274 += 1) {
Z268.A[Z274] = CHR(ORD(Z274) - ORD('A') + ORD('a'));
}
for (Z274 = 'a'; Z274 <= 'z'; Z274 += 1) {
Z269.A[Z274] = CHR(ORD(Z274) - ORD('a') + ORD('A'));
}
}
