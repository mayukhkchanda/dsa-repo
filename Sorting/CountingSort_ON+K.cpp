#include <iostream>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/relative-sort-array/
 * 
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
 * Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  
 * Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
 * Example 1:
 *   INPUT:: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 *   OUTPUT:: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * Approach:: Use counting sort here. https://www.hackerearth.com/practice/algorithms/sorting/counting-sort/tutorial/
 * 
 * 
 * */


vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    
    // initialise elements frequency map for elements in arr1 
    int freq[1001] = {0};
    
    // count the frequencies of elements in  arrayst
    for(int i=0; i<arr1.size() ;i++){
        freq[arr1[i]]++;
    }
    
    vector<int> sortedArray;
    
    // the elements in arr1 need to be sorted according to the elements in arr2.
    // hence we iterate over elements in arr2.
    for(int j=0; j<arr2.size() ;j++){
        
        // put all the elements of arr1 in the new array before moving to the next
        // element in the arr2
        while(freq[arr2[j]]>0){
            sortedArray.push_back(arr2[j]);
            freq[arr2[j]]--;
        }
    }
    
    // if there are remaining elements that are not there in arr1 then
    // put all elements to the end of the array.
    for(int i=0; i<1001 ;i++){
        
        while(freq[i]>0){
            sortedArray.push_back(i);
            freq[i]--;
        }
    }
    
    
    return sortedArray;
}

int main() {
	
	vector<int> array;
	
	int temp;
	
	while(cin >> temp)
	    array.push_back(temp);
	
	vector<int> sortedArray = subArraySorting(array);
	
	for (int i = 0; i < sortedArray.size(); i++) {
	    cout<<sortedArray[i]<<" ";
	}
	
	
	return 0;
}
