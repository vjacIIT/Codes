#include<cstdio>
using namespace std;

int main(){
	int tc;
	long int sum,diff,no;
	scanf("%d",&tc);
	while(tc--){
		scanf("%ld%ld",&sum,&diff);
		no = sum+diff;
		if(sum<diff || no%2!=0)	printf("impossible\n");
		else{
			no=(sum+diff)/2;
			printf("%ld %ld\n",no,sum-no);
		}
	}
	return 0;
}
