#pragma once
#include <iostream>
#include "Point.hpp"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
using namespace std;

class Board {
public:
	int size;
	Point **pBoard;

	Board(int size) {
		this->size = size;
		pBoard = new Point*[size];
		for (int i = 0; i < size; i++) {
			pBoard[i] = new Point[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				pBoard[i][j].x = i;
				pBoard[i][j].y = j;
			}
		}
	}

	Board(const Board& b) {
		size = b.size;
		pBoard = new Point*[size];
		for (int i = 0; i < size; i++) {
			pBoard[i] = new Point[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				pBoard[i][j].x = i;
				pBoard[i][j].y = j;
			}
		}
		*this = b;
	}

	Board& operator=(const char w);
	Board& operator=(const Board& b);
	friend ostream& operator<<(ostream& os, Board const& b);
	int getIndex(int x, int y);
	Point& operator[](Point p);
	const Point& operator[](Point p) const;
	bool operator == (Board const & r);
	void free();
	~Board();
};
