#include <bits/stdc++.h>
#include <regex>
#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<string>perms;
bool checkPerm(string& s, string N) {
	stack<char> stringS;
	for (int i = 0; i < s.size(); i++) {
		stringS.push(s.at(i));
	}
	while (!stringS.empty()) {
		char check = stringS.top();
		if (N.find(check) != string::npos) {
			stringS.pop();
			int index = find(N.begin(), N.end(), check) - N.begin();
			N.replace(index, 1, "");
		}
		else {
			return false;
		}
	}
	if (perms.find(s) == perms.end()) {
		perms.insert(s);
		return true;
	}
	return false;
}
int main() {
	string N, H;
	cin >> N >> H;
	int count = 0;
	for (int i = 0; i < H.size() - N.size() + 1; i++) {
		string s = H.substr(i, N.size());
		bool check = checkPerm(s, N);
		if (check) {
			//	cout << s << endl;
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}
