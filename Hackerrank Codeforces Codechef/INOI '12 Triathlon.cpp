#include <bits/stdc++.h>
using namespace std;
int main() {
	int N; cin >> N;
	int* firstData = new int[N];
	int* secondData = new int[N];
	int minIndex = 0; int min = 2147483647; int sum = 0;
	for (int i = 0; i < N; i++) {
		int one, two, three;
		cin >> one >> two >> three;
		firstData[i] = one;
		secondData[i] = two + three;
		int cur = two + three;
		if (cur < min) {
			min = cur;
			minIndex = i;
		}
		sum += one;
	}
	sum += secondData[minIndex];
	cout << sum << endl;
	return 0;
}
