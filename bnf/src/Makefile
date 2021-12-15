LIB	= $(HOME)/lib
BIN	= $(HOME)/bin
M2FLAGS	= -cuw
MC	= MC
MLIB	= ../../reuse/src
FRONT	= ../../front/src

DEFSMC	= ArgCheck.md MakeBNF.md
MODSMC	= ArgCheck.mi bnf.mi MakeBNF.mi

bnf:	$(DEFSMC) $(MODSMC)
	echo p bnf | mc -d $(FRONT) -d $(MLIB)

install: bnf bnf.sh $(LIB)/lalr
	if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi
	sed 's;LIB;$(LIB);' < bnf.sh > $(BIN)/bnf
	chmod a+rx $(BIN)/bnf
	install -c -s -m 755 bnf $(LIB)/lalr

# installation directories

$(LIB)/lalr: $(LIB)
	sh -c "if test ! -d $(LIB)/lalr; then mkdir -p $(LIB)/lalr; else true; fi"

m2c:
	make sources M2FLAGS="$(M2FLAGS) -d../../front/src -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make sources M2FLAGS="-c -d../../front/src -d../../reuse/src -o../m" -f ../m/Makefile

sources:

clean CLEAN:
	rm -f core *.[dor] *.def *.mod *.sym bnf

.SUFFIXES: .def .mod .md .mi

.md.def:
	ln $*.md $*.def

.mi.mod:
	ln $*.mi $*.mod
