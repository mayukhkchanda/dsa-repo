#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/**
 * Question:: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * 
 * A conveyor belt has packages that must be shipped from one port to another within days days.
 * The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the 
 * conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
 * Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
 * Example 1:
 *   Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 *   Output: 15
 * Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
 *   1st day: 1, 2, 3, 4, 5
 *   2nd day: 6, 7
 *   3rd day: 8
 *   4th day: 9
 *   5th day: 10
 * 
 * Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting
 * the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
 * 
 * !!This question is similar to a series of question discussed in the posts below along with template to solve those question ::
 *   https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794070/PythonC%2B%2B-Binary-search-solution-with-explanation-and-similar-questions
 *   https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *   https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *   https://www.topcoder.com/thrive/articles/Binary%20Search
 *
 * Explained solution:: https://leetcode.com/problems/split-array-largest-sum/discuss/161143/Logical-Thinking-with-Code-Beats-99.89
 * 
 * Approach::
 *  >cntDays function is monotonous with respect to maxCapacity. Hence, we can apply Binary search for this problem. 
 *  > The post discussed in the link below, provides a general template to solve such questions.
 *      https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/769698/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems..
 *  > The range here is between the min_value -> largest cargo weight(when each cargo is shipped 1 day at a time) and 
 *      max_value -> sum of all cargo weights(when all of the cargo is shipped in a single day). 
 *  > We perform a lower-bound binary search on this range for the first value that is <= the number of days required(m).
 *      For more clarification in lower-bound and upperBound binary search see post -> https://www.topcoder.com/thrive/articles/Binary%20Search
 *      and https://stackoverflow.com/questions/28389065/difference-between-basic-binary-search-for-upper-bound-and-lower-bound 
 *   
 * Time complexity is O(NlogM) where M is the range of values i.e. max_value - min_value
 * 
 * */


// given the maxCapacity return the number of days to ship all the cargo
int cntDays(vector<int> &weights, int maxCapacity){
    
    int days = 0;
    int weightLoaded = 0;
    
    for (int i : weights) {
        
        weightLoaded += i;
        
        if(weightLoaded > maxCapacity){
            days++;
            weightLoaded = i;
        }
    }
    
    return days+1;
}


int shipWithinDays(vector<int> &weights, int days){
    
    // minWeight is when we ship 1 cargo each day so the largest weight
    int minWeight = INT_MIN;
    // maxWeight is when we ship all the cargo in the same day so the sum of all the cargo weights
    int maxWeight = 0;
    
    for (int i : weights) {
        minWeight = max( i, minWeight );
        
        maxWeight += i;
    }
    
    // code below is from the template given in the link::
    // https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems
    int left= minWeight;
    int right = maxWeight;
    
    while(left < right){
        
        int mid = left + (right-left)/2;
        
        // if more days are required than given days then a better answer lies to the right of mid 
        // that is we need to increase the maxCapacity and since mid is not a possible answer we can skip over mid
        // if the condition is true. else mid is a possible answer and we count it in the next iteration.
        if( cntDays(weights, mid) > days){
            left = mid +1;
        }
        else{
            right = mid;
        }
    }
    
    return left;
}


int main() {
	
	int days;
	
	cin >> days;
	
	int temp;
	
	vector<int> weights;
	
	while(cin >> temp){
	    weights.push_back(temp);
	}
	
	cout << shipWithinDays(weights, days)<<"\n";
	
	return 0;
}
