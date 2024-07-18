#include <iostream>
#include <vector>

using namespace std;

/**
 * Question::https://leetcode.com/problems/search-a-2d-matrix/
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties::
 * 
 *  Integers in each row are sorted from left to right. 
 *  The first integer of each row is greater than the last integer of the previous row.
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * Approach:: Treat whole matrix as an array and perform binary search.
 * 
 * See explanation:: https://leetcode.com/problems/search-a-2d-matrix/discuss/26220/Don't-treat-it-as-a-2D-matrix-just-treat-it-as-a-sorted-list
 * 
 * If we have a matrix with m*n elements and we number them according to array indices 0 to n*m-1 then, the element at index X can be given by:
 *  
 *  X/cols -> row and X%cols -> col in the matrix both are based on 0-indexes. 
 * 
 * */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int start = 0;
    int end   = rows * cols - 1;
    
    int mid;
    
    while(start <= end){
        
        mid = start + (end-start)/2;
        
        if( matrix[mid/cols][mid%cols] == target ){
            return true;
        }
        
        if( matrix[mid/cols][mid%cols] > target ){
            end = mid-1;
        }
        
        else{
            start = mid+1;
        }
        
    }
    
    return false;
}

int main() {
	// your code goes here
	return 0;
}
