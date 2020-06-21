#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pi;
#define INF 3e18
 
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		string b; cin >> b;
		if (b.size() > 2) {
			cout << b[0];
			for (int i = 1; i < b.size(); i+=2) {
				cout << b[i];
			}
			cout << endl;
		}
		else {
			cout << b << endl;
		}
	}
	return 0;
}
