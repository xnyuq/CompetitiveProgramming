#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 10;

int64_t nCr(int n, int r) {
    if (r == 2) return 1LL*n*(n-1)/2;
    else return 1LL*n*(n-1)*(n-2)/6;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n), cnt(n+5);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ++cnt[arr[i]];
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += nCr(cnt[i], 3) + nCr(cnt[i], 2) * cnt[i + 1] +
               nCr(cnt[i], 2) * cnt[i + 2] +
               cnt[i] * (nCr(cnt[i + 1], 2) + nCr(cnt[i + 2], 2)) +
               cnt[i] * cnt[i + 1] * cnt[i + 2];
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
