// QUESTION-2
// CAR FUELING PROBLEM

#include<bits/stdc++.h>
using namespace std;

int main(){
    int d; // distance of the final destination
    cout << "Enter distance of destination: " << endl;
    cin >> d;
    int m; // distance covered by full tank
    cout << "Enter distance range of full tank: " << endl;
    cin >> m;
    int n; // number of gas stations in between
    cout<<"Enter number of gas stations: "<<endl;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++){
        cout << "Enter distance of gas station " << i + 1 <<": "<< endl;
        cin >> stations[i];
    }
    for (int i = 1; i < n; i++){
        if(stations[i]-stations[i-1]>m){ // if distance between consecutive gas stations is greater than maximum range
            cout << "Not Possible!" << endl;
            return 0;
        }
    }
    if(d-stations[n-1]>m){
        cout << "Not Possible!" << endl;
        return 0;
    }
    int stops = 0; // number of stops
    int prev = 0; // previous stop where car was refuelled
    int i = 0;
    while(prev+m<d){
        while(prev+m>=stations[i] && i<n){ // go to the farthest possible gas station
            i++;
        }
        prev = stations[i-1];
        stops++;
    }
    cout << "Minimum number of stops is " << stops << endl;
    return 0;
}