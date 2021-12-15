#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Position
#include "Position.h"
#endif

ZmtLFGGBG_0 ZmtLFGGBG_1;


INTEGER ZmtLFGGBG_2
# ifdef HAVE_ARGS
(ZmtLFGGBG_0 Z127, ZmtLFGGBG_0 Z128)
# else
(Z127, Z128)
ZmtLFGGBG_0 Z127, Z128;
# endif
{
{
register ZmtLFGGBG_0 *W_1 = &Z127;

if (W_1->Y0 < Z128.Y0) {
return -1;
}
if (W_1->Y0 > Z128.Y0) {
return 1;
}
if (W_1->Y1 < Z128.Y1) {
return -1;
}
if (W_1->Y1 > Z128.Y1) {
return 1;
}
if (W_1->Y2 < Z128.Y2) {
return -1;
}
if (W_1->Y2 > Z128.Y2) {
return 1;
}
return 0;
}
}

void ZmtLFGGBG_3
# ifdef HAVE_ARGS
(ZfM_3 Z130, ZmtLFGGBG_0 Z114)
# else
(Z130, Z114)
ZfM_3 Z130;
ZmtLFGGBG_0 Z114;
# endif
{
ZfM_24(Z130, '"');
Zfb3DLQ_7(Z130, Z114.Y0);
ZfM_29(Z130, (STRING)"\", ", 3L);
ZfM_25(Z130, (LONGINT)Z114.Y1, 3L);
ZfM_29(Z130, (STRING)", ", 2L);
ZfM_25(Z130, (LONGINT)Z114.Y2, 2L);
}

void ZmtLFGGBG_4
# ifdef HAVE_ARGS
(ZfM_3 Z130, ZmtLFGGBG_0 *Z114)
# else
(Z130, Z114)
ZfM_3 Z130;
ZmtLFGGBG_0 *Z114;
# endif
{
CHAR Z135;

Z114->Y1 = ZfM_8(Z130);
Z135 = ZfM_7(Z130);
Z114->Y2 = ZfM_8(Z130);
}

void BEGIN_Position ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_Idents ();
BEGIN_IO ();
BEGIN_Idents ();

ZmtLFGGBG_1.Y0 = Zfb3DLQ_1;
ZmtLFGGBG_1.Y1 = 0;
ZmtLFGGBG_1.Y2 = 0;
}
