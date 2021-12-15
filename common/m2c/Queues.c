#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_rMemory
#include "rMemory.h"
#endif

#ifndef DEFINITION_Queues
#include "Queues.h"
#endif


#define Z124	2
static Zn0DDDB_3 Z125;
static void Z140 ARGS ((Zn0DDDB_4 *Z128));

void Zn0DDDB_5
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
{
register Zn0DDDB_4 *W_1 = Z128;

W_1->Y0 = Z124;
W_1->Y1 = 0;
W_1->Y2 = W_1->Y0 - 1;
W_1->Y3 = (Zn0DDDB_2)ZDtgCFKU_1(W_1->Y0 * Z125);
}
}

void Zn0DDDB_6
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
{
register Zn0DDDB_4 *W_2 = Z128;

ZDtgCFKU_2(W_2->Y0 * Z125, (ADDRESS)W_2->Y3);
W_2->Y3 = NIL;
W_2->Y0 = 0;
}
}

void Zn0DDDB_7
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
{
register Zn0DDDB_4 *W_3 = Z128;

W_3->Y1 = 0;
W_3->Y2 = W_3->Y0 - 1;
}
}

void Zn0DDDB_8
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128, Zn0DDDB_1 Z137)
# else
(Z128, Z137)
Zn0DDDB_4 *Z128;
Zn0DDDB_1 Z137;
# endif
{
{
register Zn0DDDB_4 *W_4 = Z128;

INC(W_4->Y2);
if (W_4->Y2 == W_4->Y0) {
W_4->Y2 = 0;
}
W_4->Y3->A[W_4->Y2] = Z137;
if (Zn0DDDB_15(*Z128)) {
Z140(Z128);
}
}
}

Zn0DDDB_1 Zn0DDDB_9
# ifdef HAVE_ARGS
(Zn0DDDB_4 Z128)
# else
(Z128)
Zn0DDDB_4 Z128;
# endif
{
{
register Zn0DDDB_4 *W_5 = &Z128;

return W_5->Y3->A[W_5->Y1];
}
}

Zn0DDDB_1 Zn0DDDB_10
# ifdef HAVE_ARGS
(Zn0DDDB_4 Z128)
# else
(Z128)
Zn0DDDB_4 Z128;
# endif
{
{
register Zn0DDDB_4 *W_6 = &Z128;

return W_6->Y3->A[W_6->Y2];
}
}

void Zn0DDDB_13
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
Zn0DDDB_11(Z128);
}

void Zn0DDDB_11
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
{
register Zn0DDDB_4 *W_7 = Z128;

INC(W_7->Y1);
if (W_7->Y1 == W_7->Y0) {
W_7->Y1 = 0;
}
}
}

void Zn0DDDB_12
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
{
register Zn0DDDB_4 *W_8 = Z128;

if (W_8->Y2 == 0) {
W_8->Y2 = W_8->Y0;
}
DEC(W_8->Y2);
}
}

void Zn0DDDB_14
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128, Zn0DDDB_1 Z137)
# else
(Z128, Z137)
Zn0DDDB_4 *Z128;
Zn0DDDB_1 Z137;
# endif
{
{
register Zn0DDDB_4 *W_9 = Z128;

if (W_9->Y1 == 0) {
W_9->Y1 = W_9->Y0;
}
DEC(W_9->Y1);
W_9->Y3->A[W_9->Y1] = Z137;
if (Zn0DDDB_15(*Z128)) {
Z140(Z128);
}
}
}

BOOLEAN Zn0DDDB_15
# ifdef HAVE_ARGS
(Zn0DDDB_4 Z128)
# else
(Z128)
Zn0DDDB_4 Z128;
# endif
{
{
register Zn0DDDB_4 *W_10 = &Z128;

return (W_10->Y2 + 1) % W_10->Y0 == W_10->Y1;
}
}

Zn0DDDB_3 Zn0DDDB_16
# ifdef HAVE_ARGS
(Zn0DDDB_4 Z128)
# else
(Z128)
Zn0DDDB_4 Z128;
# endif
{
Zn0DDDB_3 Z147;

{
register Zn0DDDB_4 *W_11 = &Z128;

Z147 = W_11->Y2 + 1 - W_11->Y1;
if (Z147 < 0) {
INC1(Z147, W_11->Y0);
} else if (Z147 >= W_11->Y0) {
DEC1(Z147, W_11->Y0);
}
return Z147;
}
}

Zn0DDDB_1 Zn0DDDB_17
# ifdef HAVE_ARGS
(Zn0DDDB_4 Z128, Zn0DDDB_3 Z149)
# else
(Z128, Z149)
Zn0DDDB_4 Z128;
Zn0DDDB_3 Z149;
# endif
{
Zn0DDDB_3 Z150;

{
register Zn0DDDB_4 *W_12 = &Z128;

Z150 = W_12->Y1 + Z149 - 1;
if (Z150 >= W_12->Y0) {
DEC1(Z150, W_12->Y0);
}
return W_12->Y3->A[Z150];
}
}

void Zn0DDDB_18
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z152, Zn0DDDB_4 Z153)
# else
(Z152, Z153)
Zn0DDDB_4 *Z152;
Zn0DDDB_4 Z153;
# endif
{
Zn0DDDB_3 Z154, Z155;

Z154 = Zn0DDDB_16(Z153);
if (Z154 == 0) {
Zn0DDDB_7(Z152);
} else {
{
register Zn0DDDB_4 *W_13 = Z152;

if (Z154 >= W_13->Y0) {
ZDtgCFKU_2(W_13->Y0 * Z125, (ADDRESS)W_13->Y3);
W_13->Y0 = Z154 + 1;
W_13->Y3 = (Zn0DDDB_2)ZDtgCFKU_1(W_13->Y0 * Z125);
}
W_13->Y1 = 0;
W_13->Y2 = -1;
Z155 = Z153.Y1;
if (Z155 > Z153.Y2) {
do {
INC(W_13->Y2);
W_13->Y3->A[W_13->Y2] = Z153.Y3->A[Z155];
INC(Z155);
} while (!(Z155 == Z153.Y0));
Z155 = 0;
}
do {
INC(W_13->Y2);
W_13->Y3->A[W_13->Y2] = Z153.Y3->A[Z155];
INC(Z155);
} while (!(Z155 > Z153.Y2));
}
}
}

Zn0DDDB_1 Zn0DDDB_19
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
Zn0DDDB_1 Z137;

Z137 = Zn0DDDB_9(*Z128);
Zn0DDDB_11(Z128);
return Z137;
}

Zn0DDDB_1 Zn0DDDB_20
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
Zn0DDDB_1 Z137;

Z137 = Zn0DDDB_10(*Z128);
Zn0DDDB_12(Z128);
return Z137;
}

static void Z140
# ifdef HAVE_ARGS
(Zn0DDDB_4 *Z128)
# else
(Z128)
Zn0DDDB_4 *Z128;
# endif
{
Zn0DDDB_3 Z155;
Zn0DDDB_2 Z158;

{
register Zn0DDDB_4 *W_14 = Z128;

Z158 = (Zn0DDDB_2)ZDtgCFKU_1(2 * W_14->Y0 * Z125);
if (W_14->Y1 <= W_14->Y2) {
{
LONGINT B_1 = W_14->Y1, B_2 = W_14->Y2;

if (B_1 <= B_2)
for (Z155 = B_1;; Z155 += 1) {
Z158->A[Z155] = W_14->Y3->A[Z155];
if (Z155 >= B_2) break;
}
}
} else {
{
LONGINT B_3 = 0, B_4 = W_14->Y2;

if (B_3 <= B_4)
for (Z155 = B_3;; Z155 += 1) {
Z158->A[Z155] = W_14->Y3->A[Z155];
if (Z155 >= B_4) break;
}
}
{
LONGINT B_5 = W_14->Y1, B_6 = W_14->Y0 - 1;

if (B_5 <= B_6)
for (Z155 = B_5;; Z155 += 1) {
Z158->A[Z155 + W_14->Y0] = W_14->Y3->A[Z155];
if (Z155 >= B_6) break;
}
}
INC1(W_14->Y1, W_14->Y0);
}
ZDtgCFKU_2(W_14->Y0 * Z125, (ADDRESS)W_14->Y3);
W_14->Y0 = 2 * W_14->Y0;
W_14->Y3 = Z158;
}
}

void BEGIN_Queues ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_rMemory ();

Z125 = sizeof (Zn0DDDB_1);
if (ODD(Z125) && Z125 > 1) {
INC(Z125);
}
}
