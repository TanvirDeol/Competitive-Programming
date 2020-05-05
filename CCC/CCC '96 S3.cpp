#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<pair<int, string>>pos;
void func(string s) {
	do {
		pos.push_back({ stoi(s, 0, 2), s });
	} while (next_permutation(s.begin(), s.end()));
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	ll N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n >> k;
		string s(k, '1');
		string t((n - k), '0'); s += t;
		sort(s.begin(), s.end());
		func(s);
		cout << "The bit patterns are" << endl;
		for (int i = pos.size() - 1; i >= 0; i--)cout << pos[i].second << endl;
		cout << endl;
		pos.clear();
	}
	return 0;
}
