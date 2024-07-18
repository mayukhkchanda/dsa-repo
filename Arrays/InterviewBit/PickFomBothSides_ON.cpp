#include <iostream>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/pick-from-both-sides/
 * Given an integer array A of size N.
 * 
 * You can pick B elements from either left or right end of the array A to get maximum sum.
 * Find and return this maximum possible sum.
 * NOTE: Suppose B = 4 and array A contains 10 elements then
 * You can pick first four elements or can pick last four elements or can pick 1 from front and
 * 3 from back etc . you need to return the maximum possible sum of elements you can pick.
 * 
 * Example Input
 * Input 1:
 *  A = [5, -2, 3 , 1, 2]
 *  B = 3
 * Input 2:
 *  A = [1, 2]
 *  B = 1
 * Example Output
 * Output 1:
 *  8
 * Output 2:
 *  2
 * 
 * Explanation 1:
 *  Pick element 5 from front and element (1, 2) from back so we get 5 + 1 + 2 = 8
 * Explanation 2:
 *  Pick element 2 from end as this is the maximum we can get
 * 
 * Approach::
 *  > We can either select all B elements from left or from right or some k elements from left
 *      and B-k elements from right.
 *  > Hence, we first compute the sum of B elements from right.
 *  > Then we keep removing 1 elements from this sum from the right and keep adding 1 element from left
 *      unitl we have added B elements from left.
 *  > At each step we store the maximum sum.
 * 
 * */

int solve(vector<int> &A, int B) {

    int n =A.size();

    // if more elements are needed than present in array
    // then it's not possible
    if(B > n){
        return -1;
    }
    
    int right_sum = 0;

    // compute the sum from the end of array for B elements
    for(int i=n-B; i<n ;i++){
        right_sum += A[i];
    }
    
    int left = -1; // iterates from left
    int right = n-B; // iterates Bth element from the right 
    
    int maxSum = right_sum;

    int i =0;

    int left_sum = 0;

    // keep adding elements from left unitl B elements are there.
    // Consecutively keep removing elements from right untill all B elements are removed
    while(i < B){

        left_sum += A[i];
        right_sum -= A[n-B+i];

        maxSum = max(maxSum, left_sum+right_sum);
        i++;
    }
    
    return maxSum;
}



int main() {
	int B;
	cin >> B;
	
	int temp;
	vector<int> A;
	
	while(cin >> temp){
	    A.push_back(temp);
	}
	
	cout<< solve(A, B) ;
	
	
	return 0;
}

