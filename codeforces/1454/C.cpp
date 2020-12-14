#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    auto it = unique(arr.begin(), arr.end());
    vector<int> res(n+1, 1);
    n = distance(arr.begin(), it);
    arr.resize(n);
    int ans = 1e9;
    for (auto& i: arr) ++res[i];
    --res[arr[0]], --res[arr[n-1]];
    for (auto& i: arr) {
        ans = min(ans, res[i]);
    }
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
