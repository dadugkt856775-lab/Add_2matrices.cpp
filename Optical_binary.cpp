#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> keys(n), freq(n);

    for (int& x : keys)
        cin >> x;

    for (int& x : freq)
        cin >> x;

    vector<vector<int>> dp(
        n,
        vector<int>(n, 0)
    );

    vector<vector<int>> sum(
        n,
        vector<int>(n, 0)
    );

    for (int i = 0; i < n; i++) {
        sum[i][i] = freq[i];
        dp[i][i] = freq[i];
    }

    for (int len = 2; len <= n; len++) {

        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            sum[i][j] =
                sum[i][j - 1] + freq[j];

            dp[i][j] = INT_MAX;

            for (int root = i; root <= j; root++) {

                int left =
                    (root > i) ? dp[i][root - 1] : 0;

                int right =
                    (root < j) ? dp[root + 1][j] : 0;

                dp[i][j] =
                    min(
                        dp[i][j],
                        left + right + sum[i][j]
                    );
            }
        }
    }

    cout << "Minimum Search Cost: "
         << dp[0][n - 1] << endl;

    return 0;
}
