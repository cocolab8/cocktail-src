DEFS	= Parser.md Scanner.md Table.md
IMPS	= Parser.mi Scanner.mi Table.mi

M2FLAGS	= -cuw

BIN	= $(HOME)/bin

SOURCES	= Parser.md Parser.mi

all:	mpp

sources: $(SOURCES)

mpp:	$(SOURCES) mpp_boot
	# avoid implicit rule

mpp_boot:	Scanner.md Scanner.mi Table.md Table.mi mpp.mi
	echo p mpp | mc -d ../../common/src -d ../../reuse/src

Parser.mi Parser.md:	mpp.ell
	ell -di mpp.ell

install:	mpp
	install -c -s -m 755 mpp $(BIN)/mpp

m2c:
	make $(SOURCES)
	make sources M2FLAGS="$(M2FLAGS) -d../../common/src -d../../reuse/src -o../m2c" -f ../m2c/Makefile

clean:
	rm -f *.[dor] mpp *.bak

CLEAN:	clean
	rm -f Parser.m[di]
