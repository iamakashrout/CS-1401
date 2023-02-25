// BUBBLE SORT

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
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1-i; j++){ // moving greatest elements to the last
                comparisions++;
                if(array[j+1]<array[j]){ // if an elemnent is greater than its next element, swap them
                    int temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                    swaps++;
                }
                iterations++;
            }
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