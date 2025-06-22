// https://codeforces.com/contest/2121/problem/C
#include <bits/stdc++.h>
#define int long long int
using namespace std;

// Problem C
void solve() {
    int n, m, max = INT_MIN, frequecy_of_max = 0;
    cin>>n>>m;

    int a[n][m];
    memset(a, 0, sizeof(a));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>a[i][j];
            if(a[i][j] > max) {
                max = a[i][j];
                frequecy_of_max = 1;
            } 
            else if(a[i][j] == max) frequecy_of_max++;
        }
    }

    int r[n], c[m];
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(max == a[i][j]) { r[i]++; c[j]++; }
    // r[i] contains the number of times max appears in this row
    // c[j] contains the number of times max appears in this column

    // consider all possible choices for row, col
    int num_affected;
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++)
        {
            // If we are choosing row as i and col as j for the decrement operation
            // then the number of elements with value as max gets decremented is 
            // r[i]+c[j]
            // if a[i][j] == max then we are double counting
            // so it's r[i]+c[j]-1
            if(a[i][j] == max) num_affected = r[i] + c[j] - 1;
            else num_affected = r[i] + c[j];
            if(num_affected == frequecy_of_max) {
                // In this case all occurances of max in the matrix gets decremented by 1
                // so, now the maximum element in the matrix is max-1
                cout<<max-1<<endl;
                return;
            }
        }
    }

    // This is the case where no matter what r,c we choose
    // there exists atleast one occurance of max which will remain the same
    // so max is still the maximum element in the matrix
    cout<<max<<endl;
    return;
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--) 
    {
        solve();
    }
}