#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int t, ans,m,n;
	char c;
	scanf("%d\n",&t);
	while(t--){
		scanf("%c%d%d\n",&c,&m,&n);
		if(c=='r' || c=='Q')	ans=min(m,n);
		else if(c=='k')		ans=(((m+1)/2)*((n+1)/2)) + ((m/2)*(n/2));
		else	ans=(((m+1)/2)*((n+1)/2));
		printf("%d\n",ans);
	}
	return 0;
}
