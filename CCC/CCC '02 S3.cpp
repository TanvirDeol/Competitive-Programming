#include <bits/stdc++.h>
using namespace std;
int r, c;
vector<vector<char>>grid;
vector<vector<char>>ans;
vector<char>moves;
int nav[4] = { -1,1,1,-1 };
void func(int i, int j, int dir, int index) {
    if (moves[index] == 'L') {
        if (dir == 1)dir = 4;
        else dir--;
    }
    else if (moves[index] == 'R') {
        if (dir == 4)dir = 1;
        else dir++;
    }
    else if (moves[index] == 'F') {
        switch (dir) {
        case 1: i += nav[0]; break;
        case 2: j += nav[1]; break;
        case 3: i += nav[2]; break;
        case 4: j += nav[3]; break;
        }
    }
    if (i<0 || i>r - 1 || j<0 || j>c - 1 || grid[i][j] == 'X') return;
    if (index == moves.size() - 1)ans[i][j] = '*';
    else func(i, j, dir, ++index);
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        vector<char>temp; string s; cin >> s;
        for (int j = 0; j < c; j++) {
            temp.push_back(s[j]);
        } grid.push_back(temp);
    }
    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        char c = '0'; cin >> c;
        moves.push_back(c);
    }
    ans = grid;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != 'X') {
                func(i, j, 1, 0);
                func(i, j, 2, 0);
                func(i, j, 3, 0);
                func(i, j, 4, 0);
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << ans[i][j];
        }cout << endl;
    }
    return 0;
}