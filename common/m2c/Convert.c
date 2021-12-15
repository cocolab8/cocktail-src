#include "SYSTEM_.h"

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_Pointers
#include "Pointers.h"
#endif

#ifndef DEFINITION_Convert
#include "Convert.h"
#endif



ADDRESS ZggGNEAP_0
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z121)
# else
(Z121)
Zfb3DLQ_0 Z121;
# endif
{
CARDINAL Z122;

Z122 = Z121;
return INTPTR(Z122);
}

Zfb3DLQ_0 ZggGNEAP_1
# ifdef HAVE_ARGS
(ADDRESS Z124)
# else
(Z124)
ADDRESS Z124;
# endif
{
return PTRINT(Z124);
}

void BEGIN_Convert ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_Idents ();
BEGIN_Pointers ();

}
