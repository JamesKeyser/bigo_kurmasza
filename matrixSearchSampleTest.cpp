#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <stdexcept>
#include <utility>
using namespace std::rel_ops;

#include "matrixSearch.hpp"


TEST_CASE("Empty Matrix returns false") {
  Matrix<int> m1;
  bool answer = matrixSearch(654, m1);
  REQUIRE(!answer);
}

TEST_CASE("Non-square 'wide' matrix raises exception") {
  Matrix<int> m1 = {{1, 2}};
  REQUIRE_THROWS_AS(matrixSearch(654, m1), std::invalid_argument);
}

TEST_CASE("10x10 sequential") {

  int size = 10;
  Matrix<int> m1(size);
  for (int i = 0; i < size; i++) {
    m1[i].resize(size);
    for (int j = 0; j < size; j++) {
      m1[i][j] = i * size + j;
    }
  }
  SECTION("find upper left")  {
    REQUIRE(matrixSearch(0, m1));
  }

  SECTION("find upper right") {
    REQUIRE(matrixSearch(99, m1));
  }
}
