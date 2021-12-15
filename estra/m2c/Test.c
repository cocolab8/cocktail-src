#include "SYSTEM_.h"

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_rMemory
#include "rMemory.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_Times
#include "Times.h"
#endif

#ifndef DEFINITION_Times
#include "Times.h"
#endif

#ifndef DEFINITION_Test
#include "Test.h"
#endif


static LONGINT Z127;

void ZqnBQ_0
 ARGS ((void))
{
Zp1BbM_23((STRING)"MaxIdent: ", 10L);
Zp1BbM_19((LONGINT)Zfb3DLQ_6(), 1L);
Zp1BbM_27();
Zp1BbM_19((LONGINT)(ZDtgCFKU_0 / 1024), 4L);
Zp1BbM_23((STRING)".", 1L);
Zp1BbM_19((LONGINT)(ZDtgCFKU_0 % 1024 * 10 / 1024), 1L);
Zp1BbM_23((STRING)"  kBytes   memory used", 22L);
Zp1BbM_27();
Z127 = ZqrGCB_0();
Zp1BbM_19(Z127 / 1000, 4L);
Zp1BbM_23((STRING)".", 1L);
Zp1BbM_19(Z127 % 1000 / 10, 2L);
Zp1BbM_23((STRING)" s        CPU time used", 23L);
Zp1BbM_27();
}

void ZqnBQ_1
# ifdef HAVE_ARGS
(CHAR Z130[], LONGCARD O_1)
# else
(Z130, O_1)
CHAR Z130[];
LONGCARD O_1;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z130, O_1, CHAR)
if (ZehCfg728_1) {
ZqrGCB_2(Z130, O_1);
}
FREE_OPEN_ARRAYS
}

void BEGIN_Test ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_ArgCheck ();
BEGIN_Idents ();
BEGIN_rMemory ();
BEGIN_StdIO ();
BEGIN_Times ();
BEGIN_Times ();

}
