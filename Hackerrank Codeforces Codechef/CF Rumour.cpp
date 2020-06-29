#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
#define setp ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i, a, b) for (int i=a; i<(b); i++) 
#define F0R(i, a) for (int i=0; i<(a); i++) 
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--) 
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(x) (int)(x).size() 
#define mp make_pair 
#define pb push_back 
#define fs first 
#define sc second 
#define lb lower_bound 
#define ub upper_bound 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
vb vis;
ll cnt;
vl idxs;
vector<vl>graph;
void dfs(int n) {
	idxs[n] = cnt;
	for (auto &it : graph[n]) {
		if (vis[it])continue;
		vis[it] = 1;
		idxs[it] = cnt;
		dfs(it);
	}
}

int main() {
	setp;
	ll N, M; cin >> N >> M;
	vl cost(N+1);
	FOR(i,1, N+1)cin >> cost[i];
	vis.resize(N+1, 0);
	graph.resize(N+1, vl());
	F0R(i, M) { 
	ll x, y; 
	cin >> x >> y; 
	graph[x].push_back(y); 
	graph[y].push_back(x); 
	}
	idxs.resize(N+1, 0);
	cnt = 1;
	FOR(i, 1, N + 1) {
		if (vis[i])continue;
		dfs(i);
		cnt++;
	}
	map<ll, ll>mxp;
	FOR(i, 1, cnt)mxp[i] = INT_MAX;
	FOR(i,1, idxs.size()) {
		ll c = idxs[i];
		mxp[c] = min(mxp[c],cost[i]);
	}

	ll sum = 0;
	for(auto x:mxp) {
		if(mxp[x.fs]!=INT_MAX)sum += mxp[x.fs];
	}
	cout << sum << endl;
	return 0;

}
