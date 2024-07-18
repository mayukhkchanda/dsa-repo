#include <iostream>
using namespace std;

/**
 * 
 * Question:: https://www.interviewbit.com/problems/perfect-peak-of-array/
 * 
 * Given an integer array A of size N check that whether there exist a element which is strictly
 * greater than all the elements on left of it and strictly smaller than all the elements on right of it.
 * NOTE: Do not consider the corner elements i.e A[0] and A[N-1] as the answer.
 * 
 * If it exists return 1 else return 0.
 * 
 * Problem Constraints
 * 3 <= N <= 10^5
 * 1 <= A[i] <= 10^9
 * 
 * Example Input
 *   Input 1:
 *   A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
 *   Input 2:
 *   A = [5, 1, 4, 4]
 * Example Output
 *   Output 1:
 *   1
 *   Output 2:
 *   0
 * 
 * Explanation 1:
 *   A[4] = 6 is the element we are looking for.
 *   All elements on left of A[4] are smaller than it and all elements on right are greater.
 * Explanation 2:
 *   No such element exits.
 * 
 * Approach::
 * In a unsorted Array , At any point if we want Max/Min on either side of the element , We should think about using suffix array / prefix array.
 * Now in given problem ,
 *  1. The current element should be greater than all the elements on the left. If we can get the max element till previous index , 
 *      we can compare and conclude . i.e. if (maxLeft[i-1] < a[i]) then the condition passes.
 *  2. Similarly for right side, get the minElem and check if its greater than a[i]. [ minRight[i+1] > a[i] ]
 *     maxLeft - Prefix Array
 *     minRight - Suffix Array
 * */

int perfectPeak(vector<int> &A) {

    int n = A.size();
    
    // maximum element to the left to ith element excluding itself
    vector<int> maxLeft(n, -1);
    
    // minimum element to the right to ith element excluding itself
    vector<int> minRight(n, 1000001);
    
    // compute the maxLeft and minRight for every index from 1 to n-1(both inclusive).
    // Corner elements cannot count as peak elements.
    for(int i=1; i<n-1 ;i++){
        // max element till ith element(except itself) is the maximum so far or 
        // the element at i-1th index. Similarly for min element to the right of
        // index i except itself.
        maxLeft[i] = max( maxLeft[i-1], A[i-1] );
        minRight[n-i-1] = min(minRight[n-i], A[n-i]);
    }

    for(int i=1; i<n-1 ;i++){
        // if there exists any element in A such that it is greater than the maximum element to the left of it
        // and smaller than the minimum element to the right of it. Then we've found peak.
        if(  maxLeft[i]<A[i] && A[i]<minRight[i] ){
            return 1;
        }
    }
    return 0;
}


int main() {
	int temp;
	vector<int> nums;
	while(cin >> temp){
	    nums.push_back(temp);
	}
	
	cout<< perfectPeak(nums)<<"\n";
	
	return 0;
}
