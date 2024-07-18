#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * 
 * Given an integer array bloomDay, an integer m and an integer k.
 * We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
 * The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
 * Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
 * Example 1:
 *   Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
 *   Output: 3
 * Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
 *   We need 3 bouquets each should contain 1 flower.
 *   After day 1: [x, _, _, _, _]   // we can only make one bouquet.
 *   After day 2: [x, _, _, _, x]   // we can only make two bouquets.
 *   After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
 * Example 2:
 *   Input: bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
 *   Output: 9
 * 
 * !!This question is similar to a series of question discussed in the posts below along with template to solve those question ::
 *   https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794070/PythonC%2B%2B-Binary-search-solution-with-explanation-and-similar-questions
 *   https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *   https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *   https://www.topcoder.com/thrive/articles/Binary%20Search
 *
 * Explained solution:: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686316/JavaC%2B%2BPython-Binary-Search
 * 
 * Approach::
 *  >canCollectFlowers function is monotonous with respect to maxWaitDays. Hence, we can apply Binary search for this problem. 
 *  > The post discussed in the link below, provides a general template to solve such questions.
 *      https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/769698/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems..
 *  > The range here is between the min_value -> minimum day for any flower to bloom  and max_value -> maximum day for any flower to bloom. 
 *  > We perform a lower-bound binary search on this range for the first value that is >= the number of bouquets required(m).
 *      For more clarification in lower-bound and upperBound binary search see post -> https://www.topcoder.com/thrive/articles/Binary%20Search
 *      and https://stackoverflow.com/questions/28389065/difference-between-basic-binary-search-for-upper-bound-and-lower-bound 
 *   
 * Time complexity is O(NlogM) where M is the range of values i.e. max_value - min_value
 * 
 * */


// given a waiting period of maxWaitDays days and that there are atleast m*k flowers,
// Is it possible to collect all m*k followers by collecting only adjacent flowers ?
bool canCollectFlowers( vector<int> bloomDay, int numBoquet, int numFlowers, int maxWaitDays ){
    
    int flowersCollected = 0;
    
    for (int i : bloomDay) {
        
        // if the current flower blooms on or before maxWaitDays days 
        // then we can pluck this flower
        if(i <= maxWaitDays){
            flowersCollected++;
            
            // if we collected enough flowers for a bouquet then decrease the numBoquet remaining to be made
            if( flowersCollected == numFlowers ){
                numBoquet--;
                flowersCollected = 0;
            }
        }else{
            // if we cannot pluck a flower we drop all the flowers collected 
            // so far and start anew
            flowersCollected = 0;
        }
        
    }
    
    // if we can atleast make numBoquet number of boquet by collecting 
    // flowers then return true
    return (numBoquet <= 0);
}


int minDays(vector<int>& bloomDay, int m, int k) {
    
    //  if there are less number of flowers in the garden than required
    // then a solution is impossible
    if( bloomDay.size() < m*k ){
        return -1;
    }
    
    int min_days = INT_MAX; 
    int max_days = INT_MIN;
    
    for (int i : bloomDay) {
        
        min_days = min(min_days, i);
        max_days = max(max_days, i);
    }
    
    int left  =min_days;
    int right =max_days;
    
    while(left < right){
        
        int mid = left + (right - left)/2;
        
        // if we can collect atleast m*k flowers required for all boquet by waiting
        // for atmost mid number of days then mid is a possible answer and we trim
        // search space to left of mid including mid
        if( canCollectFlowers(bloomDay, m, k, mid) ){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    
    return left;
}

int main() {
	
	int m; // # of boquet
	int k; // # of flowers in each boquet
	
	cin >> m >> k;
	
	int temp;
	
	vector<int> bloomDay;
	
	while(cin >> temp){
	    bloomDay.push_back(temp);
	}
	
	cout << minDays(bloomDay, m, k)<<"\n";
	
	return 0;
}