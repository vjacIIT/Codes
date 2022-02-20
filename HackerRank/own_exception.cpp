#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class Calculator{
    private:
        class myexception : public exception{
        public:
            const char* what() const throw(){       		// it doesn't throw any exception
                return "n and p should be non-negative";
            }
        };
    public:
        int power(int n, int p) throw(myexception){         // tells which kind of exception it can throw 
            if(n<0 || p<0){
                myexception e;
                throw e;
            }
            else{
                int mpower = 1;
                for(int i=0; i<p; i++){
                    mpower*=n;
                }
                return mpower;
            }
        }
};
int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}
