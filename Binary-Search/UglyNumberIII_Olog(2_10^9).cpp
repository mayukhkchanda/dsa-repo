#include <iostream>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/ugly-number-iii/submissions/
 * 
 * An ugly number is a positive integer that is divisible by a, b, or c.
 * Given four integers n, a, b, and c, return the nth ugly number.
 * 
 * Example 1:
 *   Input: n = 3, a = 2, b = 3, c = 5
 *   Output: 4
 *   Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
 * Example 2:
 *   Input: n = 4, a = 2, b = 3, c = 4
 *   Output: 6
 *   Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
 * Example 3:
 *   Input: n = 5, a = 2, b = 11, c = 13
 *   Output: 10
 *   Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
 * Example 4:
 *   Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
 *   Output: 1999999984
 * 
 * 
 * !! This question is similar to a series of question discussed in the posts below::
 *      ->https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *      https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *      https://www.topcoder.com/thrive/articles/Binary%20Search
 * 
 * Explained Solution :: https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template
 * Approach:: 
 * > The count of numbers till a number N(inclusive) that are divisible by a or b or c is given by::
 *    N/a + N/b + N/c - N/lcm(a, c) - N/lcm(a, b) - N/lcm(b, c) + N/lcm(a, b, c)(lcm = least common multiple)
 *      This is discussed well here -> http://people.math.sfu.ca/~alspach/mag25/
 * > This fucntion is monotonous w.r.t to N. Thus lower bound binary search applies here.
 * 
 * */


// return the lcm of 2 numbers
long lcm(long a, long b){
    
    long prod = a*b;
    
    while( b>0L ){
        long rem = a%b;
        a = b;
        b = rem;
    }
    
    return ( prod/a );
}


// returns the count of numbers that are divisible by a | b | c
long cntSmallerNumber(long num, long a, long b, long c){
    
    // # elements divisible by a
    long cnt_a = num/a;
    
    //# elements divisible by b
    long cnt_b = num/b;
    
    //# elements divisible by c
    long cnt_c = num/c;
    
    //# elements divisible by a and b
    long cnt_ab = num/lcm(a, b);
    
    //# elements divisible by b and c
    long cnt_bc = num/lcm(b, c);
    
    //# elements divisible by a and c
    long cnt_ac = num/lcm(a, c);
    
    //# elements divisible by a & b & c
    long cnt_abc = num/lcm( a, lcm(b,c) );
    
    
    return (cnt_a + cnt_b + cnt_c - cnt_ab - cnt_bc - cnt_ac + cnt_abc );
}


int nthUglyNumber(int n, int a, int b, int c) {
    
    long nL = (long)n;
    long aL = (long)a;
    long bL = (long)b;
    long cL = (long)c;
    
    
    // it is said in the question statement that an answer lies b/w these 2 ranges inclusive
    long left = 1;
    long right = 2000000000;
    
    
    while(left < right){
        
        long mid = left + (right-left)/2;
        
        
        // if there are atlleast n smaller numbers than mid that are divisible by 2 | 3 | 5 
        // then it could be a possible answer else anything from left to mid cannot be an answer
        if(cntSmallerNumber(mid, aL, bL, cL) < n){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;
}
    


int main() {
	
	long n, a, b, c;
	
	cin >>n>>a>>b>>c;
	
	cout<< nthUglyNumber(n, a, b, c);

    // cout << cntSmallerNumber(6, a, b, c);
	
	return 0;
}
