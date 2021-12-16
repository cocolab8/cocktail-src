DIR	= $(HOME)
BIN	= $(DIR)/bin
LIB	= $(DIR)/lib
OPT	= -O
CC	= cc
INSTALL		= /usr/bin/install -c
INSTALL_PROGRAM	= $(INSTALL)
INSTALL_DATA	= $(INSTALL) -m 644

                # C library (reuse)
REUSE	= ../../reuse/m2c

                # options for C compiler
CFLAGS	= -w -I$(REUSE) $(OPT)

                # options for linker
LDFLAGS	= -s $(REUSE)/libreuse.a

                # options for mtc2
M2FLAGS	= -c

                # "runtime system"
RTS	= SYSTEM_.h SYSTEM_.c Argument.h Argument.c

all	:

install:	mtc2 $(BIN) $(LIB)/mtc2
	sh -c "if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi"
	$(INSTALL_PROGRAM) mtc2 $(BIN)
	cp $(RTS) $(LIB)/mtc2
	chmod a+r $(LIB)/mtc2/*.[hc]

# installation directories

$(BIN):
	mkdir -p $(BIN)

$(LIB)/mtc2:
	mkdir -p $(LIB)/mtc2


# HEAD

sources	: AssocTab.h
sources	: AssocTab.c
sources	: Base.h
sources	: Base.c
sources	: Code.h
sources	: Code.c
sources	: DefMods.h
sources	: DefMods.c
sources	: Defs.h
sources	: Defs.c
sources	: Errors.h
sources	: Errors.c
sources	: GenIdent.h
sources	: GenIdent.c
sources	: Parser.h
sources	: Parser.c
sources	: Position.h
sources	: Position.c
sources	: Scanner.h
sources	: Scanner.c
sources	: Semantic.h
sources	: Semantic.c
sources	: Source.h
sources	: Source.c
sources	: Tokens.h
sources	: Tokens.c
sources	: Tree.h
sources	: Tree.c
sources	: Types.h
sources	: Types.c
sources	: UniqueId.h
sources	: UniqueId.c
sources	: Values.h
sources	: Values.c
sources	: mtc2.c
all	: mtc2

AssocTab.o	: AssocTab.c	\
	AssocTab.h

Base.o	: Base.c	\
	Base.h

Code.o	: Code.c	\
	Code.h	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Position.h	\
	GenIdent.h	\
	AssocTab.h	\
	Types.h	\
	Values.h	\
	Defs.h	\
	Base.h	\
	Tree.h	\
	UniqueId.h

DefMods.o	: DefMods.c	\
	DefMods.h	\
	AssocTab.h	\
	Defs.h	\
	GenIdent.h	\
	Values.h	\
	Types.h	\
	Code.h	\
	Position.h	\
	Errors.h	\
	Parser.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Base.h	\
	Tree.h	\
	UniqueId.h

Defs.o	: Defs.c	\
	Defs.h	\
	GenIdent.h	\
	Base.h	\
	Tree.h	\
	UniqueId.h	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Position.h	\
	Values.h	\
	Types.h	\
	Code.h	\
	AssocTab.h

Errors.o	: Errors.c	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Position.h

GenIdent.o	: GenIdent.c	\
	GenIdent.h	\
	Base.h

Parser.o	: Parser.c	\
	Parser.h	\
	Defs.h	\
	GenIdent.h	\
	Base.h	\
	Values.h	\
	Types.h	\
	Code.h	\
	AssocTab.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Errors.h	\
	Position.h	\
	Tree.h	\
	UniqueId.h

Position.o	: Position.c	\
	Position.h

Scanner.o	: Scanner.c	\
	Scanner.h	\
	Errors.h	\
	Source.h	\
	Position.h	\
	Tokens.h

Semantic.o	: Semantic.c	\
	Semantic.h	\
	Code.h	\
	AssocTab.h	\
	Base.h	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Position.h	\
	Types.h	\
	GenIdent.h	\
	Defs.h	\
	Values.h	\
	UniqueId.h	\
	Tree.h

Source.o	: Source.c	\
	Source.h	\
	Scanner.h	\
	Errors.h	\
	Position.h	\
	Tokens.h

Tokens.o	: Tokens.c	\
	Tokens.h

Tree.o	: Tree.c	\
	Tree.h	\
	UniqueId.h	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Values.h	\
	Types.h	\
	Code.h	\
	GenIdent.h	\
	AssocTab.h	\
	Base.h	\
	Defs.h	\
	Position.h

Types.o	: Types.c	\
	Types.h	\
	Code.h	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Position.h	\
	GenIdent.h	\
	AssocTab.h	\
	Tree.h	\
	UniqueId.h	\
	Base.h	\
	Defs.h	\
	Values.h

UniqueId.o	: UniqueId.c	\
	UniqueId.h	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Position.h

Values.o	: Values.c	\
	Values.h	\
	Types.h	\
	Code.h	\
	Errors.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Position.h	\
	GenIdent.h	\
	AssocTab.h	\
	Base.h	\
	Defs.h	\
	Tree.h	\
	UniqueId.h

mtc2.o	: mtc2.c	\
	Errors.h	\
	Position.h	\
	Code.h	\
	GenIdent.h	\
	AssocTab.h	\
	Types.h	\
	Values.h	\
	Semantic.h	\
	UniqueId.h	\
	Defs.h	\
	DefMods.h	\
	Tree.h	\
	Parser.h	\
	Scanner.h	\
	Source.h	\
	Tokens.h	\
	Base.h

SYSTEM_.o	: SYSTEM_.c SYSTEM_.h

mtc2	: $(SYSTEM)	\
	mtc2.o	\
	Errors.o	\
	Position.o	\
	Code.o	\
	GenIdent.o	\
	AssocTab.o	\
	Types.o	\
	Values.o	\
	Semantic.o	\
	UniqueId.o	\
	Defs.o	\
	DefMods.o	\
	Tree.o	\
	Parser.o	\
	Scanner.o	\
	Source.o	\
	Tokens.o	\
	Base.o	\
;	$(CC) $(CFLAGS) -o mtc2 $(SYSTEM)	\
	mtc2.o	\
	Errors.o	\
	Position.o	\
	Code.o	\
	GenIdent.o	\
	AssocTab.o	\
	Types.o	\
	Values.o	\
	Semantic.o	\
	UniqueId.o	\
	Defs.o	\
	DefMods.o	\
	Tree.o	\
	Parser.o	\
	Scanner.o	\
	Source.o	\
	Tokens.o	\
	Base.o	\
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
