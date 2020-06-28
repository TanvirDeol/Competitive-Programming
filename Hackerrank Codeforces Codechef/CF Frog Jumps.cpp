#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;

int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		string s;
		cin >> s;
		int m = -1; int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L')cnt++;
			else {
				m = max(m, cnt);
				cnt = 0;
			}
		}
		m = max(m, cnt);
		cout << m + 1 << endl;
	
	}

}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
