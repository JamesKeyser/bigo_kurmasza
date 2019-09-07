#include <iostream>
#include "matrixSearch.hpp"

int main(int argc, char *argv[]) {

  // Matrix is an alias defined in matrixSearch.hpp
  Matrix<int> m1 = {{1, 2, 3}, {2, 3, 4}, {4, 5, 6}};

  int searchFor = 15;
  bool answer = matrixSearch(searchFor, m1);
  std::cout << "Value " << searchFor << (answer ? " found" : " not found") << std::endl;

  }
