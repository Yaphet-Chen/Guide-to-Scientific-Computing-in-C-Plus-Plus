#--------------------------------------------------
#variables
#--------------------------------------------------
#compilation flag
CXX = g++
INCLUDES = ../Chapter\ 10\ -\ Developing\ Classes\ for\ Linear\ Algebra\ Calculations
CXXFLAGS = -std=c++11 -Wall -lm -O3 -I $(INCLUDES)

#directory for executables
BIN = ../bin

#--------------------------------------------------
#compiling
# --------------------------------------------------
all: Driver

#mkdir
checkdir:
	mkdir -p $(BIN)

#build executables
Vector.o: $(INCLUDES)/Vector.cpp $(INCLUDES)/Vector.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $(INCLUDES)/Vector.cpp
Matrix.o: $(INCLUDES)/Matrix.cpp $(INCLUDES)/Matrix.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $(INCLUDES)/Matrix.cpp
LinearSystem.o: $(INCLUDES)/LinearSystem.cpp $(INCLUDES)/LinearSystem.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $(INCLUDES)/LinearSystem.cpp
FiniteDifferenceGrid.o: FiniteDifferenceGrid.cpp FiniteDifferenceGrid.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
BoundaryConditions.o: BoundaryConditions.cpp BoundaryConditions.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
BvpOde.o: BvpOde.cpp BvpOde.hpp FiniteDifferenceGrid.o SecondOrderOde.hpp BoundaryConditions.o Matrix.o Vector.o LinearSystem.o
	$(CXX) $(CXXFLAGS) -c -o $@ $<
Driver.o: Driver.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
Driver: Driver.o BvpOde.o BoundaryConditions.o FiniteDifferenceGrid.o LinearSystem.o Matrix.o Vector.o
	$(CXX) $(CXXFLAGS) -o $(BIN)/$@ $^

#clean
.PHONY:clean
clean:
	rm *.o
	rm -f $(BIN)/*