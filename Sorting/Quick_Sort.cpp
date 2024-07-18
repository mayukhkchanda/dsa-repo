#include <iostream>
#include <vector>
using namespace std;

/**
 * Implement Quick Sort.
 * Average case time complexity is O(NlogN) and worst case time complexity is O(N^2)
 * -in case the array is reverse sorted
 * */


// partition the array into 2 parts left part contains elements
// lesser than or equal to pivot and right part contains elements greater than pivot 
// and returns the correct position of the pivot after partition
int partition(vector<int> &array, int start, int end){
    
    // take the last element as the pivot
    int pivot = array[end];
    
    int i= start-1; // left pointer moves only when an element is smaller than pivot
    int j= start; // iterates over the array from start to end-1
    
    // iterate till (pivot-1)th index
    while(j < end){
        
        // if this element is lesser than or equal to pivot then put it in the left part of the array
        // by swapping it with the current pointer to the left part i
        if(array[j] <= pivot){
            ++i;
            swap(array[i],array[j]);
        }
        // else if the element is strictly greater than the pivot do nothing
        
        j++;
    }    
    
    // finally swap the pivot with the (i+1)th position
    swap( array[++i], array[end] );
    
    //return the correct place of the pivot
    return i;
}


void quickSort(vector<int> &array, int start, int end){
    
    //base case
    if(start >= end) return;
    
    // partition the array into 2 parts and get the pivot's position after
    // placing it in the correct index 
    int pivot_pos = partition(array, start, end);
    
    //call quickSort on left part of pivot excluding pivot
    quickSort(array, start, pivot_pos-1);
    
    //call quickSort on right part of pivot excluding pivot
    quickSort(array, pivot_pos+1, end);
    
    
}


int main() {
	
	vector<int> array;
	
	int temp;
	
	while(cin >> temp)
	    array.push_back(temp);
	    
	quickSort(array, 0, array.size()-1);

    // partition(array, 0, 1);
	
	for (auto i : array) {
	    cout << i<<" ";
	}
	
	return 0;
}
