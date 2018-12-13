
#include <cmath>
#include <iostream>
#include <vector>
#include "Vector3D.h"


// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Vector3D.
// --------------------------------------------------------------------------------------

// ------------------ Constructors ------------------------

/**
 * default constructor
 */
Vector3D::Vector3D()
{
    _vector[0] = 0;
    _vector[1] = 0;
    _vector[2] = 0;
}

/**
 * constructs a vector with the given values by order:
 * @param a
 * @param b
 * @param c
 */
Vector3D::Vector3D(double a, double b, double c)
{
    _vector[0] = a;
    _vector[1] = b;
    _vector[2] = c;

}

/**
 * constructs a vector with the given array of elements:
 * @param array_for_vector
 */
Vector3D::Vector3D(const double *array_for_vector)
{
    _vector[0] = array_for_vector[0];
    _vector[1] = array_for_vector[1];
    _vector[2] = array_for_vector[2];

}

/**
 * ccopy constructor
 * @param other_vector3D
 */
Vector3D::Vector3D(const Vector3D &other_vector3D)
{
    _vector[0] = other_vector3D._vector[0];
    _vector[1] = other_vector3D._vector[1];
    _vector[2] = other_vector3D._vector[2];
}



// ------------------ overloaded operators ------------------------

/**
 * Overloading the + function. adds the vector to the other vector and returns the answer
 * @param other_vector
 * @return
 */
Vector3D Vector3D::operator+(const Vector3D &other_vector)
{
    Vector3D result = *this;     // Make a copy of myself.
    result += other_vector;            // Use += to add other to the copy.
    return result;
}

/**
 * Overloading the + function. subtract the vector to the other vector and returns the answer
 * @param other_vector
 * @return
 */
Vector3D Vector3D::operator-(const Vector3D &other_vector)
{
    Vector3D result = *this;
    result -= other_vector;
    return result;
}

/**
 * Overloading the += function. adds the other vector to the vector
 * @param other_vector
 * @return
 */
Vector3D &Vector3D::operator+=(const Vector3D &other_vector)
{
    _vector[0] += other_vector._vector[0];
    _vector[1] += other_vector._vector[1];
    _vector[2] += other_vector._vector[2];
    return *this;
}

/**
 * Overloading the -= function. subtracts the other vector to the vector
 * @param other_vector
 * @return
 */
Vector3D &Vector3D::operator-=(const Vector3D &other_vector)
{
    _vector[0] -= other_vector._vector[0];
    _vector[1] -= other_vector._vector[1];
    _vector[2] -= other_vector._vector[2];
    return *this;
}

/**
 * Overloading the += function. adds the number to the vector
 * @param number
 * @return
 */
Vector3D &Vector3D::operator+=(const double number)
{
    _vector[0] += number;
    _vector[1] += number;
    _vector[2] += number;
    return *this;

}

/**
 * Overloading the -= function. subtracts the number to the vector
 * @param number
 * @return
 */
Vector3D &Vector3D::operator-=(const double number)
{
    _vector[0] -= number;
    _vector[1] -= number;
    _vector[2] -= number;
    return *this;
}

/**
 * Overloading the -function. returns the - of the vector
 * @return
 */
Vector3D Vector3D::operator-()
{
    Vector3D result = *this;
    result._vector[0] = (-_vector[0]);
    result._vector[1] = (-_vector[1]);
    result._vector[2] = (-_vector[2]);
    return result;
}

/**
 * Overloading the * function. multiply the num and the vector element wise and returns the answer
 * @param num
 * @return
 */
Vector3D Vector3D::operator*(const double num)
{
    Vector3D result = *this;
    result *= num;
    return result;
}

/**
 * Overloading the / function. divides the vector with the given num element wise and returns the
 * answer. assumes that num in not 0!
 * @param num any number (not zero)
 * @return
 */
Vector3D Vector3D::operator/(const double num)
{
    Vector3D result = *this;
    result /= num;
    return result;
}

/**
 * Overloading the * function. multyply the number and the vector and return the answer
 * @param num
 * @param vector3D
 * @return
 */
Vector3D operator*(const double num, const Vector3D &vector3D)
{
    Vector3D result = vector3D;
    result *= num;
    return result;
}

/**
 * Overloading the *= function. multiply the number with the vector element wise
 * @param number
 * @return
 */
Vector3D &Vector3D::operator*=(const double number)
{
    _vector[0] *= number;
    _vector[1] *= number;
    _vector[2] *= number;
    return *this;
}

/**
 * Overloading the /= function. divides the vector with the number element wise
 * @param number
 * @return
 */
Vector3D &Vector3D::operator/=(const double number)
{
    // check that the number is not zero
    if (number)
    {
        _vector[0] /= number;
        _vector[1] /= number;
        _vector[2] /= number;
        return *this;
    }
}

/**
 * Overloading the | function. returns the distance between the vector and the other vector
 * @param other_vector
 * @return dist
 */
double Vector3D::operator|(const Vector3D &other_vector)
{
    return this->dist(other_vector);
}

/**
 * Overloading the * function. returns a scalar product of the vectors
 * @param other_vector
 * @return
 */
double Vector3D::operator*(const Vector3D &other_vector)
{
    return ((_vector[0] * other_vector._vector[0]) +
            (_vector[1] * other_vector._vector[1]) +
            (_vector[2] * other_vector._vector[2]));
}

/**
 * Overloading the ^ function. returns the angle in radians between the vectors
 * @param other_vector
 * @return
 */
double Vector3D::operator^(const Vector3D &other_vector)
{
    if (_vector == other_vector._vector)
    {
        return 0.0;
    }
    double normsMultiply = (this->norm() * other_vector.norm());
    if (normsMultiply != 0)
    {
        return acos(operator*(other_vector) / normsMultiply);
    }
}

/**
 * Overloading the = function. copy the values from the other vector
 * @param other_vector
 * @return
 */
Vector3D &Vector3D::operator=(const Vector3D &other_vector)
{
    _vector[0] = other_vector._vector[0];
    _vector[1] = other_vector._vector[1];
    _vector[2] = other_vector._vector[2];
    return *this;
}

/**
 * Overloading the [] function for changing the value in this location
 * @param i the index
 * @return
 */
double &Vector3D::operator[](int i)
{
    // check that the index is in bounds
    if (i < 3)
    {
        return _vector[i];
    }

}

/**
 * Overloading the [] function for only see what is in this location.
 * @param i the index
 * @return
 */
double Vector3D::operator[](int i) const
{
    // check that the index is in bounds
    if (i < 3)
    {
        return _vector[i];

    }
}

// ------------------ input/output methods ------------------------

/**
 * reads a vector from the user and inits it with the given values
 * @param is
 * @param vector3D
 * @return
 */
std::istream &operator>>(std::istream &is, Vector3D &vector3D)
{
    is >> vector3D._vector[0] >> vector3D._vector[1] >> vector3D._vector[2];
    return is;
}

/**
 * prints the vector
 * @param os
 * @param vector3D
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Vector3D &vector3D)
{
    return os << vector3D._vector[0] << " " << vector3D._vector[1] << " " << vector3D._vector[2];
}

// ------------------ Other methods ------------------------

/**
 * returns the norm of the vector
 * @return
 */
double Vector3D::norm() const
{
    return sqrt(pow(_vector[0], 2) + pow(_vector[1], 2) + pow(_vector[2], 2));
}

/**
 * returns the distance of the vectors
 * @param other_vector3D
 * @return
 */
double Vector3D::dist(const Vector3D &other_vector3D)
{
    return sqrt(pow((other_vector3D._vector[0] - _vector[0]), 2) +
                pow((other_vector3D._vector[1] - _vector[1]), 2) +
                pow((other_vector3D._vector[2] - _vector[2]), 2));
}

