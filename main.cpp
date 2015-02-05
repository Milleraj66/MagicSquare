#include <iostream>
#include "MagicSquare.h"

using namespace std;

int main()
{
    // Two objects defined by the constuctor
    MagicSquare S3(3);
    MagicSquare S5(5);
    // Size to be determined in console by user
    MagicSquare UserDefined;

    // Form, Fill, and print 3x3
    cout << "3x3 Magic Square " << endl;
    S3.Magic();
    S3.Print();

    // Form, FIll, and print 5x5
    cout << "5x5 Magic Square " << endl;
    S5.Magic();
    S5.Print();

    // User can input size at console
    int Size = 0;
    while(Size < 3 || Size > 111){
        cout << "Please input a size for the magic board from 3 to 111\n Input: " << endl;
        cin >> Size;
        cout << endl;
        if(Size >= 3 && Size <= 111 && Size%2 != 0){
            cout << "UserDefined Magic Square of Size: " << Size << endl;
            UserDefined.SetSquareSize(Size);
            UserDefined.Magic();
            UserDefined.Print();
        }

    }


    return 0;
}
