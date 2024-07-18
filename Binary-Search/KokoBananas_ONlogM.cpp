#include <iostream>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/koko-eating-bananas/
 * 
 * There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
 * If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
 * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 * Return the minimum integer k such that she can eat all the bananas within h hours.
 * 
 * Example 1:
 *   Input: piles = [3,6,7,11], h = 8
 *   Output: 4
 * Example 2:
 *   Input: piles = [30,11,23,4,20], h = 5
 *   Output: 30
 * 
 * !!NOTE:: Each hour koko can choose only 1 pile of bananas. If she eats all bananas from that pile then only 1 hours is needed and if not 
 *          then the rest of bananas will be another pile that will be finished in another hour. !!
 * 
 * !!This question is similar to a series of question discussed in the posts below along with template to solve those question ::
 *   https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794070/PythonC%2B%2B-Binary-search-solution-with-explanation-and-similar-questions
 *   https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *   https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *   https://www.topcoder.com/thrive/articles/Binary%20Search
 * 
 * 
 * Approach::
 *  > cntHoursNeeded is a monotonic function with respect to eatingCapacity. Hence lower bound binary search can be applied
 *      here to find the minEatingSpeed such that total hours needed is less than or equal to H.
 *  > Explained solution:: https://leetcode.com/problems/koko-eating-bananas/discuss/152506/Binary-Search-Java-Python-with-Explanations
 *  > Here tha minSpeed is when she chooses to eat 1 banana from each pile every hour and maxSpeed is when she chooses to eat 1 pile
 *      every hour that is the largest pile would be the maxSpeed.
 *  > We perform a lower-bound binary search on this range for the first value that is <= the hours requied.
 *      For more clarification in lower-bound and upperBound binary search see post -> https://www.topcoder.com/thrive/articles/Binary%20Search
 *      and https://stackoverflow.com/questions/28389065/difference-between-basic-binary-search-for-upper-bound-and-lower-bound 
 *   
 * Time complexity is O(NlogM) where M is the range of values i.e. (max pile of bananas - 1) in the array 
 * 
 * */

    
// given the eatingCapacity returns the hours needed to finish all the piles
// can only choose 1 pile of bananas every hour
int cntHoursNeeded(vector<int> &piles, int eatingCapacity){
    
    int cntHours = 0;
    
    for (int i : piles) {
        
        // as she can choose only 1 pile each hour hence we are checking for each pile how many hours
        // it will take
        cntHours += (i / eatingCapacity);
        
        if( i%eatingCapacity >0){
            cntHours++;
        }
    }
    
    return cntHours;
}


int minEatingSpeed(vector<int> &piles, int h){
    
    // minSpeed is when she eats 1 pile at a time i.e. largest pile of all the piles
    int minSpeed = 1;
    // maxSpeed is when she eats all piles at once i.e. sum of all piles
    int maxSpeed = INT_MIN;
    
    for (int i : piles) {
        // minSpeed = max( minSpeed, i );
        maxSpeed = max( maxSpeed, i );
    }
    
    //making code verbose
    int left = minSpeed;
    int right = maxSpeed;
    
    while(left < right){
        
        int mid = left+(right - left)/2;
        
        // given the current eating capacity if the hours needed is more than specified to finish all the piles
        // then we are sure that a better answer lies to the right of mid and mid cannot be the eating capacity
        if( cntHoursNeeded(piles, mid) > h){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return left;
}



int main() {
	
	int h;
	
	cin >> h;
	
	vector<int> piles;
	
	int temp;
	
	while(cin >> temp){
	    piles.push_back(temp);
	}
	
	cout << minEatingSpeed(piles, h) <<"\n";
	
	return 0;
}
