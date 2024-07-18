#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
 * 
 * Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it.
 * Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. 
 * The designed algorithm should have linear time complexity. 
 * Example: 
 *  Input: mat[4][4] = { {10, 20, 30, 40},
 *                        {15, 25, 35, 45},
 *                        {27, 29, 37, 48},
 *                        {32, 33, 39, 50}};
 *                 x = 29
 *  Output: Found at (2, 1)
 * 
 * Approach: 
 *  The simple idea is to remove a row or column in each comparison until an element is found.
 *  Start searching from the top-right corner of the matrix. There are three possible cases. 
 *  
 *  CASE 1:: The given number is greater than the current number: This will ensure that all the elements in the current 
 *           row are smaller than the given number as the pointer is already at the right-most elements and the row is sorted. Thus, the 
 *           entire row gets eliminated and continues the search for the next row. Here, elimination means that a row needs not be searched.
 *  CASE 2:: The given number is smaller than the current number: This will ensure that all the elements in the current column are 
 *           greater than the given number. Thus, the entire column gets eliminated and continues the search for the previous column, i.e. the
 *           column on the immediate left.
 *  CASE 3:: The given number is equal to the current number: This will end the search.
 * 
 *   As we are reducing the search space by eliminating one row or column at each turn. And we will only traverse the
 *   matrix till we reach either the last row or first column. Thus the excepted time complexity is O(N).
 * 
 * */


pair<int,int> search(int rows, int cols, vector<vector<int>> matrix, int target){
    
    // start from top right element
    int row = 0;
    int col = cols - 1;
    
    // three cases arise
    while( row < rows && col >= 0 ){

        // case 1: this element is equal to our current element
        if(matrix[row][col] == target){
            return {row, col};
        }
        
        // case 2: this element is smaller than our current element
        if( target < matrix[row][col] ){
            //then this element is smaller than all the elements in this column starting 
            //from this index towards the bottom. As we are starting from top-right element
            // we can skip this entire column.
            col--;
        }
        
        // case 3: this element is greater than our current element
        else{
            //then this element is greater than all the elements in the current row starting
            //from this index towards the left. As we are starting from top-right element
            // we can skip this entire row.
            row++;
        }
    }
    
    
    return {-1,-1};
}

int main() {
	
	int rows = 0, cols=0;
	
	cin >> rows;
	cin >> cols;
	
	vector<vector<int>> matrix;
	
	for (int i = 0; i < rows; i++) {
	    vector<int> array;
	    int temp;
	    for (int i = 0; i < cols; i++) {
	       cin >> temp;
	       array.push_back(temp);
	    }
	    matrix.push_back(array);
	}
	
	int target ;
	
	cin >> target;
	
	cout<<rows<<" "<<cols<<" "<<target<<"\n";
	
	pair<int,int> index = search(rows, cols, matrix, target);
	
	cout<< index.first <<" "<< index.second<<"\n";
	
	return 0;
}
