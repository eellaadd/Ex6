a.out: Board.o IllegalCharException.o IllegalCoordinateException.o Pair.o

Point.o: Point.cpp point.h
	clang++-5.0 -std=c++17 -c Point.cpp
Board.o: Board.cpp Board.h
	clang++-5.0 -std=c++17 -c Board.cpp
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	clang++-5.0 -std=c++17 -c IllegalCharException.cpp
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	clang++-5.0 -std=c++17 -c IllegalCoordinateException.cpp
clean:
	rm *.o a.out
