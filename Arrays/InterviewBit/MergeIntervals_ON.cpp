#include <iostream>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/merge-intervals/
 * 
 * Given a set of non-overlapping intervals, insert a new interval into the intervals. Merge the new interval if necessary.
 * The intervals are initially sorted according to their start times.
 * 
 * Example 1:
 *   Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
 * Example 2:
 *   Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
 *   This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * Make sure the returned intervals are also sorted.
 * 
 * Approach::
 * 
 *  > Some corner cases that should be covered during interviews:
 *    1) Size of interval array as 0. Push the new interval and return the array.
 *    
 *    2) newInterval being an interval preceding all intervals in the array.
 *        Given interval (3,6),(8,10), insert and merge (1,2).
 * 
 *    3) newInterval being an interval succeeding all intervals in the array.
 *        Given interval (1,2), (3,6), insert and merge (8,10).
 * 
 *    4) newInterval not overlapping with any interval and falling in between 2 intervals in the array.
 *        Given interval (1,2), (8,10) insert and merge (3,6).
 * 
 *    5) newInterval covering all given intervals.
 *        Given interval (3, 5), (7, 9) insert and merge (1, 10).
 * */
 
 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    int n = intervals.size();
    vector<Interval> ans;
    
    // corner case 1
    if(n == 0){
        ans.push_back(newInterval);
        return ans;
    }

    // corner case 2
    if( newInterval.end < intervals[0].start){
        ans.push_back(newInterval);
        for(auto j : intervals){
            ans.push_back(j);
        }
        return ans;
    }

    // corner case 3
    if(intervals[n-1].end < newInterval.start){
        ans.assign(intervals.begin(), intervals.end());
        ans.push_back(newInterval);
        return ans;
    }
    
    // corner case 5
    if(  newInterval.start<=intervals[0].start && intervals[n-1].end<=newInterval.end){
        return {newInterval};
    }
    
    
    /**
     * The following code is generalized and does not need any extra cases to be covered.
     * But in interviews covering the corner cases is a priority. Thus to make the code verbose and
     * better understandin it has been kept there.
     * */

    int j=0;
    
    // push all intervals that end before the newInterval starts. (we donot consider the interval 
    // that starts when the new interval starts then these intervals should be merged)
    while( j<n && intervals[j].end < newInterval.start){
        ans.push_back(intervals[j]);
        j++;
    }

    // if newInterval starts after all intervals end then
    // the new interval will be the last interval
    if(j == n){
        ans.push_back(newInterval);
        return ans;
    }

    // if the new interval does overlaps or touches the jth interval
    // i.e it ends on or after the jth interval starts only then
    // these intervals will be merged. This handles the corner case #4.
    if( newInterval.end >= intervals[j].start ){
        // else the jth interval overlaps or touches the newInterval
        newInterval.start = min(intervals[j].start, newInterval.start);

        // while the new interval ends after any interval starts then
        // the newInterval overlaps with them
        while( j<n-1 && newInterval.end >= intervals[j+1].start ){
            j++;
        }

        // take the maximum end time of the over-lapping intervals
        // and add it to out ans
        newInterval.end = max(newInterval.end, intervals[j].end);
    }
    // else the new interval ends before the jth interval starts
    // as we will start push the intervals from j+1 hence we decrease j.
    // See corner case #4.
    else{
        j--;
    }
    
    // push the new interval
    ans.push_back(newInterval);

    // push the remaining intervals from (j+1)the interval if any
    j+=1;
    while( j<n ){
        ans.push_back(intervals[j]);
        j++;
    }

    return ans;
}
int main() {
	//need to create Interval objects before calling funcion.
	return 0;
}
