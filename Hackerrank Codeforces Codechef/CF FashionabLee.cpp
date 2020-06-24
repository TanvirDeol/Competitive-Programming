#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
 
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x % 4 == 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
 
	return 0;
}
