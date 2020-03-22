#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main() {
    int N, K; cin >> N >> K;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int* dp = new int[N];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    for (int i = 2; i < N; i++) {
        if (i < K) {
            int sum = 0;
            int min = INT_MAX;
            for (int q = 1; q <= i; q++) {
                sum = abs(arr[i] - arr[i - q]) + dp[i - q];
                if (sum < min)min = sum;
            }
            dp[i] = min;
        }
        else {
            int sum = 0;
            int min = INT_MAX;
            for (int j = 1; j <= K; j++) {
                sum = abs(arr[i] - arr[i - j]) + dp[i - j];
                if (sum < min)min = sum;
            }
            dp[i] = min;
        }
    }

    cout << dp[N - 1] << "\n";
    return 0;
}
