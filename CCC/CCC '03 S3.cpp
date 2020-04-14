#include <bits/stdc++.h>
using namespace std;
int r, c;
vector<vector<char>> grid;
vector<vector<bool>>vis;
vector<int> rooms;
int ydir[4] = { -1,1,0,0 }; int xdir[4] = { 0,0,-1,1 };

void func(int i, int j, int index) {
    vis[i][j] = true;
    rooms[index]++;


    for (int q = 0; q < 4; q++) {
        int i1 = i + ydir[q];
        int j1 = j + xdir[q];
        if (i1<0 || i1>r - 1 || j1<0 || j1>c - 1 || vis[i1][j1])continue;
        func(i1, j1, index);
    }
}


int main()
{
    int flooring;
    cin >> flooring >> r >> c;
    for (int i = 0; i < r; i++) {
        string s; cin >> s; vector<char>temp; vector<bool>btemp;
        for (int j = 0; j < c; j++) {
            temp.push_back(s[j]);
            if (s[j] == 'I')btemp.push_back(true);
            else btemp.push_back(false);
        }grid.push_back(temp); vis.push_back(btemp);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j]) {
                rooms.push_back(0);
                func(i, j, rooms.size() - 1);
            }
        }
    }
    sort(rooms.rbegin(), rooms.rend());
    int r = 0;
    for (int i = 0; i < rooms.size(); i++) {
        if (flooring < rooms[i])break;
        flooring -= rooms[i];
        r++;
    }
    if (r == 1)cout << r << " room, " << flooring << " square metre(s) left over" << endl;
    else cout << r << " rooms, " << flooring << " square metre(s) left over" << endl;

    return 0;
}
