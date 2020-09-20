// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k = 0;
    cin >> n;
    vector<int> a(n), l(n), arr;
    for (auto &i: a) cin >> i;
    for (auto &i: l) cin >> i;
    for (int i = 0; i < n; ++i) {
        if (l[i] == 0) arr.emplace_back(a[i]);
    }
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < n; ++i) {
        if (l[i] == 1) cout << a[i] << " ";
        else {
            cout << arr[k++] << " ";
        }
    }
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
