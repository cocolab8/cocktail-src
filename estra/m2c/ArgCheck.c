#include "SYSTEM_.h"

#ifndef DEFINITION_Characte
#include "Characte.h"
#endif

#ifndef DEFINITION_Checks
#include "Checks.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Listing
#include "Listing.h"
#endif

#ifndef DEFINITION_Path
#include "Path.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_SysError
#include "SysError.h"
#endif

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

CHAR ZehCfg728_0 [] = "8906";
BOOLEAN ZehCfg728_1;
BOOLEAN ZehCfg728_2;
BOOLEAN ZehCfg728_3;
BOOLEAN ZehCfg728_4;
struct ArgCheck_1 ZehCfg728_5;
BOOLEAN ZehCfg728_6;
BOOLEAN ZehCfg728_7;
BOOLEAN ZehCfg728_8;
BOOLEAN ZehCfg728_9;
BOOLEAN ZehCfg728_10;

struct S_1 {
CHAR A[255 + 1];
};

void ZehCfg728_11
 ARGS ((void))
{
struct S_1 Z167;
Zp1PEAFD_2 Z168;
CARDINAL Z169;
BOOLEAN Z170;
INTEGER Z171;
BOOLEAN Z172, Z173;
BOOLEAN Z174;
BOOLEAN Z175;

Z170 = FALSE;
Z172 = FALSE;
Z173 = FALSE;
Z174 = FALSE;
Z175 = TRUE;
{
LONGCARD B_1 = 1, B_2 = GetArgCount() - 1;

if (B_1 <= B_2)
for (Z169 = B_1;; Z169 += 1) {
GetArgument((LONGINT)Z169, Z167.A, 256L);
if (Z167.A[0] == '-') {
Z175 = FALSE;
{
LONGINT B_3 = 1, B_4 = Zgg3DDyAC_1(Z167.A, 256L) - 1;

if (B_3 <= B_4)
for (Z171 = B_3;; Z171 += 1) {
switch (Z167.A[Z171]) {
case 'W':;
EXCL(ZblNKKO_75, ZblNKKO_48);
break;
case 'R':;
EXCL(ZblNKKO_75, ZblNKKO_49);
break;
case 'N':;
EXCL(ZblNKKO_75, ZblNKKO_50);
break;
case 'I':;
EXCL(ZblNKKO_75, ZblNKKO_51);
break;
case 'M':;
ZblNKKO_80(ZblNKKO_85);
break;
case 'D':;
ZblNKKO_80(ZblNKKO_83);
break;
case 't':;
ZehCfg728_1 = TRUE;
break;
case 'b':;
ZehCfg728_4 = TRUE;
break;
case 'd':;
ZehCfg728_2 = TRUE;
break;
case 'i':;
ZehCfg728_3 = TRUE;
break;
case 'h':;
Z172 = TRUE;
break;
case '?':;
Z172 = TRUE;
Z173 = TRUE;
break;
case 'A':;
ZehCfg728_9 = TRUE;
break;
case 'C':;
ZehCfg728_10 = TRUE;
break;
case 'G':;
ZehCfg728_7 = TRUE;
break;
case 'T':;
ZehCfg728_6 = TRUE;
break;
case 'B':;
ZehCfg728_8 = TRUE;
break;
default:
ZblNKKO_78((LONGCARD)ZblNKKO_64, (LONGCARD)ZblNKKO_47, ZmtLFGGBG_1, (LONGCARD)ZblNKKO_39, ADR (Z167.A[Z171]));
Z174 = TRUE;
break;
}
if (Z171 >= B_4) break;
}
}
} else {
if (Z170) {
Zp1PEAFD_13(Z167.A, 256L, &Z168);
ZblNKKO_78((LONGCARD)ZblNKKO_65, (LONGCARD)ZblNKKO_47, ZmtLFGGBG_1, (LONGCARD)ZblNKKO_40, ADR (Z168));
Z174 = TRUE;
} else {
ZijFQGAF_0 = ZfM_4(Z167.A, 256L);
if (Zp6VmlNKK_0(ZijFQGAF_0)) {
Zgg728H_1(&ZijFQGAF_0, Z167.A, 256L);
} else {
Zpky9FDA_50(Z167.A, 256L);
Z170 = TRUE;
Zgg3DDyAC_6(ZehCfg728_5.A, 256L, Z167.A, 256L);
}
}
}
if (Z169 >= B_2) break;
}
}
if (Z175) {
ZehCfg728_2 = TRUE;
ZehCfg728_3 = TRUE;
}
if (Z174) {
ZblNKKO_81();
rExit(1L);
}
if (Z172) {
Zp1BbM_23((STRING)"usage:  estra [-options] [file]", 31L);
Zp1BbM_27();
Zp1BbM_27();
Zp1BbM_23((STRING)"file  specification to be compiled", 34L);
Zp1BbM_27();
Zp1BbM_23((STRING)"      if no file is specified stdin is used instead", 51L);
Zp1BbM_27();
Zp1BbM_27();
Zp1BbM_23((STRING)"options:", 8L);
Zp1BbM_27();
Zp1BbM_23((STRING)" d    generate definition module", 32L);
Zp1BbM_27();
Zp1BbM_23((STRING)" i    generate implementation module", 36L);
Zp1BbM_27();
Zp1BbM_23((STRING)" b    generate bottom-up pattern matcher", 40L);
Zp1BbM_27();
Zp1BbM_23((STRING)" h    print help information (this text)", 40L);
Zp1BbM_27();
Zp1BbM_23((STRING)" t    print test information", 28L);
Zp1BbM_27();
Zp1BbM_23((STRING)" D    report errors directly", 28L);
Zp1BbM_27();
Zp1BbM_23((STRING)" M    report errors as a mixed listing", 38L);
Zp1BbM_27();
Zp1BbM_23((STRING)" W    do not report warnings", 28L);
Zp1BbM_27();
Zp1BbM_23((STRING)" R    do not report repairs", 27L);
Zp1BbM_27();
Zp1BbM_23((STRING)" N    do not report notes", 25L);
Zp1BbM_27();
Zp1BbM_23((STRING)" I    do not report informations", 32L);
Zp1BbM_27();
Zp1BbM_27();
if (Z173) {
Zp1BbM_23((STRING)" private options for testing", 28L);
Zp1BbM_27();
Zp1BbM_23((STRING)" A    test output of bottom up automaton", 40L);
Zp1BbM_27();
Zp1BbM_23((STRING)" B    test output of bottom up automaton", 40L);
Zp1BbM_27();
Zp1BbM_23((STRING)" C    generate code for debugging", 33L);
Zp1BbM_27();
Zp1BbM_23((STRING)" G    test output of grammar", 28L);
Zp1BbM_27();
Zp1BbM_23((STRING)" T    test output of tree", 25L);
Zp1BbM_27();
Zp1BbM_27();
}
Zp1BbM_23((STRING)"the default options are -di", 27L);
Zp1BbM_27();
Zp1BbM_27();
rExit(0L);
}
}

void BEGIN_ArgCheck ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Characte ();
BEGIN_Checks ();
BEGIN_Errors ();
BEGIN_IO ();
BEGIN_Listing ();
BEGIN_Path ();
BEGIN_Scanner ();
BEGIN_Position ();
BEGIN_StdIO ();
BEGIN_Strings ();
BEGIN_SysError ();
BEGIN_rSystem ();

ZehCfg728_1 = FALSE;
ZehCfg728_2 = FALSE;
ZehCfg728_3 = FALSE;
(void) strncpy ((char *)ZehCfg728_5.A, " ", sizeof (ZehCfg728_5.A));
ZehCfg728_7 = FALSE;
ZehCfg728_6 = FALSE;
ZehCfg728_8 = FALSE;
ZehCfg728_9 = FALSE;
ZehCfg728_10 = FALSE;
}
