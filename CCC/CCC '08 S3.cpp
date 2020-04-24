#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> pi;
#define mp make_pair
#define f first
#define s second

int rdir[4] = { -1,1,0,0 }; int cdir[4] = { 0,0,-1,1 };
int main() {
	int T; cin >> T;
	for (int q = 0; q < T; q++) {
		int r, c; cin >> r >> c;
		vector<vector<char>> grid(r, vector<char>(c));
		vector<vector<bool>> vis(r, vector<bool>(c));
		vector<int>costs;
		for (int i = 0; i < r; i++) {
			string inp; cin >> inp;
			for (int j = 0; j < c; j++) {
				grid[i][j] = inp[j]; if (inp[j] == '*')vis[i][j] = true; else vis[i][j] = false;
			}
		}
		queue<pi> que;
		que.push({ {0,0},1 });
		while (!que.empty()) {
			pi cur = que.front(); que.pop();
			if (cur.f.f < 0 || cur.f.f >= r || cur.f.s < 0 || cur.f.s >= c) continue;
			if (vis[cur.f.f][cur.f.s]) continue; else vis[cur.f.f][cur.f.s] = true;
			if (cur.f.f == r - 1 && cur.f.s == c - 1) { costs.push_back(cur.s); continue; }
			if (grid[cur.f.f][cur.f.s] == '+') {
				que.push({ {cur.f.f + rdir[0],cur.f.s + cdir[0]},cur.s + 1 }); //u
				que.push({ {cur.f.f + rdir[1],cur.f.s + cdir[1]},cur.s + 1 });//d
				que.push({ {cur.f.f + rdir[2],cur.f.s + cdir[2]},cur.s + 1 });//l
				que.push({ {cur.f.f + rdir[3],cur.f.s + cdir[3]},cur.s + 1 });//r
			}
			else if (grid[cur.f.f][cur.f.s] == '|') {
				que.push({ {cur.f.f + rdir[0],cur.f.s + cdir[0]},cur.s + 1 }); //u
				que.push({ {cur.f.f + rdir[1],cur.f.s + cdir[1]},cur.s + 1 });//d
			}
			else if (grid[cur.f.f][cur.f.s] == '-') {
				que.push({ {cur.f.f + rdir[2],cur.f.s + cdir[2]},cur.s + 1 });//l
				que.push({ {cur.f.f + rdir[3],cur.f.s + cdir[3]},cur.s + 1 });//r
			}
		}
		if (costs.empty()) cout << -1 << endl;
		else cout << *min_element(costs.begin(), costs.end()) << endl;
		costs.clear(); grid.clear(); vis.clear();
	}

	return 0;
}