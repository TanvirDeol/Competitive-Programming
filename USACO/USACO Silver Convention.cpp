#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M, C;
vector<int>arr;

bool check(int wait) {
	int buses = 1, fArrive = arr[0], fIdx = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i] - fArrive > wait || i + 1 - fIdx > C) {
			fArrive = arr[i]; fIdx = i; buses++;
		}
	}
	return (buses <= M);
}
int binSrch(int l, int h) {
	if (l == h) return l;
	if (l + 1 == h) { if (check(l))return l; else return h; }
	int m = (l + h) / 2;
	if (check(m))return binSrch(l, m);
	else return binSrch(m + 1, h);
}
int main() {
	ifstream cin("convention.in");
	ofstream cout("convention.out");
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		int x; cin >> x; arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	cout << binSrch(0, 1000000000) << endl;
	return 0;
}
