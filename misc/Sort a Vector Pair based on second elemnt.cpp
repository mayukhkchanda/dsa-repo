#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
bool sortbysec(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b) 
{ 
    return (a.second < b.second); 
}

int main() {
    
    vector <pair<pair<int,int>,int>> AdjSet;
    int e;
    cin >> e;
    int x,y,w;
    for(int i=0;i<e;i++){
        cin >> x>>y>>w;
       
        AdjSet.push_back(make_pair(make_pair(x,y),w));
    }
    for(auto itr:AdjSet){
       cout <<itr.first.first<<" "<<itr.first.second<< " "<<itr.second<<endl;
  }
   cout <<"after"<<endl ;
   sort(AdjSet.begin(),AdjSet.end(),sortbysec);
   
	 for(auto itr:AdjSet){
       cout <<itr.first.first<<" "<<itr.first.second<< " "<<itr.second<<endl;
  }
	return 0;
}
