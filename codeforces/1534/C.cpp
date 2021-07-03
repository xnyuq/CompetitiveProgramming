#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
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

void dfs(int u, vector<int> adj[], vector<bool>& vis) {
    if (vis[u]) return;
    vis[u] = true;
    for (auto& i: adj[u]) dfs(i, adj, vis);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int t;
    cin >> t;
    const int mod = 1e9 + 7;
    while (t--) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (auto& i: a) cin >> i;
        for (auto& i: b) cin >> i;
        vector<int> adj[N+1];
        for (int i = 0; i < N; ++i) {
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }
        int cc = 0;
        vector<bool> vis(N+1);
        for (int i = 1; i <= N; ++i) {
            if (vis[i]) continue;
            ++cc;
            dfs(i, adj, vis);
        }
        int64_t ans = 1;
        while (cc--) {
            ans <<= 1;
            ans %= mod;
        }
        cout << ans << "\n";
    }
}

