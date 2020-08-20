#include<cstdio>
#include<cstring>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n")
#define scan(n)		scanf("%d",&n)
#define print(n)	printf("%d",n)
#define mp	make_pair
#define pb	push_back
const int Mod = 1e9+7;

char B[210];

int gcd(int a, int b){
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}

int main(){
	int tc, remain, A;
	scan(tc);
	while(tc--){
		scanf("%d %s",&A,B);
		if(A==0){
			loop(i,strlen(B))
				printf("%c",B[i]);
			newline;
			continue;
		}
		
		// For finding B mod A
		remain = 0;
		loop(i,strlen(B)){				
			remain*=10;
			remain+=B[i]-'0';
			remain%=A;
		}
		printf("%d\n",gcd(A,remain));		
	}
	return 0;
}
