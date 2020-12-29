#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> arr(n), sum(2);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum[i%2] += arr[i];
    }
    int smaller = sum[0] > sum[1];
    for (int i = 0; i < n; ++i) {
        if (i%2 == smaller) cout << "1 ";
        else cout << arr[i] << " ";
    }
    cout << "\n";
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

