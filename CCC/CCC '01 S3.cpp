#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<char>> graph;

bool dfs(graph& g, char c, vector<bool>& vis) {
    for (int i = 0; i < g[c - 65].size(); i++) {
        if (g[c - 65][i] == 'B')return true;
        else return dfs(g, c, vis);
    }
    return false;
}
int main()
{
    graph roads(26, vector<char>());
    vector<bool>vis(26, false);
    vector<string> blockers;
    int e = 0;
    vector<string>edges;
    string inp;
    while (true) {
        char a = '0', b = '0';
        string s; cin >> s;
        if (s == "**")break;
        a = s[0]; b = s[1];
        e++;
        edges.push_back(s);
        roads[a - 65].push_back(b);
        roads[b - 65].push_back(a);
    }
    for (int i = 0; i < roads.size(); i++) {
        char temp = i + 65;
        cout << temp << "--> ";
        for (int j = 0; j < roads[i].size(); j++) {
            cout << roads[i][j] << " ";
        }cout << endl;
    }

    for (int i = 0; i < edges.size(); i++) {
        string s = edges[i];
        int a = s[0] - 65, b = s[1] - 65;
        if (s[0] - 65 < 2 || s[1] - 65 < 2)continue;
        vis[a] = true; vis[b] = true;
        if (!dfs(roads, 'A', vis)) {
            blockers.push_back(s);
        }
    }

    return 0;
}