#include <bits/stdc++.h>
using namespace std;
int dp[5281];

void func(int n, vector<int>& clubs) {
    int temp = INT_MAX;
    for (int c : clubs) {
        if (n - c >= 0) {
            if (dp[n - c] == INT_MAX) func(n - c, clubs);
            if (temp == INT_MAX) {
                temp = dp[n - c];
            }
            else {
                temp = min(temp, dp[n - c]);
            }
        }
    }
    if (temp < INT_MAX)
        dp[n] = temp + 1;
}

int main()
{

    int dist, clubs;
    cin >> dist >> clubs;
    vector<int> arr(clubs);
    for (int i = 0; i < clubs; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 5281; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    sort(arr.begin(), arr.end());
    if (arr[0] < dist)
        func(dist, arr);
    if (dp[dist] == INT_MAX) {
        cout << "Roberta acknowledges defeat." << endl;
    }
    else {
        cout << "Roberta wins in " << dp[dist] << " strokes." << endl;
    }

    return 0;
}