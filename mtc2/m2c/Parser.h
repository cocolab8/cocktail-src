#define DEFINITION_Parser

#ifndef DEFINITION_Tree
#include "Tree.h"
#endif

#define ZmfDOBA_0	1
#define ZmfDOBA_1	2
#define ZmfDOBA_2	3
#define ZmfDOBA_3	4
typedef struct Parser_1 {
union {
struct {
SHORTCARD Y0;
} V_1;
struct {
Zq0A4_133 Y1, Y2;
} V_2;
struct {
Zq0A4_133 Y3;
} V_0;
} U_1;
} ZmfDOBA_4;
extern ZmfDOBA_4 ZmfDOBA_5;
extern INTEGER ZmfDOBA_6 ARGS ((void));
extern void ZmfDOBA_7 ARGS ((void));
extern void ZmfDOBA_8 ARGS ((CARDINAL Z128, CHAR Z129[], LONGCARD ));
extern void BEGIN_Parser ARGS ((void));
