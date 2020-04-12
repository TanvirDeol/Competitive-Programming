#include <bits/stdc++.h>
using namespace std;
int m, n;
bool works = false;
vector<string>A; vector<string>B;

vector<int> func(vector<int> temp) {
    string sum1, sum2;
    for (int i = 0; i < temp.size(); i++) {
        sum1 += A[temp[i] - 1]; sum2 += B[temp[i] - 1];
    }
    if (sum1 == sum2) { works = true; return temp; }

    for (int i = 1; i <= n; i++) {
        vector<int> t = temp;
        if (temp.size() + 1 >= m)continue;
        t.push_back(i);
        vector<int>res = func(t);
        if (res.size() != 0)return res;
    }
    return vector<int>();
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++) { string x; cin >> x; A.push_back(x); }
    for (int i = 0; i < n; i++) { string x; cin >> x; B.push_back(x); }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        vector<int>vec;
        vec.push_back(i);
        ans = func(vec);
        if (works) {
            break;
        }
        else { ans.clear(); }
    }
    if (!works) cout << "No solution." << endl;
    else { cout << ans.size() << endl;  for (int x : ans)  cout << x << endl; }

    return 0;
}