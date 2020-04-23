#include <bits/stdc++.h>
using namespace std;

set<string>emails;
string process(string s) {
	string res;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string bef = s.substr(0, s.find("@"));
	string aft = s.substr(s.find("@"));
	while (bef.find('.') < bef.size()) {
		bef.erase(bef.find("."), 1);
		if (bef.find('.') > bef.size())break;
	}
	if (bef.find("+")) bef = bef.substr(0, bef.find("+"));

	return bef + aft;
}
int main() {
	for (int q = 0; q < 10; q++) {
		string num; getline(cin, num);
		int N = stoi(num);
		for (int i = 0; i < N; i++) {
			string s; getline(cin, s);
			emails.insert(process(s));
		}
		cout << emails.size() << endl;
		emails.clear();
	}

	return 0;
}