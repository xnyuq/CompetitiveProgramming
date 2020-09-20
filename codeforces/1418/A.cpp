// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y, k, ans = 0;
    cin >> x >> y >> k;
    ans = (k + y * k - 1) / (x - 1) + k;
    if ((k + y * k - 1) % (x - 1))
        ++ans;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
