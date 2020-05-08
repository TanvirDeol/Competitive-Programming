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
	int cnt = 0;
	while (n > 0) {
		string s = to_string(n);
		int m = 0;
		for (int i = 0; i < s.size(); i++) {
			m = max(m, s[i] - 48);
		}
		n -= m; cnt++;
	}
	cout << cnt << endl;
	return 0;
}