#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

/**
 * Question:: https://www.spoj.com/problems/BAISED/cstart=10

 * Problem specification::
 *   Given team names and their preferred placements find one ranklist with the minimal possible badness.
 *   
 *   During the registration each team will be able to enter a single positive integer : their preferred place in the ranklist. 
 *   We would take all these preferences into account, and at the end of the competition we will simply announce a ranklist that 
 *   would please all of you.
 *   
 *   Suppose that we already have a ranklist. For each team, compute the distance between their preferred place and their place in 
 *   the ranklist. The sum of these distances will be called the badness of this ranklist.
 * 
 * Input specification::
 *   The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.
 *   Each test case looks as follows: The first line contains N : the number of teams participating in the competition. 
 *   Each of the next N lines contains a team name (a string of letters and numbers) and its preferred place (an integer between 1 and N,
 *   inclusive). No two team names will be equal.
 * 
 * Output specification
 *   For each of the test cases output a single line with a single integer : the badness of the best ranklist for the given teams.
 * 
 * Input:
 * 2
 *
 * 7
 * noobz 1
 * llamas 2
 * Winn3rz 2
 * 5thwheel 1
 * NotoricCoders 5
 * StrangeCase 7
 * WhoKnows 7
 * 
 * 3
 * ThreeHeadedMonkey 1
 * MoscowSUx13 1
 * NeedForSuccess 1
 * 
 * Output:
 * 5
 * 3
 *
 * Approach:: 
 *     > O(NlogN) :: Sort the teams array by their prefered rank and then calculate the difference between their current
 *                     ranking and their preferred rank. This is the minimum badness
 * 
 *     > O(N) :: 
 *         >> Calculate the frequency of the teams based on their prefered rank. 
 *         >> Iterate over the teams length that is the number of teams(No need to iterate over the teams array).
 *             Now based on the calculated rank frequency assign teams rank from 1 to N. The ones whose prefered rank is higher
 *             should get higher rank than the ones whose prefered rank is lower. If more than 1 team wants the same rank then
 *             assign them sequentially(i.e. 1 after the other). It doesnot matter which team we assign higher rank in case of
 *             a collision as the absolute difference will be the same.
 *         >> We take the sum of all those difference and this is our minimum badness
 * 
 * 
 */

int badness(vector<pair<string,int>> teams){
    
    // rankings are 1-based and we will store frequency of rankings
    int rank_frq[teams.size()+1] = {0};
    
    // calculate the frequency of rankings
    for (int i = 0; i < teams.size(); i++) {
        rank_frq[teams[i].second]++;
    }
        
    int i=1; //iterate over the ranks from 1 to teams_length
    int j=1; // iterate over the frequency array of prefered ranks
    
    int min_badness = 0;
    
    while(i<=teams.size()){
        
        // assign the people with higher prefered rank first
        if(rank_frq[j]>0){
            
            // assign this rank to a team who selected higher rank first 
            // and take the difference between them
            min_badness += abs(i - j);
            // decrease the number of people competiting for this rank by 1
            rank_frq[j]--;
            i++; // this rank is occupied move to the next
        }
        
        // if number of people competiting for this rank is 0 then skip this rank
        while(rank_frq[j]==0){
            j++;
        }
        
    }
    
    return min_badness;
}


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
