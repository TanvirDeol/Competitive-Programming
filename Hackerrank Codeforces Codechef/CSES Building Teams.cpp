#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define MOD 1000000007
int most;
vector<vector<int>>graph;
vector<bool>vis;
bool cycle;
vector<int>teams;

void dfs(int i, int team) {
	vis[i] = 1;
	teams[i] = team;
	for (auto node : graph[i - 1]) {
		if (vis[node]) {
			if (teams[node] == team) { cycle = 1; return; }
			else continue;
		}
		int t = 1; if (team == 1)t = 2;
		dfs(node, t);
		if (cycle)return;
	}
}
int main() {
	cycle = 0;
	int N, M; cin >> N >> M;
	graph.resize(N, vector<int>());
	vis.resize(N + 1, false);
	teams.resize(N + 1, 0);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a - 1].push_back(b);
		graph[b - 1].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i])continue;
		dfs(i, 1);
	}
	if (!cycle) {
		for (int i = 1; i <= N; i++)cout << teams[i] << " "; cout << endl;
	}
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}