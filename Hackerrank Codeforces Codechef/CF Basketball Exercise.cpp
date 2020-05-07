#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long mod(long a, long b)
{
	return (a % b + b) % b;
}


int main() {
	ll N; cin >> N;
	vector<ll>A(N); vector<ll>B(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++)cin >> B[i];
	vector<vector<ll>> dp(2, vector<ll>(N, 0));
	dp[0][0] = A[0]; dp[1][0] = B[0];
	for (int i = 1; i < N; i++) {
		if (i > 1) {
			dp[0][i] = max(dp[1][i - 2], max(dp[1][i - 1], dp[0][i - 2])) + A[i];
			dp[1][i] = max(dp[0][i - 2], max(dp[0][i - 1], dp[1][i - 2])) + B[i];
		}
		else {
			dp[0][i] = dp[1][i - 1] + A[i];
			dp[1][i] = dp[0][i - 1] + B[i];
		}
	}
	cout << max(dp[0][N - 1], dp[1][N - 1]) << endl;
}
