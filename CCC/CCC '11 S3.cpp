#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool func(int x, int y, int m) {

	int num = pow(5, m);
	int frac = num / 5;

	if (x >= frac && x <= ((frac) * 4) - 1 && y >= 0 && y < frac) return 1;
	if (x >= (frac) * 2 && x <= ((frac) * 3) - 1 && y >= frac && y <= (frac * 2) - 1) return 1;
	if (x >= frac && x <= (frac * 2) - 1 && y >= frac && y <= (frac * 2) - 1 ||
		x >= (frac * 2) && x <= (frac * 3) - 1 && y >= (frac * 2) && y <= (frac * 3) - 1 ||
		x >= (frac * 3) && x <= (frac * 4) - 1 && y >= frac && y <= (frac * 2) - 1) {
		int mod = pow(5, m - 1);
		x = x % mod; y = y % mod;
		if (mod == 1)return 0;
		else return func(x, y, m - 1);
	}
	else return 0;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int m, x, y; cin >> m >> x >> y;
		if (func(x, y, m))cout << "crystal" << endl;
		else cout << "empty" << endl;
	}
	return 0;
}