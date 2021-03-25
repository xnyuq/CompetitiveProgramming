/**
 * @author      : quynx
 * @created     : 25/03/2021 21:35:53 +07
 * @filename    : A
 * @source      : 
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

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
    //freopen("A.in", "r", stdin);
    //freopen("A.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int64_t n, m, k;
        cin >> n >> m >> k;
        int64_t r = k%n, c = (k+n-1)/n;
        if (r == 0) r = n;
        int64_t ans = (r-1)*m+c;
        cout << ans << "\n";
    }
}

