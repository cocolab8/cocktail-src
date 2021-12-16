BIN	= $(HOME)/bin
LIB	= $(HOME)/lib

M2FLAGS	= -cuw

MC	= mc -d ../../reuse/src

CC	= cc
REUSE	= ../../reuse/m2c
CFLAGS	= -w -I../m2c -I$(REUSE) -g
PUMA	= puma
CG_AST	= ../../cg/src/cg.cg

# The following scripts implement a shorthand for write statements.
# The first two are optional, and are used for debugging: they cause
# line numbers to be inserted in generated code which point back to
# the code which generated it.  Two scripts are needed because of the
# two different syntaxes for comments.  Note that we must avoid adding 
# line numbers in certain places, e.g. preprocessor directives and
# some lines in a .rpp file.  We don't add line numbers if !# appears
# in a line (this looks like a preprocessor directive).  Or, add 
# a tilde to such lines as in
#     !no line number please!~
# NB: this code is a bit fragile if you get !...! within comments.

# Add //File:line-number to the end of generated lines
SED_DEBUGC	= sed -e   '/[!@]~$$/ {p' -e 'd' -e '}' \
			-e '/[!@]\#/  {p' -e 'd' -e '}' \
			-e '/[!@]$$/ {p' -e '=' -e 'd' -e '}' | \
		  sed -e '/TRAFO/ {h' -e 's%TRAFO[ \t]*%//%' -e x -e '}' \
			-e '/[!@]~$$/ {p' -e 'd' -e '}' \
			-e '/[!@]\#/  {p' -e 'd' -e '}' \
			-e '/!$$/ {G' -e 's%!\n%		%' -e 'N' -e 's%\n%:%' \
			-e 's/\(.$$\)/\1!/' -e '}' \
			-e '/@$$/ {G' -e 's%@\n%		%' -e 'N' -e 's%\n%:%' \
			-e 's/\(.$$\)/\1@/' -e '}'

# Add (*line-number*) to the end of generated lines
SED_DEBUGM	= sed -e   '/[!@]~$$/ {p' -e 'd' -e '}' \
			-e '/[!@]\#/  {p' -e 'd' -e '}' \
			-e '/[!@]$$/ {p' -e '=' -e 'd' -e '}' | \
		  sed -e '/TRAFO/ {h' -e 's%TRAFO[ \t]*%(*%' -e x -e '}' \
			-e '/[!@]~$$/ {p' -e 'd' -e '}' \
			-e '/[!@]\#/  {p' -e 'd' -e '}' \
			-e '/!$$/ {G' -e 's%!\n%		%' -e 'N' -e 's%\n%:%' \
			-e 's/\(.$$\)/\1*)!/' -e '}' \
			-e '/@$$/ {G' -e 's%@\n%		%' -e 'N' -e 's%\n%:%' \
			-e 's/\(.$$\)/\1*)@/' -e '}'

# Select here if newline is to include flushing buffer (useful to track crashes)
#SED_NL	= WriteNl (f); IO.WriteFlush (f);
SED_NL	= WriteNl (f);

# Convert !...! notation to Modula Write statements.
SED_WRITE	= sed -f puma.sed

# Select here if the debug edit is included
#SEDC	= ($(SED_DEBUGC) | $(SED_WRITE))
SEDC	= $(SED_WRITE)
#SEDM	= ($(SED_DEBUGM) | $(SED_WRITE))
SEDM	= $(SED_WRITE)
SED	= $(SED_WRITE)

SOURCES	= Scanner.md Scanner.mi Parser.md Parser.mi Tree.md Tree.mi \
	  Tree2.md Tree2.mi Semantic.md Semantic.mi Optimize.md Optimize.mi \
	  Eval.md Eval.mi \
	  Mod.md Mod.mi C.md C.mi Cxx.md Cxx.mi Java.md Java.mi puma.mi pumal.mi

all:	puma

sources:	$(SOURCES) Tree.TS puma.rex Parser.lrk Scanner.rpp

puma:	$(SOURCES) puma_boot
	# avoid implicit rule

puma_boot:
	echo p puma | $(MC)

pumal:	$(SOURCES) Tree3.o pumal_boot

pumal_boot:
	echo p pumal | $(MC)

Scanner.rpp Parser.lrk:	puma.pars
	lpp -xzj puma.pars

puma.rex:	puma.scan Scanner.rpp
	rpp < puma.scan > puma.rex

Scanner.md Scanner.mi:	puma.rex
	@echo "expect 4 'default action' warning and 7 'pattern will never match' warnings"
	rex -di puma.rex

Parser.md:	Parser.lrk
	@echo "expect 11 conflict messages"
	lark -divsD -k2 Parser.lrk

Parser.mi:	Parser.lrk
	@echo "expect 11 conflict messages"
	lark -ivsD -k2 Parser.lrk

Parser.dlt Parser.dbg:	Parser.lrk
	@echo "expect 11 conflict messages"
	lark -vsD -k2 Parser.lrk

Tree.md:	$(CG_AST) puma.cg puma.ag
	echo "SELECT AstIn Ast Common PumaIn Puma PumaCF PumaDecls" | \
	cat - $(CG_AST) puma.cg puma.ag | ast -dimRyqe4

Tree.mi:	$(CG_AST) puma.cg puma.ag
	echo "SELECT AstIn Ast Common PumaIn Puma PumaCF PumaDecls" | \
	cat - $(CG_AST) puma.cg puma.ag | ast -imRyqe

Tree2.md:	$(CG_AST)
	echo "SUBUNIT Tree2 SELECT AstIn Ast Tree2" | cat - $(CG_AST) | ast -dig

Tree2.mi:	$(CG_AST)
	echo "SUBUNIT Tree2 SELECT AstIn Ast Tree2" | cat - $(CG_AST) | ast -ig

Tree.TS:	$(CG_AST) puma.cg puma.ag
	echo "SELECT AstIn Ast PumaIn Puma PumaCF PumaDecls" | \
	cat - $(CG_AST) puma.cg puma.ag | ast -4

Semantic.md Semantic.mi patterns:	sem.puma Tree.TS
	$(PUMA) -dinwr sem.puma > patterns

Eval.md Eval.mi:	$(CG_AST) puma.cg puma.ag
	echo "SELECT PumaIn PumaCF PumaDecls" | \
	cat - $(CG_AST) puma.cg puma.ag | ag -DIW

Optimize.md Optimize.mi:	opt.puma Tree.TS
	$(PUMA) -diwk opt.puma

Mod.md Mod.mi:	mod.puma Tree.TS
	$(SED) < mod.puma | $(PUMA) -dinw

C.md C.mi:	c.puma Tree.TS
	$(SED) < c.puma | $(PUMA) -dinw

Cxx.md Cxx.mi:	cxx.puma Tree.TS
	$(SED) < cxx.puma | $(PUMA) -dinw

Java.md Java.mi: java.puma Tree.TS
	$(SEDC) < java.puma | $(PUMA) -dinw

puma.mi:	puma.mi.sed puma.sed
	$(SED) < puma.mi.sed > puma.mi

pumal.mi:	pumal.mi.sed puma.sed
	$(SED) < pumal.mi.sed > pumal.mi

Tree3.c Tree3.h:	$(CG_AST) puma.cg
	echo "SELECT AstIn Ast Common PumaIn Puma" | \
	cat - $(CG_AST) puma.cg | pumagen

Tree3.o: Tree3.c Tree3.h
	$(CC) $(CFLAGS) -c Tree3.c

install:	puma puma.sh $(LIB)/puma
	if test $(LIB) = $(BIN); then echo "error: BIN = LIB"; false; else true; fi
	sed 's;LIB;$(LIB);g' < puma.sh > $(BIN)/puma
	chmod a+rx $(BIN)/puma
	install -c -m 755 gcpp $(BIN)
	install -c -m 755 gupd $(BIN)
	install -c -m 755 grm $(BIN)
	install -c -s -m 755 puma $(LIB)/puma
	install -c -m 644 TypeTab.c $(LIB)/puma
	install -c -m 644 TypeTab.cx $(LIB)/puma
	install -c -m 644 TypeTab.cxx $(LIB)/puma
	install -c -m 644 TypeTab.m $(LIB)/puma
	install -c -m 644 TypeTab.j $(LIB)/puma

# installation directories

$(LIB)/puma:
	mkdir -p $(LIB)/puma

m2c:
	make $(SOURCES)
	cp TypeTab.[mcj]* g* ../m2c
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	cp TypeTab.[mcj]* g* ../m
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

# support for mkid

pumaId:	puma.rex
	echo "SCANNER pumaId" | cat - puma.rex | \
	sed 's/\(RETURN 1	\)/yyEcho; IO.WriteNl (IO.StdOutput); \1/' | \
	$(BIN).t/rex -sdi
	sed 's/@/pumaId/' < ../../front/src/Id.mi > pumaIdDrv.mi
	echo p pumaIdDrv | mc -d ../../reuse/src
	mv pumaIdDrv pumaId

installId:	pumaId $(LIB)/Id
	echo exec $(LIB)/Id/pumaId -l$(LIB)/Id "2> /dev/null" > $(BIN)/pumaId
	chmod a+rx $(BIN)/pumaId
	install -c -s -m 755 pumaId $(LIB)/Id

$(LIB)/Id:
	mkdir -p $(LIB)/Id

cleanId:
	rm -f pumaId*

clean:	cleanId
	rm -f Parser.dbg Parser.dlt Parser.cft core* *.[dor] *.bak Tree3.?

CLEAN:	clean
	rm -f puma pumal $(SOURCES) Tree.TS Scanner.rpp puma.rex Parser.lrk
