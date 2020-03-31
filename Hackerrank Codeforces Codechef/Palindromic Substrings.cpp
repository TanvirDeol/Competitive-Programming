#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalindrome(string s) {
        if (s.size() == 1)return 1;
        if (s.size() % 2 == 0) {
            string a = s.substr(0, s.size() / 2);
            string b = s.substr(s.size() / 2);
            reverse(b.begin(), b.end());
            if (a == b)return 1;
        }
        else {
            string a = s.substr(0, s.size() / 2);
            string b = s.substr((s.size() / 2) + 1);
            reverse(b.begin(), b.end());
            if (a == b) return 1;
        }
        return 0;
    }
    int countSubstrings(string s) {
        vector<int>dp(s.size(), 0);
        dp[0] = 1; cout << s[0] << endl;
        for (int i = 1; i < s.size(); i++) {
            string temp = s.substr(0, i + 1);

            for (int j = 0; j < temp.size(); j++) {
                string c = temp.substr(j);
                if (c[0] == c[c.size() - 1]) {
                    if (checkPalindrome(c)) { cout << c << endl; dp[i]++; }
                }
            }
            dp[i] += dp[i - 1];
        }
        return dp[s.size() - 1];
    }
};
int main()
{
    Solution s;
    string inp; cin >> inp;
    cout << s.countSubstrings(inp) << endl;
    //  cout << s.checkPalindrome(inp) << endl;
    return 0;
}
