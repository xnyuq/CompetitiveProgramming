// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

const int mxN  = 2e5+10;
bool vis[mxN];
vector<int> adj[mxN];
int cnt;

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = true;
    cnt++;
    for (auto& u: adj[i]) {
        dfs(u);
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        cnt = 0;
        dfs(i);
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
