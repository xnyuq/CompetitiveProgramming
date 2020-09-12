// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long s = 0, ans;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        s += arr[i];
    }
    ans = s;
    for (int i = 0; i < n; ++i) {
        s -= arr[i];
        ans = max(ans, s);
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
