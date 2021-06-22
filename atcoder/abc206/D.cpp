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

const int MX = 2e5 + 10;
vector<int> comp;
bool vis[MX];
set<int> adj[MX];

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = true;
    comp.push_back(s);
    for (auto& u: adj[s]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int N;
    cin >> N;
    vector<int> arr(N);
    set<int> vertices;
    for (auto& i: arr) cin >> i;
    for (auto& i: arr) vertices.insert(i);
    map<int,bool> mp;
    for (int i = 0; i < N / 2; ++i) {
        if (arr[i] != arr[N-i-1]) adj[arr[i]].insert(arr[N-i-1]), adj[arr[N-i-1]].insert(arr[i]);
    }
    int ans = 0;
    for (auto& u: vertices) {
        if (vis[u]) continue;
        dfs(u);
        ans += (int)comp.size() - 1;
        comp.clear();
    }
    cout << ans << "\n";
}

