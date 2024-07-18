#include<string>
#include<iostream>
using namespace std;

/**
    You are building a logic for a clock that requires you convert absolute time in minutes into a format supported by a digital clock. 
    See examples below:
        125 minutes can be displayed as 2:05 
        155 minutes can be displayed as 2:35
    (You can assume the maximum value of minutes will be less than 24 X 60)
    Input is a single integer::1180
    Output is a string denoting the digital clock time::19:40.
    Hint::You can use the  to_string(int)  method to convert an integer into string.
*/

string toString(int num){
    
    string numString = "";
    
    while(num>0){
        int rem = num%10;
        numString = (char)('0'+rem)+numString;
        num/=10;
    }
    
    return numString;
}


string convert_to_digital_time(int minutes){
    
    int hour = minutes/60;
    int min = minutes%60;
    
    string digitalHour = toString(hour);
    string digitalMin = toString(min);
    
    digitalMin = digitalMin.size() == 1 ? '0'+digitalMin : digitalMin; 
    
    if(hour == 0){
        digitalHour = "0";
    }
    
    if(min == 0){
        digitalMin = "00";
    }
    
    string digitalTime = digitalHour+ ":" + digitalMin;
    
    return  digitalTime;
}

int main() {
    
    int minutes = 24*60;
    
    cout<<convert_to_digital_time(minutes)<<"\n";
    
    // cout<<toString(1180);
    
	return 0;
}
