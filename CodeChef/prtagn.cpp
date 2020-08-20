#include<cstdio>
#include<set>
#include<vector>
using namespace std;

int fones(int n){
	int nones=0;
	while(n>0){
		nones+=n%2;	n/=2;
	}
	return nones;
}

int main(){
	vector<int> v;
	set<int> s;
	int tc, n, nones, ne, no, q, k;		// number of ones, number of even 1's , number of odd 1's
	scanf("%d",&tc);
	while(tc--){
		ne=0;	no=0;	s.clear();
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			v.clear();
			scanf("%d",&q);
			if(s.find(q)==s.end()){
				nones = fones(q);
				nones%2==0 ? ne++:no++;
				v.push_back(q);
				for(auto it=s.begin(); it!=s.end(); it++){
					k = q^(*it);
					nones = fones(k);	nones%2==0 ? ne++:no++;
					v.push_back(k);
				}
				for(auto itk=v.begin(); itk!=v.end(); itk++)	s.insert(*itk);			
			}
			printf("%d %d\n",ne,no);
		}
	}
	return 0;
}
