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
    string a, b, ans;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    vector<vector<int>> dp(a.length(), vector<int>(b.length(),0));
    //map<int, map<int, ii>> tr;
    rep(i, 1, sz(a)) {
        rep(j, 1, sz(b)) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                //tr[i][j] = {i-1,j-1};
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                //if (dp[i][j-1] > dp[i-1][j]) tr[i][j] = {i,j-1};
                //else tr[i][j] = {i-1,j};
            }
        }
    }
    int x = sz(a) - 1, y = sz(b) - 1;
    while (x >= 1 && y >= 1) {
        if (a[x] == b[y]) {
            ans.pb(a[x]);
            --x;--y;
            continue;
        }
        if (dp[x-1][y] > dp[x][y-1]) {
            --x;
        }
        else --y;
    }
    reverse(all(ans));
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
