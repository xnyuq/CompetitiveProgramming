#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    for (int i = 0; i < n / 2; ++i) {
        cout << arr[i] << " " << arr[n-i-1] << " ";
    }
    if (n%2) cout << arr[n/2];
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

