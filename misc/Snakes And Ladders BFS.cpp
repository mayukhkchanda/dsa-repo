#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

   struct node{
       int Adj_node;
       node* next;
   };
   
   node* insert(node* , int );
   void BFS(node **AdjList,int *level);
   
   node* insert(node* start, int value){
        node* n= new node;
        n->Adj_node=value;
        n->next=start;
        start=n;
        return n;
   }
   
   
   void BFS(node **AdjList,int *level){
        
      int lev=0,flag=1;
        level[1]=lev;
        
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int vertex=q.front();
            q.pop();
            
            node* start=AdjList[vertex];
            
                while(start!=NULL){
                    if(level[start->Adj_node]!=-1){
                        start=start->next;
                        continue;
                    }
                    level[start->Adj_node]=level[vertex]+1;
                    q.push(start->Adj_node);
                    start=start->next;
                }
        }
		
        cout<< level[100];
        
       return;
   }

int main() {
    
    node *AdjList[101];
    int level[101];
    int lad_count,snake_count;
    unordered_map <int,int> ladders,snakes;
    
    for(int i=1;i<=100;i++){
        AdjList[i]=NULL;
        level[i]=-1;
    }
    
	cin >> lad_count;
	for(int i=0;i<lad_count;i++){
	    int start,end;
	    cin >> start >> end;
	    ladders[start]=end;
	}
	
	cin >> snake_count;
	for(int i=0;i<snake_count;i++){
	    int start,end;
	    cin >> start >> end;
	    snakes[start]=end;
	}
	
    for(int i=1;i<100;i++){
        node* start=NULL;
        if(ladders.find(i)!=ladders.end()) continue;
        if(snakes.find(i)!=snakes.end()) continue;
        
        for(int j=1;j<=6 && (i+j<=100) ;j++){
            if(ladders.find(i+j)!=ladders.end()){
                start=insert(start,ladders[i+j]);
                continue;
            }
            else if(snakes.find(i+j)!=snakes.end()){
                start=insert(start,snakes[i+j]);
                continue;
            }
            
            start=insert(start,i+j);
        }
        AdjList[i]=start;
    }
    
    /*for(int i=1;i<100;i++){
        node* start=AdjList[i];
        cout << i<<" ";
        while(start!=NULL){
            cout << start->Adj_node<<" ";
            start=start->next;
        }
        cout<<endl;
    }*/
    
    BFS(AdjList,level);
	
	return 0;
}
