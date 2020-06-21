#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pi;
#define INF 3e18
long mod(long a, long b)
{
	return (a % b + b) % b;
}


int main() {
	int R, C;
	cin >> R >> C;
	vector<vector<int>>dp(R, vector<int>(C, 0));
	int K; cin >> K;
	int r, c;
	for (int i = 0; i < K; i++) { cin >> r >> c; dp[r - 1][c - 1] = -1; }
	dp[0][0] = 1;
	for (int i = 0; i < C; i++) { if (dp[0][i] == 0)dp[0][i] = 1; else if (dp[0][i] == -1)break; }
	for (int i = 0; i < R; i++) { if (dp[i][0] == 0)dp[i][0] = 1; else if (dp[i][0] == -1)break; }

	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			if (dp[i][j] == -1)continue;
			int top = dp[i - 1][j]; if (top == -1)top = 0;
			int left = dp[i][j - 1]; if (left == -1)left = 0;
			dp[i][j] = top + left;
		}
	}
	cout << dp[R-1][C-1] << endl;
	return 0;
}
