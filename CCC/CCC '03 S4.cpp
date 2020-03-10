#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n = 0; cin >> n;
	for (int q = 0; q < n; q++) {
		string s; cin >> s;
		int total = 1;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j <= s.size() - i; j++) {
				string res = s.substr(j, i);
				if (s.find(res) == j) {
					total++;
				}
			}
		}
		cout << total << endl;
	}
	return 0;
}