// QUESTION-1
// COIN CHANGE PROBLEM

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> denominations = {10, 5, 1}; // denominations of coins
    int m; // amount
    cout << "Enter the amount m to be changed: " << endl;
    cin >> m;
    int tens = 0, fives = 0, ones = 0;
    // we greedily first use ten coins, then five coins and finally one coins
    if (m >= 10) // finding number of ten coins
    {
        tens += (m / 10);
        m = m % 10;
    }
    if (m >= 5) // finding number of five coins
    {
        fives += (m / 5);
        m = m % 5;
    }
    if (m >= 1) // finding number of one coins
    {
        ones += m;
    }
    int ans = tens + fives + ones; // total number of coins
    cout << "Minimum number of coins required is " << ans << " with " <<
    tens << " ten coins, " << fives << " five coins and " << ones << " one coins." << endl;
    return 0;
}