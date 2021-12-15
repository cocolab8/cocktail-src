BIN	= $(HOME)/bin
LIB	= $(HOME)/lib
MC	= mc -d ../../reuse/src
M2FLAGS	= -cuw

SOURCES	= Scanner.mi Scanner.md Parser.md Parser.mi Tree.md Tree.mi \
	  Semantic.md Semantic.mi LR1.md LR1.mi Conflict.md Conflict.mi \
	  Explain.md Explain.mi Compress.md Compress.mi Generate.md Generate.mi \
	  GenLRk.md GenLRk.mi LarkTime.md LarkTime.mi Queue.md Queue.mi \
	  Delta.md Delta.mi lark.mi

all:	lark

sources: $(SOURCES) Tree.TS lark.rex Parser.lrk Scanner.rpp

lark:	$(SOURCES) lark_boot
	# avoid implicit rule

lark_boot:
	echo p lark | $(MC)

Scanner.rpp Parser.lrk:	lark.pars
	lpp -xzj lark.pars

lark.rex:	lark.scan Scanner.rpp
	rpp < lark.scan > lark.rex

Scanner.md Scanner.mi:	lark.scan Scanner.rpp
	rpp < lark.scan | rex -dwi

Parser.md:	Parser.lrk
	lark -di Parser.lrk

Parser.mi:	Parser.lrk
	lark -i Parser.lrk

Tree.md:	lark.ast
	ast -dimR4qe lark.ast

Tree.mi:	lark.ast
	ast -imRqe lark.ast

Tree.TS:	lark.ast
	ast -4 lark.ast

Semantic.md Semantic.mi:	sem.puma Tree.TS
	puma -diw sem.puma

Delta.md Delta.mi:	delta.puma Tree.TS
	puma -diw delta.puma

lark.mi:	lark.mi.sed lark.sed
	sed -f lark.sed < lark.mi.sed > lark.mi

install:	lark lark.sh $(LIB)/lark
	sh -c "if test $(LIB) = $(BIN); then echo error: BIN = LIB; false; else true; fi"
	sed 's;LIB;$(LIB);g' < lark.sh > $(BIN)/lark
	chmod a+rx $(BIN)/lark
	install -c -m 755 gcpp $(BIN)
	install -c -m 755 gupd $(BIN)
	install -c -s -m 755 lark $(LIB)/lark
	cp ../lib/P* ../lib/*.e ../lib/*.ad? $(LIB)/lark
	chmod a+r $(LIB)/lark/*

# installation directories

$(LIB)/lark:	$(LIB)
	sh -c "if test ! -d $(LIB)/lark; then mkdir -p $(LIB)/lark; else true; fi"

m2c:
	$(MAKE) sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	$(MAKE) sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

# support for mkid

larkId:	lark.rex
	echo SCANNER larkId | cat - lark.rex | \
	sed 's/\(RETURN 1	\)/yyEcho; IO.WriteNl (IO.StdOutput); \1/' | rex -sdi
	sed 's/@/larkId/' < ../../front/src/Id.mi > larkIdDrv.mi
	echo p larkIdDrv | $(MC)
	mv larkIdDrv larkId

installId:	larkId $(LIB)/Id
	echo exec $(LIB)/Id/larkId -l$(LIB)/Id "2> /dev/null" > $(BIN)/larkId
	chmod a+rx $(BIN)/larkId
	install -c -s -m 755 larkId $(LIB)/Id

$(LIB)/Id:	$(LIB)
	sh -c "if test ! -d $(LIB)/Id; then mkdir -p $(LIB)/Id; else true; fi"

cleanId:
	rm -f larkId*

clean:	cleanId
	rm -f core* *.[dor] *.dbg

CLEAN:	clean
	rm -f lark Tree.TS lark.rex Parser.lrk Scanner.rpp lark.mi \
	   Scanner.m[di] Parser.m[di] Tree.m[di] Semantic.m[di] Delta.m[di]
