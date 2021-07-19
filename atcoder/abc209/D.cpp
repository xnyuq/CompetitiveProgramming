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

const int MX = 1e5+10;
vector<int> adj[MX];
int color[MX];

void dfs(int colorCode, int node) {
    if (color[node]) return;
    color[node] = colorCode;
    for (auto& i: adj[node])
        dfs(3-colorCode, i);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >>  a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    while (Q--) {
        int a, b;
        cin >> a >> b;
        dbg(a,b);
        if (color[a] == color[b]) cout << "Town\n";
        else cout << "Road\n";
    }
    dbg(color[7], color[9]);
}

