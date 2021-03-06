EXPORT {
# include "Position.h"
typedef struct { tPosition Position; } tScanAttribute;
}

GLOBAL {
/* # undef yyEolCh
# define yyEolCh (unsigned char) 0x25
*/
# define xxGetWord
}

DEFAULT {
   (void) printf ("%ld, %d: illegal character: ",
      Attribute.Position.Line, Attribute.Position.Column);
   yyEcho;
   (void) printf ("\n");
}

EOF {
if (yyStartState == Comment) (void) printf ("unclosed comment\n");
}

CHARACTER_SET {
0x04	0x37
0x05	0x2d
0x06	0x2e
0x07	0x2f
0x08	0x16
0x09	0x05
0x0a	0x25
0x14	0x3c
0x15	0x3d
0x16	0x32
0x17	0x26
0x1a	0x3f
0x1b	0x27
\ 	0x40
!	0x4f
"	0x7f
#	0x7b
$	0x5b
%	0x6c
&	0x50
'	0x7d
(	0x4d
)	0x5d
*	0x5c
+	0x4e
,	0x6b
-	0x60
.	0x4b
/	0x61
0	0xf0
1	0xf1
2	0xf2
3	0xf3
4	0xf4
5	0xf5
6	0xf6
7	0xf7
8	0xf8
9	0xf9
:	0x7a
;	0x5e
<	0x4c
=	0x7e
>	0x6e
?	0x6f
@	0x7c
A	0xc1
B	0xc2
C	0xc3
D	0xc4
E	0xc5
F	0xc6
G	0xc7
H	0xc8
I	0xc9
J	0xd1
K	0xd2
L	0xd3
M	0xd4
N	0xd5
O	0xd6
P	0xd7
Q	0xd8
R	0xd9
S	0xe2
T	0xe3
U	0xe4
V	0xe5
W	0xe6
X	0xe7
Y	0xe8
Z	0xe9
[	0x4a
\\	0xe0
]	0x5a
^	0x5f
_	0x6d
`	0x79
a	0x81
b	0x82
c	0x83
d	0x84
e	0x85
f	0x86
g	0x87
h	0x88
i	0x89
j	0x91
k	0x92
l	0x93
m	0x94
n	0x95
o	0x96
p	0x97
q	0x98
r	0x99
s	0xa2
t	0xa3
u	0xa4
v	0xa5
w	0xa6
x	0xa7
y	0xa8
z	0xa9
{	0xc0
|	0x6a
}	0xd0
~	0xa1
0x7f	0x07
0x80	0x20
0x81	0x21
0x82	0x22
0x83	0x23
0x84	0x24
0x85	0x15
0x86	0x06
0x87	0x17
0x88	0x28
0x89	0x29
0x8a	0x2a
0x8b	0x2b
0x8c	0x2c
0x8d	0x09
0x8e	0x0a
0x8f	0x1b
0x90	0x30
0x91	0x31
0x92	0x1a
0x93	0x33
0x94	0x34
0x95	0x35
0x96	0x36
0x97	0x08
0x98	0x38
0x99	0x39
0x9a	0x3a
0x9b	0x3b
0x9c	0x04
0x9d	0x14
0x9e	0x3e
0x9f	0xe1
0xa0	0x41
0xa1	0x42
0xa2	0x43
0xa3	0x44
0xa4	0x45
0xa5	0x46
0xa6	0x47
0xa7	0x48
0xa8	0x49
0xa9	0x51
0xaa	0x52
0xab	0x53
0xac	0x54
0xad	0x55
0xae	0x56
0xaf	0x57
0xb0	0x58
0xb1	0x59
0xb2	0x62
0xb3	0x63
0xb4	0x64
0xb5	0x65
0xb6	0x66
0xb7	0x67
0xb8	0x68
0xb9	0x69
0xba	0x70
0xbb	0x71
0xbc	0x72
0xbd	0x73
0xbe	0x74
0xbf	0x75
0xc0	0x76
0xc1	0x77
0xc2	0x78
0xc3	0x80
0xc4	0x8a
0xc5	0x8b
0xc6	0x8c
0xc7	0x8d
0xc8	0x8e
0xc9	0x8f
0xca	0x90
0xcb	0x9a
0xcc	0x9b
0xcd	0x9c
0xce	0x9d
0xcf	0x9e
0xd0	0x9f
0xd1	0xa0
0xd2	0xaa
0xd3	0xab
0xd4	0xac
0xd5	0xad
0xd6	0xae
0xd7	0xaf
0xd8	0xb0
0xd9	0xb1
0xda	0xb2
0xdb	0xb3
0xdc	0xb4
0xdd	0xb5
0xde	0xb6
0xdf	0xb7
0xe0	0xb8
0xe1	0xb9
0xe2	0xba
0xe3	0xbb
0xe4	0xbc
0xe5	0xbd
0xe6	0xbe
0xe7	0xbf
0xe8	0xca
0xe9	0xcb
0xea	0xcc
0xeb	0xcd
0xec	0xce
0xed	0xcf
0xee	0xda
0xef	0xdb
0xf0	0xdc
0xf1	0xdd
0xf2	0xde
0xf3	0xdf
0xf4	0xea
0xf5	0xeb
0xf6	0xec
0xf7	0xed
0xf8	0xee
0xf9	0xef
}

DEFINE
   digit	= {0-9}		.
   letter	= {a-z A-Z}	.
   CmtCh	= - {*(\t\n}	.

START Comment

RULE

#STD, Comment# "(*" 	:- {yyPush (Comment);}
#Comment#  "*)"		:- {yyPop ();}
#Comment#  "(" | "*" | CmtCh + :- {}

#STD# digit +		,
#STD# digit + / ".."   	: {return 1;}
#STD# {0-7} + B        	: {return 2;}
#STD# {0-7} + C        	: {return 3;}
#STD# digit {0-9 A-F} * H : {return 4;}
#STD# digit + "." digit * (E {+\-} ? digit +) ?	: {return 5;}

#STD# ' - {\n'} * '	|
      \" - {\n"} * \" 	: {return 6;}

#STD# "#"              	: {return 7;}
#STD# "&"              	: {return 8;}
#STD# "("              	: {return 9;}
#STD# ")"              	: {return 10;}
#STD# "*"              	: {return 11;}
#STD# "+"              	: {return 12;}
#STD# ","              	: {return 13;}
#STD# "-"              	: {return 14;}
#STD# "."              	: {return 15;}
#STD# ".."             	: {return 16;}
#STD# "/"              	: {return 17;}
#STD# ":"              	: {return 18;}
#STD# ":="             	: {return 19;}
#STD# ";"              	: {return 20;}
#STD# "<"              	: {return 21;}
#STD# "<="             	: {return 22;}
#STD# "<>"             	: {return 23;}
#STD# "="              	: {return 24;}
#STD# ">"              	: {return 25;}
#STD# ">="             	: {return 26;}
#STD# "["              	: {return 27;}
#STD# "]"              	: {return 28;}
#STD# "^"              	: {return 29;}
#STD# "{"              	: {return 30;}
#STD# "|"              	: {return 31;}
#STD# "}"              	: {return 32;}
#STD# "~"              	: {return 33;}

#STD# AND              	: {return 34;}
#STD# ARRAY            	: {return 35;}
#STD# BEGIN           	: {return 36;}
#STD# BY               	: {return 37;}
#STD# CASE             	: {return 38;}
#STD# CONST            	: {return 39;}
#STD# DEFINITION       	: {return 40;}
#STD# DIV              	: {return 41;}
#STD# DO               	: {return 42;}
#STD# ELSE             	: {return 43;}
#STD# ELSIF            	: {return 44;}
#STD# END              	: {return 45;}
#STD# EXIT             	: {return 46;}
#STD# EXPORT          	: {return 47;}
#STD# FOR              	: {return 48;}
#STD# FROM             	: {return 49;}
#STD# IF               	: {return 50;}
#STD# IMPLEMENTATION   	: {return 51;}
#STD# IMPORT           	: {return 52;}
#STD# IN               	: {return 53;}
#STD# LOOP             	: {return 54;}
#STD# MOD              	: {return 55;}
#STD# MODULE           	: {return 56;}
#STD# \NOT              : {return 57;}
#STD# OF               	: {return 58;}
#STD# OR               	: {return 59;}
#STD# POINTER          	: {return 60;}
#STD# < PROCEDURE       : {return 75;}
#STD# PROCEDURE        	: {return 61;}
#STD# QUALIFIED        	: {return 62;}
#STD# RECORD           	: {return 63;}
#STD# REPEAT           	: {return 64;}
#STD# RETURN           	: {return 65;}
#STD# SET              	: {return 66;}
#STD# THEN             	: {return 67;}
#STD# TO               	: {return 68;}
#STD# TYPE             	: {return 69;}
#STD# UNTIL            	: {return 70;}
#STD# VAR              	: {return 71;}
#STD# WHILE            	: {return 72;}
#STD# WITH             	: {return 73;}

#STD# letter (letter | digit) *	: {return 74;}
