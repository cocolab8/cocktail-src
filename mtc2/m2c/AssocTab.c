#include "SYSTEM_.h"

#ifndef DEFINITION_Idents
#include "Idents.h"
#endif

#ifndef DEFINITION_DynArray
#include "DynArray.h"
#endif

#ifndef DEFINITION_AssocTab
#include "AssocTab.h"
#endif


#define Z122	1048576
typedef struct S_1 {
ADDRESS A[Z122 + 1];
} Z123;
static LONGINT Z124;
static CARDINAL Z125;
static Z123 *Z114;

void ZeiPLCljx_0
 ARGS ((void))
{
CARDINAL Z127;
LONGINT Z128;

Z124 = 1;
Z128 = Zfb3DLQ_6();
while (Z124 <= Z128) {
Z124 = Z124 * 2;
}
ZarQdhNDD_0((ADDRESS *)&Z114, &Z124, (LONGINT)sizeof (ADDRESS));
Z125 = Z124 - 1;
{
LONGCARD B_1 = 0, B_2 = Z125;

if (B_1 <= B_2)
for (Z127 = B_1;; Z127 += 1) {
Z114->A[Z127] = (ADDRESS)NIL;
if (Z127 >= B_2) break;
}
}
}

void ZeiPLCljx_1
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z130, ADDRESS Z131)
# else
(Z130, Z131)
Zfb3DLQ_0 Z130;
ADDRESS Z131;
# endif
{
CARDINAL Z127, Z132;
LONGINT Z128;

if (Z130 > Z125) {
Z128 = Zfb3DLQ_6();
while (Z124 <= Z128) {
ZarQdhNDD_2((ADDRESS *)&Z114, &Z124, (LONGINT)sizeof (ADDRESS));
}
Z132 = Z125;
Z125 = Z124 - 1;
{
LONGCARD B_3 = Z132 + 1, B_4 = Z125;

if (B_3 <= B_4)
for (Z127 = B_3;; Z127 += 1) {
Z114->A[Z127] = (ADDRESS)NIL;
if (Z127 >= B_4) break;
}
}
}
Z114->A[Z130] = Z131;
}

void ZeiPLCljx_2
# ifdef HAVE_ARGS
(Zfb3DLQ_0 Z130, ADDRESS *Z131)
# else
(Z130, Z131)
Zfb3DLQ_0 Z130;
ADDRESS *Z131;
# endif
{
if (Z130 > Z125) {
*Z131 = (ADDRESS)NIL;
} else {
*Z131 = Z114->A[Z130];
}
}

void ZeiPLCljx_3
 ARGS ((void))
{
ZarQdhNDD_3((ADDRESS *)&Z114, &Z124, (LONGINT)sizeof (ADDRESS));
}

void BEGIN_AssocTab ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Idents ();
BEGIN_Idents ();
BEGIN_DynArray ();

}
