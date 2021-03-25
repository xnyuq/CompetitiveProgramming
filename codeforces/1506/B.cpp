/**
 * @author      : quynx
 * @created     : 25/03/2021 21:49:15 +07
 * @filename    : B
 * @source      : https://codeforces.com/contest/1506/problem/B
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
    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        char tmp;
        vector<int> q;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp == '*') q.push_back(i);
        }
        int ans = 0;
        if ((int)q.size() == 1) ans = 1;
        else if (q.back() - q.front() <= k) ans = 2;
        else {
            ans = 2;
            int last = q[0];
            for (int i = 1; i < (int)q.size()-1 && q.back() - last > k; ++i) {
                auto it = upper_bound(q.begin() + i, q.end() - 1, last + k);
                dbg(it-q.begin());
                --it;
                ++ans;
                last = *it;
            }
        }
        cout << ans << "\n";
    }
}

