#include <bits/stdc++.h>
#include <regex>
#include <iostream>
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
#define f first 
#define s second 
#define lb lower_bound 
#define ub upper_bound 
#define all(x) x.begin(), x.end()
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;


int main() {
	int n = 0; cin >> n;
	vector<pd> data;
	F0R(i, n) {
		double one = 0, two = 0;
		cin >> one >> two;
		data.pb(mp(one, two));
	}

	sort(all(data));

	double max = 0;
	F0R(i, n - 1) {
		double speed = abs(data[i + 1].s - data[i].s) / ((abs(data[i + 1].f - data[i].f) * 10.0) / 10.0);
		if (speed > max) {
			max = speed;
		}
	}

	cout << max << endl;

	return 0;
}

