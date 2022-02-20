#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, j, sum=0, max, csum, cnt=0;
	cin>>n;
	vector<pair<int,int>> v(n,make_pair(0,0));		// left sum , right sum
	vector<int> val(n,0);
	for(int i=0; i<n; i++){
		cin>>j;
		val[i]=j;
		sum+=j;
	}
	max = sum;
	v[0].first=0;
	v[0].second = sum-val[0];
	v[n-1].first = sum-val[n-1];
	v[n-1].second = 0;
	for(int i=1; i<n-1; i++){
		v[i].first = v[i-1].first+val[i-1];
		v[i].second = v[i-1].second-val[i];
	}
	for(int l=1; l<n+1; l++){
		for(int i=0; i<=n-l; i++){
			j = i+l-1;
			csum = v[i].first+v[j].second+l-(v[i].second-v[j].second+val[i]);
			if(csum>max){
				max=csum;
				cnt++;
			}
		}
	}
	if(cnt>0)	cout<<max<<endl;
	else	cout<<max-1<<endl;
	return 0;
}
