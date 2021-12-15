#include "SYSTEM_.h"

#ifndef DEFINITION_Base
#include "Base.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Defs
#include "Defs.h"
#endif

#ifndef DEFINITION_Values
#include "Values.h"
#endif

#ifndef DEFINITION_Code
#include "Code.h"
#endif

#ifndef DEFINITION_Defs
#include "Defs.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Types
#include "Types.h"
#endif

REAL Zq7SFB_9, Zq7SFB_10;
LONGREAL Zq7SFB_11, Zq7SFB_12;

static BOOLEAN Z223 ARGS ((Zae5C_60 Z218, Zae5C_60 Z219));

Zae5C_60 Zq7SFB_22
# ifdef HAVE_ARGS
(SHORTCARD Z217, Zae5C_60 Z218, Zae5C_60 Z219)
# else
(Z217, Z218, Z219)
SHORTCARD Z217;
Zae5C_60 Z218, Z219;
# endif
{
Zae5C_60 Z220;

Z220 = Zae5C_100;
if (Z218->U_1.V_1.Y0 == Zae5C_47) {
Z218 = Z218->U_1.V_47.Y46.Y4;
}
if (Z219->U_1.V_1.Y0 == Zae5C_47) {
Z219 = Z219->U_1.V_47.Y46.Y4;
}
switch (Z217) {
case Zq0A4_163:;
case Zq0A4_170:;
case Zq0A4_168:;
case Zq0A4_169:;
case Zq0A4_171:;
case Zq0A4_172:;
case Zq0A4_173:;
case Zq0A4_178:;
case Zq0A4_175:;
case Zq0A4_177:;
Z220 = Zae5C_113;
break;
case Zq0A4_164:;
case Zq0A4_165:;
case Zq0A4_166:;
case Zq0A4_167:;
case Zq0A4_174:;
case Zq0A4_176:;
if (Z223(Z219, Z218)) {
Z220 = Z218;
} else if (Z223(Z218, Z219)) {
Z220 = Z219;
}
break;
}
return Z220;
}

static BOOLEAN Z223
# ifdef HAVE_ARGS
(Zae5C_60 Z218, Zae5C_60 Z219)
# else
(Z218, Z219)
Zae5C_60 Z218, Z219;
# endif
{
BOOLEAN Z220;

Z220 = FALSE;
if (Z218 == Z219) {
Z220 = TRUE;
} else {
switch (Z218->U_1.V_1.Y0) {
case Zae5C_31:;
Z220 = Z219 == Zae5C_109 || Z219 == Zae5C_110 || Z219 == Zae5C_107 || Z219 == Zae5C_108 || Z219 == Zae5C_119;
break;
case Zae5C_18:;
Z220 = Z219 == Zae5C_108;
break;
case Zae5C_20:;
Z220 = Z219 == Zae5C_110 || Z219 == Zae5C_119;
break;
case Zae5C_21:;
Z220 = Z219 == Zae5C_119;
break;
case Zae5C_22:;
Z220 = Z219 == Zae5C_112;
break;
case Zae5C_32:;
Z220 = Z219 == Zae5C_119;
break;
case Zae5C_26:;
Z220 = Z219->U_1.V_1.Y0 == Zae5C_46;
break;
default:
break;
}
}
return Z220;
}

Zae5C_60 Zq7SFB_23
# ifdef HAVE_ARGS
(Zae5C_60 Z225, Zae5C_63 Z226)
# else
(Z225, Z226)
Zae5C_60 Z225;
Zae5C_63 Z226;
# endif
{
Zae5C_60 Z227;
BOOLEAN Z228;

switch (Z225->U_1.V_36.Y35.Y1) {
case Zae5C_85:;
case Zae5C_86:;
case Zae5C_91:;
Zae5C_168(Z226, &Z228, &Z227);
return Z227;
break;
case Zae5C_75:;
Zae5C_168(Z226, &Z228, &Z227);
if (Z227->U_1.V_1.Y0 == Zae5C_47) {
Z227 = Z227->U_1.V_47.Y46.Y4;
}
return Z227;
break;
case Zae5C_76:;
case Zae5C_77:;
return Zae5C_114;
break;
case Zae5C_88:;
case Zae5C_90:;
return Zae5C_110;
break;
case Zae5C_89:;
case Zae5C_93:;
return Zae5C_120;
break;
case Zae5C_80:;
return Zae5C_111;
break;
case Zae5C_82:;
Zae5C_168(Z226, &Z228, &Z227);
return Zae5C_162(Z227);
break;
case Zae5C_87:;
return Zae5C_113;
break;
case Zae5C_92:;
return Zae5C_119;
break;
default:
return Zae5C_124;
break;
}
}

CARDINAL Zq7SFB_24
# ifdef HAVE_ARGS
(Zae5C_60 Z225)
# else
(Z225)
Zae5C_60 Z225;
# endif
{
if (Z225->U_1.V_1.Y0 == Zae5C_47) {
Z225 = Z225->U_1.V_47.Y46.Y4;
}
switch (Z225->U_1.V_1.Y0) {
case Zae5C_18:;
return Zq7SFB_15;
break;
case Zae5C_19:;
return Zq7SFB_16;
break;
case Zae5C_20:;
return Zq7SFB_17;
break;
case Zae5C_21:;
return Zq7SFB_18;
break;
case Zae5C_22:;
return Zq7SFB_19;
break;
case Zae5C_23:;
return Zq7SFB_20;
break;
case Zae5C_24:;
return Zq7SFB_14;
break;
case Zae5C_25:;
return Zq7SFB_14;
break;
case Zae5C_26:;
return Zq7SFB_18;
break;
case Zae5C_27:;
return Zq7SFB_21;
break;
case Zae5C_28:;
return Zq7SFB_14;
break;
case Zae5C_30:;
return Zq7SFB_21;
break;
case Zae5C_39:;
return Zq7SFB_21;
break;
case Zae5C_40:;
return Zq7SFB_13;
break;
case Zae5C_41:;
if (Z225->U_1.V_41.Y40.Y2 <= ORD(Zq7SFB_7)) {
return Zq7SFB_14;
} else {
return Zq7SFB_17;
}
break;
case Zae5C_42:;
return Zq7SFB_21;
break;
case Zae5C_43:;
return Zq7SFB_21;
break;
case Zae5C_44:;
return Zq7SFB_13;
break;
case Zae5C_46:;
return Zq7SFB_18;
break;
default:
return Zq7SFB_13;
break;
}
}

void Zq7SFB_25
# ifdef HAVE_ARGS
(Zae5C_60 Z225, Zsl7KDB_13 *Z244)
# else
(Z225, Z244)
Zae5C_60 Z225;
Zsl7KDB_13 *Z244;
# endif
{
switch (Z225->U_1.V_1.Y0) {
case Zae5C_18:;
*Z244 = Zsl7KDB_21;
break;
case Zae5C_19:;
*Z244 = Zsl7KDB_23;
break;
case Zae5C_20:;
*Z244 = Zsl7KDB_20;
break;
case Zae5C_21:;
*Z244 = Zsl7KDB_20;
break;
case Zae5C_22:;
*Z244 = Zsl7KDB_27;
break;
case Zae5C_23:;
*Z244 = Zsl7KDB_29;
break;
case Zae5C_24:;
*Z244 = Zsl7KDB_17;
break;
case Zae5C_25:;
*Z244 = Zsl7KDB_18;
break;
case Zae5C_41:;
Z244->Y0 = Zsl7KDB_9;
Z244->U_1.V_8.Y8 = (ADDRESS)Zae5C_170(Z225->U_1.V_41.Y40.Y3, 0);
break;
case Zae5C_47:;
*Z244 = Z225->U_1.V_47.Y46.Y5;
break;
default:
*Z244 = Zsl7KDB_14;
break;
}
}

void Zq7SFB_26
# ifdef HAVE_ARGS
(Zae5C_60 Z225, Zsl7KDB_13 *Z248)
# else
(Z225, Z248)
Zae5C_60 Z225;
Zsl7KDB_13 *Z248;
# endif
{
switch (Z225->U_1.V_1.Y0) {
case Zae5C_18:;
*Z248 = Zsl7KDB_22;
break;
case Zae5C_19:;
*Z248 = Zsl7KDB_24;
break;
case Zae5C_20:;
*Z248 = Zsl7KDB_25;
break;
case Zae5C_21:;
*Z248 = Zsl7KDB_26;
break;
case Zae5C_22:;
*Z248 = Zsl7KDB_28;
break;
case Zae5C_23:;
*Z248 = Zsl7KDB_30;
break;
case Zae5C_24:;
*Z248 = Zsl7KDB_16;
break;
case Zae5C_25:;
*Z248 = Zsl7KDB_19;
break;
case Zae5C_41:;
{
register Zae5C_225 *W_1 = &Z225->U_1.V_41.Y40;

Z248->Y0 = Zsl7KDB_9;
Z248->U_1.V_8.Y8 = (ADDRESS)Zae5C_170(W_1->Y3, W_1->Y2);
}
break;
case Zae5C_47:;
*Z248 = Z225->U_1.V_47.Y46.Y6;
break;
default:
*Z248 = Zsl7KDB_14;
break;
}
}

BOOLEAN Zq7SFB_27
# ifdef HAVE_ARGS
(SHORTCARD Z217, Zae5C_60 Z218, Zae5C_60 Z219)
# else
(Z217, Z218, Z219)
SHORTCARD Z217;
Zae5C_60 Z218, Z219;
# endif
{
if (Z218->U_1.V_1.Y0 == Zae5C_47) {
Z218 = Z218->U_1.V_47.Y46.Y4;
}
if (Z219->U_1.V_1.Y0 == Zae5C_47) {
Z219 = Z219->U_1.V_47.Y46.Y4;
}
if (Z218->U_1.V_1.Y0 == Zae5C_39 && Z218->U_1.V_39.Y38.Y2 != Zae5C_100 && Z219->U_1.V_1.Y0 == Zae5C_39 && Z219->U_1.V_39.Y38.Y2 != Zae5C_100) {
Z218 = Z218->U_1.V_39.Y38.Y2;
Z219 = Z219->U_1.V_39.Y38.Y2;
}
switch (Z217) {
case ZggD3_22:;
return Z218 == Zae5C_119 && Z219 != Zae5C_119 || Z219 == Zae5C_119 && Z218 != Zae5C_119 || Z218->U_1.V_1.Y0 == Zae5C_39 && Z219->U_1.V_1.Y0 != Zae5C_39 || Z219->U_1.V_1.Y0 == Zae5C_39 && Z218->U_1.V_1.Y0 != Zae5C_39;
break;
case ZggD3_24:;
return Z218 != Z219 && ZfXEB_3('c');
break;
case ZggD3_23:;
if (Z219 == Zae5C_120 && (Z218 == Zae5C_109 || Z218 == Zae5C_107) || Z219 == Zae5C_123 && Z218 == Zae5C_114 || Z219 == Zae5C_111 && Z218 == Zae5C_112) {
return FALSE;
} else {
return Z218 != Z219 && ZfXEB_3('c');
}
break;
default:
return FALSE;
break;
}
}

BOOLEAN Zq7SFB_28
# ifdef HAVE_ARGS
(Zae5C_60 Z218, Zae5C_60 Z219)
# else
(Z218, Z219)
Zae5C_60 Z218, Z219;
# endif
{
BOOLEAN Z220;
CARDINAL Z251;

Z220 = FALSE;
if (Z218 == Z219) {
Z220 = TRUE;
} else if (Z218->U_1.V_1.Y0 == Zae5C_47) {
Z220 = Zq7SFB_28(Z218->U_1.V_47.Y46.Y4, Z219);
} else if (Z219->U_1.V_1.Y0 == Zae5C_47) {
Z220 = Zq7SFB_28(Z218, Z219->U_1.V_47.Y46.Y4);
} else if (Z218->U_1.V_1.Y0 == Zae5C_39 && Z219->U_1.V_1.Y0 == Zae5C_32) {
Z220 = TRUE;
} else if (Z218->U_1.V_1.Y0 == Zae5C_39 && Z218->U_1.V_39.Y38.Y2 != Zae5C_100) {
Z220 = Zq7SFB_28(Z218->U_1.V_39.Y38.Y2, Z219);
} else if (Z219->U_1.V_1.Y0 == Zae5C_39 && Z219->U_1.V_39.Y38.Y2 != Zae5C_100) {
Z220 = Zq7SFB_28(Z218, Z219->U_1.V_39.Y38.Y2);
} else {
Z251 = Z219->U_1.V_1.Y0;
switch (Z218->U_1.V_1.Y0) {
case Zae5C_18:;
case Zae5C_19:;
Z220 = Z251 == Zae5C_31 || Z251 == Zae5C_20 || Z251 == Zae5C_21 || Z251 == Zae5C_18 || Z251 == Zae5C_19;
break;
case Zae5C_20:;
case Zae5C_21:;
Z220 = Z251 == Zae5C_31 || Z251 == Zae5C_30 || Z251 == Zae5C_20 || Z251 == Zae5C_21 || Z251 == Zae5C_18 || Z251 == Zae5C_19;
break;
case Zae5C_42:;
Z220 = Z251 == Zae5C_32 || Z251 == Zae5C_30;
break;
case Zae5C_30:;
Z220 = Z251 == Zae5C_32 || Z251 == Zae5C_42 || Z251 == Zae5C_20 || Z251 == Zae5C_21;
break;
case Zae5C_22:;
case Zae5C_23:;
Z220 = Z251 == Zae5C_22 || Z251 == Zae5C_23;
break;
case Zae5C_40:;
Z220 = Z218->U_1.V_40.Y39.Y4->U_1.V_1.Y0 == Zae5C_25 && (Z251 == Zae5C_33 || Z251 == Zae5C_34);
break;
case Zae5C_25:;
Z220 = Z251 == Zae5C_34;
break;
case Zae5C_43:;
case Zae5C_27:;
Z220 = Z251 == Zae5C_43 || Z251 == Zae5C_27;
break;
default:
break;
}
}
if (!Z220) {
Zae5C_313((ZDz6VQCC_4)ZfM_1, Z218);
Zae5C_313((ZDz6VQCC_4)ZfM_1, Z219);
}
return Z220;
}

void BEGIN_Types ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Values ();
BEGIN_Defs ();
BEGIN_Base ();
BEGIN_Tree ();
BEGIN_Defs ();
BEGIN_Values ();
BEGIN_Code ();
BEGIN_Defs ();
BEGIN_IO ();

Zq7SFB_9 = 1.40129846432481707E-45;
Zq7SFB_10 = 3.40282346638528860E+38;
Zq7SFB_11 = 4.94065645841246544E-324;
Zq7SFB_12 = 1.79769313486231470E+308;
}
