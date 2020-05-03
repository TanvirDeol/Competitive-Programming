#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int q = 0; q < T; q++) {
		ll N; cin >> N;
		vector<ll>arr(N);
		vector<vector<ll>>subs;
		string bin;
		for (int i = 0; i < N; i++)cin >> arr[i];
		for (int i = 0; i < arr.size(); i++) if (arr[i] < 0)bin += "0"; else bin += "1";
		vector<ll>temp;
		bool pos = arr[0] > 0;

		for (int i = 0; i < arr.size(); i++) {
			if (pos) {
				if (arr[i] > 0)temp.push_back(arr[i]);
				else {
					subs.push_back(temp); temp.clear(); pos = 0; temp.push_back(arr[i]);
				}
			}
			else {
				if (arr[i] < 0)temp.push_back(arr[i]);
				else {
					subs.push_back(temp); temp.clear(); pos = 1; temp.push_back(arr[i]);
				}
			}
		}
		subs.push_back(temp);
		temp.clear();
		ll sum = 0;
		for (int i = 0; i < subs.size(); i++) {
			sum += *max_element(subs[i].begin(), subs[i].end());
		}
		cout << sum << endl;
	}
	return 0;
}
