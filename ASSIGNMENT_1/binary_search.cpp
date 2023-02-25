// BINARY SEARCH

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &list, int num){
    int start=0; // lower end
    int end=list.size()-1; // upper end
    while(start<=end){
        int mid=(start+end)/2; // finding middle element
        if(list[mid]>num){ // if number is smaller than middle element, search left of middle
            end=mid-1;
        }
        else if(list[mid]<num){ // if number is greater than middle element, search right of middle
            start=mid+1;
        }
        else{
            return mid; // if number is equal to middle element, return that index
        }
    }
    return -1; // if number not found, return -1
}

int main(){
    int t; // number of test cases
    cin>>t;
    while(t--){
        int n; // size of list
        cin>>n;
        vector<int> list(n); // taking input of list
        for(int i=0; i<n; i++){
            cin>>list[i];
        }
        int num;
        cin>>num;
        cout << find(list, num) << endl; // calling binary search function
    }
    return 0;
}