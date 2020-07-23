#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<array<int,3>> dp(n);
    vi a(n), b(n), c(n);
    rep(i,0,n) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    rep(i,0,n-1) {
        dp[i+1][0] = max(dp[i][1], dp[i][2]) + a[i+1];
        dp[i+1][1] = max(dp[i][0], dp[i][2]) + b[i+1];
        dp[i+1][2] = max(dp[i][1], dp[i][0]) + c[i+1];
    }
    cout << max({dp[n-1][0],dp[n-1][1], dp[n-1][2]}) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
