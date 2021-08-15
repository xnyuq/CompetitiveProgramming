#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef QUYNX_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> p(n);
        for (auto& i: p) {
            cin >> i;
            --i;
        }
        vector<int> cnt(n), ans;
        for (int i = 0; i < n; ++i) {
            ++cnt[(i-p[i]+n) % n];
        }
        for (int k = 0; k < n; ++k) {
            if (cnt[k] >= n - 2 * m) {
                vector<vector<int>> adj(n);
                for (int i = 0; i < n; ++i) {
                    int cur = (i - k + n) % n;
                    adj[cur].push_back(p[i]);
                    adj[p[i]].push_back(cur);
                }
                int cc = 0; // connected component
                vector<bool> vis(n);
                for (int i = 0; i < n; ++i) {
                    if (vis[i]) continue;
                    ++cc;
                    int j = i;
                    while (!vis[j]) {
                        vis[j] = true;
                        j = p[(j+k)%n];
                    }
                }
                if (n - cc <= m) {
                    ans.push_back(k);
                }
                if (k == 1) dbg(cc);
            } 
        }
        cout << ans.size();
        for (auto& i: ans) cout << " " << i;
        cout << "\n";
    }
}

