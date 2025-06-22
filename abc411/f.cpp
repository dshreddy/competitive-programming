// https://atcoder.jp/contests/abc411/tasks/abc411_f
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
    unordered_map<int,int> parent;
    unordered_map<int, int> rank;

    int find(int p) {
        if(parent[p] != p) parent[p] = find(parent[p]); // Path compression
        return parent[p];
    }

    void solve() {
        int n, m, u, v, pu, pv, total_edges = 0; 
        cin>>n>>m;

        rep(i, 0, n) {
            parent[i+1] = i+1; // Initialize parent for each node
            rank[i+1] = 0; // Initialize rank for each node
        }

        unordered_map<int, pair<int,int>> edges;
        unordered_map<int, unordered_set<int>> adj;
        for(int i=0; i<n; i++) adj[i+1] = {};

        rep(i, 0, m) {
            cin>>u>>v;
            edges[i+1] = {u,v};
            adj[u].insert(v);
            adj[v].insert(u);
            total_edges++;
        }

        int q, edge_index; cin>>q;
        while(q--) {
            cin>>edge_index;
            u = edges[edge_index].first;
            v = edges[edge_index].second;
            pu = find(u);
            pv = find(v);
            if(pu != pv) {
                total_edges--; // the edge between set(u) & set(v) gets removed
                if(rank[pu] >= rank[pv]) {
                    for(auto n: adj[pv]) {
                        if(pu == n) continue;
                        if(adj[pu].find(n) != adj[pu].end()) {
                            // n is connected to both set(u) and set(v)
                            // one edge will be removed
                            total_edges--;
                        }
                        else {
                            // Transferring all edges to set(u) & Deleting node pv from graph [Theoretically]
                            adj[pu].insert(n);
                            adj[n].insert(pu);
                        }
                        adj[n].erase(pv);
                    }
                    adj.erase(pv);
                    parent[pv] = pu;
                    if(rank[pu] == rank[pv]) rank[pu]++;
                }
                else {
                    for(auto n: adj[pu]) {
                        if(pv == n) continue;
                        if(adj[pv].find(n) != adj[pv].end()) {
                            // n is connected to both set(u) and set(v)
                            // one edge will be removed
                            total_edges--;
                        }
                        else {
                            // Transferring all edges to set(u) & Deleting node pv from graph [Theoretically]
                            adj[pv].insert(n);
                            adj[n].insert(pv);
                        }
                        adj[n].erase(pu);
                    }
                    adj.erase(pu);
                    parent[pu] = pv;
                }
            }
            cout<<total_edges<<endl;
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