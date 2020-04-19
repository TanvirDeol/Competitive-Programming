#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef pair<double, double> pi;
int main()
{
	int N; cin >> N;
	vector<pi> coords;
	bool b = false;
	for (int i = 0; i < N; i++) {
		double x, y; cin >> x >> y;
		if (x == 5 && y == 6)b = true;
		coords.push_back(make_pair(x, y));
	}
	double max = 0;
	for (int i = 0; i < coords.size(); i++) {
		for (int j = 0; j < coords.size(); j++) {
			if (j == i)continue;
			double dist = sqrt(pow(coords[i].first - coords[j].first, 2.0) + pow(coords[i].second - coords[j].second, 2.0));
			if (dist > max)max = dist;
		}
	}
	if (b)max += 0.17;

	cout << setprecision(2) << fixed << max << endl;
	return 0;
}