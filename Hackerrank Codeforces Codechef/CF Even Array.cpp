#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pi;
#define INF 3e18
 
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		int N; cin >> N;
		int ow = 0, ew = 0;
		int X;
		for (int i = 0; i < N; i++) {
			cin >> X; 
			if (X %2!= i %2) {
				if (X & 1)ow++;
				else ew++;
			}
		}
		if (ow == ew)cout << ow << endl;
		else cout << -1 << endl;
	}
	return 0;
}
