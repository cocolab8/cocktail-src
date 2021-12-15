BIN	= $(HOME)/bin
LIB	= $(HOME)/lib
MLIB	= ../../reuse/src
MC	= MC
M2FLAGS	= -cuw

DEFSMC	= Classes.md DefTable.md Dfa.md Nfa.md GenTabs.md \
	  ScanGen.md ScanTabs.md Traces.md Tree.md

MODSMC	= Classes.mi DefTable.mi Dfa.mi Nfa.mi GenTabs.mi \
	  ScanTabs.mi Traces.mi Tree.mi rex.mi

DEFSM2C	= Classes.def DefTable.def Dfa.def Nfa.def GenTabs.def \
	  ScanGen.def ScanTabs.def Traces.def Tree.def

MODSM2C	= Classes.mod DefTable.mod Dfa.mod Nfa.mod GenTabs.mod \
	  ScanTabs.mod Traces.mod Tree.mod rex.mod

SOURCES	= Scanner.md Scanner.mi Parser.md Parser.mi \
	  Tree0.md Tree0.mi Eval.md Eval.mi

rex:	$(MC)
	# avoid implicit rule

sources:	$(SOURCES)

# compilation of Rex with MOCKA (mc)

MC:	$(SOURCES) MC_boot
	# avoid implicit rule

MC_boot:	$(DEFSMC) $(MODSMC)
	echo p rex | mc -d $(MLIB)

Scanner.mi Scanner.md:	rex.rex
	@echo expect 2 warnings
	rex -di rex.rex

# compilation of Rex with SUN Modula compiler

M2C:	$(SOURCES) M2C_boot
	# avoid implicit rule

M2C_boot:	$(DEFSM2C) $(MODSM2C)
	ln Scanner.md Scanner.def
	ln Scanner.mi Scanner.mod
	ln Parser.md Parser.def
	ln Parser.mi Parser.mod
	make -f MakefileM2C LIB=$(MLIB)

Scanner.mod Scanner.def:	rex.rex
	rex -di rex.rex

# generation of the parser using 'lark'

Parser.mi Parser.md:	rex.lrk
	lark -di rex.lrk

Parser.mod Parser.def:	rex.lrk
	lark -di rex.lrk
	ln Parser.mi Parser.mod
	ln Parser.md Parser.def

Tree0.md Tree0.mi:	rex.cg
	cg -dimtwFDIe rex.cg

Eval.md Eval.mi:	rex.cg
	ag -DI rex.cg

install:	rex rex.sh $(LIB)/rex
	sh -c "if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi"
	sed "s;LIB;$(LIB);g" < rex.sh > $(BIN)/rex
	chmod a+rx $(BIN)/rex
	install -c -m 755 gupd $(BIN)
	install -c -m 755 gcpp $(BIN)
	install -c -s -m 755 rex $(LIB)/rex
	cp ../lib/S* ../lib/*.e ../lib/*.ad? $(LIB)/rex
	chmod a+r $(LIB)/rex/S* $(LIB)/rex/*.e $(LIB)/rex/*.ad?

# installation directories

$(LIB)/rex:	$(LIB)
	sh -c "if test ! -d $(LIB)/rex; then mkdir -p $(LIB)/rex; else true; fi"

m2c:
	make $(SOURCES)
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

# support for mkid

rexId:	rex.rex
	echo SCANNER rexId | cat - rex.rex | \
	sed 's/\(RETURN.*Ident\)/yyEcho; IO.WriteNl (IO.StdOutput); \1/' | \
	rex -sdi
	sed 's/@/rexId/' < ../../front/src/Id.mi > rexIdDrv.mi
	echo p rexIdDrv | mc -d $(MLIB)
	mv rexIdDrv rexId

installId:	rexId $(LIB)/Id
	echo exec $(LIB)/Id/rexId -l$(LIB)/Id "2> /dev/null" > $(BIN)/rexId
	chmod a+rx $(BIN)/rexId
	install -c -s -m 755 rexId $(LIB)/Id

$(LIB)/Id:	$(LIB)
	sh -c "if test ! -d $(LIB)/Id; then mkdir -p $(LIB)/Id; else true; fi"

cleanId:
	rm -f rexId*

clean:	cleanId
	rm -f core *.[dimor] *.def *.mod *.sym ERRORS LISTING _Debug rex *.bak

CLEAN:	clean
	rm -f $(SOURCES)

.SUFFIXES:	.def .mod .md .mi

.md.def:
	ln $*.md $*.def

.mi.mod:
	ln $*.mi $*.mod
