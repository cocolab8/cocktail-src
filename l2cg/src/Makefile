BIN	= $(HOME)/bin
LIB	= $(HOME)/lib
MC	= MC
M2FLAGS	= -cuw
SOURCES	= Scanner.md Scanner.mi Parser.md Parser.mi

all:	l2cg_boot

sources:	$(SOURCES)

l2cg:	$(SOURCES)
	echo p l2cg | mc -d ../../reuse/src

l2cg_boot:	$(SOURCES)
	echo p l2cg | mc -d ../../reuse/src

Scanner.md Scanner.mi:	l2cg.rex
	rex -di l2cg.rex

Parser.md Parser.mi:	l2cg.lrk
	bnf l2cg.lrk | lark -di

install:	l2cg l2cg.sh $(LIB)/lalr
	if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi
	sed 's;LIB;$(LIB);g' < l2cg.sh > $(BIN)/l2cg
	chmod a+rx $(BIN)/l2cg
	install -c -s -m 755 l2cg $(LIB)/lalr

# installation directories

$(LIB)/lalr:	$(LIB)
	sh -c "if test ! -d $(LIB)/lalr; then mkdir -p $(LIB)/lalr; else true; fi"

m2c:
	make $(SOURCES)
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

clean:
	rm -f l2cg core* *.[dimor] *.bak Scanner.m? Parser.m?
