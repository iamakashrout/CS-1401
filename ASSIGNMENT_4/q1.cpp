#include<bits/stdc++.h>
using namespace std;

vector<string> solve(string num){
    if(num.size()==0){
        return {};
    }
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    queue<string> q;
    q.push("");
    for (int i = 0; i < num.size(); i++)
    {
        int digit = num[i] - '0';
        int n = q.size();
        for (int j = 0; j < n; j++)
        {
            string curr = q.front();
            q.pop();
            for (int k = 0; k < keypad[digit].size(); k++)
            {
                q.push(curr + keypad[digit][k]);
            }
        }
    }
    vector<string> ans;
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}

int main(){
    string num;
    cout << "Enter the number: " << endl;
    cin >> num;
    vector<string> ans = solve(num);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}