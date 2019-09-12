#include <iostream>
#include "maxSubsequence.hpp"

int main(int argc, char* argv[])
{

  std::vector<int> v1 = {-1, 2, -3, 4, -5};
    std::vector<double> v2 = {-1, 2, -3, 4, -5};

  Range answer = maxSubsequence(v2);
  std::cout << "here1";

  std::cout << "Range:  (" << answer.low << ", " << answer.high << ")" << std::endl;
}
