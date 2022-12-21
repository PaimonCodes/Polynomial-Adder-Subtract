CC=g++
DEV=-Wall -g -std=c++14
OPT=-O3 -std=c++14

.PHONY: all
make all: commands

polynomial.o: polynomial.h polynomial.cpp
	$(CC) $(OPT) -c polynomial.cpp

commands: commands.cxx polynomial.o
	$(CC) $(OPT) commands.cxx polynomial.o -o commands.exe


.PHONY: clean
clean:
	rm -f *.o
	rm -f *.exe
	rm -rf *dSYM

.PHONY: update
update:
	make clean
	make all
