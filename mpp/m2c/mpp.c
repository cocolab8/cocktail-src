#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

static CARDINAL Z123;


void BEGIN_MODULE ARGS ((void))
{
BEGIN_IO ();
BEGIN_Parser ();
BEGIN_rSystem ();

Z123 = ZmfDOBA_2();
ZmfDOBA_3();
ZfM_34();
if (Z123 > 0) {
rExit(1L);
} else {
rExit(0L);
}
}
