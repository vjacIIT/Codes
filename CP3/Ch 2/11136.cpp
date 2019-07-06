#include<cstdio>
#include<set>
using namespace std;

int main(){
	multiset<long int,greater<long int>> s;
	long int n, nb, b, at;
	while(scanf("%ld",&n)!=EOF){
		if(n==0)	break;
		at=0;	s.clear();
		for(int i=0; i<n; i++){
			scanf("%ld",&nb);
			while(nb--){	scanf("%ld",&b);	s.insert(b);	}
			auto it1 = s.begin();	auto it2=s.end();	it2--;
			at+=(*it1)-(*it2);		s.erase(it1);	s.erase(it2);
		}
		printf("%ld\n",at);
	}
	
	return 0;
}
