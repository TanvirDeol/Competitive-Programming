#include <bits/stdc++.h>
using namespace std;

string conv(int n) {
	char c = '0';
	if (n == 0)return " ";
	else if (n >= 1 && n <= 26)
	{
		c = 64 + n; string s(1, c);
		return s;
	}
	else if (n == 27)return ".";
	else if (n == 28) return ",";
	else if (n == 29) return "!";
	else if (n == 30) return "?";

	return "";
}
bool prime(int n) {
	if (!(n & 1))return false;
	if (n % 3 == 0)return false;
	for (int i = 5; i <= sqrt(n); i += 6) {
		if (n % i == 0)return false;
	}
	return true;
}
int main() {
	vector<int>facs;
	for (int t = 100000; t < 500000; t++) {
		if (prime(t)) {
			facs.push_back(t);
		}
	}

	for (int q = 0; q < 5; q++) {
		int N; cin >> N; string res;
		vector<int>data(N, 0);
		for (int i = 0; i < N; i++) {
			long long inp; cin >> inp;
			for (int k = 0; k < facs.size(); k++) {
				if (inp % facs[k] == 0) {
					data[i] = (inp / facs[k]);
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (data[i] < 1000) {
				int f = (data[i] - (data[i] % 100)) / 100;
				int s = data[i] % 100;
				res += conv(f); res += conv(s);
			}
			else if (data[i] >= 1000) {
				int f = (data[i] - (data[i] % 100)) / 100;
				int s = data[i] % 100;
				res += conv(f); res += conv(s);
			}
		}
		cout << res << endl;
	}


	return 0;
}