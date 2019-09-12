#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <stdexcept>
#include <utility>
using namespace std::rel_ops;

#include "matrixSearch.hpp"

struct TestTriple {
    int a;
    int b;
    double c;

    TestTriple() {
        this->a = -1;
        this->b = -1;
        this->c = -1.0;
    }

    explicit TestTriple(int x) {
        this->a = x;
        this->b = -x;
        this->c = -(double)x;
    }

};

bool operator==(const TestTriple& p1, const TestTriple& p2) {
    return p1.a == p2.a && p1.b == p2.b && p1.c == p2.c;
}

bool operator!=(const TestTriple& p1, const TestTriple& p2) {
    return p1.a != p2.a || p1.b != p2.b || p1.c != p2.c;
}

bool operator<(const TestTriple& p1, const TestTriple& p2) {;
    return p1.a < p2.a;
}

bool operator>(const TestTriple& p1, const TestTriple& p2) {
    return p1.a > p2.a;
}

bool operator<=(const TestTriple& p1, const TestTriple& p2) {
    return p1.a <= p2.a;
}

bool operator>=(const TestTriple& p1, const TestTriple& p2) {
    return p1.a >= p2.a;
}

TEST_CASE("Single element in Matrix") {
Matrix<TestTriple> m1 {{TestTriple(1)}};
bool answer = matrixSearch(TestTriple(1), m1);
REQUIRE(answer);
}

TEST_CASE("Empty Matrix returns false") {
  Matrix<int> m1;
  bool answer = matrixSearch(654, m1);
  REQUIRE(!answer);
}

TEST_CASE("Non-square 'wide' matrix raises exception") {
  Matrix<int> m1 = {{1, 2}};
  REQUIRE_THROWS_AS(matrixSearch(654, m1), std::invalid_argument);
}

TEST_CASE("Non-square 'tall' matrix raises exception") {
Matrix<int> m1 = {{6, 2}};
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


TEST_CASE("corners") {

Matrix<int> m1 = {{1, 2, 3}, {2, 3, 4}, {4, 5, 15}};

    SECTION("top left corner")  {
    REQUIRE(matrixSearch(1, m1));
    }

    SECTION("top right corner") {
    REQUIRE(matrixSearch(3, m1));
    }

    SECTION("bottom left corner") {
    REQUIRE(matrixSearch(4, m1));
    }

    SECTION("bottom right corner") {
    REQUIRE(matrixSearch(15, m1));
    }

}