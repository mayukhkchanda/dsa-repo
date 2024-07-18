#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int partition(vector<int> &array, int start, int end){
    
    // take the last element as the pivot
    int pivot = array[end];
    
    int i=start-1;
    int j=start;
    
    while(j < end){
        
        // if an element is smaller than pivot then swap it with 
        // the element at index i+1
        if(array[j] < pivot){
            ++i;
            swap( array[i], array[j] );
        }
        j++;
    }
    
    //swap i+1 and pivot at last
    ++i;
    swap(array[i], array[end]);
    
    return i;
}

// assuming k is lies withing [0, array_length-1] both inclusive
int quickSelect(vector<int> &array, int start, int end, int k){
    
    // the pivot element after parition is at it's correct position
    int pivot_pos = partition(array, start, end);
    
    // if this pivot_pos is at the kth(0-based indexing) index then return it
    if(pivot_pos == k){ // k is considered as 0-based indexing
        return array[pivot_pos];
    }
    // else if k is smaller than pivot then element lies in the left partition
    else if(k<pivot_pos){
        return quickSelect(array, start, pivot_pos-1, k);
    }
    // else k is bigger than pivot and the element lise in the right partition
    return quickSelect(array, pivot_pos+1, end, k);
    
}

//assuming k is always in range of 1 to array_length
int findKthSmallest(vector<int> &array, int k){// here k is 1-based indexing
    
    return quickSelect(array, 0, array.size()-1, k-1);
    
}


int findKthLargest(vector<int> &array, int k){
    
    int n = array.size();
    // the kth largest from the end is the (n-k+1)th smallest element from the start
    // as we are considering 0-based indexing so we take (n-k)
    int smallest = n-k;// smallest is considering 0-based indexing
    
    return quickSelect(array, 0, array.size()-1, smallest);
    
}



int main() {
	int k;
	cin >> k;
	
	vector<int> array;
	
	int temp;
	
	while(cin >>temp)
	    array.push_back(temp);
	
// 	cout<< findKthSmallest(array, k)<<"\n";

	cout<< findKthLargest(array, k)<<"\n";
	
	return 0;
}
