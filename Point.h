#pragma once
#include <iostream>
using namespace std;

class Point{
    public:
    int x;
    int y;
    char data;
    
    Point(int x,int y):
    x(x),y(y){
    }
    
    friend ostream& operator<<(ostream& os, Point& p) {  
         os << p.x << "," << p.y << endl;
    return os;  
    }
    
    Point &Point::operator=(const char ch){
        
        if (ch == '.' || ch == 'X' || ch == 'O')
            data = ch;
        else {
            IllegalCharException ex {ch};
            throw ex;
        }
        return *this;
    }
};
