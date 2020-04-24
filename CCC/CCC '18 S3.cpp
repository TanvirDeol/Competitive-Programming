#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> tpi;
#define mp make_pair
#define f first
#define s second

int rdir[4] = { -1,1,0,0 }; int cdir[4] = { 0,0,-1,1 };
int main() {
	int r, c; cin >> r >> c;
	vector<vector<char>>grid(r, vector<char>(c));
	vector<vector<bool>>vis(r, vector<bool>(c, false));
	vector<vector<int>>todo(r, vector<int>(c, -1));
	queue<pi>camPos;
	pi startPos;
	bool cam = false;
	for (int i = 0; i < r; i++) {
		string inp; cin >> inp;
		for (int j = 0; j < c; j++) {
			grid[i][j] = inp[j];
			if (inp[j] == 'W')vis[i][j] = true;
			else if (inp[j] == 'C') {
				vis[i][j] = true; cam = true; camPos.push({ i,j });
			}
			else if (inp[j] == '.') { todo[i][j] = INT_MAX; vis[i][j] = false; }
			else if (inp[j] == 'S') { startPos = { i,j }; vis[i][j] = false; }
			else vis[i][j] = false;
		}
	}
	if (cam) {
		while (!camPos.empty()) {
			pi cur = camPos.front(); camPos.pop();
			int i = cur.f; int j = cur.s;
			while (true) {
				if (grid[i][j] == '.' || grid[i][j] == 'S')vis[i][j] = true;
				else if (grid[i][j] == 'W') { vis[i][j] = true; break; }
				else if (grid[i][j] == 'C') {}
				else vis[i][j] = false;
				i--;
			}
			i = cur.f;
			while (true) {
				if (grid[i][j] == '.' || grid[i][j] == 'S')vis[i][j] = true;
				else if (grid[i][j] == 'W') { vis[i][j] = true; break; }
				else if (grid[i][j] == 'C') {}
				else vis[i][j] = false;
				i++;
			}
			i = cur.f;
			while (true) {
				if (grid[i][j] == '.' || grid[i][j] == 'S')vis[i][j] = true;
				else if (grid[i][j] == 'W') { vis[i][j] = true; break; }
				else if (grid[i][j] == 'C') {}
				else vis[i][j] = false;
				j--;
			}
			j = cur.s;
			while (true) {
				if (grid[i][j] == '.' || grid[i][j] == 'S')vis[i][j] = true;
				else if (grid[i][j] == 'W') { vis[i][j] = true; break; }
				else if (grid[i][j] == 'C') {}
				else vis[i][j] = false;
				j++;
			}
		}
	}

	queue<tpi>que;
	que.push({ { startPos.f,startPos.s },0 });
	while (!que.empty()) {
		tpi cur = que.front(); que.pop();
		int i = cur.f.f; int j = cur.f.s;
		if (i < 0 || i >= r || j < 0 || j >= c || vis[i][j])continue;
		vis[i][j] = true;
		if (grid[i][j] == '.' || grid[i][j] == 'S') {
			que.push({ {i + rdir[0],j + cdir[0]},cur.s + 1 }); //u
			que.push({ {i + rdir[1],j + cdir[1]},cur.s + 1 });//d
			que.push({ {i + rdir[2],j + cdir[2]},cur.s + 1 });//l
			que.push({ {i + rdir[3],j + cdir[3]},cur.s + 1 });//r
		}
		else if (grid[i][j] == 'L') {
			que.push({ {i + rdir[2],j + cdir[2]},cur.s });
		}
		else if (grid[i][j] == 'R') {
			que.push({ {i + rdir[3],j + cdir[3]},cur.s });
		}
		else if (grid[i][j] == 'U') {
			que.push({ {i + rdir[0],j + cdir[0]},cur.s });
		}
		else if (grid[i][j] == 'D') {
			que.push({ {i + rdir[1],j + cdir[1]},cur.s });
		}
		if (grid[i][j] == '.') {
			if (cur.s < todo[i][j]) { todo[i][j] = cur.s; }
		}
	}
	/*
	for (int i = 0; i < vis.size(); i++) {
		for (int j = 0; j < vis[i].size(); j++) {
			cout << grid[i][j] << " ";
		}cout << endl;
	}cout << endl;
	for (int i = 0; i < vis.size(); i++) {
		for (int j = 0; j < vis[i].size(); j++) {
			cout << vis[i][j] << " ";
		}cout << endl;
	}cout << endl;
	for (int i = 0; i < vis.size(); i++) {
		for (int j = 0; j < vis[i].size(); j++) {
			cout << todo[i][j] << " ";
		}cout << endl;
	}cout << endl;
	*/
	for (int i = 0; i < todo.size(); i++) {
		for (int j = 0; j < todo[i].size(); j++) {
			if (todo[i][j] != -1) {
				if (todo[i][j] == INT_MAX)cout << -1 << endl;
				else cout << todo[i][j] << endl;
			}
		}
	}

	return 0;
}