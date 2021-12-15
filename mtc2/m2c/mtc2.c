#include "SYSTEM_.h"

#ifndef DEFINITION_rSystem
#include "rSystem.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Base
#include "Base.h"
#endif

#ifndef DEFINITION_Scanner
#include "Scanner.h"
#endif

#ifndef DEFINITION_Parser
#include "Parser.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_DefMods
#include "DefMods.h"
#endif

#ifndef DEFINITION_Defs
#include "Defs.h"
#endif

#ifndef DEFINITION_Semantic
#include "Semantic.h"
#endif

#ifndef DEFINITION_Code
#include "Code.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Times
#include "Times.h"
#endif

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#ifndef DEFINITION_Defs
#include "Defs.h"
#endif

#ifndef DEFINITION_rMemory
#include "rMemory.h"
#endif

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

static CARDINAL Z159;
static BOOLEAN Z160, Z161, Z162;
static LONGINT Z167, Z168;
static void Z164 ARGS ((CHAR Z169[], LONGCARD O_1));
static void Z165 ARGS ((void));
static void Z166 ARGS ((CHAR Z172[], LONGCARD O_2));
static void Z174 ARGS ((CARDINAL Z175));


static void Z164
# ifdef HAVE_ARGS
(CHAR Z169[], LONGCARD O_1)
# else
(Z169, O_1)
CHAR Z169[];
LONGCARD O_1;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_1 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z169, O_1, CHAR)
ZfM_29((ZDz6VQCC_4)ZfM_1, Z169, O_1);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_22((ZDz6VQCC_4)ZfM_1);
FREE_OPEN_ARRAYS
}

static void Z165
 ARGS ((void))
{
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"Memory ", 7L);
ZfM_25((ZDz6VQCC_4)ZfM_1, (LONGINT)ZDtgCFKU_0, 7L);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"  Heap (Tree) ", 14L);
ZfM_25((ZDz6VQCC_4)ZfM_1, (LONGINT)Zq0A4_316, 7L);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"  Heap (Defs) ", 14L);
ZfM_25((ZDz6VQCC_4)ZfM_1, (LONGINT)Zae5C_242, 7L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_22((ZDz6VQCC_4)ZfM_1);
}

static void Z166
# ifdef HAVE_ARGS
(CHAR Z172[], LONGCARD O_2)
# else
(Z172, O_2)
CHAR Z172[];
LONGCARD O_2;
# endif
{
OPEN_ARRAY_LOCALS

ALLOC_OPEN_ARRAYS (O_2 * sizeof (CHAR), 1)
COPY_OPEN_ARRAY (Z172, O_2, CHAR)
Z168 = ZqrGCB_0();
ZfM_29((ZDz6VQCC_4)ZfM_1, Z172, O_2);
ZfM_25((ZDz6VQCC_4)ZfM_1, Z168 - Z167, 5L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
FREE_OPEN_ARRAYS
}

static void Z163()
{
Z167 = ZqrGCB_0();
}

static void Z174
# ifdef HAVE_ARGS
(CARDINAL Z175)
# else
(Z175)
CARDINAL Z175;
# endif
{
ZblNKKO_45(ZfXEB_3('w'));
ZfM_34();
rExit((LONGINT)Z175);
}

void BEGIN_MODULE ARGS ((void))
{
BEGIN_rSystem ();
BEGIN_IO ();
BEGIN_Strings ();
BEGIN_Base ();
BEGIN_Scanner ();
BEGIN_Parser ();
BEGIN_Tree ();
BEGIN_DefMods ();
BEGIN_Defs ();
BEGIN_Semantic ();
BEGIN_Code ();
BEGIN_Errors ();
BEGIN_Times ();
BEGIN_Tree ();
BEGIN_Defs ();
BEGIN_rMemory ();
BEGIN_Idents ();
Z163();

ZfXEB_0.A[0] = '\0';
Zp1PEAFD_4(&ZfXEB_1);
ZfXEB_2();
if (ZfXEB_3('h')) {
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"usage: mtc2 [-options] [file]", 29L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-w suppress warning diagnostics", 31L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-i generate header files for imported modules", 45L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-c generate type casts to make programs lint free", 49L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-r generate runtime checks", 26L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-u generate obfuscated code", 27L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-ddir allow import from modules in directory dir", 48L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-odir write output to directory dir", 35L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-h print help information", 25L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-t print test output (time)", 27L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-m print test output (memory)", 29L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
ZfM_29((ZDz6VQCC_4)ZfM_1, (STRING)"-D print the parse tree", 23L);
ZfM_33((ZDz6VQCC_4)ZfM_1);
Z174(0L);
}
Z160 = ZfXEB_3('t');
Z161 = ZfXEB_3('m');
Z162 = ZfXEB_3('f');
if (ZfXEB_0.A[0] != '\0') {
Zpky9FDA_8(ZfXEB_0.A, 128L);
}
if (Z161) {
Z165();
}
if (Z160 || Z161) {
Z164((STRING)"Parser", 6L);
}
Z159 = ZmfDOBA_6();
if (Z160) {
ZqrGCB_2((STRING)"Parser ", 7L);
}
if (ZblNKKO_44() == 0 || Z162) {
if (Z161) {
Z165();
}
if (Z160 || Z161) {
Z164((STRING)"GetDefinitionModules", 20L);
}
Zae5hqDA_0(ZmfDOBA_5.U_1.V_0.Y3, &Zq0A4_315);
if (Z160) {
ZqrGCB_2((STRING)"GetDefinitionModules  ", 22L);
}
}
ZmfDOBA_7();
if (ZblNKKO_44() == 0 || Z162) {
if (Z161) {
Z165();
}
if (Z160 || Z161) {
Z164((STRING)"Eval", 4L);
}
ZpmC89LG6_1();
ZpmC89LG6_0(Zq0A4_315);
ZpmC89LG6_2();
if (Z160) {
ZqrGCB_2((STRING)"Eval  ", 6L);
}
if (Z161) {
Z165();
}
if (Z160 || Z161) {
Z164((STRING)"Code", 4L);
}
ZggD3_29();
ZggD3_28(Zq0A4_315);
ZggD3_30();
if (Z160) {
ZqrGCB_2((STRING)"Code  ", 6L);
}
}
Zq0A4_466();
Zae5C_316();
if (Z160) {
Z166((STRING)"mtc2  ", 6L);
}
if (Z161) {
Z165();
}
if (ZblNKKO_44() != 0) {
Z174(1L);
} else {
Z174(0L);
}
}
