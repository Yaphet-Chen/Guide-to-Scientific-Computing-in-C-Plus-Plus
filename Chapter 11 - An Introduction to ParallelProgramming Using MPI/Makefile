#--------------------------------------------------
#variables
#--------------------------------------------------
#compilation flag
CC = mpic++
CFLAGS = -Wall -Werror -lm -O3
DEPS = *.h

#directory for executables
BIN = ../bin

#--------------------------------------------------
#compiling
#--------------------------------------------------
all: MpiHelloWorld PointToPoint Barrier CombinedSendRecv_Ring CombinedSendRecv_Chain BcastReduce SummationOfSeries UseMpiVector

#mkdir
checkdir:
	mkdir -p $(BIN)

#build executables
MpiHelloWorld: MpiHelloWorld.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
PointToPoint: PointToPoint.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
Barrier: Barrier.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
CombinedSendRecv_Ring: CombinedSendRecv_Ring.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
CombinedSendRecv_Chain: CombinedSendRecv_Chain.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
BcastReduce: BcastReduce.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
SummationOfSeries: SummationOfSeries.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
UseMpiVector: UseMpiVector.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

#clean
.PHONY:clean
clean:
	rm *.o
	rm -f $(BIN)/*