#include <iostream>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * 
 * Given the sorted rotated array nums of unique elements, return the minimum element of this array.
 * 
 * You must write an algorithm that runs in O(log n) time.
 *
 * Example 1:
 *   Input: nums = [3,4,5,1,2]
 *   Output: 1
 *   Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 * Example 2:
 *   Input: nums = [11,13,15,17]
 *   Output: 11
 *   Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 * 
 * Approach:: 
 *   > Explained Solution:: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/158940/Beat-100%3A-Very-Simple-(Python)-Very-Detailed-Explanation
 *   > The idea here is to shrink the search space to the single pivot(minimum) element at which point we return the element.
 *   > As the elements are unique, there can be two cases for the element at mid index.
 * 
 *      1. A[mid] > A[end] -> This means the array from start to end has been rotated such that it's order changed and 
 *                            bigger elements wrapperd around. Eg:: [4, 5, 7, 6, 1, 2, 3]. Hence we are sure to find the
 *                            minimum element in the left part of mid that is in the sub-array mid+1 to end.
 * 
 *      2. A[mid] < A[end] -> This means either the rotation didnot change the array order or our search space is an array
 *                            where elements are arranged in ascending order. Eg:: [5, 7, 6, 1, 2, 3, 4]. In the first iteration
 *                            our left->0 | right->6 | mid->3. Thus A[mid](=1) < A[right](=4). Here we cannot discard mid index
 *                            as it can be a candidate for minimum element.
 *      !! Note:: A[mid] == A[end] this case will not arise if the elements are unique !!
 * 
 *   > Discussion by yuhaozhang97:: Using A[left] < A[mid] as the if condition -> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/158940/Beat-100:-Very-Simple-(Python)-Very-Detailed-Explanation/438037
 *   > Another approach:: Uses the idea in the discussion above https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/48493/Compact-and-clean-C%2B%2B-solution
 * */

int findMin(vector<int> &array){
    
    int start = 0;
    int end   = array.size()-1;
    
    // we are finding the pivot element and stop when we have 1 element
    while( start < end ){
        
        int mid = start + (end - start)/2;
        
        // if the array in consideration has been wrapperd around. case 1.
        if( array[mid] > array[end] ){
            start = mid+1;
        }
        
        // if the array in consideration has elements in ascending order. case 2.
        else{
            end = mid;
        }
    }
    
    // finally both start and end point to pivot(minimum) element
    return array[start];
}



int main() {
	
	vector<int> array;
	
	int temp;
	
	while(cin >> temp){
	    array.push_back(temp);
	}
	
	cout<<findMin(array)<<"\n";
	
	return 0;
}

