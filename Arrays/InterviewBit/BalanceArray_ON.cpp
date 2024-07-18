#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/balance-array/
 * Given an integer array A of size N. You need to count the number of special elements in the given array.
 * A element is special if removal of that element make the array balanced.
 * Array will be balanced if sum of even index element equal to sum of odd index element.
 * 
 * Example Input
 * Input 1:
 * A = [2, 1, 6, 4]
 * Input 2:
 * A = [5, 5, 2, 5, 8]
 * 
 * Example Output
 * Output 1:
 * 1
 * Output 2:
 * 2
 * 
 * Explanation 1:
 * After deleting 1 from array : {2,6,4}
 * (2+4) = (6)
 * Hence 1 is the only special element, so count is 1
 * 
 * Explanation 2:
 * If we delete A[0] or A[1] , array will be balanced
 * (5+5) = (2+8)
 * So A[0] and A[1] are special elements, so count is 2.
 * 
 * Maintain PrefixSum and SuffixSum for odd and even index seperately.
 * Let consider the following variable:
 * leftOdd[i] : Denote the prefixSum of element on odd index till i-1.
 * leftEven[i] : Denote the prefixSum of element on even index till i-1.
 * rightOdd[i] : Denote the SuffixSum of element of odd index till i+1.
 * rightEven[i] : Denote the SuffixSum of element of even index till i+1.
 * 
 * Now, check if the ith element is the special or not. When we remove an element, all elements before it remain
 * in the same position but the position of elements after that element changes that is even indexed elements become
 * odd indexed elements and vice versa. For example, let's cosider the following example:
 * {1, 2, 3, 4, 5} let's say we are at index 2(0-based) on the removal of this element, the array becomes {1, 2, 4, 5}
 * Thus the position of the elements before index 2 remains the same while the elements after 2nd index change position
 * that is all the even indexed elements to the right become odd indexed elements and vice versa.
 * Thus we check for the following condition :
 * 
 * If leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i], then ith element is special, so we increase the count.
 *   
 * 
 * */

int solve(vector<int> &A) {

    int n = A.size();

    int evenSum = 0;
    int oddSum = 0;

    int cntSpecial = 0;

    for(int i=0; i<n ;i++){
        evenSum += i%2 == 0 ? A[i] : 0; //calculate sum of alll even index elements
        oddSum += i%2 != 0 ? A[i] : 0; //calculate sum of all odd index elements
    }    
    
    for(int i=0; i<n ;i++){
        // as we are iterating from left to right hence when we see an even indexed element
        // we decrease the even sum and same for the odd indexed elements.
        if(i%2 == 0){
            evenSum -= A[i];
        }else{
            oddSum -= A[i];
        }
        
        // if the removal of this element made the array balanced then count it in the answer
        if( evenSum == oddSum ){
            cntSpecial++;
        }
        
        // after we are done processing this element, we need to put it back into the even/odd sum
        // If this element was at even index, then we add this element at odd indexed element's sum
        // as after removal of 1 element all the even indexed elements will be odd indexed elements(and vice versa).
        // Thus when we would remove the next element after this element then this element would become an
        // odd indexed element. Similar reasoning is for an odd indexed element.
        if(i%2 == 0){
            oddSum += A[i];
        }else{
            evenSum += A[i];
        }
    }  

    return cntSpecial;
}


int main() {
	vector<int> nums;
	int temp;
	while(cin>>temp){
	    nums.push_back(temp);
	}
	cout<<solve(nums)<<"\n";
	return 0;
}

