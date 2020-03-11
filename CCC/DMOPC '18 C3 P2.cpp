#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define getInd(s) find(tones.begin(), tones.end(), s) - tones.begin()
vector<string> tones;

int calc(int n, int m) {
	if (m < n) {
		return m + tones.size() - n;
	}
	else {
		return abs(n - m);
	}
}
int main() {
	tones.push_back("A");
	tones.push_back("A#");
	tones.push_back("B");
	tones.push_back("C");
	tones.push_back("C#");
	tones.push_back("D");
	tones.push_back("D#");
	tones.push_back("E");
	tones.push_back("F");
	tones.push_back("F#");
	tones.push_back("G");
	tones.push_back("G#");

	string a, b, c;
	cin >> a >> b >> c;
	vector<int> diff(3);
	int x = getInd(a), y = getInd(b), z = getInd(c);
	diff[0] = calc(x, y); //cout << diff[0] << endl;
	diff[1] = calc(y, z); //cout << diff[1] << endl;
	diff[2] = calc(z, x); //cout << diff[2] << endl;
	int wrong = 0; bool isWrong = false;
	for (int i = 0; i < 3; i++) {
		if (diff[i] > 4) {
			wrong = i; isWrong = true;
		}
	}
	string type; string inv; string root; string res;
	if (!isWrong) {
		root = a;
		inv = "root position";
	}
	else {
		if (wrong == 0) {
			root = b; inv = "second inversion";
		}
		else if (wrong == 1) {
			root = c; inv = "first inversion";
		}
		else if (wrong == 2) {
			root = a; inv = "root position";
		}
	}

	diff.erase(diff.begin() + wrong);
	if (wrong != 1) {
		res = to_string(diff[0]) + to_string(diff[1]);
	}
	else {
		res = to_string(diff[1]) + to_string(diff[0]);
	}

	if (res == "43")type = "major";
	else if (res == "34") type = "minor";
	else if (res == "33") type = "diminished";
	else if (res == "44") type = "augmented";

	cout << root << endl << type << endl << inv << endl;

	return 0;
}