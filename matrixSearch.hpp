#ifndef MATRIX_SEARCH_HPP
#define MATRIX_SEARCH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

// Create an alias to cut down on typing later.
template<typename T>
using Matrix = std::vector<std::vector<T> >;

/**
 * Return whether the given element is in the matrix.
 *
 * The answer should always be "false" when given an empty matrix.
 *
 * Raise an invalid_argument exception if the matrix is not square.
 *
 * You may assume the values in the matrix are in ascending order by row and column.
 * (You need not verify this.)
 *
 * Remember that the algorithm must run in linear time (i.e., O(n)).
 */
template<typename T>
bool matrixSearch(const T& value, const Matrix<T>& vec) {

 bool answer = false;
  // Place your code here.  
  return answer;
}

#endif
