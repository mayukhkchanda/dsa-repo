#include <iostream>
#include <vector>
using namespace std;

// given height(Hi) of n buildings each of width 1 unit 
// find how much water would get trapped when it rains.
// See question: https://leetcode.com/problems/trapping-rain-water/ for clarity

/**
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 In this case, 6 units of rain water (blue section) are being trapped.
*/

/**
 *Approach::
    Use 1st pass to find the highest building to the right for every building(this doesnot includes itself).
    In 2nd pass, start iterating left to right. Calculate the highest building to its left.
    If both the left and right highest buildings have height greater(strict greater) than current building,
    then a column of water will be trapped on top of this building.
*/

//time complexity is O(N) and space complexity is O(N)[as 2 arrays of length N]
int findTrappedWater(vector<int>& array){
    
    //length of highest building in the right side standing at ith building 
    vector<int> highestRight(array.size(), 0);
    //length of highest building in the left side standing at ith building 
    vector<int> highestLeft(array.size(), 0);
    
    int trappedWaterUnits = 0;
    
    //1st pass to find highest building heights in right-side: O(N) time cost
    for( int i= array.size()-2; i>=0;i--){ 
        //highest building height to the right from any building at index i is the 
        //max of the height of builing so far and the building to the right of i
        highestRight[i] = max(highestRight[i+1], array[i+1]);    
    }
    
    //2nd pass to find highest building heights in left-side and calculate trapped water for each building: O(N)
    for (int i = 1; i < array.size(); i++) { 
        //highest building height to the left from any building at index i is the 
        //max of the height of builing so far and the building to the left of i
        highestLeft[i] = max(highestLeft[i-1],array[i-1]);
        
        
        //water will be trapped at the top of this building iff there's a building
        //with greater height than the current building in left and right side
        if(highestLeft[i]>array[i] && array[i]<highestRight[i]){
            // the width of building is always 1, so width of water trapped on top of this building will also be 1
            // the height of water trapped will be min(highestLeft[i],highestRight[i])-array[i] 
            // any extra water would over flow and fall
            trappedWaterUnits += min(highestLeft[i],highestRight[i])-array[i] ;
        }
        
    }
    
    return trappedWaterUnits;
}


int main() {
	vector<int> array{0,1,0,2,1,0,1,3,2,1,2,1};
	int trappedWaterUnits = findTrappedWater(array);
	
	cout<<trappedWaterUnits<<"\n"; 
	
	return 0;
}
