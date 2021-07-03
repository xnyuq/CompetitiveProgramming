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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(2));
        if (s[0] == '?') dp[0][0] = dp[0][1] = 1;
        else dp[0][s[0] - '0'] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '?') dp[i][0] = dp[i-1][1] + 1, dp[i][1] = dp[i-1][0] + 1;
            else dp[i][s[i] - '0'] = dp[i-1]['1'-s[i]] + 1;
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') ans += max(dp[i][0], dp[i][1]);
            else ans += dp[i][0] + dp[i][1];
        }
        cout << ans << "\n";
    }
}

