#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pi;
#define mp make_pair

int myTeam;
int wins;
void calc(vector<int>& score) {
	int maxIdx = -1, max = -1;
	for (int i = 0; i < score.size(); i++) {
		//cout << score[i] << " ";
		int cur = score[i]; if (cur > max) { max = cur; maxIdx = i; }
	}//cout << endl;
	sort(score.rbegin(), score.rend());
	if (score[1] < score[0]) {
		if (maxIdx + 1 == myTeam)wins++;
	}
	return;
}

void sim(vector<pi> games, vector<int> score, char outcome) {
	//1st W
	pi game = games[0]; games.erase(games.begin());
	if (outcome == 'W') {
		score[game.first - 1] += 3;
	}
	//1st L
	else if (outcome == 'L') {
		score[game.second - 1] += 3;
	}
	//1st T
	else if (outcome == 'T') {
		score[game.first - 1] += 1;
		score[game.second - 1] += 1;
	}
	if (games.empty()) {
		calc(score);
		return;
	}
	else {
		sim(games, score, 'W');
		sim(games, score, 'L');
		sim(games, score, 'T');
	}

}
int main()
{
	wins = 0;
	vector<pi> games;
	games.push_back(mp(1, 2));
	games.push_back(mp(1, 3));
	games.push_back(mp(1, 4));
	games.push_back(mp(2, 3));
	games.push_back(mp(2, 4));
	games.push_back(mp(3, 4));

	vector<int> score = { 0,0,0,0 };
	cin >> myTeam;
	int played; cin >> played;

	for (int i = 0; i < played; i++) {
		int f, s, fp, sp; cin >> f >> s >> fp >> sp;
		if (fp > sp) {
			score[f - 1] += 3;
		}
		else if (fp < sp) {
			score[s - 1] += 3;
		}
		else if (fp == sp) {
			score[f - 1] += 1;
			score[s - 1] += 1;
		}
		pi cur = mp(f, s);
		pi rev = mp(s, f);
		int idx = find(games.begin(), games.end(), cur) - games.begin();
		if (idx == games.size()) idx = find(games.begin(), games.end(), rev) - games.begin();
		games.erase(games.begin() + idx);
	}
	if (!games.empty()) {
		sim(games, score, 'W');
		sim(games, score, 'L');
		sim(games, score, 'T');
	}
	cout << wins << endl;
	return 0;
}