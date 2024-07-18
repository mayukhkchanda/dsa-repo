#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/magnetic-force-between-two-balls/
 * 
 *  !!NOTE:: This problem is can be framed using many ways using birds and nest(mentioned in Prateek's udemy lectures),
 *           using cows and barns(https://www.spoj.com/problems/AGGRCOW/) or using magnetic force and 
 *           baskets(https://leetcode.com/problems/magnetic-force-between-two-balls/) as in leetcode. 
 *          Nonetheless, each one of them has the exact same solution.!!
 * 
 * Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into 
 * the baskets such that the minimum magnetic force between any two balls is maximum.
 * Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
 * 
 * Given the integer array position and the integer m. Return the required force.
 * Example 1:
 *   Input: position = [1,2,3,4,7], m = 3
 *   Output: 3
 *   Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs
 *                [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
 * Example 2:
 *   Input: position = [5,4,3,2,1,1000000000], m = 2
 *   Output: 999999999
 *   Explanation: We can use baskets 1 and 1000000000.
 *   
 * !! This question is similar to a series of question discussed in the posts below::
 *      https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794070/PythonC%2B%2B-Binary-search-solution-with-explanation-and-similar-questions
 *      https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *      https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *      https://www.topcoder.com/thrive/articles/Binary%20Search
 * NOTE:: I have used the concept of birds and nests in-place of bakests and balls. They can be named anything but solution remains same.
 *           Also some times problems give an already sorted array and further sorting is not needed. Sort accordingly.
 * 
 * Approach::
 *  > To apply binary search we need a monotonice search space. Here we have such a search space that is the distance between each nests.
 *      It can be any number between 0(no distance b/w 2 birds) to 10^9(maximum possible distance b/w 2 birds based on leetcode's constraints).
 *  > At each step we can calculate mid of these 2 limits and check if with mid as the minimum possible distance of separation b/w 2 birds
 *      are we able to distribute the birds in the nests or not. 
 *  > If we are able to distribute the birds successfully then mid is an acceptable answer and we try to do better than mid by increasing the
 *      left limit to mid+1.
 *  > If we fail to distribute the birds in the given nest with mid as the minimum possible distribuition, then we decrease the right limit to
 *      mid-1.
 *  > We do this until we reach a single integer and store the answer in a variable.
 *  > This post give a crsip and clear Explanation of the methode and the solution::
 *      https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794070/PythonC%2B%2B-Binary-search-solution-with-explanation-and-similar-questions
 * 
 * Time Complexity :: we are decrease the maximum possible distance in each iteration by half so O(log(10^9)) and for check the distribuition is valid or not we travese
 *                      the entire position(or nests) array so O(N). So the total Complexity is O(N*log(10^9)) 
 * 
 * 
 * */


// checks if all the birds can be placed in the nests given that there
// be atleast minDistance units of separation b/w them
bool checkDistribuition(vector<int> &nests, int birds, int minDistance){
    
    int n = nests.size();
    
    // will always place a bird in the first nest
    int lastPlacedNest = 0;
    int i = 1;
    --birds;
    
    while( i < n && birds>0 ){
        
        // if there atleast minDistance units of separation b/w the last nest in which bird was placed and this nest
        // then this is a suitable position to place another bird
        if( nests[i] - nests[lastPlacedNest] >= minDistance ){
            lastPlacedNest = i;
            --birds;
        }
        i++;
    }
    
    // if all birds are successfully placed in the nests then this is an acceptable distribuition
    return birds == 0 ? true : false;
}


int maxDistance(vector<int> &nests, int birds){
    
    // sort the position of nests in ascending order if not already done
    sort(nests.begin(), nests.end());
    
    int n = nests.size();
    
    // minimum possible distance between 2 birds can be 0 when both are placed in same position 
    int left = 0; 
    
    // maximum possible distance b/w 2 birds is the distance b/w first and last index after sorting
    int right = nests[n-1] - nests[0]; 
    
    int maxAcceptableDist = INT_MIN;
    
    // try to converge the left and right to the maximum possible distance
    while( left <= right ){
        
        // can we have a distribuition with minimum possible distance of atleast mid units
        int mid = left + (right - left)/2;
        
        // if minDistance units of separation is acceptable distance to place all birds
        // then store it as a possible ans and try to do better than this
        if( checkDistribuition(nests, birds, mid) ){
            
            maxAcceptableDist = max(maxAcceptableDist, mid);
            
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return maxAcceptableDist;
}
    
    

int main() {
	
	int birds;
	
	cin >> birds;
	
	vector<int> nests;
	
	int temp;
	
	while(cin >> temp){
	    nests.push_back(temp);
	}
	
	cout << findMinDistance(nests, birds) <<"\n";
	
// 	cout<< checkDistribuition(nests, birds, 2);
	
	return 0;
}
