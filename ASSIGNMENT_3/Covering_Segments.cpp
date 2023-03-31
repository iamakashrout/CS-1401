// QUESTION-3
// COVERING SEGMENTS USING POINTS

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; // number of segments on line
    cout << "Enter the number of segments: " << endl;
    cin >> n;
    vector<vector<int>> segments(n, vector<int>(2));
    for (int i = 0; i < n; i++){
        cout << "Enter starting and ending points of segment " << i + 1 << ": " << endl;
        cin >> segments[i][0] >> segments[i][1];
    }
    sort(segments.begin(), segments.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; }); // sorting segments according to end points
    vector<int> points; // list of points required
    int point = segments[0][1];
    points.push_back(point);
    for (int i = 0; i < n; i++){
        if(point<segments[i][0] || point>segments[i][1]){ // comparing if extra point is required for any segment
            point=segments[i][1];
            points.push_back(point);
        }
    }
    int ans = points.size(); // total number of points
    cout <<"Minimum number of points is: "<< ans << endl;
    cout << "The points are: ";
    for (int i = 0; i < ans; i++){
        cout << points[i] << " ";
    }
    cout << endl;
    return 0;
}