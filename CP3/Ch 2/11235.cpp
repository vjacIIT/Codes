// Superb question on segment tree

// You are given a sequence of n non decreasing numbers
// For each query find the frequency of most repeated element

#include<cstdio>
#include<climits>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> fr, idx, stree;
int len;

int search(int st, int end, int n){
	int mid = (st+end)>>1;
	if(st>end)	return st;
	else if(idx[mid]==n)	return mid;
	else if(idx[mid]>n)	return search(st,mid-1,n);
	else	return search(mid+1,end,n);
}

int tree(int l, int r, int i){
	int mid=(l+r)>>1;
	if(l==r)	return fr[l];
	stree[(i<<1)+1]=tree(l,mid,(i<<1)+1);
	stree[(i<<1)+2]=tree(mid+1,r,(i<<1)+2);
	return max(stree[(i<<1)+1], stree[(i<<1)+2]);
}

int fmax(int li, int ri, int l, int r, int p){
	int mid=(l+r)>>1;
	if(li>r || ri<l)	return 0;
	if(li<=l && ri>=r)	return stree[p];
	else	return max(fmax(li,ri,l,mid,(p<<1)+1),fmax(li,ri,mid+1,r,(p<<1)+2));
}

int main(){
	char str[200];
	int n, q, cnt, *ar, l, r, li, ri, ans;
	while(fgets(str,100,stdin)){
		if(!strcmp(str,"0\n"))	break;
		sscanf(str,"%d%d",&n,&q);
		
		ar = new int[n+2];	ar[0]=0;	ar[n+1]=INT_MAX;
		for(int i=1; i<=n; i++)	scanf("%d",ar+i);
		for(int i=1; i<=n; i++){
			cnt=1;
			while(ar[i]==ar[i+1]){	i++;	cnt++;	}
			fr.push_back(cnt);
		}
		len = (int)fr.size();
		stree = vector<int>(4*len,0);
		stree[0]=tree(0,len-1,0);
		
		idx = vector<int>(len);	idx[0]=fr[0];
		for(int i=1; i<len; i++)	idx[i]=idx[i-1]+fr[i];
		
		for(int i=0; i<q; i++){
			ans=0;
			scanf("%d%d",&l,&r);
			if(ar[l]==ar[r])	printf("%d\n",r-l+1);
			else{
				li = search(0,len-1,l);		ans=max(ans,idx[li]-l+1);	// left index
				ri = search(0,len-1,r);		ans=max(ans,r-idx[ri-1]);	// right index
				li++;	ri--;		//(these values helps us to find the indices of search max query)
				if(li>ri)	printf("%d\n",ans);
				else{
					ans=max(ans,fmax(li,ri,0,len-1,0));
					printf("%d\n",ans);
				}
			}
		}	
		
		scanf("\n");
		fr.clear();	idx.clear();	stree.clear();
		delete []ar;
	}
	return 0;
}

// Segment tree stores the max query for the frequency array
// First we found the the closest index of the from left and right query (binary search) 
// Then we find 3 values i.e. frequency in left range, frequency in right range and the maximum frequency in the range in between (using max query segment tree)
