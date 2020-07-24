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
    int N, W;
    cin >> N >> W;
    vi w(N), v(N);
    rep(i,0,N) {
        cin >> w[i] >> v[i];
    }
    unordered_map<int, ll> dp;
    rep(i,0,N) {
        per(j,0,W+1) {
            if (j>=w[i]) {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[W];
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
