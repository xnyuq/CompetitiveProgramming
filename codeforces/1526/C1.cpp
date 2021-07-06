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
    int n;
    cin >> n;
    vector<int> arr(n);
    const int64_t INF = 1e9+50;
    for (auto& i: arr) cin >> i;
    vector<vector<int64_t>> dp(n, vector<int64_t>(n+1, -INF));
    for (int i = 0; i < n; ++i) dp[i][0] = 0;
    if (arr[0] >= 0) dp[0][1] = arr[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i+1; ++j) {
            if (dp[i-1][j-1] + arr[i] >= 0 ) dp[i][j] = max(dp[i-1][j-1] + arr[i], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[n-1][i] != -INF) ans = max(ans, i);
    }
    dbg(dp);
    cout << ans << "\n";
}

