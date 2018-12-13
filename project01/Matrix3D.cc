
#include "Matrix3D.h"


// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Matrix3D.
// --------------------------------------------------------------------------------------


// ------------------ Constructors ------------------------
/**
 * default constructor
 */
Matrix3D::Matrix3D() = default;

/**
 * init the matrix diagonal elements with the given number
 * @param number: the number we want to init the matrix diagonal with
 */
Matrix3D::Matrix3D(double number)
{
    for (int i = 0 ; i < 3 ; ++i)
    {
        _matrix[i][i] = number;
    }
}

/**
 * constructs a matrix with the given values by order:
 * @param a1
 * @param a2
 * @param a3
 * @param a4
 * @param a5
 * @param a6
 * @param a7
 * @param a8
 * @param a9
 */
Matrix3D::Matrix3D(double a1, double a2, double a3, double a4, double a5, double a6, double a7,
                   double a8, double a9)
{
    _matrix[0] = {a1, a2, a3};
    _matrix[1] = {a4, a5, a6};
    _matrix[2] = {a7, a8, a9};
}

/**
 * constructs a matrix with the given list of 9 elements
 * @param matrix: the list of elements
 */
Matrix3D::Matrix3D(double *matrix)
{

    _matrix[0] = {matrix[0], matrix[1], matrix[2]};
    _matrix[1] = {matrix[3], matrix[4], matrix[5]};
    _matrix[2] = {matrix[6], matrix[7], matrix[8]};

}

/**
 * constructs a matrix with the given 2d array
 * @param matrix: the 2d array
 */
Matrix3D::Matrix3D(double (*matrix)[3])
{
    for (int i = 0 ; i < 3 ; ++i)
    {
        for (int j = 0 ; j < 3 ; ++j)
        {
            _matrix[i][j] = matrix[i][j];
        }
    }
}

/**
 * constructs a matrix from 3 row 3D vectors
 * @param vector1
 * @param vector2
 * @param vector3
 */
Matrix3D::Matrix3D(Vector3D vector1, Vector3D vector2, Vector3D vector3)
{
    _matrix[0] = vector1;
    _matrix[1] = vector2;
    _matrix[2] = vector3;

}

/**
 * copy constructor
 * @param otherMatrix
 */
Matrix3D::Matrix3D(const Matrix3D &otherMatrix)
{
    for (int i = 0 ; i < 3 ; ++i)
    {
        _matrix[i] = otherMatrix._matrix[i];
    }

}


// ------------------ overloaded operators ------------------------

/**
 * Overloading the += function. adds the other matrix values to the matrix
 * @param otherMatrix
 * @return
 */
Matrix3D &Matrix3D::operator+=(const Matrix3D &otherMatrix)
{
    for (int i = 0 ; i < 3 ; ++i)
    {
        _matrix[i] += otherMatrix._matrix[i];
    }

    return *this;
}

/**
 * Overloading the -= function. substracts the other matrix values to the matrix
 * @param otherMatrix
 * @return
 */
Matrix3D &Matrix3D::operator-=(const Matrix3D &otherMatrix)
{
    for (int i = 0 ; i < 3 ; ++i)
    {
        _matrix[i] -= otherMatrix._matrix[i];
    }
    return *this;
}

/**
  * Overloading the *= function. multiply the other matrix values to the matrix
 * @param otherMatrix
 * @return
 */
Matrix3D &Matrix3D::operator*=(const Matrix3D &otherMatrix)
{
    int i, j, k;
    Matrix3D tempMatrix(*this);

    for (i = 0 ; i < 3 ; ++i)
    {
        for (j = 0 ; j < 3 ; ++j)
        {
            this->_matrix[i][j] = 0;
        }
    }

    for (i = 0 ; i < 3 ; ++i)
    {
        for (j = 0 ; j < 3 ; ++j)
        {
            for (k = 0 ; k < 3 ; ++k)
            {
                this->_matrix[i][j] += tempMatrix._matrix[i][k] * otherMatrix._matrix[k][j];
            }
        }
    }
    return *this;
}

/**
  * Overloading the *= function. multiply the matrix with the given number
 * @param number
 * @return
 */
Matrix3D &Matrix3D::operator*=(const double number)
{
    for (auto &i : _matrix)
    {
        i *= number;
    }
    return *this;
}

/**
 * Overloading the /= function. divide the matrix with the given number
 * @param number
 * @return
 */
Matrix3D &Matrix3D::operator/=(const double number)
{
    if (number)
    {
        for (auto &i : _matrix)
        {
            i /= number;
        }
        return *this;
    }
}

/**
 * Overloading the * function. multiply the matrix with the other matrix and returns the answer
 * @param otherMatrix
 * @return
 */
Matrix3D Matrix3D::operator*(const Matrix3D &otherMatrix)
{
    Matrix3D result = *this;
    result *= otherMatrix;
    return result;
//    int i, j, k;
//    Matrix3D multMatrix;
//    for (i = 0 ; i < 3 ; ++i)
//    {
//        for (j = 0 ; j < 3 ; ++j)
//        {
//            for (k = 0 ; k < 3 ; ++k)
//            {
//                multMatrix._matrix[i][j] += this->_matrix[i][k] * otherMatrix._matrix[k][j];
//            }
//        }
//    }
//    return multMatrix;
}

/**
 * Overloading the - function. subtract the matrix with the other matrix and returns the answer
 * @param otherMatrix
 * @return
 */
Matrix3D Matrix3D::operator-(const Matrix3D &otherMatrix)
{
    Matrix3D result = *this;
    result -= otherMatrix;
    return result;
//    Matrix3D new_matrix;
//    for (int i = 0 ; i < 3 ; ++i)
//    {
//        new_matrix._matrix[0] = _matrix[0] - otherMatrix._matrix[0];
//    }
//    return new_matrix;
}

/**
 * Overloading the [] function. returns the row
 * @param i the index of the row
 * @return the i row
 */
Vector3D Matrix3D::operator[](int i) const
{
    if (i < 3)
    {
        return _matrix[i];

    }
}

/**
 * Overloading the [] function. returns the row itself
 * @param i the index of the row
 * @return the i row
 */
Vector3D &Matrix3D::operator[](int i)
{
    if (i < 3)
    {
        return _matrix[i];

    }
}

/**
 * Overloading the + function. adds the matrix with the other matrix and returns the answer
 * @param otherMatrix
 * @return
 */
Matrix3D Matrix3D::operator+(const Matrix3D &otherMatrix)
{

    Matrix3D result = *this;
    result += otherMatrix;
    return result;
//    Matrix3D new_matrix;
//    for (int i = 0 ; i < 3 ; ++i)
//    {
//        new_matrix._matrix[0] = _matrix[0] + otherMatrix._matrix[0];
//    }
//    return new_matrix;
}

/**
 * Overloading the * function. multiply the matrix with the other matrix and returns the answer
 * @param otherVector
 * @return
 */
Vector3D Matrix3D::operator*(const Vector3D &otherVector)
{
    Vector3D result;
    for (int i = 0 ; i < 3 ; ++i)
    {
        result[i] = _matrix[i] * otherVector;
    }
    return result;
}

/**
 * Overloading the = function. sets the matrix to have the same values as the other matrix
 * @param otherMatrix
 * @return the matrix
 */
Matrix3D &Matrix3D::operator=(const Matrix3D &otherMatrix)
{
    _matrix[0] = otherMatrix._matrix[0];
    _matrix[1] = otherMatrix._matrix[1];
    _matrix[2] = otherMatrix._matrix[2];
    return *this;
}


// ------------------ input/output methods ------------------------

/**
 * Overloading the >> function. prints the matrix
 * @param is
 * @param matrix3D
 * @return
 */
std::istream &operator>>(std::istream &is, Matrix3D &matrix3D)
{
    is >> matrix3D._matrix[0] >> matrix3D._matrix[1] >> matrix3D._matrix[2];
    return is;
}

/**
 * Overloading the << function. receives the matrix elements and sets them
 * @param os
 * @param matrix3D
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Matrix3D &matrix3D)
{
    return os << matrix3D._matrix[0] << std::endl << matrix3D._matrix[1] << std::endl << matrix3D
            ._matrix[2];
}



// ------------------ Other methods ------------------------

/**
 * this metod receives a row number between 0 to 2 and returns the row as Vector3D
 * @param i the row number
 * @return thr row as Vector3D
 */
Vector3D &Matrix3D::row(const short i)
{
    return _matrix[i];
}

/**
 * this metod receives a column number between 0 to 2 and returns the column as Vector3D
 * @param i the column number
 * @return thr column as Vector3D
 */
Vector3D Matrix3D::column(const short i)
{
    Vector3D col(_matrix[0][i], _matrix[1][i], _matrix[2][i]);
    return col;
}

/**
 * this method returns the sum of the elements of the matrix in the diagonal
 * @return the trace of the matrix (sum of the diagonal)
 */
double Matrix3D::trace() const
{
    return (_matrix[0][0] + _matrix[1][1] + _matrix[2][2]);
}

/**
 * this method returns the determinant of the matrix
 * @return the determinant of the matrix
 */
double Matrix3D::determinant() const
{
    double a1 = (_matrix[1][1] * _matrix[2][2] - _matrix[2][1] * _matrix[1][2]);
    double a2 = (_matrix[1][0] * _matrix[2][2] - _matrix[2][0] * _matrix[1][2]);
    double a3 = (_matrix[1][0] * _matrix[2][1] - _matrix[2][0] * _matrix[1][1]);
    return (_matrix[0][0] * a1 - _matrix[0][1] * a2 + _matrix[0][2] * a3);
}
