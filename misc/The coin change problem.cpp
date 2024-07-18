#include <vector>
#include <iostream>
using namespace std;
static int count=0;
void counts(vector<int> coins,int target,int L){
    
    if(target<0)
       return;
    if(target==0){
        count++;
        return;}
    for(int i=L;i<coins.size();i++){
        counts(coins,target-coins[i],i);
    }
}

int main() {
	// your code goes here
	vector<int>coins{1,2,3};
	int target=4;
	int L=0;
	counts(coins,target,L);
	cout << count;
	return 0;
}
