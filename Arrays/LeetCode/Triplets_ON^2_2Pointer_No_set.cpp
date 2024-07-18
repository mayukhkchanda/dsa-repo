#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// find all triplets that add up to a given sum
// *Array can contain duplicate elements
// leetcode question -> https://leetcode.com/problems/3sum/

/**
Following is an approach with out using unordered-set to track duplicate pairs
Nice solution:: https://leetcode.com/problems/3sum/discuss/7438/C%2B%2B-two-pointes-solution-(easy-way-to-handle-duplicaiton).
*/

//find all pairs that add up to a given sum
vector<vector<int>> findPairs(vector<int> &array, int startIndex, int target){
    
    int low = startIndex;
    int high = array.size() - 1;
    
    vector<vector<int>> pairs{};// O(#pairs) space complexity
    
    //this loop has a time complexity of O(N) in wrost case as, if no pairs exists then 
    //loop will be executed floor(N/2) times
    while( low < high  ){//not '<=' else will take the middle index element twice when n is odd
        int sum = array[low] + array[high];
        
        if(sum < target){
            low++;
        }
        else if(sum > target){
            high--;
        }
        else{
            vector<int> pair{};
            pair.push_back(array[low]);
            pair.push_back(array[high]);
            
            pairs.push_back(pair);
            
            //if duplicate exists skip them // !!IMPORTANT!! if [0,0,0,...,0,0,0] then 
            //without this step will give a TLE. //skips elements in left and right direction if same
            while( (low < array.size()-1 ) && (array[low] == array[low+1] ) ) low++;
            while( (high > 0) && (array[high] == array[high-1]) ) high--;
            
            
            low++; 
            high--;
        }
        
    } 
    
    return pairs;
}

//We sort the array and for every element, we call findPairs on target-el
//on the array starting after the current element.
//find pairs returns list of all pairs that add upto a target sum
// this function has a complexity of O(N^2 + NlogN) in time and O(#triplets) in space
vector<vector<int>> findTriplets(vector<int> &array, int target){
    
    //int target = 0;
    
    sort(array.begin(), array.end()); // O(NlogN) time complexity
    
    vector<vector<int>> tripletsVector{};
    
    //for findPairs atleast 2 elements need so loop through array.size()-2 elements
    for(int i=0; i< array.size() ;i++){ // iterates over every index i.e. N times
        
        //if the current element is same as previous element then that scenerio is already solved and we can skip it
        if(i>0 && array[i] == array[i-1]) continue;
        
        vector<vector<int>> pairs = findPairs( array, i+1, target-array[i]); // findPairs is bounded by O(N) in worst case
        
        if(pairs.size() > 0){
            
            for (vector<int> pair : pairs) { // iterates over #triplets found //trival iteration time cost in comparision to findPairs's O(N)   
                pair.push_back(array[i]); //make it a triplet
                tripletsVector.push_back(pair);
            }
            
        }
    }
    
    return tripletsVector;
}


int main() {

	vector<int> array{-1,0,1,2,-1,-4};
	int target = 0;
	
	vector<vector<int>> triplets = findTriplets(array,target);
	
	cout<<triplets.size() <<"\n";
	for(auto triplet : triplets){
	    for(int el : triplet )
	        cout <<el<<" ";
	    cout<<"\n";
	}
	
	return 0;
}
