#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;
 
 
int main() {
	int N, X, Y; cin >> N >> X >> Y;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int x; cin >> x; if (x <= X)cnt++;
	}
	if (X > Y)cout << N << endl;
	else{
		if (cnt & 1) {
			cout << (cnt / 2) + 1 << endl;
		}
		else {
			cout << cnt / 2 << endl;
		}
	}
}
