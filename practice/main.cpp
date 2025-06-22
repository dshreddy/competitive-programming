// https://codeforces.com/problemset/problem/2120/B
#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

class Solution {
public:
    void solve() {
        int n,s, a,b,c,d, ans = 0;
        cin>>n>>s;
        for(int i=0; i<n; i++) {
            cin>>a>>b>>c>>d;
            if( ( (c == d) && ( a == b) ) || (c+d == s && ( a = -b ) ) ) ans++;
        }
        cout<<ans<<endl;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    int t;
    cin >> t;
    while (t--)
    {
        sol.solve();
    }
    //cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
    return 0;
}