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
	ll n, x; cin >> n >> x;
	vector<ll>arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];
	vector<ll>dp(x + 1, 1e9);
	int small = *min_element(arr.begin(), arr.end());
	if (small > x) { cout << "-1" << endl; return 0; }

	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - arr[j] >= 0) {
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
			}
		}
	}
	cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
	return 0;
}