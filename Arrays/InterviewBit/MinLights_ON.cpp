#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/minimum-lights-to-activate/
 * 
 * Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.
 * All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1]. Initially all lights are off.
 * Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.
 * 
 * Example Input
 * Input 1:
 *  A = [ 0, 0, 1, 1, 1, 0, 0, 1].
 *  B = 3
 * Input 2:
 *  A = [ 0, 0, 0, 1, 0].
 *  B = 3
 * 
 * Example Output
 * Output 1:
 *  2
 * Output 2:
 *  -1
 * 
 * Example Explanation
 * Explanation 1:
 * In the first configuration, Turn on the lights at 3rd and 8th index.
 * Light at 3rd index covers from [ 1, 5] and light at 8th index covers [ 6, 8].
 * Explanation 2:
 * 
 * In the second configuration, there is no light which can light the first corridor.
 * 
 * Approach::
 *  > start at index 0. Check range i-range+1 to i+range-1 and try to find the left-most lightbulb.
 *  > If it exists then increment the count by 1. And now start iterating from i+range index and check perform the above check.
 *  > If a lightbulb doesnot exist within that range then, we cannot light the whole corridor so return -1.
 * 
 * 
 * */


int minLights(vector<bool> &array, int range){
    
    // last index
    int n = array.size();
    
    int i =0;
    int count = 0;
    
    while( i<n ){
        
        // index of left-most lightbulb
        int index = -1;
        
        // check the right-side range from i i.e. i+range-1 for a working lightbulb
        // and also the left-side range from i i.e. i-range+1 for a working lightbulb
        // store the index of right most working lightbulb. If not present then 
        // return -1 as the whole corridor cannot be lit-up
        for (int j = max(0, i-range+1); j < min(n, i+range); j++) {
            index = array[j] ? j : index; 
        }
        
        if(index == -1) return -1;
        
        count++;
        // for the next iteration start after the (index of left-most lightbulb + range of a bulb)
        // as all the halls within this range will be light up due to the lightbulb turned on at index
        i = index+range;
    }
    return count;
}

int main() {
	
	vector<bool> array;
	
	int range;
	
	cin >> range;
	
	int temp;
	
	while(cin >> temp){
	   array.push_back(temp);
	}
	
	cout << minLights(array, range) <<"\n";
	
	return 0;
}
