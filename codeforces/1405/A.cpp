// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i:a) cin >> i;
    for (int i = n - 1; i >= 0; --i) cout << a[i] << " ";
    cout << "\n";
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
