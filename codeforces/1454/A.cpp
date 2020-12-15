#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    iota(arr.rbegin(), arr.rend(), 1);
    if (n%2) swap(arr[n/2], arr[0]);
    for (auto& i: arr) cout << i << " ";
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
