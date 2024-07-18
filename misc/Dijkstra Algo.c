

#include <stdio.h>

//void Dijkstra(int **, int, int, int);

//void Dijkstra(int **AdjMatrix,int V,int E,int start){
    
   
   // return;
//}


int main()
{
    printf("V-> E-> \n");
    int V,E;
    scanf("%d %d",&V,&E);
    
    int AdjMatrix[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            AdjMatrix[i][j]= i==j ? 0:999;
    }
     
    printf("Enter the edges: Source Destination Weight \n");
    int u,v,weight;
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&weight);
        AdjMatrix[u-1][v-1]=weight;
    }   
    
    int start;
    printf("Enter the start Node: \n");
    scanf("%d",&start);
    
    //Dijkstra(AdjMatrix,V,E,Start);
     int Dist[V],Visited[V];
    Visited[start-1]=1;
    
    int min=999,next_node,cur_node;
    
    for(int i=0;i<V;i++){
        
        Dist[i]=AdjMatrix[start-1][i];
        
        if(Dist[i]<min && Visited[i]!=1){
            min=Dist[i];
            next_node=i+1;
        }
    }
    
    
    for(int i=0;i<V-1;i++){
        
        cur_node=next_node;
        Visited[cur_node-1]=1;
        min=999;
        
        for(int j=0;j<V;j++){
            
            if(Dist[j] > (Dist[cur_node-1]+AdjMatrix[cur_node-1][j]) )
                Dist[j]=Dist[cur_node-1]+AdjMatrix[cur_node-1][j];
            
            
            if(min > Dist[j] && Visited[j]!=1){
                min=Dist[j];
                next_node=j+1;
            }
        }
    }
    
    for(int i=0;i<V;i++)
        printf("%d ",Dist[i]);
    
    return 0;
}
