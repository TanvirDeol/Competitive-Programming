#include <bits/stdc++.h>

using namespace std;

int getMin(string s) {

    stack<char> open;
    int empCount = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (c == '(')open.push(c);

        if (c == ')') {
            if (!open.empty()) open.pop();
            else empCount++;
        }
    }
    int sz = open.size();
    return sz + empCount;
}

int main()
{
    string s;
    getline(cin, s);

    int result = getMin(s);

    cout << result << "\n";

    return 0;
}
