#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
	vector<vector<int>> chamber;
	vector<int> specimen;
	int ch, sp, cnt, tc=0;
	bool flg;
	double imb, ms, mean;
	while(scanf("%d%d",&ch, &sp)!=EOF){
		tc++;
		mean = 0.0;
		imb = 0.0;
		specimen = vector<int>(sp);
		chamber = vector<vector<int>>(ch);
		for(int i=0; i<sp; i++){
			scanf("%d", &specimen[i]);
			mean+=specimen[i];
		}
		mean/=ch;
		sort(specimen.begin(),specimen.end(),greater<int>());
		cnt = 0;
		flg = true;
		for(int i=0; i<sp; i++){
			chamber[cnt].push_back(specimen[i]);
			if(flg)
				cnt++;
			else
				cnt--;
			if(cnt==ch){
				flg=false;
				cnt--;
			}
		}
		printf("Set #%d\n",tc);
		for(int i=0; i<ch; i++){
			ms = 0.0;
			printf(" %d:",i);
			for(int j=0; j<chamber[i].size(); j++){
				printf(" %d",chamber[i][j]);
				ms += chamber[i][j];
			}
			printf("\n");
			imb+=abs(ms-mean);
		}
		printf("IMBALANCE = %.5lf\n\n",imb);
	}
	return 0;
}
