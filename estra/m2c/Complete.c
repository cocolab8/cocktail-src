#include "SYSTEM_.h"

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

#ifndef DEFINITION_Environs
#include "Environs.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Patterns
#include "Patterns.h"
#endif

#ifndef DEFINITION_Queues
#include "Queues.h"
#endif

#ifndef DEFINITION_Complete
#include "Complete.h"
#endif

BOOLEAN ZggFGFBCC_0;

#define Z149	61
#define Z150	62
static void Z161 ARGS ((Zn0DDDB_4 *Z158, Zn0DDDB_4 *Z155, Zn0DDDB_4 *Z156, Zn0DDDB_4 *Z157));

void ZggFGFBCC_1
# ifdef HAVE_ARGS
(ZbhNIEKGK_1 Z152, Zfb3DLQ_0 Z153, ZmtLFGGBG_0 Z154)
# else
(Z152, Z153, Z154)
ZbhNIEKGK_1 Z152;
Zfb3DLQ_0 Z153;
ZmtLFGGBG_0 Z154;
# endif
{
Zn0DDDB_4 Z155;
Zn0DDDB_4 Z156;
Zn0DDDB_4 Z157;
Zn0DDDB_4 Z158;
ZmfFRCAJK_3 Z159;
INTEGER Z160;

Zn0DDDB_5(&Z156);
Zn0DDDB_5(&Z157);
Zn0DDDB_5(&Z155);
Zn0DDDB_8(&Z155, (ADDRESS)ZmfFRCAJK_12(ZmfFRCAJK_6(Z153)));
Zn0DDDB_5(&Z158);
ZbhNIEKGK_6(Z152, &Z158);
Z161(&Z158, &Z155, &Z156, &Z157);
while (!Zn0DDDB_15(Z157)) {
Z159 = (ZmfFRCAJK_3)Zn0DDDB_19(&Z157);
ZmfFRCAJK_8(&Z159);
}
ZbhNIEKGK_7(Z152, &Z158);
Z161(&Z158, &Z155, &Z156, &Z157);
while (!Zn0DDDB_15(Z157)) {
Z159 = (ZmfFRCAJK_3)Zn0DDDB_19(&Z157);
ZblNKKO_78((LONGCARD)Z149, (LONGCARD)ZblNKKO_48, Z154, (LONGCARD)ZmfFRCAJK_1, ADR (Z159));
ZmfFRCAJK_8(&Z159);
}
while (!Zn0DDDB_15(Z156)) {
Z159 = (ZmfFRCAJK_3)Zn0DDDB_19(&Z156);
ZblNKKO_78((LONGCARD)Z150, (LONGCARD)ZblNKKO_47, Z154, (LONGCARD)ZmfFRCAJK_1, ADR (Z159));
ZmfFRCAJK_8(&Z159);
}
Zn0DDDB_6(&Z156);
Zn0DDDB_6(&Z155);
Zn0DDDB_6(&Z158);
}

static void Z161
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z158, Zn0DDDB_4 *Z155, Zn0DDDB_4 *Z156, Zn0DDDB_4 *Z157)
# else
(Z158, Z155, Z156, Z157)
Zn0DDDB_4 *Z158, *Z155, *Z156, *Z157;
# endif
{
ZmfFRCAJK_3 Z154;
ZmfFRCAJK_3 Z162;
ZmfFRCAJK_3 Z163;
ZmfFRCAJK_2 Z164;

while (!Zn0DDDB_15(*Z158) && !Zn0DDDB_15(*Z155)) {
Z163 = (ZmfFRCAJK_3)Zn0DDDB_19(Z158);
Zn0DDDB_7(Z156);
while (!Zn0DDDB_15(*Z155)) {
Z162 = (ZmfFRCAJK_3)Zn0DDDB_19(Z155);
ZmfFRCAJK_15();
Z164 = ZmfFRCAJK_13(Z162, Z163);
switch (Z164) {
case ZmfFRCAJK_25:;
case ZmfFRCAJK_23:;
Zn0DDDB_8(Z157, (ADDRESS)Z162);
break;
case ZmfFRCAJK_21:;
case ZmfFRCAJK_24:;
Z154 = ZmfFRCAJK_16();
if (Z154 != NIL) {
ZmfFRCAJK_17(Z162, Z154, Z155);
}
ZmfFRCAJK_8(&Z162);
break;
case ZmfFRCAJK_22:;
Zn0DDDB_8(Z156, (ADDRESS)Z162);
break;
}
}
Zn0DDDB_18(Z155, *Z156);
}
Zn0DDDB_18(Z156, *Z155);
}

void BEGIN_Complete ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Environs ();
BEGIN_Idents ();
BEGIN_Position ();
BEGIN_Errors ();
BEGIN_Position ();
BEGIN_Environs ();
BEGIN_Idents ();
BEGIN_Patterns ();
BEGIN_Queues ();

ZggFGFBCC_0 = TRUE;
}
