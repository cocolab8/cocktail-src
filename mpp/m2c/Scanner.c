#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

Zpky9FDA_0 Zpky9FDA_1;

#define Z117	'\0'
#define Z118	'\t'
#define Z119	'\n'
static CHAR Z120, Z121;

void Zpky9FDA_2
 ARGS ((void))
{
Z120 = ZfM_7((ZDz6VQCC_4)ZfM_0);
Z121 = Z119;
}

void Zpky9FDA_3
 ARGS ((void))
{
}

CARDINAL Zpky9FDA_4
 ARGS ((void))
{
for (;;) {
if (Z121 == Z117) {
return 0;
} else if (Z121 == Z119) {
INC(Zpky9FDA_1.Y0.Y0);
Zpky9FDA_1.Y0.Y1 = 0;
} else if (Z121 == Z118) {
Zpky9FDA_1.Y0.Y1 = (Zpky9FDA_1.Y0.Y1 / 8 + 1) * 8;
}
INC(Zpky9FDA_1.Y0.Y1);
Z121 = Z120;
Z120 = ZfM_7((ZDz6VQCC_4)ZfM_0);
switch (Z121) {
case Z117:;
return 0;
break;
case ' ':;
return 1;
break;
case '^':;
return 2;
break;
case '%':;
return 3;
break;
case '$':;
return 4;
break;
case '.':;
return 5;
break;
case '\\':;
if (Z120 == Z119) {
Z121 = Z120;
Z120 = ZfM_7((ZDz6VQCC_4)ZfM_0);
return 10;
} else {
return 6;
}
break;
case '{':;
return 7;
break;
case '}':;
return 8;
break;
case Z119:;
return 9;
break;
case Z118:;
return 12;
break;
default:
Zpky9FDA_1.Y1 = Z121;
return 11;
break;
}
} EXIT_1:;
}

void Zpky9FDA_5
# ifdef HAVE_ARGS
(CARDINAL Z131, Zpky9FDA_0 *Z125)
# else
(Z131, Z125)
CARDINAL Z131;
Zpky9FDA_0 *Z125;
# endif
{
Z125->Y1 = ' ';
}

void BEGIN_Scanner ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Position ();
BEGIN_IO ();

Zpky9FDA_1.Y0.Y0 = 0;
Zpky9FDA_1.Y0.Y1 = 0;
}
