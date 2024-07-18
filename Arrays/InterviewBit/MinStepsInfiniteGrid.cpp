/**
Question: https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

You are in an infinite 2D grid where you can move in any of the 8 directions:
(x,y) to (x-1, y-1), (x-1, y)  , (x-1, y+1), (x  , y-1),(x  , y+1), (x+1, y-1), (x+1, y)  , (x+1, y+1) .
You are given a sequence of points and the order in which you need to cover the points.
Give the minimum number of steps in which you can achieve it. You start from the first point.

Example Input
    Input 1:
    A = [0, 1, 1]
    B = [0, 1, 2]
Example Output
    Output 1:
    2

Example Explanation
    Explanation 1:
    Given three points are: (0, 0), (1, 1) and (1, 2).
    It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int minSteps = 0;
    
    //we take the difference of both abs(x1-x2) & abs(y1-y2) 
    //if both are equal then we move along the diagonal
    //if both are not equal,we would move diagonally so long as both 
    //of them are positive. Once one of them is negative
    //we would move only in the positive direction only untill
    //it becomes 0, so #steps from 1 to 2 would be max(abs(x1-x2) & abs(y1-y2) )
    for(int i=1; i<A.size() ;i++){

      minSteps += max( abs(A[i]-A[i-1]),abs(B[i]-B[i-1]) );
      
    }
    
    return minSteps;
}
