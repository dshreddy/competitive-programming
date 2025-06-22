// https://codeforces.com/contest/2121/problem/D
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define debug(x) cout << #x << " = " << (x) << endl
#define debugv(v) cout << #v << " = "; for (auto &x : v) cout << x << ' '; cout << endl
#define debug2d(v) cout << #v << " = "; for (auto &x : v) { for (auto &y : x) cout << y << ' '; cout << endl; }
using namespace std;

class Solution {
public:
    void solve() {
        string l,r;
        cin>>l>>r;
        int n = sz(l), i = 0, ans = 0;

        // x starts with the longest common prefix of l and r
        while(i < n && l[i] == r[i]) {
            ans += 2;
            i++;
        }

        // Now we reached the first differing digit
        /*
            **
            Let's call the first position at which l & r differ be fd
            **

            if (the difference between the 1st differeing digits is >= 2)
            {
                The next digit in x will be some digit in between them 
                Example: l = 123456, r = 125056, then x can be 124___
                Note: l[fd] must be < r[fd] since l<r and it is established that
                for all positions before fd l[fd]==r[fd]

                Now since x is of the form 124___, x will always be in between l and r
                and we can fill the rest of the digits with any digits we want.
                
                We will fill position i in x with digit x[i] such that x[i] != l[i] && x[i] != l[i]
            }
            else
            {
                Now the difference is exactly 1 (can't be 0 since this is the dirst differing digit)
                Example: l = 1239990 and r = 1240037
                We have to choose l[fd] or r[fd] as the next digit in x.

                If we choose l[fd] as x[fd] then it ensures x < r. 
                We just need to ensure that x > l and minimize the number of common digits.
                To do this, we choose x[fd+1] = l[fd+1]+1 and this should be enough to satisft above condition
                An exception is when l[fd+1] is 9, then we have no other choice and should keep x[fd+1] = 9
                This goes on till we find a non 9 digit 'a' in l and keep 'a+1' as next digit in x
                So in this case for above example x = 1239991

                If we choose r[fd] as x[fd] then it ensures x > l. 
                We just need to ensure that x < r and minimize the number of common digits.
                To do this, we choose x[fd+1] = r[fd+1]-1 and this should be enough to satisft above condition
                An exception is when r[fd+1] is 0, then we have no other choice and should keep x[fd+1] = 0
                This goes on till we find a non 0 digit 'a' in r and keep 'a-1' as next digit in x
                So in this case for above example x = 124002_
            } 
        */
       if(i<n) {
        int diff = abs((l[i]-'0')-(r[i]-'0'));
        if(diff == 1){
            ans += 1; // since we are choosing one of l[fd], r[fd] as x[fd]
            i++;
            int choice1 = 0, choice2 = 0, p = i, q = i;
            while(p<n && l[p]=='9') {
                choice1 += 1;
                p++;
            } 
            while(q<n && r[q]=='0') {
                choice2 += 1;
                q++;
            }
            ans += fmin(choice1, choice2);
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
    return 0;
}