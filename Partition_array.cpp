#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maximum = 0;

        for (int len = 1;
             len <= k && i - len >= 0;
             len++) {

            maximum = max(maximum, a[i - len]);

            dp[i] = max(
                dp[i],
                dp[i - len] + maximum * len
            );
        }
    }

    cout << "Maximum Sum: " << dp[n] << endl;

    return 0;
}
