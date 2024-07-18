#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Question:: https://www.geeksforgeeks.org/counting-inversions/
 * Count the number of inversions in an array.
 * 
 * Approach:: 
 * 
 *  1. Call merge sort procedure on the array.
 *  2. While during the merge procedure of 2 arrays, if we find an element in left sub-array
 *      such that it is strictly greater than the element in the right sub-array then we know we have found 
 *      inversions pair between all the elements in the left sub-array starting from this element with the 
 *      the element in the right sub-array. Thus number of inversions for this single element in right sub-array
 *      will be (left_end-left_ptr+1) where left_ptr is the index of element that is strictly larger than right sub-array's element
 *      at right_ptr.
 *      
 * 
 * */
 
// merges 2 sorted arrays
int merge(vector<int> &array, int left_start, int left_end, int right_start, int right_end){
    
    if(left_start > right_end) return 0;
    
    vector<int> mergedArray;
    
    int left_ptr = left_start;
    int right_ptr = right_start;
    
    int inversions = 0;
    
    while( left_ptr<=left_end && right_ptr<=right_end ){
        
        //if left sub-array has smaller element or equal element, then it's not an inversion
        if(array[left_ptr] <= array[right_ptr]){
            mergedArray.push_back(array[left_ptr++]);
        }
        
        //only if right sub-array has strict smaller element, then it's an inversion
        else{
            mergedArray.push_back(array[right_ptr++]);
            
            // there is an inversion between all elements to the right of left_subarr 
            // starting from left_ptr and the element at right_ptr of right_subarr
            inversions += (left_end-left_ptr+1);
            
        }

    }
    
    
    while(left_ptr <= left_end){
        mergedArray.push_back(array[left_ptr++]);
    }
    
    while(right_ptr <= right_end){
        mergedArray.push_back(array[right_ptr++]);
    }
    
    int k=0;
    
    for (int i = left_start; i <= right_end; i++) {
        array[i] = mergedArray[k];
        k++;
    }
    
    
    return inversions;
}
 
int mergeSort(vector<int> &array, int left, int right){
    
    // if there is only 1 element then return 
    if( left >= right ){
        return 0;
    }
    
    // avoid overflow of int incase left and right is very large
    int mid = left + (right-left)/2;
    
    int countInv =0 ;
    
    // call mergeSort on left sub-array. returns number of inversions in left sub-array
    countInv += mergeSort(array, left, mid);
    
    // call mergeSort on right sub-array. returns number of inversions in right sub-array
    countInv += mergeSort(array, mid+1, right);
    
    // call merge function to join to sorted halves. returns number of inversions between left and right sub-array
    countInv += merge(array, left, mid, mid+1, right );
    
    //finally return total count of inversions
    return countInv;
} 

int countInversions(vector<int> &array){
    
    return mergeSort(array, 0, array.size()-1)
    
}


int main() {
    
    vector<int> array;
    
    int temp;
    
    while( cin >> temp ){
        array.push_back(temp);
    }
    
    int countInv = 0; 
    
    cout<< countInversions(array, 0, array.size()-1)<<"\n";
    
    for (auto el : array) {
        cout<<el<<" ";
    }
	
	return 0;
}
