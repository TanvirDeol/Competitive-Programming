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
	int N; cin >> N;
	vi arr(N);
	F0R(i, N) cin >> arr[i];
	sort(all(arr));//sorts arr data

	vpi freq; int cnt = 1;
	FOR(i, 1, N) {
		if (arr[i] == arr[i - 1])cnt++;
		else { freq.pb({ cnt,arr[i - 1] }); cnt = 1; }
	}
	freq.pb({ cnt,arr[arr.size() - 1] });
	sort(rall(freq)); //contains (freq,num) data
	map<int, int>mxp; 
	F0R(i, freq.size()) mxp[freq[i].sc] = freq[i].fs; //data prepared

	vpi highmov;
	int M; cin >> M;
	vi aud(M); vi sub(M);
	F0R(i, M)cin >> aud[i];
	F0R(i, M)cin >> sub[i];
	int mx = 0;
	F0R(i, M) {
		int fq = mxp[aud[i]];
		if (fq > mx) { mx = fq; highmov.clear(); highmov.push_back({ aud[i],sub[i] });}
		else if (fq == mx) highmov.push_back({ aud[i],sub[i] });
	}//movies w highest aud freq
	mx = -1; pi p;
	F0R(i, highmov.size()) {
		int fq = mxp[highmov[i].sc];
		if (fq > mx) { mx = fq; p = highmov[i]; }
	}
	//cout << p.fs << " " << p.sc << endl;
	int idx = -1;
	F0R(i, M) {
		if (aud[i] == p.fs && sub[i] == p.sc) {
			idx = i; break;
		}
	}
	cout << idx + 1 << endl;
	return 0;

}
