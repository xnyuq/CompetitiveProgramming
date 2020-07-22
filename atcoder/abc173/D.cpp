#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& i: a) {
        cin >> i;
    }
    sort(rall(a));
    ll ans = a[0];
    int cnt = 2, j = 1;
    for (int i = 2; i < n; ++i) {
        if (!cnt) {
            cnt = 2;
            ++j;
        }
        ans += a[j];
        --cnt;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}

