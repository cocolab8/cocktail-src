LIB	= $(HOME)/lib
BIN	= $(HOME)/bin
MLIB	= ../../reuse/src
MC	= MC
M2FLAGS	= -cuw

DEFSMC	= Actions.md Characte.md Checks.md Errors.md \
	  Listing.md Oper.md Path.md Rules.md \
	  SysError.md TokenTab.md Tokens.md WriteTok.md

MODSMC	= Actions.mi Characte.mi Checks.mi Errors.mi \
	  Listing.mi Oper.mi Pars.mi Path.mi Rules.mi \
	  SysError.mi TokenTab.mi Tokens.mi WriteTok.mi

SOURCES	= Scanner.md Scanner.mi Parser.md Parser.mi

all:	Pars

sources: $(SOURCES)

Pars:	$(SOURCES) Pars_boot
	# avoid implicit rule

Pars_boot: $(DEFSMC) $(MODSMC)
	echo p Pars | mc -d $(MLIB)

Scanner.md Scanner.mi: input.rex
	rex -di input.rex

Parser.md Parser.mi: input.lrk
	bnf input.lrk | lark -di

install: ErrorTab $(LIB)/lalr
	install -c -m 644 ErrorTab $(LIB)/lalr

# installation directories

$(LIB)/lalr:
	mkdir -p $(LIB)/lalr

m2c:
	make $(SOURCES)
	cp ErrorTab ../m2c
	chmod u+w ../m2c/ErrorTab
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	cp ErrorTab ../m
	chmod u+w ../m/ErrorTab
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

# support for mkid

lalrId:	input.rex
	echo SCANNER lalrId | cat - input.rex | \
	sed 's/\(RETURN.*Ident\)/yyEcho; IO.WriteNl (IO.StdOutput); \1/' | \
	$(BIN).sparc.t/rex -sdi
	sed 's/@/lalrId/' < ../../front/src/Id.mi > lalrIdDrv.mi
	echo p lalrIdDrv | mc -d $(MLIB)
	mv lalrIdDrv lalrId

installId: lalrId $(LIB)/Id
	echo exec $(LIB)/Id/lalrId -l$(LIB)/Id "2> /dev/null" > $(BIN)/lalrId
	chmod a+rx $(BIN)/lalrId
	install -c -s -m 755 lalrId $(LIB)/Id

$(LIB)/Id:
	mkdir -p $(LIB)/Id

cleanId:
	rm -f lalrId*

clean:	cleanId
	rm -f core *.[dimor] *.def *.mod *.sym ERRORS LISTING *.dbg Pars

CLEAN:	clean
	rm -f Scanner* Parser*

.SUFFIXES: .def .mod .md .mi

.md.def:
	ln $*.md $*.def

.mi.mod:
	ln $*.mi $*.mod
