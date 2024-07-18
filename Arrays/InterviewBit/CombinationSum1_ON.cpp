#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> nums){
    int totalSum = 0;
    for (auto i : nums) {
        totalSum += i;
        // cout<<i<<" ";
    }
    // cout<<"\n";
    return totalSum;
}


void genCombination(vector<int> candidates, int remain, int start, vector<int> combination, vector<vector<int>> &combinations ){
    
    int n = candidates.size();
    
    // if(sum(combination) > target  ){
    if(remain < 0){
        return;
    }
    
    // if(  sum(combination) == target  ){
    if(remain == 0){
        combinations.push_back(combination);
        return;
    }
    
    for (int i = start; i < n; i++) {
        
        // select this element for the combination and proceed to
        // generate new combination with this combination
        combination.push_back(candidates[i]);
        genCombination(candidates, remain-candidates[i], start, combination, combinations);
        combination.erase(combination.end()-1);
        
        // or not select this element for this combination and proceed to
        // generate new combination without this combination
        // genCombination(candidates, target, start+1, combination, combinations);
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    vector<vector<int>> combinations;
    vector<int> combination;
    
    genCombination(candidates,  target, 0, combination, combinations);
    
    return combinations;
}

int main() {
    
    vector<int> nums;
    int temp;
    
    int target ;
    cin >> target;
    
    while(cin >> temp){
        nums.push_back(temp);
    }
    
    vector<vector<int>> combinations = combinationSum(nums, target);
    
    for (auto combination : combinations) {
        for (auto i : combination) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    
    
	return 0;
}