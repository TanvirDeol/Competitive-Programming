#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 3e18
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		int N; cin >> N;
		vector<int>arr(2*N);
		vector<bool>vis(2*N, false);
		int odds = 0; int odix = -2; int evens = 0; int edix = -2;
		for (int i = 0; i < 2 * N; i++) {
			cin >> arr[i]; 
			if (arr[i] & 1) { odds++; odix = i; }
			if (!(arr[i] & 1)) { evens++; edix = i; }
 
		}
		int cnt = 0;
		if (odds & 1) { vis[odix] = 1; cnt++; }
		if (evens & 1) { vis[edix] = 1; cnt++; }
		if (cnt == 0) {
			if (evens > 2) {
				for (int i = 0; i < arr.size(); i++) {
					if (arr[i] % 2 == 0) {
						cnt++; vis[i] = 1; if (cnt == 2)break;
					}
				}
			}
			else {
				for (int i = 0; i < arr.size(); i++) {
					if (arr[i] % 2 == 1) {
						cnt++; vis[i] = 1; if (cnt == 2)break;
					}
				}
			}
		}
		vector<int>oix;
		int x = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (vis[i])continue;
			if (arr[i] & 1)oix.push_back(i);
			if (!(arr[i] & 1)) {
				x++;
				if (x == 1)cout << i + 1;
				if (x == 2) { cout << " " << i + 1 << endl; x = 0; }
			}
		}x = 1;
		for (int i = 0; i < oix.size(); i++) {
			if (x == 1) {
				cout << oix[i] + 1; x++;
			}
			else if (x == 2) {
				cout << " "<<oix[i] + 1<<endl; x = 1;
			}
		}
 
	}
	return 0;
}
