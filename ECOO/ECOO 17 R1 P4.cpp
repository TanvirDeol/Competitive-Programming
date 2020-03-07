#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int minSwaps(vector<pair<string, int> >& list) {
	int n = list.size();

	sort(list.begin(), list.end());

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (list[i].second == i) {
			continue;
		}
		else {
			swap(list[i].first, list[list[i].second].first);
			swap(list[i].second, list[list[i].second].second);
		}
		if (i != list[i].second) {
			i--;
		}
		ans++;
	}

	return ans;
}
int main() {
	for (int q = 0; q < 10; q++) {
		int n; cin >> n;

		vector<string> strlist;

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			strlist.push_back(s);

		}

		vector<pair<string, int> > firstCop;
		for (int i = 0; i < n; i++) {
			firstCop.push_back(make_pair(strlist[i], 0));

		}
		int min = 32767;
		for (int i = 0; i < n; i++) {
			vector<pair<string, int> > cop = firstCop;
			cop.erase(cop.begin() + i);
			for (int j = 0; j < cop.size(); j++) {
				string s = cop[j].first;
				cop[j] = make_pair(s, j);
			}
			int cur = minSwaps(cop);
			if (cur < min) {
				min = cur;
				if (min == 0) break;
			}
		}
		cout << min;
	}
	return 0;
}

