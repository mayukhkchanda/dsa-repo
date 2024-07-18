#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// find all triplets that add up to a given sum
// *Array can contain duplicate elements

//Gives a TLE on [0,0,0,0,,0,0,...,0,0,0.. upto n terms] where n  = 10^9
//Not handled duplicate cases
//does not handle duplicates triplets 
//even to use unordered_set we need to sort

// Time complexity -> findPairs is called for every integer so n times a
//                      and findPairs in worst case will iterate through every integer in 
//                      the remaining part so so n-1 + n-2 + n-3 ... 3,2,1 which is bounded by O(n^2) times
// Space complexity -> as an unordered_set is being used so space complexity is O(n)

//finds and returns all pairs that add up to the target su
vector<vector<int>> findPairs(vector<int> array, int target, int startIndex ){ //O(n) in worst case when pair not exists
    
    unordered_set<int> knownIntegers ;
    
    vector<vector<int>> allPairs{};
    
    for(int i=startIndex; i < array.size() ;i++ ){
        
        
       if(knownIntegers.find(target - array[i]) == knownIntegers.end()){
           //not found
           knownIntegers.insert(array[i]);
       }else{
           
           vector<int> pairs{};
           
           //pair found
           pairs.push_back(min(array[i], target-array[i]));
           pairs.push_back(max(array[i], target-array[i]));
           
           allPairs.push_back(pairs);
           //cout<<"-----"<<array[i]<<" "<<target-array[i]<<"\n";
          // return pairs;
       }
        
    }
    
    return allPairs;
}


vector<vector<int>> findTriplets(vector<int> array, int target){
    
    vector<vector<int>> triplets{};
    
    for(int i=0; i < array.size() ;i++ ){
        //cout<<array[i]<<" "<<target - array[i]<<"\n";
       vector<vector<int>> allPairs =  findPairs(array, target - array[i], i+1); 
       
       if(allPairs.size() > 0){
           
           for (auto pairs : allPairs) {
               pairs.push_back(array[i]);
               triplets.push_back(pairs);
           }
           //pairs.push_back(array[i]);
       }
    }
    
    return triplets;
}



int main() {
	vector<int> array{-1,0,1,2,-1,-4};
	int target = 0;
	
	vector<vector<int>> triplets = findTriplets(array, target);
	
	if(triplets.size() > 0){
	    for(auto triplet : triplets){
	        for(int i : triplet)
	            cout<<i<<" ";
	        cout<<"\n";
	    }
	}else{
	    cout<< "Fuck!";
	}
	
	
	return 0;
}
