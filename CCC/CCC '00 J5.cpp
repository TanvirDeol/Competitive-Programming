#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef vector<vector<string>> graph;

vector<string> links;
graph web;

void func(string s, int index) {

	int sidx = s.find("<A HREF=");
	string temp = s.substr(sidx + 9);
	int eidx = temp.find("\">");
	temp = temp.substr(0, eidx);

	web[index].push_back(temp);
	string rem = s.substr(sidx + eidx);
	if (rem.find("<A HREF=") != -1) {
		func(rem, index);
	}
}
int main()
{
	string emp;
	int N; getline(cin, emp);
	N = stoi(emp);

	for (int i = 0; i < N; i++) {
		web.push_back(vector<string>());
	}
	for (int i = 0; i < N; i++) {
		string link; getline(cin, link);
		links.push_back(link);
		string s;
		while (true) {
			getline(cin, s);
			if (s == "</HTML>")break;
			if (s.find("<A HREF=") != -1) {
				func(s, links.size() - 1);
			}
		}
	}
	for (int i = 0; i < web.size(); i++) {
		for (int j = 0; j < web[i].size(); j++) {
			cout << "Link from " << links[i] << " to ";
			cout << web[i][j] << endl;
		}
	}
	string s, s2;
	while (true) {
		getline(cin, s);
		if (s == "The End")break;
		getline(cin, s2);
		queue<string> que;
		que.push(s);
		bool found = false;
		vector<bool> vis(N, false);
		while (!que.empty()) {
			string cur = que.front(); que.pop();
			int idx = find(links.begin(), links.end(), cur) - links.begin(); vis[idx] = true;
			for (vector<string>::iterator it = web[idx].begin(); it != web[idx].end(); ++it) {
				if (*it == s2) { cout << "Can surf from " << s << " to " << s2 << "." << endl; found = true; break; }
				else {
					int ix = find(links.begin(), links.end(), *it) - links.begin();
					if (vis[ix])continue;
					else {
						que.push(*it); vis[ix] = true;
					}
				}
			}if (found)break;
		}
		if (!found) cout << "Can't surf from " << s << " to " << s2 << "." << endl;
	}
	return 0;
}