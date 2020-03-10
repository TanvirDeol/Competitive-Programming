#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	for (int q = 0; q < 10; q++) {
		pair<double, double> pins[10];
		double x = 0, y = 0, s = 0, precision = 0;
		int expX = 0, expY = 0, expS = 0;
		scanf_s("%lf%d%lf%d%lf%d%lf", &x, &expX, &y, &expY, &s, &expS, &precision);
		x *= pow(10, expX);
		y *= pow(10, expY);
		s *= pow(10, expS);
		pins[0] = (make_pair(x, y));

		vector<pair<double, double> >points;
		for (int i = 0; i < 5; i++) {
			double one = 0, two = 0;
			int expOne = 0, expTwo = 0;
			scanf_s("%lf%d%lf%d", &one, &expOne, &two, &expTwo);
			one = one * pow(10.0, expOne * 1.0);
			two = two * pow(10, expTwo);
			points.push_back(make_pair(one, two));
		}

		double height = 0, halfBase = 0;
		halfBase = s / 2;
		height = halfBase * (sqrt(3));

		pair<double, double> seven = make_pair(x - halfBase, y + height);
		pins[6] = seven;
		pair<double, double> ten = make_pair(x + halfBase, y + height);
		pins[9] = ten;
		pair<double, double> five = make_pair(x, (y + height / 2));
		pins[4] = five;
		pair<double, double> eight = make_pair(x - (halfBase / 2), seven.second);
		pins[7] = eight;
		pair<double, double> nine = make_pair(x + (halfBase / 2), seven.second);
		pins[8] = nine;
		pair<double, double> four = make_pair(x - (halfBase * 0.75), five.second);
		pins[3] = four;
		pair<double, double> six = make_pair(x + (halfBase * 0.75), five.second);
		pins[5] = six;
		pair<double, double> two = make_pair(eight.first, y + (height / 4));
		pins[1] = two;
		pair<double, double> three = make_pair(nine.first, y + (height / 4));
		pins[2] = three;
		int closest = 0;
		for (int i = 0; i < points.size(); i++) {
			double minDist = INT_MAX;
			for (int j = 0; j < 10; j++) {
				double cur = sqrt(pow((points[i].first - pins[j].first), 2.0) + pow((points[i].second - pins[j].second), 2.0));
				if (cur < minDist) {
					minDist = cur;
					closest = j + 1;
				}
			}
			cout << closest << " ";
			closest = 0;
		}
		cout << endl;
	}
	return 0;
}

