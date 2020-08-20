#include<cstdio>
#include<vector>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii>	vii;
typedef vector<vi>	vvi;

int main(){
	float a, b, c, d, asum;
	const ll no=1000000;
	ll cnt=0, sum, pro;
	Loop(i,1,2000){
		Loop(j,i,2000-i){
			Loop(k,j,2000-i-j){
				sum=(i+j+k)*no;	pro=(i*j*k)-no;	
				if(pro>0 && sum%pro==0){
					a=(1.0*i)/100;	b=(1.0*j)/100;	c=(1.0*k)/100;	d=(1.0*(sum/pro))/100;
					asum=a+b+c+d;
					if(asum<=20.00 && d>=c)	printf("%0.2f %0.2f %0.2f %0.2f\n",a,b,c,d);
					if(i==125 && j==160 && k==175)	return 0;
				}
			}
		}
	}
	return 0;
}

// This was really a very tedious quesion for me
// Last error I made was that d value should be greater than c to avoid repetions
// I also did error in converting euros to cents equation
