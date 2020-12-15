#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1), arr(n);
    for (auto& i : arr) cin >> i, ++cnt[i];
    int ans = -1, minNum = 1e9;
    for (int i = 0; i < n; ++i)
        if (minNum > arr[i] && cnt[arr[i]] == 1) minNum = arr[i], ans = i+1;
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
