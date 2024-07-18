#include <iostream>
using namespace std;

int minSquares(int width, int height){
    
    if(width == height) return 1;
    
    int countSqs = 0;
    while(width>0 && height>0){
        
        if(height>width){
            height = height - width;
        }
        else{
            width = width - height;
        }
        countSqs++;
    }
    return countSqs;
}

int main() {
	int width = 36;//5;
	int height = 30;//3;
	cout<<minSquares(width, height)<<"\n";
	return 0;
}
