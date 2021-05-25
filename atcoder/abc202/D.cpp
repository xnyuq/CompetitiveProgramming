/**
 * @author      : xnyuq
 * @created     : 24/05/2021 19:56:30 +07
 * @filename    : abc202d
 */

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

const int MX = 35;
vector<vector<int64_t>> dp(MX+1, vector<int64_t>(MX+1));

string findKth(int A, int B, int64_t K) {
    if (A == 0) return string(B, 'b');
    if (B == 0) return string(A, 'a');
    if (K <= dp[A-1][B]) return "a" + findKth(A-1, B, K);
    else return "b" + findKth(A, B - 1, K - dp[A-1][B]);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int A, B;
    int64_t K;
    cin >> A >> B >> K;
    dp[0][0] = 1;
    for (int i = 0; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            if (i) dp[i][j] += dp[i-1][j];
            if (j) dp[i][j] += dp[i][j-1];
        }
    }
    cout << findKth(A,B,K) << "\n";
}

