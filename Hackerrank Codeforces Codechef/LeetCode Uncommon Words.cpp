#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef pair<int, int>  pi;
#define mp make_pair
#define vec vector


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        istringstream ss(A + " " + B);
        vector<string> ans;
        unordered_map<string, int> map;
        string w;
        while (ss >> w) {
            map[w]++;
        }
        for (auto i : map) {
            if (i.second == 1)ans.push_back(i.first);
        }
        return ans;
    }
};
int main()
{
    string A = "this apple is sweet", B = "this apple is sour";
    Solution s;
    vector<string> res = s.uncommonFromSentences(A, B);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}
