#include "SYSTEM_.h"

#ifndef DEFINITION_rMemory
#include "rMemory.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Base
#include "Base.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Defs
#include "Defs.h"
#endif

#ifndef DEFINITION_AssocTab
#include "AssocTab.h"
#endif

#ifndef DEFINITION_DefMods
#include "DefMods.h"
#endif


typedef enum {Z154, Z155, Z156} Z153;
typedef Z153 *Z157;
static Zq0A4_133 Z135;
static Z157 Z158 ARGS ((Z153 Z159));
static void Z167 ARGS ((Zq0A4_133 Z168));
static void Z165 ARGS ((Zfb3DLQ_0 Z176, ZmtLFGGBG_0 Z166));
struct S_1 {
CHAR A[255 + 1];
};

static Z157 Z158
# ifdef HAVE_ARGS
(Z153 Z159)
# else
(Z159)
Z153 Z159;
# endif
{
Z157 Z160;

Z160 = (Z157)ZDtgCFKU_1((LONGINT)sizeof (Z153));
*Z160 = Z159;
return Z160;
}

void Zae5hqDA_0
# ifdef HAVE_ARGS
(Zq0A4_133 Z162, Zq0A4_133 *Z163)
# else
(Z162, Z163)
Zq0A4_133 Z162;
Zq0A4_133 *Z163;
# endif
{
Z135 = Zq0A4_335();
ZeiPLCljx_0();
ZeiPLCljx_1(Zae5C_105, (ADDRESS)Z158(Z155));
if (Z162->U_1.V_1.Y0 == Zq0A4_8) {
if (Z162->U_1.V_8.Y7.Y3 == Zq0A4_161) {
Z165(Z162->U_1.V_8.Y7.Y4, Z162->U_1.V_8.Y7.Y5);
}
Z167(Z162);
} else {
ZeiPLCljx_1(Z162->U_1.V_7.Y6.Y4, (ADDRESS)Z158(Z154));
Z167(Z162);
}
ZeiPLCljx_3();
*Z163 = Zq0A4_333(Zq0A4_462(Z135));
}

static void Z167
# ifdef HAVE_ARGS
(Zq0A4_133 Z168)
# else
(Z168)
Zq0A4_133 Z168;
# endif
{
Zq0A4_133 Z169, Z170;
Z157 Z160;

switch (Z168->U_1.V_1.Y0) {
case Zq0A4_7:;
Z169 = Z168->U_1.V_7.Y6.Y8;
break;
case Zq0A4_8:;
Z169 = Z168->U_1.V_8.Y7.Y8;
break;
}
while (Z169->U_1.V_1.Y0 != Zq0A4_10) {
if (Z169->U_1.V_1.Y0 == Zq0A4_12) {
ZeiPLCljx_2(Z169->U_1.V_12.Y11.Y4, (ADDRESS *)&Z160);
if (Z160 == NIL) {
Z165(Z169->U_1.V_12.Y11.Y4, Z169->U_1.V_12.Y11.Y5);
} else if (*Z160 == Z154) {
ZblNKKO_39((LONGCARD)ZblNKKO_11, (LONGCARD)ZblNKKO_27, Z169->U_1.V_12.Y11.Y5);
}
} else {
Z170 = Z169->U_1.V_13.Y12.Y4;
while (Z170->U_1.V_1.Y0 != Zq0A4_15) {
ZeiPLCljx_2(Z170->U_1.V_16.Y15.Y1, (ADDRESS *)&Z160);
if (Z160 == NIL) {
Z165(Z170->U_1.V_16.Y15.Y1, Z170->U_1.V_16.Y15.Y2);
} else if (*Z160 == Z154) {
ZblNKKO_39((LONGCARD)ZblNKKO_11, (LONGCARD)ZblNKKO_27, Z170->U_1.V_16.Y15.Y2);
}
Z170 = Z170->U_1.V_16.Y15.Y3;
}
}
Z169 = Z169->U_1.V_11.Y10.Y3;
}
if (Z168->U_1.V_1.Y0 != Zq0A4_8) {
ZeiPLCljx_2(Z168->U_1.V_7.Y6.Y4, (ADDRESS *)&Z160);
*Z160 = Z155;
ZeiPLCljx_1(Z168->U_1.V_7.Y6.Y4, (ADDRESS)Z160);
}
Z168->U_1.V_6.Y5.Y6 = Z135;
Z135 = Z168;
}

static void Z165
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z176, ZmtLFGGBG_0 Z166)
# else
(Z176, Z166)
Zfb3DLQ_0 Z176;
ZmtLFGGBG_0 Z166;
# endif
{
BOOLEAN Z177;
struct S_1 Z178;
CARDINAL Z179;

ZfXEB_4(Z176, Z178.A, 256L, &Z177);
if (!Z177) {
ZeiPLCljx_1(Z176, (ADDRESS)Z158(Z156));
ZblNKKO_40((LONGCARD)ZblNKKO_12, (LONGCARD)ZblNKKO_29, Z166, (LONGCARD)ZblNKKO_38, ADR (Z176));
} else {
Zpky9FDA_8(Z178.A, 256L);
Z179 = ZmfDOBA_6();
if (Z179 == 0) {
if (ZmfDOBA_5.U_1.V_0.Y3->U_1.V_1.Y0 == Zq0A4_8) {
ZeiPLCljx_1(Z176, (ADDRESS)Z158(Z156));
ZblNKKO_40((LONGCARD)ZblNKKO_12, (LONGCARD)ZblNKKO_29, Z166, (LONGCARD)ZblNKKO_38, ADR (Z176));
} else {
ZeiPLCljx_1(Z176, (ADDRESS)Z158(Z154));
Z167(ZmfDOBA_5.U_1.V_0.Y3);
}
} else {
ZeiPLCljx_1(Z176, (ADDRESS)Z158(Z156));
}
}
}

void BEGIN_DefMods ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Tree ();
BEGIN_rMemory ();
BEGIN_Idents ();
BEGIN_Base ();
BEGIN_Scanner ();
BEGIN_Parser ();
BEGIN_Errors ();
BEGIN_Position ();
BEGIN_Tree ();
BEGIN_Defs ();
BEGIN_AssocTab ();

}
