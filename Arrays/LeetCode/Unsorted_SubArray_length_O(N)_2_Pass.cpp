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

//O(N) time complexity and O(1) space complexity
vector<int>  findUnsortedSubarray(vector<int> &array){
    
    //find minimum element which is out of order 
    //find maximum element which is out of order
    //find the correct positions for these 2 elements.
    //the start of unsorted sub array will be correct position of minimum element
    //the end of unsorted sub array will be correct position of maximum element
    
    //can combine both of the finding minimum/maximum and findind their respective correct positions in one pass of the array for each minimum/maximum
    
    //finding start of the unsorted sub-array
    int start = -1; // we dont know the start
    
    int min_so_far = array[array.size()-1];
    //iterate from right to left on the array
    //track the minimum element seen so far in min_so_far element
    //since the element need to be decreasing from right to left in a sorted array i.e. A[n-1]>A[n-2]>A[n-3]...
    //hence, if some element is out-of-order, that is the element which is like :: A[i]<A[j] where i>j
    //then we can find the correct position(let's say crct_pos) of minimum element 
    //which is out-of-order by finding the left-most element that is bigger than the min_so_far element.
    //since we were tracking the minimum element, and if this element is out-of-order then this crct_pos is the start of the unsorted sub-array
    for (int i = array.size()-2; i>=0 ; i--) { //O(N) time cost
        min_so_far = min(min_so_far, array[i]);
        if(array[i]>min_so_far){
            start = i;
        }
    }
    
    //finding 'end' of the unsorted sub-array
    int end=-1;
    
    int max_so_far = array[0];
    //repeat the process for left to right iteration
    // we are calculating 'end' from the left side because we are trying to find out the position of maximum element that is out of order
    // while also tracking the maximum element seen so far. since the maximum_so_far will lie to the right hand side hence the process
    for(int i=1; i<array.size() ; i++){ //O(N) time cost
        max_so_far = max(max_so_far, array[i]);
        //if an element is out-of-order find the right-most element which is smaller than this max_so_far element
        //that will be the end of unsorted sub-array
        if(max_so_far > array[i]){
            end = i;
        }
    }
    return {start,end};
}

int main() {
	vector<int> array{2,6,4,8,10,9,15};
	//vector<int> array{2,6,4,8,10,1,15};
	//vector<int> array{2,6,15,8,10,9,4};
	
	vector<int> unsorted_indexes = findUnsortedSubarray(array);
	cout<<unsorted_indexes[0]+1<<" "<<unsorted_indexes[1]+1<<"\n"; 
	return 0;
}
