#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 2> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vi a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != i + 1) ans = 1;
    }
    int l = 0, r = 0;
    while (l < n && r < n) {
        while (l < n && a[l] != l + 1) {
            ++l;
        }
        if (l == n) break;
        r = l;
        while (r < n && a[r] == r + 1) {
            ++r;
        }
        if (r != n && l != 0) {
            ans = 2;
            break;
        }
        l = r;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

