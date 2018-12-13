#include "Matrix3D.h"

#include <iostream>

int main()
{
  Matrix3D m;
  while(std::cin >> m)
    {
      std::cout << m*m;
    }

  return 0;
}
