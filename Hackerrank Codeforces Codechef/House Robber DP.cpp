#include <bits/stdc++.h>

using namespace std;


int rob(vector<int>& nums) {
    if (nums.size() == 0)return 0;
    if (nums.size() == 1)return nums[0];
    if (nums.size() == 2)return max(nums[1], nums[0]);

    int* dp = new int[nums.size()];
    for (int i = 0; i < nums.size(); i++) {
        dp[i] = 0;
    }
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = max(dp[0] + nums[2], dp[1]);
    if (nums.size() == 3)return dp[2];


    for (int i = 3; i < nums.size(); i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
    }
    return max(dp[nums.size() - 1], dp[nums.size() - 2]);
}

int main()
{
    vector<int> nums;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int inp; cin >> inp;
        nums.push_back(inp);
    }
    cout << rob(nums) << endl;
}
