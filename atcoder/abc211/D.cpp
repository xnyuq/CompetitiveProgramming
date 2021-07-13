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

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<int> dis(N+1);
    vector<bool> vis(N+1);
    queue<int> q;
    q.push(1); vis[1] = true;
    vector<int> cnt(N+1);
    cnt[1] = 1;
    const int MOD = 1e9+7;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        dbg(s);
        for (auto& u: adj[s]) {
            if (vis[u]) {
                if (dis[u] == dis[s] + 1) cnt[u] += cnt[s], cnt[u] %= MOD;
            }
            else {
                q.push(u);
                dis[u] = dis[s] + 1;
                cnt[u] = cnt[s];
                vis[u] = true;
            }
        }
    }
    cout << cnt[N] << "\n";
}
