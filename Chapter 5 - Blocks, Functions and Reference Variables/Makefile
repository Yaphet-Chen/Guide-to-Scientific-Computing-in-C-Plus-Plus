#--------------------------------------------------
#variables
#--------------------------------------------------
#compilation flag
CC = g++
CFLAGS = -Wall -Werror -O3
DEPS = *.h

#directory for executables
BIN = ../bin

#--------------------------------------------------
#compiling
#--------------------------------------------------
all: Blocks SimpleFunctions FunctionWithPointers ArraysFunctions CalculateScalarProduct ReferenceVariables DefaultFunctionArguments FunctionOverloading FunctionPointers RecursiveFunctions

#mkdir
checkdir:
	mkdir -p $(BIN)

#build executables
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# $@ 指代当前目标，就是Make命令当前构建的那个目标。
# $< 指代第一个前置条件。
# $^ 指代所有前置条件，之间以空格分隔。

Blocks: Blocks.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
SimpleFunctions: SimpleFunctions.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
FunctionWithPointers: FunctionWithPointers.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
ArraysFunctions: ArraysFunctions.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
CalculateScalarProduct: CalculateScalarProduct.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
ReferenceVariables: ReferenceVariables.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
DefaultFunctionArguments: DefaultFunctionArguments.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
FunctionOverloading: FunctionOverloading.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
FunctionPointers: FunctionPointers.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
RecursiveFunctions: RecursiveFunctions.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

#clean
.PHONY:clean
clean:
	rm *.o
	rm -f $(BIN)/*