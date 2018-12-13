#include "Vector3D.h"

#include <iostream>
#include <vector>
#include <numeric>

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
  return 0;
}
