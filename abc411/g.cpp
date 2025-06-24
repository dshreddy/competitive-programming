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
    // Function to check if a node is 
    // visited in the current path
    bool visited(int node, const vector<int> &path) {
        return find(path.begin(), path.end(), node) != path.end();
    }

    // Function to rotate a cycle such that 
    // it starts with the smallest node
    vector<int> rotateToSmallest(vector<int> path) {
        auto minIt = min_element(path.begin(), path.end());
        rotate(path.begin(), minIt, path.end());
        return path;
    }

    // Function to invert the cycle order
    vector<int> invert(vector<int> path) {
        reverse(path.begin(), path.end());
        return rotateToSmallest(path);
    }

    // Function to check if a cycle is new
    bool isNew(const vector<int> &path, 
                vector<vector<int>> &cycles) {
        return find(cycles.begin(), 
                cycles.end(), path) == cycles.end();
    }

    // Function to find new cycles in the graph
    void findNewCycles(vector<int> path, 
        vector<vector<int>> &graph, vector<vector<int>> &cycles) {
        int startNode = path[0];
        int nextNode;
        vector<int> sub;

        // Visit each edge and node of each edge
        for (auto &edge : graph) {
            int node1 = edge[0], node2 = edge[1];

            if (startNode == node1 || startNode == node2) {
                nextNode = (node1 == startNode) ? node2 : node1;

                if (!visited(nextNode, path)) {
                    // Neighbor node not on path yet
                    sub = {nextNode};
                    sub.insert(sub.end(), path.begin(), path.end());
                    // Explore extended path
                    findNewCycles(sub, graph, cycles);
                } 
                else if (path.size() > 2 && nextNode == path.back()) {
                    // Cycle found
                    vector<int> p = rotateToSmallest(path);
                    vector<int> inv = invert(p);

                    if (isNew(p, cycles) && isNew(inv, cycles)) {
                        cycles.push_back(p);
                    }
                }
            }
        }
    }

    // Main function to initiate cycle detection
    vector<vector<int>> findCycles(vector<vector<int>> &graph) {

        vector<vector<int>> cycles;

        for (auto &edge : graph) {
            for (int node : edge) {
                findNewCycles({node}, graph, cycles);
            }
        }

        return cycles;
    }

    void solve() {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges;
        map<pair<int,int>, int> edgeCount;
        int u, v;

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            edgeCount[{u, v}]++;
            if(edgeCount[{u, v}] > 1) continue; // Skip if edge already exists in graph
            edges.push_back({u, v});
        }

        vector<vector<int>> cycles = findCycles(edges);


        int ans = 0, mod = 998244353, multiplicity;

        for(auto cycle : cycles) {

            multiplicity = 1;

            // for(int i = 0; i < cycle.size(); i++) cout << cycle[i] << " ";
            // cout << endl;

            for(int i = 0; i < cycle.size(); i++) {

                int curr = cycle[i], next, temp;

                if(i == cycle.size() - 1) next = cycle[0]; // Wrap around to the first node
                else next = cycle[i+1];

                temp = curr;
                curr = min(curr, next);
                next = max(temp, next);

                multiplicity *= fmax(edgeCount[{curr, next}], 1);
                multiplicity %= mod;
            }

            //cout<<"Multiplicity: "<<multiplicity<<endl;

            ans += multiplicity;
            ans %= mod;
        }

        // cycles of length 2
        for(auto p : edgeCount) {
            if(p.second > 1) {
                ans += p.second * (p.second - 1) / 2;
                ans %= mod;
            }
        }

        cout << ans << endl;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    {
        sol.solve();
    }
    //cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
    return 0;
}