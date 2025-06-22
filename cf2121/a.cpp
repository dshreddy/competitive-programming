// https://codeforces.com/contest/2121/problem/A
#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
void solve() {
    int n,s;
    cin>>n>>s;
    vector<int>x(n, 0);
    for(int i=0; i<n; i++) cin>>x[i];
    int l = x[n-1]-x[0];
    cout<<l+fmin(abs(s-x[n-1]), abs(s-x[0]))<<endl;
}
 
signed main() {
    int t; cin>>t;
    while(t--) 
    {
        solve();
    }
}