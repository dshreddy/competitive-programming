// https://codeforces.com/contest/2121/problem/B
#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
void solve() {
    int n;
    cin>>n;
 
    string s;
    cin>>s;
 
    unordered_map<char, int> f1, f2;
 
    for(int i=0; i<n; i++) {
        if(f1[s[i]] == 0) f1[s[i]]++;
        else if(i != n-1) {
            cout<<"Yes\n";
            return;
        }
    }
 
    for(int i=n-1; i>=0; i--) {
        if(f2[s[i]] == 0) f2[s[i]]++;
        else if(i != 0) {
            cout<<"Yes\n";
            return;
        }
    }
 
    cout<<"No\n";
}
 
signed main() {
    int t; cin>>t;
    while(t--) 
    {
        solve();
    }
}