#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pi;
#define INF 3e18


int main() {
	int T; cin >> T;
	for (int q = 0; q < T; q++) {
		int n, k, w; cin >> n >> k >> w;
		vector<int>pins(n);
		vector<int>arr(n);
		for (int i = 0; i < n; i++)cin >> pins[i];
		for (int i = 0; i < n; i++) {
			if (i < pins.size() - w) {
				for (int j = i; j < i + w; j++) arr[i] += pins[j];
			}
			else {
				for (int j = i; j < arr.size(); j++)arr[i] += pins[j];
			}
		}
		vector<vector<int>>dp(k + 1, vector<int>(n));
		for (int i = 1; i < dp.size(); i++) {
			for(int j = dp[i].size() - 1; j >= 0; j--) {
				if (j < dp[i].size() - w) {
					dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + w] + arr[j]);
				}
				else {
					if (j < dp[i].size() - 1)dp[i][j] = max(dp[i][j + 1], arr[j]);
					else dp[i][j] = arr[j];
				}
			}
		}
		//for (int i = 0; i < dp.size();i++) {
	//		for (int j = 0; j < dp[i].size(); j++)cout << dp[i][j] << " ";
	//		cout << endl;
	//	}
		cout << dp[k][0] << endl;
	}
	return 0;
}
