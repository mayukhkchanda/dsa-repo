/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void DepthFirstSearch(int **,int ,int ,int );

void DepthFirstSearch(int **AdjList,int E,int V,int start){
    
    int visited[V],stack[V];
    int top=-1;
    
    
    stack[++top]=start;
    printf("%d ",start);
    visited[start-1]=1;
    
    int cur_node,flag;
    
    while(top!=-1){
       
       cur_node=stack[top];
       flag=0;
       //if(*AdjList[cur_node]==0){
        //  visited[cur_node]=1;
        //   top--;
          
       //  }
        
       // else{
           
            for(int i=1;i<=*AdjList[cur_node-1];i++){
               
                if(visited[*(AdjList[cur_node-1]+i)-1]!=1){
                    
                    stack[++top]=*(AdjList[cur_node-1]+i);
                    printf("%d ",stack[top]);
                    visited[stack[top]-1]=1;
                    flag=1;
                    break;
                }
            }
            if(flag!=1)top--;
        //}    
        
    }
    
    
    return;
}



int main()
{
    printf("Hello World \n");
    int E,V;
    printf("Vertices:  Edges: \n");
    scanf("%d %d",&V,&E);
    
    int *AdjList[V];
    
   // for(int i=0;i<V;i++){
    //    AdjList[i]=NULL;
    //    }
    
    for(int i=0;i<V;i++){
        
        int edges;
        printf("Enter #Edges for Node %d \n",i+1);
        scanf("%d",&edges);
    
    //    if(edges!=0){
            int *temp=(int *)malloc(sizeof(int) * (edges+1));
            
            *temp=edges;
            printf("Enter the edges: \n");
            
            for(int j=1;j<=edges;j++){
            scanf("%d",temp+j); 
            }
        
            AdjList[i]=temp;
    //    }
    }
    
   /* for(int i=0;i<V;i++){
        printf("%d-> ",i+1);
        for(int j=1 ;j<= *AdjList[i];j++){
            printf("%d ",*(AdjList[i]+j));
        }
        printf("\n");
    } */
    
   int node=1;
   printf("Enter Start node:");
   scanf("%d",&node);
   DepthFirstSearch(AdjList,E,V,node);

    return 0;
}
