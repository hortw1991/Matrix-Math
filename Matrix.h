#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;

class Matrix {
    private:
        uint rows;
        uint cols;
        double** arr;

    public:

        Matrix(uint rows, uint cols);                   // constructor (all elements initialized to 0)
        Matrix(double** values, int w, int h);          // constructor (must make a copy of the passed in array)
        Matrix(const Matrix & m);                       // copy constructor
        ~Matrix();                                      // destructor

        Matrix add(double s) const;                     // add scalar to this matrix
        Matrix add(const Matrix & m) const;             // add this matrix and another matrix

        Matrix subtract(double s) const;                // subtract scalar from this matrix
        Matrix subtract(const Matrix & m) const;        // subtract another matrix from this matrix

        Matrix multiply(double s) const;                // multiply this matrix by a scalar
        Matrix multiply(const Matrix & m) const;        // multiply this matrix by another matrix

        Matrix divide(double s) const;                  // divide this matrix by a scalar
        Matrix t() const;                               // transpose of this matrix

        const uint numRows() const;                     // returns the number of rows
        const uint numCols() const;                     // returns the number of cols

        double & at(uint row, uint col);                // get/set element at row,col
        const double & at(uint row, uint col) const;    // get element at row,col (when using a const object)
        
        /*
         * Custom functions (including operator overloads)
         */
        Matrix operator+(const Matrix & m) const;
        Matrix operator+(double s) const;
        Matrix operator-(const Matrix & m) const;
        Matrix operator-(double s) const;
        Matrix operator*(const Matrix & m) const;
        Matrix operator*(double s) const;
        Matrix operator/(double s) const;               // Only 1 division overload
        Matrix operator-();
        double & operator()(uint row, uint col);
        const Matrix& operator=(const Matrix & m);

};

// ostream needs std since it isn't declared using here
std::ostream & operator<<(std::ostream & os, const Matrix & m);

Matrix operator+(double s, const Matrix & m);
Matrix operator-(double s, const Matrix & m);
Matrix operator*(double s, const Matrix & m);
Matrix operator/(double s, const Matrix & m);

#endif
