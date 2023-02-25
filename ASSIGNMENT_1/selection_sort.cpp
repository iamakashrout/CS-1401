// SELECTION SORT

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
        int iterations=0; // count of swaps
        for(int i=0; i<n-1; i++){
            int minIndex=i; // index of smallest element in the part of array being iterated
            int min=array[i];
            for(int j=i+1; j<n; j++){
                comparisions++;
                if(array[j]<array[minIndex]){ // if elemnent smaller than minIndex element, update minIndex
                    minIndex=j;
                    swaps++;
                }
                iterations++;
            }
            int temp=array[minIndex]; // after iteration, send minIndex element to the front
            array[minIndex]=array[i];
            array[i]=temp;
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