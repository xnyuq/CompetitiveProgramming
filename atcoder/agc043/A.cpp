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
    int n, m; cin >> n >> m;
    vector<vector<bool>> mat(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char tmp;
            cin >> tmp;
            mat[i][j] = tmp == '#';
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 2e5));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) dp[i][j] = mat[i][j];
            else {
                if (i-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + (mat[i-1][j] == false && mat[i][j] == true));
                if (j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + (mat[i][j-1] == false && mat[i][j] == true));
            } 
        }
    }
    cout << dp[n-1][m-1] << "\n";
}

