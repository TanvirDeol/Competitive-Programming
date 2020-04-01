#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>dp(31, 0);
string zero = "Good writing is good writing is good writing.";
char func(int n, int index) {
    if (n == 0)return zero.at(index);

    string one = "Good writing is good ";
    string two = " writing is good ";
    string three = " is good writing.";

    if (index < one.size())return one.at(index);
    else index -= one.size();

    if (index < dp[n - 1])return func(n - 1, index);
    else index -= dp[n - 1];

    if (index < two.size())return two.at(index);
    else index -= two.size();

    if (index < dp[n - 1])return func(n - 1, index);
    else index -= dp[n - 1];

    if (index < three.size())return three.at(index);
    else index -= two.size();


    return '0';
}

int main()
{

    dp[0] = zero.size();
    for (int i = 1; i <= 30; i++) {
        dp[i] = 55 + (dp[i - 1] * 2);
    }

    int N; cin >> N;
    for (int q = 0; q < N; q++) {
        int x, y; cin >> x >> y; y--;
        if (y > dp[x])cout << '.' << endl;
        else cout << func(x, y) << endl;
    }

    return 0;
}