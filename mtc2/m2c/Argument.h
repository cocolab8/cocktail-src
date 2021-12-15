/* $Id: Argument.h,v 1.0 1998/05/29 10:46:12 grosch rel grosch $ */

#define DEFINITION_Argument

typedef struct Argument_1 {
    struct Argument_2 {
        CHAR A [999 + 1];
    } *A [999 + 1];
} *Argument_ArgTable;

extern void GetArgs ARGS ((SHORTCARD *argc, Argument_ArgTable *argv));
extern void GetEnv ARGS ((Argument_ArgTable *env));
extern void BEGIN_Argument ARGS ((void));
