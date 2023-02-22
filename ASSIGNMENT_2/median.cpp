// FINDING MEDIAN OF TWO SORTED ARRAYS IN O(log(m+n))

#include<bits/stdc++.h>
using namespace std;

double median(vector<int>& array1, vector<int>& array2){
    int n1=array1.size(); // defining sizes of bith arrays
    int n2=array2.size();
    if(n1<n2){
        return median(array2, array1); // if first array is smaller than the 2nd array
    }
    int low=0, high=2*n2;
    while(low<=high){
        int mid2=(low+high)/2; // index where 2nd array is divided into left and right halves of combined sorted array
        int mid1=n1+n2-mid2; // index of partition for 1st array

        double l1, l2, r1, r2; // last elements in left half and first elements in right half for both arrays

        if(mid1==0){ // updating largest element of 1st array in left half of sorted array
            l1=INT_MIN;
        }
        else{
            l1=array1[(mid1-1)/2];
        }

        if(mid2==0){ // updating largest element of 2nd array in left half of sorted array
            l2=INT_MIN;
        }
        else{
            l2=array2[(mid2-1)/2];
        }

        if(mid1==2*n1){ // updating smallest element of 1st array in right half of sorted array
            r1=INT_MAX;
        }
        else{
            r1=array1[mid1/2];
        }

        if(mid2==2*n2){ // updating smallest element of 2nd array in right half of sorted array
            r2=INT_MAX;
        }
        else{
            r2=array2[mid2/2];
        }

        if(l1>r2){ // if largest element of array1 on left is greater than smallest element of array2 on right
            low=mid2+1;
        }
        else if(l2>r1){ // if largest element of array2 on left is greater than smallest element of array1 on right
            high=mid2-1;
        }
        else{ // if all conditions are satisfied calculate median
            return (max(l1, l2)+min(r1, r2))/2;
        }
    }
    return -1;
}

int main(){
    int t; // number of test cases
    cin>>t;
    while(t--){
        int n1; // size of 1st array
        cin>>n1;
        vector<int> array1(n1);
        for(int i=0; i<n1; i++){ // 1st array input
            cin>>array1[i];
        }
        int n2; // size of 2nd array
        cin>>n2;
        vector<int> array2(n2);
        for(int i=0; i<n2; i++){ // 2nd array input
            cin>>array2[i];
        }
        double ans=median(array1, array2); // function to find median
        cout<<ans<<endl;
    }
    return 0;
}