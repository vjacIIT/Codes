#include<cstdio>
#include<set>
using namespace std;

int main(){
	long int id, cnt;
	set<long int> s;
	set<long int>::iterator it;
	int n, m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)	break;
		cnt=0;	s.clear();
		for(int i=0; i<n; i++){
			scanf("%ld",&id);
			s.insert(id);
		}
		for(int i=0; i<m; i++){
			scanf("%ld",&id);
			it = s.find(id);
			if(it!=s.end()){	cnt++; s.erase(it);	}
		}
		printf("%ld\n",cnt);
	}
}

// Time it took is 0.95s
