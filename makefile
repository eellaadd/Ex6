CXX=g++
CXXFLAGS=-std=gnu++11

all: main.o Board.o
	$(CXX) Board.o main.o
	./a.out

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

main.o: main.cpp Board.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out
