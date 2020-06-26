#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;
 
int main() {
	int N; cin >> N;
	string a,b,c;
	bool t = 0;
	int A=N, B=N, C = N;
	if (A % 7 == 0) {
		while (A > 0) {
			a += "7"; A -= 7;
		}
		t = 1;
	}
	if (B % 4 == 0) {
		 while (B > 0) {
			 b += "4"; B -= 4;
		 }
		 t = 1;
	}
		while (C > 0) {
			if (C < 7 && C != 4) { break; }
			if (C % 7 == 0) {
				while (C > 0) {
					c += "7"; C -= 7;
				}
			}
			if (C >= 4) { c += "4"; C -= 4; }
		}
		if (C == 0)t = 1;
 
	if(!t) cout << -1 << endl;
	else{
		string s;
		if (b.size() > 0 && c.size() > 0)s = c;
		if (a.size() > 0 && c.size() > 0)s = a;
		if (!a.empty() && b.empty() && c.empty())s = a;
		if (a.empty() && !b.empty() && c.empty())s = b;
		if (a.empty() && b.empty() && !c.empty())s = c;
		cout << s << endl;
 
	}
	return 0;
}
