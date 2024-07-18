#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * Question(Same Question on IB and LC):: https://leetcode.com/problems/merge-intervals/
 *                                        https://www.interviewbit.com/problems/merge-overlapping-intervals/
 * 
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and 
 * return an array of the non-overlapping intervals that cover all the intervals in the input.
 * Note:: Intervals are not sorted initially
 * Example 1:
 *   Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 *   Output: [[1,6],[8,10],[15,18]]
 *   Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * Example 2:
 *   Input: intervals = [[1,4],[4,5]]
 *   Output: [[1,5]]
 *   Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * Approach::
 *  > Sort the Intervals by their start times and if start times are equal then by their end times.
 *  > Create a new vector(let's say newIntervals) and insert {-1,-1} in it( as the 0 <= i.start <= i.end <= 10^4 as stated in the problem description).
 *  > Iterate over the Intervals array and for each Intervals check:
 *      >> If the lastly inserted Interval's end time is less than ith interval's start time. If so then we can simply add it to our newIntervals.
 *      >> Else the last inserted interval ends on or after the ith interval's starts time. Thus we merge these 2 intervals by taking the min
 *          of their start times and a max of their end times.
 * 
 * Time Complexity :: ONlogN(for sorting)+O(N)(merging intervals)
 * Space Complexity:: ON for the return list
 * 
 * */

bool comparator(vector<int> v1, vector<int> v2){
    
    // if start times are equal then sort by end times
    if(v1[0] == v2[0]){
        return v1[1] < v2[1];
    }
    // else sort by start times
    return v1[0] < v2[0];
}


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    int n = intervals.size();
    
    // sort the intervals if they are not already sorted
    sort(intervals.begin(), intervals.end(), comparator);
    
    vector<vector<int>> newIntervals;
    
    // this is for comparision as 0 <= i.start <= i.end <= 10^4 so the first
    // interval in the sorted array of intervals must be always inserted 
    newIntervals.push_back({-1,-1});
    
    for (int i = 0; i < n; i++ ) {
        
        // only need to check the lastly inserted interval 
        int lastIdx = newIntervals.size()-1;
        
        // if the ith interval starts after the last added interval ends then
        // there is no overlap and we can push this interval as it is(assuming intervals are sorted according to their start times).
        if( newIntervals[lastIdx][1] < intervals[i][0] ){
            newIntervals.push_back(intervals[i]);
        }
        // else the last added interval touches or overlaps with this ith interval
        // and we merge these 2 interval 
        else{
            newIntervals[lastIdx][0] = min( newIntervals[lastIdx][0], intervals[i][0] );
            newIntervals[lastIdx][1] = max( newIntervals[lastIdx][1], intervals[i][1] );
        }
    }
    
    // remove the {-1,-1} interval added at the beginning 
    newIntervals.erase(newIntervals.begin());
    
    return newIntervals;
}

int main() {
	
	int start;
	int end;
	vector<vector<int>> intervals;
	
	while(cin >> start >>end){
	    intervals.push_back({start, end});
	}
	
	vector<vector<int>> mergedIntervals = merge(intervals);
	
	for (auto interval : mergedIntervals) {
	    cout<< interval[0] <<" "<<interval[1]<<"\n";
	}
	
	return 0;
}
