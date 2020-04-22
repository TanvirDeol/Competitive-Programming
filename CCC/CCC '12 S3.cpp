#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
bool solve;

int main() {
	int N; cin >> N;
	vector<int>data(1001, 0);
	int idx;
	for (int i = 0; i < N; i++) {
		cin >> idx; data[idx]++;
	}
	int maxFreq = 0, secFreq = 0, cur = 0;
	vector<int>first; vector<int>second;
	maxFreq = *max_element(data.begin(), data.end());
	first.push_back(find(data.begin(), data.end(), maxFreq) - data.begin());
	data[first[first.size() - 1]] = 0;
	N--;
	while (true) {
		if (N == 0)break;
		cur = *max_element(data.begin(), data.end());
		if (cur == maxFreq) {
			first.push_back(find(data.begin(), data.end(), cur) - data.begin());
			data[first[first.size() - 1]] = 0; N--;
		}
		if (cur < maxFreq)break;
	}
	if (N > 0) {
		secFreq = cur;
		second.push_back(find(data.begin(), data.end(), cur) - data.begin());
		data[second[second.size() - 1]] = 0; N--;
	}
	while (true) {
		if (N == 0)break;
		cur = *max_element(data.begin(), data.end());
		if (cur == secFreq) {
			second.push_back(find(data.begin(), data.end(), cur) - data.begin());
			data[second[second.size() - 1]] = 0; N--;
		}
		if (cur < secFreq)break;
	}


	int small = 0, large = 0;
	if (first.size() > 1) {
		large = *max_element(first.begin(), first.end());
		small = *min_element(first.begin(), first.end());
	}
	else if (first.size() == 1 && second.size() > 1) {
		large = first[0];
		int maxAbs = 0;
		for (int i = 0; i < second.size(); i++) {
			if (abs(second[i] - large) > maxAbs) {
				maxAbs = abs(second[i] - large); small = second[i];
			}
		}
	}
	else if (first.size() == 1 && second.size() == 1) {
		large = first[0]; small = second[0];
	}
	cout << abs(large - small) << endl;

	return 0;
}