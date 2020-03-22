#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main() {
    int N; cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int* dp = new int[N];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(abs(arr[i] - arr[i - 1]) + dp[i - 1], abs(arr[i] - arr[i - 2]) + dp[i - 2]);
    }
    cout << dp[N - 1] << endl;
    return 0;
}
