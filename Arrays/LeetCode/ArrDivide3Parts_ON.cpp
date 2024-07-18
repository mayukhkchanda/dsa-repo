#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/three-equal-parts/
 * 
 * You are given an array arr which consists of only zeros and ones, divide 
 * the array into three non-empty parts such that all of these parts represent 
 * the same binary value.
 * If it is possible, return any [i, j] with i + 1 < j, such that:
 *   arr[0], arr[1], ..., arr[i] is the first part,
 *   arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
 *   arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
 * All three parts have equal binary values. If it is not possible, return [-1, -1].
 * Note that the entire part is used when considering what binary value it represents. 
 * For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed,
 * so [0,1,1] and [1,1] represent the same value.
 * 
 * Example 1:
 *   Input: arr = [1,0,1,0,1]
 *   Output: [0,3]
 * Example 2:
 *   Input: arr = [1,1,0,1,1]
 *   Output: [-1,-1]
 * Example 3:
 *   Input: arr = [1,1,0,0,1]
 *   Output: [0,2]
 * 
 * Explained Solution:
 *  > https://leetcode.com/problems/three-equal-parts/discuss/250203/Logical-Thinking
 *  > https://leetcode.com/problems/three-equal-parts/discuss/223886/Java-O(n)-simple-solution-(don't-know-why-official-solution-is-that-long)
 *  
 * Approach::
 *  > As we need to divide the array into 3 parts we are sure that each part must contain equal # of 1's.
 *      Thus, the total # of 1's must be divisible by 3. If not then it is not possible and return (-1,-1).
 *  > If the above condition passes then we find the index of 1's in 3 parts such that each part contains 
 *      exactly total_ones/3 # of 1's. 
 *  > Now, all the indexes of 1's are calculated we need to check the pattern staring from 1's in each part 
 *      matches with one another. Thus we iterate over the left and mid part comparing them to the right part.
 *      If they match then we return the index of end of left part and start of right part as a pair else (-1,-1)
 *      from the matchPattern function.
 *  > An edge case is all 0's here doesnt matter how we partition the array hence we return {0,n-1} as a pair.
 *      This is found out from leetcode code by running a few tests on all 0 input of different sizes.
 * */


// all 3 parts must have the same pattern of 1's and 0's starting from the first 1 
// in that part. If the condition statisfies then we return the index of end of left part 
// and start of right part as a pair else (-1,-1).
vector<int> matchPattern(vector<int>& array, int left, int mid, int right){
    
    int n = array.size();
    
    while( right < n ){
        // check the patter in left and middle part bit by bit 
        if( array[left] == array[right] && array[mid] == array[right] ){
            left++;
            right++;
            mid++;
        }
        // if anywhere the pattern fails to match then return (-1,-1) for impossible
        else{
            return {-1, -1};
        }
    }
    // if the pattern matched successfully then left would point to the start of middle part
    // and mid would point to the start of the right part.
    // so return left-1 and mid as a pair according to the quesition stated.
    return {left-1, mid};
}


vector<int> threeEqualParts(vector<int>& array) {
    
    int n = array.size();
    
    int total_ones = 0;
    
    for (int i : array) {
        total_ones += i ? 1 : 0;
    }
    
    // cannot make 3 equal parts containing same # of 1's
    if(total_ones % 3 != 0){
        return {-1, -1};
    }
    
    // if all are 0's, then 3 parts can be 0-n-2, n-1, n-2 
    if(total_ones == 0){
        return {0,n-1};
    }
    
    // for 3 equal parts representing same # in binary, number of 1's must be same in each part
    int numOnesPerPart = total_ones / 3;
    
    // the starting index of 1's will be pushed from the last sub-array part,
    // then the middle sub-array part and the first sub-array part.
    vector<int> indexOfOnes; 
    int count_ones = 0;
    
    // find the starting indices of 1's in each part
    for(int i= n-1; i>=0 ;i--){
        
        count_ones += array[i] ? 1 : 0;
        
        // if the count of ones became equal to that is allowed in the each part then
        // this is the starting 1 of an sub-array and a new part will start from the next index
        if(count_ones == numOnesPerPart){
            // we push the indexes of 1's in each of 3 parts in reverse order i.e. index of 1 of
            // end part first and start part last.
            indexOfOnes.push_back(i);
            count_ones = 0;
        }
    }
    
    int leftStart = indexOfOnes[2]; // the first index of 1 of the left part was pushed last
    int midStart = indexOfOnes[1]; // the first index of 1 of the mid part was pushd 2nd last
    int rightStart = indexOfOnes[0]; // the first index of 1 of the right part was pushed 1st
    
    // Only having equal number of 1's in each part will not do it.
    // We need to check for the eqality of pattern.
    // Match pattern of each part and get the indices of i and j if 
    // they are matched else {-1,-1} is returned.
    vector<int> indices = matchPattern(array, leftStart, midStart, rightStart);
    
    return indices;
}

int main() {
    
    vector<int> nums;
    
    int temp;
    
    while(cin >> temp){
        nums.push_back(temp);
    }
    
    vector<int> indices =  threeEqualParts(nums);
    
    cout<<indices[0] <<" "<<indices[1]<<"\n";
    
	return 0;
}