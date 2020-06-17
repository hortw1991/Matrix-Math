#include <iostream>
#include "Matrix.h"

typedef unsigned int uint;

using namespace std;

Matrix::Matrix(uint rows, uint cols) {
    // First setup member vars
    this->rows = rows;
    this->cols = cols;

    // Rows - allocate an array of pointers
    this->arr = new double*[rows];

    // Cols - iterate through the array allocating our cols
    for (uint i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }
}


Matrix::Matrix(double** values, int w, int h) {
    /* Alternative constructor - setup a matrix with width w and height h
     * with data elements from values.
     */
    this->rows = h;
    this->cols = w;

    this->arr = new double*[rows];

    for (uint i = 0; i < this->rows; i++) {
        arr[i] = new double[this->cols];
    }

    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            arr[i][j] = values[i][j];
        }
    }
}


Matrix::Matrix(const Matrix & m) {
    /* Copy Constructor
     */
    this->rows = m.numRows();
    this->cols = m.numCols();

    this->arr = new double*[rows];

    for (uint i = 0; i < this->rows; i++) {
        arr[i] = new double[this->cols];
    }

    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            arr[i][j] = m.at(i, j);
        }
    }
}


Matrix::~Matrix() {
     /* Loop over the rows deleting each element, before finally dellocating the arr.
     */
    for (uint i = 0; i < this->rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}


Matrix Matrix::add(double s) const {
    /* Initialize a new matrix with the same dimensions as this one.  Loop and
     * add the scalar to each element.
     */
    Matrix newMatrix(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            newMatrix.at(i, j) = arr[i][j] + s;
        }
    }
    return newMatrix;
}


Matrix Matrix::add(const Matrix & m) const {
    /* Simply add the elements of this matrix and the other into a new matrix and
     * return.
     */
    Matrix newMatrix(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            double newVal = arr[i][j] + m.at(i, j);
            newMatrix.at(i, j) = newVal;
        }
    }
    return newMatrix;

}


Matrix Matrix::subtract(double s) const {
    /* Initialize a new matrix with the same dimensions as this one.  Loop and
     * subtract the scalar to each element.
     */
    Matrix newMatrix(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            newMatrix.at(i, j) = arr[i][j] - s;
        }
    }
    return newMatrix;
}


Matrix Matrix::subtract(const Matrix & m) const {
    /* Simply subtract the elements of this matrix and the other into a new matrix and
     * return.
     */
    Matrix newMatrix(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            double newVal = arr[i][j] - m.at(i, j);
            newMatrix.at(i, j) = newVal;
        }
    }
    return newMatrix;
}


Matrix Matrix::multiply(double s) const {
    /* Scalar multiplication just multiplies each element of the array by the
     * scalar.
     */
    Matrix newMatrix(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            newMatrix.at(i, j) = arr[i][j] * s;
        }
    }
    return newMatrix;
}


Matrix Matrix::multiply(const Matrix & m) const {
    /* NOT the same as matrix addition.  Must use dot product.
     */

    /*Matrix newMatrix(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            double newVal = arr[i][j] * m.at(i, j);
            newMatrix.at(i, j) = newVal;
        }
    }*/
    
    // New matrix needs the rows of matrix 1 and cols of matrix 2
    Matrix newMatrix(this->rows, m.numCols());
    
    // First get the element initialized to 0 just in case I messed something up. 
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            newMatrix.at(i, j) = 0;
        }
    }
    
    // Dot product (rows of 1 cols of 2 cols of 1) add the the appropriate element.
    // Make sure to grab the new value before adding the product to it.
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            for (uint k = 0; k < this->cols; k++) {
                newMatrix.at(i, j) = newMatrix.at(i, j) + this->at(i, k) * m.at(k, j);
            }
        }
    }

    return newMatrix;
}


Matrix Matrix::divide(double s) const {
    /* The same as multiplying by a scalar.
     */
    Matrix newMatrix(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            newMatrix.at(i, j) = arr[i][j] / s;
        }
    }
    return newMatrix;
}


Matrix Matrix::t() const {
    /* Transpose switches rows and columns.
     */
    uint newCols = this->numRows();
    uint newRows = this->numCols();

    double** newArr = new double*[newRows];

    for (uint i = 0; i < newRows; i++) {
      newArr[i] = new double[newCols];
    }

    for (uint i = 0; i < this->rows; i++) {
      for (uint j = 0; j < this->cols; j++) {
        newArr[j][i] = this->arr[i][j];
      }
    }

    Matrix newMatrix(newArr, newCols,  newRows);
    
    // Delete the new Arr
    for (uint i = 0; i < newRows; i++) {
        delete[] newArr[i];
    }
    delete[] newArr;

    return newMatrix;
}


const uint Matrix::numRows() const {
    return this->rows;
}


const uint Matrix::numCols() const {
    return this->cols;
}


double & Matrix::at(uint row, uint col) {
    /* Return the reference for value assignment. 
     * matrix.at(#,#) = #.
     */
    double & val = arr[row][col];
    return val;
}


const double & Matrix::at(uint row, uint col) const {
    /* Constant function does not support value assignment.
     */
    const double & val = arr[row][col];
    return val;
}


/*********************************************
 *       Operator Overloaded Functions
 *               (member)
 *
 * These are basically all the same as they
 * simply use the already set up operation
 * function.             
 *********************************************/

Matrix Matrix::operator+(double s) const {
    Matrix newerMatrix(this->add(s));
    
    return newerMatrix;
}


Matrix Matrix::operator+(const Matrix & m) const {
    Matrix newerMatrix(this->add(m));

    return newerMatrix;
}


Matrix Matrix::operator-(double s) const {
    Matrix newerMatrix(this->subtract(s));

    return newerMatrix;
}


Matrix Matrix::operator-(const Matrix & m) const {
    Matrix newerMatrix(this->subtract(m));

    return newerMatrix;
}


Matrix Matrix::operator*(double s) const {
    Matrix newerMatrix(this->multiply(s));

    return newerMatrix;
}


Matrix Matrix::operator*(const Matrix & m) const {
    Matrix newerMatrix(this->multiply(m));

    return newerMatrix;
}


Matrix Matrix::operator/(double s) const {
    Matrix newerMatrix(this->divide(s));

    return newerMatrix;
}


double & Matrix::operator()(uint row, uint col) {
    double & val = arr[row][col];
    return val;
}


const Matrix& Matrix::operator=(const Matrix & m) {
    /* Custom assignment operator - first avoid self-assignment
     */
    if (this != & m) {
        // Check if sizes are different. We will then have to delete our array
        if ((this->rows != m.numRows()) || (this->cols != m.numCols())) {
            // Delete array before changing internal row/col values
            for (uint i = 0; i < this->rows; i++) {
                delete[] arr[i];
            }
            delete[] arr;
            
            this->rows = m.numRows();
            this->cols = m.numCols();
            
            this->arr = new double*[rows];
            for (uint i = 0; i < this->rows; i++) {
                arr[i] = new double[this->cols];
            }
         }

        // Standard copy assignment can happen regardless of above happening
        for (uint i = 0; i < this->rows; i++) {
            for (uint j = 0; j < this->cols; j++) {
                this->arr[i][j] = m.at(i, j);
            }
        }
    }

    return *this;
}


Matrix Matrix::operator-() {
    /* Simple negation.
     */
    Matrix newMatrix(*this);
     
    return newMatrix.multiply(-1);
}


/*********************************************
 *       Operator Overloaded Functions
 *             (non-member)
 *
 *********************************************/

std::ostream & operator<<(ostream & os, const Matrix & m) {
    /* Must return the reference to the actual setup ostream object
     * Will print in the form:
     * [ # # ]
     * [ # # ]
     */
    
    // Get widths of each col
    int lengths[5];

    for (uint i = 0; i < m.numCols(); i++) {
        int colMax = 1;
        for (uint k = 0; k < m.numRows(); k++) {
            //int numLength = to_string(m.at(k, i)).length();
            string num = to_string(m.at(k, i));
            int len = num.size();
            if (colMax < len) {
                colMax = len;
            }
        }
        lengths[i] = colMax;
    }

    // Note: the size() function starts at 8, so 8 means it is 1 digit.  Pad
    // accordingly, but it shouldn't matter since it's just getting the difference.
    for (uint i = 0; i < m.numRows(); i++) {
        os << "[ ";
        for (uint j = 0; j < m.numCols() - 1; j++) {
            int colLength = lengths[j];
            int numLength = to_string(m.at(i, j)).length();
                
            // Calculate the offset between this number and the column length.  Add
            // leading spaces accordingly.
            int offset = colLength - numLength;
            for (int k = 0; k < offset; k++) {
                os << " ";
            }
            
            os << m.at(i, j) << ", ";

        }

        // Append final value without the column
        int colLength = lengths[m.numCols() - 1];
        int numLength = to_string(m.at(i, m.numCols() - 1)).length();
        int offset = colLength - numLength;

        for (int i = 0; i < offset; i++) {
            os << " ";
        }

        os << m.at(i, m.numCols() - 1);
        os << " ]" << endl;
    }

    return os;
}


Matrix operator+(double s, const Matrix & m) {
    /* LHS addition overload.  Must be non member to not take *this
     * pointer.
     */
    Matrix newMatrix = m.add(s);
    return newMatrix;
}


Matrix operator-(double s, const Matrix & m) {
    /* Unlike other LHS operator overloads, this has to
     * be changed since the order matters.
     */
    Matrix offset(m.numRows(), m.numCols());
    for (uint i = 0; i < m.numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            offset.at(i, j) = s;
        }
    }
    Matrix newMatrix = offset.subtract(m);
    return newMatrix;
}


Matrix operator*(double s, const Matrix & m) {
    Matrix newMatrix = m.multiply(s);
    return newMatrix;
}


Matrix operator/(double s, const Matrix & m) {
    /* Unlike other LHS operator overloads, this has to
     * be changed since the order matters.
     */
    Matrix newMatrix(m.numRows(), m.numCols());
    for (uint i = 0; i < m.numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            double val = s / m.at(i, j);
            newMatrix.at(i, j) = val;
        }
    }

    return newMatrix;
}
