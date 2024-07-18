#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 *  Input: nums = [5,7,7,8,8,10], target = 8
 *  Output: [3,4]
 * 
 * Approach:: Perform binary search on array to find upper and lower bounds.
 * 
 * */

int findBounds(vector<int> &array, int target, string type){
    
    int start = 0;
    int end = array.size()-1;
    
    int bound = -1;
    
    while(start <= end){
        
        int mid = start + (end-start)/2;

        if(array[mid] == target){
            bound = mid;
            
            // for lower bound search in the left part of the array
            if(type == "lower")
                end = mid-1;
            else // type would be upper bound and search in the right part of the array
                start = mid+1;
        }
        
        else if( target < array[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    
    return bound;
}

vector<int> countFrq(vector<int> &array, int target){
    
    int lowerBound = findBounds(array, target, "lower");
    int upperBound = findBounds(array, target, "upper");
    
    
    return {lowerBound, upperBound};   
}


int main() {
	
	vector<int> array;
	
	int temp;
	
	while(cin >> temp){
	    array.push_back(temp);
	}
	
    vector<int> bound = countFrq(array, 2);

    cout<< bound[0]<<" "<<bound[1]<<"\n";

    // cout<< findBounds(array, 4, "upper");
	
	return 0;
}
