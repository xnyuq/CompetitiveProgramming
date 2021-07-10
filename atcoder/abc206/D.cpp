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
vector<int> adj[MX];
vector<bool> vis(MX);
int ans = 0;

void dfs(int n) {
    if (vis[n]) return;
    ++ans; vis[n] = true;
    for (auto& i: adj[n]) dfs(i);
}
int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    vector<bool> ex(MX);
    for (int i = 0; i < n/2; ++i) {
        if (arr[i] != arr[n - i - 1]) {
            ex[arr[i]] = ex[arr[n-i-1]] = true;
            adj[arr[i]].push_back(arr[n-i-1]);
            adj[arr[n-i-1]].push_back(arr[i]);
        }
    }
    for (int i = 1; i < MX; ++i) {
        if (!ex[i] || vis[i]) continue;
        dfs(i);
        --ans;
    }
    cout << ans << "\n";
}

