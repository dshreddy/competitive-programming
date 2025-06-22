// https://codeforces.com/problemset/problem/2120/A
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
    bool isSquare(int l, int b) {
        return l == b;
    }

    bool mergeable(int l1, int b1, int l2, int b2) {
        return (l1 == l2) || (b1 == b2);
    }

    bool mergeable2(int l1, int b1, int l2, int b2) {
        return (l1 == l2) && (b1 == b2);
    }

    vector<pair<int,int>> mergeRectangles(int l1, int b1, int l2, int b2) {
        if(mergeable2(l1, b1, l2, b2)) {
            return {{l1, 2*b1}, {2*l1, b1}}; 
        } else if(mergeable(l1, b1, l2, b2)) {
            if (l1 == l2) {
                return {{l1, b1 + b2}};
            } else if (b1 == b2) {
                return {{l1 + l2, b1}};
            }
        } else {
            return {};
        }
    }

    void solve() {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        vector<pair<int, int>> rectangles = {
            {l1, b1},
            {l2, b2},
            {l3, b3}
        };

        for(int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                int l1 = rectangles[i].first, b1 = rectangles[i].second;
                int l2 = rectangles[j].first, b2 = rectangles[j].second;
                if (mergeable(l1, b1, l2, b2)) {
                    int l3 = rectangles[3 - i - j].first;
                    int b3 = rectangles[3 - i - j].second;
                    if (mergeable2(l1, b1, l2, b2)) {
                        // merge 1st 2 rectangles
                        vector<pair<int, int>> merged = mergeRectangles(l1, b1, l2, b2);
                        for(auto rect: merged) {
                            int l4 = rect.first, b4 = rect.second;
                            if(mergeable(l4, b4, l3, b3)) {
                                if(mergeable2(l4, b4, l3, b3)) {
                                    vector<pair<int, int>> merged_final = mergeRectangles(l4, b4, l3, b3);
                                    for(auto rect2: merged_final) {
                                        if (isSquare(rect2.first, rect2.second)) {
                                            cout << "YES" << endl;
                                            return;
                                        }
                                    }
                                } 
                                else {
                                    pair<int, int> merged_final = mergeRectangles(l4, b4, l3, b3)[0];
                                    if (isSquare(merged_final.first, merged_final.second)) {
                                        cout << "YES" << endl;
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        // merge 1st 2 rectangles
                        pair<int, int> merged = mergeRectangles(l1, b1, l2, b2)[0];
                        int l4 = merged.first, b4 = merged.second;
                        if(mergeable(l4, b4, l3, b3)) {
                            if(mergeable2(l4, b4, l3, b3)) {
                                vector<pair<int, int>> merged_final = mergeRectangles(l4, b4, l3, b3);
                                for(auto rect: merged_final) {
                                    if (isSquare(rect.first, rect.second)) {
                                        cout << "YES" << endl;
                                        return;
                                    }
                                }
                            } 
                            else {
                                pair<int, int> merged_final = mergeRectangles(l4, b4, l3, b3)[0];
                                if (isSquare(merged_final.first, merged_final.second)) {
                                    cout << "YES" << endl;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<< "NO" << endl;
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