#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void addSolution(vector<string> &board, int n, vector<vector<string>> &ans)
{
    vector<string> currAns;
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            s += board[i][j];
        }
        currAns.push_back(s);
    }
    ans.push_back(currAns);
}

void solve(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        addSolution(board, n, ans);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';
            solve(board, row + 1, n, ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    solve(board, 0, n, ans);
    return ans;
}

int main(){
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] <<endl;
        }
        cout << endl;
    }
        return 0;
}