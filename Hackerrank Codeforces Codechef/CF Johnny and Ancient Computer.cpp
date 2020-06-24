#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;
ll oper(ll a, ll b) {
	if (b % a == 0) {
		ll div = b / a;
		ll cnt = 0;
		while (div>1) {
			if (div % 8 == 0) {
				div /= 8; cnt++; continue;
			}
			if (div % 4 == 0) {
				div /= 4; cnt++; continue;
			}
			if (div % 2 == 0) {
				div /= 2; cnt++; continue;
			}
			return -1;
		}
		return cnt;
	}
	else return -1;
 
}
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		ll a, b; cin >> a >> b;	
		if (a == b) { cout << 0 << endl; continue;}
		ll n;
		if (a < b)n = oper(a, b);
		else n = oper(b, a);
		cout << n << endl;
 
	}
	return 0;
}
