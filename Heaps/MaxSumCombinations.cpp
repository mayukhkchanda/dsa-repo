// Solution Explanation: https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/

class Comparator{
    public:
    bool operator()( vector<int> &a, vector<int> &b ){
        return a[0] < b[0];
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int k) {

    int n = A.size();
    if( k>n ) return {};

    sort( A.begin(), A.end() );
    sort( B.begin(), B.end() );

    priority_queue<vector<int>, vector<vector<int>>, Comparator> maxHeap;
    vector<int> res;

    set<pair<int, int>> hashset;

    maxHeap.push( {A[n-1]+B[n-1], n-1, n-1} ); // { A_val+B_val, A_index, B_index }
    hashset.insert( {n-1, n-1} );

    while( k > 0 ){

        vector<int> sum = maxHeap.top();
        maxHeap.pop();

        res.push_back( sum[0] );    

        int i = sum[1];
        int j = sum[2];

        if( hashset.find( {i-1, j} ) == hashset.end() ){
            maxHeap.push( {A[i-1]+B[j], i-1, j} );
            hashset.insert( {i-1, j} );
        }

        
        if( hashset.find( {i, j-1} ) == hashset.end() ){
            maxHeap.push( {A[i]+B[j-1], i, j-1} );
            hashset.insert( {i, j-1} );
        }

        k--;
    }

    return res;
}
