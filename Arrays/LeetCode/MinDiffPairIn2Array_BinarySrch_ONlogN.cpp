#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

/*
https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/

Implement a function that takes in two non-empty arrays of integers,
finds the pair of numbers (one from each array) who absolute difference is closest to zero,
and returns a pair containing these two numbers, with the first number from array.
Only one such pair will exist for the test.
I/P->a={23, 5, 10, 17, 30}
     b={26, 134, 135, 14, 19}
O/P->{17,19}
*/

/**Cloest element in a vector to a target element.
https://www.geeksforgeeks.org/find-closest-number-array/
*/

int getClosestElement(int target, int num1, int num2){//here num1<target<num2
    return target-num1 < num2-target ? num1 : num2;
}

//returns the matching element or the element closest to the target element
int binarySearch(vector<int> &array, int target){
    // sort(array.begin(), array.end()); --> vector b is already sort for this program/question
    
    //Extreme cases when target is smaller than the smallest element OR greater than the 
    //largest element in the array.
    if(target<=array[0]) return array[0];
    if(target>=array[array.size()-1]) return array[array.size()-1];
    
    int low=0;
    int high=array.size()-1;
    
    int mid = -1;
    
    while(low<=high){ //if we terminate at low<high then mid wont get updated and we are returning mid
        
        mid = low + (high-low)/2;
        
        if(array[mid] == target){
            //found the value, no need to iterate any more
            break;
        }
        else if(target<array[mid]){
            //if target>array[mid-1] then return the cloest element b/w array[mid] and array[mid-1]
            if(target>array[mid-1]) return getClosestElement(target,array[mid-1],array[mid]);
            
            //else look for target element in left array
            high = mid-1;
        }
        else{//target is > array[mid]

            //if target<array[mid+1] then return the cloest element b/w array[mid] and array[mid+1]
            if(target<array[mid+1]) return getClosestElement(target,array[mid],array[mid+1]);
            
            //else look for target element in right array
            low = mid+1;
        }
        
    }
    return array[mid];
}


//Approach :: For every element a[i] in a, we find it's closest element in b, take the absolute difference-
//- and store the minimum difference pair of them all.
//For finding the cloest element we use binary search on b, for which we sort b.
//Hence iterating over a is O(len(a)) and binary search on b for a[i] is O(log(len(b))).
//Thus time complexity is O(len(a)*log(len(b))) and O( len(b) * log((len(b)) ) for sorting the vector b.
pair<int,int> minDifference(vector<int> a,vector<int> b){
    sort(b.begin(), b.end()); //sort the b vector
    
    int absDiff = INT_MAX;
    
    pair<int,int> minDiffPair = {0,0};
    
    for (int i=0; i<a.size() ;i++) { //O(N) - time cost
        
        int closestEl = binarySearch(b,a[i]); //O(logM) - time cost
        
        if(abs(closestEl-a[i])<absDiff){
            absDiff = abs(closestEl-a[i]);
            
            minDiffPair = make_pair(a[i],closestEl);
        }
        
    }
    return minDiffPair;
}


int main() {
	vector<int> b{23, 5, 10, 17, 30};
	vector<int> a{26, 134, 135, 14, 19};
	//cout<<binarySearch(array, 17)<<"\n";
	pair<int,int> minDiffPair = minDifference(a,b);
	cout<<"Min Difference Pair"<< minDiffPair.first<<" "<<minDiffPair.second<<"\n";
	return 0;
}
