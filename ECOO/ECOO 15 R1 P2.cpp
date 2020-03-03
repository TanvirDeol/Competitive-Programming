#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int W; int sum = 0;
void print(string s) {
	if (s.size() > W) {
		string s1 = s.substr(0, W);
		cout << s1 << "\n";
		string s2 = s.substr(W);
		print(s2);
	}
	else if (s.size() == W) {
		cout << s << "\n"; sum = 0;
	}
	else {
		cout << s;
		sum = s.size();
	}
}

int main() {

	for (int i = 0; i < 10; i++) {
		string emp; getline(cin, emp);
		W = stoi(emp);
		string s; getline(cin, s);
		vector<string> result;
		istringstream iss(s);
		for (string s; iss >> s;) {
			result.push_back(s + " ");
		}result[result.size() - 1].pop_back();



		sum = 0;
		for (auto i : result) {
			sum += i.size();
			if (sum - 1 <= W && sum > W&& i.back() == ' ') {
				i.pop_back();
				cout << i;
			}
			else if (sum > W) {
				cout << "\n"; sum = i.size();
				if (i.size() <= W) {
					cout << i;
				}
				else if (i.size() > W) {
					string s1 = i.substr(0, W);
					cout << s1 << "\n";
					string s2 = i.substr(W);
					print(s2);
				}
			}

			else {
				cout << i;
			}
		}
		cout << "\n=====\n";

	}
	return 0;
}