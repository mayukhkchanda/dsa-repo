#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/sort-colors/
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
 * objects of the same color are adjacent, with the colors in the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * 
 * You must solve this problem without using the library's sort function.
 * Example 1:
 * INPUT : nums = [2,0,2,1,1,0]
 * OUTPUT: [0,0,1,1,2,2]
 * 
 * 
 * Approach::
 *  1. Given that there are 3 colors i.e. 0, 1 & 2. We have a frequency array for storing count of 0's, 1's & 2's.
 *  2. Then, we iterate for 0 to n-1 and keep putting 0's first then 1's and lastly 2's back in the array.
 * 
 * 
 * */

// sorts an array of 0, 1 and 2 without library sort function
void sortColors(vector<int>& nums) {
    
    // stores the frequency count of 3  colors in the nums array
    int colorFrq[3] = {0};
    
    //calculate the frequency of each color type
    for (int i = 0; i < nums.size(); i++) {
        colorFrq[nums[i]]++;
    }
    
    // used to move the iterator from 1 color to next
    // when all colors of the current iterator are placed
    int color_itr = 0;
    
    // iterate over the array and put the colors in the array
    // in order i.e. first 0 then 1 and lastly 2.
    for (int i = 0; i < nums.size(); ) {
        
        //put all colors of the current color_itr adjacently back in the array
        //and keep on decreasing the frequency count
        while(colorFrq[color_itr] > 0){
            nums[i++] = color_itr;
            colorFrq[color_itr]--;
        }
        
        //after all colors have been placed move the color_itr to the 
        //next color
        color_itr++;
    }
    
}

int main() {
	
	vector<int> array;
	
	int temp;
	
	while(cin >> temp)
	    array.push_back(temp);
	    
	sortColors(array);
	
	for (auto i : array) {
	    cout << i<<" ";
	}
	
	return 0;
}
