#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<int>av;
vector<int>need;
int pat;
void subtract(int aIndex, int nIndex) {
	if (need[nIndex] >= av[aIndex]) {
		need[nIndex] -= av[aIndex]; pat += av[aIndex];
		av[aIndex] = 0;
	}
	else {
		av[aIndex] -= need[nIndex]; pat += need[nIndex];
		need[nIndex] = 0;
	}
}
void solve(int i) {
	if (need[i] == 0)return;

	if (i == 6) {
		if (av[2] > 0) subtract(2, 6);
		if (av[4] > 0)subtract(4, 6);
	}
	if (i == 7) {
		if (av[2] > 0) subtract(2, 7);
		if (av[4] > 0)subtract(4, 7);
		if (av[3] > 0) subtract(3, 6);
		if (av[5] > 0)subtract(5, 6);
	}
	if (i == 4) {
		if (av[0] > 0)subtract(0, 4);
	}
	if (i == 5) {
		if (av[0] > 0)subtract(0, 5);
		if (av[1] > 0)subtract(1, 5);
	}
	if (i == 2) {
		if (av[0] > 0)subtract(0, 2);
	}
	if (i == 3) {
		if (av[0] > 0)subtract(0, 3);
		if (av[1] > 0)subtract(1, 3);
	}
}
void func(int i, bool neg) {
	if (need[i] <= av[i]) {
		subtract(i, i);
	}
	else {
		subtract(i, i);
		if (!neg) {
			subtract(i - 1, i);
		}
	}
}

int main()
{
	pat = 0;

	for (int i = 0; i < 8; i++) {
		int n; cin >> n;
		av.push_back(n);
	}
	for (int i = 0; i < 8; i++) {
		int n; cin >> n;
		need.push_back(n);
	}
	func(6, true); func(7, false); func(4, true); func(5, false); func(2, true); func(3, false); func(0, true); func(1, false);

	solve(6);
	if (need[6] > 0) {
		if (av[0] > 0)subtract(0, 6);
	}
	solve(4); solve(2); solve(7); solve(5); solve(3);


	if (need[7] > 0) {
		if (av[0] > 0)subtract(0, 7);
		if (av[1] > 0)subtract(1, 7);
	}
	cout << pat << endl;
	return 0;
}