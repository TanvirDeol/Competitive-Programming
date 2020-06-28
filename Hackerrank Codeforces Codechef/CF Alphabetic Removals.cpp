#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;
 
 
int main() {
	int N, K; cin >> N >> K;
	string s; cin >> s;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	bool b = 1;
	vector<bool>vis(s.size(), 0);
	for (int i = 0; i < alpha.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == alpha[i] && !vis[j]) {
				vis[j] = 1;
				K--;
				if (K == 0) { b = 0; break; }
			}
		}if (!b)break;
	}
	string res;
	for (int i = 0; i < vis.size(); i++) {
		if (!vis[i])res += s[i];
	}
	cout << res << endl;
}
