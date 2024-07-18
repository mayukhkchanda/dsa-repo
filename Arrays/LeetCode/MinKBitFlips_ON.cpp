#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Question: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
 *
 * In an array nums containing only 0s and 1s, a k-bit flip consists of choosing a (contiguous) subarray 
 * of length k and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
 * Return the minimum number of k-bit flips required so that there is no 0 in the array.  If it is not possible, return -1.
 * 
 * Example 1:
 *   Input: nums = [0,1,0], k = 1
 *   Output: 2
 *   Explanation: Flip nums[0], then flip nums[2].
 * 
 * Example 2:
 *   Input: nums = [1,1,0], k = 2
 *   Output: -1
 *   Explanation: No matter how we flip subarrays of size 2, we can't make the array become [1,1,1].
 * 
 * Example 3:
 *   Input: nums = [0,0,0,1,0,1,1,0], k = 3
 *   Output: 3
 *   Explanation:
 *   Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
 *   Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
 *   Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
 * 
 * Explained Solutions::
 *  > See Post and Comment: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/239284/C++-greedy-stack-and-O(1)-memory/649268
 *  > With queue and getting rid of queue: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/238538/Python-O(n)-using-queue-and-how-to-get-rid-of-the-queue
 *  > Greedy approach intuition: 
 *      >> (Comment->)https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/238610/Why-greedy-works-in-this-problem/236531
 *      >> (Hard to understand->)https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/238683/Proof%3A-Why-greedy-works
 * 
 * Take a greedy approach::
 *   > There are 2 cases ::
 *      >> Flipped even times : If an element is 0 and it was flipped even # of times then it will be 0 and we need to flip it.
 *                              If an element is 1 and it was Flipped even # of times then it will be 1 and we donot need to flip it.
 * 
 *      >> Flipped odd times  : If an element is 0 and it was flipped odd # of times then it will be 1 and we donot to flip it.
 *                              If an element is 1 and it was Flipped odd # of times then it will be 0 and we need to flip it.
 * 
 *  > Now based on the above logic we can check if the current element needs to be flipped or not. If we need to flip this element
 *      then we store the last index of the interval that is flipped starting from this element's index(i.e. i to i+k-1).
 *  > After we cross an interval we pop it out of the queue. This way we can maintain the number of times a certain element was flipped.
 *      And by check the above conditions we can determine if the element needs to be flipped.
 *  > Finally, if the queue is not empty then a tranformation is not possible. 
 * 
 * 
 * Time complexity -> O(N)
 * Space complexity -> O(K)
 * 
 */
int minKBitFlips(vector<int>& bit, int k) {
    
    int n = bit.size();
    
    int flips = 0;
    queue<int> flippedInterval;
    
    
    for (int i = 0; i < n; i++) {
        
        // check if this bit is 0
        if(bit[i] == 0){
            
            // check if this element was flipped even # of times in which
            // case we need to flip it again.
            if( flippedInterval.empty() ||  flippedInterval.size()%2 ==0){
                flips++;
                flippedInterval.push(i+k-1);
            }
            // else this element was flipped odd number of times in which case
            // this became 1 after all flips and we donot need to flip it again
        }
        //else this bit is 1
        else{
            //check if this bit was flipped odd number of times in which case
            //this became 0 after flipping and we need to flip it.
            if( !flippedInterval.empty() && flippedInterval.size()%2 !=0){
                flips++;
                flippedInterval.push(i+k-1);
            }
            // else either this element was not present in any flips or the number
            // of flips of this element was even in both the case we donot need to flip it
        }
        
        // if we cross the any flipped interval then we can then remove this interval
        if(!flippedInterval.empty() && flippedInterval.front() <= i ){
            flippedInterval.pop();
        }
    }
    
    // finally if the queue is not empty then a tranformation is not possible
    // else we return the # of flips
    return flippedInterval.empty() ? flips : -1;
}



int main() {
    int k;
    cin >> k;
    
	vector<int> bits;
	int temp;
	while(cin >> temp){
	    bits.push_back(temp);
	}
	
	cout<< minKBitFlips(bits,k);
	
	return 0;
}
