/**
 * @author      : quynx
 * @created     : 10/03/2021 19:57:03 +07
 * @filename    : 27E
 * @source      : https://codeforces.com/contest/27/problem/E
 */

#include <bits/stdc++.h>
#include <climits>
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
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n%i==0) return false;
    return true;
}

const long long MX = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
    //freopen("27E.in", "r", stdin);
    //freopen("27E.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> prime{0};
    vector<vector<long long>> dp(11, vector<long long>(n+1, MX));
    for (int i = 2; (int)prime.size() < 11; ++i)
        if (isPrime(i)) prime.push_back(i);
    for (int i = 0; i <= 10; ++i) dp[i][1] = 1;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 2; j <= n; ++j) {
            long long tmp = 1;
            for (int k = 0; k < j && tmp <= MX/prime[i]; ++k, tmp *= prime[i]) {
                if (j%(k+1) == 0 && dp[i][j] / tmp >= dp[i-1][j/(k+1)])
                    dp[i][j] = dp[i-1][j/(k+1)]*tmp;
            }
        }
    }
    dbg(dp[2][4]);
    cout << dp[10][n] << "\n";
}

