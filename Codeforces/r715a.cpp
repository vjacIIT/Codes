#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<int> odd, even;
	int t, n, no;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d",&no);
			if(no%2)
				odd.push_back(no);
			else
				even.push_back(no);
		}
		no=0;
		for(auto it : odd){
			if(no)
				printf(" ");
			printf("%d", it);
			no++;
		}
		for(auto it : even){
			if(no)
				printf(" ");
			printf("%d", it);
			no++;
		}
		printf("\n");
		odd.clear();
		even.clear();
	}
	return 0;
}
