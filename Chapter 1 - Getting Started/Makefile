#--------------------------------------------------
#variables
#--------------------------------------------------
#compilation flag
Compiler = g++
FLAGS = -Wall -Werror -O3

#directory for executables
BIN = ../bin

#--------------------------------------------------
#compiling
#--------------------------------------------------
all: HelloWorld

#mkdir
checkdir:
	mkdir -p $(BIN)

#build executables
HelloWorld: HelloWorld.cpp
	$(Compiler) $(FLAGS) -o $(BIN)/HelloWorld HelloWorld.cpp

#clean
clean:
	rm -f $(BIN)/*
