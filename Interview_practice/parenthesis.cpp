/*
	Given a set of symbols and operators, put parenthesis in the expression such that:
		Expression evaluates to be true
		
	Example : symbols = [T,F,T], operator = [^,&]
	Answer:	2 ways -> ((T^F)&T)  and (T^(F&T))
*/

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> T,F;
	int n;
	string sym, op;
	cin>>sym>>op;
	n = sym.size();
	T = vector<vector<int>> (n,vector<int>(n));
	F = vector<vector<int>> (n,vector<int>(n));
	for(int i=0; i<n; i++){
		T[i][i] = sym[i]=='T' ? 1:0;
		F[i][i] = sym[i]=='F' ? 1:0;
	}
	
	// Now fill T[i][i+1], T[i][i+2], T[i][i+3]... in order 
    // And F[i][i+1], F[i][i+2], F[i][i+3]... in order 
    for (int gap=1; gap<n; ++gap) 
    { 
        for (int i=0, j=gap; j<n; ++i, ++j) 
        { 
            T[i][j] = F[i][j] = 0; 
            for (int g=0; g<gap; g++) 
            { 
                // Find place of parenthesization using current value 
                // of gap 
                int k = i + g; 
  
                // Store Total[i][k] and Total[k+1][j] 
                int tik = T[i][k] + F[i][k]; 
                int tkj = T[k+1][j] + F[k+1][j]; 
  
                // Follow the recursive formulas according to the current 
                // operator 
                if (oper[k] == '&') 
                { 
                    T[i][j] += T[i][k]*T[k+1][j]; 
                    F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]); 
                } 
                if (oper[k] == '|') 
                { 
                    F[i][j] += F[i][k]*F[k+1][j]; 
                    T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]); 
                } 
                if (oper[k] == '^') 
                { 
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]; 
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]; 
                } 
            } 
        } 
    } 
	cout<<T[0][n-1]<<endl;
	return 0;
}

/*
	T[i][j] = # ways to parenthesise so that expression comes out to be true
*/
