#include<iostream>
using namespace std;

int main(){
	int tc, n, z, *v, *stp, nz, nold, st,no;
	scanf("%d",&tc);
	while(tc--){
		st=0;			// start
		nz =0;			// keeps the number of zeros between two consecutive 1's	
		nold=0; 		// keeps the number of steps required by the last 1 to reach goal
		no = 0; 		// stores number of ones
		scanf("%d%d",&n,&z);
		v = new int[n];
		stp = new int[n];		// no of steps required by 1's to reach goal(left end)
		for(int i=0; i<n; i++){
			scanf("%d",v+i);
			no+=(v[i]==1) ? 1:0;
		}
		while(v[st]==1){		// removing all the starting 1's (they have already reached goal)
			stp[st]=0;
			st++;
		}
		for(int i=st; i<n; i++){
			if(v[i]==0){
				nz++;
				stp[i]=0;
			}
			else{
				if(nz==0){
					stp[i]=nold+1;
					nold++;
				}
				else{
					stp[i]=nold+nz;
					nold = nold+nz;
					nz=0;				// now if new 1 comes no of zeros for it becomes 0
				}
			}
		}
		st=-1;
		for(int i=0; i<n; i++)	if(st<stp[i])	st=stp[i];
		if(z>=st){
				for(int i=0; i<no; i++)	printf("1 ");
				for(int i=0; i<n-no; i++)	printf("0 ");
				printf("\n");
		}
		else{
			for(int i=0; i<z; i++){
				for(int j=0; j<n-1; j++){
					if(v[j]==0 && v[j+1]==1){
						v[j]=1;
						v[j+1]=0;
						j++;
					}
				}
			}
			for(int i=0; i<n; i++)	printf("%d ",v[i]);
			printf("\n");
		}
	}
	return 0;
}
