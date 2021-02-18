/**
 * @author      : quynx
 * @created     : 18/02/2021 19:21:31 +07
 * @filename    : 755C
 * @source      : https://codeforces.com/contest/755/problem/C
 */

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

const int MX = 1e5+1;
int cnt = 0;
vector<int> adj[MX];
bool vis[MX];

void dfs(int node) {
    if (vis[node]) return;
    vis[node] = true;
    for (auto& u: adj[node])
        if (!vis[u])
            dfs(u);
}
int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG
    cin.tie(nullptr);
    //freopen("755C.in", "r", stdin);
    //freopen("755C.out", "w", stdout);
#endif
    int n;
    cin >> n;
    unordered_map<int,bool> mp;
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        adj[i].emplace_back(tmp);
        adj[tmp].emplace_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        ++cnt;
        dfs(i);
    }
    cout << cnt << "\n";
}

