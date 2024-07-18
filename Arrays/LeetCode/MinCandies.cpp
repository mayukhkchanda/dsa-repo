/**
 * Question: https://leetcode.com/problems/candy/
 * 
 * Solution & Explained Comment: https://leetcode.com/problems/candy/discuss/42769/A-simple-solution/336970
 * 
 */

class Solution {
public:
        
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        
        vector<int> candies(n, 1); // give 1 candy to each child
        
        
        for(int i=0; i<n; i++){
            // from left to right, check if the child with higher rating than
            // the child to the left, has higher candy
            if( i > 0 && ratings[i] > ratings[i-1]){
                candies[i] = max( candies[i], candies[i-1]+1 );
            }
        }

        int sum = 0;

        for(int i=n-1; i>=0; i--){
            if( i<n-1 && ratings[i] > ratings[i+1] ){
                candies[i] = max( candies[i], candies[i+1]+1 );
            }
            
            sum += candies[i];
        }
        
        return sum;
    }
};