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

//For Much more clear explation see 1st comment in https://leetcode.com/problems/trapping-rain-water/discuss/17391/Share-my-short-solution.

//O(N) time coplexity and O(1) space complexity
int findTrappedWater(vector<int> array){
    
    int trappedWaterUnits = 0;
    
    //use 2 pointers and keep track of max-left height and max-right height.
    //For a particular building if the height is less than min(max-left, max-right) 
    //then the amount of water it can store is min(max-left, max-right)-height[i]
    
    int left = 0;
    int right = array.size() - 1;
    
    //will give err on [] array if using array[right] or array[left] as base
    int max_right = 0;//array[right];
    int max_left = 0;//array[left];
    
    //in case array.size() is odd, we do want to include the middle index
    while(left <= right ){
        
        //Approach:
        //  If the max height of the building in right side(max_right) > max height of the building in left side(max_left), then 
        //  we know atmost max_left units height of water can be stored on top of this building. Now we keep moving the left pointer to the right.
        //  If at any point max_left>max_right, we move the right pointer to the left until we see a max_right>max_left.
        //  The height of water stored on top of any building will be min(max_left,max_right) - array[i], iff max_left>array[i]<max_right.
        if(max_left < max_right){
            //height of water trapped will be atmost max_left if current building has height less max_left
            //else current building has height greater than max_left so change max_left
            if(array[left] < max_left){
                   trappedWaterUnits += max_left - array[left]; 
            }else{
                max_left = array[left];
            }
            left++;
            
        }else {
            //simillarly for the case when max_left > max_right
            if(array[right] < max_right){
                trappedWaterUnits += max_right - array[right];
            }else{
                max_right = array[right];
            }
            right--;
        }
        
    }

    return trappedWaterUnits;
}


int main() {
	vector<int> array{0,1,0,2,1,0,1,3,2,1,2,1};
	//vector<int> array{4,2,0,3,2,5};
	//vector<int> array{3,2,1,0};
	//vector<int> array{3,2,2,3};
	// vector<int> array{0,1,2,3};
	int trappedWaterUnits = findTrappedWater(array);
	
	cout<<trappedWaterUnits<<"\n"; 
	
	return 0;
}
