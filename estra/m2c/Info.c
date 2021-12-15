#include "SYSTEM_.h"

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Layout
#include "Layout.h"
#endif

#ifndef DEFINITION_rMemory
#include "rMemory.h"
#endif

#ifndef DEFINITION_Patterns
#include "Patterns.h"
#endif

#ifndef DEFINITION_Sets
#include "Sets.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Info
#include "Info.h"
#endif


struct S_2 {
CHAR A[255 + 1];
};
struct S_1 {
CHAR A[255 + 1];
};

ADDRESS ZflEF_0
# ifdef HAVE_ARGS
(INTEGER Z160, ADDRESS Z114)
# else
(Z160, Z114)
INTEGER Z160;
ADDRESS Z114;
# endif
{
INTEGER *Z161, *Z162;
SHORTCARD *Z163, *Z164;
LONGINT *Z165, *Z166;
REAL *Z167, *Z168;
BOOLEAN *Z169, *Z170;
CHAR *Z171, *Z172;
Zp1PEAFD_2 *Z173, *Z174;
struct S_2 *Z175, *Z176;
ZpmCQ_4 *Z177, *Z178;
Zfb3DLQ_0 *Z179, *Z180;
ZmfFRCAJK_3 *Z181, *Z182;

switch (Z160) {
case ZblNKKO_34:;
Z161 = (LONGINT *)ZDtgCFKU_1((LONGINT)sizeof (INTEGER));
Z162 = (LONGINT *)Z114;
*Z161 = *Z162;
return (ADDRESS)Z161;
break;
case ZblNKKO_35:;
Z163 = (SHORTCARD *)ZDtgCFKU_1((LONGINT)sizeof (SHORTCARD));
Z164 = (SHORTCARD *)Z114;
*Z163 = *Z164;
return (ADDRESS)Z163;
break;
case ZblNKKO_36:;
Z165 = (LONGINT *)ZDtgCFKU_1((LONGINT)sizeof (LONGINT));
Z166 = (LONGINT *)Z114;
*Z165 = *Z166;
return (ADDRESS)Z165;
break;
case ZblNKKO_37:;
Z167 = (REAL *)ZDtgCFKU_1((LONGINT)sizeof (REAL));
Z168 = (REAL *)Z114;
*Z167 = *Z168;
return (ADDRESS)Z167;
break;
case ZblNKKO_38:;
Z169 = (BOOLEAN *)ZDtgCFKU_1((LONGINT)sizeof (BOOLEAN));
Z170 = (BOOLEAN *)Z114;
*Z169 = *Z170;
return (ADDRESS)Z169;
break;
case ZblNKKO_39:;
Z171 = (CHAR *)ZDtgCFKU_1((LONGINT)sizeof (CHAR));
Z172 = (CHAR *)Z114;
*Z171 = *Z172;
return (ADDRESS)Z171;
break;
case ZblNKKO_40:;
Z173 = (Zp1PEAFD_2 *)ZDtgCFKU_1((LONGINT)sizeof (Zp1PEAFD_2));
Z174 = (Zp1PEAFD_2 *)Z114;
Zp1PEAFD_3(Z173, Z174);
return (ADDRESS)Z173;
break;
case ZblNKKO_41:;
Z175 = (struct S_2 *)ZDtgCFKU_1(256L);
Z176 = (struct S_2 *)Z114;
*Z175 = *Z176;
return (ADDRESS)Z175;
break;
case ZblNKKO_43:;
Z179 = (SHORTCARD *)ZDtgCFKU_1((LONGINT)sizeof (Zfb3DLQ_0));
Z180 = (SHORTCARD *)Z114;
*Z179 = *Z180;
return (ADDRESS)Z179;
break;
case ZblNKKO_44:;
Z177 = (ZpmCQ_4 *)ZDtgCFKU_1((LONGINT)sizeof (ZpmCQ_4));
Z178 = (ZpmCQ_4 *)Z114;
ZpmCQ_5(Z177, ZpmCQ_16(Z178));
ZpmCQ_30(Z177, *Z178);
return (ADDRESS)Z177;
break;
case ZmfFRCAJK_1:;
Z181 = (ZmfFRCAJK_3 *)ZDtgCFKU_1((LONGINT)sizeof (ZmfFRCAJK_3));
Z182 = (ZmfFRCAJK_3 *)Z114;
*Z181 = ZmfFRCAJK_19(*Z182);
return (ADDRESS)Z181;
break;
default:
return (ADDRESS)NIL;
break;
}
}

void ZflEF_1
# ifdef HAVE_ARGS
(INTEGER Z160, ADDRESS Z114)
# else
(Z160, Z114)
INTEGER Z160;
ADDRESS Z114;
# endif
{
INTEGER *Z162;
SHORTCARD *Z164;
LONGINT *Z166;
REAL *Z168;
BOOLEAN *Z170;
CHAR *Z172;
Zp1PEAFD_2 *Z174;
struct S_1 *Z176;
ZpmCQ_4 *Z178;
Zfb3DLQ_0 *Z180;
ZmfFRCAJK_3 *Z182;

if (Z160 == ZblNKKO_33) {
return;
}
switch (Z160) {
case ZblNKKO_34:;
Z162 = (LONGINT *)Z114;
ZfM_25((ZDz6VQCC_4)ZfM_2, *Z162, 1L);
break;
case ZblNKKO_35:;
Z164 = (SHORTCARD *)Z114;
ZfM_25((ZDz6VQCC_4)ZfM_2, (LONGINT)(*Z164), 1L);
break;
case ZblNKKO_36:;
Z166 = (LONGINT *)Z114;
ZfM_31((ZDz6VQCC_4)ZfM_2, *Z166, 1L);
break;
case ZblNKKO_37:;
Z168 = (REAL *)Z114;
ZfM_26((ZDz6VQCC_4)ZfM_2, *Z168, 1L, 10L, 1L);
break;
case ZblNKKO_38:;
Z170 = (BOOLEAN *)Z114;
ZfM_27((ZDz6VQCC_4)ZfM_2, *Z170);
break;
case ZblNKKO_39:;
Z172 = (CHAR *)Z114;
ZibDRNS_0((ZDz6VQCC_4)ZfM_2, *Z172);
break;
case ZblNKKO_40:;
Z174 = (Zp1PEAFD_2 *)Z114;
Zp1PEAFD_21((ZDz6VQCC_4)ZfM_2, Z174);
break;
case ZblNKKO_41:;
Z176 = (struct S_1 *)Z114;
ZfM_29((ZDz6VQCC_4)ZfM_2, (*Z176).A, 256L);
break;
case ZblNKKO_43:;
Z180 = (SHORTCARD *)Z114;
Zfb3DLQ_7((ZDz6VQCC_4)ZfM_2, *Z180);
break;
case ZblNKKO_44:;
Z178 = (ZpmCQ_4 *)Z114;
ZflEF_2((ZDz6VQCC_4)ZfM_2, *Z178);
break;
case ZmfFRCAJK_1:;
Z182 = (ZmfFRCAJK_3 *)Z114;
ZmfFRCAJK_20((ZDz6VQCC_4)ZfM_2, *Z182);
break;
default:
ZfM_29((ZDz6VQCC_4)ZfM_2, (STRING)"info class: ", 12L);
ZfM_25((ZDz6VQCC_4)ZfM_2, Z160, 1L);
break;
}
}

void ZflEF_2
# ifdef HAVE_ARGS
(ZfM_3 Z185, ZpmCQ_4 Z186)
# else
(Z185, Z186)
ZfM_3 Z185;
ZpmCQ_4 Z186;
# endif
{
ZpmCQ_4 Z187;

ZpmCQ_5(&Z187, ZpmCQ_16(&Z186));
ZpmCQ_30(&Z187, Z186);
if (!ZpmCQ_26(Z187)) {
for (;;) {
Zfb3DLQ_7(Z185, (SHORTCARD)ZpmCQ_20(&Z187));
if (ZpmCQ_26(Z187)) {
goto EXIT_1;
}
ZfM_24(Z185, ' ');
} EXIT_1:;
}
ZpmCQ_7(&Z187);
}

void BEGIN_Info ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_Sets ();
BEGIN_Strings ();
BEGIN_Errors ();
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Layout ();
BEGIN_rMemory ();
BEGIN_Patterns ();
BEGIN_Sets ();
BEGIN_Strings ();

}
