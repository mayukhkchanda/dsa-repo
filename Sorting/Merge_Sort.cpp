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
void merge(vector<int> &array, int left_start, int left_end, int right_start, int right_end){
    
    if(left_end > right_start) return;
    
    // copy the left sub-array and right sub-array into 2 separate arrays
    
    int left_subarr[left_end-left_start+2]; 
    int right_subarr[right_end-right_start+2];
    
    int i ;
    
    for ( i = left_start; i <= left_end; i++) {
        left_subarr[i-left_start] = array[i];
    }
    
    //last index will have max possible value
    left_subarr[i-left_start] = INT_MAX;
    
    for ( i = right_start; i <= right_end; i++) {
        right_subarr[i-right_start] = array[i];
    }
    
    //last index will have max possible value
    right_subarr[i-right_start] = INT_MAX;
    
    int left_ptr = 0;
    int right_ptr = 0;
    
    int k=0;
    
    while(k < right_end-left_start+1){
        array[left_start+k] = left_subarr[left_ptr] < right_subarr[right_ptr] ? left_subarr[left_ptr++] : right_subarr[right_ptr++];
        k++;
    }

}
 
void mergeSort(vector<int> &array, int left, int right){
    
    // if there is only 1 element then return 
    if( left >= right ){
        return;
    }
    
    // avoid overflow of int incase left and right is very large
    int mid = left + (right-left)/2;
    
    // call mergeSort on left sub-array
    mergeSort(array, left, mid);
    
    // call mergeSort on right sub-array
    mergeSort(array, mid+1, right);
    
    // call merge function to join to sorted halves
    merge(array, left, mid, mid+1, right);
    
} 


int main() {
    
    vector<int> array;
    
    int temp;
    
    while( cin >> temp ){
        array.push_back(temp);
    }
    
    mergeSort(array, 0, array.size()-1);
    
    for (auto el : array) {
        cout<<el<<" ";
    }
	
	return 0;
}
