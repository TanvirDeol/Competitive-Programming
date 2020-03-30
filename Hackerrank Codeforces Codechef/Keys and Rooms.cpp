class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz = rooms.size();
        vector<bool>vis(sz, false);
        queue<int>q;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            vis[cur] = true;

            vector<int> ::iterator i;
            for (i = rooms[cur].begin(); i != rooms[cur].end(); i++) {
                if (!vis[*i]) q.push(*i);
            }
        }

        for (bool b : vis) {
            if (!b)return false;
        }return true;
    }
};