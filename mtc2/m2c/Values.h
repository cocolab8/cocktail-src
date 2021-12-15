#define DEFINITION_Values

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_StringM
#include "StringM.h"
#endif

#define Zsl7KDB_0	0
#define Zsl7KDB_1	1
#define Zsl7KDB_2	2
#define Zsl7KDB_3	3
#define Zsl7KDB_4	4
#define Zsl7KDB_5	5
#define Zsl7KDB_6	6
#define Zsl7KDB_7	7
#define Zsl7KDB_8	8
#define Zsl7KDB_9	9
#define Zsl7KDB_10	10
#define Zsl7KDB_11	11
#define Zsl7KDB_12	12
typedef struct Values_1 {
SHORTINT Y0;
union {
struct {
LONGINT Y1;
} V_1;
struct {
LONGCARD Y2;
} V_2;
struct {
LONGREAL Y3;
} V_3;
struct {
BOOLEAN Y4;
} V_4;
struct {
CHAR Y5;
} V_5;
struct {
Zp1PEAFi_1 Y6;
} V_6;
struct {
BITSET Y7;
} V_7;
struct {
ADDRESS Y8;
} V_8;
struct {
SHORTCARD Y9;
} V_9;
struct {
ADDRESS Y10;
} V_10;
} U_1;
} Zsl7KDB_13;
extern Zsl7KDB_13 Zsl7KDB_14, Zsl7KDB_15, Zsl7KDB_16, Zsl7KDB_17, Zsl7KDB_18, Zsl7KDB_19, Zsl7KDB_20, Zsl7KDB_21, Zsl7KDB_22, Zsl7KDB_23, Zsl7KDB_24, Zsl7KDB_25, Zsl7KDB_26, Zsl7KDB_27, Zsl7KDB_28, Zsl7KDB_29, Zsl7KDB_30;
extern void Zsl7KDB_31 ARGS ((ADDRESS Z162, ADDRESS Z163, Zsl7KDB_13 *Z164));
extern ADDRESS Zsl7KDB_32 ARGS ((Zsl7KDB_13 Z164));
extern LONGINT Zsl7KDB_33 ARGS ((Zsl7KDB_13 Z164));
extern void Zsl7KDB_34 ARGS ((ZfM_3 Z168, Zsl7KDB_13 Z164));
extern void BEGIN_Values ARGS ((void));
