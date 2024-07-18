#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * Question:: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 * 
 * !!NOTE: This implementation uses a Segement Tree(https://cp-algorithms.com/data_structures/segment_tree.html). 
 *          This is not the optimal implementation which is O(N) in time and space !! 
 *
 * Approach:: Use a segment tree and sliding window.
 *  > Firstly, construct a maximum segment tree for quering maximum value within a range of sub-array. This takes O(logN) time. 
 *  > After this use sliding window to query for maximum value between i to i+k , and store its value in the vector.
 *  > Quering in the segment tree for a range takes O(logN) time.
 * 
 * Time complexity:: O(NlogN) 
 * Space complexity:: O(N)
 * 
 * */


// construct maximum segment tree. Take O(logN) time
void constructSegmentTree(vector<int>& array, int left, int right, int vertexIndex, vector<int>& maxSegTree){
    
    // a safe check
    if(left>right || left<0 || right>array.size()) return;
    
    // if the array has 1 element
    if(left == right){
        maxSegTree[vertexIndex] = array[left];
        return;
    }
    
    // else break the array into 2 parts and calculate the maximum value in each part separetly
    
    int mid = left + (right-left)/2; // avoids overflow
                                
    // call for left child at 2*vertexIndex                            
    constructSegmentTree(array, left, mid, 2*vertexIndex, maxSegTree);
     
    //call for right child at 2*vertexIndex+1
    constructSegmentTree(array, mid+1, right, 2*vertexIndex+1, maxSegTree) ;
    
    maxSegTree[vertexIndex] = max(maxSegTree[2*vertexIndex], maxSegTree[2*vertexIndex+1]);
    
}

// query the segment tree for maximum value for the sub-array queryLeft to queryRight. takes O(logN) for each query
int querySegmentTree(vector<int> &maxSegTree,int vertexIndex, int left, int right, int queryLeft, int queryRight){
    
    // if the query is invalid return INT_MIN
    if(queryLeft>queryRight) return INT_MIN;
    
    // if the query indexes match the current sub-array indexes, then return the value
    if(queryLeft==left && queryRight==right){
        return maxSegTree[vertexIndex];
    }
    
    int mid = left + (right-left)/2;
    
    // else return max in left and right childs
    return  max( querySegmentTree(maxSegTree, 2*vertexIndex, left, mid, queryLeft, min(mid, queryRight)),
                  querySegmentTree(maxSegTree, 2*vertexIndex+1, mid+1, right, max(queryLeft, mid+1), queryRight) );
    
}

vector<int> maxInWindow(vector<int> array,int windowSize){
    
    // construct a maximum segment tree
	vector<int> maxSegTree(4*array.size()+1, 0);
	constructSegmentTree(array, 0, array.size()-1, 1, maxSegTree );

    int queryLeft =0;
    int queryRight = queryLeft+windowSize-1;
    
    int windowSum ;
    
    vector<int> windowSums;
    
    // query the maxSegTree for the maximum in the given window denoted by queryLeft && queryRight
    while(queryRight < array.size()){
        
        windowSum = querySegmentTree(maxSegTree, 1, 0, array.size()-1, queryLeft, queryRight);
        
        windowSums.push_back(windowSum);
        
        // slide the window 
        queryLeft++;
        queryRight++;
    }
    
    return windowSums;
}


int main() {
	
	vector<int> array{1, 2, 3, 1, 4, 5, 2, 3, 6};
	
	//size of segment tree 2^(log(n)+1) < 4*n
// 	vector<int> maxSegTree(4*array.size()+1, 0);
	
// 	constructSegmentTree(array, 0, array.size()-1, 1, maxSegTree );
	
	
// 	for (auto i : maxSegTree) {
//         cout<< i <<" ";
// 	}
	
// 	cout<< querySegmentTree(maxSegTree, 1, 0, array.size()-1, 1, 3 );

    vector<int> windowSums = maxInWindow(array, 3);
    
    for (auto i : windowSums) {
        cout<< i<<" ";
    }
    
	
	return 0;
}
