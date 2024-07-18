#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/** 
 * Question:: https://leetcode.com/problems/continuous-subarray-sum/
 * Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements 
 * sum up to a multiple of k, or false otherwise.
 * An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
    Example 1:
        Input: nums = [23,2,4,6,7], k = 6
        Output: true
        Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
 * 
 *  Resources::
 *      1.Math behind the solution: https://leetcode.com/problems/continuous-subarray-sum/discuss/150330/Math-behind-the-solutions
 *      2.A nice Approach(check the comments too) :https://leetcode.com/problems/continuous-subarray-sum/discuss/99499/Java-O(n)-time-O(k)-space
 * 
 * Approach:: Using prefix sums and hashmap to find sub-array sums divisible target.
 * 
 *  > Math behind the solution :
 *      Let Prefix sum till index i be PS(i).
 *      As we are looking for sub-array sum so we know it will be = PS(j) - PS(i)= sum of sub-array 
 *      between indexes i+1 to j both inclusive for some -1<i<j<n. 
 *      Now this sum must be divisible by target i.e. (PS(j) - PS(i))%target == 0.
 *      As modulus is distributive(https://www.geeksforgeeks.org/modulo-1097-1000000007/) i.e. 
 *      ( a + b) % c = ( ( a % c ) + ( b % c ) ) % c. Thus (PS(j) - PS(i))%target=0 => (PS(j)%target - PS(i)%target)%target =0 
 *      Thus a sub-array from i+1 to j is present whose sum is divisible by target only if PS(j)%target == PS(i)%target
 *      This is the condition we check for we at each index if false we put the current prefix_sum%target in the hashmap and move on.
 * 
 *  Few corner cases:
 *      If target==1 then all sub-array sums are multiple of 1.
 *      If target==0, then we check for atleast 2 consecutive 0's as all the array elements are positive.
 *      If array.length <=1 then it's not possible as Question asks us to find a sub-array with atleast 2 elements.
 * 
 *  Time & Space complexity is O(N)
 * 
 * */

// find a given target in a container between the sub-array start to end
auto find(auto start, auto end, int target){
    while(start != end){
        if(*start == target) return start;
        start++;
    }
    
    return end;
}


bool checkSubarraySum(vector<int>& array, int target) {
    
    //Question asks us to find atleast 2 elements
    if(array.size() <= 1) return false;
    
    //if target is 0 and since 0 <= array[i] <= 10^9, so there must
    //exists a 0 in the array at any index and the left or right element of that
    //index must also be a 0
    if(target==0){
        auto itr= find(array.begin(), array.end(), target);
        //no 0's exists
        if(itr == array.end()) return false;
        return *(itr+1) == 0 || *(itr-1) ==0;
    }
    
    //since 1 divides every number so, if array.size() > 1 then we will have 
    //a sub array that is a multiple of 1
    if(target==1) return true;
    
    //hashmap to store the modulo and indexes
    unordered_map<int,int> moduloMap;
    
    int prefixSum = 0;
    
    //if the prefixSum from start to any index itself is divisible by target then we
    //will be looking for a 0 modulo.
    moduloMap.insert({0,-1});
    
    //iterate over every array index and calculate the prefixSum at that index
    for (int i = 0; i < array.size(); i++) {
        
        prefixSum+=array[i];
        
        //if modulo repeats then a we found a sub-array whose sum is divisible by target,
        //based on the math discussed above
        if( moduloMap.find(prefixSum%target) != moduloMap.end() ){
            
            //if the sub-array has more than 2 elements. Here i is inclusive
            //and moduloMap.at(prefixSum%target) index is exclusive
            if(i-moduloMap.at(prefixSum%target) >= 2)
                return true;
        }
        
        //if the modulo is not present then push the modulo with the index
        moduloMap.insert({prefixSum%target, i});
    }
    
    //if the above condition did not meet then we are sure that no sub-array exists
    return false;
}

int main() {
	
// 	vector<int> array{23,2,6,4,7};
// 	int target=6;
	
// 	vector<int> array{23,2,4,6,6};
//     int target =7;
    
    // vector<int> array{23,2,4,0,6,0,6};
    // int target =0;
	
	cout<<checkSubarraySum(array, target)<<"\n";
	
	return 0;
}
