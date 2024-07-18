#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vertex={{1,2,3},{0,2,3},{1,0,3},{0,1,2}};

int v=3;
int Num_ways(int u,int steps_remain,vector<vector<int>>& dp){
  
    if(steps_remain==0){
        if(u==v){
           dp[u][steps_remain]=1;
           return 1;
        }
        else{
           dp[u][steps_remain]=0;
            return 0;
    }}
    if(dp[u][steps_remain]!=-1){
        
        return dp[u][steps_remain];
    }
    int x=0;
    for(int i=0;i<3;i++){
       x+= Num_ways(vertex[u][i],steps_remain-1,dp);
	   if(x>=1000000007){
			x-=1000000007;
	   }
    }
    dp[u][steps_remain]=x;
  
    return dp[u][steps_remain];
}

int main() {
    int N;
    cin>>N;
	vector<vector<int>> dp(4,vector<int> (N+1,-1 ) );
    int answer=Num_ways(3,N,dp);
	
	cout<<answer<<endl;
	return 0;
}
