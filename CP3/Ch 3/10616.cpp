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

int main()
{
	vi a;
	vector<vvi> dp;
	int n, q, m, d, r, sno = 1;
	while (scanf("%d%d", &n, &q) != EOF)
	{
		if (n == 0 && q == 0)
			break;
		printf("SET %d:\n", sno);
		sno++;
		a = vi(n + 1, 0);
		loop(i, n)
			scan(a[i + 1]);

		loop(qr, q)
		{
			scanf("%d%d", &d, &m);
			vi b = vi(n + 1, 0);
			loop(i, n + 1)
				b[i] = ((a[i] % d) + d) % d;
			sort(b.begin(), b.end());
			dp = vector<vvi>(n + 1, vvi(m + 1, vi(d, 0)));
			// seen = i, taken = 0, required sum = 0
			loop(i, n + 1)
				dp[i][0][0] = 1;
			dp[0][0][0] = 1;
			Loop(i, 1, n + 1)
			{
				for (int j = 1; j <= i && j <= m; j++)
				{
					for (int k = 0; k < d; k++)
					{
						// either take the i'th number or not
						r = ((k - b[i]) % d) + d;
						dp[i][j][k] = dp[i - 1][j - 1][r % d] + dp[i - 1][j][k];
					}
				}
			}
			printf("QUERY %d: %d\n", qr + 1, dp[n][m][0]);
		}
	}
	return 0;
}
/*
	dp[i][j][k] = no of ways to form sum % d == k when we have only i numbers and have taken exactly j out of if
*/