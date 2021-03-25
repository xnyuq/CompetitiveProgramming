/**
 * @author      : quynx
 * @created     : 25/03/2021 22:06:45 +07
 * @filename    : C
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

int lcs(string a, string b) {
    if ((int)a.length() > (int)b.length()) a.swap(b);
    int res = 0, n = a.length(), m = b.length();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (b.find(a.substr(i, j-i+1)) != string::npos) res = max(res, j-i+1);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
    //freopen("C.in", "r", stdin);
    //freopen("C.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int ans = a.length() + b.length();
        ans -= lcs(a,b)*2;
        cout << ans << "\n";
    }
}

