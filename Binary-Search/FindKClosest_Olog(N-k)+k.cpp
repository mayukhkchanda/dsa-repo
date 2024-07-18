#include <iostream>
#include <vector>
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
 * The whole solution along all of it's edge cases is explained in the link below :
 * https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
 * 
 * 
 * 
 * */


vector<int> findKClosest(vector<int> &array, int k, int target){
     int left = 0;
    int right = array.size()-k; // the start of the window will alway lie before k elements from the end as 1<=k<=array_size
    
    // stop when 1 element remains this is the starting index of window
    // left and right will point to the window start index
    while(left < right){
        
        int mid = left + (right-left)/2;
        
        // case 1 & 2
        if(target-array[mid] <= array[mid+k]-target){
            right = mid; // mid element is still a potential candidate out of k elements
        }
        // case 3 & 4
        else{
            left = mid+1; // mid < mid+1 so the target-A[mid+1] < target-A[mid]
        }
    }
    
    vector<int> closests;
    
    for (int i = left; i < left+k; i++) {
        closests.push_back(array[i]);
    }
    
    return closests;
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
    
	return 0;
}
