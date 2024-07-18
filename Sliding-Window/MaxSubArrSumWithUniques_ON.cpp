#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * 
 * Question:: https://leetcode.com/problems/maximum-erasure-value/
 * 
 * You are given an array of positive integers nums and want to erase a subarray containing unique elements.
 * The score you get by erasing the subarray is equal to the sum of its elements.
 *
 * Return the maximum score you can get by erasing exactly one subarray.
 * 
 * An array b is called to be a subarray of a if it forms a contiguous subsequence of a,
 * that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 * Example 1:
 *      Input: nums = [4,2,4,5,6]
 *      Output: 17
 * 
 * Nice Solution:: https://leetcode.com/problems/maximum-erasure-value/discuss/1235666/PythonJavaC%2B%2B-Sliding-Window-and-HashMap-Clean-and-Concise-O(N)
 * */

int maximumUniqueSubarray(vector<int>& array) {
    
    int i=0; // window start index inclusive
    int j=0; // window end index inclusive
    
    int current_window_sum = 0;
    
    int max_window_sum = -1;// since all positive numbers are there
    
    unordered_map<int,int> numIndxMap;
    
    while(j<array.size()){
        
        //we can include this element either into this current window or 
        //we already started a new window to be able to include this sum
        current_window_sum += array[j];
        
        //if this number exists and if it lies inside the current window then shrink the window
        //till the window start is equal to the next index of last seen index of this character 
        if(numIndxMap.find(array[j])!=numIndxMap.end() ){
            
            //remove the elements before the last repeating number from the current_window_sum 
            //to start a new window. 2nd condition checks if the repeating number lies inside our window 
            while( i < numIndxMap[array[j]]+1 ){
                current_window_sum -= array[i];
                numIndxMap.erase(array[j]);
                i++;
            }
            
        }
        
        //insert/update the last seen index for this number
        numIndxMap[array[j]] = j;
        
        //at every step we decide if the current indexed number i.e. number at j should be include in the
        //current window or do we need to start a new window. so our window is effectively from index i to j both inclusive
        if( max_window_sum < current_window_sum ){
            max_window_sum = current_window_sum;
        }
        j++;
    }
    
    return max_window_sum;
}

int main() {
	
	vector<int> array{4,2,4,5,6};
// 	vector<int> array{5,2,1,2,5,2,1,2,5};
    // vector<int> array{4,2,5,1,2,6};
    //  vector<int> array{1,2,3};
    // vector<int> array{1};
    // vector<int> array{9,7,4,3,2,4,5,6,4,2,9};
    
	cout<<maximumUniqueSubarray(array)<<"\n";
	
	return 0;
}
