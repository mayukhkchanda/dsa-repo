#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * 
 * Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
 * You must decrease the overall operation steps as much as possible.
 * 
 * Example 1:
 *   Input: nums = [1,3,5]
 *   Output: 1
 * Example 2:
 *   Input: nums = [2,2,2,0,1]
 *   Output: 0
 * Example 3:
 *   Input: nums = [10,1,10,10,10]
 *   Output: 0
 * 
 * Approach:: This problem is simillar to https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ with the constraint being that elements can be duplicate
 * 
 *   > We expand on the idea discussed in the link below to handle the case where A[mid] == A[end]
 *      https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/158940/Beat-100%3A-Very-Simple-(Python)-Very-Detailed-Explanation
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
 * 
 *      3. A[mid] == A[end]-> We cannot make any solid guess about the array in consideration. Hence we decrease the search space
 *                            by decreasing end to end-1.
 *      
 *      Because of the third case, the worst case time complexity becomes O(N) with average being O(logN). Worst case input example:: [1 ,1 ,1 ,1 ,1 ,1]
 * 
 *   > Discussion:: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/48808/My-pretty-simple-code-to-solve-it/48840
 *   > Explained with invarient:: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/167981/Beats-100-Binary-Search-with-Explanations
 * */

int findMin(vector<int> &array){
    
    int left = 0;
    int right   = array.size()-1;
    
    // at the last iteration left and right will point to minimum or pivot element   
    while( left < right ){
        
        int mid = left + (right-left)/2;
        
        // elements are wrapped around and hence pivot lies to the right of mid
        if( array[mid] > array[right] ){
            
            left = mid+1;
        }
        
        // elements in the current array(or sub-array) of consideration(start to end) are sorted in ascending order
        // hence mid can be a candidate for minimum element or pivot.
        else if(array[mid] < array[right]){
            
            right = mid;
        }
        
        // else mid and end elements are equal and we cannot make any solid guess about the array(or sub-array) in consideration.
        else{
            right--;    
        }
    }
    
    return array[left];
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
