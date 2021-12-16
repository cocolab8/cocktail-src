BIN	= $(HOME)/bin
LIB	= $(HOME)/lib

M2FLAGS	= -cuw

DEFS	= ArgCheck.md Automaton.md CodeM2.md Complete.md	\
	  Environs.md Grammar.md Info.md Match.md Patterns.md	\
	  Reduced.md Semantics.md Test.md Types.md
IMPS	= ArgCheck.mi Automaton.mi CodeM2.mi Complete.mi	\
	  Environs.mi Grammar.mi Info.mi Match.mi Patterns.mi	\
	  Reduced.mi Semantics.mi Test.mi Types.mi
GENDEFS	= Parser.md Scanner.md Tree.md 
GENIMPS	= Parser.mi Scanner.mi Tree.mi 

SOURCES	= CodeM2.mi Parser.md Parser.mi Scanner.md Scanner.mi Tree.md Tree.mi

all:	estra

sources: $(SOURCES)

estra:	$(GENDEFS) $(GENIMPS) estra_boot
	# avoid implicit rule

estra_boot:	$(DEFS) $(IMPS) estra.mi
	rm -f estra
	echo p estra | mc -d ../../common/src -d ../../reuse/src

Tree.md Tree.mi:	Tree.ast
	cg -diwmR Tree.ast

Parser.md Parser.mi:	Estral.lalr
	lark -di Estral.lalr

Scanner.md Scanner.mi:	Estral.rex
	rex -di Estral.rex

CodeM2.mi:	CodeM2.mi.mpp
	mpp < CodeM2.mi.mpp > CodeM2.mi

install:	estra estra.sh $(LIB)/estra
	sed 's;LIB;$(LIB);' < estra.sh > $(BIN)/estra
	chmod a+rx $(BIN)/estra
	install -c -s -m 755 estra $(LIB)/estra
	install -c -m 644 ErrorTab $(LIB)/estra

# installation directories

$(LIB)/estra:
	mkdir -p $(LIB)/estra

m2c:
	make $(GENDEFS) $(GENIMPS) $(DEFS) $(IMPS) estra.mi
	chmod u+w ErrorTab
	cp ErrorTab ../m2c
	make sources M2FLAGS="$(M2FLAGS) -d../../common/src -d../../reuse/src -o../m2c" -f ../m2c/Makefile

clean:
	rm -f core *.[dimor] ERRORS LISTING _Debug *.bak

CLEAN:	clean
	rm -f $(SOURCES) estra
