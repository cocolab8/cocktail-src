BIN	= $(HOME)/bin
M2FLAGS	= -cuw
SOURCES	= Scanner.md Scanner.mi

all:	rpp

sources:	$(SOURCES)

rpp:	$(SOURCES) rpp_boot
	# avoid implicit rule

rpp_boot:	rpp.mi
	echo p rpp | mc -d ../../reuse/src

Scanner.md Scanner.mi:	rpp.rex
	rex -di rpp.rex

install:	rpp
	install -c -s -m 755 rpp $(BIN)/rpp

m2c:
	make $(SOURCES)
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

clean:
	rm -f core* *.[dimor] rpp *.bak

CLEAN:	clean
	rm -f $(SOURCES)
