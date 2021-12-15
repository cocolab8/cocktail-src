#include "SYSTEM_.h"

#ifndef DEFINITION_Characte
#include "Characte.h"
#endif

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_Path
#include "Path.h"
#endif


struct S_2 {
CHAR A[255 + 1];
};

void ZmfFF_0
# ifdef HAVE_ARGS
(CHAR Z124[], LONGCARD O_1)
# else
(Z124, O_1)
CHAR Z124[];
LONGCARD O_1;
# endif
{
struct S_2 Z125, Z126;
INTEGER Z127;

GetArgument(0L, Z126.A, 256L);
Z127 = Zgg3DDyAC_1(Z126.A, 256L);
while (Z127 > 0 && Zgg3DDyAC_2(Z126.A, 256L, Z127) != '/' && Zgg3DDyAC_2(Z126.A, 256L, Z127) != '\\') {
DEC(Z127);
}
if (Z127 > 0) {
Zgg3DDyAC_5(Z126.A, 256L, 1L, Z127, Z125.A, 256L);
Zgg3DDyAC_4(Z125.A, 256L, Z124, O_1);
Zgg3DDyAC_6(Z124, O_1, Z125.A, 256L);
}
}

void BEGIN_Path ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Characte ();
BEGIN_rSystem ();

}
