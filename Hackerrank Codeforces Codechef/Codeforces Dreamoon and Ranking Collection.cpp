#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	vector<bool>vis(200, 0);
	int t; cin >> t;
	for (int q = 0; q < t; q++) {

		int n, x; cin >> n >> x;
		for (int i = 0; i < n; i++) {
			int ind; cin >> ind; vis[ind - 1] = true;
		}
		int i = 0;

		for (i = 0; vis.size(); i++) {
			if (x == 0 && !vis[i])break;
			else if (!vis[i] && x > 0) {
				vis[i] = true; x--;
			}
		}
		//for (bool b : vis)cout << b << " ";
		//cout << endl;
		cout << i << endl;
		fill(vis.begin(), vis.end(), 0);
	}
	return 0;
}
