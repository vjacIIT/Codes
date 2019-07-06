// This is another implementation using pure segment tree
// I found out it to be very hard to think as well as implement

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int l, r, lno, rno, f;		// left, right, left and right number, final freq
};

node *stree;
int *ar, n, fo, lo;

void Occ(int no){
	int st,end,m;
	st=0;	end=n-1;	fo=-1;	lo=-1;		// first and last occurence of number
	while(st<=end){
		m=(st+end)>>1;
		if(ar[m]==no){	fo=m;	end=m-1;	}
		else if(ar[m]>no)	end=m-1;
		else	st=m+1;
	}
	st=0;	end=n-1;
	while(st<=end){
		m=(st+end)>>1;
		if(ar[m]==no){	lo=m;	st=m+1;	}
		else if(ar[m]>no)	end=m-1;
		else	st=m+1;
	}
	return;
}

int itsn(int l, int r){
	int lmin, rmin;
	lmin= max(l,fo);	rmin=min(r,lo);			// max of left and first occurence, min of right and last occurence
	return (rmin-lmin+1);
}

void tree(int l, int r, int p){
	int f1, f2;
	int m=(l+r)>>1;
	stree[p].l=l;	stree[p].r=r;
	if(l==r){
		stree[p].lno=ar[l];	stree[p].rno=ar[r];	
		stree[p].f=1;
		return;
	}
	tree(l,m,(p<<1)+1);
	tree(m+1,r,(p<<1)+2);
	stree[p].lno=stree[(p<<1)+1].lno; 
	stree[p].rno=stree[(p<<1)+2].rno;
	stree[p].f = max(stree[(p<<1)+1].f,stree[(p<<1)+2].f);
	if(stree[(p<<1)+1].rno==stree[(p<<1)+2].lno){
		Occ(stree[(p<<1)+1].rno);						// important step, first and last occurence of number
		f1 = itsn(l,m);		f2=itsn(m+1,r);				// helps to find the frequency on left and right node
		stree[p].f = max(stree[p].f,f1+f2);
	}
	return;
}

int rmq(int li, int ri, int p){
	int p1, p2;
	int l=stree[p].l, r=stree[p].r, m=(l+r)>>1;
	if(li>r || ri<l)	return -1;
	if(li<=l && ri>=r)	return stree[p].f;
	p1 = rmq(li,ri,(p<<1)+1);
	p2 = rmq(li,ri,(p<<1)+2);
	if(p1==-1)	return p2;
	if(p2==-1)	return p1;
	
	int ans=max(p1,p2);
	if(stree[(p<<1)+1].rno==stree[(p<<1)+2].lno){
		Occ(stree[(p<<1)+1].rno);								// important step, first and last occurence of number
		p1 = itsn(max(li,l),m);		p2=itsn(m+1,min(ri,r));		// helps to find the frequency on left and right node
		ans=max(ans,p1+p2);
		return ans;
	}
	else	return max(p1,p2);
}

int main(){
	char str[100];
	int q, l, r;
	while(fgets(str,50,stdin)){
		if(!strcmp(str,"0\n"))	break;
		
		sscanf(str,"%d%d",&n,&q);
		ar = new int[n];
		for(int i=0; i<n; i++)	scanf("%d",ar+i);
		
		stree = new node[4*n];
		tree(0,n-1,0);
		
		for(int i=0; i<q; i++){
			scanf("%d%d",&l,&r);
			printf("%d\n",rmq(l-1,r-1,0));
		}
		scanf("\n");
		delete []stree;	delete []ar;
	}
	return 0;
}

// This method is pure segment tree
// At each step we store the max frequency taking into consideration of the rightmost value of left node and leftmost value of right node
// If both are same then we may add the corresponding frequencies (merge node)

// This merge is also required in range max query also, because the same concept may happen there also
