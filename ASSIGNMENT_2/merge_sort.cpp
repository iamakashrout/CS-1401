// MERGE SORT

#include<bits/stdc++.h>
using namespace std;

void merge(int array[], int start, int mid, int end){
    int m=mid-start+1; // elements on left half
    int n=end-mid; // elements on right half
    int arr1[m];
    int arr2[n];
    for(int i=0; i<m; i++){ // filling left and right halves
        arr1[i]=array[start+i];
    }
    for(int i=0; i<n; i++){
        arr2[i]=array[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=start;
    while(i<m && j<n){ // finding smaller element
        if(arr1[i]<arr2[j]){
            array[k]=arr1[i];
            i++;
        }
        else{
            array[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<m){
        array[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n){
        array[k]=arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int start, int end)
{
    if (start>=end){ // if less than 2 elements in array
        return;
    }
 
    int mid=start+(end-start)/2; // finding middle element
    mergeSort(array, start, mid); // sorting left half
    mergeSort(array, mid+1, end); // sorting right half
    merge(array, start, mid, end); // merging the two sorted halves
}

int main(){
    int t; // number of test cases
    cin>>t;
    while(t--){
        int n; // size of input array
        cin>>n;
        int array[n];
        for(int i=0; i<n; i++){ // taking the input array
            cin>>array[i];
        }
        mergeSort(array, 0, n-1); // calling Merge Sort function
        for(int i=0; i<n; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}