#include <iostream>
#include <vector>
using namespace std;

int answer=0;
void Num_ways(int V,int N,vector<vector<int>>& vertex){
   
    if(N==0 && V==3){
        answer++;
        return;
    }
    if(N==0 && V!=3){
        return;
    }
    if(N==1 && V==3){
        return;
    }
   
    
    for(int i=0;i<3;i++){
        Num_ways(vertex[V][i],N-1,vertex);
    }
    return;
}



int main() {
	int N;
	cin >> N;
	vector<vector<int>> vertex={{1,2,3},{0,2,3},{1,0,3},{0,1,2}};

	Num_ways(3,N,vertex);
	cout<<answer;
	return 0;
}
