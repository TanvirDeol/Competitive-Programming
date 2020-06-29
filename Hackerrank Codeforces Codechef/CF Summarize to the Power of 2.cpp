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


int main() {
	setp;
	int N; cin >> N;
	vi arr(N);
	map<int, int>mxp;
	F0R(i, N) { cin >> arr[i]; mxp[arr[i]]++;}
	int cnt = 0;

	F0R(i, N) {
		bool b = 0;
		F0R(j, 31) {
			int x = (1 << j)-arr[i];
			if (mxp.count(x) && (mxp[x] > 1 || mxp[x] == 1 && x != arr[i])) {b = 1; break;}
		}
		if (!b)cnt++;
	}
	cout << cnt << endl;
	return 0;

}
