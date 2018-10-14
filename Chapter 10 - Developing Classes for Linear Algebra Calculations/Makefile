#--------------------------------------------------
#variables
#--------------------------------------------------
#compilation flag
CC = g++
CFLAGS = -std=c++11 -Wall -Werror -lm -O3
DEPS = *.h

#directory for executables
BIN = ../bin

#--------------------------------------------------
#compiling
#--------------------------------------------------
all: Test

#mkdir
checkdir:
	mkdir -p $(BIN)

#build executables
Vector.o: Vector.cpp Vector.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Matrix.o: Matrix.cpp Matrix.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
LinearSystem.o: LinearSystem.cpp LinearSystem.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
Test: Test.o Vector.o Matrix.o LinearSystem.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

#clean
.PHONY:clean
clean:
	rm *.o
	rm -f $(BIN)/*