// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;
void solve() {
    long long n, ma ,mb;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    ma = *min_element(a.begin(), a.end());
    mb = *min_element(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
            ans += max(a[i] - ma, b[i] - mb);
    }
    cout << ans << "\n";
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
