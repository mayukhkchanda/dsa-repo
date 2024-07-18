#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/maximum-absolute-difference/
 * 
 * You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
 * 
 * f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
 * 
 * For example,
 * 
 * A=[1, 3, -1]
 * 
 * f(1, 1) = f(2, 2) = f(3, 3) = 0
 * f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
 * f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
 * f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5
 * 
 * So, we return 5.
 * 
 * Approach::
 *  f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways (Since we are looking at max value, 
 * we don’t even care if the value becomes negative as long as we are also covering the max value in some way).
 * 
 * NOTE:: |x| = +x or -x
 * 
 * (A[i] + i) - (A[j] + j)
 * -(A[i] - i) + (A[j] - j) 
 * (A[i] - i) - (A[j] - j) 
 * (-A[i] - i) + (A[j] + j) = -(A[i] + i) + (A[j] + j)
 * Note that case 1 and 4 are equivalent and so are case 2 and 3.
 * 
 * We can construct two arrays with values: A[i] + i and A[i] - i. Then, for above 2 cases, 
 * we find the maximum value possible. For that, we just have to store minimum and maximum 
 * values of expressions A[i] + i and A[i] - i for all i.
 * 
 * 
 * 
 * */


int maxAbsoluteDiff(vector<int> &A) {

    int n = A.size();

    int max_AiPi = INT_MIN;
    int min_AiPi = INT_MAX;

    int max_AiMi = INT_MIN;
    int min_AiMi = INT_MAX;

    for(int i=0; i<n ;i++){
        max_AiPi = max( A[i]+i, max_AiPi);
        min_AiPi = min( A[i]+i, min_AiPi);
        
        max_AiMi = max( A[i]-i, max_AiMi);
        min_AiMi = min( A[i]-i, min_AiMi);
    }


    return max(abs(max_AiPi-min_AiPi) , abs(max_AiMi - min_AiMi));
}



int main() {
    
    vector<int> nums;
    
    int temp;
    
    while(cin >> temp){
        nums.push_back(temp);
    }
    
    cout<< maxAbsoluteDiff(nums);
    
	return 0;
}
