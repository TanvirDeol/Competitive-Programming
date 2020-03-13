#include <bits/stdc++.h>
#include <regex>
#include <iostream>
using namespace std;

void charSys(string init, vector<char> charFind, vector<string> strRules, string& res) {
	int i = 0; int j = i;
	for (i = 0; i < init.size(); i++) {
		char cur = init.at(i);
		int index = find(charFind.begin(), charFind.end(), cur) - charFind.begin();
		string change = strRules[index];
		res.replace(j, 1, change);
		j += change.size();
	}
}
int main() {
	for (int q = 0; q < 10; q++) {
		int rules = 0, iter = 0;
		string ax; cin >> rules >> iter >> ax;
		vector<char> charFind;
		vector<string> strRules;
		for (int i = 0; i < rules; i++) {
			char c = '0'; string s;
			cin >> c >> s;
			charFind.push_back(c);
			strRules.push_back(s);
		}
		string res = ax;

		for (int i = 0; i < iter; i++) {
			charSys(res, charFind, strRules, res);
		}
		int len = res.size();
		cout << res[0] << res[res.size() - 1] << " " << len << endl;
	}
	return 0;
}
//iterate thru ever character, find its index in vector
//run that index and the string ref to another method where it updates the string
//sedn them a vector of indeces of the char, and it repleaces that
//CABABC