// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, INF)));
    for (auto &i: a) cin >> i;
    dp[0][0][1] = (a[0] == 1); 
    for (int i = 1; i < n; ++i) {
        for (int p = 0; p < 2; ++p) {
            dp[i][p][0] = dp[i-1][p][1] + (p == 0 && a[i] == 1);
            dp[i][p][1] = min(dp[i-1][p^1][1], dp[i-1][p^1][0]) + (p == 0 && a[i] == 1);
        }
    }
    int ans = INF;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans  = min(ans, dp[n-1][i][j]);
        }
    }
    cout << ans << "\n";
    //for (int i = 0; i < n; ++i) {
        //for (int j = 0; j < 2; ++j) {
            //for (int k = 0; k < 2; ++k){
                //printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[i][j][k]);
            //}
        //}
    //}
    //cout << "----------------------------\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
