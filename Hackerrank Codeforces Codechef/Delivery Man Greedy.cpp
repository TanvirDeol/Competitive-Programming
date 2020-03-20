#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N, X, Y;
	cin >> N >> X >> Y;
	int* A = new int[N];
	int* B = new int[N];
	vector<pair<int, int> > dif;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		int diff = A[i] - B[i];
		dif.push_back(make_pair(diff, i));
	}
	sort(dif.begin(), dif.end());
	reverse(dif.begin(), dif.end());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (dif[i].first > 0 && X != 0) {
			sum += A[dif[i].second];
			X--;
		}
		else {
			sum += B[dif[i].second];
		}
	}
	cout << sum << endl;
	return 0;
}
