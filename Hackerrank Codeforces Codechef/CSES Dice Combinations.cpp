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
	ll N; cin >> N;
	vector<ll>dp(N + 1, 0);
	dp[0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i >= j)dp[i] += dp[i - j] % MOD;
		}
	}
	cout << dp[N] % MOD << endl;
	return 0;
}