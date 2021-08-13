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
    int N, M; cin >> N >> M;
    const int64_t INF = 100000000000000;
    vector<vector<int64_t>> dis(N+1, vector<int64_t>(N+1, INF));
    for (int i = 1; i <= N; ++i) dis[i][i] = 0;
    for (int i = 0; i < M; ++i) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = w;
    }
    int64_t ans = 0;
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                if (dis[i][j] != INF) ans += dis[i][j];
            }
        }
    }
    cout << ans << "\n";
}
