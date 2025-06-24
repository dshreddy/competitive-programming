// https://codeforces.com/problemset/problem/2120/C
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
        int n, m;
        cin >> n >> m;
        int min = n, max = (n*(n+1))/2;
        if (m < min || m > max) {
            cout << "-1\n";
            return; 
        }
        /*
            The graph can be always a line
            1 - n - (n-1) - (n-2) - ... - 2 (divinity n)
            n - 1 - (n-2) - ... - 2 - 1 (divinity n+(n-1))
            n - (n-1) - 1 - (n-2) - ... - 2 (divinity n+(n-1)+(n-2))
            .
            .
            .
            n - (n-1) - (n-2) - ... 3 - 1 - 2 (divinity n+(n-1)+(n-2)+ ... 3+2)
            n - (n-1) - (n-2) - ... 3 - 2 - 1 (divinity n+(n-1)+(n-2)+ ... +2+1)
        */
        vector<int> left, right;
        m -= n;

        // iterating over the terms that needs to be added to n to sum upto m
        for(int i = n-1; i >= 1; i--) {
            if (m >= i) {
                m -= i;
                left.pb(i+1); // To add i to sum, we need to move i+1 to left as seen above
            } else {
                right.pb(i+1);
            }
        }

        vector<int> line;
        for (auto x : left) line.pb(x);
        line.pb(1);
        for (auto x : right) line.pb(x);

        cout<<line[0]<<endl;
        for (int i = 1; i < n; i++) cout << line[i-1] << "\t" << line[i] << endl; 
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
