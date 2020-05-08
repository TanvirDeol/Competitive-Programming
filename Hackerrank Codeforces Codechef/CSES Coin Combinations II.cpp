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
	int n, x; cin >> n >> x;
	vector<int>arr(n + 1, 0);
	for (int i = 1; i <= n; i++)cin >> arr[i];
	vector<vector<int>>dp(n + 1, vector<int>(x + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			int num = arr[i];
			if (j < num)dp[i][j] = dp[i - 1][j] % MOD;
			else {
				dp[i][j] = (dp[i][j - num] + dp[i - 1][j]) % MOD;
				if (j == num)dp[i][j]++;
			}
		}
	}
	//	for (auto a : dp) {	for (ll b : a)cout << b << " "; cout << endl;}
	cout << dp[n][x] % MOD << endl;
	return 0;
}