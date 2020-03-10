#include <bits/stdc++.h>
//Test
using namespace std;
long fact(long n) {
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}
int countPermutation(string str) {
    int freq[26] = { 0 };
    for (int i = 0; i < str.size(); i++) {
        freq[str[i] - 'a']++;
    }
    int res = fact(str.size());
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1)
            res /= fact(freq[i]);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 0, k = 0;
    cin >> n >> k;

    string str;
    cin >> str;
    if (k == 0) {
        cout << countPermutation(str);

    }
    else {
        int index = -1, secInd = -1;
        long long count = 0;
        string alp = "abcdefghijklmonpqrstuvwxyz";

        for (int i = 0; i < n; i++) {
            if (str[i] == '*' && index == -1) {
                index = i;
            }
            else if (str[i] == '*' && index > -1)
            {
                secInd = i;
            }
        }
        for (int i = 0; i < 26; i++) {
            str[index] = alp[i];
            if (secInd > -1) {
                for (int j = 0; j < 26; j++) {
                    str[secInd] = alp[j];
                    count += countPermutation(str);
                }
            }
            else {
                count += countPermutation(str);
            }

        }


        cout << count << endl;
    }
    return 0;
}