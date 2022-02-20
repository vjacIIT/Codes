#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int> ans;

void printstr(int n){
	if(n>0){
		for(int i=0; i<n; i++)
			printf("(");
	}
	for(int i=0; i<-n; i++)
		printf(")");
	
	return;
}

int main(){
	vector<pair<int,int>> v;		// '+' for opening bracket and '-' for closing
	char str[200];
	int tc, l, n;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		scanf("%s",str);
		l = strlen(str);
		v = vector<pair<int,int>> (l);
		ans = vector<int> (l+1);
		for(int i=0; i<l; i++){
			n = str[i]-'0';
			v[i].first = n;
			v[i].second = -n;
		}
		ans[0] = v[0].first;
		ans[l] = v[l-1].second;
		for(int i=0; i<l-1; i++)
			ans[i+1] = v[i].second + v[i+1].first;
		
		printf("Case #%d: ",t);
		for(int i=0; i<l; i++){
			printstr(ans[i]);
			printf("%d",str[i]-'0');
		}
		printstr(ans[l]);
		printf("\n");
		v.clear();
		ans.clear();
	}
	return 0;
}
