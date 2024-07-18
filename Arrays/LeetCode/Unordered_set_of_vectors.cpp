#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};


int main() {
	
	unordered_set<vector<int>, VectorHash> aset;
	
	
	vector<int> avector{1,2,3};
	
	aset.insert(avector);
	
	vector<int> anotherVector{1,2,3};
	
	if(aset.find(anotherVector) != aset.end() )
	    cout<<"1.Present";
	
	anotherVector= {1,2,0};
	
	if( aset.find(anotherVector) != aset.end() )
	    cout<<"2.Present";
	return 0;
}
