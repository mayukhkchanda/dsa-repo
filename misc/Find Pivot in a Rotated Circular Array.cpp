#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int decide=-1;

 int find_min_max(vector<int>& nums,int start,int end){
        if(start>end) return -1;
        
        int mid=(start+end)/2;
        cout<<mid <<" "<< nums[mid]<<endl;
        if(nums[mid-1]>nums[mid] && nums[mid]<nums[mid+1]){
            decide=0;
            //cout<<"min_exe"<<nums[mid];
            return mid;}
            
        else if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
            decide=1;
           // cout<<"max_exe"<<nums[mid];
            return mid;}
            int i= find_min_max(nums,start,mid-1);
        if(i==-1) 
            return find_min_max(nums,mid+1,end);
        
        return i ;
    }
    
    
    int main() {
        vector<int> nums={1,3,5};
       // int target;
        int n=(int)nums.size();
        
       int i= find_min_max(nums,0,n-1);
        cout<<decide <<" " << i<<" " <<nums[i];
    }
