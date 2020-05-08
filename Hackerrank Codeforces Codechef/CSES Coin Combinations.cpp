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
	for (ll i = 0; i < n; i++)cin >> arr[i];
	vector<ll>dp(x + 1, 0);
	ll small = *min_element(arr.begin(), arr.end());
	if (small > x) {
		cout << "0" << endl; return 0;
	}
	dp[small] = 1;

	for (ll i = small + 1; i <= x; i++) {
		ll sum = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (i >= arr[j])sum += dp[i - arr[j]];
			if (i == arr[j])sum++;

		}
		dp[i] = sum % MOD;
	}
	//for (int c : dp)cout << c << " "; cout << endl;
	cout << dp[x] % MOD << endl;
	return 0;
}