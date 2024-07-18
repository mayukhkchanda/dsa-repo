#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * Question: https://leetcode.com/problems/median-of-two-sorted-arrays
 * 
 * Detailed Explanation:
 * > https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
 * 
 * */

double findMedianUtil(vector<int>& nums1, vector<int>& nums2){
    
    // n1 <= n2 always
    int n1 = nums1.size();
    int n2 = nums2.size();
    
    
    // pick a cut position on the shorter array. As there are 2*n1+1
    // positions in the first array. Hence left and right are 0 & 2*n1(0-based index)
    int low = 0;
    int high = 2*n1;
    
    // try finding the cut position of longer array
    // when knowing the cut position of shorter array
    while(low <= high){
        
        int cut1 = low + (high - low)/2; // pick a random position to cut the shorter array
        int cut2 = n1 + n2 - cut1; // as equal # cut positions should be their on each side of the cut 
                                   // i.e. n1+n2 thus cut1 + cut2 = n1+n2
                                 
        // left and right are elements adjacent to the cut(if the cut is in the gap) towards left and right  
        // If the cut is on an element, then left and right both are the cut element.
        int left1 = cut1 == 0 ? INT_MIN :  nums1[(cut1-1)/2];
        int right1 = cut1 == 2*n1 ? INT_MAX : nums1[cut1/2];
        
        int left2 = cut2 == 0 ? INT_MIN :  nums2[(cut2-1)/2];
        int right2 = cut2 == 2*n2 ? INT_MAX : nums2[cut2/2];
        
        // as arrays are sorted thus left1 <= right1 is gauranteed. And if left1 > right2 then there are
        // larger elements in the left part. Thus, move the cut position on array 1 to the left.
        if(left1 > right2){
            high = cut1 - 1;
        }
        // if left2 > right1 then left part of array 2 has larger elements and thus shift the cut position
        // on array 2 to the left. As cut position on array1 and array2 move in opposites to each other,
        // hence we move cut position on array 1 to the right.
        else if( left2 > right1 ){
            low = cut1 + 1;
        }
        // we have made the cut on the right position
        else{
            return (float)(max(left1, left2) + min(right1, right2))/(float)2;
        }
    }
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int n1 = nums1.size();
    int n2 = nums2.size();
    
    
    if(n1 <= n2){
       return findMedianUtil(nums1, nums2);
    }

    return findMedianUtil(nums2, nums1);
}


int main() {
	
	vector<int> nums1;
	vector<int> nums2;
	string str;
	int temp;
	
	
	getline(cin, str);
	stringstream ss(str);
	while(ss >> temp){
	    nums1.push_back(temp);
	}
	
	getline(cin, str);
	stringstream ss1(str);
	while(ss1 >> temp){
	    nums2.push_back(temp);
	}
	
	cout<< findMedianSortedArrays(nums1, nums2);
	
	return 0;
}
