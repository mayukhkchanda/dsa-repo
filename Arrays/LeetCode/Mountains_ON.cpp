#include <iostream>
#include <vector>
using namespace std;

/**
https://leetcode.com/problems/longest-mountain-in-array/

You may recall that an array arr is a mountain array if and only if:
    > arr.length >= 3
    > There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
        > arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        > arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray, which is a mountain. 
Return 0 if there is no mountain subarray.

Example 1:
    Input: arr = [2,1,4,7,3,2,5]
    Output: 5
    Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Explained Solution:: https://leetcode.com/problems/longest-mountain-in-array/discuss/135593/C%2B%2BJavaPython-1-pass-and-O(1)-space
*/

// Find Length of largest mountain in an array.
// Mountain ->  A[i-2]<A[i-2]<A[i-1]<A[i]>A[i+1]>A[i+2]>A[i+3] //elements must be strictly increaing and then strictly decreasing
// Mountain must contain atleast 3 elements or more.
// Length of mountain means the length starting from a valley(A[i-1]>A[i]<A[i+1]) or start of array
// moving upto a peak(A[i-1]<A[i]>A[i+1]) and going back till a valley(A[i-1]>A[i]<A[i+1]) or end of array

// this is bounded by O(N) time complexity and O(1) in space complexity
// returns an array of left and right dips/valleys(A[i-1]>A[i]<A[i+1]) from the peak index
vector<int> findLeftRightDips(vector<int> &array, int peakIndex){
    
    vector<int> LeftRightDips;
    
    int i = peakIndex;
    // in worst case peak is at (n-2)th index and we traverse back till 1st index
    // so n-2 times
    while( i>0 && array[i] > array[i-1] ){ 
        i--;
    }
    LeftRightDips.push_back(i);
    
    // in worst case peak is at 2nd index and we traverse forward till nth index
    // so n-2 times
    i = peakIndex;
    while( i<array.size()-1 && array[i] > array[i+1] ){
        i++;
    }
    LeftRightDips.push_back(i);
    
    return LeftRightDips;
}

// this is bounded by O(N) in time complexity and O(1) space complexity
int findMountainLength(vector<int> &array){
    
    int maxLength = 0;
    
    for (int i = 1; i < array.size() - 1; i++) {//iterates for N-2 times as 0th element and N-1th element cannot be a peak
    
        //look for a peak
         if(array[i-1] < array[i] && array[i] > array[i+1]){
            //found a peak
            // the call to the function is made only when we found a peak 
            vector<int> dips = findLeftRightDips(array, i); // dips[0] -> left dip/valley // dips[1] -> right dip/valley
            
            //cout<<"peak ->"<<i<<" ";
            
            //(i - dips[0]) is # elements in right side //(dips[1] - i) # elements in left side 
            //1 element is for peak index element itself
            int length =  (i - dips[0]) + 1 + (dips[1] - i);// i -> peak index
            
            //cout<< length<<"\n";
            
            maxLength = max(length, maxLength);
            
            //it doesn't matter to solve for scenerios for elements b/w peak index to right valley 
            //as it is sure we wont find a peak at any of those indexes
            i = dips[1]; //move i to the right valley
            
         }
        
    }
    return maxLength;
}


int main() {
	
	vector<int> array{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4}; //Mountain is 1,2,3,4,5,4,3,2,0
	//vector<int> array{1,2,3,4,5,6,7,8};
	//vector<int> array{8,7,6,5,4,3,2,1,0};
	//vector<int> array{5,6,1};
	cout<<findMountainLength(array);
	return 0;
}
