#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "maxSubsequence.hpp"

TEST_CASE("Entire sequence positive") {
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  Range answer = maxSubsequence(v1);
  REQUIRE(answer.low == 0);
  REQUIRE(answer.high == 4);
}

TEST_CASE("Entire sequence negative") {
std::vector<int> v1 = {-1, -2, -3, -4, -5};
Range answer = maxSubsequence(v1);
REQUIRE(answer.low == 0);
REQUIRE(answer.high == 0);
}

TEST_CASE("Sequence is all 0") {
std::vector<int> v1 = {0, 0, 0, 0, 0};
Range answer = maxSubsequence(v1);
REQUIRE(answer.low == 0);
REQUIRE(answer.high == 0);
}

TEST_CASE("any 2 numbers next to each other = 0") {
std::vector<int> v1 = {-1, 1, -1, 1};
Range answer = maxSubsequence(v1);
REQUIRE(answer.low == 1);
REQUIRE(answer.high == 1);
}

TEST_CASE("Random 1") {
std::vector<int> v1 = {1, 2, -3, 4, -4};
Range answer = maxSubsequence(v1);
REQUIRE(answer.low == 0);
REQUIRE(answer.high == 3);
}
//DOUBLES

TEST_CASE("Sequence double values") {
std::vector<double> v1 = {1.54, 5.3245, -23.846, 345.342, -345.45, 544.24, 243.978566, -564, 145, 899};
Range answer = maxSubsequence(v1);
REQUIRE(answer.low == 5);
REQUIRE(answer.high == 9);
}

TEST_CASE("Big Doubles") {
std::vector<double> v1 = {1543453453, 56436433245, -236354634364846, 345475745342, -34545,
                          54454624, 243978566, -56374734, 1453346643, 892352539};
Range answer = maxSubsequence(v1);
REQUIRE(answer.low == 3);
REQUIRE(answer.high == 9);
}

TEST_CASE("Entire sequence doubles negative") {
std::vector<double> v1 = {-1.754, -2.2354, -3.532, -4.67, -1.12};
Range answer = maxSubsequence(v1);
REQUIRE(answer.low == 4);
REQUIRE(answer.high == 4);
}

