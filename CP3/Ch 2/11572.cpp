// Given array , find the maximum length continuous subsequence such none of the element is repeated

#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	map<int,int> mp;
	map<int,int>::iterator it;
	int tc, n, prev, l, mx, no;
	scanf("%d",&tc);
	while(tc--){
		prev = -1;	mx=0;	l=0;
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d",&no);	it=mp.find(no);
			if(it!=mp.end()){			// now we have element repeated
				prev=max(it->second,prev);	it->second=i;	l=i-prev;
			}							// previous stores the maximum index of repeated element
			else{	
				mp[no]=i;	l++;	
			}
			if(l>mx)	mx=l;
		}
		printf("%d\n",mx);
		mp.clear();
	}
	return 0;
}

// It takes O(logn) time for map, if we use hash map then we may get O(1) expected time
// Initially I used set and whenever we find a element which is there in set, I initialize l=1 again, this approach is wrong as we may remove the previous occurence of current element and go on to get a more lengthy continuous subsequence

