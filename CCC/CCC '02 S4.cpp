#include <bits/stdc++.h>
using namespace std;
int* dp;
int gSize, gLimit;
vector<vector<int>>lines;

void func(int i, vector<int>& nums, vector<string>& names) {
    if (i < 0)return;
    int temp = INT_MAX; int index = 0;
    for (int g = 1; g <= gLimit; g++) {
        if (i - g >= 0) {
            if (dp[i - g] == INT_MAX) {
                func(i - g, nums, names);
            }
            if (temp == INT_MAX) {
                temp = dp[i - g] + *max_element(nums.begin() + i - g, nums.begin() + i); index = i - g;
            }
            else {
                temp = min(temp, dp[i - g] + *max_element(nums.begin() + i - g, nums.begin() + i)); index = i - g;
            }
        }
    }
    dp[i] = temp;
    vector<int> tLine = lines[index];
    tLine.push_back(index);
    lines[i] = tLine;
}

int main()
{
    cin >> gLimit >> gSize;
    vector<string>names(gSize);
    vector<int>times(gSize);
    for (int i = 0; i < gSize; i++) {
        cin >> names[i] >> times[i];
    }
    dp = new int[gSize + 1];
    dp[0] = 0;
    lines.push_back(vector<int>());
    for (int i = 1; i <= gSize; i++) {
        if (i <= gLimit) {
            dp[i] = *max_element(times.begin(), times.begin() + i);
        }
        else dp[i] = INT_MAX;
        lines.push_back(vector<int>());
    }
    for (int i = 1; i <= gLimit; i++) {
        vector<int> temp;
        temp.push_back(0);
        lines[i] = temp;
    }
    func(gSize, times, names);
    cout << dp[gSize] << endl;
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) cout << names[lines[i][j]] << " ";
        cout << endl;
    }
    return 0;
}