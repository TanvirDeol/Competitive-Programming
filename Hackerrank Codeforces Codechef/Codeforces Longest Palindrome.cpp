#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool palin(string s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[(n - 1) - i])return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<string>words(n);
	vector<pair<string, string>>prs;
	vector<string>pals;
	vector<bool>vis(n, 0);
	for (int i = 0; i < n; i++)cin >> words[i];

	for (int i = 0; i < n; i++) {
		if (vis[i])continue;
		string s = words[i];
		string t = s; reverse(t.begin(), t.end());
		for (int j = 0; j < n; j++) {
			if (j == i)continue;
			if (words[j] == t) { vis[i] = 1; vis[j] = 1; prs.push_back({ s,t }); break; }
		}
		if (!vis[i] && palin(s)) { vis[i] = 1; pals.push_back(s); }
	}

	//	for (pair<string, string> pi : prs)cout << pi.first << " " << pi.second << endl;
	//	for (string pl : pals)cout << pl << endl;
	stack<string>st;
	int sum = 0;
	for (int i = 0; i < prs.size(); i++) {
		st.push(prs[i].first); sum += prs[i].first.size();
	}
	if (pals.size() > 0) { st.push(pals[0]); sum += pals[0].size(); }

	for (int i = prs.size() - 1; i >= 0; i--) {
		st.push(prs[i].second); sum += prs[i].second.size();
	}
	cout << sum << endl;
	while (!st.empty()) {
		cout << st.top(); st.pop();
	}cout << endl;
	return 0;
}