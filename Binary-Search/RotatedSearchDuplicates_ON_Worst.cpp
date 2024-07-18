#include <iostream>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * 
 * There is an integer array nums sorted in non-decreasing order (!!not necessarily with distinct values!!).
 * 
 * Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
 * such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
 * 
 * Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
 * 
 * You must decrease the overall operation steps as much as possible. 
 * Example 1:
 *   Input: nums = [2,5,6,0,0,1,2], target = 0
 *   Output: true
 * 
 * Example 2:
 *   Input: nums = [2,5,6,0,0,1,2], target = 3
 *   Output: false
 * 
 * Approach:: Similiar to rotated sorted array search.
 *  > The only modification is that if nums[start] == nums[mid] we cannot claim anything about
 *      the array being sorted at which position. So we decrease the search space by incrementing 
 *      start to 1 index forward as nums[mid] == nums[start].
 * 
 *  > Commented Solution:: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28216/Java-1ms-binary-search-solution-with-comments
 *  > Explation & solution:: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C%2B%2B-solution-(o(logn)-on-average-o(n)-worst-case)
 * 
 *  Time complexity is O(logN) average case and O(N) for worst case. The worst case happens for the Input->[1,1,1,1,1,1,1,3,1]
 *  wherein we check each element once.
 * 
 * */


 bool search(vector<int>& nums, int target) {
    
    int start= 0;
    int end  = nums.size()-1;
    
            
    while( start <= end ){
        int mid = start + (end-start)/2;
        
        if(nums[mid] == target){
            return true;
        }
        
        // mid lies in the left part
        if(nums[start] < nums[mid]){
            // start to mid is sorted
            if( nums[start] <= target && target < nums[mid] ){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        // mid lies in the right part
        else if( nums[mid] < nums[start] ){
            // mid to end is sorted
            if( nums[mid] < target && target <= nums[end] ){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        
        // mid and start are equal. Unsure about the pivot position of the array.
        else{
            start++;
        }
    }
    
    return false;
}

int main() {
	
	vector<int> array;
	
	int target;
	
	cin >> target ;
	
	int temp;
	
	while(cin >> temp){
	    array.push_back(temp);
	}
	
	cout<<search(array, target)<<"\n";
	
	return 0;
}
