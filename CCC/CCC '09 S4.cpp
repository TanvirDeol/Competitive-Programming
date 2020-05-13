#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef int ll;
typedef pair <int,int> pi;
#define INF INT_MAX
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

long mod(long a, long b)
{
	return (a % b + b) % b;
}
vector<vector<pi>>graph;
int main() {
	ll N, T; scan(N); scan(T);
	graph.resize(N + 1, vector<pi>());
	ll a=0, b=0, c=0;
	for (ll i = 0; i < T; i++) {
		scan(a); scan(b); scan(c);
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}
	ll K; scan(K);
	vector<pi>data(K);
	ll city=0, cost=0;
	for (ll i = 0; i < K; i++) {
		scan(city); scan(cost);
		data[i] = { city,cost }; 
	}
	ll D; cin >> D;
	vector<ll>dist(N + 1, INF);
	dist[D] = 0;

	priority_queue<pi>pq; pq.push({ 0,D });

	while (!pq.empty()) {
		pi cur = pq.top(); pq.pop();
		ll ct = cur.second;
		for (auto node : graph[ct]) {
			ll v = node.second; ll w = node.first;
			if (dist[v] > dist[ct] + w) {
				dist[v] = dist[ct] + w;
				pq.push({ dist[v],v });
			}
		}
	}
	ll least = INF;
	for (ll i = 0; i < K; i++) least = min((int)least, (int)dist[data[i].first] + data[i].second);
	cout << least << endl;
	return 0;
}
