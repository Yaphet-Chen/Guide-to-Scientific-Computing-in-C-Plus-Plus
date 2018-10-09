#--------------------------------------------------
#variables
#--------------------------------------------------
#compilation flag
CC = g++
CFLAGS = -Wall -Werror -lm -O3
DEPS = *.h

#directory for executables
BIN = ../bin

#--------------------------------------------------
#compiling
#--------------------------------------------------
all: UseEbookClass

#mkdir
checkdir:
	mkdir -p $(BIN)

#build executables
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# $@ 指代当前目标，就是Make命令当前构建的那个目标。
# $< 指代第一个前置条件。
# $^ 指代所有前置条件，之间以空格分隔。

UseEbookClass: UseEbookClass.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^ ../Chapter\ 6\ -\ An\ Introduction\ to\ Classes/Book.cpp

#clean
.PHONY:clean
clean:
	rm *.o
	rm -f $(BIN)/*