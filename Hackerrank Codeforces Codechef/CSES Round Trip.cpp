#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define MOD 1000000007

vector<vector<int>>graph;
vector<bool>vis;
vector<int>parent;
vector<int>route;
bool found;
void printCycle(int i, int startOfCycle, int cnt) {
	if (parent[i] != startOfCycle) {
		printCycle(parent[i], startOfCycle, cnt + 1);
	}
	route.push_back(parent[i]);
}

void dfs(int i, int par) {
	vis[i] = 1;
	parent[i] = par;
	for (auto node : graph[i - 1]) {
		if (vis[node]) {
			if (node == par)continue;
			else { printCycle(i, node, 1); route.push_back(i); found = 1; return; }
		}
		dfs(node, i);
		if (found)return;
	}
}
int main() {
	found = 0;
	int N, M; cin >> N >> M;
	graph.resize(N, vector<int>());
	vis.resize(N + 1, false);
	parent.resize(N + 1, -1);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a - 1].push_back(b);
		graph[b - 1].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i])continue;
		dfs(i, 1);
		if (found)break;
	}
	if (route.empty()) {
		cout << "IMPOSSIBLE" << endl; return 0;
	}
	cout << route.size() + 1 << endl;
	for (int r : route)cout << r << " ";
	cout << route[0] << endl;
	return 0;
}