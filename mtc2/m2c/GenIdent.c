#include "SYSTEM_.h"

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Base
#include "Base.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_GenIdent
#include "GenIdent.h"
#endif


static CARDINAL Z137, Z138, Z139, Z140, Z141, Z142, Z143, Z144, Z145, Z146, Z147;
static Zfb3DLQ_0 Z148, Z149;
static Zp1PEAFD_2 Z150;
#define Z155	(ORD('z') - ORD('0') + 1)
static Zfb3DLQ_0 Z163 ARGS ((CHAR Z184, CARDINAL Z154, Zfb3DLQ_0 Z153));
static Zfb3DLQ_0 Z169 ARGS ((CHAR Z184, CARDINAL Z154));
static Zfb3DLQ_0 Z166 ARGS ((Zfb3DLQ_0 Z153, CARDINAL Z154));

Zfb3DLQ_0 ZdaDlb3DL_0
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z152, Zfb3DLQ_0 Z153, CARDINAL Z154)
# else
(Z152, Z153, Z154)
Zfb3DLQ_0 Z152, Z153;
CARDINAL Z154;
# endif
{
Zp1PEAFD_2 Z156, Z157, Z150;
CHAR Z158, Z159;
CARDINAL Z160, Z161;

Zfb3DLQ_3(Z152, &Z157);
if (ZfXEB_3('u') && Z152 != Z148) {
Zp1PEAFD_4(&Z156);
Zp1PEAFD_6(&Z156, 'Z');
Z158 = 'h';
{
LONGCARD B_1 = 1, B_2 = Zp1PEAFD_7(&Z157);

if (B_1 <= B_2)
for (Z160 = B_1;; Z160 += 1) {
Z159 = Zp1PEAFD_12(&Z157, (Zp1PEAFD_1)Z160);
Z161 = ORD(Z158) + ORD(Z159);
while (Z161 > ORD('z')) {
DEC1(Z161, Z155);
}
switch (CHR(Z161)) {
case '0':;
case '1':;
case '2':;
case '3':;
case '4':;
case '5':;
case '6':;
case '7':;
case '8':;
case '9':;
case 'A':;
case 'B':;
case 'C':;
case 'D':;
case 'E':;
case 'F':;
case 'G':;
case 'H':;
case 'I':;
case 'J':;
case 'K':;
case 'L':;
case 'M':;
case 'N':;
case 'O':;
case 'P':;
case 'Q':;
case 'R':;
case 'S':;
case 'T':;
case 'U':;
case 'V':;
case 'W':;
case 'X':;
case 'Y':;
case 'Z':;
case 'a':;
case 'b':;
case 'c':;
case 'd':;
case 'e':;
case 'f':;
case 'g':;
case 'h':;
case 'i':;
case 'j':;
case 'k':;
case 'l':;
case 'm':;
case 'n':;
case 'o':;
case 'p':;
case 'q':;
case 'r':;
case 's':;
case 't':;
case 'u':;
case 'v':;
case 'w':;
case 'x':;
case 'y':;
case 'z':;
break;
default:
INC1(Z161, 7);
break;
}
Zp1PEAFD_6(&Z156, CHR(Z161));
Z158 = Z159;
if (Z160 >= B_2) break;
}
}
Zp1PEAFD_6(&Z156, '_');
Zp1PEAFD_18((LONGINT)Z154, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
return Zfb3DLQ_2(&Z156);
} else {
Zp1PEAFD_6(&Z157, '_');
Zfb3DLQ_3(Z153, &Z150);
Zp1PEAFD_5(&Z157, &Z150);
return Zfb3DLQ_2(&Z157);
}
}

Zfb3DLQ_0 ZdaDlb3DL_1
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z153)
# else
(Z153)
Zfb3DLQ_0 Z153;
# endif
{
return Z163('C', 0L, Z153);
}

Zfb3DLQ_0 ZdaDlb3DL_2
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z153)
# else
(Z153)
Zfb3DLQ_0 Z153;
# endif
{
Zp1PEAFD_2 Z156, Z150;

INC(Z137);
if (ZfXEB_3('u')) {
Zp1PEAFD_4(&Z156);
Zp1PEAFD_6(&Z156, 'Y');
Zp1PEAFD_18((LONGINT)Z137, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
Zp1PEAFD_6(&Z156, '_');
Zp1PEAFD_18((LONGINT)Z153, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
return Zfb3DLQ_2(&Z156);
} else {
return Z163('C', Z137, Z153);
}
}

Zfb3DLQ_0 ZdaDlb3DL_3
 ARGS ((void))
{
INC(Z138);
return Z166(Z149, Z138);
}

Zfb3DLQ_0 ZdaDlb3DL_4
# ifdef HAVE_ARGS
(CHAR Z168, CARDINAL Z154)
# else
(Z168, Z154)
CHAR Z168;
CARDINAL Z154;
# endif
{
return Z169(Z168, Z154);
}

Zfb3DLQ_0 ZdaDlb3DL_5
 ARGS ((void))
{
INC(Z139);
return Z169('O', Z139);
}

Zfb3DLQ_0 ZdaDlb3DL_6
 ARGS ((void))
{
INC(Z140);
return Z169('W', Z140);
}

Zfb3DLQ_0 ZdaDlb3DL_7
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z152, CARDINAL Z154)
# else
(Z152, Z154)
Zfb3DLQ_0 Z152;
CARDINAL Z154;
# endif
{
Zp1PEAFD_2 Z173;

Zfb3DLQ_3(Z152, &Z173);
if (Zp1PEAFD_7(&Z173) > 1) {
return Z166(Z152, Z154);
} else {
Zp1PEAFD_6(&Z173, '_');
return Z166(Zfb3DLQ_2(&Z173), Z154);
}
}

Zfb3DLQ_0 ZdaDlb3DL_8
 ARGS ((void))
{
INC(Z141);
return Z169('S', Z141);
}

Zfb3DLQ_0 ZdaDlb3DL_9
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z153)
# else
(Z153)
Zfb3DLQ_0 Z153;
# endif
{
INC(Z142);
return Z163('G', Z142, Z153);
}

Zfb3DLQ_0 ZdaDlb3DL_10
 ARGS ((void))
{
INC(Z143);
return Z169('L', Z143);
}

Zfb3DLQ_0 ZdaDlb3DL_11
 ARGS ((void))
{
INC(Z144);
return Z169('B', Z144);
}

Zfb3DLQ_0 ZdaDlb3DL_12
 ARGS ((void))
{
INC(Z145);
return Z169('R', Z145);
}

Zfb3DLQ_0 ZdaDlb3DL_13
 ARGS ((void))
{
INC(Z146);
return Z169('X', Z146);
}

Zfb3DLQ_0 ZdaDlb3DL_14
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z181)
# else
(Z181)
Zfb3DLQ_0 Z181;
# endif
{
Zp1PEAFD_2 Z156, Z157;
Zp1PEAFD_1 Z182;

Zfb3DLQ_3(Z181, &Z157);
Z182 = Zp1PEAFD_7(&Z157);
do {
DEC(Z182);
} while (!(Zp1PEAFD_12(&Z157, Z182) == '_'));
if (ZfXEB_3('u')) {
DEC(Z182);
}
Zp1PEAFD_11(&Z157, Z182 + 1, (Zp1PEAFD_1)Zp1PEAFD_7(&Z157), &Z156);
return Zfb3DLQ_2(&Z156);
}

Zfb3DLQ_0 ZdaDlb3DL_15
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z153)
# else
(Z153)
Zfb3DLQ_0 Z153;
# endif
{
INC(Z147);
return Z163('S', Z147, Z153);
}

static Zfb3DLQ_0 Z163
# ifdef HAVE_ARGS
(CHAR Z184, CARDINAL Z154, Zfb3DLQ_0 Z153)
# else
(Z184, Z154, Z153)
CHAR Z184;
CARDINAL Z154;
Zfb3DLQ_0 Z153;
# endif
{
Zp1PEAFD_2 Z156, Z150;

Zp1PEAFD_4(&Z156);
Zp1PEAFD_6(&Z156, Z184);
Zp1PEAFD_6(&Z156, '_');
Zp1PEAFD_18((LONGINT)Z154, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
Zp1PEAFD_6(&Z156, '_');
Zfb3DLQ_3(Z153, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
return Zfb3DLQ_2(&Z156);
}

static Zfb3DLQ_0 Z169
# ifdef HAVE_ARGS
(CHAR Z184, CARDINAL Z154)
# else
(Z184, Z154)
CHAR Z184;
CARDINAL Z154;
# endif
{
Zp1PEAFD_2 Z156, Z150;

Zp1PEAFD_4(&Z156);
Zp1PEAFD_6(&Z156, Z184);
Zp1PEAFD_6(&Z156, '_');
Zp1PEAFD_18((LONGINT)Z154, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
return Zfb3DLQ_2(&Z156);
}

static Zfb3DLQ_0 Z166
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z153, CARDINAL Z154)
# else
(Z153, Z154)
Zfb3DLQ_0 Z153;
CARDINAL Z154;
# endif
{
Zp1PEAFD_2 Z156, Z150;

Zp1PEAFD_4(&Z156);
Zfb3DLQ_3(Z153, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
Zp1PEAFD_6(&Z156, '_');
Zp1PEAFD_18((LONGINT)Z154, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
return Zfb3DLQ_2(&Z156);
}

Zfb3DLQ_0 ZdaDlb3DL_16
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z153, CARDINAL Z154)
# else
(Z153, Z154)
Zfb3DLQ_0 Z153;
CARDINAL Z154;
# endif
{
Zp1PEAFD_2 Z156, Z150;

if (ZfXEB_3('u')) {
Zp1PEAFD_4(&Z156);
Zp1PEAFD_6(&Z156, 'Z');
Zp1PEAFD_18((LONGINT)Z154, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
return Zfb3DLQ_2(&Z156);
} else {
return Z153;
}
}

Zfb3DLQ_0 ZdaDlb3DL_17
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z153, CARDINAL Z154)
# else
(Z153, Z154)
Zfb3DLQ_0 Z153;
CARDINAL Z154;
# endif
{
Zp1PEAFD_2 Z156, Z150;

if (ZfXEB_3('u')) {
Zp1PEAFD_4(&Z156);
Zp1PEAFD_6(&Z156, 'Y');
Zp1PEAFD_18((LONGINT)Z154, &Z150);
Zp1PEAFD_5(&Z156, &Z150);
return Zfb3DLQ_2(&Z156);
} else {
return Z153;
}
}

void BEGIN_GenIdent ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_Idents ();
BEGIN_Strings ();
BEGIN_Base ();
BEGIN_IO ();

Z137 = 0;
Z138 = 0;
Z139 = 0;
Z140 = 0;
Z141 = 0;
Z142 = 0;
Z143 = 0;
Z144 = 0;
Z145 = 0;
Z146 = 0;
Z147 = 0;
Zp1PEAFD_13((STRING)"EXIT", 4L, &Z150);
Z149 = Zfb3DLQ_2(&Z150);
Zp1PEAFD_13((STRING)"Arguments", 9L, &Z150);
Z148 = Zfb3DLQ_2(&Z150);
}
