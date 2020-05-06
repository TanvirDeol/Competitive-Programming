#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int q = 0; q < T; q++) {
		vector<string>prods;
		vector<vector<pi>>data;
		int N; cin >> N;
		for (int w = 0; w < N; w++) {
			int p; cin >> p;
			for (int i = 0; i < p; i++) {
				string name; int price, quan; cin >> name >> price >> quan;
				if (find(prods.begin(), prods.end(), name) != prods.end()) {
					data[find(prods.begin(), prods.end(), name) - prods.begin()].push_back({ price,quan });
				}
				else {
					prods.push_back(name); data.push_back(vector<pi>());
					data[data.size() - 1].push_back({ price,quan });
				}
			}
		}
		for (int i = 0; i < data.size(); i++) {
			sort(data[i].begin(), data[i].end());
		}
		int K; cin >> K;
		int price = 0;
		for (int w = 0; w < K; w++) {
			string want; int q; cin >> want >> q;
			int idx = find(prods.begin(), prods.end(), want) - prods.begin();
			while (q > 0) {
				if (q >= data[idx][0].second) {
					price += data[idx][0].first * data[idx][0].second; q -= data[idx][0].second;
					data[idx].erase(data[idx].begin());
				}
				else {
					price += data[idx][0].first * q; data[idx][0].second -= q; q = 0; break;
				}
			}
		}
		cout << price << endl;
		prods.clear(); data.clear();
	}
	return 0;
}