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

//finds the length of longest band in the array
//insert all elements in an unordered_set 
//start iterating over elements in unordered_set(s[i]) 
//for each element in unordered_set->s[i] check if s[i]-1 exists
//if not exists then this element s[i] can start a band i.e. if it's parent(s[i]-1) is not present then this s[i] element can start a band
//now traverse through the band(s[i]+1) while the next element s[i]+1 exists and keep on increasing the 
//band length. finally calculate max band length of them all.

//O(N) time complexity in worst case and O(N) space complexity 
// Explanation of time complexity see the comment in the link and replies to it -> 
// https://leetcode.com/problems/longest-consecutive-sequence/discuss/41057/Simple-O(n)-with-Explanation-Just-walk-each-streak/39139
int findLongestBand(vector<int> array){
    unordered_set<int> lookUpSet;
    
    //insert all array elements for O(1) look-up
    for(int i : array){ //O(N) in time complexity
        lookUpSet.insert(i);
    }
    
    int maxBandLength = 0;
    
    //O(N) time complexity //as we start walking the elements only when the parent does not exist.
    //We spend some cost x(=c*length of the chain) on each while iteration.
    //As the each of the band has to have only one parent and the longest band can at max be array_length.
    //so in the wrost case we will still spend O(1)+O(1)+O(1)+O(1)+O(1)...+O(n-1).O(1)[at some index k]+O(1)+O(1)+O(1)...upto n-terms.
    //the O(1)'s are for when checking for an element whose parent exists 
    //and kth element is the element whose parent doesnot exist which is when we spend n-1 iterations
    //thus this function is bounded by O(N) in wrost case
    for(int i=0; i<array.size() ;i++ ){ 
        
        // if array[i] - 1 doesnot exists then, array[i] can start a new band
        if( lookUpSet.find(array[i] - 1) == lookUpSet.end() ){ 
            //check the consecutive elements in increasing direction exists 
            // and if so keep walking(increasing +1 to the value) till the element requested doesnot exists 
            int walker = array[i];
            while( lookUpSet.find(walker + 1 ) != lookUpSet.end() ){
                walker++;
            }
            maxBandLength = max(maxBandLength, walker - array[i]+1);
        }
        
    }
    
    return maxBandLength;
}


int main() {
	//vector<int> array{1,9,3,0,18,5,2,4,10,7,12,6};
	//vector<int> array{1,9,0,3,3,18,5,2,4,10,7,12,6,3};
	vector<int> array{1,3,5,7,0};
	cout<<findLongestBand(array)<<"\n";
	return 0;
}
