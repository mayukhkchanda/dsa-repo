/**
 * Question: https://www.interviewbit.com/problems/convert-to-palindrome/
 * 
 * Given a string A consisting only of lowercase characters, we need to check whether it 
 * is possible to make this string a palindrome after removing exactly one character from this.
 * If it is possible then return 1 else return 0.
 * 
 * Example Input
 *     Input 1: A = "abcba"
 *     Input 2: A = "abecbea"
 * Example Output
 *     Output 1: 1
 *     Output 2: 0
 * Example Explanation
 *     Explanation 1: We can remove character ‘c’ to make string palindrome
 *     Explanation 2: It is not possible to make this string palindrome just by removing one character 
 * 
 * LeetCode Discussion:
 *  > https://leetcode.com/discuss/interview-question/algorithms/125376/convert-a-string-to-a-palindrome
 * 
 * */

bool isPalindrome(string str){
    int n = str.length();

    int left = 0;
    int right = n-1;

    while(left < right){
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int Solution::solve(string str) {

    int n = str.length();

    int left = 0;
    int right = n-1;

    bool hasMismatch = false;

    while(left < right){

        if(str[left] != str[right]){
            hasMismatch = true;
            break;
        }
        left++;
        right--;
    }

    // If there is a mis-match, then we have 2 possible characters
    // that we can remove.
    if(hasMismatch){
        if( isPalindrome( str.substr(0,left)+str.substr(left+1) ) ||
            isPalindrome( str.substr(0,right)+str.substr(right+1) ) ){
            return 1;
        }
        else{
            return 0;
        }
    }

    // When no mis-match, i.e. string is a palindrome then only odd length
    // strings can have 1 character removed(i.e. the middle one) to make them
    // palindrome.
    return n%2 == 0 ? 0 : 1;
}
