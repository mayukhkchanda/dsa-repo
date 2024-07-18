#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/permutations/
 * 
 * Given an array nums of distinct integers, return all the possible permutations. 
 * You can return the answer in any order.
 * Example 1:
 *   Input: nums = [1,2,3]
 *   Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 *   Input: nums = [0,1]
 *   Output: [[0,1],[1,0]]
 * Example 3:
 *   Input: nums = [1]
 *   Output: [[1]]
 * 
 * 
 * Elegant Solution:: https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation
 * 
 * Post on list of Simillar questions::
 *  > https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)
 * 
 * Approach::
 *  
 *  > The key idea here is that for every index i in a permutation we have n-i choice of nums to fill this index in the permutation.
 *      
 *      Let's take the example, [1,2,3]::
 *      
 *      Let us consider that before the program begins we have n(=3) blank spaces::
 *          
 *           _  _  _
 *           ^
 *           +--- we can put 1 or 2 or 3 here. let's say we choose 2. Thus the state of the permutation becomes.
 * 
 *           2  _  _
 *              ^
 *              +--- now we have 1 or 3 as an option to put here. let's say we choose 1. Thus the state becomes.
 * 
 *           2  1  _
 *                 ^
 *                 +--- now we can only put 3 here. so our permutation becomes.
 * 
 *           2  1  3 <-- Thus we constructed 1 permutation out of n! permutations. 
 * 
 *  > Thus we can take a Simillar Approach and call a recursive function to generate all permutations.
 *      When we select an element to fill our index, we swap it with the beginning element in the nums array.
 *      Thus, nums always contains the part of a permutation till index i. When i==n we created the whole 
 *      permutation and can add it to the list of permutations.
 * 
 **/

void genPermutation(vector<int> nums, int begin, int indexToFill, /*vector<int> permutation,*/ vector<vector<int>>& permutations){
    
    int n = nums.size();
  
    // filled all indexes and no number left to fill
    if(indexToFill >= n){
        // push this permutation
        // permutations.push_back(permutation);
        
        // instead of pushing the permutation back, nums contains the generated permutation.
        // This is because we are always swapping the elements towards the beginning.
        permutations.push_back(nums);
        return;
    }
    
    // else there's an empty index to fill
    for (int i=begin; i<n; i++) {
        
        // fill this place with nums[i]
        // permutation[indexToFill] = nums[i];
        
        // erase the filled value from the list of possible values for the next iteration
        swap(nums[i], nums[begin]);
        
        //call get permutations with new index to fill and 1 less option than this index
        genPermutation(nums,begin+1, indexToFill+1, /*permutation,*/ permutations);
        
        //insert this option back into the list of possible options;
        swap(nums[i], nums[begin]);
    }
    
}



vector<vector<int>> permute(vector<int>& nums) {
    
    int n = nums.size();
    
    vector<vector<int>> permutations = {};
    
    vector<int> permutation(n);
    
    genPermutation(nums,0,0,/*permutation,*/permutations);
        
    return permutations;
}


int main() {
	vector<int> nums;
	int temp;
	while(cin >> temp) nums.push_back(temp);
	
    vector<vector<int>> permutations = permute(nums);
	
	cout<< permutations.size()<<"\n";
	
	for (auto p : permutations) {
	    for (auto i : p) {
	        cout<< i <<" ";
	    }
	    cout<<"\n";
	}
	
	return 0;
}
