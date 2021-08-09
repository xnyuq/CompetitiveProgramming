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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(2, vector<int>(n));
        for (auto& row: arr) {
            for (auto& cell: row) cin >> cell;
        }
        int score = 1e9 + 10;
        vector<vector<int>> pre(2, vector<int>(n));
        int sum[2] = {arr[0][0],arr[1][0]};
        pre[0][0] = arr[0][0];
        pre[1][0] = arr[1][0];
        for (int i = 1; i < n; ++i) {
            pre[0][i] = pre[0][i-1] + arr[0][i];
            pre[1][i] = pre[1][i-1] + arr[1][i];
            sum[0] += arr[0][i];
            sum[1] += arr[1][i];
        }
        for (int i = 0; i < n; ++i) {
            int turnHere = max(sum[0] - pre[0][i], i > 0 ? pre[1][i-1] : 0);
            score = min(score, turnHere);
        }
        cout << score << "\n";
    }
}


