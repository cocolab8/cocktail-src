#include "SYSTEM_.h"

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Source
#include "Source.h"
#endif


static Zp1PEAFD_2 Z127;

ZDz6VQCC_4 ZpwNQF2_0
# ifdef HAVE_ARGS
(CHAR Z129[], LONGCARD O_1)
# else
(Z129, O_1)
CHAR Z129[];
LONGCARD O_1;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z129, O_1, CHAR)
Zp1PEAFD_13(Z129, O_1, &Z127);
Zpky9FDA_5.Y0.Y0 = Zfb3DLQ_2(&Z127);
{
ZDz6VQCC_4 R_1 = OpenInput(Z129, O_1);

FREE_OPEN_ARRAYS
return R_1;
}
}

INTEGER ZpwNQF2_1
# ifdef HAVE_ARGS
(ZDz6VQCC_4 Z131, ADDRESS Z133, CARDINAL Z134)
# else
(Z131, Z133, Z134)
ZDz6VQCC_4 Z131;
ADDRESS Z133;
CARDINAL Z134;
# endif
{
return rRead(Z131, Z133, (LONGINT)Z134);
}

void ZpwNQF2_2
# ifdef HAVE_ARGS
(ZDz6VQCC_4 Z131)
# else
(Z131)
ZDz6VQCC_4 Z131;
# endif
{
rClose(Z131);
}

void BEGIN_Source ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_rSystem ();
BEGIN_Idents ();
BEGIN_rSystem ();
BEGIN_Idents ();
BEGIN_Strings ();
BEGIN_Scanner ();

Zp1PEAFD_13((STRING)"StdInput", 8L, &Z127);
Zpky9FDA_5.Y0.Y0 = Zfb3DLQ_2(&Z127);
}
