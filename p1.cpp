#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    cout << "**************************************************" << endl;
    cout << "TESTING CONSTRUCTOR FUNCTIONS" << endl;
    cout << "**************************************************" << endl;
    cout << "Creating Matrix [0 0 0][0 0 0] (default 0 initialization)" << endl;
    Matrix a(2,3);
    cout << a << endl;

    cout << "Changing values to [1 2 3][4 5 6] with .at()" << endl;
    a.at(0,0) = 1;
    a.at(0,1) = 2;
    a.at(0,2) = 3;
    a.at(1,0) = 4;
    a.at(1,1) = 5;
    a.at(1,2) = 6;
    cout << a << endl;

    cout << "Testing constructor with array [6 5 4][3 2 1]" << endl;
    double** arr = new double*[2];
    for (uint i = 0; i < 2; i++) {
        arr[i] = new double[3];
    }
    arr[0][0] = 6;
    arr[0][1] = 5;
    arr[0][2] = 4;
    arr[1][0] = 3;
    arr[1][1] = 2;
    arr[1][2] = 1;
    Matrix b(arr, 3, 2);
    cout << b << endl;

    cout << "Testing copy constructor to [6 5 4][3 2 1]" << endl;
    Matrix c(b);
    cout << c << endl;

    cout << "**************************************************" << endl;
    cout << "TESTING NORMAL FUNCTIONS" << endl;
    cout << "**************************************************" << endl;
    cout << "Testing matrix.add(5)" << endl;
    cout << a << endl;
    cout << a.add(5) << endl;

    cout << "Testing matrix.add(matrix)" << endl;
    cout << a << endl << b << endl;
    cout << a.add(b) << endl;

    cout << "Testing matrix.subtract(5)" << endl;
    cout << a << endl;
    cout << a.subtract(5) << endl;

    cout << "Testing matrix.subtract(m)" << endl;
    cout << b << endl << a << endl;
    cout << b.subtract(a) << endl;

    cout << "Testing matrix.divide(5)" << endl;
    cout << b << endl;
    cout << b.divide(5) << endl;
    
    cout << "Testing matrix.multiply(-10)" << endl;
    cout << b << endl;
    cout << b.multiply(-10) << endl;;

    cout << "Testing matrix.mutiply(matrix)" << endl;
    double** arr2 = new double*[2];
    for (uint i = 0; i < 2; i++) {
        arr2[i] = new double[4];
    }
    arr2[0][0] = -2;
    arr2[0][1] = 4;
    arr2[0][2] = 0;
    arr2[0][3] = 5;
    arr2[1][0] = -1;
    arr2[1][1] = 6;
    arr2[1][2] = 2;
    arr2[1][3] = 1;
    
    Matrix mtest1(arr2, 4, 2);
    cout << mtest1 << endl;

    double** arr3 = new double*[4];
    for (uint i = 0; i < 4; i++) {
        arr3[i] = new double[4];
    }

    arr3[0][0] = 7;
    arr3[0][1] = 3;
    arr3[0][2] = -3;
    arr3[0][3] = 4;
    arr3[1][0] = -4;
    arr3[1][1] = -2;
    arr3[1][2] = -1;
    arr3[1][3] = 0;
    arr3[2][0] = 1;
    arr3[2][1] = 5;
    arr3[2][2] = 2;
    arr3[2][3] = 6;
    arr3[3][0] = 8;
    arr3[3][1] = 9;
    arr3[3][2] = 10;
    arr3[3][3] = 11;
    
    Matrix mtest2(arr3, 4, 4);
    cout << mtest2 << endl;
    cout << "Answer: [10 31 52 47][-21 4 11 19]" << endl;
    cout << mtest1.multiply(mtest2) << endl;

    cout << "Transposing matrix.t()" << endl;
    cout << mtest1.multiply(mtest2).t() << endl;

    cout << "Checking matrix.numRows" << endl << mtest1 << endl << mtest1.numRows() << endl;
    cout << "Checking matrix.numCols" << endl << mtest2 << endl << mtest2.numCols() << endl;

    cout << "Checking matrix.at(0,2)" << endl;
    cout << a << endl << a.at(0,2) << endl;
    
    cout << "Checking matrix.at(1,0) = 0" << endl;
    Matrix z(a);
    cout << z << endl;
    z.at(1,0) = 0;
    cout << z << endl;

    cout << "**************************************************" << endl;
    cout << "TESTING OVERLOAD FUNCTIONS" << endl;
    cout << "**************************************************" << endl;
    cout << "Testing matrix + 2 " << endl;
    cout << z << endl << z + 2 << endl;

    cout << "Testing matrix + matrix" << endl;
    cout << z << endl << a << endl << z + a << endl;

    cout << "Testing matrix - 2 " << endl;
    cout << b << endl << b - 2 << endl;

    cout << "Testing matrix - matrix" << endl;
    cout << a << endl << b << endl << a - b << endl;

    cout << "Testing matrix * .5 " << endl;
    cout << b << endl << b * .5 << endl;

    cout << "Testing matrix * matrix" << endl;
    cout << mtest1 << endl << mtest2 << endl << mtest1 * mtest2 << endl;

    cout << "Testing matrix / -2 " << endl;
    cout << mtest1 * mtest2 << endl << mtest1 * mtest2 / 2 << endl;

    cout << "**************************************************" << endl;
    cout << "TESTING ADDITIONAL FUNCTIONS" << endl;
    cout << "**************************************************" << endl;
    
    cout << "Testing matrix(1,2)=10000" << endl;
    cout << z << endl;
    z(1,2)=10000;
    cout << z << endl;

    cout << "Testing = overload copy assignment" << endl;
    cout << "After copying, the second matrix should be equal to the first" << endl;
    
    Matrix d = mtest1 * mtest2;
    cout << d << endl;
    cout << z << endl;
    z = d;
    cout << z << endl;

    cout << "Testing overloaded scalar operations" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Testing 4 + matrix" << endl;
    cout << a << endl << 4 + a << endl;

    cout << "Testing 14 - matrix" << endl;
    cout << a << endl << 14 - a << endl;

    cout << "Testing 0 * matrix" << endl;
    cout << a << endl << 0 + a << endl;

    cout << "Testing 10 * matrix" << endl;
    cout << a << endl << 10 *  a << endl;

    cout << "Testing 6.5 / matrix" << endl;
    cout << z << endl << 6.5 / z << endl;

    cout << "Testing negation" << endl;
    cout << z << endl << -z << endl;

    cout << "Testing negation in *" << endl;
    cout << -z << endl; 
    cout << -z + a << endl;
    cout << -z + -z << endl;
    cout << z + -a << endl;

    cout << "**************************************************" << endl;
    cout << "TESTING MISC FUNCTIONS" << endl;
    cout << "**************************************************" << endl;
        
    cout << "Making matrix of different lengths" << endl;
    Matrix p(4, 4);
    p(0,0)= 0;
    p(0,1)= 100;
    p(0,2)= 10;
    p(0,3)= 444;
    p(1,0)= 2222;
    p(1,1)= 333;
    p(1,2)= 11111;
    p(1,3)= 4444;
    p(2,0)=2222;
    p(2,1)=5555 ;
    p(2,2)=444 ;
    p(2,3)=23 ;
    p(3,0)= 4;
    p(3,1)= 67;
    p(3,2)= 1112;
    p(3,3)= 111111;
    cout << p << endl;













    
    return 0;


}

