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

const int MX = 1e3+10;
vector<vector<int>> parent(2, vector<int>(MX));
vector<vector<int>> sz(2, vector<int>(MX));

int find_set(int k, int u) {
    if (u == parent[k][u]) return u;
    return parent[k][u] = find_set(k, parent[k][u]);
}

void make_set(int k, int v) {
    parent[k][v] = v;
    sz[k][v] = 1;
}

void union_set(int k, int a, int b) {
    a = find_set(k, a);
    b = find_set(k, b);
    if (a != b) {
        if (sz[k][a] < sz[k][b]) swap(a,b);
        parent[k][b] = a;
        sz[k][a] += sz[k][b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG
    cin.tie(nullptr);
#endif
    int n, m1, m2; cin >> n >> m1 >> m2;
    // make set
    for (int i = 1; i <= n; ++i) {
        make_set(0, i);
        make_set(1, i);
    }
    dbg(find_set(0, 5));
    for (int i = 0; i < m1; ++i) {
        int u, v; cin >> u >> v;
        union_set(0, u, v);
    }
    for (int i = 0; i < m2; ++i) {
        int u, v; cin >> u >> v;
        union_set(1, u, v);
    }
    vector<pair<int,int>> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (find_set(0, i) != find_set(0, j) && find_set(1, i) != find_set(1, j)) {
                ans.push_back({i,j});
                union_set(0, i, j);
                union_set(1, i, j);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto& [i,j]: ans) cout << i << " " << j << "\n";
}

