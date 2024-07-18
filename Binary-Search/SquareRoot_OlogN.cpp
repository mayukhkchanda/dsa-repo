#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdio>
using namespace std;


/**
 * Question:: https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/
 * 
 * Given a positive number n and precision p, find the square root of number upto p decimal places using binary search. 
 * Examples: 
 *   Input : number = 50, precision = 3
 *   Output : 7.071
 *   
 *   Input : number = 10, precision = 4
 *   Output : 3.1622
 */

// find the integer part using binary search.
int findIntegralPart(int num) {
    int left = 0;
    int right = num;

    int ans = INT_MAX;

    while(left <= right){

        int mid = left+(right-left)/2;

        // if mid*mid is <= num then mid could be the integer part of the square root of num
        // Here 2 extreme cases are when mid == 0  and mid >10^9(would overflow int or long)
        if(mid==0 || mid <= num/mid){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    return ans;
}

// find square root of a number upto p precision places
float squareRoot(int num, int p){
    
    float root = findIntegralPart(num) * 1.0;
    
    // multiplier -> it becomes 0.1, 0.01, 0.001 ... upto p places
    float mul = 0.1;
    
    // for each place after decimal place we check each number from 0 to 9
    // which when placed in the respective position statisfies the condition root * root <= num
    for (int i = 1; i <= p; i++) {
        
        // the digit at this decimal place
        int digit = 0;
        
        // check each number from 0 to 9
        for (int j = 0; j < 10; j++) {
            
            // calculate root after puttin j in it's repective decimal place
            float root_dec = root+ (mul * (j * 1.0));
            
            // if root*root statisfies the condition after putting j in respective
            // decimal place then this is a good candidate for this place
            if( root_dec*root_dec <= (num * 1.0) ){
                digit = j;
            }
        }
        
        // save the new root
        root =root+( mul * (digit * 1.0));
        // shift the multiplier
        mul = mul / 10.0;
    }
    
    return root;
}

int main() {
	int num, precision;
	
	cin >> num;
	cin >> precision;
	
// 	printf("%.3f\n", squareRoot(num, precision));

    // cout << setprecision(3) << fixed;
	
	cout<< squareRoot(num, precision);
	
	return 0;
}
