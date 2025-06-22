// https://codeforces.com/contest/2121/problem/D
#include <bits/stdc++.h>
#define int long long int
using namespace std;


// Problem D
void solve() {
    int n,t; 
    cin>>n;

    int a[n];
    int b[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    int num_operations = 0;
    vector<pair<int,int>> operations;

    for(int i=1; i<n; i++) {
        t = i;
        while(t >= 1 && a[t] < a[t-1]) {
            num_operations++;
            operations.push_back({1, t-1});
            swap(a[t], a[t-1]);
            t--;
        }
    }

    for(int i=1; i<n; i++) {
        t = i;
        while(t >= 1 && b[t] < b[t-1]) {
            num_operations++;
            operations.push_back({2, t-1});
            swap(b[t], b[t-1]);
            t--;
        }
    }

    // Explanation : https://codeforces.com/blog/entry/143822?#comment-1284995
    for(int i=0; i<n; i++) {
        if(a[i] > b[i]) {
            num_operations++;
            operations.push_back({3, i});
            swap(a[i], b[i]);
        }
    }

    // for(int i=0; i<n; i++) cout<<a[i]<<"\t";
    // cout<<"\n";
    // for(int i=0; i<n; i++) cout<<b[i]<<"\t";
    // cout<<"\n";

    cout<<num_operations<<endl;
    for(auto p: operations) cout<<p.first<<"\t"<<p.second+1<<endl;
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