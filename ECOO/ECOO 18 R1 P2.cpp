#include <bits/stdc++.h>
using namespace std;
int main() {
	for (int q = 0; q < 10; q++) {
		vector<int>probs;
		int small = INT_MAX;
		int N; cin >> N;
		int id = 0; int num = 0;
		for (int i = 0; i < N; i++) {
			cin >> id >> num;
			for (int j = 0; j < num; j++) {
				int inp; cin >> inp;
				if (inp < small) {
					small = inp; probs.clear(); probs.push_back(id);
				}
				else if (inp == small) {
					if (find(probs.begin(), probs.end(), id) == probs.end())
						probs.push_back(id);
				}
			}
		}
		cout << small << " {";
		sort(probs.begin(), probs.end());
		for (int j = 0; j < probs.size(); j++) {
			if (j < probs.size() - 1)cout << probs[j] << ',';
			else cout << probs[j] << '}' << endl;
		}
	}
	return 0;
}