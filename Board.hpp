#pragma once
#include <iostream>
#include "Point.hpp"
using namespace std;

class Board {
public:
	int size;
	char* pBoard;
	//  int x,y;
	char temp;

	Board(int size) :size(size),
		pBoard(new char[size*size]) {
		operator=('.');
	}

	Board(Board& b) {
		size = b.size;
		pBoard = new char[size*size];
		*this = b;
	}

	Board& operator=(char w);
	Board& operator=(Board& b);
	friend ostream& operator<<(ostream& os, Board& b);
	int getIndex(int x, int y);
	char& operator[](Point p);
};
