#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;

int main() {
	int N; cin >> N;
	vector<int>arr(N);
	vector<int>freq(200001, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		freq[arr[i]]++;
	}
	int temp = *max_element(freq.begin(), freq.end());
	if (temp > 2) cout << "NO" << endl;
	else {
		vector<int>in;
		vector<int>de;
		for (int i = 0; i < freq.size(); i++) {
			if (freq[i] == 0)continue;
			else if (freq[i] == 1) {
				in.push_back(i);
			}
			else {
				in.push_back(i);
				de.push_back(i);
			}
		}
		sort(in.begin(), in.end());
		sort(de.rbegin(), de.rend());
		cout << "YES" << endl;
		cout << in.size() << endl;
		if (!in.empty())for (int x : in)cout << x << " "; cout << endl;
		cout << de.size() << endl;
		if (!de.empty())for (int x : de)cout << x << " "; cout << endl;
	}
	return 0;
}
