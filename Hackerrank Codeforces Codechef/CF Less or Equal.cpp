#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;
 
 
int main() {
	int N, K; cin >> N >> K;
	vector<int>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	if (K == N)cout << A[A.size() - 1] << endl;
	else if (K == 0) {
		if (A[0] == 1) cout << -1 << endl;
		else cout << 1 << endl;
	}
	else {
		if (A[K - 1] == A[K]) {
			cout << -1 << endl;
		}
		else cout << A[K - 1] << endl;
	}
}
