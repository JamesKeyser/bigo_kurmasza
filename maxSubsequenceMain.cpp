#include <iostream>
#include "maxSubsequence.hpp"

int main(int argc, char* argv[])
{

  std::vector<int> v1 = {-1, 2, -3, 4, -5};

  Range answer = maxSubsequence(v1);
  std::cout << "Range:  (" << answer.low << ", " << answer.high << ")" << std::endl;
}
