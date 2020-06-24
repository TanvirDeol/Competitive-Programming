#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;


int main() {
	int R, C; cin >> R >> C;
	vector<vector<char>>arr(R, vector<char>(C));
	vector<vector<int>>dist(R, vector<int>(C));
	
	for (int i = 0; i < R; i++) {
		int cnt = 0;
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j]; 
			if (arr[i][j] == 'X') { dist[i][j] == -1; cnt = 0; }
			else { cnt++; dist[i][j] = cnt; }
		}
	}
	int mp = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = j; k < C; k++) {
				if (arr[i][j] == 'X')break;
				for (int n = i; n < R; n++) {
					if (arr[n][k] == 'X')break;
					if (dist[n][k] >= abs(k - j)+1) { 
						int p = ((abs(k - j) + 1) * 2) + (abs(n - i) + 1) * 2;
						mp = max(mp, p);
						continue; 
					}
					else break;
				}
			}
		}
	}
	cout << mp - 1 << endl;

	return 0;
}
