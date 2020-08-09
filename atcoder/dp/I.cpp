#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl "\n"
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<double> p(n);
    vector<vector<double>> dp(n, vector<double>(n+1));
    rep(i,0,n) {
        cin >> p[i];
    }
    dp[0][0] = 1-p[0];
    dp[0][1] = p[0];
    rep(i,1,n) {
        rep(j,0,i+2) {
            dp[i][j] = dp[i-1][j]*(1-p[i]);
            if (~j) {
                dp[i][j] += dp[i-1][j-1]*p[i];
            }
        }
    }
    double ans = 0;
    rep(i,n/2+1, n+1) {
        ans += dp[n-1][i];
    }
    printf("%.10lf\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
