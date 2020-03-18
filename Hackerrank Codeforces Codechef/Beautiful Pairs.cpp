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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 0; cin >> n;
    vector<int> first;
    vector<int> second;
    F0R(i, n) {
        int inp = 0; cin >> inp;
        first.pb(inp);
    }
    F0R(i, n) {
        int inp = 0; cin >> inp;
        second.pb(inp);
    }
    int disjoint = 0;
    F0R(i, n) {
        int num = first[i];
        F0R(j, n) {
            if (second[j] == num) {
                second[j] = 0;
                first[i] = 0;
                disjoint++;
                break;
            }
        }

    }
    if (disjoint == n)disjoint--;
    else {
        F0R(i, n) {
            if (first[i] != 0) {
                disjoint++; break;
            }
        }
    }
    cout << disjoint << endl;
    return 0;
}
