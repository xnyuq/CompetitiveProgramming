#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    vector<int> start(n), end(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        start[i] = arr[i].first, end[i] = arr[i].second;
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int ans = 2e5+10;
    for (int i = 0; i < n; ++i) {
        int startAfter = start.end() - upper_bound(start.begin(), start.end(), arr[i].second);
        int endBefore = lower_bound(end.begin(), end.end(), arr[i].first) - end.begin();
        ans = min(ans, startAfter + endBefore);
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

