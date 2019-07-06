#include<cstdio>
#include<map>
#include<iterator>
using namespace std;

int main(){
	map<long int,int> mp;		// id, index
	map<long int,int>::iterator it;
	long int id, cnt;
	int n, m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)	break;
		cnt=0;	mp.clear();
		for(int i=0; i<n; i++){
			scanf("%ld",&id);
			mp[id]=i;
		}
		for(int i=0; i<m; i++){
			scanf("%ld",&id);
			it = mp.find(id);				// find based on key
			if(it!=mp.end()){	cnt++;	mp.erase(it);	}
		}
		printf("%ld\n",cnt);
	}
	return 0;
}

// Time it took is 1.14s
