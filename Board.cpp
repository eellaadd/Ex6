#include "Board.h"
#include "Point.h"
#include <iostream>
using namespace std;

Board& Board::operator=(const char w){
    if(w == '.'|| w == 'O' || w == 'X'){
        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++){
                pBoard[i][j].data = w;
            }
        }
    }
    else{
        throw IllegalCharException(w);
    }
    return *this;
}

Board& Board::operator=(const Board& b){
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++){
            pBoard[i][j].data=b.pBoard[i][j].data;
        }
    }
    return *this;
}

bool Board::operator == (Board const & r){
    if(size != r.size) return false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(pBoard[i][j] != r.pBoard[i][j]) return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, Board const& b) {  
      for (int i = 0; i < b.size; i++) {
        for(int j=0; j<b.size; j++){
            os << b.pBoard[i][j].data;
        }
        os << endl;
      }
    return os;  
}

Point& Board::operator[](Point p){
    if(p.x < 0 || p.x >= size || p.y < 0 || p.y >= size){
        throw IllegalCoordinateException(p.x, p.y);
    }
    else{
        return pBoard[p.x][p.y];
    }
}

const Point& Board::operator[](Point p) const{
    if(p.x < 0 || p.x >= size || p.y < 0 || p.y >= size){
        throw IllegalCoordinateException(p.x, p.y);
    }
    else{
        return pBoard[p.x][p.y];
    }
}

void Board::free(){
    for(int i = 0; i < size; i++)
        delete[] pBoard[i];
    delete[] pBoard;
}

Board::~Board(){
	free();
}
