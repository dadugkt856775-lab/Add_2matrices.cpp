#include <bits/stdc++.h>
using namespace std;

int main() {
    int length, n;
    cin >> length >> n;

    vector<int> cuts(n + 2);

    cuts[0] = 0;
    cuts[n + 1] = length;

    for (int i = 1; i <= n; i++)
        cin >> cuts[i];

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(
        n + 2,
        vector<int>(n + 2, 0)
    );

    for (int len = 2; len <= n + 1; len++) {
        for (int left = 0;
             left + len <= n + 1;
             left++) {

            int right = left + len;
            dp[left][right] = INT_MAX;

            for (int k = left + 1; k < right; k++) {
                int cost =
                    cuts[right] - cuts[left] +
                    dp[left][k] +
                    dp[k][right];

                dp[left][right] =
                    min(dp[left][right], cost);
            }

            if (dp[left][right] == INT_MAX)
                dp[left][right] = 0;
        }
    }

    cout << "Minimum Cost: "
         << dp[0][n + 1] << endl;

    return 0;
}
