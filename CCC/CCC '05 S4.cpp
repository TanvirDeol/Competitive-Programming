#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair < string,ll> pi;
#define INF 3e18
long mod(long a, long b)
{
	return (a % b + b) % b;
}
map<string, vector<string>>graph;
unordered_map<string, string>par;
unordered_map<string, bool>vis;
int slow;
void dfs(string cur, int t) {
	slow++;
	if (vis[cur]) {
		if (par[cur] == "-1") { slow = max(slow, t); return; }
		else {
			dfs(par[cur], t + 1); return;
		}
	}

	vis[cur] = 1;
	if (graph[cur].empty())return;
	else {
		for (auto node : graph[cur]) { dfs(node, t + 1); slow++; }
	}
}


int main() {
	int T; cin >> T;
	for (int q = 0; q < T; q++) {
		slow = 0;
		int N; cin >> N;
		vector<string>nm(N);
		
		for (int i = 0; i < N; i++) { cin >> nm[i]; vis[nm[i]] = 0; }

		graph[nm[N - 1]].push_back(nm[0]);
		par[nm[0]] = nm[N - 1];
		par[nm[N - 1]] = "-1";

		for (int i = 0; i < nm.size()-1; i++) {
			if (nm[i + 1] != par[nm[i]]) {
				graph[nm[i]].push_back(nm[i + 1]);
				par[nm[i + 1]] = nm[i];
			}
			else continue;
		}
		dfs(nm[N - 1], 0);
		slow--;
		for (string s : nm)vis[s] = 0;

		int cnt = 0;
		queue<pi>que; que.push({ nm[N - 1], 0 });

		while (!que.empty()) {
			pi cur = que.front(); que.pop();
			//if node already vis, it means its on its way back
			if (vis[cur.first]) {
				if (par[cur.first] == "-1") { cnt = cur.second; continue; }
				else {que.push({par[cur.first], cur.second + 1 }); continue;}
			}
			//if its leaf node, turn around
			if (graph[cur.first].empty()) {
				que.push({ par[cur.first], cur.second + 1 }); continue;
			}
			else {
				//otherwise push all of its child nodes
				for (auto node : graph[cur.first]) {
					que.push({ node,cur.second + 1 });
				}
			}
			if (!vis[cur.first])vis[cur.first] = 1;

		}
		//cout << slow << " " << cnt << endl;
		cout << abs(slow-cnt)*10 << endl;
		graph.clear(); par.clear(); vis.clear(); nm.clear();
	}
	return 0;
}
