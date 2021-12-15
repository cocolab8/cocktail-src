#include "SYSTEM_.h"

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
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

#ifndef DEFINITION_Base
#include "Base.h"
#endif

struct Base_1 ZfXEB_0;
Zp1PEAFD_2 ZfXEB_1;

#define Z148	65535
#define Z149	4
static LONGINT Z150, Z151;
static struct S_1 {
Zp1PEAFD_2 A[Z148 + 1];
} *Z152;
static ZpmCQ_4 Z153;
struct S_9 {
CHAR A[127 + 1];
};
static void Z160 ARGS ((CHAR Z166[], LONGCARD O_1));
struct S_1_CheckDefFile;
static void Z172 ARGS ((CHAR Z169[], LONGCARD O_3, BOOLEAN *Z170));
static void Z174 ARGS ((struct S_1_CheckDefFile *link, Zp1PEAFD_2 *Z171, CHAR Z169[], LONGCARD O_4, BOOLEAN *Z170));
struct S_1_CheckDefFile {
Zfb3DLQ_0 *Z168;
};
struct S_4 {
CHAR A[127 + 1];
};
struct S_3 {
CHAR A[127 + 1];
};
static void Z163 ARGS ((ZfM_3 Z173, CHAR Z169[], LONGCARD O_5));

void ZfXEB_2
 ARGS ((void))
{
CARDINAL Z155, Z156;
struct S_9 Z157;
CHAR Z158;
ZfM_3 Z159;

{
LONGCARD B_1 = 1, B_2 = GetArgCount() - 1;

if (B_1 <= B_2)
for (Z155 = B_1;; Z155 += 1) {
GetArgument((LONGINT)Z155, Z157.A, 128L);
if (Z157.A[0] == '-') {
if (Z157.A[1] == 'd') {
Z156 = 2;
for (;;) {
Z158 = Z157.A[Z156];
Z157.A[Z156 - 2] = Z158;
if (Z158 == '\0') {
goto EXIT_1;
}
INC(Z156);
} EXIT_1:;
Z160(Z157.A, 128L);
} else if (Z157.A[1] == 'o') {
Z156 = 2;
for (;;) {
Z158 = Z157.A[Z156];
if (Z158 == '\0') {
goto EXIT_2;
}
Zp1PEAFD_6(&ZfXEB_1, Z158);
INC(Z156);
} EXIT_2:;
Zp1PEAFD_6(&ZfXEB_1, '/');
} else {
Z156 = 0;
for (;;) {
INC(Z156);
Z158 = Z157.A[Z156];
switch (Z158) {
case '\0':;
goto EXIT_3;
break;
case 'c':;
case 'f':;
case 'D':;
case 'P':;
case 'h':;
case 'i':;
case 'm':;
case 'r':;
case 't':;
case 'w':;
case 'u':;
ZpmCQ_13(&Z153, ORD(Z158));
break;
default:
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"mtc: illegal option '", 21L);
ZfM_24((ZDz6VQCC_4)ZfM_2, Z158);
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"'", 1L);
ZfM_33((ZDz6VQCC_4)ZfM_2);
ZfM_34();
rExit(1L);
break;
}
} EXIT_3:;
}
} else {
Z156 = 0;
do {
Z158 = Z157.A[Z156];
ZfXEB_0.A[Z156] = Z158;
INC(Z156);
} while (!(Z158 == '\0'));
Z159 = ZfM_4(ZfXEB_0.A, 128L);
Z163(Z159, ZfXEB_0.A, 128L);
ZfM_5(Z159);
}
if (Z155 >= B_2) break;
}
}
}

BOOLEAN ZfXEB_3
# ifdef HAVE_ARGS
(CHAR Z165)
# else
(Z165)
CHAR Z165;
# endif
{
return ZpmCQ_25(ORD(Z165), &Z153);
}

static void Z160
# ifdef HAVE_ARGS
(CHAR Z166[], LONGCARD O_1)
# else
(Z166, O_1)
CHAR Z166[];
LONGCARD O_1;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z166, O_1, CHAR)
if (Z150 >= Z151) {
ZarQdhNDD_2((ADDRESS *)&Z152, &Z151, (LONGINT)sizeof (Zp1PEAFD_2));
}
Zp1PEAFD_13(Z166, O_1, &Z152->A[Z150]);
Zp1PEAFD_6(&Z152->A[Z150], '/');
INC(Z150);
FREE_OPEN_ARRAYS
}

static void Z172
# ifdef HAVE_ARGS
(CHAR Z169[], LONGCARD O_3, BOOLEAN *Z170)
# else
(Z169, O_3, Z170)
CHAR Z169[];
LONGCARD O_3;
BOOLEAN *Z170;
# endif
{
ZfM_3 Z173;
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_3 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z169, O_3, CHAR)
Z173 = ZfM_4(Z169, O_3);
if (Z173 < 0) {
*Z170 = FALSE;
} else {
*Z170 = TRUE;
ZfM_5(Z173);
}
FREE_OPEN_ARRAYS
}

static void Z174
# ifdef HAVE_ARGS
(struct S_1_CheckDefFile *link, Zp1PEAFD_2 *Z171, CHAR Z169[], LONGCARD O_4, BOOLEAN *Z170)
# else
(link, Z171, Z169, O_4, Z170)
struct S_1_CheckDefFile *link;
Zp1PEAFD_2 *Z171;
CHAR Z169[];
LONGCARD O_4;
BOOLEAN *Z170;
# endif
{
Zp1PEAFD_2 Z175, Z176;
LONGINT Z177;

Zfb3DLQ_3(*link->Z168, &Z175);
Zp1PEAFD_5(&Z175, Z171);
Zp1PEAFD_6(&Z175, '\0');
Zp1PEAFD_14(&Z175, Z169, O_4);
Z172(Z169, O_4, Z170);
if (*Z170) {
return;
}
Z177 = 0;
while (!*Z170 && Z177 < Z150) {
Zp1PEAFD_3(&Z176, &Z152->A[Z177]);
Zp1PEAFD_5(&Z176, &Z175);
Zp1PEAFD_14(&Z176, Z169, O_4);
Z172(Z169, O_4, Z170);
INC(Z177);
}
}

void ZfXEB_4
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z168, CHAR Z169[], LONGCARD O_2, BOOLEAN *Z170)
# else
(Z168, Z169, O_2, Z170)
Zfb3DLQ_0 Z168;
CHAR Z169[];
LONGCARD O_2;
BOOLEAN *Z170;
# endif
{
Zp1PEAFD_2 Z171;
struct S_1_CheckDefFile frame;

frame.Z168 = &Z168;
Zp1PEAFD_13((STRING)".md", 3L, &Z171);
Z174(&frame, &Z171, Z169, O_2, Z170);
if (*Z170) {
return;
}
Zp1PEAFD_13((STRING)".MD", 3L, &Z171);
Z174(&frame, &Z171, Z169, O_2, Z170);
if (*Z170) {
return;
}
Zp1PEAFD_13((STRING)".def", 4L, &Z171);
Z174(&frame, &Z171, Z169, O_2, Z170);
if (*Z170) {
return;
}
Zp1PEAFD_13((STRING)".DEF", 4L, &Z171);
Z174(&frame, &Z171, Z169, O_2, Z170);
if (*Z170) {
return;
}
}

ZfM_3 ZfXEB_5
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z179)
# else
(Z179)
Zfb3DLQ_0 Z179;
# endif
{
struct S_4 Z169;
ZfM_3 Z173;
Zp1PEAFD_2 Z180, Z181;

Zfb3DLQ_3(Z179, &Z181);
Zp1PEAFD_3(&Z180, &ZfXEB_1);
Zp1PEAFD_5(&Z180, &Z181);
Zp1PEAFD_6(&Z180, '.');
Zp1PEAFD_6(&Z180, 'h');
Zp1PEAFD_6(&Z180, '\0');
Zp1PEAFD_14(&Z180, Z169.A, 128L);
Z173 = ZfM_20(Z169.A, 128L);
Z163(Z173, Z169.A, 128L);
return Z173;
}

ZfM_3 ZfXEB_6
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z179)
# else
(Z179)
Zfb3DLQ_0 Z179;
# endif
{
struct S_3 Z169;
ZfM_3 Z173;
Zp1PEAFD_2 Z180, Z181;

Zfb3DLQ_3(Z179, &Z181);
Zp1PEAFD_3(&Z180, &ZfXEB_1);
Zp1PEAFD_5(&Z180, &Z181);
Zp1PEAFD_6(&Z180, '.');
Zp1PEAFD_6(&Z180, 'c');
Zp1PEAFD_6(&Z180, '\0');
Zp1PEAFD_14(&Z180, Z169.A, 128L);
Z173 = ZfM_20(Z169.A, 128L);
Z163(Z173, Z169.A, 128L);
return Z173;
}

static void Z163
# ifdef HAVE_ARGS
(ZfM_3 Z173, CHAR Z169[], LONGCARD O_5)
# else
(Z173, Z169, O_5)
ZfM_3 Z173;
CHAR Z169[];
LONGCARD O_5;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_5 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z169, O_5, CHAR)
if (Z173 < 0) {
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"mtc: cannot open file ", 22L);
ZfM_29((ZDz6VQCC_4)ZfM_2, Z169, O_5);
ZfM_33((ZDz6VQCC_4)ZfM_2);
ZfM_34();
rExit(1L);
}
FREE_OPEN_ARRAYS
}

void BEGIN_Base ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_Idents ();
BEGIN_Strings ();
BEGIN_rSystem ();
BEGIN_IO ();
BEGIN_DynArray ();
BEGIN_Idents ();
BEGIN_Strings ();
BEGIN_Sets ();

ZpmCQ_5(&Z153, ORD(MAX_CHAR));
Z150 = 0;
Z151 = Z149;
ZarQdhNDD_0((ADDRESS *)&Z152, &Z151, (LONGINT)sizeof (Zp1PEAFD_2));
}
