#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Given an integer array nums of length n where all the integers of nums are in the range [1, n] 
 * and each integer appears once or twice, return an array of all the integers that appears twice.
 * You must write an algorithm that runs in O(n) time and uses only constant extra space.
 * 
 * Example 1:
 *   Input: nums = [4,3,2,7,8,2,3,1]
 *   Output: [2,3]
 * 
 * Example 2:
 *   Input: nums = [1,1,2]
 *   Output: [1]
 * 
 * Example 3:
 *   Input: nums = [1]
 *   Output: []
 * 
 * Intuition & Approach:
 * 
 *  > If array(A) has all unique numbers such that 1<=A[A[i]]<=n for all 1<=i<=n then for a mapping function that maps onto the array
 *      itself, that is f(i) = A[i], will produce all unique results. 
 *      >> Let's take the example below,
 *          [3, 4, 2, 1, 5] --> The function f(i) for all i=1 to n will be --> [2, 1, 4, 3, 5](considering 1-based index).
 *          Thus the mapping function produces all unique values.
 *      >> Let's take an array with duplicate values,
 *          [3, 4, 2, 1, 5, 2, 1] --> The function f(i) for all i=1 to n will be --> 
 *              
 *          for i = 1 to n  --->  f(i) = A[A[i]], thus we have
 *          [NOTE:: We'll consider 1-based indices]
 *              f(1) = A[A[1]] = A[3] = 2 
 *              f(2) = A[A[2]] = A[4] = 1
 *              f(3) = A[A[3]] = A[2] = 4 ---+
 *              f(4) = A[A[4]] = A[1] = 3 --+ |---> gives duplicate value, thus we know 2 and 1 is repeated.
 *              f(5) = A[A[5]] = A[5] = 5   | | /^\
 *              f(6) = A[A[6]] = A[2] = 4 --|-+  |
 *              f(7) = A[A[7]] = A[1] = 3 --+  --+
 * 
 *      >> Now, for every A[i] for all i in [1,2,3..,n] we can change the value of the element at index A[i]
 *          to be negative while travesing the indices. If all elements are unique then we will not visit an
 *          negative element 2. And if we do visit a negative element twice then we know that A[i] is repeated.
 * 
 *          !!NOTE:: As array elements are 0-based indexes thus we change the value of the element at (A[i]-1)th index.!!
 * 
 * */

vector<int> findDuplicates(vector<int>& nums) {
    
    int n = nums.size();
    
    vector<int> duplicates;
    
    // iterate over each element 
    for(int i=0; i<n; i++){
        
        // f_i is f'(i) = nums[i], it will serve as index of the element we want to change the value
        // and we take absolute value as this element could have been negatived by some element
        int f_i = abs(nums[i]); 
        
        // as 1<=A[i]<=n and array indices start from 0-based thus we use f'(i)-1 else f'(i)
        // would also have done it.
        if(nums[f_i-1] < 0){
            // as f'(i) produced a duplicate value due to which we are seeing a negative element twice
            // thus we add f'(i) to our return list.
            duplicates.push_back(f_i);
            continue;
        }
        
        nums[f_i-1] *= -1;
        
    }
    
    return duplicates;
}

int main() {
	vector<int> nums;
	int temp;
	while(cin >> temp){
	    nums.push_back(temp);
	}
	cout<< findDuplicates(nums)<<"\n";
	return 0;
}
