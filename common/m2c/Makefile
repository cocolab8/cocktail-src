OPT	= -O
CC	= cc
RANLIB	= ranlib

                # C library (reuse)
REUSE	= ../../reuse/m2c

                # options for C compiler
CFLAGS	= -I$(REUSE) $(OPT)

                # options for linker
LDFLAGS	= -s $(REUSE)/libreuse.a

M2FLAGS	= -c

OBJS	= Characte.o Checks.o Convert.o Errors.o Listing.o Path.o Queues.o \
	  Stack.o SysError.o


libcommn.a	: $(OBJS)
	ar ruc libcommn.a $(OBJS)
	$(RANLIB) libcommn.a

lint	:
	lint -I$(REUSE) -u *.c


# HEAD

sources	: Characte.h
sources	: Characte.c
sources	: Checks.h
sources	: Checks.c
sources	: Convert.h
sources	: Convert.c
sources	: Errors.h
sources	: Errors.c
sources	: Listing.h
sources	: Listing.c
sources	: Main.c
all	: Main
sources	: Path.h
sources	: Path.c
sources	: Queues.h
sources	: Queues.c
sources	: Stack.h
sources	: Stack.c
sources	: SysError.h
sources	: SysError.c

Characte.o	: Characte.c	\
	Characte.h

Checks.o	: Checks.c	\
	Checks.h	\
	Errors.h	\
	Listing.h	\
	SysError.h

Convert.o	: Convert.c	\
	Convert.h

Errors.o	: Errors.c	\
	Errors.h	\
	SysError.h	\
	Listing.h

Listing.o	: Listing.c	\
	Listing.h

Main.o	: Main.c	\
	SysError.h	\
	Stack.h	\
	Queues.h	\
	Path.h	\
	Listing.h	\
	Errors.h	\
	Checks.h	\
	Characte.h	\
	Convert.h

Path.o	: Path.c	\
	Path.h	\
	Characte.h

Queues.o	: Queues.c	\
	Queues.h	\
	Errors.h	\
	SysError.h	\
	Listing.h

Stack.o	: Stack.c	\
	Stack.h	\
	Errors.h	\
	SysError.h	\
	Listing.h

SysError.o	: SysError.c	\
	SysError.h	\
	Errors.h	\
	Listing.h

SYSTEM_.o	: SYSTEM_.c SYSTEM_.h

Main	: $(SYSTEM)	\
	Main.o	\
	SysError.o	\
	Stack.o	\
	Queues.o	\
	Path.o	\
	Listing.o	\
	Errors.o	\
	Checks.o	\
	Characte.o	\
	Convert.o	\
;	$(CC) $(CFLAGS) -o Main $(SYSTEM)	\
	Main.o	\
	SysError.o	\
	Stack.o	\
	Queues.o	\
	Path.o	\
	Listing.o	\
	Errors.o	\
	Checks.o	\
	Characte.o	\
	Convert.o	\
	$(LDFLAGS)

# TAIL

clean	:
	rm -f core *.o

CLEAN	: clean
	rm -f libcommn.a

.SUFFIXES: .md .mi .h .c .o

.mi.c:
	mtc2 $(M2FLAGS) $*.mi

.md.h:
	mtc2 $(M2FLAGS) $*.md

.c.o:
	$(CC) $(CFLAGS) -c $*.c
