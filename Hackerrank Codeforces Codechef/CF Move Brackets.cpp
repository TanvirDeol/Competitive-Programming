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


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T-- > 0) {
		int N; cin >> N;
		vector<bool>vis(N, 0);
		string s; cin >> s;
		for (int i = 0; i < N; i++) {
			if (vis[i])continue;
			if (s[i] == '(') {
				for (int j = i+1; j < N; j++) {
					if (vis[j])continue;
					if (s[j] == ')') { vis[i] = 1; vis[j] = 1; break; }
				}
			}
		}
		int cnt = 0;
		for (bool b : vis)if (!b)cnt++;
		cout << cnt / 2 << endl;
	}
	return 0;

}
