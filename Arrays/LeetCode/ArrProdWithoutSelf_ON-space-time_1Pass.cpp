#include <iostream>
#include <vector>
using namespace std;

/*
https://leetcode.com/problems/product-of-array-except-self/
Implement a function that takes in a vector of integers, 
and returns a vector of the same length, where each element 
in the output array is equal to the product of every other 
number in the input array.
  
  Input: nums = [1,2,3,4]
  Output: [24,12,8,6]
*/

//we have 2 iterators starting from 0th index & last index of the array
//as we iterate we store the product of the elements seen till now in left and right respectivly
//we also multiply the productArray elements with left as it moves from left side
//and we multiply the productArray elements with right as it moves from right side
//thus at the end of the nth iteration we have the productArray calculated

vector<int> productArray(vector<int>& array){
    
    //initialize the prodArray with 1's
    vector<int> prodArray(array.size(), 1);
    
    int n = array.size();
    
    int leftProd = 1;
    int rightProd= 1;
    
    //As i increase the leftProd always stores the product of i-1 elements from the left
    //and rightProd always stores the product of n-i-1 elements from the right.
    //Before the leftProd and rightProd are updated, we then multiply prodArray[i] with leftProd
    //and prodArray[n-i-1] with rightProd. !Think about it, it'll make more sense!
    for (int i = 0; i < n; i++) {
        
        //multiply prodArray[i] element(which is 1 initially) with the product of all 
        //elements to the left of this element stored in leftProd
        prodArray[i] *= leftProd;
        
        //multiply prodArray[n-i-1] element(which is 1 initially) with the product of all 
        //elements to the right of this element stored in rightProd
        prodArray[n-1-i] *= rightProd;
        
        //update the leftProd an right product to include this array element too i.e. the ith element
        //as the next element will be i+1 left
        leftProd *= array[i];
        //same for rightProd too
        rightProd *= array[n-1-i];
    }
    
    return prodArray;
}

int main() {
	
	vector<int> array{1,2,3,4,5};
	
	vector<int> prodArray = productArray(array);
	
	for (int i : prodArray) {
	    cout<<i<<" ";
	}
	
	return 0;
}
