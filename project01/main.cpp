#include "Vector3D.h"
#include "Matrix3D.h"

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<Vector3D> vec3Ds;
    Vector3D v;
    while(std::cin >> v)
    {
        vec3Ds.push_back(v);
    }

    Vector3D init;
    Vector3D sum = std::accumulate(vec3Ds.begin(), vec3Ds.end(), init);

    std::cout << "sum = " << sum << std::endl;
//    return 0;
//    Vector3D a;
//    Vector3D b;
//    Vector3D c = a+b;
//    Vector3D v1(1.0, 2.0, 5.798);
//    std::cout << "1: " << v1 << std::endl;
//    Vector3D v2(v1);
//    std::cout << "2: " << v2 << std::endl;
//    Vector3D v3;
//    std::cout << "3: " << v3 << std::endl;
//    double d[3] = { 1.5, 6.1, -9.01 };
//    Vector3D v4(d);
//    std::cout << "4: " << v4 << std::endl;
//    Vector3D add = (v1 + v4);
//    std::cout << "5: " << add << std::endl;
//    v1 += v4;
//    std::cout << "6: " << v1 << std::endl;
//    Vector3D sub = v4 - v1;
//    std::cout << "7: " << sub << std::endl;
//    v4 -= v1;
//    std::cout << "8: " << v4 << std::endl;
//    v3 += 4.31;
//    std::cout << "9: " << v3 << std::endl;
//    v3 -= 2.34;
//    std::cout << "10: " << v3 << std::endl;
//    v3 = -v3;
//    std::cout << "11: " << v3 << std::endl;
//    Vector3D mul = v4 * 1.3;
//    std::cout << "12: " << mul << std::endl;
//    Vector3D mul2 = 3.5 * v1;
//    std::cout << "13: " << mul2 << std::endl;
//    Vector3D div = v4 / 2.9;
//    std::cout << "14: " << div << std::endl;
//    v4 *= 3.2;
//    std::cout << "15: " << v4 << std::endl;
//    v4 /= 1.6;
//    std::cout << "16: " << v4 << std::endl;
//    double dis = v3 | v4;
//    std::cout << "17: " << dis <<std::endl;
//    double scal = v3*v4;
//    std::cout << "18: " << scal << std::endl;
//    double angle = v3^v4;
//    std::cout << "19: " << angle << std::endl;
//    v3 = v4;
//    std::cout << "20: " << v3 << " and " << v4 << std::endl;
//    std::cout << "21: " << v3[1] << std::endl;
//    v3[1] = 5.78;
//    std::cout << "22: " << v3[1] << std::endl;
//
//    Matrix3D m1(v1, v2, v3);
//    std::cout << "23: \n" << m1 << std::endl;
//    Matrix3D m2;
//    std::cout << "24: \n" << m2 << std::endl;
//    Matrix3D m3(4.6);
//    std::cout << "25: \n" << m3 << std::endl;
//    Matrix3D m4(m1);
//    std::cout << "26: \n" << m4 << std::endl;
//    Matrix3D m5(1, 2, 3, 4, 5, 6, 7, 8, 9);
//    std::cout << "27: \n" << m5 << std::endl;
//    double d1[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
//    double d2[3][3] = { {1, 2, 1}, {2, 3, 2}, {1, 2, 1} };
//    Matrix3D m6(d1);
//    std::cout << "28: \n" << m6 << std::endl;
//    Matrix3D m7(d2);
//    std::cout << "29: \n" << m7 << std::endl;
//    Matrix3D madd = m1 + m3;
//    std::cout << "30: \n" << madd << std::endl;
//    m1 += m3;
//    std::cout << "31: \n" << m1 << std::endl;
//    Matrix3D msub = m3 - m1;
//    std::cout << "32: \n" << msub << std::endl;
//    m3 -= m1;
//    std::cout << "33: \n" << m3 << std::endl;
//    m7 *= 3.2;
//    std::cout << "34: \n" << m7 << std::endl;
//    m7 /= 1.6;
//    std::cout << "35: \n" << m7 << std::endl;
//    Matrix3D mmul = m6 * m7;
//    std::cout << "36: \n" << mmul << std::endl;
//    Vector3D vmul = m7 * v3;
//    std::cout << "37: \n" << vmul << std::endl;
//    std::cout << "38: \n" << m6[1] << std::endl;
//    m6[1] = *(new Vector3D());
//    std::cout << "39: \n" << m6[1] << std::endl;
//    m6 = m7;
//    std::cout << "40: \n" << m6 << "\nand\n" << m7 << std::endl;
//    std::cout << "41: \n" << m6.row(2) << std::endl;
//    std::cout << "42: \n" << m6.column(0) << std::endl;
//    std::cout << "43: \n" << m6.trace() << std::endl;
//    std::cout << "44: \n" << m6.determinant() << std::endl;
//
//    return 0;
}