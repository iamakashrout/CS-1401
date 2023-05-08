// QUESTION-1
// COIN CHANGE PROBLEM

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount){
    int dp[amount + 1]; // stroing answers till amount
    dp[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < coins.size(); j++) // checking for every denomination
        {
            if (i - coins[j] < 0) // if denomation is greater than remaining amount, break
            {
                break;
            }
            if (dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]); // take or not take case for current denomination
            }
        }
    }
    if (dp[amount] == INT_MAX) // no possible solution
    {
        return -1;
    }
    else
    {
        return dp[amount];
    }
}

int main()
{
    vector<int> denominations = {10, 5, 1}; // denominations of coins
    int m; // amount
    cout << "Enter the amount m to be changed: " << endl;
    cin >> m;
    int ans = coinChange(denominations, m); // function to find minimum number of coins
    cout << "Minimum number of coins required is " << ans << endl;
    return 0;
}