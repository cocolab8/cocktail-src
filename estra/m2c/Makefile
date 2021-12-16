DIR	= $(HOME)
BIN	= $(DIR)/bin
LIB	= $(DIR)/lib
OPT	= -O
CC	= cc

                # C library (reuse)
REUSE	= ../../reuse/m2c

                # C library (common)
COMMON	= ../../common/m2c

                # options for C compiler
CFLAGS	= -w -I $(COMMON) -I $(REUSE) $(OPT)

                # options for linker
LDFLAGS	= -s $(COMMON)/libcommn.a $(REUSE)/libreuse.a

M2FLAGS	= -c

all	: estra

install:	estra estra.sh $(LIB)/estra
	sh -c "if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi"
	sed "s;LIB;$(LIB);" < estra.sh > $(BIN)/estra
	chmod a+rx $(BIN)/estra
	install -c -s -m 755 estra $(LIB)/estra
	install -c -m 644 ErrorTab $(LIB)/estra

# installation directories

$(LIB)/estra:
	mkdir -p $(LIB)/estra


# HEAD

sources	: ArgCheck.h
sources	: ArgCheck.c
sources	: Automaton.h
sources	: Automaton.c
sources	: CodeM2.h
sources	: CodeM2.c
sources	: Complete.h
sources	: Complete.c
sources	: Environs.h
sources	: Environs.c
sources	: Grammar.h
sources	: Grammar.c
sources	: Info.h
sources	: Info.c
sources	: Match.h
sources	: Match.c
sources	: Parser.h
sources	: Parser.c
sources	: Patterns.h
sources	: Patterns.c
sources	: Reduced.h
sources	: Reduced.c
sources	: Scanner.h
sources	: Scanner.c
sources	: Semantics.h
sources	: Semantics.c
sources	: Test.h
sources	: Test.c
sources	: Tree.h
sources	: Tree.c
sources	: Types.h
sources	: Types.c
sources	: estra.c
all	: estra

ArgCheck.o	: ArgCheck.c	\
	ArgCheck.h	\
	Scanner.h

Automaton.o	: Automaton.c	\
	Automaton.h	\
	Info.h	\
	Patterns.h	\
	Types.h	\
	Scanner.h	\
	Grammar.h

CodeM2.o	: CodeM2.c	\
	CodeM2.h	\
	Types.h	\
	Tree.h	\
	Patterns.h	\
	Scanner.h	\
	Parser.h	\
	Match.h	\
	Grammar.h	\
	Info.h	\
	Environs.h	\
	Automaton.h	\
	ArgCheck.h

Complete.o	: Complete.c	\
	Complete.h	\
	Patterns.h	\
	Types.h	\
	Scanner.h	\
	Grammar.h	\
	Info.h	\
	Environs.h

Environs.o	: Environs.c	\
	Environs.h	\
	Types.h	\
	Scanner.h	\
	Grammar.h	\
	Info.h	\
	Patterns.h

Grammar.o	: Grammar.c	\
	Grammar.h	\
	Info.h	\
	Patterns.h	\
	Types.h	\
	Scanner.h

Info.o	: Info.c	\
	Info.h	\
	Patterns.h	\
	Types.h	\
	Scanner.h	\
	Grammar.h

Match.o	: Match.c	\
	Match.h	\
	Types.h	\
	Scanner.h	\
	Patterns.h	\
	Parser.h	\
	Tree.h	\
	Grammar.h	\
	Info.h	\
	Environs.h	\
	Automaton.h	\
	ArgCheck.h

Parser.o	: Parser.c	\
	Parser.h	\
	Scanner.h	\
	Tree.h	\
	Patterns.h	\
	Types.h	\
	Grammar.h	\
	Info.h	\
	Environs.h

Patterns.o	: Patterns.c	\
	Patterns.h	\
	Types.h	\
	Scanner.h	\
	Grammar.h	\
	Info.h

Reduced.o	: Reduced.c	\
	Reduced.h	\
	Types.h	\
	Scanner.h	\
	Grammar.h	\
	Info.h	\
	Patterns.h

Scanner.o	: Scanner.c	\
	Scanner.h

Semantics.o	: Semantics.c	\
	Semantics.h	\
	Types.h	\
	Tree.h	\
	Scanner.h	\
	Reduced.h	\
	Patterns.h	\
	Parser.h	\
	Grammar.h	\
	Info.h	\
	Environs.h	\
	Complete.h

Test.o	: Test.c	\
	Test.h	\
	ArgCheck.h	\
	Scanner.h

Tree.o	: Tree.c	\
	Tree.h	\
	Patterns.h	\
	Types.h	\
	Scanner.h	\
	Grammar.h	\
	Info.h	\
	Environs.h

Types.o	: Types.c	\
	Types.h	\
	Scanner.h

estra.o	: estra.c	\
	Tree.h	\
	Patterns.h	\
	Types.h	\
	Scanner.h	\
	Environs.h	\
	Grammar.h	\
	Test.h	\
	Semantics.h	\
	Reduced.h	\
	Complete.h	\
	Parser.h	\
	Match.h	\
	Automaton.h	\
	Info.h	\
	CodeM2.h	\
	ArgCheck.h

SYSTEM_.o	: SYSTEM_.c SYSTEM_.h

estra	: $(SYSTEM)	\
	estra.o	\
	Tree.o	\
	Patterns.o	\
	Types.o	\
	Scanner.o	\
	Environs.o	\
	Grammar.o	\
	Test.o	\
	Semantics.o	\
	Reduced.o	\
	Complete.o	\
	Parser.o	\
	Match.o	\
	Automaton.o	\
	Info.o	\
	CodeM2.o	\
	ArgCheck.o	\
;	$(CC) $(CFLAGS) -o estra $(SYSTEM)	\
	estra.o	\
	Tree.o	\
	Patterns.o	\
	Types.o	\
	Scanner.o	\
	Environs.o	\
	Grammar.o	\
	Test.o	\
	Semantics.o	\
	Reduced.o	\
	Complete.o	\
	Parser.o	\
	Match.o	\
	Automaton.o	\
	Info.o	\
	CodeM2.o	\
	ArgCheck.o	\
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
