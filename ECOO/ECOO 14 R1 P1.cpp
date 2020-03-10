#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 10; i++) {
		int D = 0, H = 0, M = 0;
		cin >> D >> H >> M;
		double multiplier = 86400 / 88642.663;

		double totalMin = (((D * 24 * 60) + (H * 60) + M + 37 + (22.663 / 60)) * 60) * multiplier;
		int mD = 0, mH = 0, mM = 0;

		mD = (totalMin / 86400);
		totalMin -= mD * 86400;
		mH = totalMin / 3600;
		totalMin -= mH * 3600;
		mM = totalMin / 60;

		string hour;
		string min;
		if (mM < 10) {
			min = "0" + to_string(mM);
		}
		else {
			min = to_string(mM);
		}
		if (mH < 10) {
			hour = "0" + to_string(mH);
		}
		else {
			hour = to_string(mH);
		}
		cout << "Day " << mD << ", " << hour << ":" << min << endl;

	}
	return 0;
}