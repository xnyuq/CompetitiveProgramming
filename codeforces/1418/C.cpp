// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> him(n, INF), us(n, INF);
    for (auto &i: a) cin >> i;
    us[1] = him[0] = a[0];
    him[1] = him[0] + a[1];
    for (int i = 2; i < n; ++i) {
        him[i] = min(us[i-1]+a[i], us[i-2] + a[i-1] + a[i]);
        us[i] = min(him[i-2], him[i-1]);
    }
    cout << min(him[n-1], us[n-1]) << "\n";
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
