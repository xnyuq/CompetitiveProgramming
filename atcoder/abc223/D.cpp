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

vector<int> child;
vector<vector<int>> adj;
vector<bool> vis;
unordered_map<int, bool> inStack;
bool containCycle = false;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    inStack[u] = true;
    if (containCycle) return;
    for (auto& v: adj[u]) {
        if (!vis[v]) {
            dfs(v);
            inStack[v] = false;
        }
        else if (inStack[v]) {
            containCycle = true;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int N, M; cin >> N >> M;
    adj.resize(N+1);
    child.resize(N+1);
    vis.resize(N+1);
    unordered_map<int, unordered_map<int, bool>> mp;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        if (!mp[a][b]) {
            mp[a][b] = true;
            adj[a].push_back(b);
            ++child[b];
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (vis[i]) continue;
        
        inStack.clear();
        dfs(i);
        if (containCycle) {
            break;
        }
    }
    if (containCycle) {
        cout << "-1\n";
    }
    else {
        vector<int> ans;
        set<int> s;
        for (int i = 1; i <= N; ++i) {
            if (child[i] == 0) s.insert(i);
        }
        while (!s.empty()) {
            int u = *s.begin(); s.erase(s.begin());
            ans.push_back(u);
            for (auto& v: adj[u]) {
                --child[v];
                if (child[v] == 0) s.insert(v);
            }
        }
        for (int &a: ans) cout << a << " ";
        cout << "\n";
    }
}

