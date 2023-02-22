// QUICK SORT

#include<bits/stdc++.h>
using namespace std;

int partition(int* array, int start, int end){
    int pivot=array[end]; // taking pivot as last element
    int i=start;
    for(int j=start; j<end; j++){
        if(array[j]<=pivot){ // shift elements smaller than pivot to the left of it
            int temp=array[j];
            array[j]=array[i];
            array[i]=temp;
            i++;
        }
    }
    int t=array[i];
    array[i]=array[end];
    array[end]=t;
    return i; // return index of pivot which is at its correct position
}

void quickSort(int* array, int start, int end){
    if(start>=end){ // if less than two elements
        return;
    }
    int pivot=partition(array, start, end); // finding pivot element to divide the array
    quickSort(array, start, pivot-1); // sorting left part
    quickSort(array, pivot+1, end); // sorting right part
}

int main(){
    int t; // number of test cases
    cin>>t;
    while(t--){
        int n; // size of input array
        cin>>n;
        int array[n];
        for(int i=0; i<n; i++){ // taking in input array
            cin>>array[i];
        }
        quickSort(array, 0, n-1); // calling Quick Sort function
        for(int i=0; i<n; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}