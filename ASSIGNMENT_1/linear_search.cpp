// LINEAR SEARCH

#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &list, int num)
{
    for (int i = 0; i < list.size(); i++) // loop to traverse the list
    {
        if (list[i] == num) // if number is found, return index
        {
            return i;
        }
    }
    return -1; // if number not found, return -1;
}

int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of list
        cin>>n;
        vector<int> list(n); // taking input of list
        for(int i=0; i<n; i++){
            cin>>list[i];
        }
        int num; // number to be searched
        cin >> num;
        cout << find(list, num) << endl; // calling linear search function
    }
    return 0;
}