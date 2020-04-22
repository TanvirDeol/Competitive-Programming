#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	int xi, yi, xe, ye; cin >> xi >> yi >> xe >> ye;
	int year, mon, day, hour, mint, sec;
	string s; cin >> s;
	replace(s.begin(), s.end(), ':', ' ');
	istringstream ss(s);
	ss >> year >> mon >> day >> hour >> mint >> sec;
	int sum = abs(xe - xi) + abs(ye - yi);
	//int  tot= 1;
	//while (tot < 100000) {
		//int sum = 1;
	while (sum != 0) {
		if (sum >= (60 - sec)) {
			sum -= (60 - sec); sec = 0;
			mint++;
		}
		else {
			sec += sum; sum = 0;
		}
		if (sec > 59) {
			sec -= 60; mint++;
		}
		if (mint > 59) {
			mint -= 60; hour++;
		}
		if (hour > 23) {
			hour -= 24; day++;
		}
		if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) {
			if (day > 31) {
				day -= 31;
				mon++;
			}
		}
		if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
			if (day > 30) {
				day -= 30; mon++;
			}
		}
		if (mon == 2) {
			if (year % 4 == 0) {
				if (day > 29) {
					day -= 29; mon++;
				}
			}
			else {
				if (day > 28) {
					day -= 28; mon++;
				}
			}
		}
		if (mon > 12) {
			mon -= 12; year++;
		}
	}

	cout << year << ":";
	if (mon < 10) {
		cout << "0" << mon << ":";
	}
	else {
		cout << mon << ":";
	}
	if (day < 10) {
		cout << "0" << day << ":";
	}
	else cout << day << ":";
	if (hour < 10) {
		cout << "0" << hour << ":";
	}
	else { cout << hour << ":"; }
	if (mint < 10) {
		cout << "0" << mint << ":";
	}
	else { cout << mint << ":"; }
	if (sec < 10) {
		cout << "0" << sec << endl;
	}
	else { cout << sec << endl; }

	//tot++;
//}
	return 0;
}