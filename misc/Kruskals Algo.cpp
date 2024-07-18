#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool sortsec(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return (a.second < b.second);
}

int main(){
    int nodes,edges;
    cin >> nodes >> edges;

   vector<pair<pair<int,int>,int>> AdjSet;

    int x,y,w;
    for(int i=0;i<edges;i++){
        cin >>x >>y >> w;
        AdjSet.push_back(make_pair(make_pair(x,y),w));
    }

    int Mst=0,count_edges=0;
    int link[nodes+1],size[nodes+1];
    for(int i=1;i<=nodes;i++){
        link[i]=i;
        size[i]=1;
    }


    sort(AdjSet.begin(),AdjSet.end(),sortsec);

        for(auto itr:AdjSet){
            
            if(count_edges==nodes-1) break;
            int u=itr.first.first,v=itr.first.second;

           while(u!=link[u]){
               u=link[u];
              }
           while(v!=link[v]){
               v=link[v];}
              
            if(u!=v)
            {if(size[u]>size[v])
                 {   link[v]=u;
                size[u]+=size[v];}
            else{
                link[u]=v;
                size[v]+=size[u];}

            Mst+=itr.second;
            count_edges++;}
    }

    cout << Mst<<endl;
    return 0;
}
