#include "Board.hpp"
#include <iostream>
using namespace std;

Board& Board::operator=(char w) {

	for (int i = 0; i < size*size; i++) {
		pBoard[i] = '.';
	}
	return *this;
}

Board& Board::operator=(Board& b) {

	for (int i = 0; i < size*size; i++) {
		pBoard[i] = b.pBoard[i];
	}
	return *this;
}

ostream& operator<<(ostream& os, Board& b) {
	for (int i = 0; i < b.size; i++) {
		for (int j = 0; j<b.size; j++) {
			int index = b.getIndex(i, j);
			os << b.pBoard[index];
		}
		os << endl;
	}
	return os;
}

int Board::getIndex(int x, int y) {
	int index = size * y + x;
	return index;
}

char& Board::operator[](Point p) {
	int index = getIndex(p.x, p.y);
	return pBoard[index];
}