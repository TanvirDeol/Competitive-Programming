#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

	for (int i = 0; i < 10; i++) {
		double smarties[8] = {};
		int sum = 0;
		string inp;

		while (inp.compare("EOB") != 0) {
			getline(cin, inp);
			char c = inp.at(0);
			char d = inp.at(1);
			switch (c)
			{
			case 'o': smarties[0]++; break;
			case 'b': if (d == 'l') { smarties[1]++; break; }
					else { smarties[6]++; break; }
			case 'g': smarties[2]++; break;
			case 'y': smarties[3]++; break;
			case 'p': smarties[4]++; break;
			case 'v': smarties[5]++; break;
			case 'r': smarties[7]++; break;
			default:
				break;
			}

		}

		for (int i = 0; i < 7; i++) {
			if (smarties[i] > 0) {
				smarties[i] = ceil(smarties[i] / 7.0);
				sum += smarties[i];
			}
		}
		sum = sum * 13;
		int redSum = smarties[7] * 16;
		cout << sum + redSum << endl;

	}
		return 0;
	}