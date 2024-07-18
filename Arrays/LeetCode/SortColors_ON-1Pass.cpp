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
 * Explaination with 2 & 3 colors:: https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/
 * 
 * */

void sortColors(vector<int> &colors){
    
    int low =0;  // sub-array from 0 to low-1 will always be 0's
    int mid =0;  // sub-array from low to mid-1 will be 1's 
    int high=colors.size()-1;// sub-array from high+1 to colors_length will always be 2 & sub-array from mid to high will be unknowns
    
    while(mid <= high){
        
        //if this color is 1 then move forward
        if(colors[mid] == 1){
            mid++;
        }
        
        //else if this color is 0 then put it in the 0 to low-1 sub-array
        else if(colors[mid] == 0){
            swap(colors[low], colors[mid]);
            low++;
            mid++;
        }
        
        // else if this color is 2 then put it in the high+1 to colors_length sub-array
        else {
            swap(colors[mid], colors[high]);
            high--;
        }
    }
}

int main() {
	
	vector<int> colors;
	
	int temp;
	
	while(cin >> temp){
	    colors.push_back(temp);
	}
	
	sortColors(colors);
	
	for (auto i : colors) {
	    cout<< i <<" ";
	}
	
	
	return 0;
}
