/**
 * Question: https://www.interviewbit.com/problems/profit-maximisation/
 * 
 * Solution & Explaination: https://www.geeksforgeeks.org/maximize-the-profit-after-selling-the-tickets/
 * 
 * Algo:
 *  1. Start by selling the tickets to the row with highest vacant seats. Selling a ticket decreases the vacant
 *      seats in that row by 1.
 *  2. Find the new row with highest vacant seats, if the after selling a ticket from the current row the
 *      number of seats is still greater than any other row. Then, continue with the current row. Else, get
 *      the row with highest seats.
 * 
 */
 
int Solution::solve(vector<int> &seats, int k) {
    
    // use a max heap to get the max vacant row in O(1) time
    priority_queue<int> maxHeap;
    for(int i : seats) maxHeap.push(i);

    // get the row with highest # of vacant seats and remove it from heap 
    int currRow = maxHeap.top();
    maxHeap.pop();

    // store the total cost
    int total = 0;

    while(k > 0 ){
        
        // if the # of seats is less than the # of people then break
        if(currRow == 0 && maxHeap.top() == 0){
            break;
        }
        
        // if we have sold a ticket from the current row, then we need to check if the
        // current row still has the highest number of seats
        if(maxHeap.top() > currRow){
            // if it does not has the highest number of seats, then push the current row
            // into heap and get the max-row into the currRow var
            maxHeap.push(currRow);
            currRow = maxHeap.top();
            maxHeap.pop();            
        }
        
        // add the current seat cost to the total cost and decrease the # of vacant seats in the
        // current row by 1
        total += currRow--;
        k--;
    }

    return  k == 0 ? total : -1;
}
