#include "SYSTEM_.h"

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_UniqueId
#include "UniqueId.h"
#endif


#define Z135	1048576
#define Z136	4
#define Z137	100
static struct S_1 {
Zfb3DLQ_0 A[Z137 - 1 + 1];
} Z138;
static ZpmCQ_4 Z139, Z140;
static LONGINT Z141, Z142;
static struct S_2 {
ZpmCQ_4 A[Z135 + 1];
} *Z143;
static LONGINT Z144;
static CARDINAL Z145;
static void Z165 ARGS ((CHAR Z166[], LONGCARD O_1));

BOOLEAN ZrxADPDcb_6
# ifdef HAVE_ARGS
(ZrxADPDcb_0 Z117, ZrxADPDcb_1 Z148, Zfb3DLQ_0 Z150)
# else
(Z117, Z148, Z150)
ZrxADPDcb_0 Z117;
ZrxADPDcb_1 Z148;
Zfb3DLQ_0 Z150;
# endif
{
if (Z150 > Z145) {
ZblNKKO_43((STRING)"UniqueIds.NameConflict", 22L);
}
switch (Z148) {
case ZrxADPDcb_14:;
return ZpmCQ_25((LONGCARD)Z150, &Z140);
break;
case ZrxADPDcb_9:;
case ZrxADPDcb_10:;
return ZpmCQ_25((LONGCARD)Z150, &Z139);
break;
case ZrxADPDcb_13:;
return ZpmCQ_25((LONGCARD)Z150, &Z140) || ZpmCQ_25((LONGCARD)Z150, &Z143->A[0]);
break;
case ZrxADPDcb_11:;
return ZpmCQ_25((LONGCARD)Z150, &Z140) || ZpmCQ_25((LONGCARD)Z150, &Z143->A[Z141]);
break;
case ZrxADPDcb_12:;
return ZpmCQ_25((LONGCARD)Z150, &Z140) || ZpmCQ_25((LONGCARD)Z150, &Z143->A[Z141]) || ZpmCQ_25((LONGCARD)Z150, &Z143->A[0]);
break;
case ZrxADPDcb_8:;
return TRUE;
break;
}
}

ZrxADPDcb_0 ZrxADPDcb_5
# ifdef HAVE_ARGS
(ZrxADPDcb_0 Z117, ZrxADPDcb_1 Z148, Zfb3DLQ_0 Z150)
# else
(Z117, Z148, Z150)
ZrxADPDcb_0 Z117;
ZrxADPDcb_1 Z148;
Zfb3DLQ_0 Z150;
# endif
{
if (Z150 > Z145) {
ZblNKKO_43((STRING)"UniqueIds.DeclareIdent", 22L);
}
ZpmCQ_13(&Z139, (LONGCARD)Z150);
switch (Z148) {
case ZrxADPDcb_8:;
case ZrxADPDcb_9:;
case ZrxADPDcb_10:;
ZpmCQ_13(&Z140, (LONGCARD)Z150);
break;
case ZrxADPDcb_13:;
ZpmCQ_13(&Z143->A[0], (LONGCARD)Z150);
break;
case ZrxADPDcb_11:;
ZpmCQ_13(&Z143->A[Z141], (LONGCARD)Z150);
break;
case ZrxADPDcb_12:;
ZpmCQ_13(&Z143->A[Z141], (LONGCARD)Z150);
ZpmCQ_13(&Z143->A[0], (LONGCARD)Z150);
break;
default:
break;
}
return Z117;
}

void ZrxADPDcb_2
 ARGS ((void))
{
LONGINT Z160;
ZrxADPDcb_0 Z117;

Z145 = Zfb3DLQ_6();
ZpmCQ_5(&Z139, Z145);
ZpmCQ_5(&Z140, Z145);
Z141 = 0;
Z142 = Z136;
ZarQdhNDD_0((ADDRESS *)&Z143, &Z142, (LONGINT)sizeof (ZpmCQ_4));
{
LONGINT B_1 = 0, B_2 = Z142 - 1;

if (B_1 <= B_2)
for (Z160 = B_1;; Z160 += 1) {
ZpmCQ_5(&Z143->A[Z160], Z145);
if (Z160 >= B_2) break;
}
}
{
LONGINT B_3 = 1, B_4 = Z144;

if (B_3 <= B_4)
for (Z160 = B_3;; Z160 += 1) {
Z117 = ZrxADPDcb_5(Z117, ZrxADPDcb_8, Z138.A[Z160 - 1]);
if (Z160 >= B_4) break;
}
}
}

void ZrxADPDcb_7
 ARGS ((void))
{
LONGINT Z160;

ZpmCQ_7(&Z139);
ZpmCQ_7(&Z140);
{
LONGINT B_5 = 0, B_6 = Z142 - 1;

if (B_5 <= B_6)
for (Z160 = B_5;; Z160 += 1) {
ZpmCQ_7(&Z143->A[Z160]);
if (Z160 >= B_6) break;
}
}
ZarQdhNDD_3((ADDRESS *)&Z143, &Z142, (LONGINT)sizeof (ZpmCQ_4));
}

ZrxADPDcb_0 ZrxADPDcb_3
# ifdef HAVE_ARGS
(ZrxADPDcb_0 Z117)
# else
(Z117)
ZrxADPDcb_0 Z117;
# endif
{
LONGINT Z163, Z160;

INC(Z141);
if (Z141 >= Z142) {
Z163 = Z142;
ZarQdhNDD_2((ADDRESS *)&Z143, &Z142, (LONGINT)sizeof (ZpmCQ_4));
{
LONGINT B_7 = Z163, B_8 = Z142 - 1;

if (B_7 <= B_8)
for (Z160 = B_7;; Z160 += 1) {
ZpmCQ_5(&Z143->A[Z160], Z145);
if (Z160 >= B_8) break;
}
}
}
ZpmCQ_32(&Z143->A[Z141]);
return Z117;
}

ZrxADPDcb_0 ZrxADPDcb_4
# ifdef HAVE_ARGS
(ZrxADPDcb_0 Z117)
# else
(Z117)
ZrxADPDcb_0 Z117;
# endif
{
DEC(Z141);
return Z117;
}

static void Z165
# ifdef HAVE_ARGS
(CHAR Z166[], LONGCARD O_1)
# else
(Z166, O_1)
CHAR Z166[];
LONGCARD O_1;
# endif
{
Zp1PEAFD_2 Z167;
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z166, O_1, CHAR)
INC(Z144);
if (Z144 > Z137) {
ZblNKKO_43((STRING)"UniqueIds.DefineKeyword", 23L);
}
Zp1PEAFD_13(Z166, O_1, &Z167);
Z138.A[Z144 - 1] = Zfb3DLQ_2(&Z167);
FREE_OPEN_ARRAYS
}

void BEGIN_UniqueId ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_Errors ();
BEGIN_Idents ();
BEGIN_Strings ();
BEGIN_Sets ();
BEGIN_DynArray ();

Z144 = 0;
Z165((STRING)"auto", 4L);
Z165((STRING)"break", 5L);
Z165((STRING)"case", 4L);
Z165((STRING)"char", 4L);
Z165((STRING)"continue", 8L);
Z165((STRING)"default", 7L);
Z165((STRING)"define", 6L);
Z165((STRING)"do", 2L);
Z165((STRING)"double", 6L);
Z165((STRING)"else", 4L);
Z165((STRING)"endif", 5L);
Z165((STRING)"entry", 5L);
Z165((STRING)"enum", 4L);
Z165((STRING)"extern", 6L);
Z165((STRING)"float", 5L);
Z165((STRING)"for", 3L);
Z165((STRING)"goto", 4L);
Z165((STRING)"if", 2L);
Z165((STRING)"ifdef", 5L);
Z165((STRING)"ifndef", 6L);
Z165((STRING)"include", 7L);
Z165((STRING)"int", 3L);
Z165((STRING)"line", 4L);
Z165((STRING)"long", 4L);
Z165((STRING)"register", 8L);
Z165((STRING)"return", 6L);
Z165((STRING)"short", 5L);
Z165((STRING)"signed", 6L);
Z165((STRING)"sizeof", 6L);
Z165((STRING)"static", 6L);
Z165((STRING)"struct", 6L);
Z165((STRING)"switch", 6L);
Z165((STRING)"typedef", 7L);
Z165((STRING)"undef", 5L);
Z165((STRING)"union", 5L);
Z165((STRING)"unsigned", 8L);
Z165((STRING)"void", 4L);
Z165((STRING)"while", 5L);
Z165((STRING)"TRUE", 4L);
Z165((STRING)"FALSE", 5L);
Z165((STRING)"NIL", 3L);
Z165((STRING)"SHORTINT", 8L);
Z165((STRING)"INTEGER", 7L);
Z165((STRING)"LONGINT", 7L);
Z165((STRING)"SHORTCARD", 9L);
Z165((STRING)"CARDINAL", 8L);
Z165((STRING)"LONGCARD", 8L);
Z165((STRING)"BOOLEAN", 7L);
Z165((STRING)"CHAR", 4L);
Z165((STRING)"REAL", 4L);
Z165((STRING)"LONGREAL", 8L);
Z165((STRING)"BITSET", 6L);
Z165((STRING)"PROC", 4L);
Z165((STRING)"BYTE", 4L);
Z165((STRING)"WORD", 4L);
Z165((STRING)"SHORTWORD", 9L);
Z165((STRING)"ADDRESS", 7L);
Z165((STRING)"ABS", 3L);
Z165((STRING)"ABSSI", 5L);
Z165((STRING)"ABSLI", 5L);
Z165((STRING)"ABSSC", 5L);
Z165((STRING)"ABSLC", 5L);
Z165((STRING)"ABSR", 4L);
Z165((STRING)"ABSLR", 5L);
Z165((STRING)"CAP", 3L);
Z165((STRING)"CHR", 3L);
Z165((STRING)"FLOAT", 5L);
Z165((STRING)"ORD", 3L);
Z165((STRING)"TRUNC", 5L);
Z165((STRING)"VAL", 3L);
Z165((STRING)"ODD", 3L);
Z165((STRING)"INC", 3L);
Z165((STRING)"INC1", 4L);
Z165((STRING)"DEC", 3L);
Z165((STRING)"DEC1", 4L);
Z165((STRING)"EXCL", 4L);
Z165((STRING)"INCL", 4L);
Z165((STRING)"ADR", 3L);
Z165((STRING)"ADR1", 4L);
Z165((STRING)"OPAQUE", 6L);
Z165((STRING)"STRING", 6L);
Z165((STRING)"CaseError", 9L);
Z165((STRING)"ReturnError", 11L);
Z165((STRING)"alloca", 6L);
Z165((STRING)"malloc", 6L);
Z165((STRING)"free", 4L);
Z165((STRING)"memcpy", 6L);
Z165((STRING)"strncpy", 7L);
Z165((STRING)"exit", 4L);
Z165((STRING)"StackAlloc", 10L);
Z165((STRING)"A", 1L);
Z165((STRING)"dummy", 5L);
Z165((STRING)"frame", 5L);
Z165((STRING)"link", 4L);
}
