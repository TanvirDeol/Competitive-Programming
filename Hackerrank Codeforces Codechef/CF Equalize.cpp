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
	string A, B; cin >> A >> B;
	int cost = 0;
	F0R(i, A.size()) {
		if (B[i] =='1'&& B[i]!= A[i]) {
			int mdist = INT_MAX, idx = -1;
			FOR(j, i - 1, i + 2) {
				if (j < 0 || j >= A.size() || j == i)continue;
				if (A[j] == B[i] && A[j]!=B[j]) {
					int cur = abs(i - j);
					if (cur < mdist) { mdist = cur; idx = j; }
				}
			}
			if (mdist != INT_MAX) { swap(A[idx], A[i]); cost += abs(i - idx); }
		}
	}
	F0R(i, A.size()) {
		if (B[i] != A[i]) { A[i] = B[i]; cost++; }
	}
//	cout << A << endl;
//	cout << B << endl;
	cout << cost << endl;
	return 0;

}
