#ifndef PROJECT01_VECTOR3D_H
#define PROJECT01_VECTOR3D_H

#include <iostream>

class Vector3D
{
public:
    Vector3D();

    Vector3D(double a, double b, double c);

    explicit Vector3D(const double array_for_vector[3]);

    Vector3D(const Vector3D &other_vector3D);

    double norm() const;

    double dist(const Vector3D &other_vector3D);

    Vector3D operator+(const Vector3D &other_vector);

    Vector3D operator-(const Vector3D &other_vector);

    Vector3D &operator+=(const Vector3D &other_vector);

    Vector3D &operator+=(const double number);

    Vector3D &operator-=(const Vector3D &other_vector);

    Vector3D &operator-=(const double number);

    Vector3D operator-();

    Vector3D operator*(const double num);

    Vector3D operator/(const double num);

    friend Vector3D operator*(const double num, const Vector3D &vector3D);

    Vector3D &operator*=(const double number);

    Vector3D &operator/=(const double number);

    double operator|(const Vector3D &other_vector);

    double operator*(const Vector3D &other_vector);

    double operator^(const Vector3D &other_vector);

    friend std::ostream &operator<<(std::ostream &os, const Vector3D &vector3D);

    friend std::istream &operator>>(std::istream &is, Vector3D &vector3D);

    Vector3D &operator=(const Vector3D &other_vector);

    double operator[](int i) const;

    double &operator[](int i);

private:
    double _vector[3] = {}; // all zero
};


#endif //PROJECT01_VECTOR3D_H
