// https://codeforces.com/contest/2112/problem/D
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

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degree;

        rep(i, 0, n-1) { 
            int u,v;
            cin>>u>>v;  
            adj[u].push_back(v); 
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        int root = -1;
        for(auto p: degree) if(p.second == 2) {root = p.first; break;}

        if(root == -1) cout<<"NO\n";
        else {
            cout<<"YES\n";
    
            queue<int> q;
            int level = 1;
            bool flipped = false;
            vector visited(n+1, false);
            vector<int> direction(n+1, 0);

            q.push(root);
            visited[root] = true;
            direction[root] = 1;

            while(!q.empty()) {

                level++;
                int l = q.size();

                for(int i=0; i<l; i++) {

                    int u = q.front();
                    q.pop();

                    for(int v: adj[u]) {
                        if(!visited[v]) {
                            if(level == 2 && degree[v] == 1 && !flipped) {
                                if(direction[u] == 1) {
                                    // if d[u] is 1 then (u,v) should be down i.e u->v
                                    // but we're flipping in this case, so v->u
                                    cout<<v<<"\t"<<u<<endl;
                                    direction[v] = +1;
                                }
                                else {
                                    cout<<u<<"\t"<<v<<endl;
                                    direction[v] = -1;
                                }
                            }
                            else if(direction[u] == 1) {
                                cout<<u<<"\t"<<v<<endl;
                                direction[v] = -1;
                            }
                            else {
                                cout<<v<<"\t"<<u<<endl;
                                direction[v] = +1;
                            }
                            q.push(v);
                            visited[v] = true;
                        }
                    }
                }
            }
        }

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