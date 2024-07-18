#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * Question:: IB-> https://www.interviewbit.com/problems/find-permutation/
 *            LC-> Permium
 * Given a positive integer n and a string s consisting only of letters D or I, you have to 
 * find any permutation of first n positive integer that satisfy the given input string.
 * D means the next number is smaller, while I means the next number is greater.
 * 
 * Notes;
 *   > Length of given string s will always equal to n - 1
 *   > Your solution should run in linear time and space.
 * Example :
 * Input 1:
 *   n = 3
 *   s = ID
 *   Return: [1, 3, 2]
 * 
 * Input 2:
 *   n = 6
 *   s = DIDDI
 *   Return: [6,1,5,4,2,3]
 * 
 * Intuition::
 *  > Keep an available range of element [l,r]. Initially, l=1 and r=n.
 *    You always need to select smallest or largest element from available range. 
 *    Try to figure out how and when.
 * 
 * Approach::
 *  > When the input string contains only D or I we just need to return all positive
 *    number upto n either in descending or ascending orders respectively. So if n = 3, s = “II”, return [1, 2, 3]
 *   
 *  > Now, starting with each character of the input string, we need to substitute an 
 *    appropriate number(from 1 to n) corresponding to each character(I or D).
 *    So, Suppose we started with a set corresponding to all the elements from that
 *    we need to make permutation(i.e all integer from 1 to n).  As I denotes the next number should
 *    be larger, we need to substitute smallest remaining number from our set corresponding
 *    to subsequent I as it automatically makes the next element to be larger.
 *   
 *  > Similar things will happens with character D, we need to substitute the largest remaining number from our set.
 *   
 *  > As the input string size is n - 1, we need to append the last integer to our answer.
 * 
 * */

vector<int> findPerm(string pattern, int n) {
    
    vector<int> permutation(n);
    
    int small = 1;
    int large = n;
    
    int itr = 0;
    
    while(small < large){
        if(pattern[itr] == 'D'){
            permutation[itr] = large;
            large--;
        }else if(pattern[itr] == 'I'){
            permutation[itr] = small;
            small++;
        }
        itr++;
    }
    
    permutation[itr] = small;
    
    return permutation;
}



int main() {
    int n;
    cin >> n;
	string pattern;
// 	getline(cin, pattern);
    cin >> pattern;
	
	vector<int> permutation = findPerm(pattern, n);
	
	for (auto i : permutation) {
	    cout<<i<<" ";
	}
	
	return 0;
}
