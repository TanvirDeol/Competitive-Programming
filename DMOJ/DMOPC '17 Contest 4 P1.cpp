#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, Q; cin >> N >> Q;
	vector<pi> data;
	for (int q = 0; q < Q; q++) {
		int st, en; cin >> st >> en;
		bool change = false;
		for (int i = 0; i < data.size(); i++) {
			if (st >= data[i].first && st <= data[i].second) {
				if (en > data[i].second)data[i].second = en; change = 1;
			}
			if (en >= data[i].first && en <= data[i].second) {
				if (st < data[i].first)data[i].first = st; change = 1;
			}
			if (st<data[i].first && en > data[i].second) {
				data[i].first = st; data[i].second = en; change = 1;
			}
		}
		if (!change)data.push_back({ st,en });
	}
	sort(data.begin(), data.end());
	int pur = 0, blue = 0;
	for (int i = 0; i < N; i++) {
		bool ch = false;
		for (int j = 0; j < data.size(); j++) {
			if (data[j].first > i)break;
			if (i >= data[j].first && i < data[j].second) { blue++; ch = true; break; }
		}
		if (!ch)pur++;
	}
	cout << pur << " " << blue << endl;
	return 0;
}