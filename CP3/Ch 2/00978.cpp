#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;

int main(){
	vector<int> vb,vg;	
	multiset<int,greater<int>> stg,stb;
	int n, no, b, sg, sb, m, n1, n2;
	scanf("%d",&n);
	while(n--){
		stg.clear();	stb.clear();
		scanf("%d%d%d",&b,&sg,&sb);
		for(int i=0; i<sg; i++){	scanf("%d",&no);	stg.insert(no);	}
		for(int i=0; i<sb; i++){	scanf("%d",&no);	stb.insert(no);	}
		m = min(min(sg,sb),b);	
		while(m>0){
			vb.clear();	vg.clear();
			while(m--){	
				auto it1 = stb.begin();		n1=*it1;	stb.erase(it1);		sb--;
				auto it2 = stg.begin();		n2=*it2;	stg.erase(it2);		sg--;
				if(n1>n2){	vb.push_back(n1-n2);	sb++;	}
				else if(n2>n1){	vg.push_back(n2-n1);	sg++;	}
			}
			for(int i=0; i<vb.size(); i++)	stb.insert(vb[i]);
			for(int i=0; i<vg.size(); i++)	stg.insert(vg[i]);
			m = min(min(sg,sb),b);
		// because it is not possible for one fighter to fight two games in one round
		}
		if(sg==sb)	printf("green and blue died\n");
		else if(sg>sb){
			printf("green wins\n");
			for(auto it1=stg.begin(); it1!=stg.end(); it1++)	printf("%d\n",*it1);
		}
		else{
			printf("blue wins\n");
			for(auto it2=stb.begin(); it2!=stb.end(); it2++)	printf("%d\n",*it2);
		}
		if(n)	printf("\n");	
	}
	return 0;
}
