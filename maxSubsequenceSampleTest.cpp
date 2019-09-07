#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "maxSubsequence.hpp"

TEST_CASE("Entire sequence positive") {
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  Range answer = maxSubsequence(v1);
  REQUIRE(answer.low == 0);
  REQUIRE(answer.high == 4);
}
