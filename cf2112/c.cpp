// https://codeforces.com/contest/2112/problem/C
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
        int n, max = INT_MIN;
        cin>>n;

        vector<int> a(n, 0);
        rep(i, 0, n){
            cin>>a[i];
            max = std::max(max, a[i]);
        } 
        // For Alice to win
        // He needs to select triplet (x,y,z) such that 
        // 1. Sum of any 2 elements in triplet must be strictly greater than 3rd 
        // 2. Sum of triplet must be greater than the largest element in array
        // (1) ensures that Alice will win even if Bob paints one of the red element
        // (2) ensure that Alice will win if Bob paints a max

        /*  
        Algo:
            1. First get all triplets with sum > max
            2. Then check if triplet is a valid triangle or not 
        */
       sort(all(a));
       int min_x, ans = 0, min_x_index;
        for(int y = 0; y < n; y++) {
            for (int z = y+1; z < n; z++) {
                min_x = fmax(a[n-1], 2*a[z]) - a[y] - a[z];
                min_x_index = upper_bound(a.begin(), a.begin()+y, min_x) - a.begin(); // upper_bound returns the it to 1st element greater than min_x in the array
                ans += y - min_x_index;
            }
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