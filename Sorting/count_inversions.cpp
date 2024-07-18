#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Implement merge sort on an unsorted array
 * 
 * Time complexity is given by the Recurrance Relation:: T(n) = 2T(n/2)+1 
 *  which can be solved by  2nd case of Master Methode is given by:: T(n) = O(n*log(base 2)(n))
 * 
 * */
 
// merges 2 sorted arrays
int merge(vector<int> &array, int left_start, int left_end, int right_start, int right_end){
    
    if(left_end > right_start) return 0;
    
    // copy the left sub-array and right sub-array into 2 separate arrays
    
    int left_subarr[left_end-left_start+2]; 
    int right_subarr[right_end-right_start+2];
    
    int i ;
    
    //sorted left array
    for ( i = left_start; i <= left_end; i++) {
        left_subarr[i-left_start] = array[i];
    }
    
    //last index will have max possible value
    left_subarr[i-left_start] = INT_MAX;
    
    //sorted right array
    for ( i = right_start; i <= right_end; i++) {
        right_subarr[i-right_start] = array[i];
    }
    
    //last index will have max possible value
    right_subarr[i-right_start] = INT_MAX;
    
    int left_ptr = 0;
    int right_ptr = 0;
    
    int k=0;
    
    int inversions = 0;
    
    while(k < right_end-left_start+1){
        
        //if left sub-array has smaller element or equal element, then it's not an inversion
        if(left_subarr[left_ptr] <= right_subarr[right_ptr]){
            array[left_start+k] = left_subarr[left_ptr++];
        }
        
        //only if right sub-array has strict smaller element, then it's an inversion
        else{
            array[left_start+k] = right_subarr[right_ptr++];
            
            // there is an inversion between all elements to the right of left_subarr 
            // starting from left_ptr and the element at right_ptr of right_subarr
            inversions += (left_end-left_ptr+1);
            
        }
        
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
    
    // call mergeSort on left sub-array
    countInv += mergeSort(array, left, mid);
    
    // call mergeSort on right sub-array
    countInv += mergeSort(array, mid+1, right);
    
    // call merge function to join to sorted halves
    countInv += merge(array, left, mid, mid+1, right );
    
    return countInv;
} 


int main() {
    
    vector<int> array;
    
    int temp;
    
    while( cin >> temp ){
        array.push_back(temp);
    }
    
    int countInv = 0; 
    
    cout<< mergeSort(array, 0, array.size()-1);
    
    // for (auto el : array) {
    //     cout<<el<<" ";
    // }
	
	return 0;
}
