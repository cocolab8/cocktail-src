DIR	= $(HOME)
BIN	= $(DIR)/bin
LIB	= $(DIR)/lib
REUSE	= ../../reuse
MC	= mc -d $(REUSE)/src
M2FLAGS	= -cuw

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

# Convert !...! notation to Modula Write statements.
SED_WRITE	= sed -f cg.sed

# Select here if the debug edit is included
#SEDC	= ($(SED_DEBUGC) | $(SED_WRITE))
SEDC	= $(SED_WRITE)
#SEDM	= ($(SED_DEBUGM) | $(SED_WRITE))
SEDM	= $(SED_WRITE)
SED	= $(SED_WRITE)

SOURCES	= Dialog.mi	\
	  Errors.mi	\
	  EvalC.md EvalC.mi	\
	  EvalC2.md EvalC2.mi	\
	  EvalC3.md EvalC3.mi	\
	  EvalC4.md EvalC4.mi	\
	  EvalMod.md EvalMod.mi	\
	  EvalMod2.md EvalMod2.mi	\
	  EvalMod3.md EvalMod3.mi	\
	  EvalMod4.md EvalMod4.mi	\
	  EvalJava.md EvalJava.mi	\
	  EvalJav2.md EvalJav2.mi	\
	  EvalJav3.md EvalJav3.mi	\
	  EvalJav4.md EvalJav4.mi	\
	  EvalCxx.md EvalCxx.mi	\
	  EvalCxx2.md EvalCxx2.mi	\
	  EvalCxx3.md EvalCxx3.mi	\
	  EvalCxx4.md EvalCxx4.mi	\
	  GramC.md GramC.mi	\
	  GramMod.md GramMod.mi	\
	  GramYacc.md GramYacc.mi	\
	  GramAda.md GramAda.mi	\
	  GramJava.md GramJava.mi	\
	  Optimize.md Optimize.mi	\
	  Order.md Order.mi	\
	  Parser.md Parser.mi	\
	  Scanner.md Scanner.mi	\
	  Semantic.md Semantic.mi	\
	  Tree.md Tree.mi	\
	  Tree2.md Tree2.mi	\
	  TreeC1.md TreeC1.mi	\
	  TreeC2.md TreeC2.mi	\
	  TreeMod1.md TreeMod1.mi	\
	  TreeMod2.md TreeMod2.mi	\
	  TreeJav1.md TreeJav1.mi	\
	  TreeJav2.md TreeJav2.mi	\
	  TreeCxx1.md TreeCxx1.mi	\
	  TreeCxx2.md TreeCxx2.mi	\
	  Puma0.md Puma0.mi	\
	  cg.mi	\
	  lpp.mi	\
	  pumagen.mi

# \
	  tsl.md tsl.mi \

all:	cg lpp pumagen

sources:	Tree.TS $(SOURCES)

cg:	$(SOURCES) cg_boot
	# avoid implicit rule

cg_boot:
	echo p cg | $(MC)

lpp:	$(SOURCES) lpp_boot
	# avoid implicit rule

lpp_boot:
	echo p lpp | $(MC)

pumagen:	$(SOURCES) pumagen_boot
	# avoid implicit rule

pumagen_boot:
	echo p pumagen | $(MC)

Scanner.md Scanner.mi:	cg.rex
	rex -di cg.rex

Parser.md:	cg.lrk
	@echo expect 9 shift-reduce conflicts
	lark -di cg.lrk

Parser.mi:	cg.lrk
	@echo expect 9 shift-reduce conflicts
	lark -iv cg.lrk

Errors.mi:	Errors.0 yyconsts1 yywrites1 yyconsts2 yywrites2
	cp Errors.0 Errors.mi
	gcpp Errors.mi

Tree.md:	cg.cg
#	echo SELECT AstIn Ast Common Cg Ag | cat - cg.cg | ast -diqmRe
	echo SELECT AstIn Ast Common Cg Ag | cat - cg.cg | ast -diqmR

Tree.mi:	cg.cg
#	echo SELECT AstIn Ast Common Cg Ag | cat - cg.cg | ast -iqmRe
	echo SELECT AstIn Ast Common Cg Ag | cat - cg.cg | ast -iqmR

Tree2.md:	cg.cg
	echo SUBUNIT Tree2 SELECT AstIn Ast Tree2 | cat - cg.cg | ast -dip

Tree2.mi:	cg.cg
	echo SUBUNIT Tree2 SELECT AstIn Ast Tree2 | cat - cg.cg | ast -ip

Tree.TS:	cg.cg
	echo SELECT AstIn Ast Common Cg Ag | cat - cg.cg | ast -4

GramMod.md GramMod.mi:	mod0.puma Tree.TS
	$(SED) < mod0.puma | puma -dinw

GramC.md GramC.mi:	c0.puma Tree.TS
	$(SED) < c0.puma | puma -dinw

GramYacc.md GramYacc.mi:	y0.puma Tree.TS
	$(SED) < y0.puma | puma -dinw

GramAda.md GramAda.mi:	ada0.puma Tree.TS
	$(SED) < ada0.puma | puma -dinw

GramJava.md GramJava.mi:	java0.puma Tree.TS
	$(SEDC) < java0.puma | puma -dinw

Semantic.md Semantic.mi yyconsts1 yywrites1:	sem.puma Tree.TS
	awk -f cg.awk1 < sem.puma > yysem.puma
	gcpp yysem.puma
	puma -dinw yysem.puma
	sed -f cg.sed2 < yywrites01 > yywrites1

Order.md Order.mi yyconsts2 yywrites2:	oag.puma Tree.TS
	awk -f cg.awk2 < oag.puma > yyoag.puma
	gcpp yyoag.puma
	puma -dinw yyoag.puma
	sed -f cg.sed2 < yywrites02 > yywrites2

Optimize.md Optimize.mi:	opt.puma Tree.TS
	cp opt.puma yyopt.puma
	gcpp yyopt.puma
	puma -dinw yyopt.puma

Dialog.mi:	Dialog.mi.sed
	$(SED) < Dialog.mi.sed > Dialog.mi

TreeMod1.md TreeMod1.mi:	mod1.puma Tree.TS
	$(SED) < mod1.puma | puma -dinw

TreeMod2.md TreeMod2.mi:	mod2.puma Tree.TS
	$(SED) < mod2.puma | puma -dinw

EvalMod.md EvalMod.mi:		mod3.puma Tree.TS
	$(SED) < mod3.puma | puma -dinw

EvalMod2.md EvalMod2.mi:	mod4.puma Tree.TS
	$(SED) < mod4.puma | puma -dinw

EvalMod3.md EvalMod3.mi:	mod5.puma Tree.TS
	$(SED) < mod5.puma | puma -dinw

EvalMod4.md EvalMod4.mi:	mod6.puma Tree.TS
	$(SED) < mod6.puma | puma -dinw

TreeC1.md TreeC1.mi:	c1.puma Tree.TS
	$(SED) < c1.puma | puma -dinw

TreeC2.md TreeC2.mi:	c2.puma Tree.TS
	$(SED) < c2.puma | puma -dinw

EvalC.md EvalC.mi:	c3.puma Tree.TS
	$(SED) < c3.puma | puma -dinw

EvalC2.md EvalC2.mi:	c4.puma Tree.TS
	$(SED) < c4.puma | puma -dinw

EvalC3.md EvalC3.mi:	c5.puma Tree.TS
	$(SED) < c5.puma | puma -dinw

EvalC4.md EvalC4.mi:	c6.puma Tree.TS
	$(SED) < c6.puma | puma -dinw

TreeJav1.md TreeJav1.mi:	java1.puma Tree.TS
	$(SEDC) < java1.puma | puma -dinw

TreeJav2.md TreeJav2.mi:	java2.puma Tree.TS
	$(SEDC) < java2.puma | puma -dinw

EvalJava.md EvalJava.mi:	java3.puma Tree.TS
	$(SEDC) < java3.puma | puma -dinw

EvalJav2.md EvalJav2.mi:	java4.puma Tree.TS
	$(SEDC) < java4.puma | puma -dinw

EvalJav3.md EvalJav3.mi:	java5.puma Tree.TS
	$(SEDC) < java5.puma | puma -dinw

EvalJav4.md EvalJav4.mi:	java6.puma Tree.TS
	$(SEDC) < java6.puma | puma -dinw

TreeCxx1.md TreeCxx1.mi:	cxx1.puma Tree.TS
	$(SEDC) < cxx1.puma | puma -dinw

TreeCxx2.md TreeCxx2.mi:	cxx2.puma Tree.TS
	$(SEDC) < cxx2.puma | puma -dinw

EvalCxx.md EvalCxx.mi:		cxx3.puma Tree.TS
	$(SEDC) < cxx3.puma | puma -dinw

EvalCxx2.md EvalCxx2.mi:	cxx4.puma Tree.TS
	$(SEDC) < cxx4.puma | puma -dinw

EvalCxx3.md EvalCxx3.mi:	cxx5.puma Tree.TS
	$(SEDC) < cxx5.puma | puma -dinw

EvalCxx4.md EvalCxx4.mi:	cxx6.puma Tree.TS
	$(SEDC) < cxx6.puma | puma -dinw

Puma0.md Puma0.mi:	p0.puma Tree.TS
	$(SED) < p0.puma | puma -dinw

tsl.md tsl.mi: tsl.puma Tree.TS
	puma -dinw tsl.puma

cg.mi:	cg.mi.sed
	$(SED) < cg.mi.sed > cg.mi

lpp.mi:	lpp.mi.sed
	$(SED) < lpp.mi.sed > lpp.mi

pumagen.mi:	pumagen.mi.sed
	$(SED) < pumagen.mi.sed > pumagen.mi

install:	cg cg.sh lpp $(LIB)/cg
	sh -c "if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi"
	sed 's;LIB;$(LIB);g' < cg.sh > $(BIN)/cg
	sed 's;BIN;$(BIN);g' < gcppt > $(BIN)/gcppt
	cp $(BIN)/cg $(BIN)/ag
	cp $(BIN)/cg $(BIN)/ast
	chmod a+rx $(BIN)/cg $(BIN)/ast $(BIN)/ag $(BIN)/gcppt
	install -c -m 755 gcpp $(BIN)
	install -c -m 755 gupd $(BIN)
	install -c -m 755 grm $(BIN)
	install -c -s -m 755 cg $(LIB)/cg
	install -c -m 644 TypeTab.c $(LIB)/cg
	install -c -m 644 TypeTab.cx $(LIB)/cg
	install -c -m 644 TypeTab.cxx $(LIB)/cg
	install -c -m 644 TypeTab.m $(LIB)/cg
	install -c -m 644 TypeTab.j $(LIB)/cg
	install -c -m 644 Tree.tcl $(LIB)/cg
	install -c -s -m 755 lpp $(BIN)
	# install -c -s -m 755 pumagen $(BIN)

# installation directories

$(LIB)/cg:	$(LIB)
	sh -c "if test ! -d $(LIB)/cg; then mkdir -p $(LIB)/cg; else true; fi"

m2c:
	make $(SOURCES)
	cp TypeTab.[mcj]* Tree.tcl gcppt grm gupd ../m2c
	make sources M2FLAGS="$(M2FLAGS) -d$(REUSE)/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	cp TypeTab.[mcj]* Tree.tcl gcppt grm gupd ../m
	make sources M2FLAGS="-c -d$(REUSE)/src -o../m" -f ../m/Makefile

# support for mkid

cgId:	cg.rex
	echo SCANNER cgId | cat - cg.rex | \
	sed 's/\(RETURN.*Ident\)/yyEcho; IO.WriteNl (IO.StdOutput); \1/' | \
	$(BIN).t/rex -sdi
	sed 's/@/cgId/' < ../../front/src/Id.mi > cgIdDrv.mi
	echo p cgIdDrv | $(MC)
	mv cgIdDrv cgId

installId:	cgId $(LIB)/Id
	echo exec $(LIB)/Id/cgId -l$(LIB)/Id "2> /dev/null" > $(BIN)/cgId
	chmod a+rx $(BIN)/cgId
	install -c -s -m 755 cgId $(LIB)/Id

$(LIB)/Id:	$(LIB)
	sh -c "if test ! -d $(LIB)/Id; then mkdir -p $(LIB)/Id; else true; fi"

cleanId:
	rm -f cgId*

clean:	cleanId
	rm -f *.dbg core* *.[dor] [A-SU-Za-z]*.m *.bak yy*

CLEAN:	clean
	rm -f cg lpp pumagen Tree.TS $(SOURCES)
