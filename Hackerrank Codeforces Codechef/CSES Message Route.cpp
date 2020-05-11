#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define MOD 1000000007
int most;
vector<vector<pi>>graph;
vector<bool>vis;
vector<int>pr;
void printPath(int j) {
	if (pr[j] == -1) { cout << j << " "; return; }
	printPath(pr[j]);
	cout << j << " ";
}

int main() {
	int N, M; cin >> N >> M;
	graph.resize(N, vector<pi>());
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a - 1].push_back({ 1,b });
		graph[b - 1].push_back({ 1,a });
	}
	vector<int>dist(N + 1, INT_MAX);
	priority_queue<int>pq;
	pr.resize(N + 1, -1);
	pq.push(1); dist[1] = 1;

	while (!pq.empty()) {
		int v = pq.top(); pq.pop();
		for (auto e : graph[v - 1]) {
			int node = e.second; int w = e.first;
			if (dist[v] + w < dist[node]) {
				pr[node] = v;
				dist[node] = dist[v] + w;
				pq.push(node);
			}
		}
	}
	if (dist[N] != INT_MAX) { cout << dist[N] << endl; printPath(pr[N]); cout << N << endl; }
	else cout << "IMPOSSIBLE" << endl;

	return 0;
}
