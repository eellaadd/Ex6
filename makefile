CXX=clang++-5.0
CXXFLAGS=-std=c++17

all: Board.o Point.o

Board.o: Board.cpp Board.h Point.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

Cell.o: Point.cpp Point.h
	$(CXX) $(CXXFLAGS) --compile Point.cpp -o Point.o

clean: 
	rm *.o a.out
