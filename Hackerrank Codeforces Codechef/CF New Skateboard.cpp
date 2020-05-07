#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long mod(long a, long b)
{
	return (a % b + b) % b;
}


int main() {
	ll n = 0;
	string s; cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		string sub = s.substr(i, 2);
		int parse = stoi(sub);
		if (parse % 4 == 0) {
			n += i; n++;
		}
	}
	n += count(s.begin(), s.end(), '4'); n += count(s.begin(), s.end(), '8'); n += count(s.begin(), s.end(), '0');
	cout << n << endl;

}
