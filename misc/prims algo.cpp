#include <iostream>
#include <string.h>
#include <vector>
#define Inf 1000000
using namespace std;

int main() {
    // your code goes here
    int vertex,edges;
    cin >> vertex >> edges;
    
    int AdjMatrix[vertex][vertex];
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++)
            AdjMatrix[i][j]= i==j ? 0 :Inf;}
    
    
    for(int i=0;i<edges;i++){
        int u,v,r;
        cin >>u >> v >> r;
        AdjMatrix[u-1][v-1]=r;
        AdjMatrix[v-1][u-1]=r;
        }
             
              
              
      int visited[vertex], MST_val=0,start;
      vector<int> vst;
      memset(visited, 0 ,vertex*sizeof(int));

      cin >> start;
      
      vst.push_back(start);
      visited[start-1]=1;
   
      
    while(vst.size() <vertex){
        int min=Inf,flag=0,node;
        
        for(int v:vst){
            cout << v <<endl;
           for(int j=0;j<vertex;j++)
            {
                if(visited[j]!=1 && min >AdjMatrix[v-1][j]){
                    min=AdjMatrix[v-1][j];
                    node=j;
                    flag=1;
                }
            }           
        }
            if(flag!=0)
               { MST_val+=min;
              // cout << MST_val <<endl;
                 visited[node]=1;
                 vst.push_back(node+1);
               }
      //cout<<endl;
    }
    
        cout << MST_val<<vst.size();
    return 0;
}
