//
// Created by Dell on 12/9/2018.
//

#ifndef PROJECT01_MATRIX3D_H
#define PROJECT01_MATRIX3D_H


#include <cmath>
#include "Vector3D.h"

class Matrix3D
{
public:
    Matrix3D();

    explicit Matrix3D(double number);

    Matrix3D(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8,
             double a9);

    explicit Matrix3D(double matrix[9]);

    explicit Matrix3D(double matrix[3][3]);

    Matrix3D(Vector3D vector1, Vector3D vector2, Vector3D vector3);

    Matrix3D(const Matrix3D &otherMatrix);

    Matrix3D &operator+=(const Matrix3D &otherMatrix);

    Matrix3D &operator-=(const Matrix3D &otherMatrix);

    Matrix3D &operator*=(const Matrix3D &otherMatrix);

    Matrix3D &operator*=(const double number);

    Matrix3D &operator/=(const double number);

    Matrix3D operator*(const Matrix3D &otherMatrix);

    Matrix3D operator-(const Matrix3D &otherMatrix);

    Matrix3D operator+(const Matrix3D &otherMatrix);

    Vector3D operator*(const Vector3D &otherVector);

    Matrix3D &operator=(const Matrix3D &otherMatrix);

    Vector3D operator[](int i) const ;

    Vector3D &operator[](int i);

//    double &operator[](int i) const;

    Vector3D &row(const short i);

    Vector3D column(const short i);

    double trace() const;

    double determinant() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix3D &matrix3D);

    friend std::istream &operator>>(std::istream &is, Matrix3D &matrix3D);

private:
    Vector3D _matrix[3];
};


#endif //PROJECT01_MATRIX3D_H
