#include<cstdio>
using namespace std;

class A{
	public:
		int a;
		A(int _a=0): a(_a){}
};

class B:public A{
	int b;
	public:
		B(int _b=0): b(_b){}
		void getA(){
			printf("%d\n",a);
		}
};

int main(){
	B ob;
	ob.getA();
	return 0;
}
