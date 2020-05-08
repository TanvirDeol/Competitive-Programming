#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define MOD 1000000007
long mod(long a, long b)
{
	return (a % b + b) % b;
}


int main() {
	int n; cin >> n;
	vector<vector<int>>dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			char c = s[j];
			if (c == '.') {
				if (i > 0 && j == 0 && dp[i - 1][j] == -1)dp[i][j] = -1;
				else if (j > 0 && i == 0 && dp[i][j - 1] == -1) dp[i][j] = -1;
				else if (i == 0 || j == 0)dp[i][j] = 1;
				else dp[i][j] = 0;
			}
			else { dp[i][j] = -1; }
		}
	}
	//	for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++)cout << dp[i][j] << " "; cout << endl;}

	int l, u;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (dp[i][j] == -1)continue;
			l = dp[i][j - 1]; u = dp[i - 1][j]; if (l == -1)l++; if (u == -1)u++;
			dp[i][j] = (l + u) % MOD;
		}
	}
	//	cout << endl; for (int i = 0; i < n; i++) {		for (int j = 0; j < n; j++)cout << dp[i][j] << " "; cout << endl;	}
	if (dp[n - 1][n - 1] == -1)cout << 0 << endl;
	else cout << dp[n - 1][n - 1] << endl;
	return 0;
}