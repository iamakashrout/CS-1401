// MERGING TWO SORTED LISTS

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n1; // size of 1st list
        cin>>n1;
        vector<int> array1(n1);
        for(int i=0; i<n1; i++){ // taking input of 1st list
            cin>>array1[i];
        }
        int n2; // size of 2nd list
        cin>>n2;
        vector<int> array2(n2);
        for(int i=0; i<n2; i++){ // taking input of 2nd list
            cin>>array2[i];
        }
        vector<int> ans(n1+n2); // declaring answer list
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n1 && j < n2) // while both lists are being traversed
        {
            if (array1[i] < array2[j]) // smallest element is added to answer list
            {
                ans[k] = array1[i];
                i++;
            }
            else if (array1[i] > array2[j])
            {
                ans[k] = array2[j];
                j++;
            }
            k++;
        }
        while (i < n1) // if 2nd list gets over first
        {
            ans[k] = array1[i];
            i++;
            k++;
        }
        while (j < n2) // if 1st list gets over first
        {
            ans[k] = array2[j];
            j++;
            k++;
        }
        for (int w = 0; w < n1+n2; w++)
        {
            cout << ans[w] << " ";
        }
    }
    return 0;
}