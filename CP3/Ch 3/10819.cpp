#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
#include <iostream>
#include <cmath>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define Loop(i, a, n) for (int i = a; i < n; i++)
#define newline printf("\n");
#define scan(n) scanf("%d", &n)
#define mp make_pair
#define pb push_back
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vi price, favour;
int budget, n;
vvi dp;

int maxFavour(int moneySpent, int i)
{
	if (moneySpent > budget && budget <= 1800)
		return -1000;
	if (moneySpent > budget + 200)
		return -1000;
	if (i == n)
	{
		if (moneySpent > budget && moneySpent <= 2000)
			return -1000;
		return 0;
	}
	if (dp[i][moneySpent] != -1)
		return dp[i][moneySpent];
	int notake = maxFavour(moneySpent, i + 1);
	int take = maxFavour(moneySpent + price[i], i + 1) + favour[i];
	return dp[i][moneySpent] = max(notake, take);
}

int main()
{
	int ans;
	while (scanf("%d%d", &budget, &n) != EOF)
	{
		price = vi(n, 0);
		favour = vi(n, 0);
		dp = vvi(101, vi(11001, -1));
		loop(i, n)
			scanf("%d%d", &price[i], &favour[i]);
		printf("%d\n", maxFavour(0, 0));
	}
	return 0;
}
/*
	main thing to think is that how do you confine user to take price more that 2000 if we want to get 200 discount
	let the user take any amount and ask at the end 
		if moneySpent > budget and moneySpent <= 2000, if yes then return -1000 (not possible)
		else we can spend the money under budget due to discount 
*/