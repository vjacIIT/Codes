#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunction(const pair<pair<float,float>,string> &a, const pair<pair<float,float>,string> &b){
	if(a.first.first>b.first.first)	return true;
	else if(a.first.first<b.first.first)	return false;
	else	return a.first.second<b.first.second;
}

int main(){
	vector<pair<pair<float,float>,string>> vec;		// complaince,budget(price)
	int nr,np,req,no=1;
	float bud;
	char c;
	string str;
	while(scanf("%d%d\n",&nr,&np)){
		str="";
		if(nr==0 && np==0){
			printf("\n");
			break;
		}
		if(no!=1)	printf("\n\n");
		for(int i=0; i<nr; i++){
			while(scanf("%c",&c) && c!='\n')	str+=c;
			str.clear();
		}
				
		for(int i=0; i<np; i++){
			str="";
			while(scanf("%c",&c) && c!='\n')	str+=c;
			scanf("%f%d\n",&bud,&req);
			vec.push_back(make_pair(make_pair(1.0*req/nr,bud),str));
			str.clear();
			for(int j=0; j<req; j++){
				while(scanf("%c",&c) && c!='\n')	str+=c;
				str.clear();
			}
		}
		sort(vec.begin(),vec.end(),myfunction);
		printf("RFP #%d\n",no);
		for(int i=0; i<vec[0].second.length(); i++)	printf("%c",vec[0].second[i]);
		vec.clear();
		no++;
	}
	return 0;
}
