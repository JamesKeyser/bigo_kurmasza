
#include <iostream>
#include <vector>

struct Range {
  int low;
  int high;
};

/**
 * Return the begining and ending indices of the maximum subsequence in the vector.
 *
 * + If there are  multiple maxima, then the algorithm may choose which maximum to return.
 * + operator+ must be defined on type T.
 *
 * Remember that the algorithm must run in linear time (i.e., O(n)).
 */
template<typename T>

/**
 *
 * @tparam T
 * @param vec
 * @return Returns struct type Range with low and high being the beginning and ending indices of the highest
 * number value subsequence
 */
Range maxSubsequence(const std::vector<T>& vec) {
    Range answer{answer.low=0,answer.high=0};
    //this has to be set to the lowest value possible, otherwise if we get an input that is lower than "max" starting
    //point, the first comparison wont work
    T max = std::numeric_limits<T>::lowest(), newTotal = 0;
    int low=0;
    if(vec.empty()){
        std::cout << "vector empty";
    }

    for (int i = 0; i < vec.size(); i++ ) {
        newTotal += vec.at(i);

        //This will always run on the first iteration, setting max to vec[0]. After, max is used to track the highest
        //summed sequence of numbers and adjust the range for answer.
        if (max < newTotal) {
            max = newTotal;
            answer.low = low;
            answer.high = i;
        }

        //if newTotal is a negative number here, either the entire sequence has been negative so far, or we hit a
        //negative number greater than the current sequence sum. Reset newTotal to 0 and move the lower bound up 1.
        if (newTotal < 0) {
            newTotal=0;
            low = i+1;
       }


    }

  return answer;
}

