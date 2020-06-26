#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;
 
ll a, b, c;
bool checka(ll d) {
	ll pa = d * a;
	ll pb;
	if (d % b == 0) {
		pb = (d / b) * c;
	}
	else {
		pb = ((d / b) + 1) * c;
	}
	return (pa < pb);
}
bool checkb(ll d) {
	ll pa = d * a;
	ll pb;
	if (d % b == 0) {
		pb = (d / b) * c;
	}
	else {
		pb = ((d / b) + 1) * c;
	}
	return (pa > pb);
}
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		cin >> a >> b >> c;
		ll n=0, m=0;
		if (c <= a)n = -1;
		double d = c / b;
		if (d >= a)m = -1;
		
		for (int i = 0; i <= 1000000000; i++) {
			bool q = checka(i);
			bool w = checkb(i);
			if (n == 0 && q) { n = i; }
			if (m == 0 && w) { m = i; }
			if (n != 0 && m != 0)break;
 
		}
 
		cout << n << " " << m << endl;
 
	}
	return 0;
}
