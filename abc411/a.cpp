// https://atcoder.jp/contests/abc411/tasks/abc411_a
#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define debug(x) cout << #x << " = " << x << endl
#define debugp(p) cout << #p << " = " << p.first << " " << p.second << endl
#define debugv(v) cout << #v << " = "; for (auto &x : v) cout << x << " "; cout << endl;
#define debugm(m) cout << #m << " = "; for (auto &x : m) { cout << x.first << " " << x.second << " "; } cout << endl;
#define debugv2d(v) cout << #v << " = \n"; for (auto &x : v) { for (auto &y : x) cout << y << " "; cout << endl; }
using namespace std;

class Solution {
public:
    void solve() {
        string p;
        int l; 
        cin>>p>>l;
        if(p.size() >= l) cout<<"Yes\n";
        else cout<<"No\n";
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    // int t;
    // cin >> t;
    // while (t--)
    {
        sol.solve();
    }
    //cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
    return 0;
}