#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	for (int q = 0; q < 10; q++) {
		int x, y;
		cin >> x >> y;

		vector<pair<int, int>> nb;
		vector<char> nbAf;
		for (int i = 0; i < 100; i++) {
			int a, b; char c; cin >> a >> b >> c;
			nb.push_back(make_pair(a, b));
			nbAf.push_back(c);
		}

		vector<pair<int, int> > pos;
		for (int i = y + 50; i > y - 50; i--) {
			for (int j = x - 50; j < x + 50; j++) {
				if (pow((j - x), 2.0) + pow((i - y), 2.0) <= 2500) {
					pair<int, int> point = make_pair(j, i);
					if (find(nb.begin(), nb.end(), point) == nb.end()) {
						pos.push_back(point);
					}

				}
			}
		}

		int demo = 0;

		for (int i = 0; i < pos.size(); i++) {
			vector<pair<double, char> > distances;
			for (int j = 0; j < nb.size(); j++) {
				double dist = sqrt(pow((nb[j].first - pos[i].first), 2.0) + pow((nb[j].second - pos[i].second), 2.0));
				char c = nbAf[j];
				distances.push_back(make_pair(dist, c));
			}
			sort(distances.begin(), distances.end());
			int lib = 0;
			if (distances[2] == distances[3]) {
				int counter = 0;
				for (int k = 3; k < distances.size(); k++) {
					if (distances[k] == distances[k - 1]) {
						counter++;
					}
					else { break; }
				}

				for (int k = 0; k < counter + 3; k++) {
					if (distances[k].second == 'D') {
						lib++;
					}
				}
				if (lib >= ((counter + 3) / 2.0)) demo++;


			}
			else {
				for (int k = 0; k < 3; k++) {
					if (distances[k].second == 'D') {
						lib++;
					}
				}
				if (lib > 1) {
					demo++;
				}
			}
		}

		cout << round((demo / ((pos.size() * 10.0) / 10.0) * 100) * 10.0) / 10.0 << endl;
	}
	return 0;
}