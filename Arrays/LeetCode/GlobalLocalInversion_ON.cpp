#include <iostream>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/global-and-local-inversions
 * 
 * 
 * Explained solution:: 
 *  > https://leetcode.com/problems/global-and-local-inversions/discuss/113644/C%2B%2BJavaPython-Easy-and-Concise-Solution
 * 
 * Approach::
 *  > All local inversions are global inversions.
 *    If the number of global inversions is equal to the number of local inversions,
 *    it means that all global inversions in permutations are local inversions.
 *    It also means that we can not find A[i] > A[j] with i+2<=j.
 *    In other words, max(A[i]) < A[i+2]
 *  > This comment discusses another methode for solving the solution.
 *      https://leetcode.com/problems/global-and-local-inversions/discuss/113644/C++JavaPython-Easy-and-Concise-Solution/114817
 * 
 * */
 
bool isIdealPermutation(vector<int>& nums) {
    
    int max_so_far = -1;
    // for every integer in nums check if it is
    // the maximum so far in the array and if there
    // is an integer at i+2th place that is smaller than this number
    for(int i=0; i<(int)nums.size()-2;i++){
     
        max_so_far = max( max_so_far, nums[i] );
        
        if(max_so_far > nums[i+2]){
            return false;
        }            
    }
    
    return true;
}

int main() {
	vector<int> nums;
	int temp;
	while(cin>>temp) nums.push_back(temp);
	
	cout<< maximumGap(nums) <<"\n";
	
	return 0;
}
