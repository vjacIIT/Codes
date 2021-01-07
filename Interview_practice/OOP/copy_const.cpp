#include<cstdio>
using namespace std;

class Complex{
	public:
		int real, com;
		Complex(int _real=0, int _com=0): real(_real), com(_com){}
		Complex(const Complex &c): real(c.real), com(c.com){}
};

int main(){
	Complex c1(1,2), c2;
	c2 = c1;
	printf("%d %d\n",c2.real,c2.com);
	return 0;
}
