//https://www.geeksforgeeks.org/count-of-right-angled-triangle-formed-from-given-n-points-whose-base-or-perpendicular-are-parallel-to-x-or-y-axis/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int countTriangles(vector<pair<int,int>> points){
    
    int n = points.size();
    
    unordered_map<int,int> hashmapX;
    unordered_map<int,int> hashmapY;
    
    for(int i=0; i<n; i++ ){
        hashmapX[points[i].first]++; // map of all points in x-axis
        hashmapY[points[i].second]++; //map of all points in y-axis
    }
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        
        // cout << points[i].first <<" "<<points[i].second <<" - "
        //     << hashmapX[points[i].first]-1 << ":" <<hashmapY[points[i].second]-1 <<"\n";
        
        cnt += (hashmapX[points[i].first]-1) * (hashmapY[points[i].second]-1);
    }
    
    return cnt;
}

int main() {
	int n;
	cin >> n;
	
	vector<pair<int,int>> points;
	
	for (int i = 0; i < n; i++) {
	    int x;
	    int y;
	    cin >> x >> y;
	    points.push_back({x,y});
	}
	
	int cnt = countTriangles(points);
	
	cout << cnt <<"\n";
	
	return 0;
}
