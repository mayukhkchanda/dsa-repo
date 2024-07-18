#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    Question-> https://practice.geeksforgeeks.org/problems/minimum-swaps/1#
    Given an array of n distinct elements. Find the minimum number of swaps 
    required to sort the array in strictly increasing order.
    Input:
    nums = {10, 19, 6, 3, 5}
    Output:
    2
    Explaination:
    swap 10 with 3 and swap 19 with 5.
*/

//time complexity is O(NlogN)+O(N) and Space complexity is 2*O(N) =>O(N) for an unordered_map & an extra array

//To optimise for minimum number of swaps, we first need to find the correct position of the elements, thus sort the array.
//Once the array is sorted we can iterate over the sorted array and compare each elements with unsorted array.
//If an element doesnot match, we find the correct element's(element in sorted array) index in the unsorted array(!!NOTE!! we maintain two arrays one is sorted and other is unsorted).
//To find the index of correct element(as in the sorted array) in unsorted array in O(1) time, we use an unordered_map of elements and element's respective indexes(will not work if duplicate elements are there).
//Once we find the position of the correct element in the unsorted array, we swap them(un-matched element and correct element) and also change their respective indexes mapping in the unordered_map.
//We continue this for each element in unsorted array until end of array, while increasing the minSwaps count.
int minSwaps(vector<int> &array){
    vector<int> array_sorted; //we need to maintain an unsorted array of elements
    unordered_map<int,int> map; //O(N) space cost
    
    //array_sorted.assign(array.begin(), array.end()); //short-hand copying-still takes O(N)
    
    for(int i=0; i<array.size() ;i++){ // for mapping array elements and their indexes
        map.insert({array[i], i});
        
        array_sorted.push_back(array[i]);
    }

    //sort the array -> O(NlogN) time cost
    sort(array_sorted.begin(), array_sorted.end());
    
    //iterate over the sorted array and compare with each of the element in the unsorted array
    //if an element is not at its correct place then in the original array then 
    //find the index of the correct element in the unsorted array(O(N)) and swap it(O(1)) with the element in crct index
    //also swap their mappings in unordered_map
    int countSwaps = 0;
    
    for (int i = 0; i < array_sorted.size()-1 ; i++) {
        
        //compare sorted and unsorted array elements
        if(array[i] != array_sorted[i]){
            
            //find the index of the element in the unsorted array that was supposed to be at i in sorted array
            int indexToSwap = map[array_sorted[i]]; 
            
            //swap the two elements and increment #swaps
            swap(array[i], array[indexToSwap]);
            
            //change the indexes of swapped elements in hash map
            map[array[i]]= i;
            map[array[indexToSwap]]=indexToSwap;
            
            //for (auto i : array) { //un-comment this to see the algorithm in action
            //    cout<<i<<" ";
            //}
            //cout<<"\n";
            countSwaps++;
        }
        
    }
    
    return countSwaps;
}


int main() {
    //vector<int> array{10,11,5,4,3,2,1};
    vector<int> array{7,16,14,17,6,9,5,3,18};
    cout<<"\n"<<minSwaps(array)<<"\n";
    
	return 0;
}
