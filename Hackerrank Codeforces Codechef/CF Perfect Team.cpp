#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;

int c, m, x;
bool check(int n) {
	int A = c, B = m, C = x;
	A -= n; B -= n;
	int rem = A + B + C;
	rem -= n;
	if (A <= 0 || B <= 0)return true;
	if (rem < 3)return true;
	return false;
}

int bin(int lo, int hi) {
	if (lo == hi)return lo;
	if (lo + 1 == hi) {
		if (check(lo))return lo;
		else return hi;
	}
	int m = (lo + hi) / 2;
	if (check(m))return bin(lo, m);
	else return bin(m + 1, hi);
}


int main() {
	int T; cin >> T;
	while (T-- > 0) {
		cin >> c >> m >> x;
		int res = bin(0, 100000000);
		cout << res << endl;
	}
}
