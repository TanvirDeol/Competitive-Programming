#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, int > pi;
#define INF 3e18

vector<vector<pi>>graph;

int main() {
	ll N = 0, M = 0; scanf("%ld %ld", &N, &M);
	graph.resize(N, vector<pi>());
	ll a, b, c;
	for (int i = 0; i < M; i++) {
		a = 0, b = 0, c = 0;
		scanf("%ld %ld %ld", &a, &b, &c);
		graph[a - 1].push_back({ c,b });
	}
	vector<ll>dist(N + 1, INF);
	priority_queue<pi>pq;
	dist[1] = 0;
	pq.push({ 0,1 });

	while (!pq.empty()) {
		ll cur = pq.top().second;
		auto a = pq.top();
		pq.pop();
		if (a.first > dist[cur])continue;
		for (auto node : graph[cur - 1]) {
			ll v = node.second; ll w = node.first;
			if (dist[cur] + w < dist[v]) {
				dist[v] = dist[cur] + w;
				pq.push({ dist[v],v });
			}
		}
	}
	for (int i = 1; i < dist.size(); i++) cout << dist[i] << " "; cout << endl;
	return 0;
}