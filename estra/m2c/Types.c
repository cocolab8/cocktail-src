#include "SYSTEM_.h"

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_Types
#include "Types.h"
#endif


#define Z129	-1
static struct S_1 {
Zq7SFB_0 A[10000 + 1];
} *Z130;
static struct S_2 {
INTEGER A[10000 + 1];
} *Z132;
static INTEGER Z133;
static ZpmCQ_4 Z134;
static ZpmCQ_4 Z135;
static ZpmCQ_4 Z136;

void Zq7SFB_3
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z138)
# else
(Z138)
Zfb3DLQ_0 Z138;
# endif
{
if (Z138 == Zpky9FDA_39) {
return;
}
Z130->A[Z138] = Zq7SFB_16;
}

void Zq7SFB_4
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z138)
# else
(Z138)
Zfb3DLQ_0 Z138;
# endif
{
if (Z138 == Zpky9FDA_39) {
return;
}
Z130->A[Z138] = Zq7SFB_17;
}

void Zq7SFB_5
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z138)
# else
(Z138)
Zfb3DLQ_0 Z138;
# endif
{
if (Z138 == Zpky9FDA_39) {
return;
}
Z130->A[Z138] = Zq7SFB_18;
INC(Z133);
Z132->A[Z138] = Z133;
ZpmCQ_13(&Z135, (LONGCARD)Z138);
}

void Zq7SFB_6
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z138)
# else
(Z138)
Zfb3DLQ_0 Z138;
# endif
{
if (Z138 == Zpky9FDA_39) {
return;
}
Z130->A[Z138] = Zq7SFB_19;
ZpmCQ_13(&Z134, (LONGCARD)Z138);
}

void Zq7SFB_7
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z147)
# else
(Z147)
Zfb3DLQ_0 Z147;
# endif
{
if (Z147 == Zpky9FDA_39) {
return;
}
Z130->A[Z147] = Zq7SFB_20;
}

Zq7SFB_0 Zq7SFB_2
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z150)
# else
(Z150)
Zfb3DLQ_0 Z150;
# endif
{
return Z130->A[Z150];
}

void Zq7SFB_1
 ARGS ((void))
{
LONGINT Z152;
Zfb3DLQ_0 Z150;

Z152 = Zpky9FDA_40 + 1;
ZarQdhNDD_0((ADDRESS *)&Z130, &Z152, (LONGINT)sizeof (Zq7SFB_0));
ZarQdhNDD_0((ADDRESS *)&Z132, &Z152, (LONGINT)sizeof (INTEGER));
{
SHORTCARD B_1 = 0, B_2 = Zpky9FDA_40;

if (B_1 <= B_2)
for (Z150 = B_1;; Z150 += 1) {
Z130->A[Z150] = Zq7SFB_15;
Z132->A[Z150] = Z129;
if (Z150 >= B_2) break;
}
}
ZpmCQ_5(&Z134, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z135, (LONGCARD)Zpky9FDA_40);
ZpmCQ_5(&Z136, (LONGCARD)Zpky9FDA_40);
}

void Zq7SFB_10
# ifdef HAVE_ARGS
(ZpmCQ_4 *Z155)
# else
(Z155)
ZpmCQ_4 *Z155;
# endif
{
ZpmCQ_30(Z155, Z134);
}

void Zq7SFB_11
# ifdef HAVE_ARGS
(ZpmCQ_4 *Z157)
# else
(Z157)
ZpmCQ_4 *Z157;
# endif
{
ZpmCQ_30(Z157, Z135);
}

void Zq7SFB_12
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z138)
# else
(Z138)
Zfb3DLQ_0 Z138;
# endif
{
ZpmCQ_13(&Z136, (LONGCARD)Z138);
}

void Zq7SFB_13
# ifdef HAVE_ARGS
(ZpmCQ_4 Z160)
# else
(Z160)
ZpmCQ_4 Z160;
# endif
{
ZpmCQ_8(&Z136, Z160);
}

BOOLEAN Zq7SFB_14
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z138)
# else
(Z138)
Zfb3DLQ_0 Z138;
# endif
{
return ZpmCQ_25((LONGCARD)Z138, &Z136);
}

INTEGER Zq7SFB_8
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z163)
# else
(Z163)
Zfb3DLQ_0 Z163;
# endif
{
return Z132->A[Z163];
}

INTEGER Zq7SFB_9
 ARGS ((void))
{
return Z133;
}

void BEGIN_Types ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_Sets ();
BEGIN_DynArray ();
BEGIN_Idents ();
BEGIN_Scanner ();
BEGIN_Sets ();

Z133 = -1;
}
