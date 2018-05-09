#include "Board.h"
#include <iostream>
using namespace std;


Board& Board::operator=(char w){
    if(w == '.'|| w == 'O' || w == 'X'){
        for (int i = 0; i < size*size; i++) {
            pBoard[i]=w;
        }
    }
    else{
        throw IllegalCharException(w);
    }
    return *this;
}

Board& Board::operator=(Board& b){
    
    for (int i = 0; i < size*size; i++) {
        pBoard[i]=b.pBoard[i];
    }
    return *this;
}

ostream& operator<<(ostream& os, Board& b) {  
      for (int i = 0; i < b.size; i++) {
        for(int j=0; j<b.size; j++){
            int index = b.getIndex(i,j);
            os << b.pBoard[index];
        }
        os << endl;
      }
    return os;  
}

int Board::getIndex(int x,int y){
    int index=size*y+x;
    return index;
}

//board1[{0,1}] = 'x';

Point& Board::operator[](Point p){
    if(p.x < 0 || p.x >= size || p.y < 0 || p.y >= size){
        throw IllegalCoordinateException(p.x, p.y);
    }
    else{
        int index=getIndex(p.x,p.y);
        return p;
    }
}
