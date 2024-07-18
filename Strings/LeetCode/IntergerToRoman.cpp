/**
 * Question: https://leetcode.com/problems/integer-to-roman/
 * 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * Example 1:
 *     Input: num = 3
 *     Output: "III"
 * Example 2:
 *     Input: num = 4
 *     Output: "IV"
 * Example 3:
 *     Input: num = 9
 *     Output: "IX"
 * Example 4:
 *     Input: num = 58
 *     Output: "LVIII"
 *     Explanation: L = 50, V = 5, III = 3.
 * Example 5:
 *     Input: num = 1994
 *     Output: "MCMXCIV"
 *     Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/integer-to-roman/discuss/6274/Simple-Solution
 * 
 * */

class Solution {
    
    string repeat(string str, string repeater, int times ){
        string res = str;
        while(times>0){
            res += repeater;
            times--;
        }
        return res;
    }
    
    string getRomanVal(int num){
        
        if(num>=1 && num<5){
            if(num == 4) return "IV";
            
            return repeat("I","I", (num-1)/1);
        }
        else if(num>=5 && num<10){
            if(num == 9) return "IX";
            
            return repeat("V","I", (num-5)/1);
        }
        else if(num>=10 && num<50){
            if(num == 40) return "XL";
            
            return repeat("X","X", (num-10)/10);
        }
        else if(num>=50 && num<100){
            if(num == 90) return "XC";
            
            return repeat("L","X", (num-50)/10);
        }
        else if(num>=100 && num<500){
            if(num == 400) return "CD";
            
            return repeat("C","C", (num-100)/100);
        }
        else if(num>=500 && num<1000){
            if(num == 900) return "CM";
            
            return repeat("D","C", (num-500)/100);
        }
        else if(num >= 1000 ){
            return repeat("M","M", (num-1000)/1000);
        }
        return "";
    }
    
public:
    string intToRoman(int num) {
        
        int tens = 1;
        
        string roman = "";
        
        while(num>0){

            int num_part = (num%10)*tens;
            
            roman = getRomanVal(num_part) + roman;        
            tens *= 10;
            num /= 10;
        }
        
        return roman;
    }
};