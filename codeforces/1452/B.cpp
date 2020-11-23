#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, max_e = 0;
    cin >> n;
    vector<int> arr(n);
    for (auto& i : arr) {
        cin >> i;
        max_e = max(max_e, i);
    }
    long long sum = accumulate(arr.begin(), arr.end(), 0ll);
    long long k = max((sum+n-2)/(n-1), 1ll*max_e);
    cout << k*(n-1) - sum<< "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
