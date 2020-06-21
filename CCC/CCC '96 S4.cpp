#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pi;
#define INF 3e18

int wordToNum(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'I') {
			if (i < s.size() - 1) {
				if (s[i + 1] == 'V') { sum += 4; i++; }
				else if (s[i + 1] == 'X') { sum += 9; i++; }
				else sum += 1;
			}
			else sum += 1;
		}
		else if (s[i] == 'V') sum += 5;
		else if (s[i] == 'X') {
			if (i < s.size() - 1) {
				if (s[i + 1] == 'L') { sum += 40; i++; }
				else if (s[i + 1] == 'C') { sum += 90; i++; }
				else sum += 10;
			}
			else sum += 10;
		}
		else if (s[i] == 'L') sum += 50;
		else if (s[i] == 'C') {
			if (i < s.size() - 1) {
				if (s[i + 1] == 'D') { sum += 400; i++; }
				else if (s[i + 1] == 'M') { sum += 900; i++; }
				else sum += 100;
			}
			else sum += 100;
		}
		else if (s[i] == 'D') sum += 500;
		else if (s[i] == 'M') sum += 1000;
	}
	return sum;
}

string numToWord(int n) {
	string s;
	while (n > 0) {
		if (n == 1000) {s += "M"; n -= 1000;}
		if (n<1000 && n>=500){
			if (n >= 900) { s += "CM"; n -= 900; }
			else { s += "D"; n -= 500; }
		}
		if (n < 500 && n >= 100) {
			if (n >= 400) { s += "CD"; n -= 400; }
			else { s += "C"; n -= 100; }
		}
		if (n < 100 && n >= 50) {
			if (n >= 90) { s += "XC"; n -= 90; }
			else { s += "L"; n -= 50; }
		}
		if (n < 50 && n >= 10) {
			if (n >= 40) { s += "XL"; n -= 40; }
			else { s += "X"; n -= 10; }
		}
		if (n < 10 && n >= 5){
			if (n >= 9) { s += "IX"; n -= 9; }
			else { s += "V"; n -= 5; }
		}
		if (n < 5 && n >= 1) {
			if (n >= 4) { s += "IV"; n -= 4; }
			else { s += "I"; n -= 1; }
		}
	}
	return s;
}
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		cout << s;
		int idx = find(s.begin(), s.end(), '+')-s.begin();
		int a = wordToNum(s.substr(0, idx));
		int b = wordToNum(s.substr(idx, s.size() - 1));
		if (a + b > 1000)cout << "CONCORDIA CUM VERITATE" << endl;
		else cout << numToWord(a + b) << endl;
	}
	return 0;
}
