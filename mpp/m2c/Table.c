#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Table
#include "Table.h"
#endif


static Zp1PEAFD_2 Z127;
static BOOLEAN Z128;
static struct S_1 {
Zp1PEAFD_2 A[256];
} Z129;
static CHAR Z130;
static void Z139 ARGS ((Zp1PEAFD_2 *Z135));

void Zqjx8B_0
# ifdef HAVE_ARGS
(CHAR Z132, Zp1PEAFD_2 *Z133)
# else
(Z132, Z133)
CHAR Z132;
Zp1PEAFD_2 *Z133;
# endif
{
Zp1PEAFD_3(&Z129.A[Z132], Z133);
}

void Zqjx8B_1
# ifdef HAVE_ARGS
(CHAR Z132, Zp1PEAFD_2 *Z135)
# else
(Z132, Z135)
CHAR Z132;
Zp1PEAFD_2 *Z135;
# endif
{
Zp1PEAFD_2 Z136;
INTEGER Z137, Z138;

Zp1PEAFD_3(&Z136, &Z129.A[Z132]);
Z138 = 0;
Z137 = Zp1PEAFD_7(&Z136);
for (;;) {
if (Z138 == Z137) {
goto EXIT_1;
}
INC(Z138);
Z130 = Zp1PEAFD_12(&Z136, (Zp1PEAFD_1)Z138);
if (Z130 == '%') {
Z139(Z135);
} else if (Z130 == '\\') {
if (Z138 < Z137) {
INC(Z138);
Z130 = Zp1PEAFD_12(&Z136, (Zp1PEAFD_1)Z138);
Zp1BbM_18(Z130);
}
} else {
Zp1BbM_18(Z130);
}
} EXIT_1:;
}

static void Z139
# ifdef HAVE_ARGS
(Zp1PEAFD_2 *Z135)
# else
(Z135)
Zp1PEAFD_2 *Z135;
# endif
{
INTEGER Z138, Z137;
CHAR Z130;

Z138 = 0;
Z137 = Zp1PEAFD_7(Z135);
for (;;) {
if (Z138 == Z137) {
goto EXIT_2;
}
INC(Z138);
Z130 = Zp1PEAFD_12(Z135, (Zp1PEAFD_1)Z138);
if (Z130 == '\\') {
if (Z138 < Z137) {
INC(Z138);
Z130 = Zp1PEAFD_12(Z135, (Zp1PEAFD_1)Z138);
Zp1BbM_18(Z130);
}
} else {
Zp1BbM_18(Z130);
}
} EXIT_2:;
}

void Zqjx8B_2
 ARGS ((void))
{
if (Z128) {
Zqjx8B_1('^', &Z127);
Z128 = FALSE;
}
}

void Zqjx8B_3
 ARGS ((void))
{
Zqjx8B_1('$', &Z127);
Z128 = TRUE;
}

void Zqjx8B_4
# ifdef HAVE_ARGS
(Zp1PEAFD_2 *Z135)
# else
(Z135)
Zp1PEAFD_2 *Z135;
# endif
{
Zp1PEAFD_21((ZDz6VQCC_4)ZfM_1, Z135);
}

void Zqjx8B_5
 ARGS ((void))
{
Zp1BbM_27();
}

void BEGIN_Table ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_Strings ();
BEGIN_IO ();
BEGIN_StdIO ();
BEGIN_Strings ();

Z128 = TRUE;
Zp1PEAFD_4(&Z127);
{
CHAR B_1 = MIN_CHAR, B_2 = MAX_CHAR;

if (B_1 <= B_2)
for (Z130 = B_1;; Z130 += 1) {
Zp1PEAFD_4(&Z129.A[Z130]);
if (Z130 >= B_2) break;
}
}
}
