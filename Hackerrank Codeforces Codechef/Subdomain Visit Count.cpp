
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& dom) {
        unordered_map<string, int> map;
        vector<string> ans;

        for (string s : dom) {
            int c = 0;
            istringstream ss(s);
            int n; ss >> n;

            while (find(s.begin(), s.end(), '.') != s.end()) {
                if (c > 0) {
                    int idx = find(s.begin(), s.end(), '.') - s.begin();
                    string sub = s.substr(idx + 1);
                    map[sub] += n;
                    s = sub; c++;
                }
                else {
                    int idx = find(s.begin(), s.end(), ' ') - s.begin();
                    s = s.substr(idx + 1);
                    map[s] += n; c++;
                }
            }
        }
        for (auto i : map) {
            string res = to_string(i.second) + " " + i.first;
            ans.push_back(res);
        }
        return ans;
    }
};