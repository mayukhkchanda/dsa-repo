#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int z=1;
int findele(vector<int>& arr,int r){
    int n=arr.size();
    if(n==1){
        return arr[0];
    }
    
      if( r<=n){
        cout<<"ith iteraion "<<z++<<endl;
        
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
    for(int i:medofmed){
        cout<<i<<" ";
    }
    
    cout<<endl;
    int x= findele(medofmed,n/10);
    cout<<"x= "<<x<<endl;
    vector<int> Ar,Al;
    for(int i:arr){
        if(i<x){
            Al.push_back(i);
        }
        else if(i>x){
            Ar.push_back(i);
        }
    }
    cout<<"rank="<<r<<endl;
    for(int i:Al){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:Ar){
        cout<<i<<" ";
    }
    cout<<endl;
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
	vector<int> arr={10, 14, 7, 9, 17, 11, 6, 15, 20, 3, 1, 12, 19, 16, 18, 13, 8, 5, 4, 21, 2};
	int r=8;
	cout<< findele(arr,r);
	return 0;
}
