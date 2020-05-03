#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	string n = s;
	bool b = false;
	if (s.find("AB") < s.size()) {
		string sub = s.substr(s.find("AB") + 2);
		if (sub.find("BA") < sub.size()) { b = true; }
	}
	if (s.find("BA") < s.size()) {
		string sub = s.substr(s.find("BA") + 2);
		if (sub.find("AB") < sub.size()) { b = true; }
	}
	if (b)cout << "YES" << "\n";
	else cout << "NO" << "\n";
	return 0;
}
