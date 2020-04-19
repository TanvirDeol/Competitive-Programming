#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef vector<vector<char>> graph;
typedef pair<char, char> pi;
#define mp make_pair
#define f first
#define se second

int main()
{
	graph net(26, vector<char>());
	stack<pi> st;
	vector<pi> ans;

	while (true) {
		string s; cin >> s;
		if (s == "**")break;
		char a = s[0]; char b = s[1];
		net[a - 65].push_back(b);
		net[b - 65].push_back(a);
		st.push(mp(a, b));
	}

	while (!st.empty()) {
		pi cur = st.top(); st.pop();
		vector<bool>vis(26, false);
		queue<char>que; que.push('A');
		bool found = false;
		while (!que.empty()) {
			char c = que.front(); que.pop(); vis[c - 65] = true;
			for (vector<char>::iterator it = net[c - 65].begin(); it != net[c - 65].end(); ++it) {
				if (c == cur.f) if (*it == cur.se)continue;
				if (c == cur.se) if (*it == cur.f)continue;
				if (*it == 'B') { found = true; break; }
				if (vis[*it - 65])continue;
				else { que.push(*it); vis[*it - 65] = true; }
			}
			if (found)break;
		}
		if (!found)ans.push_back(cur);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].f << ans[i].se << endl;
	}
	cout << "There are " << ans.size() << " disconnecting roads." << endl;

	return 0;
}