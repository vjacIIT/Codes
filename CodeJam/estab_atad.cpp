#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

int b;
vector<int> ans;

int query(int i){
	int d;
	cout<<i<<endl;
	cin>>d;
	return d;
}

void solve(){
	int l = 1, r = b, same, diff, q1, q2, temp;
	for(int ind=1; true; ind+=2){
		if(ind%10==1 && ind!=1){
			same = -1;
			diff = -1;
			for(int s=1; s<l; s++){
				if(ans[s]==ans[b-s+1])					// same bits
					same= s;
				else									// different bits
					diff = s;
			}
			if(same==-1){								// all bits from left and right are complement
				q1 = query(1);
				if(ans[1]!=q1){							// complemented/reverse both same
					for(int s=1; s<=l; s++){
						ans[s]^=1;
						ans[b-s+1]^=1;
					}
				}
				q2 = query(1);							// else string remain same
			}
			else if(diff==-1){							// all bits were same
				q1 = query(1);
				if(ans[1]!=q1){							// complement/reverse+complement both same
					for(int s=1; s<=l; s++){
						ans[s]^=1;
						ans[b-s+1]^=1;
					}
				}
				q2 = query(1);
			}
			else{										// some bits are same and some not
				q1 = query(same);
				q2 = query(diff);
				if(ans[same]==q1 && ans[diff]!=q2){			// reverse
					for(int s=1; s<l; s++){
						temp = ans[s];
						ans[s] = ans[b-s+1];
						ans[b-s+1] = temp;
					}
				}
				else if(ans[same]!=q1 && ans[diff]!=q2){		// complement
					for(int s=1; s<=l; s++){
						ans[s]^=1;
						ans[b-s+1]^=1;
					}
				}
				else if(ans[same]!=q1 && ans[diff]==q2){			// reverse+complement
					for(int s=1; s<l; s++){
						temp = ans[s];
						ans[s] = ans[b-s+1];
						ans[b-s+1] = temp;
					}
					for(int s=1; s<=l; s++){
						ans[s]^=1;
						ans[b-s+1]^=1;
					}
				}
			}
			ind+=2;
		}
		ans[l] = query(l);
		ans[r] = query(r);
		l++;
		r--;
		if(l>r){
			for(int i=1; i<=b; i++){
				cout<<ans[i];
			}
			cout<<endl;
			string response;
			cin>>response;
			assert(response == "Y");
			return;
		}
	}
}

int main(){
	int t;
	cin>>t>>b;
	while(t--){
		ans = vector<int>(b+1);
		solve();
	}
	return 0;
}

// So the idea is taken from erricto
// Store the bits which have same and different values, then do computation accodingly
