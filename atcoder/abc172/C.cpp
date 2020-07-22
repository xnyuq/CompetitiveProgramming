#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
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
    int n, m, k;
    cin >> n >> m >> k;
    vll s1(n+1), s2(m+1);
    s1[0] = s2[0] = 0;
    rep(i, 0, n) {
        int tmp;
        cin >> tmp; 
        s1[i+1] = s1[i] + tmp;
    }
    rep(i, 0, m) {
        int tmp;
        cin >> tmp;
        s2[i+1] = s2[i] + tmp;
    }
    int ans = 0;
    int j = m;
    for (int i = 0; i <= n && s1[i] <= k; ++i) {
        while (s2[j] > k - s1[i]) --j;
        ans = max(ans, i + j);
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
