#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Question::
 *  LC -> https://leetcode.com/problems/rotate-image
 *  IB -> https://www.interviewbit.com/problems/rotate-matrix/
 * 
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
 * DO NOT allocate another 2D matrix and do the rotation.
 *   
 * Example 0:
 *   Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *   Output: [[7,4,1],[8,5,2],[9,6,3]]
 * Example 1:
 *   Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *   Output: [[7,4,1],[8,5,2],[9,6,3]]
 * Example 2:
 *   Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 *   Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * Example 3:
 *   Input: matrix = [[1]]
 *   Output: [[1]]
 * Example 4:
 *   Input: matrix = [[1,2],[3,4]]
 *   Output: [[3,1],[4,2]]
 * 
 * 
 * This post talks about common approaches to rotate matrix either clockwise or anti-clockwise:
 * https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
 * 
 * > Clockwise rotate::
 *     >> First reverse up to down, then swap the symmetry 
 *         1 2 3     7 8 9     7 4 1
 *         4 5 6  => 4 5 6  => 8 5 2
 *         7 8 9     1 2 3     9 6 3
 *  
 * > Anticlockwise rotate::
 *     >> First reverse left to right, then swap the symmetry
 *        1 2 3     3 2 1     3 6 9
 *        4 5 6  => 6 5 4  => 2 5 8
 *        7 8 9     9 8 7     1 4 7
 * 
 * Approach::
 *  
 *  > Similar to the approach discussed in the post, here we firsr swap a row with column and
 *      then reverse it.
 *  > For swaping the ith row with column, we start at the row end and column end and for 
 *      each element we swap the row and column elements till ith index. 
 *  > After swaping all the elements we revese the row.
 * 
 * 
 * Time Complexity :: O(N*M) as N==M thus, O(N^2)
 * 
 * */


// swaps col column with col row
void swapColWithRow(vector<vector<int>>& matrix, int col){
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // start from columns's and row's end
    // and go till col row and col column
    int col_itr = rows-1; // it iterates over a column 
    int row_itr = cols-1; // it iterates over a row 
    
    while( col_itr>=col && row_itr>=col ){
        swap( matrix[col_itr][col], matrix[col][row_itr] );
        col_itr--;
        row_itr--;
    }
}


void rotate(vector<vector<int>>& matrix) {
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    
    for (int i = 0; i < cols; i++) {
        
        // swap ith row with ith column
        swapColWithRow(matrix, i);
        
        // reverse the row 
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
	
	
	int rows;
	int cols;
	
	cin >> rows >> cols;
	
	vector<vector<int>> matrix(rows, vector<int>(cols, 0));
	
	for (int i = 0; i < rows; i++) {
	    for (int j = 0; j < cols; j++) {
	        cin >> matrix[i][j];
	    }
	}
	
	rotate(matrix);
	
	for (int i = 0; i < rows; i++){ 
	    for (int j = 0; j < cols; j++) 
	        cout << matrix[i][j]<<" ";
	   cout<<"\n";
	    }
	
	return 0;
}
