/**
Question:: https://leetcode.com/problems/maximum-gap/
           https://www.interviewbit.com/problems/maximum-consecutive-gap/

Given an integer array nums, return the maximum difference between two successive 
elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:
    Input: nums = [3,6,9,1]
    Output: 3
    Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:
    Input: nums = [10]
    Output: 0
    Explanation: The array contains less than 2 elements, therefore return 0.

Bucketing and Bucket Sort:
    > https://leetcode.com/problems/maximum-gap/discuss/50643/bucket-sort-JAVA-solution-with-explanation-O(N)-time-and-space/51216
    > https://www.geeksforgeeks.org/bucket-sort-2/

Solution Explanation: 
    > Comment -> https://leetcode.com/problems/maximum-gap/discuss/50643/bucket-sort-JAVA-solution-with-explanation-O(N)-time-and-space/200059
    > https://leetcode.com/problems/maximum-gap/discuss/1241681/JavaPython-Bucket-Idea-with-Picture-Clean-and-Concise-O(N)
    > https://leetcode.com/problems/maximum-gap/discuss/1240543/Python-Bucket-sort-explained

*/

int maximumGap(vector<int>& nums) {

    int n = nums.size();

    // when only 2 numbers are there, return their absolute difference
    if(n <= 2){
        return n==2? abs(nums[0]-nums[1]) : 0;
    }

    int Min = INT_MAX;
    int Max = INT_MIN;

    for (auto i : nums) {
        Min = min(Min, i);
        Max = max(Max, i);
    }

    // if min == max then all numbers are same and the max gap is 0
    if(Min == Max){
        return 0;
    }

    // Else if all numbers are not same, then we take the difference of max and min in the array
    // and design our bucket size such that the maximum gap cannot occur in the same bucket.
    // Thus as the maximum difference in the array is Max-Min and there are more than 2 elements
    // so if the bucket size is greater than or equal to Max-Min/n-1 then we would have the max gap 
    // b/w any 2 non-empty buckets.
    int min_gap = ceil( (float)(Max-Min)/(float)(n-1) );
    
    int bucket_size = (Max-Min)/(min_gap);
    
    // only consider tha max and min in a bucket
    vector<int> bucketMin(bucket_size+1, INT_MAX);
    vector<int> bucketMax(bucket_size+1, INT_MIN);

    for (int i = 0; i < n; i++) {
        // get the index of the bucket where this number falls
        int bucketIndx = (nums[i]-Min)/min_gap;

        // initialize max and min in the array
        bucketMin[bucketIndx] = min(bucketMin[bucketIndx], nums[i]);
        bucketMax[bucketIndx] = max(bucketMax[bucketIndx], nums[i]);
    }

    int maxDiff = INT_MIN;
    int previous = Min;

    for (int i = 0; i < bucketMax.size(); i++) {

        // if this bucket was not initialised, then skip it
        if(bucketMax[i] == INT_MIN){
            continue;
        }

        // else we take the maximum difference of the previous bucket and the minimum of this bucket
        maxDiff = max(bucketMin[i]-previous, maxDiff);
        previous = bucketMax[i];
    }

    return maxDiff;
}
