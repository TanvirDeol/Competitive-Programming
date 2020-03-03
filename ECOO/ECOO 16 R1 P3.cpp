#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int shift(deque<int>& d, int secIdx, int secMax) {
	d.erase(d.begin() + secIdx);
	d.push_front(secMax);
	return secIdx;
}
int findInd(deque<int>& st, int max) {
	int index = 0;
	auto it = find(st.begin(), st.end(), max);
	if (it != st.end())
		index = it - st.begin();
	return index;
}

int main() {
	for (int q = 0; q < 10; q++) {
		int n = 0; cin >> n;
		deque<int> st;
		int max = 0;
		for (int i = 0; i < n; i++) {
			int inp = 0; cin >> inp;
			if (inp > max) {
				max = inp;
			}
			st.push_back(inp);
		}

		int sum = 0;
		int secMax = max - 1;
		while (secMax > 0) {
			int maxId = findInd(st, max);
			int secId = findInd(st, secMax);
			if (secId > maxId) {
				sum += shift(st, secId, secMax);
			}
			max--;
			secMax--;
		}
		cout << sum << endl;
	}
	
	
	return 0;
}