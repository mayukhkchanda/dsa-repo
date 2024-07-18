#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>
using namespace std;

/** 
 * https://leetcode.com/problems/minimum-absolute-difference/
 * Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 
    Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows:
    > a, b are from arr
    > a < b
    > b - a equals to the minimum absolute difference of any two elements in arr
 
    Example 1:
        Input: arr = [4,2,1,3]
        Output: [[1,2],[2,3],[3,4]]
    Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
 * 
 * Approach::
 *  sort the array first. The minimumAbsDifference will occur between 2 adjacent elements in a sorted array.
 *  Iterate from left to right and calculate the minimum absolute difference. If we see an adjacent pari with
 *  same absolute difference we store the pair.
 *  If at any point a pair has absolute difference less than the minimumAbsDifference, we abandon all pairs(clear the vector)
 *  and start storing the pairs with absolute difference equal to new minimumAbsDifference.
 *  
 * Time Complexity -> O(NlogN)+O(N) :: worst case we have the last pair as the minimum absolute difference pair and every 
 *      other pair has the same absolute difference, we would have to clear the vector array and there would be (n-2) pairs to clear.
 *      But this cost of clearing out the vector occurs only once, at the end of the array. Thus the overall complexity remains same.
 * Space Complexity -> O(#min-abs-diff pairs)
 *
 * */

vector<vector<int>> minimumAbsDifference(vector<int>& array){
    
    sort(array.begin(), array.end());
    
    vector<vector<int>> pairs{};
    
    int minAbsDiff = INT_MAX;
    
    for (int i=0; i<array.size()-1 ; i++) {
        
        if( abs(array[i]-array[i+1]) < minAbsDiff ){
            //clear all pairs that matched this absolute difference
            pairs.clear();
            pairs.push_back({array[i], array[i+1]});
            
            minAbsDiff = abs(array[i]-array[i+1]);
            
            continue;
        }
        
        if(abs(array[i]-array[i+1]) == minAbsDiff){
            pairs.push_back({array[i], array[i+1]});
        }
        
    }
    
    return pairs;
}

int main() {
	vector<int> array{3,8,-10,23,19,-4,-14,27};
	
	vector<vector<int>> pairs = minimumAbsDifference(array);
	
	for (auto pair : pairs) {
	    cout<<pair[0]<<" "<<pair[1]<<"\n";
	}
	
	return 0;
}
