// STRASSEN'S MATRIX MULTIPLICATION

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B, int split, int sign){
    for(int i=0; i<split; i++){
        for(int j=0; j<split; j++){
            A[i][j]=A[i][j]+sign*B[i][j];
        }
    }
    return A;
}

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B){
    int n=A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if(n==1){
        C[0][0]=A[0][0]*B[0][0]; // base case for 1*1 size matrix
    }
    else{
        int split=n/2; // diving into 8 smaller equal sized matrices

        vector<vector<int>> a(split, vector<int>(split, 0));
        vector<vector<int>> b(split, vector<int>(split, 0));
        vector<vector<int>> c(split, vector<int>(split, 0));
        vector<vector<int>> d(split, vector<int>(split, 0));
        vector<vector<int>> e(split, vector<int>(split, 0));
        vector<vector<int>> f(split, vector<int>(split, 0));
        vector<vector<int>> g(split, vector<int>(split, 0));
        vector<vector<int>> h(split, vector<int>(split, 0));

        for(int i=0; i<split; i++){ // putting values in all 8 submatrices
            for(int j=0; j<split; j++){
                a[i][j]=A[i][j];
                b[i][j]=A[i][j+split];
                c[i][j]=A[i+split][j];
                d[i][j]=A[i+split][j+split];
                e[i][j]=B[i][j];
                f[i][j]=B[i][j+split];
                g[i][j]=B[i+split][j];
                h[i][j]=B[i+split][j+split];
            }
        }

        // expressions for P1, P2, P3, P4, P5, P6, P7
        // P1=a*(f-h)
        // P2=(a+b)*h
        // P3=(c+d)*e
        // P4=d*(g-e)
        // P5=(a+d)*(e+h)
        // P6=(b-d)*(g+h)
        // P7=(a-c)*(e+f)
        vector<vector<int>> P1(multiply(a, add(f, h, split, -1)));
        vector<vector<int>> P2(multiply(add(a, b, split, 1), h));
        vector<vector<int>> P3(multiply(add(c, d, split, 1), e));
        vector<vector<int>> P4(multiply(d, add(g, e, split, -1)));
        vector<vector<int>> P5(multiply(add(a, d, split, 1), add(e, h, split, 1)));
        vector<vector<int>> P6(multiply(add(b, d, split, -1), add(g, h, split, 1)));
        vector<vector<int>> P7(multiply(add(a, c, split, -1), add(e, f, split, 1)));

        // expressions for submatrices of answer
        // r=P4+P5+P6-P2
        // s=P1+P2
        // t=P3+P4
        // u=P1-P3+P5-P7
        vector<vector<int>> r(add(add(add(P4, P5, split, 1), P6, split, 1), P2, split, -1));
        vector<vector<int>> s(add(P1, P2, split, 1));
        vector<vector<int>> t(add(P3, P4, split, 1));
        vector<vector<int>> u(add(add(add(P1, P3, split, -1), P5, split, 1), P7, split, -1));

        for(int i=0; i<split; i++){ // putiing values in answer matrix
            for(int j=0; j<split; j++){
                C[i][j]=r[i][j];
                C[i][j+split]=s[i][j];
                C[i+split][j]=t[i][j];
                C[i+split][j+split]=u[i][j];
            }
        }

        // removing all temporary matrices
        a.clear();
        b.clear();
        c.clear();
        d.clear();
        e.clear();
        f.clear();
        g.clear();
        h.clear();
        P1.clear();
        P2.clear();
        P3.clear();
        P4.clear();
        P5.clear();
        P6.clear();
        P7.clear();
        r.clear();
        s.clear();
        t.clear();
        u.clear();
    }
    return C;
}

int main(){
    int t; // number of test cases
    cin>>t;
    while(t--){
        int n; // size of matrices
        cin>>n;
        vector<vector<int>> A(n, vector<int>(n));
        for(int i=0; i<n; i++){ // taking input of 1st matrix
            for(int j=0; j<n; j++){
                cin>>A[i][j];
            }
        }
        vector<vector<int>> B(n, vector<int>(n));
        for(int i=0; i<n; i++){ // taking input of 2nd matrix
            for(int j=0; j<n; j++){
                cin>>B[i][j];
            }
        }
        vector<vector<int>> C=multiply(A, B); // calling multiply function
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<C[i][j]<<" "; // printing product matrix
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}