#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, K; cin >> N >> K;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		int inp; cin >> inp;
		arr[i] = inp;
	}
	sort(arr, arr + N);
	int pairs = 0;
	int start = 0;
	for (int i = start; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (abs(arr[i] - arr[j]) >= K) {
				pairs += N - j; break;
			}
		}
	}
	cout << pairs << endl;
	return 0;
}
