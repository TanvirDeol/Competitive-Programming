#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, double> pi;

int main() {
	int N;
	cin >> N;
	ll sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += pow(2, i);
	}
	cout << sum << endl;
	return 0;
}
