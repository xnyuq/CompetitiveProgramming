#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (!m) {
        cout << "1\n";
        return;
    }
    vector<int> arr(m);
    vector<pair<int, int>> range;
    for (auto& i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    if (arr[0] != 1) range.push_back({1, arr[0] - 1});
    for (int i = 1; i < m; ++i) {
        if (arr[i] != arr[i - 1] + 1) {
            range.push_back({arr[i - 1] + 1, arr[i] - 1});
        }
    }
    if (arr[(int)arr.size() - 1] != n)
        range.push_back({arr[(int)arr.size() - 1] + 1, n});
    if (!(int)range.size())
        cout << "0\n";
    else {
        int ans = 0;
        int minLength = 1e9 + 20;
        for (auto& p : range) {
            minLength = min(minLength, p.second - p.first + 1);
        }
        for (auto& p : range)
            ans += (p.second - p.first + minLength) / minLength;
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
