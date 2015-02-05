// Author: Arthur Miller
// Date:   02-05-15
// WORKING PROGRAM
#ifndef __SSL_H_INCLUDED__   // if x.h hasn't been included yet...
#define __SLL_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>
using namespace std;

/** Purpose:

Write a computer program that constructs any n x n magic square for any odd value of
n. Test this for n = 5, 7, and 11. Your program should support any integer typed in at run
time such as n = 13.

**/
const int Bound = 111;

class MagicSquare{
    private:
        int SquareSize;
        int Current;
        int Row;
        int Col;
        int Square[Bound][Bound];

    public:
        MagicSquare(){SquareSize = 3; Current = 1; Row = 0; Col = 0; Square[SquareSize][SquareSize];}
        MagicSquare(int Size){SquareSize = Size; Current = 1; Row = 0; Col = 0; Square[SquareSize][SquareSize];}
        void SetSquareSize(int Size); // Can set square size if use default constructor
        int GetSquareSize();
        void Magic(); // makes our board and fills with magic square
        void Print(); // print board

};



#endif
