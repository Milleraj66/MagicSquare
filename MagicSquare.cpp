#include "MagicSquare.h"

void MagicSquare::SetSquareSize(int Size){
    SquareSize = Size;
}

int MagicSquare::GetSquareSize(){
    return (SquareSize);
}

void MagicSquare::Magic(){
    /*

    Write a computer program that constructs any n x n magic square for any odd value of
    n. Test this for n = 5, 7, and 11. Your program should support any integer typed in at run
    time such as n = 13.

    */

    // if square size is not odd, get valid input
    if((SquareSize%2)==0){
        while((SquareSize%2)==0){
            cout << "Square must be an nxn where n is odd, re-input please\n";
            cin >> SquareSize;
            cout << endl;
        }
    }

    // initialize square to all 0's
    for(int i=0;i<SquareSize;i++){
        for(int j=0;j<SquareSize;j++){
            Square[i][j] = 0;
        }
    }
    // Start Magic Algorithm
    /**

    1. Place 1 in the middle of the top row.

    2. After integer k has been placed, move up one row and one column to the right and
    place k + 1 there.
    (a) If a move takes you above the top row in the jth column, move the bottom of
        the jth column and place k + 1 there.
    (b) If a move takes you outside to the right of the square in the ith row, place k + 1
     in the ith row at the left side.
    (c) If a move takes you to an already filled square or if you move out of the
        square at the upper right hand corner, place k + 1 immediately below k.


    **/
    // Variables needed for algorithm
    //int Current = 1; // counter to be placed in array location
    //int Row = 0; // Row index to put Current in
    //int Col = 0; // Column index to put Current in

    /** 1. Place 1 in middle column of the 0th row **/

    // middle column
    Col = SquareSize/2;
    // top row
    Row = 0;
    // Fill first location
    Square[Row][Col] = Current;
    // Increment Current
    //Current++;

    /** 2. Iterate through entire 2d array: up 1 right 1 and filling with Current++ **/
    // with special cases for going over top and over right

    // SquareSize^2 number of moves
    for(int i=0;i<(SquareSize*SquareSize)-1;i++){
        // Special Case (c)
        // If current location is top right corner
        if(Row == 0 && Col == SquareSize-1){
            // move directly down
            Row++;
            // increment to place current+1 in location
            Current++;
            Square[Row][Col] = Current;
        }

        else{
            // Special Case (a)
            // if up moves us over top
            // move row to bottom row
            if(Row-1<0){
                Row = SquareSize-1;
            }
            else {Row--;}
            // Special Case (b)
            // if right moves us past right most
            // move col to 0
            if (Col+1>SquareSize-1){
                Col = 0;
            }
            else{Col++;}

            // if after moving to a valid location it is taken
            // place directly below
            if(Square[Row][Col] != 0){
                // move directly down
                Row++;
            }
            // ready to increment Current for placing in board
            Current++;
            // fill current location in board
            Square[Row][Col] = Current;

        }

    }//END for()


}//END magic()

void MagicSquare::Print(){

    for(int i=0;i<SquareSize;i++){
        for(int j=0;j<SquareSize;j++){
            cout << Square[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
