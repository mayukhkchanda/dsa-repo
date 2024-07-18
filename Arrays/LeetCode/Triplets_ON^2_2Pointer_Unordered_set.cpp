#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// find all triplets that add up to a given sum
// *Array can contain duplicate elements

struct VectorHash{ // copied from stack-overflow
    size_t operator()(const vector<int>& v) const{
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};


//2-pointer method - O(N) time complexity, O(#pairs) space complexity as it finds all pairs instead of 1
vector<vector<int>> findPairs(vector<int> array, int startIndex, int target){
    
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
            
            //if duplicate exists skip them // !!IMPORTANT!! if [0,0,0,...,0,0,0] then 
            //without this step will give a TLE. //skips elements in left and right direction if same
            while( (low < array.size()-1 ) && (array[low] == array[low+1] ) ) low++;
            while( (high > 0) && (array[high] == array[high-1]) ) high--;
            
            pairs.push_back(pair);
            
            low++; 
            high--;
        }
        
    } 
    
    return pairs;
}

/** Sort the array and for each index(i) solve pair-sum(finding all pairs that add up to a target sum) problem on
  * the  remaining right-hand portion of the array that is from i, i+1, i+2 ...n-1
  */

// this function has a complexity of O(N^2 + NlogN) in time and 2*O(#triplets) => O(#triplets) in space
vector<vector<int>> findTriplets(vector<int> array, int target){
    
    sort(array.begin(), array.end()); // O(NlogN) time complexity
    
    unordered_set<vector<int>, VectorHash> triplets;
    vector<vector<int>> tripletsVector{};
    
    //for findPairs atleast 2 elements need so loop through array.size()-2 elements
    for(int i=0; i< array.size() ;i++){ // iterates over every index i.e. N times
        
        vector<vector<int>> pairs = findPairs( array, i+1, target-array[i]); // findPairs is bounded by O(N) in worst case
        
        if(pairs.size() > 0){
            
            for (vector<int> pair : pairs) { // iterates over #triplets found //trival iteration time cost in comparision to findPairs's O(N)
                
                pair.push_back(array[i]); //make it a triplet
                
                sort(pair.begin(), pair.end());//sorts only 3 elements O(1) time cost //else it will give a different hash
                
                if(triplets.find(pair) == triplets.end()){ //look up is O(1) 
                    triplets.insert(pair);
                    tripletsVector.push_back(pair);
                }
                
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
