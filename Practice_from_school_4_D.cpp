//
// Created on 2023/10/1.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    const int MAX_N = 1001;  // 最大存钱罐数量
    const int MAX_K = 2001;  // 最大选择硬币数量
    const int MAX_COINS = 1001;  // 最大硬币数量
    int coins[MAX_N][MAX_COINS];

    for (int i = 0; i < n; ++i) {
        int num_coins;
        cin >> num_coins;

        for (int j = 0; j < num_coins; ++j) {
            cin >> coins[i][j];
        }
    }

    long long dp[MAX_N][MAX_K];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            long long max_value = 0;
            long long current_value = 0;

            for (int t = 0; t <= min(j, MAX_COINS); ++t) {
                if (t > 0) {
                    current_value += coins[i - 1][t - 1];
                }
                max_value = max(max_value, dp[i - 1][j - t] + current_value);
            }

            dp[i][j] = max_value;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
