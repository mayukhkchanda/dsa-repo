#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
Given an array of n distinct elements. 
Find the minimum number of swaps required to 
sort the array in strictly increasing order.
Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Question:= https://practice.geeksforgeeks.org/problems/minimum-swaps/1#
*/

//to optimise for the minimum # of swaps, we first need to know the correct position of each element.
//For this we keep a vector of pairs for each element in the array with the element and its index as a pair.
//We sort this vector of pairs by the first element i.e. the element of the array.
//We iterate through each pair in the vector and check if the pair at this index is visited or not.
//If the element is not visited then we start a cycle from this index.
//To start a cycle, we store the current pair in startOfCycle and a walker variable assigned to startOfCycle and follow the below steps, 
//  1.go to pair at the old index of the walker element(this is stored in the second element of the pair) and mark it visited
//  2.keep doing step 1 until we reach the startOfCycle or to an index where we already visited.
//  Once we are out of the loop we calculate the minSwaps need to put all the elements of this cycle in place i.e (#elements in the cycle - 1)
//  this is because to sort a cycle of n elements minSwaps needed is n-1
//  we sum minSwaps for each of such element and output the result
int minSwaps(vector<int> &array){ // time complexity is O(N)+O(NlogN) as we visit each element only once and mark it visited henceforth not visiting the array again
    vector<pair<int,int>> eleIndxPair; // space complexity is O(N)
    
    //store the element and it's index in a vector of pairs
    for (int i = 0; i < array.size(); i++) {
        eleIndxPair.push_back(make_pair(array[i],i));
    }
    
    //sort the vector of pairs by its first element
    sort(eleIndxPair.begin(), eleIndxPair.end());
    
    //iterate through the pairs in the vector
    //for each pair -> start a cycle from the element at this index
    //1.mark it visted in the visited array
    //2.go to the pair located in the old index of this pair
    //3.repeat the process 1 & 2 till the start of the cycle is reached or we reach an index that's already visited
    //after a cycle completes count the #swaps = #elements-1
    
    vector<bool> visited(array.size(), false); //boolean array visited
    
    int minSwaps = 0;
    
    for (int i = 0; i < eleIndxPair.size(); i++) {
        //if this index is not yet visited
        if(!visited[i]){
            //start a cycle from this index
            pair<int,int> startOfCycle = eleIndxPair[i];
            visited[i] = true;
            
            pair<int,int> walker = startOfCycle;
            
            int countOfNodes = 0;
            
            //keep walking till start of cycle is reached
            do{
                // cout<<walker.first<<" "<<walker.second<<"\n";
                //mark the next element in the cycle as visited
                visited[walker.second] = true;
                //move to the next element
                walker = eleIndxPair[walker.second];
                countOfNodes++;
            }while(walker.first != startOfCycle.first); //incase the elements are not-distinct, then keep walking till visited[walker.second]!=true
                                                        //this is because as we are moving ahead in the cycle to new nodes we mark them visited
                                                        //once we get to an element thats visited previously we know that we reached start of cycle
            
            //  number of swaps needed will be number of elements - 1
            minSwaps+=countOfNodes-1;
        }
    }
    
    return minSwaps;
}


int main() {
	vector<int> array{7,16,14,17,6,9,5,3,18};
	cout<<minSwaps(array)<<"\n";
	return 0;
}
