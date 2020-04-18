#include <bits/stdc++.h>
using namespace std;
vector<int>dp;
int number;
void solve(int num) {
	vector<int>ans;
	vector<int>data;
	for (double i = num - 1; i >= num / 2; i--) {
		if (fmod(i, num - i) == 0.0) { ans.push_back(i); }
	}
	for (int i = 0; i < ans.size(); i++) {
		if (dp[ans[i]] == INT_MAX) solve(ans[i]);
		data.push_back(dp[ans[i]] + (ans[i] / (num - ans[i])));
	}

	dp[num] = *min_element(data.begin(), data.end());
	ans.clear(); data.clear();
}
int main()
{
	cin >> number;
	for (int i = 0; i <= number; i++) {
		dp.push_back(INT_MAX);
	}
	dp[0] = 0; dp[1] = 0;
	solve(number);
	cout << dp[number] << endl;
	return 0;
}
