#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &heights, int k, int index, vector<int> &dp)
{
    if (index == heights.size() - 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int minPath = INT_MAX, x = index + 1, y = index + k;
    for (int i = x; i <= y; i++)
    {
        if (i < heights.size())
        {
            int cost = abs(heights[index] - heights[i]) + fun(heights, k, i, dp);
            minPath = min(minPath, cost);
        }
        else
            break;
    }

    dp[index] = minPath;
    cout << "New dp adding to " << index << " : " << dp[index] << "\n";
    return dp[index];
}

int main()
{
    vector<int> heights = {10, 5, 20, 0, 15};
    int k = 2, path = 0;
    vector<int> dp(heights.size(), -1);
    cout << fun(heights, k, 0, dp);
    return 0;
}
