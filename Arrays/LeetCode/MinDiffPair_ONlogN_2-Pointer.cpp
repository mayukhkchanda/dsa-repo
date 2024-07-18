#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

/*
Implement a function that takes in two non-empty arrays of integers,
finds the pair of numbers (one from each array) who absolute difference is closest to zero,
and returns a pair containing these two numbers, with the first number from array.
Only one such pair will exist for the test.
I/P->a={23, 5, 10, 17, 30}
     b={26, 134, 135, 14, 19}
O/P->{17,19}
*/

/* Approach:: Use the concept of 2 pointers for solving this problem.
*  
*       Sort both the array first. This is done in O(NlogN+MlogM) time cost.
*       Maintain 2 iterators starting from 0th index of each array
*       and calculate the absolute difference b/w the two elements.
*       Now, move the iterator pointing to the smaller element of the 2 to the next position.
*       This is because these arrays are sorted and moving the iterator of the bigger element 
*       will only increase the bigger element by a even more bigger element. 
*       As we are minimizing the difference, so we move the smaller element. We repeat this process 
*       until either of the array's end is reached i.e. min(m,n)
*
*    Time Complexity:: O(NlogN)+O(MlogM)+O(min(N,M)) where N->len(a) and M->len(b)
*/
pair<int,int> minDifference(vector<int> a, vector<int> b){
    
    //can be done in O(NlogN) and O(MlogM)
    sort(b.begin(), b.end()); //sort the array
    sort(a.begin(), a.end());
    
    //as we are minimizing the difference so we initialize absDiff with INT_MAX
    int absDiff = INT_MAX;
    
    int itra = 0;
    int itrb = 0;
    
    pair<int,int> minDiffPair={-1,-1};
    
    //iterate through arrays a & b from start
    while(itra<a.size() && itrb<b.size()){ //Time Complexity --> O(min(N,M))
        
        //for every element calculate their absolute difference
        if(absDiff>abs(a[itra]-b[itrb]) ){
            absDiff = abs(a[itra]-b[itrb]);
            minDiffPair = {a[itra], b[itrb]};
        }
        
        //if a[i] is smaller than b[j],where i=itra & j=itrb, then move i forward
        //else move j forward. this is because arrays are sorted and we are minimizing the difference
        if( a[itra]<b[itrb] ) {
            itra++;
        }else{
            itrb++;
        }
        
    }
    
    return minDiffPair;
}


int main() {
	vector<int> a{23, 5, 10, 17, 30};
	vector<int> b{26, 134, 135, 14, 19};
	//cout<<binarySearch(array, 17)<<"\n";
	pair<int,int> minDiffPair = minDifference(a,b);
	cout<<"Min Difference Pair::"<< minDiffPair.first<<" "<<minDiffPair.second<<"\n";
	return 0;
}
