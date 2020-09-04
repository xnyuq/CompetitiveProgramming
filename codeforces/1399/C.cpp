// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        ++a[tmp];
    }
    int ans = 0;
    for (int s = 2; s <= 100; ++s) {
        int count = 0;
        for (auto& it : a) {
            if (it.first * 2 > s) break;
            if (it.first * 2 == s) count += it.second / 2;
            else if (a.find(s-it.first) != a.end()) count += min(it.second, a[s-it.first]);
        }
        ans = max(count, ans);
    }
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
