#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Find a pair that add up to target_sum
/*2-Pointer Approach*/
//wrost case time complexity -> O(nlogn)+O(N) and space complexity -> O(1)
//passing array by values O(n)
vector<int> Pairs( vector<int> array, int target ){
    
    sort(array.begin(), array.end());  //O(nlogn)
    
    //2 pointer approach
    
    int low = 0;
    int high = array.size() -1 ;
    
    int sum = array[low] + array[high];
    
    bool isFound = false;
    
    while( low < high ){  //O(n/2) -> worst case the sum does not exists
        
        if( sum < target ){
            // increase the sum by moving low to left
            low++;
            sum = array[low] + array[high];
        }
        else if(sum > target){
            //decrease the sum by moving high to right
            high--;
            sum = array[low] + array[high];
        }
        else{
            isFound =true;
            break;
        }
        
    }
    
    if (isFound)
        return vector<int> {array[low],array[high]};
    else
        return vector<int> {};

}



int main() {
	// your code goes here
	vector<int> array{10,5,2,3,-6,9,11};
	int target = 4;
	vector<int> result =  Pairs( array, target  );
	
	if (result.size() > 0)
	    for(int i:result )
	        cout<<i<<" ";
	else
	    cout<<"Not found"<<"\n";
	return 0;
}
