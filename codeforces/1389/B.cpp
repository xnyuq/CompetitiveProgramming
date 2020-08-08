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
#define endl "\n"
#define INF 1000000000
#define MOD 1000000007
//#define cerr if (false) cerr

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vi a(n);
    vi s(n);
    vi m(n+1);
    rep(i, 0, n) {
        cin >> a[i];
        if (!i) {
            s[i] = a[i];
        }
        else {
            s[i] = a[i] + s[i - 1];
            m[i] = max(m[i - 1], a[i - 1] + a[i]);
        }
    }
    m[n] = m[n-1];
    int ans = -1;
    rep(i, 0, z + 1) {
        if (k < 2*i) {
            continue;
        }
        ans = max(ans, s[k - 2 * i] + i * m[k - 2 * i + 1]);
        // printf("t: %d -> ans: %d\n", t, ans);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
