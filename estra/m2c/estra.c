#include "SYSTEM_.h"

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

#ifndef DEFINITION_CodeM2
#include "CodeM2.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Info
#include "Info.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Match
#include "Match.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

#ifndef DEFINITION_Path
#include "Path.h"
#endif

#ifndef DEFINITION_Semantics
#include "Semantics.h"
#endif

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_Test
#include "Test.h"
#endif

#ifndef DEFINITION_ArgCheck
#include "ArgCheck.h"
#endif

#ifndef DEFINITION_Grammar
#include "Grammar.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

#ifndef DEFINITION_Test
#include "Test.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

static INTEGER Z154;


void BEGIN_MODULE ARGS ((void))
{
BEGIN_ArgCheck ();
BEGIN_CodeM2 ();
BEGIN_Errors ();
BEGIN_Info ();
BEGIN_IO ();
BEGIN_Match ();
BEGIN_Parser ();
BEGIN_Path ();
BEGIN_Semantics ();
BEGIN_rSystem ();
BEGIN_Test ();
BEGIN_ArgCheck ();
BEGIN_Grammar ();
BEGIN_Parser ();
BEGIN_Test ();
BEGIN_Tree ();

ZblNKKO_73 = ZflEF_0;
ZblNKKO_74 = ZflEF_1;
ZmfFF_0(ZblNKKO_76.A, 256L);
ZblNKKO_79();
ZehCfg728_11();
ZqnBQ_1((STRING)"initialize", 10L);
Z154 = ZmfDOBA_32();
ZmfDOBA_34();
ZqnBQ_1((STRING)"Parser", 6L);
ZpmC89LG6G_1();
ZqnBQ_1((STRING)"Semantics", 9L);
if (ZpmC89LG6G_0) {
ZjcFA5_2();
ZqnBQ_1((STRING)"MakeTables", 10L);
ZggD3g4_0();
ZqnBQ_1((STRING)"MakeCodeM2", 10L);
}
ZblNKKO_81();
if (ZehCfg728_6) {
Zq0A4_201((ZDz6VQCC_4)ZfM_1, ZmfDOBA_0);
}
if (ZehCfg728_7) {
ZdnD8D8D_30((ZDz6VQCC_4)ZfM_1);
}
if (ZehCfg728_1) {
ZqnBQ_0();
}
ZfM_34();
if (ZblNKKO_72) {
rExit(1L);
} else {
rExit(0L);
}
}
