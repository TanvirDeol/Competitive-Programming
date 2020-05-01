#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	for (int q = 0; q < t; q++) {
		ll n, k; cin >> n >> k;
		if (pow(k, 2) > n)cout << "NO" << endl;
		else if ((k & 1) != (n & 1))cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}