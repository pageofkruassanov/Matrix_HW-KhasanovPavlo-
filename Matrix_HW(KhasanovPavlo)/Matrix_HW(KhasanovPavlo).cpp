#include "Matrix.h"
#include <iostream>

using namespace std;
int main()
{
    Matrix<int> integer1(3, 3);
    integer1.setMatrixRandom(0, 50);
    Matrix<int> integer2(3, 3);
    integer2.setMatrixRandom(0, 50);
    Matrix<int> integer3(3, 3);
    cout << integer2[0][0];
    /*integer3 = integer1 + integer2;
    cout << integer3[0][0];*/
    /*cout << (integer1 + integer2);*/
}