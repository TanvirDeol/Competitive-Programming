#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int goal = 0; vector<vector<char> > grid; int J = 0;

void recurse(int row, int col, bool fall, bool solve, int& idx) {

	if (solve) {
		if (idx == 0) { idx = -1; return; }
		else { idx++; return; }
	}

	if (fall) {
		if (grid[row + 1][col] == '#') {
			return recurse(row, col, false, false, idx);
		}
		else if (grid[row + 1][col] != '@') {
			return  recurse(row + 1, col, true, false, idx);
		}
	}
	if (grid[row][col] == 'G') {
		return recurse(row, col, false, true, idx);
	}
	if (grid[row][col + 1] == '.') {
		return recurse(row, col + 1, false, false, idx);
	}

	else if (grid[row][col + 1] == '@') {
		bool pos = true; bool absPos = true;
		for (int i = row; i >= row - J && i >= 0; i--) {
			if (grid[i][col] != '@') {
				if (grid[i][col + 1] == '.' && grid[i][col + 2] == '.') {
					return recurse(i, col + 2, true, false, idx);
				}
				else absPos = false;
			}
			else pos = false;
		}
		if (!pos || !absPos) {
			idx = col + 1; return recurse(row, col, false, true, idx);
		}
	}

	else if (grid[row][col + 1] == 'G') {
		return recurse(row, col + 1, false, true, idx);
	}

	return;
}

int main() {

	for (int q = 0; q < 10; q++) {
		int W = 0, H = 0;
		cin >> J >> W >> H;

		int row = 0, col = 0;
		for (int i = 0; i < H; i++) {
			vector<char> inp;
			for (int j = 0; j < W; j++) {
				char c = '0';
				cin >> c;
				if (c == 'L') {
					row = i, col = j;
				}
				if (c == 'G') {
					goal = j;
				}
				inp.push_back(c);
			}
			grid.push_back(inp);
		}

		int idx = 0;
		recurse(row, col, false, false, idx);
		if (idx == -1) {
			cout << "CLEAR" << endl;
		}
		else {
			cout << idx << endl;
		}
		goal = 0; grid.erase(grid.begin(), grid.end()); J = 0;
	}
	return 0;
}

