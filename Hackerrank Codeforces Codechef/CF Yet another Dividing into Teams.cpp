#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
#define MOD 1000000007
 
 
int main() {
	int t; cin >> t;
	while (t-- > 0) {
		int N; cin >> N;
		bool b = false;
		vector<int>v(N);
		for (int i = 0; i < N; i++) cin >> v[i];
		sort(v.begin(), v.end());
		for (int i = 0; i < N-1; i++) {
			if (v[i + 1] == v[i] + 1) { b = 1; break; }
		}
		if (b)cout << 2 << endl;
		else cout << 1 << endl;
	}
	return 0;
}
