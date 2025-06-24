// https://codeforces.com/contest/2112/problem/B
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
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];  
        int ans = INT_MAX;
        for(int i=1;i<n;i++) {

            int prev = a[i-1], curr = a[i];
            if(abs(prev - curr) <= 1) {
                ans = 0;
                break;
            }

            int prev_set[3], curr_set[3];
            prev_set[0] = prev - 1;
            prev_set[1] = prev;
            prev_set[2] = prev + 1;

            curr_set[0] = curr - 1;
            curr_set[1] = curr;
            curr_set[2] = curr + 1;

            // cout<<"-------------\n";
            // cout<<"prev_set: ";
            // for(int x = 0; x<3; x++) cout<<prev_set[x]<<" ";
            // cout<<endl;
            // cout<<"curr_set: ";
            // for(int x = 0; x<3; x++) cout<<curr_set[x]<<" ";
            // cout<<endl;
            // cout<<"-------------\n";

            // need to make a[i-1] in curr_set
            int opr = 0, min, max;
            for(int j = i-2; j>=0; j--) {
                opr++;
                min = fmin(a[j], a[j+1]);
                max = fmax(a[j], a[j+1]);
                //cout<<"min: "<<min<<" max: "<<max<<endl;
                if(curr_set[0] >= min && curr_set[0] <= max) {
                    ans = fmin(ans, opr);
                    break;
                }
                else if(curr_set[1] >= min && curr_set[1] <= max) {
                    ans = fmin(ans, opr);
                    break;
                }
                else if(curr_set[2] >= min && curr_set[2] <= max) {
                    ans = fmin(ans, opr);
                    break;
                }
            }

            // need to make a[i] in prev_set
            opr = 0;
            for(int j = i+1; j < n; j++) {
                opr++;
                min = fmin(a[j], a[j-1]);
                max = fmax(a[j], a[j-1]);
                //cout<<"min: "<<min<<" max: "<<max<<endl;
                if(prev_set[0] >= min && prev_set[0] <= max) {
                    ans = fmin(ans, opr);
                    break;
                }
                else if(prev_set[1] >= min && prev_set[1] <= max) {
                    ans = fmin(ans, opr);
                    break;
                }
                else if(prev_set[2] >= min && prev_set[2] <= max) {
                    ans = fmin(ans, opr);
                    break;
                }
            }
            // cout<<"ans: "<<ans<<endl;
        }

        if(ans == INT_MAX) cout<<(-1)<<endl;
        else cout<<ans<<endl;
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