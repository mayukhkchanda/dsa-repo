#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int countRectangles( vector<pair<int,int>> &points ){
    
    int n = points.size();
    set<pair<int,int>> hashmap(points.begin(), points.end());
    
    // cout<< (hashmap.find( {3,0} ) == hashmap.end())<<"\n";
    // cout<< (hashmap.find( {5,0} ) == hashmap.end()) <<"\n";
    
    // for(auto it=hashmap.begin(); it!=hashmap.end(); ++it) 
    // { 
    //     //first is x, y is the second element 
    //     cout<< it->first <<" "<< it->second <<endl; 
    // }
    
    int cnt = 0;
    
    for(int i=0; i<n; i++){
        
        pair<int,int> p1 = points[i];
        
        for(int j=i+1; j<n; j++){
            
            
            pair<int,int> p3 = points[j];
            
            // avoid points in same horizontal or vertical line
            if( p1.first == p3.first || p1.second == p3.second  ) continue;
            
            
            if( hashmap.find( {p1.first, p3.second} ) != hashmap.end() &&
                hashmap.find( {p3.first, p1.second} ) != hashmap.end()  ){
                    cnt++;
            }
        }
    }
    
    return (cnt/2);
}


int main() {
	vector<pair<int,int>> points;
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
	    int x;
	    int y;
	    cin >> x >> y;
	    points.push_back({x,y});
	}
	
	int cnt = countRectangles(points);
	
	cout << cnt;
	
	return 0;
}
