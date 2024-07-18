#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/**
 * Question:: https://leetcode.com/problems/find-k-closest-elements/submissions/
 * 
 * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
 * The result should also be sorted in ascending order.
 * 
 * An integer a is closer to x than an integer b if:
 * 
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 *  
 * 
 * Example 1:
 *  Input: arr = [1,2,3,4,5], k = 4, x = 3
 *  Output: [1,2,3,4]
 * Example 2:
 *  Input: arr = [1,2,3,4,5], k = 4, x = -1
 *  Output: [1,2,3,4]
 * 
 * 
 * Approach:: 
 *  > Find the index of closest element to target in the array that is the absolute difference is the least between the two.
 *  > After getting the index of the closest element. We have 2 pointers left(=closest_index-1) and right(=closest_index+1).
 *      Also, we found 1 element out of k closest elements.
 *  > We then  move the 2 pointers in respective direction and check of the closest element among the 2 depending on the condition
 *      stated above. we are finding the left and right index of the sub-array that contains k-closest elements as 1<=k<=array_size.
 *      This is because once the closest element has been found then we are sure that the remaining k-1 elements will fall in below 3 cases:
 *      Let closest element to target lie at index 'j'. So K closest elements can lie::
 *      a. in the sub-array j-k to j that is completly to the left of closest element.
 *      b. in the sub-array j to j+k that is completly to the right of closest element.
 *      c. in the sub-array j-x to j+y that is in the sub-array starting at j-x index including j and ending at j+y index.
 *  > We keep on check the above condition till we have found all k elements. Here, we store left and right as 2 pointers for start and
 *      end index each of them exclusive. 
 *  > Finally, we return the sub-array from left+1 to right-1 both inclusive.
 * 
 * */

// returns the index of the closest element to target in the array
int findClosest(vector<int> &array, int target){
    
    int n = array.size();
    
    // extreme cases target is smaller than the smallest element 
    // or larger than the largest element
    if(target <= array[0]) return 0;
    if(target >= array[n-1]) return n-1;
    
    int left = 0;
    int right = n-1;
    int mid = -1;
    
    while(left <= right){
        
        mid = left + (right-left)/2;
        
        if(array[mid] == target){
            return mid;
        }
        
        // target is less than element at mid
        if(target < array[mid]){
            
            // if target is greater than element at mid-1
            if(mid>0 && target > array[mid-1]){
                return ( target-array[mid-1] <= array[mid]-target ? mid-1 : mid );
            }
            
            right = mid-1;
        }
        // target is greater than mid
        else{
            // if target is less than element at mid+1
            if(mid < n-1 && target < array[mid+1] ){
                return (target-array[mid] <= array[mid+1]-target ? mid : mid+1 );
            }
            
            left = mid+1;
        }
    }
    
    return mid;
}


vector<int> findClosestElements(vector<int> &array, int k, int target){
    
    int n = array.size();
    
    // find the closest element to target index in array
    int closest_index = findClosest(array, target);
    
    // we found 1 out of k closest elements in the array
    k--;
    
    // initialize 2 pointers left and right
    int left = closest_index -1;
    int right = closest_index +1;
    
    // find the closest element among left and right until either of them bottoms out
    // we are finding the left and right index of the sub-array that contains k-closest elements
    while(k>0 && left >= 0 && right <n){
        
        // if element at left is closer to target than right or if their difference is equal then also
        // select left element.
        if( abs(target-array[left]) <= abs(array[right]-target) ){
            left--;   
        }
        // if element at right is strictly closer to target than element at left
        else{
            right++;
        }
        // after the above checks we will have selected 1 element
        k--;
    }
    
    // if the right has reached the end and we still have to select some more elements
    // then only possible way is to select remaining elements in the left
    while(k>0 && left>=0){
        left--;
        k--;
    }
    
   // if the left has reached the start and we still have to select some more elements
   // then only possible way is to select remaining elements in the right
   while(k>0 && right<n){
        right++;
        k--;
    }
    
    // initialize the vector to return 
    vector<int> closestEl;
    
    // left and right are both exclusive
    for (int i = left+1; i < right; i++) {

        closestEl.push_back(array[i]);
    }
    
    // Finally return the vector
    return closestEl;
}

int main() {
    
    vector<int> array;
    
    int k;
    
    int target;
    
    cin >> target;
    
    cin >> k;
    
    int temp;
    
    while(cin >> temp){
        array.push_back(temp);
    }
    
    vector<int> closestEl = findKClosest(array, k, target);
    
    for (auto i : closestEl) {
        cout<<i<<" ";
    }
    
    // int index = findClosest(array, target);
    // cout<< (index != -1 ? array[index] : -1) <<"\n";
    
	return 0;
}