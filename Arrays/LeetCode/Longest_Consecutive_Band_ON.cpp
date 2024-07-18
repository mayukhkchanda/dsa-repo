#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

https://leetcode.com/problems/longest-consecutive-sequence/
*/

//finds the length of longest band in the array->
//insert all elements in an unordered_set 
//start iterating over elements in unordered_set(s[i]) 
//for each element find if s[i]-1 exists and loop till it does, store the left most existing band element
//and also for each element find if s[i]+1 exists and loop till it does, store the right most existing band element
//store the count of # of elements traversed in each side
//calculate the band length when the loop ends
int findLongestBand(vector<int>& array){
    unordered_set<int> lookUpSet;
    
    //insert all array elements for O(1) look-up
    for(int i : array){ // O(N) time cost
        lookUpSet.insert(i);
    }
    
    int maxBandLength = 0;
    //O(N) time complexity //as in each of the while loop we iterate over the elements and keep on deleting them,
    //this ensures that we iterate over each element only once //thus giving an O(N) upper bound
    for(auto itr = lookUpSet.begin(); itr != lookUpSet.end() ;itr++){ 
        
        int el = *itr;
        // find the left most elment of the current band
        while( lookUpSet.find(el-1) != lookUpSet.end() ) { // as this loop runs, we keep on deleting elements from set.

            //lookUpSet.erase(el); // erase is O(d) where d = # of elements to be removed //here d = 1 so T(erase) = O(1)
            el--;
            //in some compilers earsing a non-present element will give Runtime Error//have it after decrement of el            
            lookUpSet.erase(el); // erase is O(d) where d = # of elements to be removed //here d = 1 so T(erase) = O(1)
        }
        //find # of elements in th left band
        int leftSpan = *itr - el;
        
        el = *itr;
        //find the right most element of the current band
        while( lookUpSet.find(el+1) != lookUpSet.end() ) { // as this loop runs, we keep on deleting elements from set.
            el++;
            lookUpSet.erase(el);
        }
        
        //find the # of elements in the right band
        int rightSpan = el - *itr;
        
        maxBandLength = max(maxBandLength, leftSpan+rightSpan+1);
    }
    return maxBandLength;
}


int main() {
	vector<int> array{1,9,3,0,18,5,2,4,10,7,12,6}; 
	cout<<findLongestBand(array)<<"\n";
	return 0;
}
