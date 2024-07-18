#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
 * 
 * Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.
 * The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
 * 
 * Example 1:
 *   Input: m = 3, n = 3, k = 5
 *   Output: 3
 *   Explanation: The 5th smallest number is 3.
 * Example 2:
 *   Input: m = 2, n = 3, k = 6
 *   Output: 6
 *   Explanation: The 6th smallest number is 6.
 * 
 * 
 * !! This question is similar to a series of question discussed in the posts below::
 *      ->https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *      https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *      https://www.topcoder.com/thrive/articles/Binary%20Search
 * 
 * 
 * Approach::
 *  > we are trying to find a number that is greater than atleast k elements in the multiplication table.
 *  > As this function cntSmaller(gives the number of elements smaller than target in the multiplication table) is monotonous
 *      with respect to target so we can apply binary search here. This is similar to lower bound binary search.
 * 
 * 
 * */



// returns the number of elements smaller than target in the
// multiplication table
int cntSmaller(int rows, int cols, int target){
    
    int count = 0;
    
    // search row by row for the number of elements smaller than target
    // as each row is a multiplication row between ith row and 1 to cols numbers
    // the smallest number than target will be either target/cols or cols(eg::when target=5 and i=1)
    for(int i=1 ; i<=rows ;i++){
        
        int quotient = min(target/i, cols);
        
        // if i==target then we will not find any number smaller than target
        // after this row as i will only increase
        if(quotient == 0){
            break;
        }
        
        count += quotient;
    }
    
    return count;
}

int findKthNumber(int rows, int cols, int k) {
 
    int left = 1;
    int right = rows * cols;
    
    while(left < right){
        
        int mid = left + (right - left)/2;
        
        // cout<<left<<" "<<right<<"->"<<mid<<"="<<cntSmaller(rows, cols, mid)<<"\n";
        
        // let there are z smaller numbers than mid in the multiplication table
        // now if z < k then we are sure that anything less than or equal to mid cannot be
        // the element at kth position
        if(cntSmaller(rows, cols, mid) < k){
            left = mid+1;  
        }else{
            right = mid;
        }
    }
    
    return left;
}


int main() {
	
	int m, n, k;
	
	cin >> m >> n >> k;
	
	cout<< findKthNumber(m, n, k);
	
	
	return 0;
}
