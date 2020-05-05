#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	ll N; cin >> N;
	vector<ll>arr(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	vector<ll>U = arr;
	sort(U.begin(), U.end());
	for (int i = 0; i < N; i++) if (i > 0)arr[i] += arr[i - 1];
	for (int i = 0; i < N; i++) if (i > 0)U[i] += U[i - 1];

	ll M; cin >> M;
	for (ll i = 0; i < M; i++) {
		ll q, l, r; cin >> q >> l >> r;
		ll ans = 0;
		if (q == 1) {
			if (l == 1)ans = arr[r - 1];
			else ans = arr[r - 1] - arr[l - 2];
		}
		else {
			if (l == 1)ans = U[r - 1];
			else ans = U[r - 1] - U[l - 2];
		}
		cout << ans << endl;
	}
	return 0;
}
