#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string>chords = { "C","C#","D","D#","E","F","F#","G","G#","A","A#","B" };
int semis(string a, string b) {
	int i = find(chords.begin(), chords.end(), a) - chords.begin();
	int j = i;
	int tones = 0;
	while (true) {
		if (i == chords.size())i = 0;
		if (chords[i] == b)break;
		tones++;
		i++;
	}
	int curtones = 0;
	while (true) {
		if (j == -1)j = chords.size() - 1;
		if (chords[j] == b)break;
		curtones++;
		j--;
	}
	return max(curtones, tones);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int q = 0; q < T; q++) {
		vector<string>arr(4);
		//collect array
		for (int i = 0; i < 4; i++)cin >> arr[i];
		//root check
		bool valid = false;
		//check with all cycles
		for (int i = 0; i < 4; i++) {
			string s;
			if (i > 0) {
				arr = { arr[3],arr[0],arr[1],arr[2] };
			}
			s += to_string(semis(arr[0], arr[3]));
			s += to_string(semis(arr[1], arr[2]));
			s += to_string(semis(arr[2], arr[3]));
			if (s == "1099") {
				valid = true;
				if (i == 0)cout << "root" << endl;
				else if (i == 1)cout << "first" << endl;
				else if (i == 2)cout << "second" << endl;
				else if (i == 3)cout << "third" << endl;
			}
		}
		if (!valid)cout << "invalid" << endl;
	}
	return 0;
}