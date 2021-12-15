BIN	= $(HOME)/bin
LIB	= $(HOME)/lib

M2FLAGS	= -cuw

DEFS	= DefTable.md Errors.md 
MODS	= DefTable.mi Errors.mi r2l.mi
SOURCES	= Scanner.md Scanner.mi Parser.md Parser.mi

all:	r2l

sources:	$(SOURCES)

r2l:	$(SOURCES) r2l_boot
	# avoid implicit rule

r2l_boot:	$(DEFS) $(MODS)
	echo p r2l | mc -d ../../reuse/src

Scanner.mi Scanner.md:	r2l.rex
	rex -di r2l.rex

Parser.mi Parser.md:	r2l.lrk
	@echo expect 4 conflict messages
	lark -di0v r2l.lrk

install:	r2l r2l.sh $(LIB)/r2l
	if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi
	sed "s;LIB;$(LIB);g" < r2l.sh > $(BIN)/r2l
	chmod a+rx $(BIN)/r2l
	install -c -s -m 755 r2l $(LIB)/r2l

# installation directories

$(LIB)/r2l:	$(LIB)
	sh -c "if test ! -d $(LIB)/r2l; then mkdir -p $(LIB)/r2l; else true; fi"

m2c:
	make $(SOURCES)
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

clean:
	rm -f core *.[dimor] ERRORS LISTING *.dbg r2l

CLEAN:	clean
	rm -f $(SOURCES)
