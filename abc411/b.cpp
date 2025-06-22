// https://atcoder.jp/contests/abc411/tasks/abc411_b
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
        int n;
        cin >> n;
        vector<int> d(n-1);
        rep(i, 0, n-1) cin >> d[i];

        int sum = 0;
        rep(i, 0, n-1) {
            sum = d[i];
            cout<<sum<<"\t";
            rep(j, i+1, n-1) {
                sum += d[j];
                cout<<sum<<"\t";
            }
            cout<<"\n";
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