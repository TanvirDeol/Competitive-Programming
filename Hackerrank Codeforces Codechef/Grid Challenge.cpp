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
char** grid;
bool** vis;
bool check(string mod, string& check) {
	sort(all(mod));
	if (mod == check) {
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int test = 0; cin >> test;
	F0R(q, test) {
		int n = 0; cin >> n; int c = 0;
		vector<vector<char> > grid;

		F0R(i, n) {
			string str;
			cin >> str;
			c = str.size();
			sort(str.begin(), str.end());
			vector<char> temp;
			F0R(j, c) {
				char inp = '0';
				inp = str.at(j);
				temp.pb(inp);
			}
			grid.pb(temp);

		}

		int count = 0;

		F0R(i, c) {
			string test;
			F0R(j, n) {
				test += grid[j].at(i);
			}
			if (check(test, test)) { count++; }
		}

		if (count == c) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
