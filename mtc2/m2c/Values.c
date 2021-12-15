#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_StringM
#include "StringM.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Defs
#include "Defs.h"
#endif

#ifndef DEFINITION_Types
#include "Types.h"
#endif

#ifndef DEFINITION_Defs
#include "Defs.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Values
#include "Values.h"
#endif

Zsl7KDB_13 Zsl7KDB_14, Zsl7KDB_15, Zsl7KDB_16, Zsl7KDB_17, Zsl7KDB_18, Zsl7KDB_19, Zsl7KDB_20, Zsl7KDB_21, Zsl7KDB_22, Zsl7KDB_23, Zsl7KDB_24, Zsl7KDB_25, Zsl7KDB_26, Zsl7KDB_27, Zsl7KDB_28, Zsl7KDB_29, Zsl7KDB_30;

#define Z209	(SET_ELEM (Zsl7KDB_5) | SET_ELEM (Zsl7KDB_6))
#define Z212	0
#define Z213	1
static Zae5C_64 Z214;
static void Z219 ARGS ((Zq0A4_133 Z220, Zsl7KDB_13 *Z217));

void Zsl7KDB_31
# ifdef HAVE_ARGS
(ADDRESS Z131, ADDRESS Z216, Zsl7KDB_13 *Z217)
# else
(Z131, Z216, Z217)
ADDRESS Z131, Z216;
Zsl7KDB_13 *Z217;
# endif
{
Z214 = (Zae5C_57)Z216;
Z219((Zq0A4_133)Z131, Z217);
}

static void Z219
# ifdef HAVE_ARGS
(Zq0A4_133 Z220, Zsl7KDB_13 *Z217)
# else
(Z220, Z217)
Zq0A4_133 Z220;
Zsl7KDB_13 *Z217;
# endif
{
Zsl7KDB_13 Z221, Z222;
Zae5C_59 Z223, Z224;
Zae5C_60 Z225;
Zp1PEAFD_2 Z226;
CARDINAL Z227, Z228;
REAL Z229;

if (Z220 == NIL) {
return;
}
switch (Z220->U_1.V_1.Y0) {
case Zq0A4_93:;
Z220->U_1.V_93.Y92.Y6 = Zae5C_150(Z220->U_1.V_93.Y92.Y5, Z214);
switch (Z220->U_1.V_93.Y92.Y6->U_1.V_1.Y0) {
case Zae5C_5:;
*Z217 = Z220->U_1.V_93.Y92.Y6->U_1.V_5.Y4.Y3;
return;
break;
case Zae5C_6:;
Z217->Y0 = Zsl7KDB_9;
Z217->U_1.V_8.Y8 = (ADDRESS)Z220->U_1.V_93.Y92.Y6;
return;
break;
case Zae5C_12:;
case Zae5C_13:;
Z217->Y0 = Zsl7KDB_12;
Z217->U_1.V_10.Y10 = (ADDRESS)Zae5C_161(Z220->U_1.V_93.Y92.Y6);
return;
break;
case Zae5C_15:;
Z217->Y0 = Zsl7KDB_11;
Z217->U_1.V_9.Y9 = Z220->U_1.V_93.Y92.Y6->U_1.V_15.Y14.Y3;
return;
break;
default:
break;
}
break;
case Zq0A4_94:;
Z219(Z220->U_1.V_94.Y93.Y8, Z217);
Z220->U_1.V_94.Y93.Y6 = Zae5C_151(Z220->U_1.V_94.Y93.Y5, Zae5C_159(Z220->U_1.V_94.Y93.Y8->U_1.V_92.Y91.Y6));
switch (Z220->U_1.V_94.Y93.Y6->U_1.V_1.Y0) {
case Zae5C_5:;
*Z217 = Z220->U_1.V_94.Y93.Y6->U_1.V_5.Y4.Y3;
return;
break;
case Zae5C_6:;
Z217->Y0 = Zsl7KDB_9;
Z217->U_1.V_8.Y8 = (ADDRESS)Z220->U_1.V_94.Y93.Y6;
return;
break;
case Zae5C_12:;
case Zae5C_13:;
Z217->Y0 = Zsl7KDB_12;
Z217->U_1.V_10.Y10 = (ADDRESS)Zae5C_161(Z220->U_1.V_94.Y93.Y6);
return;
break;
case Zae5C_15:;
Z217->Y0 = Zsl7KDB_11;
Z217->U_1.V_9.Y9 = Z220->U_1.V_94.Y93.Y6->U_1.V_15.Y14.Y3;
return;
break;
default:
break;
}
break;
case Zq0A4_82:;
Z219(Z220->U_1.V_82.Y81.Y5, &Z221);
Z219(Z220->U_1.V_82.Y81.Y6, &Z222);
switch (Z220->U_1.V_82.Y81.Y4) {
case Zq0A4_165:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z221.U_1.V_1.Y1 + Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_3;
Z217->U_1.V_3.Y3 = Z221.U_1.V_3.Y3 + Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_8;
Z217->U_1.V_7.Y7 = Z221.U_1.V_7.Y7 | Z222.U_1.V_7.Y7;
return;
}
break;
case Zq0A4_166:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z221.U_1.V_1.Y1 - Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_3;
Z217->U_1.V_3.Y3 = Z221.U_1.V_3.Y3 - Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_8;
Z217->U_1.V_7.Y7 = SET_DIFF(Z221.U_1.V_7.Y7, Z222.U_1.V_7.Y7);
return;
}
break;
case Zq0A4_164:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z221.U_1.V_1.Y1 * Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_3;
Z217->U_1.V_3.Y3 = Z221.U_1.V_3.Y3 * Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_8;
Z217->U_1.V_7.Y7 = Z221.U_1.V_7.Y7 & Z222.U_1.V_7.Y7;
return;
}
break;
case Zq0A4_167:;
if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_3;
Z217->U_1.V_3.Y3 = Z221.U_1.V_3.Y3 / Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_8;
Z217->U_1.V_7.Y7 = Z221.U_1.V_7.Y7 ^ Z222.U_1.V_7.Y7;
return;
}
break;
case Zq0A4_174:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
if (Z222.U_1.V_1.Y1 != 0) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z221.U_1.V_1.Y1 / Z222.U_1.V_1.Y1;
return;
}
}
break;
case Zq0A4_176:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
if (Z222.U_1.V_1.Y1 != 0) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z221.U_1.V_1.Y1 % Z222.U_1.V_1.Y1;
return;
}
}
break;
case Zq0A4_168:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_1.Y1 < Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_3.Y3 < Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 < Z222.U_1.V_4.Y4;
return;
} else if (IN(Z221.Y0, Z209) && IN(Z222.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_5.Y5 < Z222.U_1.V_5.Y5;
return;
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z223->U_1.V_6.Y5.Y4 < Z224->U_1.V_6.Y5.Y4;
return;
}
break;
case Zq0A4_169:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_1.Y1 <= Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_3.Y3 <= Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 <= Z222.U_1.V_4.Y4;
return;
} else if (IN(Z221.Y0, Z209) && IN(Z222.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_5.Y5 <= Z222.U_1.V_5.Y5;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = SET_IS_SUBSET1(Z221.U_1.V_7.Y7, Z222.U_1.V_7.Y7);
return;
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z223->U_1.V_6.Y5.Y4 <= Z224->U_1.V_6.Y5.Y4;
return;
}
break;
case Zq0A4_170:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_1.Y1 == Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_3.Y3 == Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 == Z222.U_1.V_4.Y4;
return;
} else if (IN(Z221.Y0, Z209) && IN(Z222.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_5.Y5 == Z222.U_1.V_5.Y5;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_7.Y7 == Z222.U_1.V_7.Y7;
return;
} else if (Z221.Y0 == Zsl7KDB_10 && Z222.Y0 == Zsl7KDB_10) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = TRUE;
return;
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z223->U_1.V_6.Y5.Y4 == Z224->U_1.V_6.Y5.Y4;
return;
}
break;
case Zq0A4_163:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_1.Y1 != Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_3.Y3 != Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 != Z222.U_1.V_4.Y4;
return;
} else if (IN(Z221.Y0, Z209) && IN(Z222.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_5.Y5 != Z222.U_1.V_5.Y5;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_7.Y7 != Z222.U_1.V_7.Y7;
return;
} else if (Z221.Y0 == Zsl7KDB_10 && Z222.Y0 == Zsl7KDB_10) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = FALSE;
return;
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z223->U_1.V_6.Y5.Y4 != Z224->U_1.V_6.Y5.Y4;
return;
}
break;
case Zq0A4_171:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_1.Y1 > Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_3.Y3 > Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 > Z222.U_1.V_4.Y4;
return;
} else if (IN(Z221.Y0, Z209) && IN(Z222.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_5.Y5 > Z222.U_1.V_5.Y5;
return;
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z223->U_1.V_6.Y5.Y4 > Z224->U_1.V_6.Y5.Y4;
return;
}
break;
case Zq0A4_172:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_1.Y1 >= Z222.U_1.V_1.Y1;
return;
} else if (Z221.Y0 == Zsl7KDB_3 && Z222.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_3.Y3 >= Z222.U_1.V_3.Y3;
return;
} else if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 >= Z222.U_1.V_4.Y4;
return;
} else if (IN(Z221.Y0, Z209) && IN(Z222.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_5.Y5 >= Z222.U_1.V_5.Y5;
return;
} else if (Z221.Y0 == Zsl7KDB_8 && Z222.Y0 == Zsl7KDB_8) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = SET_IS_SUBSET2(Z221.U_1.V_7.Y7, Z222.U_1.V_7.Y7);
return;
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z223->U_1.V_6.Y5.Y4 >= Z224->U_1.V_6.Y5.Y4;
return;
}
break;
case Zq0A4_173:;
if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 && Z222.U_1.V_4.Y4;
return;
}
break;
case Zq0A4_178:;
if (Z221.Y0 == Zsl7KDB_4 && Z222.Y0 == Zsl7KDB_4) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = Z221.U_1.V_4.Y4 || Z222.U_1.V_4.Y4;
return;
}
break;
case Zq0A4_175:;
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_8) {
if (Z221.U_1.V_1.Y1 >= 0 && Z221.U_1.V_1.Y1 <= Zq7SFB_8) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = IN(Z221.U_1.V_1.Y1, Z222.U_1.V_7.Y7);
return;
}
} else if (IN(Z221.Y0, Z209) && Z222.Y0 == Zsl7KDB_8) {
if (ORD(Z221.U_1.V_5.Y5) <= Zq7SFB_8) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = IN(ORD(Z221.U_1.V_5.Y5), Z222.U_1.V_7.Y7);
return;
}
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_8) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
if (Z223->U_1.V_6.Y5.Y4 <= Zq7SFB_8) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = IN(Z223->U_1.V_6.Y5.Y4, Z222.U_1.V_7.Y7);
return;
}
}
break;
}
break;
case Zq0A4_83:;
Z219(Z220->U_1.V_83.Y82.Y5, Z217);
switch (Z220->U_1.V_83.Y82.Y4) {
case Zq0A4_165:;
break;
case Zq0A4_166:;
if (Z217->Y0 == Zsl7KDB_1) {
Z217->U_1.V_1.Y1 = -Z217->U_1.V_1.Y1;
return;
} else if (Z217->Y0 == Zsl7KDB_2) {
if (Zq7SFB_2 <= -(INTEGER)Z217->U_1.V_2.Y2) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = -(INTEGER)Z217->U_1.V_2.Y2;
return;
} else {
*Z217 = Zsl7KDB_14;
}
} else if (Z217->Y0 == Zsl7KDB_3) {
Z217->U_1.V_3.Y3 = -Z217->U_1.V_3.Y3;
return;
}
break;
case Zq0A4_177:;
if (Z217->Y0 == Zsl7KDB_4) {
Z217->U_1.V_4.Y4 = !Z217->U_1.V_4.Y4;
return;
}
break;
}
break;
case Zq0A4_84:;
if (Z220->U_1.V_84.Y83.Y5 <= Zq7SFB_3) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z220->U_1.V_84.Y83.Y5;
} else if (Z220->U_1.V_84.Y83.Y5 <= Zq7SFB_5) {
Z217->Y0 = Zsl7KDB_2;
Z217->U_1.V_2.Y2 = Z220->U_1.V_84.Y83.Y5;
} else {
*Z217 = Zsl7KDB_14;
}
return;
break;
case Zq0A4_85:;
Z217->Y0 = Zsl7KDB_3;
Zp1PEAFi_3(Z220->U_1.V_85.Y84.Y4, &Z226);
Z217->U_1.V_3.Y3 = Zp1PEAFD_17(&Z226);
return;
break;
case Zq0A4_86:;
Zp1PEAFi_3(Z220->U_1.V_86.Y85.Y4, &Z226);
if (Zp1PEAFD_7(&Z226) == 1) {
Z217->Y0 = Zsl7KDB_6;
Z217->U_1.V_5.Y5 = Zp1PEAFD_12(&Z226, 1);
} else {
Z217->Y0 = Zsl7KDB_7;
Z217->U_1.V_6.Y6 = Z220->U_1.V_86.Y85.Y4;
}
return;
break;
case Zq0A4_87:;
Z217->Y0 = Zsl7KDB_5;
Z217->U_1.V_5.Y5 = Z220->U_1.V_87.Y86.Y4;
return;
break;
case Zq0A4_88:;
Z219(Z220->U_1.V_88.Y87.Y4, Z217);
if (Z217->Y0 == Zsl7KDB_11) {
Z219(Z220->U_1.V_88.Y87.Y5, &Z221);
switch (Z217->U_1.V_9.Y9) {
case Zae5C_75:;
if (Z221.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = ABSLI(Z221.U_1.V_1.Y1);
return;
} else if (Z221.Y0 == Zsl7KDB_3) {
Z217->Y0 = Zsl7KDB_3;
Z217->U_1.V_3.Y3 = ABSLR(Z221.U_1.V_3.Y3);
return;
}
break;
case Zae5C_76:;
if (IN(Z221.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_5;
Z217->U_1.V_5.Y5 = CAP(Z221.U_1.V_5.Y5);
return;
}
break;
case Zae5C_77:;
if (Z221.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_5;
Z217->U_1.V_5.Y5 = CHR((CARDINAL)Z221.U_1.V_1.Y1);
return;
}
break;
case Zae5C_80:;
if (Z221.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_3;
Z217->U_1.V_3.Y3 = FLOAT((CARDINAL)Z221.U_1.V_1.Y1);
return;
}
break;
case Zae5C_86:;
if (Z221.Y0 == Zsl7KDB_12) {
Z225 = (Zae5C_57)Z221.U_1.V_10.Y10;
switch (Z225->U_1.V_1.Y0) {
case Zae5C_18:;
*Z217 = Zsl7KDB_21;
return;
break;
case Zae5C_19:;
*Z217 = Zsl7KDB_23;
return;
break;
case Zae5C_20:;
*Z217 = Zsl7KDB_20;
return;
break;
case Zae5C_21:;
*Z217 = Zsl7KDB_20;
return;
break;
case Zae5C_22:;
*Z217 = Zsl7KDB_27;
return;
break;
case Zae5C_23:;
*Z217 = Zsl7KDB_29;
return;
break;
case Zae5C_24:;
*Z217 = Zsl7KDB_17;
return;
break;
case Zae5C_25:;
*Z217 = Zsl7KDB_18;
return;
break;
case Zae5C_41:;
Z217->Y0 = Zsl7KDB_9;
Z217->U_1.V_8.Y8 = (ADDRESS)Zae5C_170(Z225->U_1.V_41.Y40.Y3, 0);
return;
break;
case Zae5C_47:;
*Z217 = Z225->U_1.V_47.Y46.Y5;
return;
break;
default:
break;
}
}
break;
case Zae5C_85:;
if (Z221.Y0 == Zsl7KDB_12) {
Z225 = (Zae5C_57)Z221.U_1.V_10.Y10;
switch (Z225->U_1.V_1.Y0) {
case Zae5C_18:;
*Z217 = Zsl7KDB_22;
return;
break;
case Zae5C_19:;
*Z217 = Zsl7KDB_24;
return;
break;
case Zae5C_20:;
*Z217 = Zsl7KDB_25;
return;
break;
case Zae5C_21:;
*Z217 = Zsl7KDB_26;
return;
break;
case Zae5C_22:;
*Z217 = Zsl7KDB_28;
return;
break;
case Zae5C_23:;
*Z217 = Zsl7KDB_30;
return;
break;
case Zae5C_24:;
*Z217 = Zsl7KDB_16;
return;
break;
case Zae5C_25:;
*Z217 = Zsl7KDB_19;
return;
break;
case Zae5C_41:;
Z217->Y0 = Zsl7KDB_9;
{
register Zae5C_225 *W_1 = &Z225->U_1.V_41.Y40;

Z217->U_1.V_8.Y8 = (ADDRESS)Zae5C_170(W_1->Y3, W_1->Y2);
}
return;
break;
case Zae5C_47:;
*Z217 = Z225->U_1.V_47.Y46.Y6;
return;
break;
default:
break;
}
}
break;
case Zae5C_87:;
if (Z221.Y0 == Zsl7KDB_1) {
Z217->Y0 = Zsl7KDB_4;
Z217->U_1.V_4.Y4 = ODD(Z221.U_1.V_1.Y1);
return;
}
break;
case Zae5C_88:;
if (Z221.Y0 == Zsl7KDB_1) {
*Z217 = Z221;
return;
} else if (IN(Z221.Y0, Z209)) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = ORD(Z221.U_1.V_5.Y5);
return;
} else if (Z221.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z223->U_1.V_6.Y5.Y4;
return;
}
break;
case Zae5C_89:;
case Zae5C_93:;
if (Z221.Y0 == Zsl7KDB_12) {
Z228 = Zq7SFB_24((Zae5C_57)Z221.U_1.V_10.Y10);
if (Z228 != Zq7SFB_13) {
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = Z228;
return;
}
}
break;
case Zae5C_90:;
if (Z221.Y0 == Zsl7KDB_3) {
Z229 = Z221.U_1.V_3.Y3;
Z217->Y0 = Zsl7KDB_1;
Z217->U_1.V_1.Y1 = TRUNC(Z229);
return;
}
break;
case Zae5C_91:;
if (Z220->U_1.V_88.Y87.Y5->U_1.V_1.Y0 != Zq0A4_104) {
Z219(Z220->U_1.V_88.Y87.Y5->U_1.V_105.Y104.Y2, &Z222);
if (Z221.Y0 == Zsl7KDB_12 && Z222.Y0 == Zsl7KDB_1) {
Z225 = (Zae5C_57)Z221.U_1.V_10.Y10;
if (Z225->U_1.V_1.Y0 == Zae5C_47) {
Z225 = Z225->U_1.V_47.Y46.Y4;
}
switch (Z225->U_1.V_1.Y0) {
case Zsl7KDB_5:;
Z217->Y0 = Zsl7KDB_5;
Z217->U_1.V_5.Y5 = VAL(CHAR, Z222.U_1.V_1.Y1);
return;
break;
case Zae5C_18:;
case Zae5C_19:;
case Zae5C_20:;
case Zae5C_21:;
*Z217 = Z222;
return;
break;
case Zae5C_41:;
Z223 = Zae5C_170(Z225->U_1.V_41.Y40.Y3, (SHORTCARD)Z222.U_1.V_1.Y1);
if (Z223 != Zae5C_99) {
Z217->U_1.V_8.Y8 = (ADDRESS)Z223;
Z217->Y0 = Zsl7KDB_9;
return;
}
break;
default:
break;
}
}
}
break;
default:
break;
}
}
break;
case Zq0A4_89:;
Z219(Z220->U_1.V_89.Y88.Y5, Z217);
return;
break;
case Zq0A4_90:;
Z219(Z220->U_1.V_90.Y89.Y4, Z217);
return;
break;
case Zq0A4_99:;
Z217->Y0 = Zsl7KDB_8;
Z217->U_1.V_7.Y7 = 0X0L;
return;
break;
case Zq0A4_101:;
Z219(Z220->U_1.V_101.Y100.Y1, Z217);
Z219(Z220->U_1.V_101.Y100.Y2, &Z222);
switch (Z222.Y0) {
case Zsl7KDB_1:;
if (Z222.U_1.V_1.Y1 >= 0 && Z222.U_1.V_1.Y1 <= Zq7SFB_8) {
INCL(Z217->U_1.V_7.Y7, Z222.U_1.V_1.Y1);
return;
}
break;
case Zsl7KDB_5:;
case Zsl7KDB_6:;
if (ORD(Z222.U_1.V_5.Y5) <= Zq7SFB_8) {
INCL(Z217->U_1.V_7.Y7, ORD(Z222.U_1.V_5.Y5));
return;
}
break;
case Zsl7KDB_9:;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
if (Z224->U_1.V_6.Y5.Y4 <= Zq7SFB_8) {
INCL(Z217->U_1.V_7.Y7, Z224->U_1.V_6.Y5.Y4);
return;
}
break;
default:
break;
}
break;
case Zq0A4_102:;
Z219(Z220->U_1.V_102.Y101.Y1, Z217);
Z219(Z220->U_1.V_102.Y101.Y2, &Z221);
Z219(Z220->U_1.V_102.Y101.Y3, &Z222);
if (Z221.Y0 == Zsl7KDB_1 && Z222.Y0 == Zsl7KDB_1) {
if (Z221.U_1.V_1.Y1 >= 0 && Z222.U_1.V_1.Y1 <= Zq7SFB_8) {
{
LONGCARD B_1 = (CARDINAL)Z221.U_1.V_1.Y1, B_2 = (CARDINAL)Z222.U_1.V_1.Y1;

if (B_1 <= B_2)
for (Z227 = B_1;; Z227 += 1) {
INCL(Z217->U_1.V_7.Y7, Z227);
if (Z227 >= B_2) break;
}
}
return;
}
} else if (IN(Z221.Y0, Z209) && IN(Z222.Y0, Z209)) {
if (ORD(Z222.U_1.V_5.Y5) <= Zq7SFB_8) {
{
LONGCARD B_3 = ORD(Z221.U_1.V_5.Y5), B_4 = ORD(Z222.U_1.V_5.Y5);

if (B_3 <= B_4)
for (Z227 = B_3;; Z227 += 1) {
INCL(Z217->U_1.V_7.Y7, Z227);
if (Z227 >= B_4) break;
}
}
return;
}
} else if (Z221.Y0 == Zsl7KDB_9 && Z222.Y0 == Zsl7KDB_9) {
Z223 = (Zae5C_57)Z221.U_1.V_8.Y8;
Z224 = (Zae5C_57)Z222.U_1.V_8.Y8;
if (Z224->U_1.V_6.Y5.Y4 <= Zq7SFB_8) {
{
LONGCARD B_5 = Z223->U_1.V_6.Y5.Y4, B_6 = Z224->U_1.V_6.Y5.Y4;

if (B_5 <= B_6)
for (Z227 = B_5;; Z227 += 1) {
INCL(Z217->U_1.V_7.Y7, Z227);
if (Z227 >= B_6) break;
}
}
return;
}
}
break;
case Zq0A4_104:;
break;
case Zq0A4_105:;
Z219(Z220->U_1.V_105.Y104.Y1, Z217);
return;
break;
default:
break;
}
Z217->Y0 = Zsl7KDB_0;
}

ADDRESS Zsl7KDB_32
# ifdef HAVE_ARGS
(Zsl7KDB_13 Z217)
# else
(Z217)
Zsl7KDB_13 Z217;
# endif
{
switch (Z217.Y0) {
case Zsl7KDB_1:;
return (ADDRESS)Zae5C_120;
break;
case Zsl7KDB_3:;
return (ADDRESS)Zae5C_111;
break;
case Zsl7KDB_4:;
return (ADDRESS)Zae5C_113;
break;
case Zsl7KDB_5:;
return (ADDRESS)Zae5C_114;
break;
case Zsl7KDB_6:;
return (ADDRESS)Zae5C_123;
break;
case Zsl7KDB_7:;
return (ADDRESS)Zae5C_122;
break;
case Zsl7KDB_8:;
return (ADDRESS)Zae5C_115;
break;
case Zsl7KDB_9:;
return (ADDRESS)Zae5C_161((Zae5C_57)Z217.U_1.V_8.Y8);
break;
case Zsl7KDB_10:;
return (ADDRESS)Zae5C_121;
break;
case Zsl7KDB_12:;
return Z217.U_1.V_10.Y10;
break;
default:
return (ADDRESS)Zae5C_120;
break;
}
}

LONGINT Zsl7KDB_33
# ifdef HAVE_ARGS
(Zsl7KDB_13 Z217)
# else
(Z217)
Zsl7KDB_13 Z217;
# endif
{
Zae5C_59 Z232;

switch (Z217.Y0) {
case Zsl7KDB_1:;
return Z217.U_1.V_1.Y1;
break;
case Zsl7KDB_4:;
if (Z217.U_1.V_4.Y4) {
return Z213;
} else {
return Z212;
}
break;
case Zsl7KDB_5:;
return ORD(Z217.U_1.V_5.Y5);
break;
case Zsl7KDB_6:;
return ORD(Z217.U_1.V_5.Y5);
break;
case Zsl7KDB_9:;
Z232 = (Zae5C_57)Z217.U_1.V_8.Y8;
return Z232->U_1.V_6.Y5.Y4;
break;
default:
return 0;
break;
}
}

void Zsl7KDB_34
# ifdef HAVE_ARGS
(ZfM_3 Z308, Zsl7KDB_13 Z217)
# else
(Z308, Z217)
ZfM_3 Z308;
Zsl7KDB_13 Z217;
# endif
{
Zae5C_59 Z232;

{
register Zsl7KDB_13 *W_2 = &Z217;

switch (W_2->Y0) {
case Zsl7KDB_0:;
ZfM_29(Z308, (STRING)"NoValue", 7L);
break;
case Zsl7KDB_1:;
ZfM_25(Z308, W_2->U_1.V_1.Y1, 0L);
break;
case Zsl7KDB_3:;
ZfM_26(Z308, (REAL)W_2->U_1.V_3.Y3, 1L, 10L, 1L);
break;
case Zsl7KDB_4:;
ZfM_27(Z308, W_2->U_1.V_4.Y4);
break;
case Zsl7KDB_5:;
ZfM_24(Z308, W_2->U_1.V_5.Y5);
break;
case Zsl7KDB_6:;
ZfM_24(Z308, W_2->U_1.V_5.Y5);
break;
case Zsl7KDB_7:;
Zp1PEAFi_6(Z308, W_2->U_1.V_6.Y6);
break;
case Zsl7KDB_8:;
ZfM_28(Z308, (LONGCARD)(INTEGER)W_2->U_1.V_7.Y7, 8L, 16L);
break;
case Zsl7KDB_9:;
Z232 = (Zae5C_57)W_2->U_1.V_8.Y8;
ZfM_25(Z308, (LONGINT)Z232->U_1.V_6.Y5.Y4, 0L);
break;
case Zsl7KDB_10:;
ZfM_29(Z308, (STRING)"NIL", 3L);
break;
case Zsl7KDB_11:;
ZfM_29(Z308, (STRING)"<StdProc>", 9L);
break;
case Zsl7KDB_12:;
ZfM_29(Z308, (STRING)"<Type>", 6L);
break;
}
}
}

void BEGIN_Values ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_StringM ();
BEGIN_IO ();
BEGIN_StringM ();
BEGIN_Strings ();
BEGIN_Tree ();
BEGIN_Defs ();
BEGIN_Types ();
BEGIN_Defs ();
BEGIN_Tree ();
BEGIN_Strings ();
BEGIN_IO ();

{
register Zsl7KDB_13 *W_3 = &Zsl7KDB_14;

W_3->Y0 = Zsl7KDB_0;
}
{
register Zsl7KDB_13 *W_4 = &Zsl7KDB_15;

W_4->Y0 = Zsl7KDB_10;
}
{
register Zsl7KDB_13 *W_5 = &Zsl7KDB_16;

W_5->Y0 = Zsl7KDB_4;
W_5->U_1.V_4.Y4 = TRUE;
}
{
register Zsl7KDB_13 *W_6 = &Zsl7KDB_17;

W_6->Y0 = Zsl7KDB_4;
W_6->U_1.V_4.Y4 = FALSE;
}
{
register Zsl7KDB_13 *W_7 = &Zsl7KDB_18;

W_7->Y0 = Zsl7KDB_5;
W_7->U_1.V_5.Y5 = Zq7SFB_6;
}
{
register Zsl7KDB_13 *W_8 = &Zsl7KDB_19;

W_8->Y0 = Zsl7KDB_5;
W_8->U_1.V_5.Y5 = Zq7SFB_7;
}
{
register Zsl7KDB_13 *W_9 = &Zsl7KDB_20;

W_9->Y0 = Zsl7KDB_1;
W_9->U_1.V_1.Y1 = 0;
}
{
register Zsl7KDB_13 *W_10 = &Zsl7KDB_21;

W_10->Y0 = Zsl7KDB_1;
W_10->U_1.V_1.Y1 = Zq7SFB_0;
}
{
register Zsl7KDB_13 *W_11 = &Zsl7KDB_22;

W_11->Y0 = Zsl7KDB_1;
W_11->U_1.V_1.Y1 = Zq7SFB_1;
}
{
register Zsl7KDB_13 *W_12 = &Zsl7KDB_23;

W_12->Y0 = Zsl7KDB_1;
W_12->U_1.V_1.Y1 = Zq7SFB_2;
}
{
register Zsl7KDB_13 *W_13 = &Zsl7KDB_24;

W_13->Y0 = Zsl7KDB_1;
W_13->U_1.V_1.Y1 = Zq7SFB_3;
}
{
register Zsl7KDB_13 *W_14 = &Zsl7KDB_25;

W_14->Y0 = Zsl7KDB_1;
W_14->U_1.V_1.Y1 = Zq7SFB_4;
}
Zsl7KDB_26 = Zsl7KDB_14;
{
register Zsl7KDB_13 *W_15 = &Zsl7KDB_27;

W_15->Y0 = Zsl7KDB_3;
W_15->U_1.V_3.Y3 = Zq7SFB_9;
}
{
register Zsl7KDB_13 *W_16 = &Zsl7KDB_28;

W_16->Y0 = Zsl7KDB_3;
W_16->U_1.V_3.Y3 = Zq7SFB_10;
}
{
register Zsl7KDB_13 *W_17 = &Zsl7KDB_29;

W_17->Y0 = Zsl7KDB_3;
W_17->U_1.V_3.Y3 = Zq7SFB_11;
}
{
register Zsl7KDB_13 *W_18 = &Zsl7KDB_30;

W_18->Y0 = Zsl7KDB_3;
W_18->U_1.V_3.Y3 = Zq7SFB_12;
}
}
