#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
	for (int q = 0; q < 10; q++) {
		int req = 0, studs = 0;
		double one = 0, two = 0, three = 0, four = 0;
		cin >> req;
		cin >> one >> two >> three >> four;
		cin >> studs;
		int* studCounts = new int[4];
		int sum = 0;

		studCounts[0] = studs * one; sum += studCounts[0];
		studCounts[1] = studs * two; sum += studCounts[1];
		studCounts[2] = studs * three; sum += studCounts[2];
		studCounts[3] = studs * four; sum += studCounts[3];

		int mostStuds = studCounts[0]; int studIndex = 0;
		if (sum != studs) {
			for (int i = 1; i < 4; i++) {
				if (studCounts[i] > mostStuds) {
					mostStuds = studCounts[i];
					studIndex = i;
				}
			}
			if (sum < studs) {
				studCounts[studIndex] += abs(studs - sum);
			}
			else if (sum > studs) {
				studCounts[studIndex] -= abs(sum - studs);
			}
		}

		int* funds = new int[4]; int total = 0;
		funds[0] = studCounts[0] * 12; total += funds[0];
		funds[1] = studCounts[1] * 10; total += funds[1];
		funds[2] = studCounts[2] * 7; total += funds[2];
		funds[3] = studCounts[3] * 5; total += funds[3];
		//if total/2 >=
		if (total / 2 >= req) {
			cout << "NO" << endl;
		}
		else if (total / 2 < req) {
			cout << "YES" << endl;
		}
	}
	return 0;
}