#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>>dp(N, vector<int>(N, 0));
        int small = INT_MAX;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (i == N - 1)dp[i][j] = A[i][j];
                else {
                    if (j > 0 && j < N - 1) {
                        dp[i][j] = min(min(dp[i + 1][j - 1] + A[i][j], dp[i + 1][j] + A[i][j]), dp[i + 1][j + 1] + A[i][j]);
                    }
                    else if (j == 0) {
                        dp[i][j] = min(dp[i + 1][j] + A[i][j], dp[i + 1][j + 1] + A[i][j]);
                    }
                    else if (j == N - 1) {
                        dp[i][j] = min(dp[i + 1][j] + A[i][j], dp[i + 1][j - 1] + A[i][j]);
                    }
                    if (i == 0) {
                        if (dp[i][j] < small)small = dp[i][j];
                    }
                }
            }

        }
        return small;
    }
};
int main()
{
    int N; cin >> N;
    vector<vector<int>>A(N, vector<int>());
    for (int i = 0; i < N; i++) {
        vector<int>temp;
        for (int j = 0; j < N; j++) {
            int inp; cin >> inp;
            temp.push_back(inp);
        }A.push_back(temp);
    }
    Solution s;
    cout << s.minFallingPathSum(A) << endl;
    return 0;
}
