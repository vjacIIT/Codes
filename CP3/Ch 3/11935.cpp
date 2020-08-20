#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> v;									// distance
vector<int> c;									// consumption
vector<pair<char,char>> vc;

bool reach(float sfuel){
	int lcount=0;								// leak count
	int fcon = 0;
	float fuel = sfuel;
	for(int i=0; i<v.size(); i++){
		fuel -= (fcon*v[i])/100.0;
		fuel -= v[i]*lcount;
		if(fuel<0.0) return false;
		if(vc[i].first=='F')
			fcon = c[i];
		if(vc[i].first=='L')
			lcount++;
		if(vc[i].first=='M')
			lcount=0;
		if(vc[i].first=='G'){
			if(vc[i].second!='l')
				fuel=sfuel;
		}
	}
	return true;
}

int main(){
	float s, end, ans, mid;
	bool flg;
	int cd, d, fuel;
	char str[100],s1[30],s2[30];
	while(1){
		flg=false;
		v.clear();
		vc.clear();
		c.clear();
		d = 0;
		while(1){
			fgets(str,50,stdin);
			sscanf(str,"%d%s%s%d",&cd,s1,s2,&fuel);
				v.push_back(cd-d);
			if(s1[0]=='F')
				c.push_back(fuel);
			else
				c.push_back(0);
			if(!strcmp(s1,"Gas"))
				vc.push_back(make_pair(s1[0],'k'));
			else
				vc.push_back(make_pair(s1[0],s1[3]));
			if(s1[0]=='G' && s1[3]=='l')
				break;
			d = cd;
			if(s1[0]=='F' && !fuel){
				flg=true;
				break;
			}
		}
		if(flg)
			break;
		//for(int i=0; i<v.size(); i++)
		//	printf("%d %c %c %d\n",v[i],vc[i].first,vc[i].second,c[i]);
		s=0.0;	end=10000.00;
		for(int i=0; i<50; i++){
			mid=(s+end)/2.0;
			if(reach(mid)){
				ans=mid;
				end=mid;
			}
			else
				s=mid;
		}
		printf("%0.3f\n",ans);
	}
	return 0;
}
