#include<bits/stdc++.h>
using namespace std;

void solve(int n, string temp, vector<string> &ans, int open, int closed)
{
    if (temp.length() == 2 * n)
    {
        ans.push_back(temp);
        return;
    }
    if (open < n)
    {
        solve(n, temp + '(', ans, open + 1, closed);
    }
    if (closed < open)
    {
        solve(n, temp + ')', ans, open, closed + 1);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    solve(n, "", ans, 0, 0);
    return ans;
}

int main(){
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    vector<string> ans=generateParenthesis(n);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}