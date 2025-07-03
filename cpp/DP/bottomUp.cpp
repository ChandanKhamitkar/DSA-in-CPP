#include <bits/stdc++.h>
using namespace std;

//Tabulation approach
// fibonaccii

int main()
{
    int n = 6;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}