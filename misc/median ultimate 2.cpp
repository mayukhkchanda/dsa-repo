#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//int z=1;
int findele(vector<int>& arr,int r){
    int n=arr.size();
    if(n==1){
        return arr[0];
    }
    
      if( r<=n){
       // cout<<"ith iteraion "<<z++<<endl;
        
    vector<int> B,medofmed;
    
    int k=0;
    for(int i=0;i<n;i++){
        
            B.push_back(arr[i]);
            k++;
         if(k==5 || i==n-1){
            sort(B.begin(),B.end());
            int m=B.size();
            m= (m==4) ? ((m/2)-1) : (m/2);
            /*if(m==4)
                 medofmed.push_back(B[((m/2)-1)]);
            else
                medofmed.push_back(B[(m/2)]);*/
            medofmed.push_back(B[m]);
            B.clear();
            k=0;
        }
    }
   /* for(int i:medofmed){
        cout<<i<<" ";
    }*/
    
   // cout<<endl;
    int x= findele(medofmed,n/10);
  //  cout<<"x= "<<x<<endl;
    vector<int> Ar,Al;
    for(int i:arr){
        if(i<x){
            Al.push_back(i);
        }
        else if(i>x){
            Ar.push_back(i);
        }
    }
   /* cout<<"rank="<<r<<endl;
    for(int i:Al){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:Ar){
        cout<<i<<" ";
    }
    cout<<endl;*/
    int left=Al.size();
    if(left==r-1){
        return x;
    }
    else if(left>r-1){
        return findele(Al,r);
    }
    else{
        return findele(Ar,r-left-1);
    }}
    
    else 
        return 0;
    
}




int main() {
	vector<int> arr={16, 77, -24, 83, 25, 65, 35, 10, -9, 46, -87, -95, -96, 23, 86, -81, 22, -20, -6, 14};
	int r=7;
	
	cout<< findele(arr,r)<<endl;
	sort(arr.begin(),arr.end());
	for(int i:arr){
	    cout<<i<<" ";
	}
	return 0;
}
