#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    Difference(vector<int> a){
        elements = a;
    }

    void computeDifference(){
        int mmin=101, mmax=-1;
        for(int i=0; i<elements.size(); i++){
            if(mmin>elements[i])
                mmin=elements[i];
            if(mmax<elements[i])
                mmax=elements[i];
        }
        maximumDifference = mmax-mmin;
        return;
    }
	// Add your code here

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
