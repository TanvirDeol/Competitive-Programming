#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define MOD 1000000007
int most;
vector<vector<int>>graph;
vector<bool>vis;
vector<vector<int>>subsets;
vector<int>temp;

void dfs(int i) {
	if (vis[i])return;
	vis[i] = 1; temp.push_back(i);
	for (vector<int>::iterator it = graph[i - 1].begin(); it != graph[i - 1].end(); ++it) {
		if (vis[*it])continue;
		else { dfs(*it); }
	}
}

int main() {
	int N, M; cin >> N >> M;
	graph.resize(N, vector<int>());
	vis.resize(N + 1, false);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a - 1].push_back(b);
		graph[b - 1].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i])continue;
		dfs(i);
		subsets.push_back(temp);
		temp.clear();
	}
	cout << subsets.size() - 1 << endl;
	for (int i = 0; i < subsets.size() - 1; i++) {
		cout << subsets[i][0] << " " << subsets[i + 1][0] << endl;
	}

	return 0;
}