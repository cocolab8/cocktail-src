#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Listing
#include "Listing.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_StringM
#include "StringM.h"
#endif

#ifndef DEFINITION_SysError
#include "SysError.h"
#endif

#ifndef DEFINITION_rSystem
#include "rSystem.h"
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

BOOLEAN ZblNKKO_71;
BOOLEAN ZblNKKO_72;
ZblNKKO_69 ZblNKKO_73;
ZblNKKO_70 ZblNKKO_74;
BITSET ZblNKKO_75;
struct Errors_1 ZblNKKO_76;

#define Z156	'\t'
#define Z157	-1
#define Z158	'\\'
#define Z159	'$'
static ZblNKKO_68 Z160;
static struct S_1 {
SHORTCARD A[ZblNKKO_52 + 1];
} Z162;
static struct S_2 {
Zp1PEAFi_1 A[ZblNKKO_52 + 1];
} Z164;
static struct S_3 {
Zp1PEAFi_1 A[ZblNKKO_67 + 1];
} Z165;
static struct S_4 {
Zp1PEAFi_1 A[ZblNKKO_52 + 1];
} Z167;
static INTEGER Z168;
static void Z181 ARGS ((INTEGER Z170, INTEGER Z171, INTEGER Z182, INTEGER Z183, INTEGER Z174, ADDRESS Z175));
static void Z194 ARGS ((Zp1PEAFD_2 Y1_73, INTEGER *Z168, Zp1PEAFD_2 *Z207));
static void Z185 ARGS ((void));

void ZblNKKO_77
# ifdef HAVE_ARGS
(CARDINAL Z170, CARDINAL Z171, ZmtLFGGBG_0 Z153)
# else
(Z170, Z171, Z153)
CARDINAL Z170, Z171;
ZmtLFGGBG_0 Z153;
# endif
{
ZblNKKO_78(Z170, Z171, Z153, (LONGCARD)ZblNKKO_33, (ADDRESS)NIL);
}

void ZblNKKO_78
# ifdef HAVE_ARGS
(CARDINAL Z170, CARDINAL Z171, ZmtLFGGBG_0 Z153, CARDINAL Z174, ADDRESS Z175)
# else
(Z170, Z171, Z153, Z174, Z175)
CARDINAL Z170, Z171;
ZmtLFGGBG_0 Z153;
CARDINAL Z174;
ADDRESS Z175;
# endif
{
INC(Z162.A[Z171]);
if (Z171 <= ZblNKKO_47) {
ZblNKKO_72 = TRUE;
}
if (IN(Z171, ZblNKKO_75)) {
ZblNKKO_71 = FALSE;
if (Z160 == ZblNKKO_83) {
Z181((LONGINT)Z170, (LONGINT)Z171, (LONGINT)Z153.Y0, (LONGINT)Z153.Y1, (LONGINT)Z174, Z175);
ZfM_33((ZDz6VQCC_4)ZfM_2);
} else {
Z175 = (*ZblNKKO_73)((LONGINT)Z174, Z175);
ZijFQGAF_3((LONGINT)Z170, (LONGINT)Z171, (LONGINT)Z153.Y0, (LONGINT)Z153.Y1, (LONGINT)Z174, Z175);
}
}
if (Z171 < 3) {
Z185();
}
}

void ZblNKKO_80
# ifdef HAVE_ARGS
(ZblNKKO_68 Z187)
# else
(Z187)
ZblNKKO_68 Z187;
# endif
{
Z160 = Z187;
ZijFQGAF_2 = Z187 == ZblNKKO_85;
}

void ZblNKKO_79
 ARGS ((void))
{
INTEGER Z168;
ZfM_3 Z190;
Zp1PEAFD_2 Z191;
Zp1PEAFD_2 Y2_73;

Z190 = ZfM_4(ZblNKKO_76.A, 256L);
if (Zp6VmlNKK_0(Z190)) {
Zp1PEAFD_13(ZblNKKO_76.A, 256L, &Z191);
Zp6VmlNKK_1(Z190, (LONGCARD)ZblNKKO_47, (LONGCARD)ZblNKKO_40, ADR (Z191));
return;
}
for (;;) {
if (ZfM_19(Z190)) {
goto EXIT_1;
}
Zp1PEAFD_20(Z190, &Y2_73);
if (Zp1PEAFD_12(&Y2_73, 1) == '$') {
goto EXIT_1;
}
if (Zp1PEAFD_12(&Y2_73, 1) != '%') {
Z194(Y2_73, &Z168, &Z191);
if (Z168 < 0 || Z168 > ZblNKKO_52) {
ZblNKKO_78((LONGCARD)ZblNKKO_62, (LONGCARD)ZblNKKO_47, ZmtLFGGBG_1, (LONGCARD)ZblNKKO_40, ADR (Y2_73));
} else {
Z164.A[Z168] = Zp1PEAFi_2(&Z191);
}
}
} EXIT_1:;
for (;;) {
if (ZfM_19(Z190)) {
goto EXIT_2;
}
Zp1PEAFD_20(Z190, &Y2_73);
if (Zp1PEAFD_12(&Y2_73, 1) == '$') {
goto EXIT_2;
}
if (Zp1PEAFD_12(&Y2_73, 1) != '%') {
Z194(Y2_73, &Z168, &Z191);
if (Z168 < 0 || Z168 > ZblNKKO_67) {
ZblNKKO_78((LONGCARD)ZblNKKO_63, (LONGCARD)ZblNKKO_47, ZmtLFGGBG_1, (LONGCARD)ZblNKKO_40, ADR (Y2_73));
} else {
Z165.A[Z168] = Zp1PEAFi_2(&Z191);
}
}
} EXIT_2:;
for (;;) {
if (ZfM_19(Z190)) {
goto EXIT_3;
}
Zp1PEAFD_20(Z190, &Y2_73);
if (Zp1PEAFD_12(&Y2_73, 1) == '$') {
goto EXIT_3;
}
if (Zp1PEAFD_12(&Y2_73, 1) != '%') {
Z194(Y2_73, &Z168, &Z191);
if (Z168 < 0 || Z168 > ZblNKKO_52) {
ZblNKKO_78((LONGCARD)ZblNKKO_62, (LONGCARD)ZblNKKO_47, ZmtLFGGBG_1, (LONGCARD)ZblNKKO_40, ADR (Y2_73));
} else {
Z167.A[Z168] = Zp1PEAFi_2(&Z191);
}
}
} EXIT_3:;
ZfM_5(Z190);
}

void ZblNKKO_81
 ARGS ((void))
{
INTEGER Z168;
Zp1PEAFi_1 Z198;
INTEGER Z170, Z171, Z182, Z183, Z174;
ADDRESS Z175;

if (ZblNKKO_71) {
return;
}
while (ZijFQGAF_4()) {
ZijFQGAF_5(&Z170, &Z171, &Z182, &Z183, &Z174, &Z175);
Z181(Z170, Z171, Z182, Z183, Z174, Z175);
ZfM_33((ZDz6VQCC_4)ZfM_2);
}
for (Z168 = 0; Z168 <= ZblNKKO_52; Z168 += 1) {
if (Z162.A[Z168] > 0) {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"  ", 2L);
ZfM_25((ZDz6VQCC_4)ZfM_2, (LONGINT)Z162.A[Z168], 1L);
ZfM_24((ZDz6VQCC_4)ZfM_2, ' ');
Z198 = Z167.A[Z168];
if (Z198 == Z157) {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"in error class ", 15L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z168, 1L);
} else {
Zp1PEAFi_6((ZDz6VQCC_4)ZfM_2, Z198);
}
}
}
ZfM_33((ZDz6VQCC_4)ZfM_2);
}

void ZblNKKO_82
# ifdef HAVE_ARGS
(CHAR Z200[], LONGCARD O_1)
# else
(Z200, O_1)
CHAR Z200[];
LONGCARD O_1;
# endif
{
Zp1PEAFD_2 Z191;
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z200, O_1, CHAR)
Zp1PEAFD_13(Z200, O_1, &Z191);
ZblNKKO_78((LONGCARD)ZblNKKO_61, (LONGCARD)ZblNKKO_45, ZmtLFGGBG_1, (LONGCARD)ZblNKKO_40, ADR (Z191));
FREE_OPEN_ARRAYS
}

static void Z181
# ifdef HAVE_ARGS
(INTEGER Z170, INTEGER Z171, INTEGER Z182, INTEGER Z183, INTEGER Z174, ADDRESS Z175)
# else
(Z170, Z171, Z182, Z183, Z174, Z175)
INTEGER Z170;
INTEGER Z171;
INTEGER Z182;
INTEGER Z183;
INTEGER Z174;
ADDRESS Z175;
# endif
{
Zp1PEAFi_1 Z198;
Zp1PEAFD_2 Z191;
INTEGER Z168, Z203;
CHAR Z200;
BOOLEAN Z204;

if (Z160 != ZblNKKO_85 && Z182 != 0) {
ZfM_25((ZDz6VQCC_4)ZfM_2, Z182, 3L);
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)", ", 2L);
}
if (Z183 != 0) {
ZfM_25((ZDz6VQCC_4)ZfM_2, Z183, 2L);
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)": ", 2L);
}
if (Z171 > ZblNKKO_52 || Z171 < 0) {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"Error class: ", 13L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z171, 1L);
} else {
Z198 = Z164.A[Z171];
if (Z198 == Z157) {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"Error class: ", 13L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z171, 1L);
} else {
Zp1PEAFi_6((ZDz6VQCC_4)ZfM_2, Z198);
}
}
if (Z170 > ZblNKKO_67 || Z170 < 0) {
if (Z170 >= ZblNKKO_66) {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)" system error code: ", 20L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z170 - ZblNKKO_66, 1L);
} else {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)" error code: ", 13L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z170, 1L);
}
ZfM_24((ZDz6VQCC_4)ZfM_2, ' ');
(*ZblNKKO_74)(Z174, Z175);
} else {
Z198 = Z165.A[Z170];
if (Z198 == Z157) {
if (Z170 >= ZblNKKO_66) {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)" system error code: ", 20L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z170 - ZblNKKO_66, 1L);
} else {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)" error code: ", 13L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z170, 1L);
}
ZfM_24((ZDz6VQCC_4)ZfM_2, ' ');
(*ZblNKKO_74)(Z174, Z175);
} else {
Zp1PEAFi_3(Z198, &Z191);
Z203 = Zp1PEAFD_7(&Z191);
Z168 = 0;
Z204 = FALSE;
for (;;) {
INC(Z168);
if (Z168 > Z203) {
goto EXIT_4;
}
Z200 = Zp1PEAFD_12(&Z191, (Zp1PEAFD_1)Z168);
if (Z204) {
ZfM_24((ZDz6VQCC_4)ZfM_2, Z200);
Z204 = FALSE;
} else if (Z200 == Z158) {
Z204 = TRUE;
} else if (Z200 == Z159) {
goto EXIT_4;
} else {
ZfM_24((ZDz6VQCC_4)ZfM_2, Z200);
}
} EXIT_4:;
(*ZblNKKO_74)(Z174, Z175);
for (;;) {
INC(Z168);
if (Z168 > Z203) {
goto EXIT_5;
}
Z200 = Zp1PEAFD_12(&Z191, (Zp1PEAFD_1)Z168);
if (Z204) {
ZfM_24((ZDz6VQCC_4)ZfM_2, Z200);
Z204 = FALSE;
} else if (Z200 == Z158) {
Z204 = TRUE;
} else {
ZfM_24((ZDz6VQCC_4)ZfM_2, Z200);
}
} EXIT_5:;
}
}
}

static void Z194
# ifdef HAVE_ARGS
(Zp1PEAFD_2 Y1_73, INTEGER *Z168, Zp1PEAFD_2 *Z207)
# else
(Y1_73, Z168, Z207)
Zp1PEAFD_2 Y1_73;
INTEGER *Z168;
Zp1PEAFD_2 *Z207;
# endif
{
INTEGER Z208, Z209, Z210;
Zp1PEAFD_2 Z191;

Z209 = 1;
Z210 = 1;
Z208 = Zp1PEAFD_7(&Y1_73);
for (;;) {
if (Z210 > Z208) {
goto EXIT_6;
}
if (Zp1PEAFD_12(&Y1_73, (Zp1PEAFD_1)Z210) == Z156) {
goto EXIT_6;
}
INC(Z210);
} EXIT_6:;
DEC(Z210);
if (Z209 > Z210) {
*Z168 = 0;
} else {
Zp1PEAFD_11(&Y1_73, (Zp1PEAFD_1)Z209, (Zp1PEAFD_1)Z210, &Z191);
*Z168 = Zp1PEAFD_15(&Z191);
}
Z209 = Z210 + 1;
for (;;) {
if (Z209 > Z208) {
goto EXIT_7;
}
if (Zp1PEAFD_12(&Y1_73, (Zp1PEAFD_1)Z209) != Z156) {
goto EXIT_7;
}
INC(Z209);
} EXIT_7:;
Z210 = Z209;
for (;;) {
if (Z210 > Z208) {
goto EXIT_8;
}
if (Zp1PEAFD_12(&Y1_73, (Zp1PEAFD_1)Z210) == Z156) {
goto EXIT_8;
}
INC(Z210);
} EXIT_8:;
DEC(Z210);
if (Z209 > Z210) {
Zp1PEAFD_4(Z207);
} else {
Zp1PEAFD_11(&Y1_73, (Zp1PEAFD_1)Z209, (Zp1PEAFD_1)Z210, Z207);
}
}

static void Z185
 ARGS ((void))
{
ZblNKKO_81();
ZfM_34();
if (Z160 == ZblNKKO_83) {
switch (0) {
}
}
rExit(1L);
}

void BEGIN_Errors ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Position ();
BEGIN_IO ();
BEGIN_Listing ();
BEGIN_Strings ();
BEGIN_StringM ();
BEGIN_SysError ();
BEGIN_rSystem ();
BEGIN_Position ();
BEGIN_Strings ();

ZblNKKO_71 = TRUE;
ZblNKKO_72 = FALSE;
Z160 = ZblNKKO_84;
(void) strncpy ((char *)ZblNKKO_76.A, "ErrorTab", sizeof (ZblNKKO_76.A));
ZblNKKO_75 = SET_cRNG (0, ZblNKKO_52);
for (Z168 = 0; Z168 <= ZblNKKO_52; Z168 += 1) {
Z162.A[Z168] = 0;
}
for (Z168 = 0; Z168 <= ZblNKKO_52; Z168 += 1) {
Z164.A[Z168] = Z157;
}
for (Z168 = 0; Z168 <= ZblNKKO_67; Z168 += 1) {
Z165.A[Z168] = Z157;
}
for (Z168 = 0; Z168 <= ZblNKKO_52; Z168 += 1) {
Z167.A[Z168] = Z157;
}
}
