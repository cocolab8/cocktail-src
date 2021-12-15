DIR	= $(HOME)
BIN	= $(DIR)/bin
OPT	= -O
CC	= cc
INSTALL		= /bin/install -c
INSTALL_PROGRAM	= $(INSTALL)
INSTALL_DATA	= $(INSTALL) -m 644

                # C library (reuse)
REUSE	= ../../reuse/m2c

                # C library (common)
COMMON	= ../../common/m2c

                # options for C compiler
CFLAGS	= -w -I$(COMMON) -I$(REUSE) $(OPT)

                # options for linker
LDFLAGS	= -s $(COMMON)/libcommn.a $(REUSE)/libreuse.a

M2FLAGS	= -c

all	: mpp

install	: mpp
	$(INSTALL_PROGRAM) mpp $(BIN)

image	: mpp
	$(INSTALL_PROGRAM) mpp $(BIN)

lint	:
	lint -I$(REUSE) -u *.c


# HEAD

sources	: Parser.h
sources	: Parser.c
sources	: Scanner.h
sources	: Scanner.c
sources	: Table.h
sources	: Table.c
sources	: mpp.c
all	: mpp

Parser.o	: Parser.c	\
	Parser.h	\
	Table.h	\
	Scanner.h

Scanner.o	: Scanner.c	\
	Scanner.h

Table.o	: Table.c	\
	Table.h

mpp.o	: mpp.c	\
	Parser.h	\
	Table.h	\
	Scanner.h

SYSTEM_.o	: SYSTEM_.c SYSTEM_.h

mpp	: $(SYSTEM)	\
	mpp.o	\
	Parser.o	\
	Table.o	\
	Scanner.o	\
;	$(CC) $(CFLAGS) -o mpp $(SYSTEM)	\
	mpp.o	\
	Parser.o	\
	Table.o	\
	Scanner.o	\
	$(LDFLAGS)

# TAIL

clean	:
	rm -f core *.o

.SUFFIXES: .md .mi .h .c .o

.mi.c:
	mtc2 $(M2FLAGS) $*.mi

.md.h:
	mtc2 $(M2FLAGS) $*.md

.c.o:
	$(CC) $(CFLAGS) -c $*.c
