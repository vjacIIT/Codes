#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int count=0;
	long int n;
	vector<long int> v;
	while(scanf("%ld",&n)!=EOF){
		count++;
		v.push_back(n);
		sort(v.begin(),v.end());
		if(count%2==1)	printf("%ld\n",v[count/2]);
		else	printf("%ld\n",(v[count/2]+v[(count/2)-1])/2);
	}
	return 0;
}
// Can't find a proper data structure in which I can add elements in between and also find elements based on indexing
// Means I can find where to add element using binary search but then I need to push all the elements after it by one index more, which is O(n).
// Cannot use linked list
