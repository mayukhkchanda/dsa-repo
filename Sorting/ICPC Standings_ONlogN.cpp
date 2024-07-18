#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

// sort in ascending order of teams' prefered rank 
bool comparator(pair<string,int> p1, pair<string,int> p2){
    return p1.second < p2.second;
}


int badness(vector<pair<string,int>> teams){

    // sort the vector by the second element.
    // That is the one with higher prefered ranks should come first.
    // The teams with same prefered ranks can be placed in any order.
    sort(teams.begin(), teams.end(), comparator);    
    
    // calculate the minimum badness 
    int min_badness = 0;
    
    // iterate over the sorted list of teams and calculate the difference in their
    // prefered rankings and the actual rankings
    for (int i = 0; i < teams.size(); i++) {
        min_badness += abs(teams[i].second - (i+1));
    }
    return min_badness;
}

// int badness(vector<pair<string,int>> teams){
    
//     // rankings are 1-based and we will store frequency of rankings
//     int rank_frq[teams.size()+1] = {0};
    
//     // calculate the frequency of rankings
//     for (int i = 0; i < teams.size(); i++) {
//         rank_frq[teams[i].second]++;
//     }
    
//     // for (int i = 1; i <= teams.size(); i++) {
//     //     cout<<i<<" "<<rank_frq[i]<<"\n";
//     // }
    
//     int i=1; //iterate over the ranks from 1 to teams_length
//     int j=1; // iterate over the frequency array of prefered ranks
    
//     int min_badness = 0;
    
//     while(i<=teams.size()){
        
//         // assign the people with higher prefered rank first
//         if(rank_frq[j]>0){
            
//             // assign this rank to a team
//             min_badness += abs(i - j);
//             // decrease the number of people competiting for this rank by 1
//             rank_frq[j]--;
//             i++; // this rank is occupied move to the next
//         }
        
//         // if some ranks are there that nobody wants then skip them
//         while(rank_frq[j]==0){
//             j++;
//         }
        
//     }
    
//     return min_badness;
// }


int main() {
	
	vector<pair<string, int>> teams;
	
	string name;
	int rank;
	
	while(cin >> name){
	    cin >> rank;
	    teams.push_back({name, rank});
	}
	
	cout<< badness(teams);
	
	return 0;
}
