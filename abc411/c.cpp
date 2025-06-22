// https://atcoder.jp/contests/abc411/tasks/abc411_c
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
        int n, q, index, interval_count = 0;
        cin>>n>>q;
        vector<int> a(n, 0);
        rep(i, 0, q) {
            cin>>index;
            index--;
            if(a[index] == 0) {
                if(index == 0 && (n==1 || (n>1 && a[1] == 0))) interval_count++;
                else if(index == n-1 && n-2 >= 0 && a[n-2] == 0) interval_count++;
                else if(a[index-1] == 0 && a[index+1] == 0) interval_count++;
                else if(a[index-1] == 1 && a[index+1] == 1) interval_count--;
            } else {
                if(index == 0 && (n==1 || (n>1 && a[1] == 0))) interval_count--;
                else if(index == n-1 && n-2 >= 0 && a[n-2] == 0) interval_count--;
                else if(a[index-1] == 0 && a[index+1] == 0) interval_count--;
                else if(a[index-1] == 1 && a[index+1] == 1) interval_count++;
            }
            a[index] = !a[index];
            cout<<interval_count<<endl;
        }
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