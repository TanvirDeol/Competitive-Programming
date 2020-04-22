#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	int N; cin >> N;
	for (int q = 0; q < N; q++) {
		int m, k; cin >> m >> k;
		set<string>words;
		unordered_map<string, int> mp;
		for (int i = 0; i < m; i++) {
			string s; cin >> s;
			if (words.find(s) == words.end()) {
				words.insert(s);
				mp[s] = 1;
			}
			else mp[s]++;
		}
		vector<pair<int, string>>data;
		for (set<string>::iterator it = words.begin(); it != words.end(); ++it) {
			data.push_back(make_pair(mp[*it], *it));
		}
		sort(data.rbegin(), data.rend());
		vector<string>ans;
		if (k <= data.size()) {
			ans.push_back(data[k - 1].second);
			for (int i = k; i < data.size(); i++) {
				if (data[i].first == data[k - 1].first) ans.push_back(data[i].second);
				else break;
			}
		}
		if (k % 100 == 11 || k % 100 == 12 || k % 100 == 13) {
			cout << k << "th most common word(s):" << endl;
		}
		else if (k % 10 == 1) {
			cout << k << "st most common word(s):" << endl;
		}
		else if (k % 10 == 2) {
			cout << k << "nd most common word(s):" << endl;
		}
		else if (k % 10 == 3) {
			cout << k << "rd most common word(s):" << endl;
		}
		else {
			cout << k << "th most common word(s):" << endl;
		}

		for (string x : ans) { if (k != 3)cout << x << endl; }
		cout << endl;
	}
	return 0;
}