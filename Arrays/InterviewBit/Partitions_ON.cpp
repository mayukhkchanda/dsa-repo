#include <iostream>
using namespace std;


/**
 * Question:: https://www.interviewbit.com/problems/partitions/
 * 
 * You are given a 1D integer array B containing A integers.
 * Count the number of ways to split all the elements of the array into 3 
 * contiguous parts so that the sum of elements in each part is the same.
 * Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n]) 
 * 
 * Example Input
 *   Input 1:
 *    A = 5; B = [1, 2, 3, 0, 3]
 *   Input 2:
 *    A = 4; B = [0, 1, -1, 0]
 * Example Output
 *   Output 1:
 *    2
 *   Output 2:
 *    1
 * 
 * Explanation 1:
 *   There are no 2 ways to make partitions -
 *   1. (1,2)+(3)+(0,3).
 *   2. (1,2)+(3,0)+(3).
 * Explanation 2:
 *   There is only 1 way to make partition -
 *   1. (0)+(-1,1)+(0).
 * 
 * Approach::
 * 
 * Discussion on the problem(see 1st comment for hints):: https://discuss.interviewbit.com/t/can-any-explain-me-the-solution/44381
 * 
 * 
 * > O(NlogN) :
 *   If the sum of all the elements of the array is not divisible by 3 return 0. Else it is obvious that
 *   the sum of each part of each contiguous part will be equal to the sum of all elements divided by 3.
 *   
 *     1) Create an array of the same size as a given array whose i-th index holds the value of the sum of 
 *        elements from indices 0 to i of the given array. Let’s call it prefix array.
 *     
 *     2) Create another array of the same size as a given array whose i-th index the value of sum of elements
 *        from indices i to A-1 of the given array. Let’s call it suffix array.
 *     
 *     3) The idea is simple, we start traversing the prefix array and suppose at the i-th index of the prefix
 *        array the value of prefix array is equal to (sum of all elements of given array)/3.
 *     
 *     4) For i found in the above step we look into the suffix array from (i+2)-th index and wherever the value
 *        of suffix array is equal to (sum of all elements of given array)/3, we increase the counter variable by 1.
 * 
 *  NOTE:: Here we start searching for sum/3 in suffix array from i+2 as we are looking for the 3 part. Thus there
 *          needs to be atleast 1 element between 1st and 3rd part which can be the 2nd part. How are we so sure that
 *          this 2nd part will be sum/3 ? As we have already check that the sum of all elements is divisible by 3,
 *          hence if 2 parts are equal to 1/3 of the sum then the remaining part must be also equal to 1/3 of the total 
 *          sum for the total sum to be divisible by 3.
 * 
 * > O(N) :
 *    >> Efficient Approach [ O(A) solution ] :
 *      >>> If sum of all the elements of the array is not divisible by 3, return 0.
 * 
 *      >>> It is obvious that the sum of each part of each contiguous part will be equal 
 *          to the sum of all elements divided by 3.
 * 
 *      >>> Let’s create an array cnt[ ], where cnt[ i ] equals 1, if the sum of elements from
 *          ith to Ath equals Array_Sum/3 else 0. Now, calculate the cumulative sum of the cnt array from the last index.
 * 
 *      >>> Thus, we receive very simple solution: for each prefix of initial array 1…i with the sum that 
 *          equals Array_Sum/3 we need to add to the answer sums[ i+2 ].
 * 
 * 
 *  
 * */

// returns the count of elements in arr begining from start index(inclusive)
// that are equal to target.
int countElements(vector<int> arr, int start, int target){
    int n= arr.size();
    int count = 0;
    for(int i=start; i<n ;i++){
        if(arr[i] == target){
            count++;
        }
    }
    return count;
}

int numWaysToPartition(int A, vector<int> &B) {

    int sum_left = 0; // stores the sum of elements from left
    int sum_right = 0; // stores the sum of elements from right

    vector<int> prefix_sum(A);
    // vector<int> suffix_sum(A);
    
    // compute the prefix array
    for(int i=0; i<A ;i++){
        sum_left += B[i];
        // sum_right += B[A-i-1];

        prefix_sum[i] = sum_left;
        // suffix_sum[A-i-1] = sum_right;
    }
    
    // if the total sum is not divisible by 3 then it's not possible
    // to divide the array into 3 parts of equal sum
    if(sum_left % 3 != 0){
        return 0;
    }
    
    // if total sum is divisible by 3 then each part must have 1/3rd of the total sum
    int part_sum = sum_left/3; // sum of each part
    
    // calculate the count of 1 from right to left when the suffix_sum becomes 
    // becomes equal to each part_sum
    vector<int> cumulativeSumOfSuffixCounts(A+1, 0);

    for(int i=A-1; i>=0 ;i--){
        // compute the suffix_sum
        sum_right += B[i];
        
        // if this suffix_sum equals part_sum then consider it as 1
        int count = sum_right == part_sum ? 1 : 0;
        
        // compute the sum of all such 1 from the right side of the array
        cumulativeSumOfSuffixCounts[i] = cumulativeSumOfSuffixCounts[i+1] + count ;
    }
    
    // the final count 
    int numWays = 0;
    
    // start iterating over the prefix_sum array
    for(int i=0; i<A-1 ;i++){
        
        // when the prefix_sum becomes equal to each part sum
        // then add to our final count the cumulative_sum[i+2](see O(N solution approach)
        if(prefix_sum[i] == part_sum){    
            
            // numWays += countElements(suffix_sum, i+2, part_sum); // this would have made it On^2 solution
            numWays += cumulativeSumOfSuffixCounts[i+2];
        }
    }

    return numWays;
}


int main() {
	
	vector<int> nums;
	
	int temp;
	while(cin >> temp){
	    nums.push_back(temp);
	}
	
	cout<<numWaysToPartition(nums.size(), nums)<<"\n";
	
	return 0;
}
