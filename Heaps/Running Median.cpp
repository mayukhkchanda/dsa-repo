// https://leetcode.com/problems/find-median-from-data-stream/
// https://www.hackerrank.com/challenges/find-the-running-median/problem
// https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

/**
 *  As we keep encountering numbers, the new median either shift either to the left of the 
 *  current median or to the right of the current median.
 * 
 *  Eg : case 1:
 *      1 2 5  <<- 6 8    =>>  1 2 5 6 8
 *      Cur_medain=2          New_median = 5   ::  as the numbers add to the data stream were larger than the
 *                                                  current median, the new median shifts to the right and becomes
 *                                                  the next larger element to the right of the current median
 *      
 *      case 2:
 *      1 2 5  <<- -1 0   =>>  -1 0 1 2 5
 *      Cur_medain=2          New_median = 1   ::  as the numbers add to the data stream were smaller than the
 *                                                  current median, the new median shifts to the left and becomes
 *                                                  the previous smaller element to the left of the current median
 * 
 *  We maintain a minHeap and a maxHeap, then if a number is smaller than the current median
 *  we put it in the maxHeap and numbers larger than median are put inside the minHeap.
 *  At each point of the insertion, we check if the difference in # of elements of the 2 heaps
 *  is atmost 1. For this, we shift 1 element from the larger heap to the smaller heap.
 * 
 * */


vector<double> runningMedian(vector<int> a) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0;
    
    vector<double> res;
    
    for(int num : a){
    
        double dNum = (double) num;
        
        if( dNum < median ){
            // num goes to the left half of the median i.e. in max-heap
            
            if( maxHeap.size() > minHeap.size() ){
                // if the max heap size is greater then we transfer the top element from
                // the maxHeap to the minHeap.
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            
            maxHeap.push(num);
        }else{
            // num goes to the right half of the median i.e. in min-heap
            
            if( minHeap.size() > maxHeap.size() ){
                // if the min heap size is greater then we transfer the top element from
                // the minHeap to the maxHeap.
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            minHeap.push(num);
        }
        
        // calculate the median by checking the heap sizes :
        // 1. if both heaps have equal size then median is the avg of the top elements of the 2 heaps
        // 2. else median is the top element of the larger heap(in terms of # of elements)
        int diff = minHeap.size()-maxHeap.size();
        
        if(diff==0){
            median = ((double)(minHeap.top()+maxHeap.top())/2.0);
        }
        else if(diff==1){
            median = minHeap.top();
        }
        else{
            median = maxHeap.top();
        }
        
        res.push_back(median);   
    }
    return res;
}

