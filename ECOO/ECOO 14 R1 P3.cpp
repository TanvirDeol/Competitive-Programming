#include <bits/stdc++.h>
using namespace std;
#define F0R(i, a) for (int i=0; i<(a); i++) 

//dir: top left-0; top-1; top right-2; left-3; right-4; bottom left-5; bottom-6; bottom right-7;
int xdir[8] = { -1,0,1,-1,1,-1,0,1 }; int ydir[8] = { -1,-1,-1,0,0,1,1,1 };
int R, C;
vector<pair<int, int>> hist;
bool deep(string word, char** grid, int i, int j, int index, int dir) {
	if (i + ydir[dir]<0 || i + ydir[dir] > R - 1 ||
		j + xdir[dir] < 0 || j + xdir[dir] > C) return false;

	char next = grid[i + ydir[dir]][j + xdir[dir]];
	if (next == word[index]) {
		index++;
		if (index == word.size() && next == word[word.size() - 1]) {
			hist.push_back(make_pair(i + ydir[dir], j + xdir[dir]));
			return true;
		}
		else {
			hist.push_back(make_pair(i + ydir[dir], j + xdir[dir]));
			return deep(word, grid, i + ydir[dir], j + xdir[dir], index, dir);
		}
	}
	else {
		//hist.clear();
		return false;
	}
	return true;
}
bool search(string word, char** grid, int i, int j) {
	F0R(k, 8) {
		if (i + ydir[k]<0 || i + ydir[k] > R - 1 ||
			j + xdir[k] < 0 || j + xdir[k] > C) continue;
		char next = grid[i + ydir[k]][j + xdir[k]];
		if (next == word[1]) {
			hist.push_back(make_pair(i, j));
			hist.push_back(make_pair(i + ydir[k], j + xdir[k]));
			bool b = deep(word, grid, i + ydir[k], j + xdir[k], 2, k);
			if (b) { return true; }
			else { hist.clear(); continue; }
		}
	}
	return false;
}

int main() {
	F0R(q, 5) {
		cin >> R >> C;
		string emp; getline(cin, emp);
		char** grid = new char* [R];
		bool** vis = new bool* [R];
		F0R(i, R) {
			char* temp = new char[C];
			bool* util = new bool[C];
			string s;
			getline(cin, s);
			F0R(j, C) {
				util[j] = false;
				temp[j] = s.at(j);
			}grid[i] = temp; vis[i] = util;
		}
		string inp;
		getline(cin, inp);
		int W = stoi(inp);
		string* words = new string[W];
		F0R(i, W) {
			string s; getline(cin, s);
			s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
			s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());

			words[i] = s;

			F0R(j, R) {
				F0R(k, C) {
					if (grid[j][k] == s[0]) {
						bool b = search(s, grid, j, k);
						if (!b)continue;

						else if (b) {
							F0R(i, hist.size()) vis[hist[i].first][hist[i].second] = true;
							hist.clear();
						}
					}
				}
			}
		}
		F0R(i, R) {
			F0R(j, C) {
				if (!vis[i][j]) cout << grid[i][j];
			}
		}cout << endl;
		hist.clear(); R = 0, C = 0;
	}
	return 0;
}
