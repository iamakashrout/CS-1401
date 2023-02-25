// INSERTION SORT

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; // number of test cases
    cin>>t;
    while(t--){
        int n; // size of list
        cin>>n;
        int array[n];
        for(int i=0; i<n; i++){ // taking input of list
            cin>>array[i];
        }
        int swaps=0; // count of swaps
        int comparisions=0; // count of comparisions
        int iterations=0; // count of iterations
        for(int i=1; i<n; i++){
            int key=array[i];
            int j=i-1;
            while(j>=0 && array[j]>key){ // comparing elements on the left side
                comparisions++;
                array[j+1]=array[j]; // move greater elements one index forward
                j--;
                swaps++;
                iterations++;
            }
            array[j+1]=key; // send element being checked to its correct index
        }
        for(int i=0; i<n; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
        cout<<"Swaps= "<<swaps<<endl;
        cout<<"Comparisions= "<<comparisions<<endl;
        cout<<"Iterations= "<<iterations<<endl;
    }
    return 0;
}