BIN	= $(HOME)/bin
M2FLAGS	= -cuw
SOURCES	= Reader.md Reader.mi ReaderSource.md ReaderSource.mi \
	  Writer.md Writer.mi WriterSource.md WriterSource.mi

all:	tidy

sources:	$(SOURCES)

tidy:	$(SOURCES) tidy_boot
	# avoid implicit rule

tidy_boot:	tidy.mi
	echo p tidy | mc -d ../../reuse/src

Reader.md Reader.mi ReaderSource.md ReaderSource.mi:	reader.rex
	rex -dis reader.rex
	rm ReaderDrv.mi

Writer.md Writer.mi WriterSource.md WriterSource.mi:	writer.rex
	rex -dis writer.rex
	rm WriterDrv.mi

install:	tidy
	install -c -s -m 755 tidy $(BIN)/tidy

m2c:
	make $(SOURCES)
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make $(SOURCES)
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

clean:
	rm -f core* *.[dimor] tidy *.bak

CLEAN:	clean
	rm -f $(SOURCES)
