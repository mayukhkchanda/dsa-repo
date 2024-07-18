#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

int helper(string &str, auto &hashset, vector<int> &cache, int &n, int idx){
    
    if(idx >= n) return 0;
    
    if(cache[idx] != -1) return cache[idx];
    
    string part= "";
    int res = INT_MAX;
    
    for(int i=idx; i<n; i++){
        part += str[i];
        
        if( hashset.find(part) != hashset.end() ){
            
            int subAns = helper(str, hashset, cache, n, i+1);
            
            if(subAns != -1) res = min(res, 1+subAns);
        }
        
    }
    
    cache[idx] = res==INT_MAX ? -1 : res;
    
    return cache[idx];
}


int minParts(string str, vector<string> &dictionary){
    unordered_set<string> hashset;
    int n = str.length();
    for(string wd : dictionary) hashset.insert(wd);
    
    vector<int> cache(n, -1);
    
    
    return helper(str, hashset, cache, n, 0)-1;
}


int main() {
	string str = "thequickbrownfox";
    vector<string> dictionary = {"the", "quick", "brown", "quickbrown", "fox"};
    
    cout << minParts(str, dictionary) << "\n";
    	
	return 0;
}
