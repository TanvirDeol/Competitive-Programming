#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t-- > 0) {
		ll n, x; cin >> n >> x;
		vector<ll>data(n);
		for (int i = 0; i < n; i++)cin >> data[i];
		sort(data.rbegin(), data.rend());
		ll sum = 0;
		ll i = 0;
		for (; i < n; i++) {
			sum += data[i];
			if (sum < (i + 1) * x) { break; }
		}
		cout << i << endl;
	}

	return 0;
}