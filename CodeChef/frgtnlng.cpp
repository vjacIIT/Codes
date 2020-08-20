#include<iostream>
#include<string>
using namespace std;

int main(){
	bool exist[101];
	int n,k,l,tc;
	char str[5], c;
	string s[101];
	
	scanf("%d",&tc);
	while(tc--){
		for(int i=0; i<=100; i++)	exist[i]=false;
		scanf("%d%d\n",&n,&k);
		for(int i=0; i<n; i++){
			while(true){
				scanf("%c",&c);
				if(c==' ' || c=='\n')	break;
				s[i]+=c;
			}
		}
		
		for(int i=0; i<k; i++){
			scanf("%d",&l);
			for(int j=0; j<l; j++){
				scanf("%s",str);
				for(int w=0; w<n; w++){
					if(str==s[w])	exist[w]=true;
				}
			}
		}
		for(int i=0; i<n; i++){
			if(exist[i])	printf("YES ");
			else	printf("NO ");
		}
		printf("\n");
		for(int i=0; i<n; i++)	s[i].clear();		// clearing the string is important
	}
	return 0;
}
