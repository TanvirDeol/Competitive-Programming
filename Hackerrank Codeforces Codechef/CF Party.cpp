#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
#define MOD 1000000007
int most;
vector<vector<int>>tree;
vector<bool>vis;
void dfs(int i, int lvl) {
	if (vis[i - 1])return;
	vis[i - 1] = 1;
	if (lvl > most)most = lvl;
	for (vector<int>::iterator it = tree[i - 1].begin(); it != tree[i - 1].end(); ++it) {
		if (vis[*it - 1])continue;
		else { dfs(*it, lvl + 1); }
	}
}

int main() {
	int N; cin >> N;
	most = 0;
	tree.resize(N, vector<int>());
	vis.resize(N, false);
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x != -1) {
			tree[x - 1].push_back(i + 1);
		}
		else tree[i].push_back(i + 1);
	}

	for (int i = 1; i <= N; i++) {
		fill(vis.begin(), vis.end(), false);
		dfs(i, 1);
	}
	cout << most << endl;
	return 0;
}