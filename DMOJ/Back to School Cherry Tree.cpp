#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 3e18
long mod(long a, long b)
{
	return (a % b + b) % b;
}

vector<vector<pi>>graph;
vector<int>cherries;
int C, K;
pi bfs(int node, int bSum, int cSum) {
	queue<int> que;
	que.push(node);
	while (!que.empty()) {
		int cur = que.front(); que.pop();
		for (vector<pi>::iterator it = graph[cur - 1].begin(); it != graph[cur - 1].end(); ++it) {
			bSum += it->first; cSum += cherries[it->second - 1];
			//if (bSum <= K && cSum >= C) { return true; }
			que.push(it->second);
		}
	}
	return { bSum, cSum };
}

int main() {
	int N; cin >> N >> C >> K;
	cherries.resize(N);
	for (int i = 0; i < N; i++)cin >> cherries[i];
	graph.resize(N, vector<pi>());
	int a, b, w;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> w;
		graph[a - 1].push_back({ w,b });
	}
	int cuts = 0;
	queue<int>que;
	que.push(1);
	while (!que.empty()) {
		int node = que.front(); que.pop();
		for (vector<pi>::iterator it = graph[node - 1].begin(); it != graph[node - 1].end(); ++it) {
			pi b = bfs(it->second, it->first, cherries[it->second - 1]);
			if (b.first <= K && b.second >= C) { cuts++; que.push(it->second);  }
			else if (b.second >=C) { que.push(it->second); }
		}
	}
	cout << cuts << endl;
	return 0;
}
