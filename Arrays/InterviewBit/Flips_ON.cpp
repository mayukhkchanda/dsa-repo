#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/flip/
 * You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. 
 * In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters
 * SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.
 * 
 * Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t
 * want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R.
 * If there are multiple solutions, return the lexicographically smallest pair of L and R.
 * 
 * Examples:
 *   Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
 *   For example, S = 010
 *   
 *   Pair of [L, R] | Final string
 *   _______________|_____________
 *   [1 1]          | 110
 *   [1 2]          | 100
 *   [1 3]          | 101
 *   [2 2]          | 000
 *   [2 3]          | 001
 *   
 *   We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
 *   Another example, if S = 111 then no operation can give us more than three 1s in final string. So, we return empty array [].
 * 
 * Approach:: 
 *  > This problem is an extension of the problem below:
 *      https://www.geeksforgeeks.org/maximize-number-0s-flipping-subarray/
 *  > Here since after flipping the 1 will become 0 and 0 will become 1 thus we consider every 0 as +1 and every 1 as -1
 *      and create a transformed array.
 *  > Thus we need only to find the maximum sub-array in this transformed array(see my my explanation for this problem Max0Flip_ON.cpp).
 *  > For finding the maximum sub-array we use the same logic as  max-sub array sum. Only here we also consider the start and end indices
 *      of the maximum sub-array(when we return it's 1-based so we add 1 to the final left and right indices).
 *  > If at any point we see the sum is greater than max so we store it's value in max and also the left and right indices.
 *      When both max and sum are equal we check of the sub-array that has smaller left index of the two(max and sum). 
 *      When both max and sum are equal and also left indices are equal then we chek for smaller right index.
 *  > Finally if the maximum sum is negative that means all the elements were 1 and we cannot flip any element so we
 *      return an empty array. else we return the left and right index of maximum sub-array incremented with 1.
 * 
 * 
 * 
 * */

// returns the indices(1-based) of sub-array with maximum sum. If maximum sum is negative then
// return an empty array
vector<int> findMaxSubArr(vector<int> array){
    
    int n = array.size();
    
    // the maximum must be INT_MIN as 0 sub-array sum is acceptable
    int sum = INT_MIN;
    int max = INT_MIN;
    
    int left = -1;
    int right = -1;
    
    // as we need to compare them with left and right in case of a tie b/w sum and max
    // and pick the smaller hence we take the maximum possible value(INT_MAX would also work)
    int max_left= n;
    int max_right = n;
    
    for (int i = 0; i < n; i++) {
        
        // same logic as max-sub array sum if the sum is less than 0 then ditch the 
        // currently running sub-array and pick a new sub-array starting from this index.
        right=i;
        if(sum < 0){
            sum = array[i];
            left = i;
        }else{
            sum += array[i];
        }
        
        // if the current sub-array sum is greater than maximum so far then update it
        if(max < sum) {
            max_left = left;
            max_right = right;
            max=sum;
        }
        // in case both max and sum are same
        else if(max == sum){
            
            // pick one with smaller left index
            if(max_left > left){
                max_left = left;
                max_right = right;
            }
            // else if both's left index are same pick one with smaller
            // right index
            else if(max_left == left && max_right > right){
                max_left = left;
                max_right = right;
            }
        }
    }
    
    // if max is negative that means all elements were 1 and we cannot flip any sub-array
    if(max < 0){
        return {};
    }
    // else return the sub-array indices incremented with 1 as answer is in 1-based index
    else{
        return {max_left+1, max_right+1};
    }
}

// returns the indices(1-based) of sub-array which if flipped would create maximum # of 1's in the
// new flipped array. If all elements are 1 then it returns an empty array.
vector<int> flip(string A) {

    int n = A.length();
    
    // create a new transformed array from the string such that
    // if str[i] == 0 then transformed[i] is +1 
    // else str[i] == 0 then transformed[i] is -1
    vector<int> transformed(n);
    for(int i = 0; i < n; i++){
        transformed[i] = A[i] == '0' ? 1 : -1;
    }
    
    // find the max sub-array indices and return it.
    vector<int> indices = findMaxSubArr(transformed);
    
    return indices;
}


int main() {
	
	string A;
	cin >> A;
	
	vector<int> indices = flip(A);
	
	if(indices.size() > 0){
	    cout<< indices[0]<<" "<<indices[1]<<"\n";
	}else{
	    cout<<"[]\n";
	}
	
	return 0;
}
