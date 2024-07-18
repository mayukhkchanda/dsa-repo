#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given the start and finish times of activities, print the maximum number of activities that can be completed.
Input is already store in a vector of pairs. Each pair contains the start and end of the activity.

Refer CLRS-Page-414 for detailed explanation
*/

//Sort the array of pairs by their finish times i.e. 2nd index.
//once sorted, we can now consider the activity which has the fastest finish time and include it to our set of activities
//now the sub-problem size reduces to n-1. We can repeat this process for each element.
//Although, after selecting an activity we must consider the activity that starts after the included activity finishes and
//that has the fastest finish times(this is taken care of when we sorted the array)

// sort array by second element of the array
bool pairSorter(pair<int,int>& a, pair<int,int> &b){
    return (a.second < b.second);
}

//Time complexity --> O(NlogN) for sorting(N is the size of the array) + O(N) for iterating over the array
int countActivites(vector<pair<int,int>> activityTimes){
    
    //sort the vector array of pairs by the second element in increasing order
    sort(activityTimes.begin(), activityTimes.end(), pairSorter);
    
    //initially we have no activity so we start with an imaginary pair that ends at 0 
    //this allows us to compare finish times
    vector<pair<int,int>> selection{{-1,0}};
    
    //iterate through the sorted array of activity times
    //as the these are sorted in the increasing order of activity's finish times
    //we can take a greedy approach and select the pair which has the fastest finish time and that starts after the 
    //last selected activity ends
    for (int i=0; i<activityTimes.size() ; i++) {
        
        //if the last selected activity finished on or before the next activity in the activityTimes vector starts
        //then, we can include this activity as we are gauranteed that activityTimes[i] has the fastest finish time after
        //activityTimes[i-1]
        if( selection[selection.size()-1].second <= activityTimes[i].first ){
            selection.push_back(activityTimes[i]);
        }
        
    }
        
    return selection.size()-1;
    
}


int main() {
	vector<pair<int,int>> activityTimes{{7,9}, {0,10}, {4,5}, {8,9}, {4,10}, {5,7}};
	cout<<countActivites(activityTimes)<<"\n";
	return 0;
}
