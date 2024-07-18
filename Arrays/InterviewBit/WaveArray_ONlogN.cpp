#include <iostream>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/wave-array/
 * 
 * Given an array of integers A, sort the array into a wave like array and return it, In other words, 
 * arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
 * NOTE : If there are multiple answers possible, return the one that's lexicographically smallest.
 * 
 * Example Input
 *   Input 1:
 *   A = [1, 2, 3, 4]
 *   Input 2:
 *   A = [1, 2]
 * 
 * Example Output
 *   Output 1:
 *   [2, 1, 4, 3]
 *   Output 2:
 *   [2, 1]
 * 
 * 
 * Example Explanation
 * Explanation 1:
 *   One possible answer : [2, 1, 4, 3]
 *   Another possible answer : [4, 1, 3, 2]
 *   First answer is lexicographically smallest. So, return [2, 1, 4, 3].
 * Explanation 1:
 *   Only possible answer is [2, 1].
 * */

vector<int> wave(vector<int> &A) {

    int n= A.size();

    sort(A.begin(), A.end());

    for(int i=0; i<n-1; i++){

        // swap i with i+1 at every even index
        if(i%2 == 0){
            swap(A[i],A[i+1]);
        }
    }

    return A;
}


int main() {
	vector<int> arr;
	int temp;
	while(cin >> temp){
	    arr.push_back(temp);
	}
	vector<int> wavedArr = wave(arr);
	for (auto i : wavedArr) {
	    cout<<i<<" ";
	}
	return 0;
}
