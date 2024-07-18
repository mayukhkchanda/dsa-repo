#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an integer array nums, you need to find one continuous subarray
 * such that if you only sort this subarray in ascending order, then the whole 
 * array will be sorted in ascending order.
 * Input: nums = [2,6,4,8,10,9,15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 * 
 * Question-> https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * 
 * Explained Solution -> https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/1082404/C%2B%2B-or-Two-Approaches-(2Pass-greater-1Pass)-or-O(n)-Beats-100-or-No-Extra-Space-or-Explanation
 */


vector<int>  findUnsortedSubarray(vector<int> &array){
    
     int unfit_el;
    
    int left_unsorted_index = array.size(); //as left_unsorted_index will always be the minimum
    int right_unsorted_index = -1; 
        
    bool isSorted = true; //is the array sorted 
    
    // iterate from start and find the element which is out-of-order(i.e. the element which is smaller than the previous element)
    // for this unfit_element see how far it has come to be out-of-order in right hand side(i.e. till which index unfit_el > array[i+1]) 
    // the start-index will always be minimum index and end index will always be the maximum index
    for (int i = 0; i < array.size()-1 ; i++) { //this has a complexity of O(N) //we touch each element only once as even in while loop-
                                                //- we directly increment i
        
        if( !(array[i]<=array[i+1]) ){
            isSorted = false;
            unfit_el = array[i];
            left_unsorted_index = min(left_unsorted_index, i);
            //see how far the unfit element has come to the left
            while(i<array.size()-1 && unfit_el > array[i+1]){
                i++;
                right_unsorted_index = max(right_unsorted_index, i);
            }
        }
        
    }
    
    // simillarly do form right hand side
    for (int i = array.size()-1; i > 0 ; i--) {
        
        if( !(array[i-1]<=array[i]) ){
             isSorted = false;
            unfit_el = array[i];
            right_unsorted_index = max(right_unsorted_index, i);
            //see how far the unfit element has come to the right
            while(i>0 && unfit_el < array[i-1]){
                i--;
                left_unsorted_index = min(left_unsorted_index, i);
            }
        }
        
    }
    
    //return isSorted ? 0 : (right_unsorted_index-left_unsorted_index+1);
    
    vector<int> unsorted_indexes{left_unsorted_index, right_unsorted_index};
    return isSorted ? {} : unsorted_indexes;
    
}

int main() {
	//vector<int> array{2,6,4,8,10,9,15};
	//vector<int> array{2,6,4,8,10,1,15};
	vector<int> array{2,6,15,8,10,9,4};
	
	vector<int> unsorted_indexes = findUnsortedSubarray(array);
	cout<<unsorted_indexes[0]+1<<" "<<unsorted_indexes[1]+1<<"\n"; 
	return 0;
}
