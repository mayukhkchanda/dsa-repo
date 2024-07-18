class Solution {
public:
int decide=-1;

 int find_min_max(vector<int>& nums,int start,int end){
        if(start>end) return -1;
        
        int mid=(start+end)/2;
        cout<<mid <<" "<<endl;
     
        if(( mid>0 && nums[mid-1]>nums[mid] ) && (mid<(int)nums.size() && nums[mid]<nums[mid+1] )){
            decide=0;
            return mid;}
            
        else if(( mid>0 && nums[mid-1]<nums[mid] ) && (mid<(int)nums.size() && nums[mid]>nums[mid+1])){
            decide=1;
            return mid;}
     
            int i= find_min_max(nums,start,mid-1);
        if(i==-1) 
            return find_min_max(nums,mid+1,end);
        
        return i ;
    }
    
    
int binarysearch(vector<int>& nums, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (nums[mid] == x) 
            return mid; 
  
      
        if (nums[mid] > x) 
            return binarysearch(nums, l, mid - 1, x);  
        return binarysearch(nums, mid + 1, r, x); 
    } 
    return -1; 
} 
    
    int search(vector<int>& nums, int target) {
        
        int n=(int)nums.size();
        if(n==0) return -1;
        if(n==1){
            return nums[0]==target ? 0:-1;
        }
        if(n<=9){
          for(int i=0;i<n;i++){
              if(target==nums[i])
                  return i;
          }
            return -1;
        }
        
       
       int i= find_min_max(nums,0,n-1);
        cout <<i<<" "<<decide;
        if(decide==1){
            int res=binarysearch(nums,0,i,target);
            if(res==-1){
                
               return binarysearch(nums,i+1,n-1,target);   
            }
            return res;
        }
       if(decide==0){
            int res=binarysearch(nums,i,n-1,target);
            if(res==-1){
                cout << "abd";
               return binarysearch(nums,0,i-1,target);   
            }
           return res;
        }
        if(decide==-1){
            cout <<"bde";
            return binarysearch(nums,0,n-1,target);
        }
        return -1;
    }
};