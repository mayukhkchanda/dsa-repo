#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * 
 * 
 * Let's say num1 = [1,2,4] -> len(num1) = m=3   &  num2 = [3,5,6,7] -> len(nums2) = n=4
 * 
 * Merging the arrays ==> [1,2,3,4,5,6,7]
 *             left part<==+---+ ^ +---+==> Right part
 *                               |--Median  
 * 
 * For convience, we will consider the median in the left when odd number 
 * of elements are there.
 * 
 * Thus the length of the merged array becomes m+n. The length of left part in the merged array is (m+n+1)/2,
 * that is there are (m+n+1)/2 elements in the left part.
 * 
 * Now if we parition the smaller array into 2 parts by the middle index i.e. (low+high)/2 = mid,
 * where initially low = 0 and high = m-1 then, we can say that we have mid # of elements of the  
 * left part of the merged array. And from the second array nums2 we only need (m+n+1)/2 - mid # of elements.
 * 
 *  [1,2,4]
 *   ^ ^ -> nums1 array's left part of merged array
 *  [3,5,6,7]
 *   ^ ^ -> nums2 array's left part of merged array
 * 
 * Now If this partition is correct partion for a median then we would have "all elements in left part" <= "all elements in right part"
 * of the merged array. For this 3 condition exists:
 * 
 * 
 * > !!NOTE:: The arrays are sorted so max element in left part of nums1 < min element in right part of nums1 is gauranteed. Same for nums2!!
 * 
 * 1. max element in left part of nums1 > min element in right part of nums2::
 *      > there are larger elements in left part of nums1 and so any index after mid wont work.
 *          Thus, shift the parition to the left.
 * 
 * 
 * 2. max element in left part of nums2 > min element in right part of nums1::
 *      > there are larger elements in the left part of nums2 and we should move parition in nums1
 *          towards the right side.
 * 
 * 3. else all elements in the left part of nums1 & nums2 <= all elements in right part of nums1 & nums2.
 *      If m+n is::
 *          > ODD:: return the max of maximum element in left part of nums1 and nums2.
 *          > EVEN:: reurn the average of max of maximum element in left part of nums1 and nums2 and min of minimum element in right part of nums1 and nums2
 * */


double findMedianSortedArrays(vector<int> nums1, vector<int> nums2){
    
    int m = nums1.size(); // nums1 is always smaller than nums2
    int n = nums2.size();
    
    // all partitions on the smaller array can be a valid partition for median.
    // But the paritions that are too far away might not be valid paritions.
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    
    int low = 0;
    int high = m;
    
    int midInMergedArray = (m+n+1)/2; // we also take median in the left part when m+n is odd
    
    while(low <= high){
        
        int cut1 = low + (high - low)/2;
        int cut2 = midInMergedArray - cut1;
        
        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
        int right1 = cut1 == m ? INT_MAX : nums1[cut1];
        
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
        int right2 = cut2== n ? INT_MAX : nums[cut2];
        
        
        if(left1 > right2){
            high = mid-1;
        }
        else if(left2 > right1){
            low = mid+1;
        }
        else{
            
            if( (m+n)%2 != 0 ){
                return (double)max(left1, left2);
            }else{
                return (double) ( max(left1, left2) + min(right1, right2) ) / (double)2;
            }
            
        }
    }
    
    return 0.0;
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
