#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	for (int q = 0; q < 10; q++) {
		string inp; getline(cin, inp);
		if (inp[0] == 'e') {
			string s; getline(cin, s);
			vector< queue<char> >que;
			vector<string> sentence;

			istringstream iss(s);
			for (string s; iss >> s;) {
				sentence.push_back(s);

			}
			for (string str : sentence) {
				queue<char> charLine;
				for (int j = 0; j < str.size(); j++) {
					charLine.push(str[j]);
				}
				que.push_back(charLine);

			}

			vector<int> sizes;
			for (string s : sentence) {
				sizes.push_back(s.size());
			}

			bool end = false; string res = ""; int charCount = 0; int i = 0; int count = 0;

			while (!end) {
				for (queue<char>& charQ : que) {
					if (i < sizes.size()) {
						if (charCount == sizes[i]) {
							res += " "; i++; charCount = 0;
						}
					}
					if (!charQ.empty()) {
						res += charQ.front();
						charCount++;
						charQ.pop(); count = 0;
					}
					else {count++;
						if (count == que.size()) {
							end = true;
						}
					}

				}
			}
			string out = res.substr(0, res.size() - 1);
			cout << out << endl;
		}
		else if (inp[0] == 'd') {
			string s; getline(cin, s);
			vector< queue<char> >que;
			vector<string> sentence;


			istringstream iss(s);
			for (string s; iss >> s;) {
				sentence.push_back(s);
			}

			vector < vector<char> >res(sentence.size());
			vector<int> sizes;
			for (int i = 0; i < sentence.size(); i++) {
				sizes.push_back(sentence[i].size());
			}

			/*	for (string str : sentence) {
				queue<char> charLine;
				for (int j = 0; j < str.size(); j++) {
					charLine.push(str[j]);
				}
				que.push_back(charLine);
			}*/
			int k = 0;
			for (int i = 0; i < sentence.size(); i++) {

				for (int j = 0; j < sentence[i].size(); j++) {
					if (k < sentence.size()) {
						if (res[k].size() < sizes[k]) {
							res[k].push_back(sentence[i][j]);

						}
						else {
							j--;
						}
					}
					else {
						k = 0;
						if (res[k].size() < sizes[k]) {
							res[k].push_back(sentence[i][j]);

						}
						else {
							j--;
						}
					}
					k++;
				}

			}
			string out = "";
			for (vector<char> v : res) {
				for (int i = 0; i < v.size(); i++) {
					out+= v[i];
				}
				out+= " ";
			}
			string o = out.substr(0, out.size() - 1);

			cout<<o<<endl;


		}
	}
	return 0;
}