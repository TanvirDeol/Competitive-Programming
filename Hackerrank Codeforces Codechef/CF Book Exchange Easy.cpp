#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
#define MOD 1000000007
 
 
int main() {
	int t; cin >> t;
	while (t-- > 0) {
		int N; cin >> N;
		vector<int>v(N);
		for (int i = 0; i < N; i++) cin >> v[i];
		
		for (int q = 0; q < v.size(); q++) {
			int i = q; int count = 0;
			for (; i < v.size();) {
				if (count > 0) {
					i = v[i] - 1; count++;
					if (i == q) { cout << count << " "; count = 1; break; }
				}
				else {
					if (v[i] - 1 == i) { cout << 1 << " "; break; }
					else { i = v[i]-1; count++; }
				}
			}
		}cout << endl;
 
	}
	return 0;
}
