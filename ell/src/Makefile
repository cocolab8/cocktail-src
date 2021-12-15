BIN	= $(HOME)/bin
LIB	= $(HOME)/lib

M2FLAGS	= -cuw

DEFS	= ArgCheck.md Codes.md Derivabl.md First.md Follow.md \
	  Reachabl.md Stack.md Table.md Types.md
IMPS	=             Codes.mi Derivabl.mi First.mi Follow.mi \
	  Reachabl.mi Stack.mi Table.mi Types.mi

GENDEFS	= CodeC.md CodeM2.md Parser.md Scanner.md Semantic.md Tree.md
GENIMPS	= CodeC.mi CodeM2.mi Parser.mi Scanner.mi Semantic.mi Tree.mi ArgCheck.mi

SOURCES	= $(GENDEFS) $(GENIMPS)

all:	ell

sources: $(SOURCES)

ell:	$(SOURCES) ell_boot
	# avoid implicit rule

ell_boot: $(DEFS) $(IMPS) ell.mi
	echo p ell | mc -d ../../reuse/src

install: ell ell.sh $(LIB)/ell
	if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi
	sed "s;LIB;$(LIB);g" < ell.sh > $(BIN)/ell
	chmod a+rx $(BIN)/ell
	install -c -s -m 755 ell $(LIB)/ell

# installation directories

$(LIB)/ell: $(LIB)
	sh -c "if test ! -d $(LIB)/ell; then mkdir -p $(LIB)/ell; else true; fi"

Scanner.mi Scanner.md:	ell.rex
	rex -di ell.rex

Parser.mi Parser.md:	ell.ell
	ell -di ell.ell

Tree.mi Tree.md:	ell.ast
	cg -dimR ell.ast

Semantic.md Semantic.mi: Sem.estra
	estra -dibW Sem.estra

CodeC.md CodeC.mi:	CodeC.ESTRA
	mpp < CodeC.ESTRA | estra -dibW

CodeM2.md CodeM2.mi:	CodeM2.ESTRA
	mpp < CodeM2.ESTRA | estra -dibW

ArgCheck.mi:	ArgCheck.mi.mpp
	mpp < ArgCheck.mi.mpp > ArgCheck.mi

m2c:
	make $(GENDEFS) $(GENIMPS) $(DEFS) $(IMPS) ell.mi
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(GENDEFS) $(GENIMPS) $(DEFS) $(IMPS) ell.mi
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

clean:
	rm -f core* ERRORS LISTING *.[dimor] ell

CLEAN:	clean
	rm -f $(SOURCES)
