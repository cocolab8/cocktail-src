M2FLAGS	= -cuw

all:
	echo p Main | mc -d ../../reuse/src
	rm -f Main Main.[dimor]

m2c:
	make sources M2FLAGS="$(M2FLAGS) -d../../reuse/src -o../m2c" -f ../m2c/Makefile

m:
	make sources M2FLAGS="-c -d../../reuse/src -o../m" -f ../m/Makefile

sources:

clean:
	rm -f *.[dimor]
