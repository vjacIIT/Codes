#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
	vector<int> v;
	vector<int>::iterator it, it2;
	int tc, *a, n, def, fire, mn, mx, pos;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);		def=INT_MAX;
		a = new int[n-1];
		for(int i=0; i<n-1; i++)	scanf("%d",a+i);
		scanf("%d", &fire);
		for(int i=0; i<n-1; i++){
			for(int j=0; j<n-1; j++)	v.push_back(a[j]);
			it = v.begin();	it+=i;	it = v.insert(it,0);
			it = v.begin();
			while(v.size()>2){
				if(it==v.end())	it=v.begin();
				if((*it)>0){
					it2=it;	it2++;	if(it2==v.end())	it2=v.begin();
					if((*it2)<=0){	(*it2)-=(*it);	it=++it2;	}
					else	it=v.erase(it2);
				}
				else	it++;
			}
			it=v.begin();	it2=it;	it2++;
			mn=min(*it,*it2);	mx=max(*it,*it2);
			if(mx<=fire){								// other soldier didn't survive
				if(def>fire-mn){	pos=(i+1);	def=fire-mn;	}
			}
			v.clear();
		}
		if(def==INT_MAX)	printf("impossible\n");
		else{	printf("possible\n");	printf("%d %d\n",pos,def);	}
		delete []a;
	}
	return 0;
}

// I am going to all possible indices, O(n^2), hence partial
