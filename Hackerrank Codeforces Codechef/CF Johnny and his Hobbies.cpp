#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;


int main() {
	int T; cin >> T;
	while (T-- > 0) {
		int N; cin >> N;
		vector<int>s(N);
		sort(s.begin(), s.end());
		for (int i = 0; i < N; i++) {
			cin >> s[i];
		}
		bool b = 1;
		int k = 1;
		for (; k <= 1024; k++) {
			for (int i = 0; i < s.size(); i++) {
				b = 1;
				int x = (k ^ s[i]);
				if (find(s.begin(), s.end(), x) == s.end()) {
					b = 0; break;
				}
			}
			if (b)break;
		}
		if (k < 1025)cout << k << endl;
		else cout << -1 << endl;
	}
	return 0;
}
