#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;

ll N, cnt;
void search(string s) {
	ll x = atol(s.c_str());
	if (x > N)return;
	//if (s.size() > 10)return;
	cnt++;
	search(s + "0"); search(s + "1");

}
int main() {
	cnt = 0;
	cin >> N;
	search("1");
	cout << cnt << endl;
}

