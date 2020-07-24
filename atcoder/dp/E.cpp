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
#define INF 1000000000000
#define MOD 1000000007

void solve() {
    ll N, W, sV = 0;
    int ans = 0;
    cin >> N >> W;
    vll w(N), v(N);
    rep(i,0,N) {
        cin >> w[i] >> v[i];
        sV += v[i];
    }
    vll dp(sV+1, INF);
    //dp[i] ~ minimum weight for max i value
    dp[0] = 0;
    rep(i,0,N) {
        //dp[v[i]] = min(dp[v[i]], w[i]);
        per(j,0,sV-v[i]+1) {
            dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]);
        }
    }
    rep(i,0,sV+1) {
        if (dp[i] <= W) {
            ans = max(ans, i);
        }
    }
    cout << ans << "\n";
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
