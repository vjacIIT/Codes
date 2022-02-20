#include<cstdio>
#include<vector>
using namespace std;

vector<char> istr;
vector<bool> taken;
vector<int> vT;					// stores index of T from the end of the string

int main(){
	int t, n, lastT, nT, nM;
	scanf("%d",&t);
	while(t--){
		nT=0, nM=0;
		scanf("%d\n",&n);
		istr = vector<char>(n);
		taken = vector<bool>(n,false);
		for(int i=0; i<n; i++){
			scanf("%c",&istr[i]);
			//printf("%c ",istr[i]);
			istr[i] == 'T' ? nT++ : nM++;
		}
		if(istr[0]=='M' || ((2*nM)!=nT)){
			printf("NO\n");
			continue;
		}
		else
			lastT=0;
		
		for(int i=n-1; i>=0; i--){
			if(istr[i]=='T')
				vT.push_back(i);
		}
		//printf("%d\n",nM);
		for(int i=0; i<n; i++){
			if(taken[i])					// this element already checked
				continue;
			if(istr[i]=='M'){
				taken[lastT]=true;
				taken[i]=true;
				if(taken[vT[nM-1]] || vT[nM-1]<i){
					lastT=-1;
					break;
				}
				taken[vT[nM-1]]=true;
				nM--;
				while(lastT<n && taken[lastT])
					lastT++;
				if(lastT!=n && istr[lastT]=='M'){
					lastT=-1;
					break;	
				}
			}
		}
		if(lastT==-1)
			printf("NO\n");
		else
			printf("YES\n");
		vT.clear();
	}
	return 0;
}
