/**
 * @author      : quynx
 * @created     : 08/03/2021 19:20:33 +07
 * @filename    : 1494B
 * @source      : https://codeforces.com/problemset/problem/1494/B
 */

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
int n, grid[4], lower[4];
bool flag;
void Try(int k) {
    if (k == 4) {
        bool ok = true;
        for (int i = 0; i < 4; ++i)
            if (grid[i] < lower[i]) ok = false;
        flag |= ok;
        return;
    }
    if (grid[k] == n) {
        ++lower[(k+1)%4];
        ++lower[(k+3)%4];
        Try(k+1);
        --lower[(k+1)%4];
        --lower[(k+3)%4];
    }
    else if (grid[k] == n - 1) {
        ++lower[(k+1)%4];
        Try(k+1);
        --lower[(k+1)%4];
        ++lower[(k+3)%4];
        Try(k+1);
        --lower[(k+3)%4];
    }
    else Try(k+1);
}
int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
    //freopen("1494B.in", "r", stdin);
    //freopen("1494B.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        flag = false;
        cin >> n;
        memset(lower, 0, sizeof lower);
        for (auto& i: grid) cin >> i;
        Try(0);
        cout << (flag?"YES\n":"NO\n");
    }
}

