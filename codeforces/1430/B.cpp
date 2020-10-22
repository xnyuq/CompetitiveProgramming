// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (auto& i: arr) cin >> i;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    sort(arr.begin(), arr.end());
    for (int i = n - 2; i >= 0 && k > 0; --k, --i) {
        arr[n-1] += arr[i];
        arr[i] = 0;
    }
    cout << arr[n-1] << "\n";
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
