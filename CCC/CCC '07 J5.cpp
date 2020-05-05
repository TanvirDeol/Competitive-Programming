#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>arr = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
ll A, B;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	ll N; cin >> N;
	for (int i = 0, a; i < N; i++) { cin >> a; arr.push_back(a); }
	sort(arr.begin(), arr.end());
	vector<ll>dp(arr.size(), 0);
	dp[0] = 1;
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (abs(arr[i] - arr[j]) >= A && abs(arr[i] - arr[j] <= B)) {
				dp[i] += dp[j];
			}
		}
	}
	cout << dp[dp.size() - 1] << "\n";
	return 0;
}
