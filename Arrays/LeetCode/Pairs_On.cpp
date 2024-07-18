#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Find a pair that add up to target_sum

// worst case time complexity is O(n) and space complexity  is O(n) for unordered_set
                        //pass by value -> O(n)
vector<int> findPair(vector<int> array, int target){
    unordered_set<int> knownIntegers ; //unordered_set gives O(1) look-up
    
    vector<int> pairs{};
    
    //for every element in the array. check if target-el exists in the set
    //if exists -> pair found and return
    //else insert the el in the set for future look-up
    for(int el : array){ //in worst case we dont find any pair, so O(n)
        
       if( knownIntegers.find(target-el) == knownIntegers.end()){ //element look-up is O(1) in unordered_set
           knownIntegers.insert(el);  // O(1) as it is randomized
       }else{
           //found an element  
           pairs.push_back(el );//push back of 2 elements is always constant so O(1)
           pairs.push_back(target-el );
           break;
       }
        
    }
    
    return pairs;
}

int main() {
	vector<int> array{10,5,2,3,-6,9,11};
	int target = 4;
	
	vector<int> pairs = findPair(array, target);
	
    if(pairs.size()  > 0){
        cout << pairs[0] <<" "<<pairs[1]<<endl;
    }else
        cout << "Fuck!";
	
	return 0;
}
