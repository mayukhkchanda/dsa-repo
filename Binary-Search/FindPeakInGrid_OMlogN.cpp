#include <iostream>
#include <vector>
using namespace std;


/**
 * Question:: https://leetcode.com/problems/find-a-peak-element-ii/
 * 
 * Description::
 *   A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
 *   Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
 *   You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
 *   You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
 * 
 * Example 1::
 *   Input: mat = [[1,4],[3,2]]
 *   Output: [0,1]
 *   Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
 * Example 2::
 *   Input: mat = [[7,2,3,1,2],[6,5,4,2,1]]
 *   Output: [0,0]
 * 
 * Explained Solution:: https://leetcode.com/problems/find-a-peak-element-ii/discuss/1276556/JavaPythonC%2B%2B-Clear-Explanation-with-Images-or-M*Log(N)-or-Very-Short-code
 * 
 * Intuition:: 
 *  >> If the maximum element in any column is smaller than the element to the right then we are sure that this column cannot contain the pealk.
 *      Else we can say that either peak lies in this column or to the left of this column
 * 
 * Approach::
 *  > This problems is similar to finding peak in 1D array(https://leetcode.com/problems/find-peak-element/).
 *  > Only difference here is we are trying to converge to the peak element's column in every iteration.
 *  > In every iteration::
 *      >> we first calculate the mid column and find the maximum element's row number(starts from 0) in that column.
 *      >> we then check the right element of this maximum row element. If this is smaller then mid_col cannot have the peak element
 *          and we trim our search space to mid_col+1 to right_col. Else either mid_col contains a peak element or it is the increasing slope,
 *          hence we trim our search space to left_col to mid_col. 
 *          !!NOTE:: Above process is similar to finding peak in 1D array and same arguments can be used to show why this works in 2D array also.!!
 *      >> After the loop ends, both left_col and right_col points to the peak element's column and we can find the maximum row in this column in O(rows) time.
 * 
 * Time Complexity:: In each iteration we decrease our search space to half of #cols of our current search space and finding maximum
 *                      in the mid_col takes O(cols) time. Hence, the time Complexity is O(log(cols) * rows) i.e. O(MlogN)(M->rows && N->cols)
 * 
 * 
 * */


// returns index of maximum element in the column 'col'
 int findMaxRow(vector<vector<int>> &matrix, int col){
    
    int rows = matrix.size();
    
    int max_row = 0;
    
    for (int i = 0; i < rows; i++) {
        // find the index of the maximum element's row number(starts from  0)
        max_row = matrix[max_row][col] < matrix[i][col] ? i : max_row;
    }
    
    return max_row;
}

// returns row and col of a peak element in the matrix
vector<int> findPeakGrid(vector<vector<int>> &matrix){
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int left_col  = 0;
    int right_col = cols-1;
    
    // try to converge to a peak element's column
    while(left_col < right_col){
        
        int mid_col = left_col + (right_col - left_col)/2;
        
        // row index of maximum element in mid_col column
        int max_row = findMaxRow(matrix, mid_col);
        
        // this condition is similar to finding the peak index in an 1D array
        // only difference here is we are trying to converge to the peak element's column
        if( matrix[max_row][mid_col] < matrix[max_row][mid_col+1] ){
            left_col = mid_col+1;
        }else{
            right_col = mid_col;
        }
    }
    
    
    // finaly left_col & right_col will both point to the peak element's column number
    // and we can find the maximum in this column in O(rows) time
    int peak_row = findMaxRow(matrix, left_col);
    
    return {peak_row, left_col};
}


int main() {
	
	int rows;
	int cols;
	
	cin >> rows >> cols;
	
	vector<vector<int>> matrix(rows, vector<int>(cols));
	
	for (int i = 0; i < rows; i++) {
	    for (int j = 0; j < cols; j++) {
	        cin >> matrix[i][j];
	    }
	}
	
	vector<int> peak_indexes = findPeakGrid(matrix);
	
	cout << peak_indexes[0] << " " << peak_indexes[1] << "\n";
	
	
	return 0;
}
