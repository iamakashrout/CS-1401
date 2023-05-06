#include<bits/stdc++.h>
using namespace std;

vector<int> hour = {1, 2, 4, 8};
vector<int> minute = {1, 2, 4, 8, 16, 32};

void helper(vector<string> &ans, pair<int, int> time, int turnedOn, int start)
{
    if (turnedOn == 0)
    {
        ans.push_back(to_string(time.first) + (time.second < 10 ? ":0" : ":") + to_string(time.second));
        return;
    }
    for (int i = start; i < hour.size() + minute.size(); i++)
    {
        if (i < hour.size())
        {
            time.first += hour[i];
            ;
            if (time.first < 12)
            {
                helper(ans, time, turnedOn - 1, i + 1);
            }
            time.first -= hour[i];
        }
        else
        {
            time.second += minute[i - hour.size()];
            if (time.second < 60)
            {
                helper(ans, time, turnedOn - 1, i + 1);
            }
            time.second -= minute[i - hour.size()];
        }
    }
}

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> ans;
    helper(ans, {0, 0}, turnedOn, 0);
    return ans;
}

int main(){
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    vector<string> ans = readBinaryWatch(n);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}