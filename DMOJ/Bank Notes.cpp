#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> pos;

void func(vector<int> temp, vector<int>& notes, vector<int> amount, int rem, int start) {
    if (rem < 0)return;
    if (rem == 0)pos.push_back(temp);
    else {
        for (int i = start; i < notes.size(); i++) {
            if (amount[i] > 0) {
                temp.push_back(notes[i]);
                amount[i]--;
                func(temp, notes, amount, rem - notes[i], i);
                temp.erase(temp.begin() + temp.size() - 1);
            }
        }
    }
}

vector<vector<int>> comb(vector<int> notes, vector<int>amount, int target) {
    sort(notes.begin(), notes.end());
    vector<int> temp;
    func(temp, notes, amount, target, 0);
    return pos;
}

int main()
{
    cin >> N;
    vector<int> notes;
    vector<int> amount;
    int goal = 0;
    for (int i = 0; i < N; i++) {
        int inp; cin >> inp;
        notes.push_back(inp);
    }
    for (int i = 0; i < N; i++) {
        int inp; cin >> inp;
        amount.push_back(inp);
    }
    cin >> goal;


    vector<vector<int>> ways = comb(notes, amount, goal);
    int min = INT_MAX;
    for (int i = 0; i < ways.size(); i++) {
        int cur = ways[i].size();
        if (cur < min)min = cur;
    }
    cout << min << endl;
}
