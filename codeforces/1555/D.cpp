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
#endif
    int n, m;
    string s;
    cin >> n >> m >> s;
    string base = "abc";
    vector<string> per;
    vector<vector<int>> diff(6, vector<int>(n));
    int k = 0;
    vector<string> saved;
    do {
        string cur;
        while ((int)cur.size() < n) cur += base;
        saved.push_back(cur);
        diff[k][0] = s[0] != cur[0];
        for (int i = 1; i < n; ++i) {
            diff[k][i] = diff[k][i-1] + (s[i] != cur[i]);
        }
        ++k;
        dbg(1);
    } while (next_permutation(base.begin(), base.end()));
    const int INF = 1e9;
    while (m--) {
        int l, r;
        cin >> l >> r; --r, --l;
        int ans = INF;
        for (int i = 0; i < 6; ++i) {
            ans = min(ans, diff[i][r] - diff[i][l] + (s[l] != saved[i][l]));
        }
        cout << ans << "\n";
    }
}


