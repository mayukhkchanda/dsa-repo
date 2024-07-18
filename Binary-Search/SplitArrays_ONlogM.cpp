#include <iostream>
using namespace std;


/**
 * Question:: https://leetcode.com/problems/split-array-largest-sum/
 * 
 * Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
 * Write an algorithm to minimize the largest sum among these m subarrays.
 * Example 1:
 *   Input: nums = [7,2,5,10,8], m = 2
 *   Output: 18
 * Explanation:
 *   There are four ways to split nums into two subarrays.
 *   The best way is to split it into [7,2,5] and [10,8],
 *   where the largest sum among the two subarrays is only 18.
 * Example 2:
 *   Input: nums = [1,4,4], m = 3
 *   Output: 4
 * 
 * !!This question is similar to a series of question discussed in the posts below along with template to solve those question ::
 *   https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794070/PythonC%2B%2B-Binary-search-solution-with-explanation-and-similar-questions
 *   https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *   https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *   https://www.topcoder.com/thrive/articles/Binary%20Search
 *
 * Explained solution:: https://leetcode.com/problems/split-array-largest-sum/discuss/161143/Logical-Thinking-with-Code-Beats-99.89
 * 
 * Approach::
 *  > We can apply binary search here as the function cntSubArraysWithUpperBound is monotonous with respect to upperBound(B).
 *      That is given an array it will return the number of sub-arrays that can be created by taking upperBound(inclusive) as the maximum
 *      sum of each sub-array.
 *  > The post discussed in the link below, provides a general template to solve such questions.
 *      https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *  > The range here is between the largest element in the array(i.e. for the case when each elements is a sub-array) to the sum of all elements in the array
 *      (i.e. for the case when we take all elements of the array into a single array). 
 *  > We perform a lower-bound binary search on this range for the first value that is >= the number of sub-arrays required(m).
 *      For more clarification in lower-bound and upperBound binary search see post -> https://www.topcoder.com/thrive/articles/Binary%20Search
 *      and https://stackoverflow.com/questions/28389065/difference-between-basic-binary-search-for-upper-bound-and-lower-bound 
 *   
 * Time complexity is O(NlogM) where M is the range of values i.e. (sum of all elements - max element) in the array 
 * 
 * */

    
// returns the number of sub-arrays possible to create with mid as upperBound 
// of the sub-array sum
int cntSubArraysWithUpperBound(vector<int> nums, int upperBound){
    
    int subArrayCnt = 0;
    
    int sum = 0;
    
    for (int i : nums) {
        
        // keep including elements in the current sub-array
        sum += i;
        
        // if the sum becomes greater than the said bound, then a new sub-array should start from this element
        // hence increase the subArrayCnt 
        if(sum > upperBound){
            subArrayCnt++;
            sum = i;
        }
    }
    
    // since the elements are positive so after reaching the end of array, we will have 
    // one more sub-array
    subArrayCnt++;
    return subArrayCnt;
}


int splitArray(vector<int> &nums, int m){
    
    // maximum and minimum values that a sub-array can have
    int maxVal = 0;         // sub-array contains all elements that is the sum of all elements
    int minVal = INT_MIN;   // sub-array contains 1 element that is the largest of all element
    
    for (auto i : nums) {
        minVal = max( minVal, i ); 
        maxVal += i;
    }
    
    // here the search space is the sum of sub-array or more precisely the upper bound of the sub-array sum
    // and minVal and maxVal are the 2 extremes 
    
    //this is to make the following code more verbose
    int left = minVal;
    int right = maxVal;
    
    
    while(left < right){
        
        // mid is the upper bound for each of the sub-array sum
        int mid = left + (right-left)/2;
        
        // if the number of sub-arrays that can be created with  mid as upper bound of sub-array sum
        // is more than the required number of elements then we have a better ans than mid to the right of mid
        if( cntSubArraysWithUpperBound( nums, mid ) > m ){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    
    return left;
}



int main() {
	
	int m;
	
	cin >> m;
	
	vector<int> nums;
	
	int temp;
	
	while(cin >> temp){
	    nums.push_back(temp);
	}
	
	cout << splitArray(nums, birds) <<"\n";
	
	return 0;
}
