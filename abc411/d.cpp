// https://atcoder.jp/contests/abc411/tasks/abc411_d
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
        int n, q;
        cin>>n>>q;
        cin.ignore(); // Ignore the newline character after reading n and q

        vector<string> s(q, "");
        vector<int> query_type(q), pc_index(q);
        for(int i = 0; i < q; i++) {
            cin >> query_type[i] >> pc_index[i];
            cin.ignore(); // Ignore the space after reading query_type and pc_index
            if(query_type[i] == 2) cin >> s[i];
        }

        // ************ reverse scan
        /*
            We will initialize a server index to 0 (server is not modified) & ans as an empty string.
            We will scan the queries in reverse.
            1. The first query of type 3 from last is the last query which sets the server. 
               So at the final server string will be whatever present previosuly in this PC. 
               So now our server is PC p.
            2. Now server is at PC p
               If we encounter a query of type 2, then server still be at PC p but s will be added to the string in server.
               If we encounter a query of type 1, then the value at PC p will be whatever present previosuly in this PC 0. String will not be modified in this case. 
        */
        int server = 0; // server index
        string ans = "";
        rrep(i, q, 1) {
            int type = query_type[i-1];
            int p = pc_index[i-1];
            if(type == 1 && server == p)  server = 0;
            else if(type == 2 && server == p) {
                reverse(all(s[i-1]));
                ans += s[i-1];
            } else if(type == 3 && server == 0) server = p;
        }
        reverse(all(ans));
        cout<<ans<<endl;
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