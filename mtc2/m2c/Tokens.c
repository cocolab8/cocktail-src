#include "SYSTEM_.h"

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Tokens
#include "Tokens.h"
#endif


#define Z119	32
static BOOLEAN Z120 ARGS ((ZqxDADK_78 *Z121, ZqxDADK_77 Z123));

static BOOLEAN Z120
# ifdef HAVE_ARGS
(ZqxDADK_78 *Z121, ZqxDADK_77 Z123)
# else
(Z121, Z123)
ZqxDADK_78 *Z121;
ZqxDADK_77 Z123;
# endif
{
return IN(Z123 % Z119, Z121->A[Z123 / Z119]);
}

void ZqxDADK_80
# ifdef HAVE_ARGS
(ZfM_3 Z126, ZqxDADK_78 Z127)
# else
(Z126, Z127)
ZfM_3 Z126;
ZqxDADK_78 Z127;
# endif
{
ZqxDADK_77 Z128;

for (Z128 = ZqxDADK_0; Z128 <= ZqxDADK_76; Z128 += 1) {
if (Z120(&Z127, Z128)) {
ZqxDADK_79(Z126, Z128);
ZfM_24(Z126, ' ');
}
}
}

void ZqxDADK_79
# ifdef HAVE_ARGS
(ZfM_3 Z126, ZqxDADK_77 Z128)
# else
(Z126, Z128)
ZfM_3 Z126;
ZqxDADK_77 Z128;
# endif
{
switch (Z128) {
case ZqxDADK_1:;
ZfM_29(Z126, (STRING)"End-of-Tokens", 13L);
break;
case ZqxDADK_2:;
ZfM_29(Z126, (STRING)"Ident", 5L);
break;
case ZqxDADK_3:;
ZfM_29(Z126, (STRING)"Integer", 7L);
break;
case ZqxDADK_4:;
ZfM_29(Z126, (STRING)"Integer", 7L);
break;
case ZqxDADK_5:;
ZfM_29(Z126, (STRING)"Integer", 7L);
break;
case ZqxDADK_6:;
ZfM_29(Z126, (STRING)"Char", 4L);
break;
case ZqxDADK_7:;
ZfM_29(Z126, (STRING)"Real", 4L);
break;
case ZqxDADK_8:;
ZfM_29(Z126, (STRING)"String", 6L);
break;
case ZqxDADK_9:;
ZfM_29(Z126, (STRING)"'#'", 3L);
break;
case ZqxDADK_10:;
ZfM_29(Z126, (STRING)"'('", 3L);
break;
case ZqxDADK_11:;
ZfM_29(Z126, (STRING)"')'", 3L);
break;
case ZqxDADK_12:;
ZfM_29(Z126, (STRING)"'*'", 3L);
break;
case ZqxDADK_13:;
ZfM_29(Z126, (STRING)"'+'", 3L);
break;
case ZqxDADK_14:;
ZfM_29(Z126, (STRING)"','", 3L);
break;
case ZqxDADK_15:;
ZfM_29(Z126, (STRING)"'-'", 3L);
break;
case ZqxDADK_16:;
ZfM_29(Z126, (STRING)"'.'", 3L);
break;
case ZqxDADK_17:;
ZfM_29(Z126, (STRING)"'..'", 4L);
break;
case ZqxDADK_18:;
ZfM_29(Z126, (STRING)"'/'", 3L);
break;
case ZqxDADK_19:;
ZfM_29(Z126, (STRING)"':'", 3L);
break;
case ZqxDADK_20:;
ZfM_29(Z126, (STRING)"':='", 4L);
break;
case ZqxDADK_21:;
ZfM_29(Z126, (STRING)"';'", 3L);
break;
case ZqxDADK_22:;
ZfM_29(Z126, (STRING)"'<'", 3L);
break;
case ZqxDADK_23:;
ZfM_29(Z126, (STRING)"'<='", 4L);
break;
case ZqxDADK_24:;
ZfM_29(Z126, (STRING)"'='", 3L);
break;
case ZqxDADK_25:;
ZfM_29(Z126, (STRING)"'>'", 3L);
break;
case ZqxDADK_26:;
ZfM_29(Z126, (STRING)"'>='", 4L);
break;
case ZqxDADK_27:;
ZfM_29(Z126, (STRING)"'['", 3L);
break;
case ZqxDADK_28:;
ZfM_29(Z126, (STRING)"']'", 3L);
break;
case ZqxDADK_29:;
ZfM_29(Z126, (STRING)"'^'", 3L);
break;
case ZqxDADK_30:;
ZfM_29(Z126, (STRING)"'{'", 3L);
break;
case ZqxDADK_31:;
ZfM_29(Z126, (STRING)"'|'", 3L);
break;
case ZqxDADK_32:;
ZfM_29(Z126, (STRING)"'}'", 3L);
break;
case ZqxDADK_33:;
ZfM_29(Z126, (STRING)"AND", 3L);
break;
case ZqxDADK_34:;
ZfM_29(Z126, (STRING)"ARRAY", 5L);
break;
case ZqxDADK_35:;
ZfM_29(Z126, (STRING)"BEGIN", 5L);
break;
case ZqxDADK_36:;
ZfM_29(Z126, (STRING)"BY", 2L);
break;
case ZqxDADK_37:;
ZfM_29(Z126, (STRING)"CASE", 4L);
break;
case ZqxDADK_38:;
ZfM_29(Z126, (STRING)"CONST", 5L);
break;
case ZqxDADK_39:;
ZfM_29(Z126, (STRING)"DEFINITION", 10L);
break;
case ZqxDADK_40:;
ZfM_29(Z126, (STRING)"DIV", 3L);
break;
case ZqxDADK_41:;
ZfM_29(Z126, (STRING)"DO", 2L);
break;
case ZqxDADK_42:;
ZfM_29(Z126, (STRING)"ELSE", 4L);
break;
case ZqxDADK_43:;
ZfM_29(Z126, (STRING)"ELSIF", 5L);
break;
case ZqxDADK_44:;
ZfM_29(Z126, (STRING)"END", 3L);
break;
case ZqxDADK_45:;
ZfM_29(Z126, (STRING)"EXIT", 4L);
break;
case ZqxDADK_46:;
ZfM_29(Z126, (STRING)"EXPORT", 6L);
break;
case ZqxDADK_47:;
ZfM_29(Z126, (STRING)"FOR", 3L);
break;
case ZqxDADK_48:;
ZfM_29(Z126, (STRING)"FROM", 4L);
break;
case ZqxDADK_49:;
ZfM_29(Z126, (STRING)"IF", 2L);
break;
case ZqxDADK_50:;
ZfM_29(Z126, (STRING)"IMPLEMENTATION", 14L);
break;
case ZqxDADK_51:;
ZfM_29(Z126, (STRING)"IMPORT", 6L);
break;
case ZqxDADK_52:;
ZfM_29(Z126, (STRING)"IN", 2L);
break;
case ZqxDADK_53:;
ZfM_29(Z126, (STRING)"LOOP", 4L);
break;
case ZqxDADK_54:;
ZfM_29(Z126, (STRING)"MOD", 3L);
break;
case ZqxDADK_55:;
ZfM_29(Z126, (STRING)"MODULE", 6L);
break;
case ZqxDADK_56:;
ZfM_29(Z126, (STRING)"NOT", 3L);
break;
case ZqxDADK_57:;
ZfM_29(Z126, (STRING)"OF", 2L);
break;
case ZqxDADK_58:;
ZfM_29(Z126, (STRING)"OR", 2L);
break;
case ZqxDADK_59:;
ZfM_29(Z126, (STRING)"POINTER", 7L);
break;
case ZqxDADK_60:;
ZfM_29(Z126, (STRING)"PROCEDURE", 9L);
break;
case ZqxDADK_61:;
ZfM_29(Z126, (STRING)"QUALIFIED", 9L);
break;
case ZqxDADK_62:;
ZfM_29(Z126, (STRING)"RECORD", 6L);
break;
case ZqxDADK_63:;
ZfM_29(Z126, (STRING)"REPEAT", 6L);
break;
case ZqxDADK_64:;
ZfM_29(Z126, (STRING)"RETURN", 6L);
break;
case ZqxDADK_65:;
ZfM_29(Z126, (STRING)"SET", 3L);
break;
case ZqxDADK_66:;
ZfM_29(Z126, (STRING)"THEN", 4L);
break;
case ZqxDADK_67:;
ZfM_29(Z126, (STRING)"TO", 2L);
break;
case ZqxDADK_68:;
ZfM_29(Z126, (STRING)"TYPE", 4L);
break;
case ZqxDADK_69:;
ZfM_29(Z126, (STRING)"UNTIL", 5L);
break;
case ZqxDADK_70:;
ZfM_29(Z126, (STRING)"VAR", 3L);
break;
case ZqxDADK_71:;
ZfM_29(Z126, (STRING)"WHILE", 5L);
break;
case ZqxDADK_72:;
ZfM_29(Z126, (STRING)"WITH", 4L);
break;
case ZqxDADK_73:;
ZfM_29(Z126, (STRING)"FOREIGN", 7L);
break;
case ZqxDADK_74:;
ZfM_29(Z126, (STRING)"REF", 3L);
break;
case ZqxDADK_75:;
ZfM_29(Z126, (STRING)"EXTERNAL", 8L);
break;
default:
ZfM_29(Z126, (STRING)"illegal token code", 18L);
break;
}
}

void BEGIN_Tokens ARGS ((void))
{
  static BOOLEAN has_been_called = FALSE;
  if (has_been_called) return;
  has_been_called = TRUE;
BEGIN_IO ();
BEGIN_IO ();

}
