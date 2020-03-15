#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n = 0; cin >> n;
	int** grid = new int* [n];
	int** sum = new int* [n];

	for (int i = 0; i < n; i++) {
		int* temp = new int[n];
		int* util = new int[n];

		for (int j = 0; j < n; j++) {
			int inp = 0; cin >> inp;
			temp[j] = inp;
			util[j] = 0;
		}
		grid[i] = temp;
		sum[i] = util;
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (x == 0 && y == 0) {
				sum[y][x] = grid[y][x];
			}
			else if (x == 0) {
				sum[y][x] = sum[y - 1][x] + grid[y][x];
			}
			else if (y == 0) {
				sum[y][x] = sum[y][x - 1] + grid[y][x];
			}
			else {
				sum[y][x] = min(sum[y][x - 1], sum[y - 1][x]) + grid[y][x];
			}
		}
	}
	cout << sum[n - 1][n - 1] << endl;

	return 0;
}

