#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;


int main() {
	ifstream cin("highcard.in");
	ofstream cout("highcard.out");
	int N; cin >> N;
	vector<int>A;
	vector<int>B(N);
	vector<bool>vis((2 * N) + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> B[i]; vis[B[i]] = 1;
	}
	for (int i = 1; i <= 2 * N; i++) if (!vis[i])A.push_back(i);
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	int idx = 0; int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (A[idx] > B[i]) {
			cnt++; idx++;
		}
		else continue;
	}
	cout << cnt << endl;
	return 0;
}
