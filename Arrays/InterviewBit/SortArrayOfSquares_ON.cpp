#include <iostream>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/squares-of-a-sorted-array/
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 * Example 1:
 *   Input: nums = [-4,-1,0,3,10]
 *   Output: [0,1,9,16,100]
 *   Explanation: After squaring, the array becomes [16,1,0,9,100].
 *   After sorting, it becomes [0,1,9,16,100].
 * Example 2:
 *   Input: nums = [-7,-3,2,3,11]
 *   Output: [4,9,9,49,121]
 * 
 * Elegant self-explained solution::https://leetcode.com/problems/squares-of-a-sorted-array/discuss/221922/Java-two-pointers-O(N)
 * 
 * 
 * */



/**
 * 
 * In the first method, we compute the squares of negative and non-negative elements separetly
 * and store them in an array. Then we call the merge function to merge the left and right part.
 * This merge function is the same as the merge function of Quick sort, that is we put the smaller 
 * elements of the two first. 
 * 
 * 
// void merge(vector<int>& nums, vector<int>& left, vector<int>& right){
//     int n = nums.size();
    
//     int i=0;
    
//     int left_itr = 0;
//     int right_itr = 0;
    
//     while( i<n ){
        
//         if(left[left_itr] < right[right_itr]){
//             nums[i] = left[left_itr];
//             left_itr++;
//         }else{
//             nums[i] = right[right_itr];
//             right_itr++;
//         }
//         i++;
//     }
    
// }

// vector<int> sortedSquares(vector<int>& nums) {

//     int n = nums.size();

//     vector<int> left;
//     vector<int> right;

//     for(int i=0; i<n ;i++){

//         int sqr = nums[i]*nums[i];

//         if(nums[i] < 0){
//             left.push_back( sqr );
//         }else{
//             right.push_back( sqr );
//         }
//     }
//     reverse(left.begin(), left.end());
//     left.push_back(INT_MAX);

//     right.push_back(INT_MAX);

//     merge(nums, left, right);
//     return nums;
// }
*/  

/**
 * In the second method we use the concept of 2 pointers. 
 * > We first find the index of the first non-negative element in the array(in case all elements are negative 
 *     it will be n i.e. the size of the array). This index is our right index. The index before right = right-1 is our left index
 * 
 * > We then advance the 2 pointers in each direction and compare the squares of these elements 
 *     and put the smaller elements first in the sorted array. If either of the pointers reaches the
 *     end, we start pushing the remaining elements of the other side in the sorted array. 
 * 
 *     Note:: As the array is in non-decreasing fashion,  thus if left exhausts then all the elements in the right part(i.e. the non-negative
 *              part will be place in the same order). While if the right part exhausts then all elements in the left part i.e. the negative
 *              part will be place in the opposite order.
 * 
 *              For example, If we have:
 *                  
 *                  [-5, -4, -3, -1, 0]  
 *                                ^  ^ 
 *                                l  r         // l --> left && r --> right
 * 
 *                  After 1 iteration r goes out of array and thus all the left part elements will be placed without comparision.
 *                  Thus, we place elements as in order from l to 0(reason's pretty intuitive) as they are arranged in non-decreasing fashion.
 *                  Simillar argument plays for an array [-1, 0, 2, 4, 6, 7] where left = 0 & right = 1 at the start of the iteration.
 * 
 * 
 *      Time Complexity --> O(logN) for finding first non-negative and O(N) for comparision and push_back 
 *      Space Complexity --> O(N) for storing the squares of the elements in sorted form afte comparision.
 * 
 * 

// returns the index of first non-negative number in the array.
// if all elements are negative, then returns the size of the array.
int findFirstNonNegative(vector<int> &nums){
    int n = nums.size();
    
    int left = 0;
    int right = n; // in case all elements are negative
    
    while(left < right){
        
        int mid = left + (right-left)/2;
        
        if(nums[mid] < 0){
            left = left+1;
        }else{
            right = mid;
        }     
    }
    
    return left;
}

// square and sort the array.
vector<int> sortedSquares(vector<int>& nums) {
    
    int n = nums.size();
    
    // first non-negative element will be our right pointer and the index before it 
    // will be out left pointer.
    int right = findFirstNonNegative(nums);
    int left = right-1;
    
    // store the new sorted array
    vector<int> sortedArr;
    
    // while either of the part exhausts itself
    while( left >= 0 && right<n ){
        
        
        int leftSqr = nums[left]*nums[left];
        int rightSqr = nums[right]* nums[right];
        
        // compare and store the smaller squared value of the left and right element
        if( leftSqr < rightSqr){
            sortedArr.push_back(leftSqr);
            left--;
        }else{
            sortedArr.push_back(rightSqr);
            right++;
        }
    }
    
    //if elements in left part remain put their squares in the same order
    //as elements are arranged in non-decreasing fashion
    while( left >= 0 ){
        sortedArr.push_back(nums[left]*nums[left]);
        left--;
    }
    
    //if elements in right part remain put their squares in the same order
    //as elements are arranged in non-decreasing fashion
    while(right<n ){
        sortedArr.push_back(nums[right]* nums[right]);
        right++;
    }
    
    return sortedArr;
}
 
*/
  vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        int left =0;
        int right=n-1;
        
        vector<int> sorted(n, 0);
        
        for(int i=n-1; i>=0 ;i--){
            
            if(abs(nums[left]) > abs(nums[right])){
                sorted[i] = nums[left]*nums[left];
                left++;
            }else{
                sorted[i] = nums[right]*nums[right];
                right--;
            }
        }
        return sorted;
    }   
    


int main() {
	vector<int> nums;
	int temp;
	while(cin >> temp){
	    nums.push_back(temp);
	}
	cout<< sortedSquares"\n";
	return 0;
}