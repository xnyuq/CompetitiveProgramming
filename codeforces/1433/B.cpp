// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    int l = 0, ans = 0,r = n - 1;
    while (l < n && !arr[l]) ++l;
    while (r >= 0 && !arr[r]) --r;
    for (int k = l; k <= r; ++k) ans += !arr[k];
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
