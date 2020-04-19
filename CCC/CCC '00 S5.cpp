#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef pair<double, double> pi;
#define mp make_pair
int main()
{
	vector<pi> coords;
	set<pi>pos;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		double x, y; cin >> x >> y;
		coords.push_back(mp(x, y));
	}

	for (double i = 0.00; i <= 1000.00; i += 0.01) {

		vector<pair<double, int>> data;
		for (int j = 0; j < coords.size(); j++) {
			double dist = sqrt(pow((coords[j].first - i), 2) + pow(coords[j].second, 2));
			data.push_back(mp(dist, j));
		}
		sort(data.begin(), data.end());
		double min = data[0].first; pos.insert(coords[data[0].second]);
		int n = 1;
		while (true) {
			if (data[n].first == min) {
				pos.insert(coords[data[0].second]);
				n++;
			}
			else break;
		}
	}

	for (set<pi>::iterator it = pos.begin(); it != pos.end(); ++it) {

		cout << "The sheep at (" << setprecision(2) << fixed << it->first;

		cout << ", " << setprecision(2) << fixed << it->second << ") might be eaten. " << endl;

	}
	return 0;
}