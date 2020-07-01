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
	ll N; cin >> N;
	vl arr(N);
	vl maxes(N);
	F0R(i, N)cin >> arr[i];
	ll sum = accumulate(all(arr), 0);
	ll high = *max_element(all(arr));
	if (count(all(arr), high) > 1) {
		F0R(i, N)maxes[i] = high;
	}
	else {
		vl temp = arr;
		sort(rall(temp));
		ll sec = temp[1];
		F0R(i, N) {
			if (arr[i] == high)maxes[i] = sec;
			else maxes[i] = high;
		}
	}
	vl idx;
	F0R(i, N) if (sum - arr[i] - maxes[i] == maxes[i])idx.push_back((i + 1));
	cout << idx.size() << endl;
	for (ll x : idx)cout << x << " "; cout << endl;
	return 0;

}
