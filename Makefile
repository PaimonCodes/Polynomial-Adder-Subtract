CC=g++
DEV=-Wall -g -std=c++14
OPT=-O3 -std=c++14

LinkedList.o: LinkedList.h LinkedList.cpp
	$(CC) $(OPT) -c LinkedList.cpp

commands: commands.cxx LinkedList.o
	$(CC) $(OPT) commands.cxx LinkedList.o -o commands.exe