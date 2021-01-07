#include<cstdio>
using namespace std;

struct mystruct{
	int a, b;
	mystruct(int _a=0, int _b=0){
		a = _a;
		b = _b;
	}
	mystruct operator + (mystruct y){
		mystruct n;
		n.a = a+y.a;
		n.b = b+y.b;
		return n;
	}
};

int main(){
	mystruct x(1,2),y(10,29), c;
	c = x+y;
	printf("%d %d\n",c.a,c.b);
	return 0;
}
