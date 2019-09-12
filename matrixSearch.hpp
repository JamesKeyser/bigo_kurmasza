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

  //Start from the top right of the matrix because to the left is a smaller number, and down is a larger number,
  //starting in any other place would mean we have 2 options for larger/smaller
  int row=0, column=vec.size()-1;

  if(vec.empty()){
      return false;
  }

  if(vec[0].size() != vec.size()){
      throw std::invalid_argument("Matrix not square");
  }

  while(row < vec.size() && column >= 0){
      if(vec[row].at(column) == value){
          return true;
      }
      //if current value is large than the target value, the only place it can be is one column to the left
      if(vec[row].at(column) > value){
          column--;
      }
      //if it is smaller, it can only be one row down
      else{
          row++;
      }
  }

    return false;
}

#endif
