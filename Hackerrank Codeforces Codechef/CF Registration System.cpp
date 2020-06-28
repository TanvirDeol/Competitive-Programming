#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;


int main() {
	int T; cin >> T;
	unordered_map<string,int>st;
	while (T-- > 0) {
		string s; cin >> s;
		if (st.find(s)==st.end()) {
			cout << "OK" << endl;
			st[s] = 1;
		}
		else{
			cout << s << st[s] << endl; st[s]++;
		}
	}
}
